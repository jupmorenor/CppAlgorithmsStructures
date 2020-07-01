#include <iostream>
#include <stdlib.h>
#include <iostream>
#include "ArbolArreglo.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int tamano, datInser, datBuscar, datElim,z;
	cout << "Ingrese el número de datos del arbol: ";
	cin >> tamano;
	system("cls");
	ArbolArreglo *a = new ArbolArreglo(tamano+1);
	do {
		cout<<"             ******************************************************"<<endl;
		cout<<"             *                 MENU DE ARBOL COMO ARREGLO         *"<<endl;
		cout<<"             ******************************************************"<<endl;
		cout<<"                          1. Insertar			                "<<endl;
		cout<<"                          2. Buscar				                "<<endl;
		cout<<"                          3. Eliminar				            "<<endl;
		cout<<"                          4. Imprimir                            "<<endl;
		cout<<"                          5. Mostrar Inorden	                    "<<endl;
		cout<<"                          6. Mostrar Preorden                    "<<endl;
		cout<<"                          7. Mostrar Postorden                   "<<endl;
		cout<<"                          0.Salir                                "<<endl;
		cout<<"             ******************************************************"<<endl;
		cout<<"Digite la opcion que desea realizar:";
		cin >> z;
		system("pause");
		system("cls");

		switch (z) {

		case 1:  /* 2. Insertar   */
			cout << "Ingrese el dato a ingresar ";
			cin >> datInser;
			system("cls");
			a->insertar(datInser);
			break;

		case 2:  /* 3. Buscar */
			cout << "Ingrese el dato a buscar ";
			cin >> datBuscar;
			cout << "posicion " << a->buscar(datBuscar) << endl;
			system("cls");
			break;

		case 3:  /* 4. Eliminar */
			cout << "Ingrese el dato a eliminar ";
			cin >> datElim;
			a->eliminar(datElim);
			system("cls");
			break;

		case 4:  /* 5. Imprimir */
			a->imprimirArreglo();
			system("pause");
			break;

		case 5:  /* 5. mostrar Inorden */
			a->inorden();
			system("pause");
			break;
			
		case 6:  /* 5. Imprimir Preorden*/
			a->preorden();
			system("pause");
			break;
		
		case 7:  /* 5. Imprimir posorden */
			a->postorden();
			system("pause");
			break;
		
		case 0:  /* 0.Salir */
			break;

		default:
			cout << "ingrese una opcion valida" << endl;
			break;

		}
		system("cls");

	}while (z!=0);
	system ("PAUSE");
	return EXIT_SUCCESS;
}
