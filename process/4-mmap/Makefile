race_sfile:
	touch counter.txt
	echo 0 >> counter.txt
	gcc inc_number_file-race.c -o a.out
	./a.out
	cat counter.txt
	rm  counter.txt

race:
	gcc mmap_lib.c mmap_race.c -o a.out
	./a.out

mmap:
	gcc mmap_lib.c mmap_spinlock.c -o a.out
	./a.out

c:
	rm *out
