
/*Universidad te cnologica de pereira
Programa ISC
Materia : Estructura  de datos
Nombre del autor: Laura Quintero Montoya, Diego	Fernando Santana Fernandez.
Fecha de Actualizacion: 15 de Septiembre de 2022
Titulo del Trabajo: ProyectoFacturaMinerva
Version:5.2
*/

#include <iostream>
#include  "Factura.h"

using namespace std;

//---------------------------------------------------------
/*Nombre del procedimiento  main()
Objetivo: al llamr la funcion se realiza todo la implentacion de las colas en c++
parametros: Al ser un un main no tiene parametro.
			Ejemplo: main,  al ser el menu del programa en este caso es el que ejecuta el programa principal ya que todas sus funciones y variables estan
			                adentro de ella.
*/


int main()
{
	Menu();
	Factura P=NULL;
	long AuxNit;
	int op;
	
	do
	{
		system("cls");
		Menu(); 
		color(15);posicion(70,4);cin>>op;
		switch (op)
		{
			case 1: system("cls");
					system("color 0a");
					
					GenerarFactura(P);
					break;
					
			case 2: system("cls");
			        system("color 0a");
					cout<<"\n\nMostrando factura: \n\n";

					   MostrarFactura(P);;

					break;
			
			case 3: system("cls");
			        system("color 0a");
					cout<<"ingrese Nit de la empresa para buscar la buscar  "<<endl;
					cin>>AuxNit;
					BuscarFactura(P,AuxNit);
					break;
					
			case 4: system("cls");
			        system("color 0a");
			        cout<<"ingrese Nit a Modificar  "<<endl;
					cin>>AuxNit;
					ModificarFactura(P,AuxNit);

					break;
					
			case 5: system("cls");
			        system("color 0a");
					
					ClientesRecientes(P);
					break;
					
			case 6: system("cls");
			        system("color 0b");
					
					MostrarClientes(P);
					break;
					
			case 7: system("cls");
					system("color 0a");
				//	cout<<"ingrese Nit a eliminar  "<<endl;
					//cin>>AuxNit;
					EliminarFactura(P);
					break;		
		}	
		cout<<endl<<endl;
		posicion(1,40);
		system("pause");system("cls");
	}while(op!=8);
}


