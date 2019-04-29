#include "Random.h"
#include "math.h"
#include "time.h"
Sayi SayiOlustur(int uzunluk){
	Sayi this;
	this = (Sayi)malloc(sizeof(struct SAYI));
	this->Sayilar=malloc(sizeof(int)* uzunluk);
	this->uzunluk=uzunluk;
	
	// Burada Rasgele sayi olusturulacak. Sayilar dizisine atanacak.
	
		time_t gec;
		struct tm * timeptr;
		gec = time(NULL);
		timeptr = localtime(&gec);
		this->x = timeptr->tm_sec;
	for(int i=0;i<uzunluk;i++){
		
		//printf("%f ",this->x);
		this->y = ((this->x * this->x)+5)/3;
		//printf("%f ",this->y);
		this->Sayilar[i]=this->y;

		this->x += 1.67;
		//printf("%f ",this->x);
	}


	this->Yaz = &_Yaz;
	this->Yoket = &_Yoket;
return this;
}

void _Yaz(const Sayi this){
	int i;
	for(i=0;i<this->uzunluk;i++){
		printf("%d ,",this->Sayilar[i]);
	}
}
void _Yoket(Sayi this){
	if(this==NULL)return;
	free(this->Sayilar);
	free(this);
}
