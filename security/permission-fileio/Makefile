attack-capability-leaking:
	gcc setuid.c
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

