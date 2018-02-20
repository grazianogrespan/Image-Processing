#include <cmath>

using namespace std;

//~ Per ogni pixel dell' immagine, si lavora con ciascuno dei 3 canali RGB; l' inverso di ogni canale RGB si ottiene calcolando il suo complementare, ovvero 255 - il canale RGB.
//~ 
//~ PER OGNI pixel {
   //~ PER OGNI canaleRGB {
      //~ canaleRGB = 255 - canaleRGB
   //~ }
//~ }

void Negativo (unsigned char Sorgente[][3], int larg, int alt, unsigned char Destinazione[][3]){
	for(int i=0; i<larg*alt; i++) 
		{	
			Destinazione[i][0] = 255 - Sorgente[i][0];
			Destinazione[i][1] = 255 - Sorgente[i][1];
			Destinazione[i][2] = 255 - Sorgente[i][2];
		}
}
