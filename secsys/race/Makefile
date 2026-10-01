safe_file:
	touch counter.txt
	echo 0 > counter.txt
	gcc spinlock.c ../../process/4-mmap/mmap_lib.c race-proof-file-inc-number.c -o a.out
	./a.out
	cat counter.txt
	rm  counter.txt

race_file:
	touch counter.txt
	echo 0 > counter.txt
	gcc race-file-inc-number.c -o a.out
	./a.out
	cat counter.txt
	rm  counter.txt

race_mmap:
	gcc -O0 ../../process/4-mmap/mmap_lib.c race-mmap-inc-number.c
	./a.out
	rm a.out

safe_mmap:
	gcc -O0 spinlock.c ../../process/4-mmap/mmap_lib.c race-proof-mmap-inc-number.c
	./a.out
	rm a.out

race:
	gcc ../../process/4-mmap/mmap_lib.c race-mmap.c -o a.out
	./a.out


