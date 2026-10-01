Demos
===

1. Multi-user permissions in bash (2)
---

```
touch file_wo.txt
sudo chown root file_wo.txt 
sudo chmod 620 file_wo.txt 
ls -ltr file_wo.txt 
#-rw--w----  1 root  staff  0 Feb  3 11:58 file_wo.txt
echo "alice" >> file_wo.txt 
#expected to succeed
###### cat 1 (from tristartom)
cat file_wo.txt
#expected to fail
sudo su
###### cat 2 (from root)
cat file_wo.txt 
exit
# exit the prompt
###### cat 3 (from root)
sudo cat file_wo.txt 
```

2. Turn a normal program to a privileged program (from SEED)
---

Turn mycat4 from a normal program to a setuid program

```
make turn-priv-program-macos
#make turn-priv-program
```

3. Set-uid program
---

```
make setuid
```

4. Confused deputy (Capability-leaking attack)
---

```
make clean
make attack-capability-leaking
#this will fail, which is expected.
./a.out
#fd is 3
#sh-3.2$ 
#in the above prompt, type the following:
echo yyy >&3
cat /etc/zzz
```

Toggle the protection on, in the setuid.c

5. TOCTOU2 in privileged program
---

#### Overview

| | Normal | DoS attack | Priv. escalation |
| --- | --- | --- | --- |
| `file_a.txt`  | ✅ | ❌ | |
| `file_rt.txt` | ❌ | | ✅ |

#### Normal (no attack)

Without attacks: A setuid program under alice and root

```
make files
make toctou2-d
```

#### DoS attack

On terminal 1:

```
make files
make toctou2-a
```

On terminal 2:

```
make toctou2-v
```

#### Priv. escalation

