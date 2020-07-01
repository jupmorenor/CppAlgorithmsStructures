/*
 * main.cpp
 *
 *  Created on: 28/09/2014
 *      Author: Juan Pablo Moreno Rico - 20111020059
                 Diana Crithina Pérez Pérez - 20111020069
 */

#include <iostream>
#include <cstdlib>
#include "ListaCircular.cpp"
using namespace std;

template <class T> void imprimir(ListaCircular<T> &list) {
	for (int i=0; i<list.long_lista(); i++) {
		cout << list.buscar(i) << " ";
	}
	cout << endl;
}

template <class T> void imprimirInv(ListaCircular<T> &list) {
	for (int i=list.long_lista()-1; i>= 0; i--) {
		cout << list.buscar(i) << " ";
	}
	cout << endl;
}

struct Prueba {
	int valor;
	char letra;
};

ListaCircular<int> *listaInt;
ListaCircular<float> *listaFloat;
ListaCircular<char> *listaChar;
ListaCircular<Prueba> *listaStruct;
Prueba *prueba1, *prueba2, *prueba3, *prueba4, *prueba5;


int main() {
	/* Prueba con enteros */
	cout << "/* Prueba con enteros */" << endl;
	listaInt = new ListaCircular<int>();
	listaInt->insertar_inicio(5);
	listaInt->insertar_inicio(10);
	listaInt->insertar_inicio(15);
	listaInt->insertar_final(20);
	listaInt->insertar_final(25);
	imprimir(*listaInt);
	cout << "tam: " << listaInt->long_lista() << endl;
	cout << "Primero de la lista: " << listaInt->primero() << endl;
	cout << "Ultimo de la lista: " << listaInt->ultimo() << endl;
	cout << "Posicion 3 de la lista: " << listaInt->buscar(3) << endl;
	listaInt->suprimir(3);
	cout << "tam: " << listaInt->long_lista() << endl;
	listaInt->insertar_pos(50, 3);
	cout << "Eliminada la posicion 3 e insertado 50 en la posicion 3" << endl;
	imprimir(*listaInt);
	imprimirInv(*listaInt);
	cout << endl;
	
	
	
	/* Prueba con flotantes */
	cout << "/* Prueba con flotantes */" << endl;
	listaFloat = new ListaCircular<float>();
	listaFloat->insertar_inicio(5.1);
	listaFloat->insertar_inicio(10.3);
	listaFloat->insertar_inicio(15.2);
	listaFloat->insertar_final(20.5);
	listaFloat->insertar_final(25.4);
	imprimir(*listaFloat);
	cout << "tam: " << listaFloat->long_lista() << endl;
	cout << "Primero de la lista: " << listaFloat->primero() << endl;
	cout << "Ultimo de la lista: " << listaFloat->ultimo() << endl;
	cout << "Posicion 3 de la lista: " << listaFloat->buscar(3) << endl;
	listaFloat->suprimir(3);
	cout << "tam: " << listaFloat->long_lista() << endl;
	listaFloat->insertar_pos(50.9, 3);
	cout << "Eliminada la posicion 3 e insertado 50.9 en la posicion 3" << endl;
	imprimir(*listaFloat);
	imprimirInv(*listaFloat);
	cout << endl;	
	
	/* Prueba con char */
	cout << "/* Prueba con char */" << endl;
	listaChar = new ListaCircular<char>();
	listaChar->insertar_inicio('@');
	listaChar->insertar_inicio('t');
	listaChar->insertar_inicio('w');
	listaChar->insertar_final('*');
	listaChar->insertar_final('|');
	imprimir(*listaChar);
	cout << "tam: " << listaChar->long_lista() << endl;
	cout << "Primero de la lista: " << listaChar->primero() << endl;
	cout << "Ultimo de la lista: " << listaChar->ultimo() << endl;
	cout << "Posicion 3 de la lista: " << listaChar->buscar(3) << endl;
	listaChar->suprimir(3);
	cout << "tam: " << listaChar->long_lista() << endl;
	listaChar->insertar_pos('?', 3);
	cout << "Eliminada la posicion 3 e insertado ? en la posicion 3" << endl;
	imprimir(*listaChar);
	imprimirInv(*listaChar);
	cout << endl;
   
	/* Prueba con estructuras */
	prueba1 = new Prueba();
	prueba1->letra = 'm';
	prueba1->valor = 13;
	prueba2 = new Prueba();
	prueba2->letra = 'n';
	prueba2->valor = 14;
	prueba3 = new Prueba();
	prueba3->letra = 'o';
	prueba3->valor = 15;
	prueba4 = new Prueba();
	prueba4->letra = 'p';
	prueba4->valor = 16;
	prueba5 = new Prueba();
	prueba5->letra = 'q';
	prueba5->valor = 17;
	cout << "/* Prueba con estructuras */" << endl;
	listaStruct = new ListaCircular<Prueba>();
	listaStruct->insertar_inicio(*prueba1);
	listaStruct->insertar_inicio(*prueba2);
	listaStruct->insertar_final(*prueba3);
	listaStruct->insertar_final(*prueba4);
	for (int i=0; i<listaStruct->long_lista(); i++) {
		cout << listaStruct->buscar(i).letra << listaStruct->buscar(i).valor << " ";
	}
	cout << endl;
	cout << "Primero de la lista: " << listaStruct->primero().letra << listaStruct->primero().valor << endl;
	cout << "Ultimo de la lista: " << listaStruct->ultimo().letra << listaStruct->ultimo().valor << endl;
	cout << "Posicion 2 de la lista: " << listaStruct->buscar(2).letra << listaStruct->buscar(3).valor << endl;
	listaStruct->suprimir(1);
	listaStruct->insertar_pos(*prueba5, 2);
	cout << "Eliminada la posicion 1 e insertado q17 en la posicion 2" << endl;
	for (int i=0; i<listaStruct->long_lista(); i++) {
		cout << listaStruct->buscar(i).letra << listaStruct->buscar(i).valor << " ";
	}
	cout << endl;
	for (int i=listaStruct->long_lista()-1; i>=0; i--) {
		cout << listaStruct->buscar(i).letra << listaStruct->buscar(i).valor << " ";
	}	
	cout << endl;
	cout << endl;	
	
	system("PAUSE");
	return EXIT_SUCCESS;
}


