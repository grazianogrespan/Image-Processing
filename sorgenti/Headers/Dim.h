//definizione della struttura.
struct HAL{
	
	int header;
	int larg;
	int alt;
	
	HAL(int a=0,int b=0,int c=0){
		header=a;
		larg=b;
		alt=c;
	}
	
};

HAL OttieniHAL(char* path);
