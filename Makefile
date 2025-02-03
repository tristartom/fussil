all: c
	git push

c:
	git config --global user.email tristartom@gmail.com
	git add -A
	git commit -am 'setuid instructions added (with weixiang)'

b:
	make -C socket all
	make -C process all

