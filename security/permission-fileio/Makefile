files:
	rm *.txt
	touch file_a.txt file_rt.txt
	echo "alice" >> file_a.txt
	echo "root" >> file_rt.txt
	sudo chown root file_rt.txt
	sudo chmod 700 file_rt.txt #unreadable to normal user

setuid: files
	-rm a.out
	gcc setuid.c 
	sudo chown root a.out 
	sudo chmod u+s a.out 
	./a.out file_a.txt
	./a.out file_rt.txt

turn-priv-program:
	#turn a program into SETUID program
	touch /etc/zzz1
	sudo chown root /etc/zzz1
	sudo chmod g-r /etc/zzz1
	sudo chmod o-r /etc/zzz1
	cp /bin/cat mycat4
	ls -l mycat4
	./mycat4 /etc/zzz1
	sudo chown root mycat4
	ls -l mycat4
	./mycat4 /etc/zzz1
	sudo chmod 4755 mycat4
	ls -l mycat4
	./mycat4 /etc/zzz1

attack-capability-leaking:
	gcc confused.c
	sudo chown root a.out
	ls -ltr a.out
	sudo chmod 4755 a.out
	ls -ltr a.out
	sudo touch /etc/zzz
	sudo chmod 744 /etc/zzz
	cat /etc/zzz
	echo aaa > /etc/zzz
	./a.out

attack-seed-setuidlab-task8:
	gcc setuid2.c 
	sudo chmod 4755 a.out

clean:
	rm -f a.out

