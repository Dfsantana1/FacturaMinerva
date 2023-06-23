/*Universidad te cnologica de pereira
Programa ISC
Materia : Estructura  de datos
Nombre del autor: Laura Quintero Montoya, Diego	Fernando Santana Fernandez.
Fecha de Actualizacion: 15 de Septiembre de 2022
Titulo del Trabajo: Proyecto Factura Minerva
Version:5.0
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <string.h>
#include "fecha.h"
#include "ventanas.h"
#include <conio.h>

//-------------------------------------------------------
/*Nombre del procedimiento  Detalle
Objetivo: crear una estructura para guardar todos los detalles para calcular la factura
parametros: Al ser una funcion tipo estructura no tiene parametro.
			Ejemplo: Detalle, al llamar esa funcion se aguarda se le puede asignar los detalles pedidos o requeridos
*/
struct Detalle
{ 
	char Codigo[10];
	char Descripcion [30];
	long ValorUnit;
	long ValorToTal;
	int NumProducto;
	int cant;
	Detalle *SgtDetalle;
};
typedef struct Detalle  *DetalleFactura;

//-------------------------------------------------------
/*Nombre del procedimiento  Factur
Objetivo: crear una estructura para guardar todos los detalles para guardar la informacion de la factura
parametros: Al ser una funcion tipo estructura no tiene parametro.
			Ejemplo: Detalle, al llamar esa funcion se aguarda se le puede asignar los detalles pedidos o requeridos
*/
struct Factur
{
	int numFact;
	Fecha F;	 //revisar la manera adecuada de llamar la estructura fehca
	long  Nit;
	char vendididoA [50];
	char telefono [50];
	char cuidad[20];
	long iva;
	long total;
	Factur *SgtFact;
	DetalleFactura Pro;
};
typedef  struct  Factur *Factura;


