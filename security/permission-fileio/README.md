Demos
===

Multi-user permissions in bash (2)
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

Turn a normal program to a privileged program (from SEED)
---

Turn mycat4 from a normal program to a setuid program

```
make turn-priv-program
```

TOCTOU2 in privileged program
---

Without attacks

```
make files
make toctou2-v
```

Under attacks

On terminal 1:

```
make files
make toctou2-a
```

On terminal 2:

```
make toctou2-v
```

Confused deputy (Capability-leaking attack)
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


Demos (Deprecated)
===

Demo multi-user permissions in bash
---

```
touch file_ro.txt
sudo chown root file_ro.txt 
sudo chmod 640 file_ro.txt 
ls -ltr file_ro.txt 
#-rw-r-----  1 root  staff  0 Feb  3 11:58 file_ro.txt
echo "alice" >> file_ro.txt 
#expected to fail
cat file_ro.txt 
#expected to succeed 'cause the current user (tristartom) may be in the same group as root.
sudo su
#in the prompt
echo "bob" >> file_ro.txt 
exit
# exit the prompt
cat file_ro.txt 
```

Run seed-setuidlab-task8 attack （deprecated）
---

This attack doesn't work on latest Linux/MacOS which is protected.

```
make clean
make attack-seed-setuidlab-task8
touch file1.txt
echo xxx > file1.txt 
./a.out file1.txt 
touch /etc/zzz
sudo chmod 700 /etc/zzz
ls -ltr /etc/zzz
cat /etc/zzz
./a.out "file1.txt; cat /etc/zzz" 
```
