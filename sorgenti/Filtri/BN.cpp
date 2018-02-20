#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;
		
	//~ PER OGNI pixel {
	   //~ SCALA DI GRIGIO = (0.5*canaleR + 0.3*canaleG + 0.2*canaleB)
	   //~ canaleR = canaleGRIGIO
	   //~ canaleG = canaleGRIGIO
	   //~ canaleB = canaleGRIGIO
	//~ }
	
void BN (unsigned char Sorgente[][3], int larg, int alt, unsigned char Destinazione[][3]){


	for(int i=0; i<larg*alt; i++)
	{
		int lum = (Sorgente[i][0]*0.5) + (Sorgente[i][1]*0.3) + (Sorgente[i][2]*0.2);
		Destinazione[i][0] = lum;
		Destinazione[i][1] = lum;
		Destinazione[i][2] = lum;
	}

}
