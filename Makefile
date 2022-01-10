client_objects = client1.o 
server_objects = server.o

.PHONY: all clean
all: client server clean_o

client: $(client_objects)
	@gcc -o client $^

server: $(server_objects)
	@gcc -o server $^

clean_o:
	rm ./*.o

clean:
	-rm client server