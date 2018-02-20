#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

//riscala l'immagine e ne fa la media dei 4 punti attorno

int LeggiInterpolato(float x, float y, int c, unsigned char ImmagineS1[][3], int largS, int altS){
	double v1, v2, v3, v4;
	int X = (int) x;
	int Y = (int) y;
	x -= X;
	y -= Y;

	if(X < 0) X = 0;
	if(X >= largS - 1) X = largS - 1;
	if(Y < 0) Y = 0;
	if(Y >= altS - 1) Y = altS - 1;

	v1 = ImmagineS1[X + (largS * Y)][c];
	v2 = ImmagineS1[X + 1 + (largS * Y)][c];
	v3 = ImmagineS1[X + (largS * (Y + 1))][c];
	v4 = ImmagineS1[X + 1 + (largS * (Y + 1))][c];

	return( (v1 * (1 - x) * (1 - y)) +
			(v2 * x * (1 - y)) +
			(v3 * (1 - x) * y) +
			(v4 * x * y) );
}

void Scala(unsigned char ImmagineS1[][3], int largS, int altS, unsigned char ImmagineD[][3], int largD, int altD){
	int x, y;
	int l;
	float u, v;

	float larg= largS; //SX
	float alt= altS; //SY

	float larg2= largD; //DX
	float alt2= altD; //DY

	float factW= larg/larg2;
	float factH= alt/alt2;

    for(int c=0; c<3; c++){
        for(y = 0;y < altD;y++) {
        	for(x = 0;x < largD;x++) {
        		u = factW * x;
        		v = factH * y;
        		l = LeggiInterpolato(u, v, c, ImmagineS1, largS, altS);
        		if(l > 255) l = 255;
        		if(l < 0) l = 0;
        		ImmagineD[x + (y * largD)][c] = l;
        	}
        }
    }

}
