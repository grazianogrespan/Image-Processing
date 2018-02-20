#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <cmath>

using namespace std;

void Luminosita(unsigned char Sorgente[][3], int larg, int alt, unsigned char Destinazione[][3], float Scala)
{
	float v;
	
//il valore è diviso per 10 per fa si che l'aumento di luminosità risulti graduale. 	
	Scala /=10;
	
	for(int c=0; c<3; c++)
	{
		for(int y = 0; y < alt; y++) 
		{
			for(int x = 0; x < larg; x++) 
			{
				v = Sorgente[x + (y * larg)][c];
								
//se l'immagine è da scurire divide il valore del pixel per la scala, altrimenti per ottenere l'effetto opposto ne moltiplica il valore
				if(Scala > 0)
					v = v * Scala;
				else
					v = v / abs(Scala);
				
				//correzione dei bound	
				if(v > 255) 
					v = 255;
					
				if(v < 0) 
					v = 0;
					
				Destinazione[x + (y * larg)][c] = v;
			}
		}
	}
}