//-----------------------------------------------------------------------------------------------------
/*Nombre del procedimiento  promediolista(DetalleFactura D)
Objetivo: recorrer una lista de productos y retornar su total
parametros DetalleFactura D--> recibe una estructura de tipo Detallle Factura
			Ejemplo: PromedioLista(q) Recibe una lista y retorna la sumatoria de los valores totales de cada producto 
*/
long PromedioLista(DetalleFactura &D)
{
	long sumatoria=0; //se define  un auxiliar sumatoria
	while(D != NULL)
	{
		sumatoria= sumatoria+D->ValorToTal; //recorro la lista de productos y voy sumando sus valores totales
		D= D->SgtDetalle;	
	}
		return sumatoria; //retorno el valor de la sumatoria
	
}
//_--------------------------------------------------------------------------------------------------
/*Nombre del procedimiento  AgregarProducto(DetalleFactura &D)
Objetivo: Agregar un Producto en una lista de productos
parametros DetallleFactura D--> recibe una estructura de tipo DetalleFactura
			Ejemplo: AgregarProducto(D) Recibe como parametro una lista de detalles y pide los datos para agregar un nodo mas
*/
void agregarProducto(DetalleFactura &D) //funcion para agregar nodos de  productos
{
	
	DetalleFactura pr,t; //defino dos auxiliares de tipo factura
	pr = new(struct Detalle ); //genero espacio en memoria para mi nuevo nodo
	pr->SgtDetalle = NULL;
	int cont=1; //contador para generar especificacion de  posicion en cada nodo
	ventana(15,2,100,22);
	posicion(37,3);cout<<"INGRESO DE DETALLE ";
	
	posicion(16,5);cout<<"ingrese cantidad del producto";
	posicion(46,5);cin>>pr->cant;
	posicion(16,7);cout<<"ingrese codigo del producto";
	fflush(stdin);
	posicion(44,7);cin.getline(pr->Codigo,10,'\n');
	posicion(16,9);cout<<"ingrese precio del  producto ";
	posicion(45,9);cin>>pr->ValorUnit;
	posicion(16,11);cout<<"ingrese Descripcion";
	fflush(stdin);
	posicion(37,11);cin.getline(pr->Descripcion,30,'\n');
	pr->ValorToTal=pr->ValorUnit*pr->cant;
	//ingreso los datos necesarios para llenar adecuadamente mi nodo
	pr->NumProducto=1;	
	if(D == NULL)
	{	
		pr->NumProducto=cont; //si es el primer elemento de la sublista
		D = pr; 
		cont++;
	}
	else
	{
		cont++; //aumento mi contador en uno para el segundo nodo 
		t = D;
		while(t->SgtDetalle!=NULL)
		{
			t = t->SgtDetalle;
			cont++;
		}
		D->NumProducto=cont;
		t->SgtDetalle = pr;
	
	}
}
//--------------------------------------------------------------------------------------------------------------------------
/*Nombre del procedimiento  GenerarFactura(Factura &D)
Objetivo: Agregar un cliente y sus datos a una lista 
parametros Factura D--> recibe una estructura de tipo Factua
			Ejemplo: GenerarFactura(P) Recibe como parametro una lista de facturas y pide los datos para agregar un nodo mas
*/			
void GenerarFactura(Factura &P) //funcion para generar Factura
{
	system("color 0a");
	Factura q,t;
	DetalleFactura aux;
	q = new(struct Factur);
	q->SgtFact =NULL;
	int cont=1;
	int op;
	ventana(15,2,100,22);
	lineaV(50,5,16);
	//pido los datos que iran en la factura
	posicion(37,3);cout<<"INGRESO DE FACTURA ";
	
	posicion(16,5);cout<<"ingrese a"<<(char)164 <<"o: ";
	posicion(29,5);cin>>q->F.year;
	posicion(16,7);cout<<"ingrese el numero del mes: ";
	posicion(44,7);cin>>q->F.month;
	posicion(16,9);cout<<"ingrese dia ";
	posicion(29,9);cin>>q->F.day;
	
	bool verificacion = ValidarFecha(q->F);
	if (verificacion == true)  //validaion de fecha si es incorrecta el progrma vuelve a pedir estos datos
	{
	posicion(53,5);cout<<"ingrese cuidad ";
	posicion(68,5);fflush(stdin);
	posicion(68,5);cin.getline(q->cuidad,20,'\n');
  					//tengo dudas si para leer el dato lo mas adecuado es usar cin ya que vamos a tener espacios
	posicion(53,7);cout<<"ingrese NIT: ";
	posicion(67,7);cin>>q->Nit;
	q->numFact=cont;
	posicion(53,9);cout<<"ingrese numero de telefono: ";
	fflush(stdin);
	posicion(82,9);cin.getline(q->telefono,10,'\n');

	posicion(53,11);cout<<"ingrese nombre del cliente: ";
		fflush(stdin);
	posicion(82,11);cin.getline(q->vendididoA,50,'\n');
	q->numFact=cont;
	q->Pro=NULL;
//	system("cls");
	lineaH(53,12,37);
	posicion(53,13);cout<<"Pulse 1 para ingresar producto: ";
	posicion(86,13);cin>>op;
	system("cls");
	while(op==1) //while para agregar productos a la factura
	{
		system("cls");
		agregarProducto( q->Pro);	
		lineaH(16,12,74);
		posicion(16,13);cout<<"ingrese 1 si desea ingresar un producto o 2 para volver al menu: ";
		posicion(81,13);cin>>op;
		
	}
	aux=q->Pro;

	q->total=PromedioLista(aux);
	q->iva=q->total*0.19;
	if(P == NULL)
	{	P = q;
		q->numFact=cont;
	}
	else
	{
		cont++;
		t = P;
		while(t->SgtFact !=NULL)
		{	
			cont ++;
			t = t->SgtFact;
		}
		q->numFact=cont;
		t->SgtFact = q;
	}
}
else{
		system("cls");
			color(4);
		ventana(5,3,60,10);
		posicion(9,6);
		color(6);
		//cout<<"menu ppal";
        cout << "La fecha NO es valida, por favor ingrese una nueva";
        posicion(1,40);
        system("PAUSE");

        GenerarFactura(P);
    }

}


