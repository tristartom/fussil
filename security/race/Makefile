safe_file:
	touch counter.txt
	echo 0 >> counter.txt
	gcc race-proof-file-inc-number.c -o a.out
	./a.out
	cat counter.txt
	rm  counter.txt

race_file:
	touch counter.txt
	echo 0 >> counter.txt
	gcc race-file-inc-number.c -o a.out
	./a.out
	cat counter.txt
	rm  counter.txt

race:
	gcc mmap_lib.c race-mmap.c -o a.out
	./a.out


