#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

//~ Per quanto riguarda il filtro di "sharpening" viene applicato un filtro a convoluzione con il seguente kernel:
//~ {   0,  -1,  0,
   //~ -1,   5, -1,
    //~ 0,  -1,  0
//~ }.
//~ Per ogni pixel della destinazione viene calcolato, tramite la funzione PixelS il valore che è la somma dei pixel, 
//~ adiacenti a quello che si sta valutando, della sorgente moltiplicato per il valore del kernel nella posizione corrispondente.

int PixelS(int x, int y, int c, unsigned char ImmagineS1[][3], int larg, int alt){
	
	int u, v;
	int a;
	int p = 0;
    int Kernel[9] = {
        0,  -1, 0,
        -1, 5,  -1,
        0,  -1, 0
    };
    
    int OFS= 1;
    int KD= 3;

	for(v = -OFS;v <= OFS;v++) {
		if(y + v < 0 || y + v >= alt) continue;
		for(u = -OFS;u <= OFS;u++) {
			if(x + u < 0 || x + u >= larg) continue;

			a = ImmagineS1[x + u + ((y + v) * larg)][c];
			p += (a * Kernel[u + OFS + ((v + OFS) * KD)]);
		}
	}

	if(p < 0) p = 0;
	if(p > 255) p = 255;

	return(p);
}

void Sharp(unsigned char ImmagineS1[][3], int larg, int alt, unsigned char ImmagineD[][3]){
	int x, y;

	for(y = 0;y < alt;y++) {
		for(x = 0;x < larg;x++) {
            for(int c=0; c<3; c++){
                ImmagineD[x + (y * larg)][c] = PixelS(x, y, c, ImmagineS1, larg, alt);
            }
		}
	}

}
