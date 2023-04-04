1:
	@echo "o"
	gcc client.c -g -o client.o
	gcc serveur.c -g -o serveur.o
	./serveur.o &
	./client.o 2 '*' 69

2:
	rm /tmp/key1; touch /tmp/key1; chmod 777 /tmp/key1
	rm /tmp/key2; touch /tmp/key2; chmod 777 /tmp/key2
	gcc ex2/client.c -g -o ex2/client.o
	gcc ex2/server.c -g -o ex2/server.o
	./ex2/server.o &
	./ex2/client.o msglol
