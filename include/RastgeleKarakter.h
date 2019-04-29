#ifndef KARAKTER_H
#define KARAKTER_H

#include "Random.h"

struct KARAKTER{
	// Degiskenler
	Sayi super;
	char* Alfabe;

	//Karakter Uretme Islemi yapan fonksiyon gostericileri
	char* (*KarakterUret)(struct KARAKTER*, int);
	char (*BelirtilenKarakterlerArasindaUret)(struct KARAKTER*, char*);
	char* (*BelirtilenIkiKarakterArasindaUret)(struct KARAKTER*,int,char,char);

	// Uretilen Karakterlerin ekrana yazılmasını saglayan fonksiyon göstericileri
	void (*RasgeleSayiYaz)(struct KARAKTER*);
	void (*BelirtilenKarakterleriYaz)(struct KARAKTER*,char*);
	void (*UretilenKarakterleriYaz)(struct KARAKTER*,int);
	void (*BelirtilenIkiKarakterArasindakileriYaz)(struct KARAKTER*,int,char,char);
	// Heap bellek bölgesi temizleme
	void (*Yoket)(struct KARAKTER*);

};
typedef struct KARAKTER* Karakter;

//Nesne uretebilmek icin gerekli kullanılan yapıcı metod benzetmesi
Karakter KarakterOlustur();

//Karakter ureten fonksiyonlar
char* _KarakterUret(Karakter,int);
char _BelirtilenKarakterlerArasindaUret(Karakter, char*);
char* _BelirtilenIkiKarakterArasindaUret(Karakter,int,char,char);

//Ekrana Yazan Fonksiyonlar
void _RasgeleSayiYaz(Karakter); //Random sınıfında uretilen rasgele sayiları ekrana yazar
void _BelirtilenKarakterleriYaz(Karakter,char*); // Belirtilen karakterler arasında üretilen rasgele karakterleri ekrana yazar
void _UretilenKarakterleriYaz(Karakter,int);// Istenilen sayi kadar uretilen karakterleri ekrana yazar
void _BelirtilenIkiKarakterArasindakileriYaz(Karakter,int,char,char);

//Heap temizleme islemi yapan fonksiyon
void _KarakterYoket(Karakter);

#endif
