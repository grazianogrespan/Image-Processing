#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

//~ Per applicare l'effetto seppia viene fatta una passata di tutta la matrice dei pixel, scorrendo per ognuno di essi 
//~ prima tutti i canali colori.
//~ Per calcolare il nuovo valore del pixel viene richiamata la funzione Pixel che, in base al canale che si sta valutando, 
//~ effettua una somma dei canali sorgente di quel pixel moltiplicati per dei fattori permetteno di modificare il valore ottenendo 
//~ così l'effetto "seppia".

int Pixel(int x, int y, int c, unsigned char ImmagineS1[][3], int larg, int alt){
	
	float t;
	int ris;

	
	if(c==2){
			t=(0.393f*ImmagineS1[x+(y*larg)][0])+(0.769f*ImmagineS1[x+(y*larg)][1])+(0.189f*ImmagineS1[x+(y*larg)][2]);
			ris= (int) t;
	}
	if(c==1){
			t=(0.349f*ImmagineS1[x+(y*larg)][0])+(0.686f*ImmagineS1[x+(y*larg)][1])+(0.168f*ImmagineS1[x+(y*larg)][2]);
			ris= (int) t;
	}
	if(c==0){
			t=(0.272f*ImmagineS1[x+(y*larg)][0])+(0.534f*ImmagineS1[x+(y*larg)][1])+(0.131f*ImmagineS1[x+(y*larg)][2]);
			ris= (int) t;
	}
	
	if(ris>255) 
		ris=255;
	
	if(ris<0) 
		ris=0;
	
	return ris;

}

void Seppia(unsigned char ImmagineS1[][3], int largS, int altS, unsigned char ImmagineD2[][3]){

	for(int y=0; y< altS; y++){//SY
		for(int x=0; x < largS; x++){//SX
			for(int c=0; c<3; c++){
				ImmagineD2[x + (y* largS)][c]= Pixel(x, y, c, ImmagineS1, largS, altS);
			}
		}
	}
}
