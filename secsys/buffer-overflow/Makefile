c2:
	clang -g -fno-stack-protector -Wno-deprecated-declarations -D_FORTIFY_SOURCE=0  -o a.out overflow1_controlhijack.c
	./a.out 1 123

c:
	clang -g -fno-stack-protector -Wno-deprecated-declarations -D_FORTIFY_SOURCE=0  -o a.out overflow1_crash.c
	./a.out XXXYXXXYXXXYXXX
	./a.out XXXYXXXYXXXYXXXY

db2:
	lldb \
	  -o 'b overflow1_controlhijack.c:11' \
	  -o 'r 2 123' \
	  -o 'register read fp' ./a.out

db:
	lldb \
	  -o 'b overflow1_crash.c:11' \
	  -o 'r XXXYXXXYXXXYXXXY' \
	  -o 'register read fp' ./a.out


s:
	gcc -S overflow1_crash.c -fno-stack-protector -Wno-deprecated-declarations
	

g:
	gcc -g -fno-stack-protector -Wno-deprecated-declarations overflow1_crash.c
	lldb a.out

clean:
	rm -r *.out *.s *.dSYM
