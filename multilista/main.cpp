/*
 * main.cpp
 *
 *  Created on: 5/10/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 */

#include <cstdlib>
#include <iostream>
#include "Multilista.cpp"
using std::cin;
using std::cout;
using std::endl;

int x;
int y;
int z;
string nombre;
string actividad;
string carrera;
int edad;
Multilista<Estudiante> *multilista;
Estudiante *estudiante;

int escogerCarrera() {
	int carr;
	do {
		cout<<"             ______________________________________________________"<<endl;
		cout<<"             +                 MENU DE CARRERAS                   +"<<endl;
		cout<<"             +            1. Ingeniería Electrica                 +"<<endl;
		cout<<"             +            2. Ingeniería Industrial                +"<<endl;
		cout<<"             +            3. Ingeniería Catastral                 +"<<endl;
		cout<<"             +            4. Ingeniería de Sistemas               +"<<endl;
		cout<<"             ______________________________________________________"<<endl;
		cout << "Seleccione una carrera: ";
		cin >> carr;
		if(carr<1 && carr>4) {
			cout << "ingrese una opcion valida" << endl;
		}
		system("pause");
		system("cls");
	} while (carr<=0 && carr>4);
	return carr;
}

int escogerActividad() {
	int actv;
	do {
		cout<<"             ______________________________________________________"<<endl;
		cout<<"             +                 MENU DE ACTIVIDADES                +"<<endl;
		cout<<"             +            5. Danzas                               +"<<endl;
		cout<<"             +            6. Basquet                              +"<<endl;
		cout<<"             +            7. Natacion                             +"<<endl;
		cout<<"             +            8. Beisbol                              +"<<endl;
		cout<<"             ______________________________________________________"<<endl;
		cout << "Seleccione una actividad: ";
		cin >> actv;
		if (actv<=0 && actv>4) {
			cout << "ingrese una opcion valida" << endl;
		}
		system("pause");
		system("cls");

	} while(actv<5 && actv>8);
	return actv;
}

int main() {
	multilista = new Multilista<Estudiante>();
	do {
		cout<<"             ______________________________________________________"<<endl;
		cout<<"             +                 MENU DE MULTILISTA                 +"<<endl;
		cout<<"             +            1. Agregar estudiante                   +"<<endl;
		cout<<"             +            2. Mostrar por nombre                   +"<<endl;
		cout<<"             +            3. Mostrar por carrera                  +"<<endl;
		cout<<"             +            4. Mostrar por actividad                +"<<endl;
		cout<<"             +            5. Mostrar por edad                     +"<<endl;
		cout<<"             +            0.Salir                                 +"<<endl;
		cout<<"             ______________________________________________________"<<endl;
		cout<<"Digite la opcion que desea realizar:";
		cin >> z;
		system("pause");
		system("cls");

		switch (z) {
		case 1:  /* 1. Agregar estudiante  */
			cout << "Ingrese el nombre del estudiante: ";
			cin >> nombre;
			system("cls");
			x = escogerCarrera();
			carrera = ATRIBUTOS[x];
			y = escogerActividad();
			actividad = ATRIBUTOS[y];
			cout << "ingrese la edad del estudiante: ";
			cin >> edad;
			multilista->insertarEstudiante(nombre, carrera, actividad, edad);
			break;

		case 2:  /* 2. Mostrar por nombre   */
			estudiante = new Estudiante;
			estudiante = multilista->mostrar(ATRIBUTOS[0]);
			if (estudiante!=NULL) {
				while (estudiante->sigNombre!=NULL) {
					cout << estudiante->nombre << endl;
					estudiante = estudiante->sigNombre;
				}
				cout << estudiante->nombre << endl;
			} else {
				cout << "vacio" << endl;
			}
			break;

		case 3:  /* 3. Mostrar por carrera */
			x = escogerCarrera();
			estudiante = new Estudiante;
			estudiante = multilista->mostrar(ATRIBUTOS[x]);
			if(estudiante!=NULL) {
				while (estudiante->sigCarrera!=NULL) {
					cout << estudiante->nombre << endl;
					estudiante = estudiante->sigCarrera;
				}
				cout << estudiante->nombre << endl;
			} else {
				cout << "vacio" << endl;
			}
			break;

		case 4:  /* 4. Mostrar por actividad */
			y = escogerActividad();
			estudiante = new Estudiante;
			estudiante = multilista->mostrar(ATRIBUTOS[y]);
			if (estudiante!=NULL) {
				while (estudiante->sigActividad!=NULL) {
					cout << estudiante->nombre << endl;
					estudiante = estudiante->sigActividad;
				}
				cout << estudiante->nombre << endl;
			} else {
				cout << "vacio" << endl;
			}
			break;

		case 5:  /* 5. Mostrar por edad */
			estudiante = new Estudiante;
			estudiante = multilista->mostrar(ATRIBUTOS[9]);
			if(estudiante!=NULL) {
				while (estudiante->sigEdad!=NULL) {
					cout << estudiante->nombre << " tiene " << estudiante->edad << endl;
					estudiante = estudiante->sigEdad;
				}
				cout << estudiante->nombre << " tiene " << estudiante->edad << endl;
			} else {
				cout << "vacio" << endl;
			}
			break;

		case 0:  /* 0.Salir */
			break;

		default:
			cout << "ingrese una opcion valida" << endl;
			break;

		}
		system("pause");
		system("cls");

	}while (z!=0);
	system("pause");
	delete multilista;
	delete estudiante;
	return EXIT_SUCCESS;
}
