
# En fonction de l'emplacement des fichiers so faire
# export LD_LIBRARY_PATH=.
# ou
# export LD_LIBRARY_PATH=../libnotreparser/:../librequest-0.5/ <--bypass symbolic links


all:
	gcc -I ../libparser -I ../librequest-0.5/api  -L ../libparser -L ../librequest-0.5 -o server server.c -lparser -lrequest

notre:
	gcc -I ../libnotreparser -I ../librequest-0.5/api  -L ../libnotreparser -L ../librequest-0.5 -o server server.c -lnotreparser -lrequest 