//-----------------------------------------------------------------------------------------------------
/*Nombre del procedimiento  MostrarDetalle(DetalleFactura  D)
Objetivo: mostrar los productos y sus especificaciones
parametros DetalleFactura D--> recibe una estructura de tipo DetalleFactura
			Ejemplo: MostrarDetalle(P) Recibe como parametro una lista de Productos y imprime en pantalla los detalles
*/

void MostrarDetalle(DetalleFactura D) //funcion para mostrar detalles
{	int i = 1;
	int op = 1;
	while (D != NULL && op != 2)
	{
		//color(14);
		cuadro(15,7,80,12);
		posicion(17,8);cout<<"Codigo";
		posicion(16,10);cout<<D->Codigo;
		lineaV(24,8,3);
		posicion(25,8);cout<<"Descripcion";
		posicion(25,10);cout<<D->Descripcion;
		lineaV(47,8,3);
		posicion(48,8);cout<<"Cantidad";
		posicion(48,10);cout<<D->cant;
		lineaV(52,8,3);
		posicion(53,8);cout<<"Valor ToTal";
		posicion(53,10);cout<<D->ValorToTal;
		/*
		////////////////////////////////////
		cout<<' '<<i<<") Cantidad "<<D->cant<<endl;
		//////////////////////////////////////
		cout<<' '<<i<<") Codigo "<<D->Codigo<<endl;
		cout<<' '<<i<<") Describcion"<<D->Descripcion<<endl;
		cout<<' '<<i<<") valor total"<<D->ValorToTal<<endl;
	*/
		D = D->SgtDetalle;
		i++;
		color(4);
		ventana(3,15,46,20);
		posicion(9,6);
		color(6);
	//	cuadro(85,7,102,12);
		 posicion (4,16);cout<<"Presione 1 para mostra mas detalles: "<<endl;
		   posicion (45,16);  cin>>op;
	}
	
	
	
		
		color(4);
		ventana(3,15,46,20);
		posicion(9,6);
		color(6);
	//	cuadro(85,7,102,12);
		posicion (4,16);cout<<"Ya no hay mas detalle"<<endl;
		   //posicion (20,16);  cin>>op;
	
	

	
}
//--------------------------------------------------------------------------------
/*Nombre del procedimiento  MostrarFactura(Factura P)
Objetivo: mostrar los clientes su informacion y los productos de cada factura
parametros Factura  P--> recibe una estructura de tipo Factura
			Ejemplo: MostrarFactura(P) Recibe como parametro una lista de facturas muestra cada factura info de sus usuariso y de los productos de la lista
*/
void MostrarFactura(Factura P) //funcion para mostrarb facturas 
{
	int i = 1;
	int op =1;
	
	while (P != NULL && op!= 2){ 
			system("cls");
			cuadro(15,2,80,7);
			posicion(47,4);cout<<"FACTURA NUMERO "<<P->numFact;
			lineaV(75,3,3);posicion (76,3);cout<<"a"<<(char)164 <<"o";
		    posicion (76,4);cout<<P->F.year;
			lineaV(71,3,3);posicion (72,3);cout<<"mes";
			posicion (72,4);cout<<P->F.month;
			lineaV(67,3,3);posicion (68,3);cout<<"dia";	
			posicion (68,4); cout<<P->F.day;lineaV(45,3,3);
			
			
			posicion(16,3);cout<<"Vendido a: "<<P->vendididoA;
			posicion(16,4);cout<<"Nit: "<<P->Nit;
			posicion(16,5);cout<<"Ciudad: "<<P->cuidad;
			posicion(16,6);cout<<"Telefono: "<<P->telefono;
			
			lineaV(65,8,3);
			posicion(66,8);cout<<"Iva";
			posicion(66,10);cout<<P->iva;
			lineaV(70,8,3);
			posicion(71,8);cout<<"Total";
			posicion(71,10);cout<<P->total;;
			/*
	
			cout<<' '<<i<<"cuidad) "<<
			cout<<' '<<i<<"telefono) "<<P->telefono;
			cout<<' '<<i<<
			cout<<' '<<i<<"iva)"<< P->iva;
			cout<<' '<<i<<"Total) "<<P->total;*/
	
			MostrarDetalle(P->Pro);
			P = P->SgtFact;
			i++;
		color(4);
		ventana(3,15,52,20);
		posicion(9,6);
		color(6);
		posicion (4,16);cout<<"Presione 1 para mostra mas facturas: "<<endl;
		posicion (45,16);  cin>>op;
		//	cout<<"Presione 1 para mostra mas factura: "<<endl;
		  // posicion (87,4);  cin>>op;
	       // MostrarFactura(P);
		
	}
	system("cls");
		color(4);
		ventana(3,15,68,20);
		posicion(9,6);
		color(6);
	//	cuadro(85,7,102,12);
		posicion (4,16);cout<<"No hay  factura que mostrar pulsa cualquier boton para ir al menu ";
		   //posicion (20,16);  cin>>op;
		//cout<<"No hay  factura que mostrar pulsa cualquier boton para ir al menu "<<endl;
		
	    posicion(1,40);
        system("PAUSE");
}	
//----------------------------------------------------------------------
/*Nombre del procedimiento  BuscarFactura(Factura &p,Long NitaBUs)
Objetivo: mostrarla factura que est registra con el nit a buscar
parametros DFactura p--> recibe una estructura de tipo factura y
			long nitabus-->recibe un nit a buscar este es tipo long
			Ejemplo: BuscarFactura(P,1) en la lista de las facturas busca la que tenga el nit=1 y la muestra en pantalla
*/
void BuscarFactura(Factura &p,long NitaBus) //funcion que muestra un nodo de la lista buscado con el nit
	
