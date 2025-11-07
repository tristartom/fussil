
Privileged programs
===

Motivating application
===

Fine-grained AC
---

A password file storing multiple users' passwords.

File-grained permissions are not expressive enough.

Fine-grained AC
---

* A password file storing Alice's and Bob's passwords. 
* Alice and Bob are group users to the password file.
  * If the file's group read permission is 1, 
    * Alice can see Alice's password (utility), 
    * and Alice can see Bob's password (insecurity).


Fine-grained AC
---

* A password file storing Alice's and Bob's passwords. 
* Alice and Bob are group users to the password file.
  * If the file's group read permission is 1, 
  * If the file's group read permission is 0, 
    * Alice cannot see Alice's password (loss of utility), 
    * and Alice cannot see Bob's password (security).

Fine-grained AC
---

* A password file storing Alice's and Bob's passwords. 
* Alice and Bob are group users to the password file.
  * If the file's group read permission is 1, 
  * If the file's group read permission is 0, 
* So, how to achieve both security and utility?  


Fine-grained AC
---

* So, how to achieve both security and utility?  
* A privileged program enforcing fine-grained access control.
  * A privileged program has read/write access to password file.
  * The priledged program is trusted and honestly enforces fine-grain AC.

Privileged program
===

Privileged program (u+s)
---

- Consider Alice runs program "p" which request accessing file "f".
- Bob owns the program file "p".
- If "p" is a normal program: OS sees the file access is from Alice.
- If "p" is a privileged program: OS sees the file access is from Bob.

Demo: `cd permission-fileio; make turn-priv-program`

RUID/EUID
---

- RUID: the account calling the program
- EUID: the ID the program uses to interact with OS (internal-calls syscalls)

```
+----+         +-------+         +----+
|User|--RUID-->|Program|--EUID-->| OS |
+----+         +-------+         +----+
```

- By default: 
  - `EUID = RUID` for normal program
  - `EUID = root` for privileged program (owner of the program file)


`setuid()`
---

You can use `setuid()` function to change EUID inside the program file.

```c
#include <unistd.h>
int setuid(uid_t uid);
uid_t getuid(void); //the real user ID, RUID
uid_t geteuid(void); //returns the effective user ID, EUID
```

Demo
---

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  int ruid=getuid();
  int euid=geteuid();
  printf("Before setuid:\n");
  printf(" Real UID: %d\n", getuid());
  printf(" Effective UID: %d\n", geteuid());
  // Try to change effective UID to 0 (root)
  if (setuid(ruid) == -1) perror("setuid failed");
  printf("\nAfter setuid(0):\n");
  printf(" Real UID: %d\n", getuid());
  printf(" Effective UID: %d\n", geteuid());
}
```

Summary
---

Consider `Alice` calls an executable file owned by `root`.

| Program type | RUID | EUID |
|---------------|------|------|
| Normal | `Alice` | `Alice` |
| Privileged (`u=s`) | `Alice` | `root` |
| Privileged (before `setuid()`) | `Alice` | `root` |
| Privileged (after `setuid()`) | `Alice` | `Alice` |

Principle of least privilege
---

P1: Privilege exercised
P2: Privilege needed

| P1 | P2 | Utility | Security |
|----|----|---------|----------|
| L  | L  |    ✔    |     ✔    |
| L  | H  |    ✗    |     N.A. |
| H  | H  |     ✔   |     ✔    |
| H  | L  |    ✔    |     ❌   |




Internal design of privileged programs
---

1. authentication
2. fine-grained access control
3. execute the job the user/Alice requests

Revisit password file
---

- normal file-grained access control: a permission (binary 0/1) defined on file f and user type g
- fine-grained access control: a permission (binary 0/1) defined on a line of a file l and a specific account (Alice).

setuid program: Downgrading

confused deputy bug

Misc.
===

Demo
---

normal user: nathan
root user: root

#from nathan
cat file_wo.txt

#from root
sudo su
cat file_wo.txt

#from root, but initiated from nathan
sudo cat file_wo.txt

- how it works internally (sudo cat file_wo.txt)
- nathan>sudo ==> root>cat 
- OS see cat issued from root

Commands on MacOS
---

sudo sysadminctl -addUser username -password 'pw'
sudo sysadminctl -addUser nathan -password '1234'

su - B

dscl . list /Users



