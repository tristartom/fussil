raceBal-sf:
	gcc -I ../lib ../lib/server_lib.c ../lib/mmap_lib.c server_main_fork_req_resp_raceBal.c -o server_f.out
	./server_f.out 1234

raceBal-c:
	gcc -I ../lib ../lib/client_lib.c client_main_req_resp_raceBal.c -o client.out
	./client.out 127.0.0.1 1234

echo-s:
	touch file.txt
	gcc -I ../lib ../lib/server_lib.c server_main_echo.c -o server.out
	./server.out 1234
	cat file.txt
	rm file.txt

u-echo-c:
	gcc -I ../lib ../lib/client_lib_u.c client_main_echo.c -o client.out
	./client.out 127.0.0.1 2009

echo-cb:
	gcc -I ../lib ../lib/client_lib.c client_main_echo_b.c -o client_b.out
	./client_b.out 127.0.0.1 1234

u-echo-cb:
	gcc -I ../lib ../lib/client_lib_u.c client_main_echo_b.c -o client_b.out
	./client_b.out 127.0.0.1 2009


