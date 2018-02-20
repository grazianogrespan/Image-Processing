#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

//~ L' aumento o la diminuzione del contrasto non è altro che l' amplificazione o riduzione del valore di ciascun canale RGB del colore.
//~ Il metodo è quello di trovare una formuletta (arbitraria, anche diversa dalla mia) che, dato un parametro che indichi il valore del 
//~ contrasto, amplifichi (aumentando o riducendo) il valore iniziale.

void Contrasto(unsigned char Sorgente[][3], int larg, int alt, unsigned char Destinazione[][3], float C)
{
	float v;
 
	for(int c=0; c<3; c++)
	{
		for(int y = 0; y < alt; y++) 
		{
			for(int x = 0; x < larg; x++) 
			{
				//calcolo il valore di contrasto da applicare all'immagine
				float F = ( 259 * ( C + 255 ) ) / ( 255 * (259 - C) );
				
				v = Sorgente[x + (y * larg)][c];
								
				v =  F * (v - 128) +128;

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
