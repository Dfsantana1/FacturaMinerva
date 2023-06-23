/*Universidad te cnologica de pereira
Programa ISC
Materia : Estructura  de datos
Nombre del autor: Laura Quintero Montoya, Diego	Fernando Santana Fernandez.
Fecha de Actualizacion: 15 de Septiembre de 2022
Titulo del Trabajo: Proyecto Factura Minerva
Version:5.0
*/
#include <iostream>
using namespace std;

/*Nombre del procedimiento:   fecha 
Objetivo: Es una colección de variables simples  que pueden 
          contener tre variables de tipo entero (fecha, mes y año).
parametros:Al ser una definicion de una estructura no tiene .
Ejemplo: struct Fecha//Cuando se crea un struct, se pueden crear varias 
                    instancias de este «nuevo» tipo de variable que se ha 
					hecho y usarla en diferentes funciones que requiera de la 
					fecha y sus variable entero que es el dia,mes y año.
*/
struct Fecha
{
    int day;
    int month;
    int year;
};
/*Nombre del procedimiento:  ValidarFechaEstrutura de la fecha 
Objetivo: Es una colección de variables simples  que pueden 
          contener tre variables de tipo entero (fecha, mes y año).
parametros:Al ser una definicion de una estructura no tiene .
Ejemplo: struct Fecha//Cuando se crea un struct, se pueden crear varias 
                    instancias de este «nuevo» tipo de variable que se ha 
					hecho y usarla en diferentes funciones que requiera de la 
					fecha y sus variable entero que es el dia,mes y año.
*/
/*Nombre del procedimiento:  menu del programa ()
Objetivo: El usuario puede validar  digitada sea correcta o no, y tambien 
		  comprobar que el año sea bisiesto o no.
parametros:Fecha-->date recibe  datos tipo Fecha
Ejemplo: ValidarFecha (Fecha Mifecha)//ingresar al programa el dia, fecha y año, 
                                       validar si la fecha es corecta o no
									  
*/
bool ValidarFecha(Fecha date){
    int Novalido = 0;
    int day = date.day;
    int month = date.month;
    int year = date.year;
    if((year % 4) == 0 && year >= 0){
        switch (month){
            case 1:
                if(day <= 0 || day > 31){
                    Novalido++;
                }
                break;
            case 2:
                if(day <= 0 || day> 29){
                    Novalido++;
                }
                break;
            case 3:
                if(day <= 0 || day > 31){
                    Novalido++;
                }
                break;
            case 4:
                if(day <= 0 || day > 30){
                    Novalido++;
                }
                break;
            case 5:
                if(day <= 0 || day > 30){
                    Novalido++;
                }
                break;
            case 6:
                if(day <= 0 || day > 30){
                    Novalido++;
                }
                break;
            case 7:
                if(day <= 0 || day > 31){
                    Novalido++;
                }
                break;
            case 8:
                if(day <= 0 || day > 31){
                    Novalido++;
                }
                break;
            case 9:
                if(day <= 0 || day > 30){
                    Novalido++;
                }
                break;
            case 10:
                if(day <= 0 || day > 31){
                    Novalido++;
                }
                break;
            case 11:
                if(day <= 0 || day > 30){
                    Novalido++;
                }
                break;
            case 12:
                if(day <= 0 || day > 31){
                    Novalido++;
                }
                break;
            default: Novalido++;


        }}else if(year >= 0){
            switch (month){
            case 1:
                if(day <= 0 || day > 31){
                    Novalido++;
                }
                break;
            case 2:
                if(day <= 0 || day > 28){
                    Novalido++;
                }
                break;
            case 3:
                if(day <= 0 || day > 31){
                    Novalido++;
                }
                break;
            case 4:
                if(day <= 0 || day > 30){
                    Novalido++;
                }
                break;
            case 5:
                if(day <= 0 || day > 30){
                    Novalido++;
                }
                break;
            case 6:
                if(day <= 0 || day > 30){
                    Novalido++;
                }
                break;
            case 7:
                if(day <= 0 || day > 31){
                    Novalido++;
                }
                break;
            case 8:
                if(day <= 0 || day > 31){
                    Novalido++;
                }
                break;
            case 9:
                if(day <= 0 || day > 30){
                    Novalido++;
                }
                break;
            case 10:
                if(day <= 0 || day > 31){
                    Novalido++;
                }
                break;
            case 11:
                if(day <= 0 || day > 30){
                    Novalido++;
                }
                break;
            case 12:
                if(day <= 0 || day > 31){
                    Novalido++;
                }
                break;
            default: Novalido++;
        }
    } else{
        Novalido++;
    }
    if(Novalido == 0){
        return true;
    }else{
        return false;
    }
}