{
	Factura q = p;
	int i = 1, band = 0;
	while(q!=NULL)
	{
		if(q->Nit == NitaBus)
		{
		//	cout<<endl<<" Encontrada en posicion "<<i<<endl; //recorre la lista y la bandera determina si el elemento existe
			band ++;
			cuadro(15,2,80,7);
			posicion(47,4);cout<<"FACTURA ENCONTRADA # "<<q->numFact;
			lineaV(75,3,3);posicion (76,3);cout<<"a"<<(char)164 <<"o";
		    posicion (76,4);cout<<q->F.year;
			lineaV(71,3,3);posicion (72,3);cout<<"mes";
			posicion (72,4);cout<<q->F.month;
			lineaV(67,3,3);posicion (68,3);cout<<"dia";	
			posicion (68,4); cout<<q->F.day;lineaV(45,3,3);
			
			
			posicion(16,3);cout<<"Vendido a: "<<q->vendididoA;
			posicion(16,4);cout<<"Nit: "<<q->Nit;
			posicion(16,5);cout<<"Ciudad: "<<q->cuidad;
			posicion(16,6);cout<<"Telefono: "<<q->telefono;
			
			lineaV(65,8,3);
			posicion(66,8);cout<<"Iva";
			posicion(66,10);cout<<q->iva;
			lineaV(70,8,3);
			posicion(71,8);cout<<"Total";
			posicion(71,10);cout<<q->total;;
		MostrarDetalle(q->Pro);
		}
		q = q->SgtFact;
		i++;
	}
	if (band == 0){
		color(4);
		ventana(5,3,60,10);
		posicion(10,6);
		color(6);
		//cout<<"menu ppal";
        cout << "Nit no encontrado";
        posicion(1,40);
	}
		
	else
	{
		system("cls");
		color(4);
		ventana(5,3,60,10);
		color(5);
		posicion(7,6);cout<<"Ya no hay mas Factura que mostrar";
		color(6);
		posicion(7,9);cout<<"Facturas registradas con el nit "<<NitaBus<<" solo existen "<<band;	
		posicion(1,40);
	}

}

