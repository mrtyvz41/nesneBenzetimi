#ifndef RANDOM_H
#define RANDOM_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct SAYI{
	int *Sayilar;
	double y;
	double x;
	int uzunluk;
	int* (*RasgeleSayiOlustur)(struct SAYI*);
	void (*Yaz)(struct SAYI*);
	void (*Yoket)(struct SAYI*);
};
typedef struct SAYI* Sayi;

Sayi SayiOlustur(int uzunluk);
int* _RasgeleSayiOlustur(Sayi);
void _Yaz(Sayi);
void _Yoket(Sayi);

#endif
