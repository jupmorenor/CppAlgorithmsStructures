/*
 * main.cpp
 *
 *  Created on: 29/09/2014
 *      Author: Juan Pablo Moreno Rico - 20111020059
                 Diana Crithina Pérez Pérez - 20111020069
 */

#include <cstdlib>
#include <iostream>
#include "Queue.cpp"
using namespace std;

template <class T> void imprimir(Queue<T> &list) {
	for (int i=0; i<list.long_lista(); i++) {
		cout << list.buscar(i) << " ";
	}
	cout << endl;
}

template <class T> void imprimirInv(Queue<T> &list) {
	for (int i=list.long_lista()-1; i>= 0; i--) {
		cout << list.buscar(i) << " ";
	}
	cout << endl;
}

struct Prueba {
	int valor;
	char letra;
};

Queue<int> *queueInt;
Queue<float> *queueFloat;
Queue<char> *queueChar;
Queue<Prueba> *queueStruct;

int z, op;
char letra;
float tr;
Prueba *prueba;

int main(int argc, char *argv[]) 
{
	queueInt = new Queue<int>();
	queueFloat = new Queue<float>();
	queueChar = new Queue<char>();
	queueStruct = new Queue<Prueba>();

	do {
		cout<<"             ______________________________________________________"<<endl;
		cout<<"             +                 MENU DE QUEUE                      +"<<endl;
		cout<<"             +            1. Agregar al inicio                    +"<<endl;
		cout<<"             +            2. Agregar al final                     +"<<endl;
		cout<<"             +            3. Eliminar al inicio                   +"<<endl;
		cout<<"             +            4. Eliminar al final                    +"<<endl;
		cout<<"             +            5. Tamaño del queue                     +"<<endl;
		cout<<"             +            6. Buscar un elemento                   +"<<endl;
		cout<<"             +            7. Esta vacia?                          +"<<endl;
		cout<<"             +            8. Primer elemento                      +"<<endl;
		cout<<"             +            9. Ultimo elemento                      +"<<endl;
		cout<<"             +            10. Mostrar todo                        +"<<endl;
		cout<<"             +            11. Mostrar invertido                   +"<<endl;
		cout<<"             +            0.Salir                                 +"<<endl;
		cout<<"             ______________________________________________________"<<endl;
		cout<<"Digite la opcion que desea realizar:";
		cin>>z;
		 
		system("cls");
		switch(z) {
		case 1:	/*  1. Agregar al inicio  */
			cout<<"entero a ingresar: "<<endl;
			cin>>op;
			queueInt->insertar_inicio(op);

			cout<<"caracter a ingresar: "<<endl;
			cin>>letra;
			queueChar->insertar_inicio(letra);

			cout<<"float a ingresar: "<<endl;
			cin>>tr;
			queueFloat->insertar_inicio(tr);

			prueba = new Prueba();
			cout << "La estructura se compondra del entero y caracter ya dados" << endl;
			prueba->letra = letra;
			prueba->valor = op;
			queueStruct->insertar_inicio(*prueba);
			break;

		case 2: /*  2. Agregar al final  */
			cout<<"entero a ingresar: "<<endl;
			cin>>op;
			queueInt->insertar_final(op);

			cout<<"caracter a ingresar: "<<endl;
			cin>>letra;
			queueChar->insertar_final(letra);

			cout<<"float a ingresar: "<<endl;
			cin>>tr;
			queueFloat->insertar_final(tr);

			prueba = new Prueba();
			cout << "La estructura se compondra del entero y caracter ya dados" << endl;
			prueba->letra = letra;
			prueba->valor = op;
			queueStruct->insertar_final(*prueba);
			break;

		case 3:  /*  3. Eliminar al inicio  */
			queueInt->eliminar_inicio();
			queueFloat->eliminar_inicio();
			queueChar->eliminar_inicio();
			queueStruct->eliminar_inicio();
			break;

		case 4:  /*  4. Eliminar al final  */
			queueInt->eliminar_final();
			queueFloat->eliminar_final();
			queueChar->eliminar_final();
			queueStruct->eliminar_final();
			break;

		case 5:  /*  5. Tamaño del queue  */
			cout << "El queue de enteros tiene " << queueInt->long_lista() << " elementos" << endl;
			cout << "El queue de floatntes tiene " << queueFloat->long_lista() << " elementos" << endl;
			cout << "El queue de caracteres tiene " << queueChar->long_lista() << " elementos" << endl;
			cout << "El queue de estructuras tiene " << queueStruct->long_lista() << " elementos" << endl;
			break;

		case 6:  /*  6. Buscar un elemento  */
			int pos;
			cout << "Indique la posicion del elemento a consultar: ";
			cin >> pos;
			cout << "Posicion " << pos << " en el queue de enteros: " << queueInt->buscar(pos) << endl;
			cout << "Posicion " << pos << " en el queue de flotantes: " << queueFloat->buscar(pos) << endl;
			cout << "Posicion " << pos << " en el queue de caracteres: " << queueChar->buscar(pos) << endl;
			cout << "Posicion " << pos << " en el queue de estructuras: " << (queueStruct->buscar(pos)).letra << (queueStruct->buscar(pos)).valor << endl;
			break;

		case 7:  /* 7. Esta vacia?  */
			cout << "El queue de enteros " << (queueInt->esta_vacia()?"":"no") << " esta vacio" << endl;
			cout << "El queue de flotantes " << (queueFloat->esta_vacia()?"":"no") << " esta vacio" << endl;
			cout << "El queue de caracteres " << (queueChar->esta_vacia()?"":"no") << " esta vacio" << endl;
			cout << "El queue de estructuras " << (queueStruct->esta_vacia()?"":"no") << " esta vacio" << endl;
			break;

		case 8: /*  8. Primer elemento  */
			cout << "El primer elemento del queue de enteros es: " << queueInt->primero() << endl;
			cout << "El primer elemento del queue de flotantes es: " << queueFloat->primero() << endl;
			cout << "El primer elemento del queue de caracteres es: " << queueChar->primero() << endl;
			cout << "El primer elemento del queue de estructuras es: " << (queueStruct->primero()).letra << (queueStruct->primero()).valor << endl;
			break;

		case 9:  /*  9. Ultimo elemento  */
			cout << "El ultimo elemento del queue de enteros es: " << queueInt->ultimo() << endl;
			cout << "El ultimo elemento del queue de flotantes es: " << queueFloat->ultimo() << endl;
			cout << "El ultimo elemento del queue de caracteres es: " << queueChar->ultimo() << endl;
			cout << "El ultimo elemento del queue de estructuras es: " << (queueStruct->ultimo()).letra << (queueStruct->ultimo()).valor << endl;
			break;

		case 10:  /*  10. Mostrar queue  */
			cout << "queue de enteros: ";
			imprimir(*queueInt);
			cout << "queue de flotantes: ";
			imprimir(*queueFloat);
			cout << "queue de caracteres: ";
			imprimir(*queueChar);
			cout << "queue de estructuras ";
			for(int i=0; i<queueStruct->long_lista(); i++) {
				cout << queueStruct->buscar(i).letra << queueStruct->buscar(i).valor << " ";
			}
			cout << endl;
			break;

		case 11:  /*  11. Mostrar invertido    */
			cout << "queue de enteros: ";
			imprimirInv(*queueInt);
			cout << "queue de flotantes: ";
			imprimirInv(*queueFloat);
			cout << "queue de caracteres: ";
			imprimirInv(*queueChar);
			cout << "queue de estructuras ";
			for(int i=queueStruct->long_lista()-1; i>=0; i--) {
				cout << queueStruct->buscar(i).letra << queueStruct->buscar(i).valor << " ";
			}
			cout << endl;
			break;

		case 0:  /* 0. Salir  */
			break;

		default:
			cout << "ingrese una opcion valida" << endl;
			break;
		}
		system("pause");
		system("cls");
                                
	}while(z!=0);
      
      system("PAUSE");
      return 0;
} 


