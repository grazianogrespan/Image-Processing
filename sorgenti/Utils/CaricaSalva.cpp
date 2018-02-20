#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//legge il contenuto del file e ne salva header e array con la codifica bitmap
void CaricaBmp24(const char *Nome, unsigned char *Dove, unsigned char* Header, int x, int y, int dimH)
{	
	FILE *fHan = fopen(Nome, "r");
	if(fHan == NULL) {
		printf("errore!\n");
		exit(1);
	}
	
	fread(Header, dimH, 1, fHan);
	fread(Dove, x * y * 3, 1, fHan);
	fclose(fHan);
}

//scrive il contenuto dell'header e la sua codifica nel file

void SalvaBmp24(const char *Nome, unsigned char *DaDove,unsigned char* Header, int x, int y, unsigned char dimH)
{
	FILE *fHan = fopen(Nome, "w");
	if(fHan == NULL) {
		printf("errore!\n");
		exit(1);
	}
	
//dalla posizione 18 dell'header modifica la lunghezza del file in pixel	
	Header[18]= (unsigned char)(x);
	Header[19]= (unsigned char)(x>>8);
	Header[20]= (unsigned char)(x>>16);
	Header[21]= (unsigned char)(x>>24);
	
//dalla posizione 22 dell'header modifica l'altezza del file in pixel
	Header[22]= (unsigned char)(y);
	Header[23]= (unsigned char)(y>>8);
	Header[24]= (unsigned char)(y>>16);
	Header[25]= (unsigned char)(y>>24);
	
	fwrite(Header, dimH, 1, fHan);
	fwrite(DaDove, x * y * 3, 1, fHan);

}
