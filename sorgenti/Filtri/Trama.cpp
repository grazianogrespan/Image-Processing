#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

/*
 La funzione trama fa un effetto simile ad una texture,questo perchè salta in lettura un numero s pixel definito dall'utente.
 * */
void Trama (unsigned char Sorgente[][3], int larg, int alt, unsigned char Destinazione[][3], int s){

	for(int i=0; i<larg*alt; i+=s)
	{
		Destinazione[i][0] = Sorgente[i][0];
		Destinazione[i][1] = Sorgente[i][1];
		Destinazione[i][2] = Sorgente[i][2];
	}
}