//---------------------------------------------------------------------------------------------------
/*Nombre del procedimiento  BuscarFactura(Factura &p,Long NitaBUs)
Objetivo: modificar factura que est registra con el nit a buscar
parametros Factura p--> recibe una estructura de tipo factura y
			long niitabus-->recibe un nit a buscar este es tipo long
			Ejemplo: BuscarFactura(P,1) en la lista de las facturas busca la que tenga el nit=1 y modifica la  informacion de la factura
*/
void ModificarFactura(Factura &F, long auxNit) //busca una factura y modifica los datos de factura 
{
	Factura q = F;
	int op;
	int i = 1, band = 0;
	while(q!=NULL)
	{
		if(q->Nit == auxNit)
		{   system("cls");
			ventana(5,102,90,112);
			posicion(7,104);
			cout<<"Factura Encontrada: Factura numero: "<<i<<endl;
			color(4);
		    
		    posicion(7,110);
		    color(6);
			band = 1;
			cout<<"Si deseas Modificar Informacion de la factura ingrese 1  ";
			posicion(66,110);cin>>op;
			if(op==1)
			{
				

				ventana(15,2,100,22);
				lineaV(50,5,16);
				//pido los datos que iran en la factura
				posicion(37,3);cout<<"INGRESO DE FACTURA ";
				
				posicion(16,5);cout<<"ingrese a"<<(char)164 <<"o: ";
				posicion(29,5);cin>>q->F.year;
				posicion(16,7);cout<<"ingrese el numero del mes: ";
				posicion(44,7);cin>>q->F.month;
				posicion(16,9);cout<<"ingrese dia ";
				posicion(29,9);cin>>q->F.day;
				posicion(53,5);cout<<"ingrese cuidad ";
				posicion(68,5);fflush(stdin);
				posicion(68,5);cin.getline(q->cuidad,20,'\n');
			  					//tengo dudas si para leer el dato lo mas adecuado es usar cin ya que vamos a tener espacios
				posicion(53,7);cout<<"ingrese NIT: ";
				posicion(67,7);cin>>q->Nit;
			//	q->numFact=cont;
				posicion(53,9);cout<<"ingrese numero de telefono: ";
				fflush(stdin);
				posicion(82,9);cin.getline(q->telefono,10,'\n');
			
				posicion(53,11);cout<<"ingrese nombre del cliente: ";
					fflush(stdin);
				posicion(82,11);cin.getline(q->vendididoA,50,'\n');

			
			}
			system("cls");
		    color(4);
		    ventana(5,3,60,10);
		    posicion(9,6);
		    color(6);
			band = 1;
			cout<<"Factura modificada"<<endl;
		}
		q = q->SgtFact;
		i++;
	}
	if (band == 0){
		system("cls");
		color(4);
		ventana(5,3,60,10);
		posicion(9,6);
		color(6);
		//cout<<"menu ppal";
        cout << "Numero no encontrado";
        posicion(1,40);
        
	}
		
}
//-----------------------------------------------------------------------
/*Nombre del procedimiento  Eliminar(Factura &p,Long NitaBUs)
Objetivo: eliminar factura que est registra con el nit a buscar
parametros Factura p--> recibe una estructura de tipo factura y
			long nitabus-->recibe un nit a buscar este es tipo long
			Ejemplo: EliminarFactura(P,1) en la lista de las facturas busca la que tenga el nit=1 y la elimina
*/
void EliminarFactura(Factura &Fac ) //elimina una factura  buscada por ekl nit
{
		
	Factura p,ant;
	p =Fac;
	long ANit;
	color(13);
	ventana(5,3,60,10);
	posicion(9,6);
	color(6);
							//cout<<"menu ppal";
	cout << "ingrese Nit a Modificar";
	posicion(33,6);cin>>ANit;

	if (Fac !=NULL)
	{
		while(p!=NULL)
		{
			if(p->Nit==ANit)
			{
				if(p==Fac)
					Fac = Fac->SgtFact;
					else
						ant->SgtFact = p->SgtFact;
					delete(p);
							color(4);
							ventana(5,3,60,10);
							posicion(9,6);
							color(6);
							//cout<<"menu ppal";
					        cout << "Factura eliminada";
					        posicion(1,40);
					        system("PAUSE");
				//	return;
			}
			ant = p;
			p = p->SgtFact;
		}

	}
	else
	{
		color(4);
		ventana(5,3,60,10);
		posicion(9,6);
		color(6);
		//cout<<"menu ppal";
        cout << "Factura vacia";
        posicion(1,40);
        
	}

}
	
//---------------------------------------------------------------------------	

