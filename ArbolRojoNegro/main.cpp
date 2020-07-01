/*
 * main.cpp
 *
 *  Created on:
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */
#include <iostream>
#include <stdlib.h>
#include "RojoNegro.h"
using namespace std;

int main() {
	int datInser, datBuscar, datElim,z;
	NODO *r;
	ARBOL *a = new ARBOL();
	do {
		cout<<"             ******************************************************"<<endl;
		cout<<"             *                 MENU DE ARBOL ROJO - NEGRO         *"<<endl;
		cout<<"             ******************************************************"<<endl;
		cout<<"                          1. Insertar			                "<<endl;
		cout<<"                          2. Buscar				                "<<endl;
		cout<<"                          3. Eliminar				            "<<endl;
		cout<<"                          4. Mostrar Inorden	                    "<<endl;
		cout<<"                          5. Mostrar Preorden                    "<<endl;
		cout<<"                          6. Mostrar Postorden                   "<<endl;
		cout<<"                          0.Salir                                "<<endl;
		cout<<"             ******************************************************"<<endl;
		cout<<"Digite la opcion que desea realizar:";
		cin >> z;
		system("cls");

		switch (z) {

		case 1:  /* 2. Insertar   */
			cout << "Ingrese el dato a ingresar ";
			cin >> datInser;
			if (a->ins_arbol(datInser)==-1) {
				cout << "Ya existe" << endl;
			}
			break;

		case 2:  /* 3. Buscar */
			cout << "Ingrese el dato a buscar ";
			cin >> datBuscar;
			r = a->raiz_arbol();
			cout << "Nodo : " << (a->buscar(datBuscar, &r, NULL)==NULL ? "":"no ") << "encontrado" << endl;
			break;

		case 3:  /* 4. Eliminar */
			cout << "Ingrese el dato a eliminar ";
			cin >> datElim;
			if (a->retira_arbol(datElim)==-1) {
				cout << "No existe" << endl;
			} else {
				cout << "Nodo eliminado" << endl;
			}
			system("cls");
			break;

		case 4:  /* 4. mostrar Inorden */
			a->inorden(a->raiz_arbol());
			cout << endl;
			system("pause");
			break;

		case 5:  /* 5. Imprimir Preorden*/
			a->preorden(a->raiz_arbol());
			cout << endl;
			system("pause");
			break;

		case 6:  /* 6. Imprimir posorden */
			a->posorden(a->raiz_arbol());
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
