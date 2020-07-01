/*
 * main.cpp
 *
 *  Created on: 23/10/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */
#include <iostream>
#include <stdlib.h>
#include "Monticulo.h"
using namespace std;

int main() {
	int tamano, z, ins;
	cout << "Ingrese el número de datos del arbol: ";
	cin >> tamano;
	system("cls");
	Monticulo *monticulo = new Monticulo(tamano+1);
	do {
		cout<<"             ******************************************************"<<endl;
		cout<<"             *        MENU DE COLA DE PRIORIDAD COMO ARREGLO      *"<<endl;
		cout<<"             ******************************************************"<<endl;
		cout<<"                          1. Insertar			                "<<endl;
		cout<<"                          2. Atender                                "<<endl;
		cout<<"                          3. Imprimir                            "<<endl;
		cout<<"                          0. Salir                                "<<endl;
		cout<<"             ******************************************************"<<endl;
		cout<<"Digite la opcion que desea realizar:";
		cin >> z;
		system("pause");
		system("cls");

		switch (z) {
		case 1:  /*  1. insertar  */
			cout << "Digite la prioridad a ingresar ";
			cin >> ins;
			cout << (monticulo->insertar(ins) ? "ha ingresado" : "no hay cupo") << endl;
			break;

		case 2:  /* Atender  */
			cout << monticulo->atender() << endl;
			break;

		case 3:  /*  Imprimir  */
			monticulo->imprimir();
			break;

		case 0:  /*  0.Salir   */
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
