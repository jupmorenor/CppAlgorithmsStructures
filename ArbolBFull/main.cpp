/*
 * main.cpp
 *
 *  Created on: 20/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#include <iostream>
#include <stdlib.h>
#include "ArbolBFull.h"
using namespace std;

int orden, datInser, datBuscar, datElim, z;
nodo *r;
arbolB *a;

int main() {
	do {
		cout << "Ingrese el orden del arbol b+: ";
		cin >> orden;
		if (orden < 2) {
			cout << "el valor ingresado no es un orden valido para un arbol B+ de acuerdo a Cormen"<< endl;
		}
	} while(orden < 2);
	a = new arbolB(orden);
	do {
		cout<<"             ******************************************************"<<endl;
		cout<<"             *                 MENU DE ARBOL B+                   *"<<endl;
		cout<<"             ******************************************************"<<endl;
		cout<<"                          1. Insertar			                "<<endl;
		cout<<"                          2. Eliminar				            "<<endl;
		cout<<"                          3. Mostrar     	                    "<<endl;
		cout<<"                          0.Salir                                "<<endl;
		cout<<"             ******************************************************"<<endl;
		cout<<"Digite la opcion que desea realizar:";
		cin >> z;
		system("cls");

		switch (z) {

		case 1:  /* 1. Insertar   */
			cout << "Ingrese el dato a ingresar ";
			cin >> datInser;
			a->insertar(datInser);
			break;

		case 2:  /* 2. Eliminar */
			cout << "Ingrese el dato a eliminar ";
			cin >> datElim;
			/*if (a->borrar(datElim)==-1) {
				cout << "No existe" << endl;
			} else {
				cout << "Nodo eliminado" << endl;
			}*/
			cout << "No implementado" << endl;
			system("cls");
			break;

		case 3:  /* 3. mostrar  */
			a->imprimirArbol(a->dar_raiz());
			cout << endl;
			system("pause");
			break;

		case 0:  /* 0.Salir */
			break;

		default:
			cout << "ingrese una opcion valida" << endl;
			break;

		}
		system ("PAUSE");
		system("cls");

	}while (z!=0);
	system ("PAUSE");
	return EXIT_SUCCESS;
}



