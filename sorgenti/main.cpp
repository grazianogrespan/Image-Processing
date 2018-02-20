#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cmath>

#include "Headers/Dim.h"
#include "Headers/Scala.h"
#include "Headers/CaricaSalva.h"
#include "Headers/Seppia.h"
#include "Headers/Blur.h"
#include "Headers/Sharp.h"
#include "Headers/BN.h"
#include "Headers/Lumin.h"
#include "Headers/Contrasto.h"
#include "Headers/Zoom.h"
#include "Headers/Negativo.h"
#include "Headers/Trama.h"

using namespace std;

int main(int argc, char* argv[]){

    if (argc != 6){
        cout<<"ERRORE! l'uso corretto del comando è:  <fileinput> <comando> <dimensioni_x> <dimensioni_y> <fileoutput>"<<endl;
        return 1;
    }

	string filtro = argv[2];

	int largD = atoi(argv[3]);
	int altD = atoi(argv[4]);

	//ottengo le informazioni dal file di sorgente
	HAL infoS =OttieniHAL(argv[1]);

	//creo l'array della del file di sorgente
	unsigned char colorS[infoS.larg * infoS.alt][3];

	//creo l'array della del file di destinazione del filtro non scalato
	unsigned char colorFiltro[infoS.larg * infoS.alt][3];

	//creo l'header del file di sorgente
	unsigned char Header[infoS.header];

	//setto la larghezza dell'immagine di output ad una dimensione che sia il precedente multiplo di 4 nel caso non lo sia già
    int divisore= largD/4;
    largD= divisore*4;

    // carico in colorS i valori dell'immagine di input
	CaricaBmp24(argv[1], &colorS[0][0] , Header, infoS.larg, infoS.alt, infoS.header);

	//a assumerà un valore in base dal tipo di filtro da applicare all'immagine di input
	int  a = 0;
    if(filtro=="blur")  a=1;
    else if(filtro=="sharpen")  a=2;
    else if(filtro=="seppia")   a=3;
    else if(filtro=="bn")   a=4;
    else if(filtro=="lumin")    a=5;
    else if(filtro=="contrasto")    a=6;
    else if(filtro=="zoom") a=7;
    else if(filtro=="negativo") a=8;
    else if(filtro=="trama")    a=9;
	switch(a)
	{

		case 1:{
				cout<<endl<<endl;
				cout<<"  *************************************************************************\n";
				cout<<"  *                            METODO BLURRING                            *\n";
				cout<<"  *************************************************************************\n\n";

				bool continua=false;
				int sigma;

				while(!continua)
				{
					cout<<"  Inserire un tasso di blur positivo da applicare all'immagine\n\n";
					cout<<"                           !!! Attenzione !!!\n\n";
					cout<<"  Un valore superiore a 20 potrebbe comportare una sfocatura eccessiva \n";
					cout<<"  ed un tempo di elaborazione prolungato\n\n";
					cout<<"\u2B22  ";
					cin>>sigma;

					 if(sigma <= 0)
					{
						cout<<"  !!!\t Attenzione !!!\n";
						cout<<"  inserire un valore > 0\n";
                        continue;
					}
					if(sigma>=20)
					{
						cout<<"  !!!\t Attenzione !!!\n";
						cout<<"  valore elevato, continuare comunque? s/n?\n";
						char x;
						cin>>x;

						if(x == 's')
							continua=true;

					}
                    else{
                        continua=true;
                    }

				}

				Blur(colorS,colorFiltro,infoS.larg, infoS.alt,sigma);

				cout<<endl<<endl;
				cout<<"  *************************************************************************\n";
				cout<<"  *                  IMMAGINE ELABORATA CORRETTAMENTE                     *\n";
				cout<<"  *************************************************************************\n\n";
            }
        break;
        case 2:{
            cout<<endl<<endl;
            cout<<"  *************************************************************************\n";
            cout<<"  *                            METODO SHARPENING                           *\n";
            cout<<"  *************************************************************************\n\n";

            Sharp(colorS, infoS.larg, infoS.alt, colorFiltro);

            cout<<endl<<endl;
            cout<<"  *************************************************************************\n";
            cout<<"  *                  IMMAGINE ELABORATA CORRETTAMENTE                     *\n";
            cout<<"  *************************************************************************\n\n";
        }break;

        case 3:{
            cout<<endl<<endl;
            cout<<"  *************************************************************************\n";
            cout<<"  *                            METODO SEPPIA                              *\n";
            cout<<"  *************************************************************************\n\n";

            Seppia(colorS, infoS.larg, infoS.alt, colorFiltro);

            cout<<endl<<endl;
            cout<<"  *************************************************************************\n";
            cout<<"  *                  IMMAGINE ELABORATA CORRETTAMENTE                     *\n";
            cout<<"  *************************************************************************\n\n";


        }break;

        case 4:{
            cout<<endl<<endl;
            cout<<"  *************************************************************************\n";
            cout<<"  *                         METODO SCALA DI GRIGI                         *\n";
            cout<<"  *************************************************************************\n\n";

            BN(colorS, infoS.larg, infoS.alt, colorFiltro);

            cout<<endl<<endl;
            cout<<"  *************************************************************************\n";
            cout<<"  *                  IMMAGINE ELABORATA CORRETTAMENTE                     *\n";
            cout<<"  *************************************************************************\n\n";


        }break;

		case 5:{
			cout<<endl<<endl;
			cout<<"  *************************************************************************\n";
			cout<<"  *                            AUMENTO LUMINOSITA'                        *\n";
			cout<<"  *************************************************************************\n\n";

			bool continua=false;
			int sigma;

			while(!continua)
			{
				cout<<"  Inserire un valore positivo per aumentare la luminosità all'immagine\n\n";
				cout<<"                                  oppure\n\n";
				cout<<"  Inserire un valore negativo per diminuire la luminosità all'immagine\n\n";
				cout<<"\u2B22  ";
				cin>>sigma;
//il valore  inserito è volutamente maggiore di 10 perchè nella funz. lumin il valore viene diviso per 10 per fare un aumento graduale della luminosità
				if(sigma >= 0 && sigma <= 10)
				{
					cout<<" \n !!!\t Attenzione !!!\n";
					cout<<"  il valore inserito non comporta nessuna modifica all'immagine\n";
					cout<<"  inserire un valore > 10 per ottenere l'effetto desiderato \n\n";
				}
				else{
					continua=true;
				}
			}

			if(sigma)
				Luminosita(colorS,infoS.larg, infoS.alt,colorFiltro,sigma);

			cout<<endl<<endl;
			cout<<"  *************************************************************************\n";
			cout<<"  *                  IMMAGINE ELABORATA CORRETTAMENTE                     *\n";
			cout<<"  *************************************************************************\n\n";
		}break;

		case 6:{
			cout<<endl<<endl;
			cout<<"  *************************************************************************\n";
			cout<<"  *                             AUMENTO CONTRASTO                         *\n";
			cout<<"  *************************************************************************\n\n";

			bool continua=false;
			int sigma;

			while(!continua)
			{
				cout<<"  Inserire un valore positivo per aumentare il contrasto all'immagine\n\n";
				cout<<"                                  oppure\n\n";
				cout<<"  Inserire un valore negativo per diminuire il contrasto all'immagine\n\n";
				cout<<"\u2B22  ";
				cin>>sigma;

				if(sigma == 0)
				{
					cout<<"  !!!\t Attenzione !!!\n";
					cout<<"  il valore inserito non comporta nessuna modifica all'immagine, continuare comunque? s/n?\n\n";
					char x;
					cin>>x;

					if(x == 's')
						continua=true;

				}
				else{
					continua=true;
				}
			}

			if(sigma)
				Contrasto(colorS,infoS.larg, infoS.alt,colorFiltro,sigma);

			cout<<endl<<endl;
			cout<<"  *************************************************************************\n";
			cout<<"  *                  IMMAGINE ELABORATA CORRETTAMENTE                     *\n";
			cout<<"  *************************************************************************\n\n";
		}break;

		case 7:{
            cout<<endl<<endl;
            cout<<"  *************************************************************************\n";
            cout<<"  *                              METODO ZOOM                              *\n";
            cout<<"  *************************************************************************\n\n";

			bool continua=false;
			int zoom;

			while(!continua)
			{
				cout<<"  Inserire un valore positivo per aumentare lo zoom all'immagine\n\n";
				cout<<"\u2B22  ";
				cin>>zoom;

				if(zoom <= 1)
				{
					cout<<"  !!!\t Attenzione !!!\n";
					cout<<"  il valore inserito non comporta nessuna modifica all'immagine\n";
					cout<<"  inserire un valore > 1 \n";
				}
				else{
					continua=true;
				}
			}

			if(zoom)
				Zoom(colorS, infoS.larg, infoS.alt, colorFiltro, zoom);


            cout<<endl<<endl;
            cout<<"  *************************************************************************\n";
            cout<<"  *                  IMMAGINE ELABORATA CORRETTAMENTE                     *\n";
            cout<<"  *************************************************************************\n\n";


        }break;

        case 8:{
            cout<<endl<<endl;
            cout<<"  *************************************************************************\n";
            cout<<"  *                              METODO NEGATIVO                          *\n";
            cout<<"  *************************************************************************\n\n";

            Negativo(colorS, infoS.larg, infoS.alt, colorFiltro);

            cout<<endl<<endl;
            cout<<"  *************************************************************************\n";
            cout<<"  *                  IMMAGINE ELABORATA CORRETTAMENTE                     *\n";
            cout<<"  *************************************************************************\n\n";


        }break;

        case 9:{
            cout<<endl<<endl;
            cout<<"  *************************************************************************\n";
            cout<<"  *                            METODO TRAMA                               *\n";
            cout<<"  *************************************************************************\n\n";
            bool continua=false;
            int sigma;

            while(!continua)
            {
                cout<<"  Inserire un valore positivo > 1 per aumentare lo spessore della trama all'immagine\n\n";
                cout<<"\u2B22  ";
                cin>>sigma;
                if(sigma <= 1){
                    cout<<"  !!!\t Attenzione !!!\n";
                    cout<<"  il valore inserito non corretto!\n";
                }
                else if(sigma > 7)
                {
                    cout<<"  !!!\t Attenzione !!!\n";
                    cout<<"  il valore inserito comporta una modifica invasiva all'immagine\n";
                    cout<<"  Per avere dei risultati accettabili, inserire un valore positivo tra 1 e 7  \n";
                    cout<<"	 continuare comunque? s/n?\n";
                    char x;
                    cin>>x;

                    if(x == 's')
                        continua=true;

                }
                else{
                    continua=true;
                }
            }

            if(sigma)
                Trama(colorS, infoS.larg, infoS.alt, colorFiltro, sigma);



            cout<<endl<<endl;
            cout<<"  *************************************************************************\n";
            cout<<"  *                  IMMAGINE ELABORATA CORRETTAMENTE                     *\n";
            cout<<"  *************************************************************************\n\n";


        }break;

        default:{
        cout<<endl<<" filtro non trovato, inserisci uno di questi comandi per applicare un effetto all'imagine di input \n";
		cout<<"<blur>\t<sharpen>\t<seppia>\t<bn>\t<lumin>\t<contrasto>\t<zoom>\t<negativo>\t<trama>\n";
		return 1;
		}
	}
    //richiamo Resize per sistemare colorD

    if(largD == infoS.larg && altD == infoS.alt)
        SalvaBmp24(argv[5], &colorFiltro[0][0] , Header, infoS.larg, infoS.alt, infoS.header);

	else{
        unsigned char colorD2[largD * altD][3];

        Scala(colorFiltro, infoS.larg, infoS.alt, colorD2, largD, altD);

        SalvaBmp24(argv[5], &colorD2[0][0] , Header, largD, altD, infoS.header);

    }
    return 0;

}
