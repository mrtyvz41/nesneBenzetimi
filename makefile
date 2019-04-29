CFLAGS	=	-I "./include/"
CLIB	=	-o "./lib/"
CSRC	=	-c "./src/"
hepsi:derle calistir

derle:
	gcc $(CFLAGS) $(CLIB)/Sayi.o $(CSRC)/Random.c
	gcc $(CFLAGS) $(CLIB)/Karakter.o $(CSRC)/RastgeleKarakter.c
	gcc $(CFLAGS) -o ./bin/Test ./lib/Karakter.o ./lib/Sayi.o ./src/Test.c
calistir:
	./bin/Test
