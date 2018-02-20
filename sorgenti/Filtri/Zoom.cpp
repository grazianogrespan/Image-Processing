#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

#include "../Headers/Scala.h"

using namespace std;
//la funzione zoom effettua uno zoom centrale dell'immagine di un fattore che dipende dal valore zoom passato alla funzione.
//Il punto di partenza è centrale perchè si parte dal punto che corrisponde x =largS/4 e y =altS/4.
//Cambiando questi parametri si può partire da un punto differente dell'immagine.

void Zoom(unsigned char ImmagineS1[][3], int largS, int altS, unsigned char ImmagineD[][3], int zoom){
	int x, y;
	int l;

	for(int c=0; c<3; c++){
        for(y = 0;y < altS;y++) {
        	for(x = 0 ;x < largS;x++) {
				float u= x;
				float v= y;
        		l = LeggiInterpolato((u/zoom)+(largS/4), (v/zoom)+(altS/4), c, ImmagineS1, largS, altS);
        		if(l > 255) l = 255;
        		if(l < 0) l = 0;
        		ImmagineD[x + (y * largS)][c] = l;
        	}
        }
    }

}
