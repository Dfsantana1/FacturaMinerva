#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
using namespace std;
/**********************************************************
   Esta Funcion muestra en pantalla los caracteres ascii
														 */
void ascii () 
{
     for(int i = 0; i < 256; i++)
     {
          cout<<(char)i<<" ="<<i;
          cout<<endl;
     }
     system("pause");
}
/**********************************************************/
/***********************************************************
   Esta Funcion Permite Ubicar En La Pantalla Un Mensaje
   														  */
void posicion (int PosX, int PosY)
{
     HANDLE hConsoleOutput;
     COORD coord;
     hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
     // hasta esta parte se debe dejar fijo

     /*  A partir de aqui la sintaxis es la siguiente, como en el gotoxy (x,y): 
         x es para la posicion en horizontal y Y para el vertical */
     coord.X = PosX; coord.Y = PosY;
     SetConsoleCursorPosition (hConsoleOutput, coord);
}
/*********************************************************/
/*********************************************************
     Esta funcion permite escribir un texto con color la 
     escala va desde 0 hasta 255
														 */	
void color (int c)
{
     /* Esta funcion es para el color de las letras y la sintaxis es la 
        siguiente, el numero es el que cambia */
     SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),c);
     //HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);
     // SetConsoleTextAttribute (hConsoleHandle, 10);
}
/************************************************************/
/************************************************************
	 Esta Funcion Permite hacer una line horizontal 
	 en pantalla                                            */
void lineaH (int PosX,int PosY, int r )
{
     for (int i=0;i<=r;i++)
     {
         posicion(PosX+i,PosY);
         cout<<(char)196;
     }
}
/************************************************************/
/************************************************************
	 Esta Funcion Permite hacer una line horizontal 
	 en pantalla                                            */
void lineaV (int PosX,int PosY, int r )
{
     for (int i=0;i<=r;i++)
     {
         posicion(PosX,PosY+i);
         cout<<(char)179;
     }
}
/************************************************************/
/************************************************************
	 Esta Funcion Permite hacer una line horizontal 
	 en pantalla                                            */
void lineaV2 (int PosX,int PosY, int r )
{
     for (int i=0;i<=r;i++)
     {
         posicion(PosX,PosY+i);
         cout<<(char)186;
     }
}
/************************************************************/
/***********************************************************
     Esta Funcion Permite hacer una linea Doble horizontal 
	 en pantalla                                          */
void lineaH2 (int PosX,int PosY, int r )
{
     for (int i=0;i<=r;i++)
     {
         posicion(PosX+i,PosY);
         cout<<(char)205;
     }
}



/********************************************************
     Esta Funcion Permite hacer un cuadro en Pantalla
														*/
void cuadro (int PosX1, int PosY1, int PosX2, int PosY2)
{
     posicion(PosX1,PosY1);
     cout<<(char)218;
     lineaH (PosX1+1,PosY1,PosX2-2-PosX1+1);
     cout<<(char)191;
     for (int i=1;i<PosY2-PosY1;i++)
     {
         posicion(PosX1,PosY1+i);
         cout<<(char)179;
         posicion(PosX2+1,PosY1+i);
         cout<<(char)179;
     }
     posicion(PosX1,PosY2);
     cout<<(char)192;
     lineaH (PosX1+1,PosY2,PosX2-2-PosX1+1);
     cout<<(char)217;
}    
/************************************************************/
/***********************************************************
      Esta Funcion Permite hacer un cuadro en Pantalla    
	                                                      */
void cuadro2 (int PosX1, int PosY1, int PosX2, int PosY2)
{
     posicion(PosX1,PosY1);
     cout<<(char)201;
     lineaH2 (PosX1+1,PosY1,PosX2-2-PosX1+1);
     cout<<(char)187;
     for (int i=1;i<PosY2-PosY1;i++)
     {
         posicion(PosX1,PosY1+i);
         cout<<(char)186;
         posicion(PosX2+1,PosY1+i);
         cout<<(char)186;
     }
     posicion(PosX1,PosY2);
     cout<<(char)200;
     lineaH2 (PosX1+1,PosY2,PosX2-2-PosX1+1);
     cout<<(char)188;
}    
/************************************************************/
/************************************************************
       Esta Funcion Permite hacer un Relleno en Pantalla   
	   														*/
void relleno(int PosX1, int PosY1, int PosX2, int PosY2)
{
     for (int f=PosX1;f<=PosX2;f++)
     {
         for(int c=PosY1; c<=PosY2; c++)
		 {
		 	 posicion(f,c);
		 	 cout<<(char)177;
		 }		 
     }
}
/************************************************************/
/************************************************************
	   Esta Funcion Permite hacer un Relleno en Pantalla
															*/
void limpiar(int PosX1, int PosY1, int PosX2, int PosY2)
{
     for (int f=PosX1;f<=PosX2;f++)
     {
         for(int c=PosY1; c<=PosY2; c++)
		 {
		 	 posicion(f,c);
		 	 cout<<(char)32;
		 }		 
     }
}
/************************************************************/
/***********************************************************
		Esta Funcion Permite hacer una Ventana en Pantalla												  
														  */
void ventana(int PosX1, int PosY1, int PosX2, int PosY2)
{	
	relleno(PosX1+1, PosY1+1, PosX2+2, PosY2+1);
	limpiar(PosX1, PosY1, PosX2, PosY2);
	cuadro(PosX1, PosY1, PosX2, PosY2);
}

/************************************************************/
/***********************************************************
	    Esta Funcion Muestra la lista de colores desde
	    cero hasta 255
														  */
void colores () 
{
     for(int i = 0; i <= 255; i++)
     {
          color(i); 
		  cout<<(char)219<<" ="<<i;
		   cout<<endl;
     }
}
/************************************************************/
/************************************************************/



