int* CreaKernel(float sigma,int n);

void Blur_buffer (unsigned char Sorgente[][3], unsigned char Destinazione[][3],int larg,int alt,float sigma,int c);

void Blur (unsigned char Sorgente[][3], unsigned char Destinazione[][3],int larg,int alt,float sigma);

void Blur_colonne (unsigned char Sorgente[][3], unsigned char Destinazione[][3],int larg,int alt,float sigma,int c);