/*Nombre del procedimiento  AgregarDetalle(Factura &p,Long NitaBUs)
Objetivo: agregar productos en lafactura que est registra con el nit a buscar
parametros Factura p--> recibe una estructura de tipo factura 
			int nitabus-->recibe un numero de factura a buscar 
			Ejemplo: AgregarDetalle(P,1) en la lista de las facturas busca la que tenga la posicioon =1 y agrega 1 o mas detalles a la factura
*/

void AgregarDetalle(Factura &F, int pos) //segun la lista # agrega detalle
{
	Factura q = F;
	int op;
	int i = 1, band = 0;
	while(q!=NULL)
	{
		if(q->numFact == pos)
		{
			do
			{
				agregarProducto(q->Pro);
				cout<<"deseas ingresar mas productos ingrese 1 "<<endl;
				cin>>op;
				
				
			}while(op == 1);
		
		
			band = 1;
		}
		q = q->SgtFact;
		i++;
	}
	if (band == 0)
		cout<<"\n\n Numero no encontrado...!"<<endl;
}
//-------------------------------------------------------
/*Nombre del procedimiento  nodo1
Objetivo: crear una estructura para guardar un elemto y un puntero
parametros: Al ser una funcion tipo estructura no tiene parametro.
			Ejemplo: nodo1 , al llamar esa funcion se aguarda se le puede asignar el elemento y el puntero 
*/
struct nodo1
{
	char cliente[50];
	struct nodo1 *Siguiente;
};
//--------------------------------------------------------

/*Nombre del procedimiento  Cola
Objetivo: crear una estructura para realiazar punteros en los nodo.
parametros: Al ser una funcion tipo estructura no tiene parametro.
			Ejemplo: Cola , al llamar esa funcion se aguarda se le puede asignar el puntero Adelantero o Atras
*/
struct Cola							//Siempre que insertamos un
{                                   //Elemento lo hacemos en el ultimo (atrás)
	nodo1 *Adelante; 				//Pero lo tenemos que conectar de alguna
	nodo1 *Atras;              		//manera con la lista (adelante)
};
/*Nombre del procedimiento  Encolar(struct Cola &q, int Valor)
Objetivo: Agregar un elemento en una cola
parametros cola q--> recibe una estructura de tipo cola 
		   int  Valor--> un valor a encolar
			Ejemplo: Encolar(q,valor) Recibe una cola y un dato a encolar 
*/
void Encolar (struct Cola &q, char valor[])
{
	struct nodo1 *aux = new(struct nodo1);
	strcpy (aux->cliente, valor);
	aux->Siguiente = NULL;
	if(q.Adelante == NULL)
		q.Adelante = aux;
	else 
		(q.Atras)->Siguiente = aux;
		q.Atras = aux;
}
//---------------------------------------------------------
/*Nombre del procedimiento   MuestraCola(struct Cola &q)
Objetivo: Muestra los elementos de una cola
parametros cola q--> recibe una estructura de tipo cola}r
			Ejemplo: MuestraCola(q) Recibe una cola y la funcion muestra en pantalla los valores qu estan almacenados en la cola
*/
void MuestraCola (struct Cola q )
{
	struct nodo1 *aux;
	aux = q.Adelante;
	int x=16;
	int y=5 ;
	while(aux !=NULL)
	{
		posicion(x,y);cout<<aux->cliente;
		aux = aux->Siguiente;
		y++;
	}
}
//---------------------------------------------------------
/*Nombre del procedimiento   MostrarClientes(Factura P)
Objetivo: Encola por medio de la repeticion de facturas los clientes mas activos
parametros Factura P--> recibe una estructura de tipo factura
			Ejemplo: MostrarClientes(P) Recibe una cola y los encola para determinar cual de los cliente hace mas usos del programa
*/
void MostrarClientes(Factura P)//se saca los clientes 
{
		struct Cola C;
		C.Adelante=NULL;
		C.Atras=NULL;
	while (P != NULL)
	{
		Encolar(C,P->vendididoA);
		P = P->SgtFact;
	}
	ventana(15,2,100,22);
	//lineaV(50,5,16);
	//pido los datos que iran en la factura
	posicion(37,3);cout<<"CLIENTE MAS ACTIVOS ";
	MuestraCola(C);
	
}

