all: c
	git push

c:
	git config --global user.email tristartom@gmail.com
	git add -A
	git commit -am 'reorganize related code into security/race and securiity/permission-fileio dir'

b:
	make -C socket all
	make -C process all

