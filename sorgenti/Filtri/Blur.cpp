#include <math.h>

int sizes[3];

void Blur_colonne (unsigned char Sorgente[][3], unsigned char Destinazione[][3],int larg,int alt,float sigma,int c);

void Blur_righe (unsigned char Sorgente[][3], unsigned char Destinazione[][3],int larg,int alt,float sigma,int c);

int* CreaKernel(float sigma,int n) // deviazione standard, dim del kernel
{
    int wIdeal = sqrt((12*sigma*sigma/n)+1);  // larghezza media ideale del filtro 
    int wl = floor(wIdeal);  
    
    if(wl%2==0) 
		wl--;
    int wu = wl+2;
				
    int mIdeal = (12*sigma*sigma - n*wl*wl - 4*n*wl - 3*n)/(-4*wl - 4);
    int m =round(mIdeal);  
      
    for(int i=0; i<n; i++)
    { 
		if( i < m)
			sizes[i]=wl;
		else
			sizes[i]=wu;	
	}
	
    return sizes;
}

//funzione che crea il buffer per le operazioni fatte sulle righe e sulle colonne dell'immagine
void Blur_buffer (unsigned char Sorgente[][3], unsigned char Destinazione[][3],int larg,int alt,float sigma,int c) {
    for(int i=0; i<larg*alt; i++) 
		Destinazione[i][c] = Sorgente[i][c];
		
    Blur_colonne(Destinazione, Sorgente, larg, alt, sigma,c);
    Blur_righe(Sorgente, Destinazione, larg, alt, sigma,c);
}

void Blur (unsigned char Sorgente[][3], unsigned char Destinazione[][3],int larg,int alt,float sigma) {
    int* bxs = CreaKernel(sigma, 3);
    for(int c=0; c<3; c++)
    {
		Blur_buffer (Sorgente, Destinazione, larg, alt, (bxs[0]-1)/2,c);
		Blur_buffer (Destinazione, Sorgente, larg, alt, (bxs[1]-1)/2,c);
		Blur_buffer (Sorgente, Destinazione, larg, alt, (bxs[2]-1)/2,c);
	}
}
void Blur_colonne (unsigned char Sorgente[][3], unsigned char Destinazione[][3],int larg,int alt,float sigma,int c) {
    for(int i=0; i<alt; i++)
        for(int j=0; j<larg; j++)  {
            float val = 0;
            for(int ix=j-sigma; ix<j+sigma+1; ix++) {
                int x = fmin(larg-1, fmax(0, ix));
                val += Sorgente[i*larg+x][c];
            }
            Destinazione[i*larg+j][c] = val/(sigma+sigma+1);
        }
}   

void Blur_righe (unsigned char Sorgente[][3], unsigned char Destinazione[][3],int larg,int alt,float sigma,int c) {
    for(int i=0; i<alt; i++)
        for(int j=0; j<larg; j++) {
            float val = 0;
            for(int iy=i-sigma; iy<i+sigma+1; iy++) {
                int y = fmin(alt-1, fmax(0, iy));
                val += Sorgente[y*larg+j][c];
            }
            Destinazione[i*larg+j][c] = val/(sigma+sigma+1);
        }
}

