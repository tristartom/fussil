Instructions
===

Demo multi-user permissions in bash
---

```
touch file_r.txt
sudo chown root file_r.txt 
sudo chmod 640 file_r.txt 
ls -ltr file_r.txt 
#-rw-r-----  1 root  staff  0 Feb  3 11:58 file_r.txt
echo "alice" >> file_r.txt 
#expected to fail
cat file_r.txt 
#expected to succeed 'cause the current user (tristartom) may be in the same group as root.
sudo su
#in the prompt
echo "bob" >> file_r.txt 
exit
# exit the prompt
cat file_r.txt 
```

Run capability-leaking attack
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
```

Toggle the protection on, in the setuid.c

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
