#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

// HAL è una struttura che contiene 3 parametri interi.

struct HAL{

	int header;
	int larg;
	int alt;

	HAL(int a=0,int b=0,int c=0){
		header=a;
		larg=b;
		alt=c;
	}

};

//OttieniHAL restituisce tre parametri che son rispettivamente header,larghezza e altezza dell'immagine di input nella funzione.

HAL OttieniHAL(char* path){

	FILE *fpo=fopen(path,"rb");
	int int_var;
	HAL X;

	fseek(fpo,14,0);
    //n =
	fread(&int_var,sizeof(int), 1, fpo);
    X.header=int_var+14;
    //n =
	fread(&int_var,sizeof(int), 1, fpo);
    X.larg=int_var;
    //n =
	fread(&int_var,sizeof(int), 1, fpo);
    X.alt=int_var;

    return X;

}

//~ int main(){
//~ 
	//~ HAL X = OttieniHAL("/home/davide/img400x300.bmp");
//~ 
	//~ cout<<" - Header: "<<X.header<<endl;
	//~ cout<<" - Larghezza: "<<X.larg<<endl;
	//~ cout<<" - Altezza: "<<X.alt<<endl;
//~ 
//~ }
