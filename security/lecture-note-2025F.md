Motivating application: fine-grained control of access to shared password file
---

password file shared across multiple users.

file-grained permissions are not expressive enough.
- a password file storing alice's and bob's passwords. alice and bob are group users to the password file owner. 
-- if the file's group read permission is 1, alice can see alice's password (utility), and alice can see bob's password (insecurity).
-- if the file's group read permission is 0, alice cannot see alice's password (loss of utility), and alice can see bob's password (security).
-- so, how to achieve both? privileged program enforcing fine-grained access control.
-- a privileged program can always access the file, from OS perspective. It is trusted by end users. internally, it enforces the access logic, who can see what (part) of the file.
-- how to let a program be able to access shared password file. Let this program have privilege. 
--- program file owned by privileged user (root), and when 


Privileged program
---

Consider Alice runs program "p" which request accessing file "f".
Bob owns the program file "p".

If "p" is a normal program: OS sees the file access is from Alice.

If "p" is a privileged program: OS sees the file access is from Bob.

Demo: `permission-fileio/make turn-priv-program`

Normal design of privileged programs: 
- 1. authentication
- 2. fine-grained access control
- 3. execute the job the user/Alice requests

back to the example of shared password file:
- normal file-grained access control: a permission (binary 0/1) defined on file f and user type g
- fine-grained access control: a permission (binary 0/1) defined on a line of a file l and a specific account (Alice).

??? fine-grained ACL

Permissions and ACL
===

Privileged programs
===

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

demo: commands on MacOS
---

sudo sysadminctl -addUser username -password 'pw'
sudo sysadminctl -addUser nathan -password '1234'

su - B

dscl . list /Users



