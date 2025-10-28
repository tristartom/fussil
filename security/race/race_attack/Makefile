init:
	-@rm *out *txt
	touch fileRO.txt
	touch permRO.txt
	chmod u-w permRO.txt
	ls -l permRO.txt
	touch fileRW.txt
	touch permRW.txt
	ls -l permRW.txt

victim:
	gcc toctou-victim.c
	./a.out
	-cat fileRW.txt
	@echo ""
	-cat fileRO.txt

attack:
	gcc toctou-attack.c -o attack.out
	./attack.out 

clean:
	-@rm *out *txt
	
