#include "RastgeleKarakter.h"

Karakter KarakterOlustur(){
	Karakter this;
	this = (Karakter)malloc(sizeof(struct KARAKTER));
	this->super = SayiOlustur(100);
	this->Alfabe = "abcdefghiklmnoprstuvyz";

	// Karakter Uretme Islemi yapan fonksiyonları göstericilerimize Atıyoruz
	this->KarakterUret = & _KarakterUret; // verilan sayi kadar rastgele karakter üretir
	this->BelirtilenKarakterlerArasindaUret= & _BelirtilenKarakterlerArasindaUret; // asdf üret
	this->BelirtilenIkiKarakterArasindaUret = & _BelirtilenIkiKarakterArasindaUret; // a,r arası üret

	// Uretilen Karakterleri Ekrana yazacak fonksiyonlarımızı göstericilere atıyoruz
	this->RasgeleSayiYaz = & _RasgeleSayiYaz;
	this->BelirtilenKarakterleriYaz= & _BelirtilenKarakterleriYaz;
	this->UretilenKarakterleriYaz = & _UretilenKarakterleriYaz;
	this->BelirtilenIkiKarakterArasindakileriYaz = & _BelirtilenIkiKarakterArasindakileriYaz;
	//Heap bölgesini temizle islemi
	this->Yoket = & _KarakterYoket;
return this;
}

//				---------KARAKTER URETME ISLEMLERI--------

//Adet sayısı kadar rasgele karakter uretir.
char* _KarakterUret(Karakter this,int adet){

	char* UretilenKarakterler;
	UretilenKarakterler = malloc(sizeof(char)*101);
// Karakter sınıfının referans aldıgı random sınıfındaki rastgele sayılara ulasarak bunların 23 e modu alınmıs sekilde belirtilen adet kadar rastgele karakter olusturulur.
	for(int i =0;i<adet;i++){
		int mod = this->super->Sayilar[i] % 21;
		UretilenKarakterler[i] = this->Alfabe[mod];
	}

return UretilenKarakterler;
}

//Belirtilen Karakter dizisi arasından rastgele karakter üretir.
char _BelirtilenKarakterlerArasindaUret(Karakter this,char* BelirtilenDizi){

	char UretilenKarakterler;
	int mod = this->super->Sayilar[0] % 5;
	UretilenKarakterler = *(BelirtilenDizi+mod);
	
return UretilenKarakterler;
}
//Belirtilen iki karakter arasında ragele sayi olusturulur.
char* _BelirtilenIkiKarakterArasindaUret(Karakter this,int adet,char baslangic,char bitis){

	char* UretilenKarakterler;
	UretilenKarakterler = malloc(sizeof(char)*adet);
	int Baslangic=0,Bitis=21;
	for(int j=0;j<=21;j++){
		if(this->Alfabe[j]==baslangic) Baslangic=j;
		if(this->Alfabe[j]==bitis) Bitis=j;
	}
	// mod + baslangic 23 ü gecmemeli !!! ACIK VAR!!
	for(int i =0;i<=adet;i++){
		int mod = this->super->Sayilar[i] % Bitis;
		UretilenKarakterler[i] = this->Alfabe[mod];
	}


return UretilenKarakterler;
}



//				---------YAZMA ISLEMLERI------------
//Random sınıfında uretilen rasgele sayilari ekrana yaziyoruz.
void _RasgeleSayiYaz(Karakter this){
	printf("Uretilen Rasgele Sayilar : ");
	this->super->Yaz(this->super);
	printf("\n");
}
//Belirtilen karakter dizisindeki elemanları arasından olusturulan karakterleri ekrana yazıyoruz.
void _BelirtilenKarakterleriYaz(Karakter this,char* BelirtilenKarakterDizisi){
	printf("Belirtilen Karakterler Arasindaki Rasgele Karakterler : ");
	printf("%c",this->BelirtilenKarakterlerArasindaUret(this,BelirtilenKarakterDizisi));
	printf("\n");
}
//Istenilen sayi kadar rasgele karakter uretip ekrana yazıyoruz.
void _UretilenKarakterleriYaz(Karakter this,int UretilecekKarakterSayisi){
	printf("100 adet Rastgele Karakter Karakterler :");
	printf("%s", this->KarakterUret(this,UretilecekKarakterSayisi));
	printf("\n");
}
//Belirtilen iki karakter arasındaki karakterlerden rasgele karakter uretip ekrana yazıyoruz.
void _BelirtilenIkiKarakterArasindakileriYaz(Karakter this,int Adet,char Baslangic,char Bitis){
	printf("Belirtilen Iki Karakter Arasındaki ( %c, %c ) Rasgele Karakterler : ",Baslangic,Bitis);
	printf("%s",this->BelirtilenIkiKarakterArasindaUret(this,Adet,Baslangic,Bitis));
	printf("\n");
}

//				--------HEAP TEMİZLEME-----------
void _KarakterYoket(Karakter this){
	if(this==NULL) return;
	if(this->super != NULL)	this->super->Yoket(this->super);
	free(this);
}