//-------------------------------------------------------
/*Nombre del procedimiento  nodo1
Objetivo: crear una estructura para guardar un elemto y un puntero
parametros: Al ser una funcion tipo estructura no tiene parametro.
			Ejemplo: nodo1 , al llamar esa funcion se aguarda se le puede asignar el elemento y el puntero 
*/
struct nodo{
	char cliente[50];
	struct nodo *sgte;
};
typedef nodo *ptrPila;
 //--------------------------------------------------------
/*Nombre del procedimiento  Apilar(ptrPila &P, int Valor)
Objetivo: Agregar un elemento en una cola
parametros nodo p--> recibe una estructura de tipo nodo 
		   int  Valor--> un valor a apilar
			Ejemplo: Apilar(P,valor) Recibe una pila y un dato a apilar 
*/
void Apilar(ptrPila &P, char  valor[])  // apilar elemento
{
	ptrPila aux;
	aux = new(struct nodo);   //apuntamos al nuevo nodocreado
	strcpy (aux->cliente, valor);
	aux->sgte= P;
	P=aux;
}
//------------------------------------------------------------------------------
/*Nombre del procedimiento   MuestraPila(ptrPila &P)
Objetivo: Muestra los elementos de una cola
parametros nodo p--> recibe una estructura de tipo nodo 
			Ejemplo: MuestraCola(p) Recibe una cola y la funcion muestra en pantalla los valores qu estan almacenados en la cola
*/
void MostrarPila(ptrPila P)
{
	ptrPila aux;
	aux=P;
	int x=16;
	int y=5 ;
	while(aux !=NULL)
	{
		posicion(x,y);cout<<aux->cliente;
		aux=aux->sgte;
		y++;
	}
}
/*Nombre del procedimiento   ClientesRecientes (Factura P)
Objetivo: apila por medio de la pocision de la lista , los clientes mas recientes
parametros Factura P--> recibe una estructura de tipo factura
			Ejemplo: ClientesRecientes(P) Recibe una pila y los apilas para determinar cual de los cliente mas reciente ha utilizado el programa
*/
void ClientesRecientes (Factura P)//se saca los clientes 
{
		ptrPila  N=NULL;
		
	
	while (P != NULL)
	{
		Apilar(N,P->vendididoA);
		P = P->SgtFact;
	}
	ventana(15,2,100,22);
	//lineaV(50,5,16);
	//pido los datos que iran en la factura
	posicion(37,3);cout<<"CLIENTE MAS RECIENTES ";
	MostrarPila(N);
	
}

//-----------------------------------------------
/*Nombre del procedimiento  menu()
Objetivo: Mostrar en pantalla los diferentes procedimiento que hace el programa
parametros al ser un programa que solo vizualiza las opciones no tiene parametro.
			Ejemplo: menu() al llamar la funcion se vizualiza en pantalla las diferentes implementaciones
*/
//////////////////////////////////////////////////////

Menu (){
	
	color(9);ventana(15,2,80,22);
	posicion(10,4);color(15);
	posicion(33,4);cout<<"FACTURA";
	color(9);lineaH(16,5,37);
	color(15);
	posicion(22,7);cout<<"1. AGREGAR NUEVA FACTURA";
	posicion(22,9);cout<<"2. MOSTRAR FACTURAS";
	posicion(22,11);cout<<"3.BUSCAR FACTURA ";
	posicion(22,13);cout<<"4. MODIFICAR FACTURA ";
	posicion(22,15);cout<<"5. MOSTRAR CLIENTES RECIENTE";
	posicion(22,17);cout<<"6. CLIENTE MAS ACTIVOS";
	posicion(22,19);cout<<"7. ELIMINAR FACTURA";
	posicion(22,21);cout<<"8. SALIDA";
	color(3);lineaV(54,3,18);
	color(15);posicion(60,4);cout<<"OPCION :";
	//lineaH(25,7,20);
	//lineaV(43,5,14.999);
	//posicion(15,10);cout<<"Ingrese el numero de la Nomina: ";
	
	
	posicion(1,40);
}
