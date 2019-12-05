web_server: web_server.c
	gcc -O2 -Wall -Werror -pedantic -o $@ $< -lpthread
epoll: epoll.c
	gcc -O2 -Wall -Werror -pedantic epoll.c
.PHONY: clean
clean:
	rm -f web_server
