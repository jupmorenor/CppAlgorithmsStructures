/*
 * main.cpp
 *
 *  Created on: 25/09/2014
 *      Author: Juan Pablo Moreno Rico - 20111020059
 */

#include <iostream>
#include <cstdlib>
//#include "ListaStruct.h"
#include "ListaStruct.cpp"
using namespace std;

struct Prueba {
	int valor;
	char letra;
};

ListaS<int> *listaInt;
ListaS<float> *listaFloat;
ListaS<char> *listaChar;
ListaS<Prueba> *listaStruct;
Prueba *prueba1, *prueba2, *prueba3, *prueba4, *prueba5;


template <class T> void imprimir(ListaS<T> &list) {
	for (int i=0; i<list.long_lista(); i++) {
		cout << list.buscar(i) << " ";
	}
	cout << endl;
}

int main() {

	/* Prueba con enteros */
	cout << "/* Prueba con enteros */" << endl;
	listaInt = new ListaS<int>();
	listaInt->insertar_inicio(5);
	listaInt->insertar_inicio(10);
	listaInt->insertar_inicio(15);
	listaInt->insertar_final(20);
	listaInt->insertar_final(25);
	imprimir(*listaInt);
	cout << "Primero de la lista: " << listaInt->primero() << endl;
	cout << "Ultimo de la lista: " << listaInt->ultimo() << endl;
	cout << "Posicion 3 de la lista: " << listaInt->buscar(3) << endl;
	listaInt->suprimir(3);
	listaInt->insertar_pos(50, 3);
	cout << "Eliminada la posicion 3 e insertado 50 en la posicion 3" << endl;
	imprimir(*listaInt);
	cout << endl;

	/* Prueba con flotantes */
	cout << "/* Prueba con flotantes */" << endl;
	listaFloat = new ListaS<float>();
	listaFloat->insertar_inicio(5.5);
	listaFloat->insertar_inicio(10.2);
	listaFloat->insertar_inicio(15.3);
	listaFloat->insertar_final(20.1);
	listaFloat->insertar_final(25.8);
	imprimir(*listaFloat);
	cout << "Primero de la lista: " << listaFloat->primero() << endl;
	cout << "Ultimo de la lista: " << listaFloat->ultimo() << endl;
	cout << "Posicion 3 de la lista: " << listaFloat->buscar(3) << endl;
	listaFloat->suprimir(0);
	listaFloat->insertar_pos(50.9, 0);
	cout << "Eliminada la posicion cero e insertado 50.9 en la posicion cero" << endl;
	imprimir(*listaFloat);
	cout << endl;

	/* Prueba con caracteres */
	cout << "/* Prueba con caracteres */" << endl;
	listaChar = new ListaS<char>();
	listaChar->insertar_inicio('a');
	listaChar->insertar_inicio('b');
	listaChar->insertar_inicio('c');
	listaChar->insertar_final('d');
	listaChar->insertar_final('e');
	imprimir(*listaChar);
	cout << "Primero de la lista: " << listaChar->primero() << endl;
	cout << "Ultimo de la lista: " << listaChar->ultimo() << endl;
	cout << "Posicion 3 de la lista: " << listaChar->buscar(3) << endl;
	listaChar->suprimir(4);
	listaChar->insertar_pos('f', 5);
	cout << "Eliminada la posicion 4 e insertado 'f' en la posicion 5 que viene siendo la ultima" << endl;
	imprimir(*listaChar);
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
	listaStruct = new ListaS<Prueba>();
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
	cout << endl;


	return EXIT_SUCCESS;
}





