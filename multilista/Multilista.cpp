/*
 * Multilista.cpp
 *
 *  Created on: 5/10/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 */
#include "Multilista.h"

const int DATOS = 10;
const string ATRIBUTOS[] = {"NOMBRE", "IE", "II", "IC", "IS", "danza", "basquet", "natacion", "baseball", "edad"};

template <class T> Multilista<T>::Multilista() {
	cabeza = crear_nodo(ATRIBUTOS[0]);
	tam = 0;
	Nodo<T> *Aux = cabeza;
	for(int i=1; i<DATOS; i++) {
		Aux->siguiente = crear_nodo(ATRIBUTOS[i]);
		Aux = Aux->siguiente;
	}
}

template <class T> Multilista<T>::~Multilista() {
	//TODO
}

template <class T> void Multilista<T>::insertarNombre(T *est) {
	Nodo<T> *Aux = cabeza;
	T *lista;
	int pos = 0;
	while ((Aux->ID)!=ATRIBUTOS[0]) {
		Aux = Aux->siguiente;//ubica el nodo con la cabeza que apunta a nombres
	}
	if (Aux->registro==NULL) {
		Aux->registro = est;//si esta vacio lo guarda ahi
	} else {
		lista = Aux->registro;
		if (est->nombre[pos] < lista->nombre[pos]) {//si la letra es menor lo deja de primero
			est->sigNombre = lista;
			Aux->registro = est;
		} else {
			while((est->nombre[pos] > lista->nombre[pos]) && (lista->sigNombre!=NULL)) {
				if (est->nombre[pos] < lista->sigNombre->nombre[pos] ) {
					break;//si es mayor al siguiente y no es nulo, se mueve al siguiente de lo contrario se queda ahi
				}
				lista = lista->sigNombre;
			}
			if (lista->sigNombre!=NULL) {//si el siguiente no es nulo, lo inserta en medio
				est->sigNombre = lista->sigNombre;
				lista->sigNombre = est;
			} else {
				lista->sigNombre = est;//de lo contrario queda de ultimo
			}
		}
	}
}

/* OK */
template <class T> void Multilista<T>::insertarCarrera(T *est) {
	Nodo<T> *Aux = cabeza;
	T *lista;
	while ((Aux->ID)!=(est->carrera)) {
		Aux = Aux->siguiente;//ubicar el nodo con la lista de quienes estudian la misma carrera
	}
	if (Aux->registro==NULL) {
		Aux->registro = est;//si esta vacio lo guarda ahi
	} else {
		lista = Aux->registro;
		while (lista->sigCarrera!=NULL) {//si no, se mueve hasta el final y lo deja de ultimo
			lista = lista->sigCarrera;
		}
		lista->sigCarrera = est;
	}
}

/* OK */
template <class T> void Multilista<T>::insertarActividad(T *est) {
	Nodo<T> *Aux = cabeza;

	while ((Aux->ID)!=(est->actividad)) {
		Aux = Aux->siguiente;//ubicar el nodo con la lista de quienes hacen la misma actividad
	}
	if (Aux->registro==NULL) {
		Aux->registro = est;//si esta vacio lo guarda ahi
	} else {
		est->sigActividad = Aux->registro;//si no, lo deja de primero
		Aux->registro = est;
	}
}

/* OK */
template <class T> void Multilista<T>::insertarEdad(T *est) {
	Nodo<T> *Aux = cabeza;
	T *lista;

	while ((Aux->ID)!=ATRIBUTOS[9]) {
		Aux = Aux->siguiente; //ubicar el nodo con la cabeza que apunta a edades
	}
	if (Aux->registro==NULL) {
		Aux->registro = est; //si esta vacio lo guarda ahi
	} else {
		lista = Aux->registro;
		if (est->edad > lista->edad) {//si es el mayor lo pone de primero
			est->sigEdad = lista;
			Aux->registro = est;
		} else {
			while((est->edad < lista->edad) && (lista->sigEdad!=NULL)) {
				if (est->edad > lista->sigEdad->edad) {
					break;
				}
				lista = lista->sigEdad;//se mueve hasta la posicion q le corresponde
			}
			if (lista->sigEdad!=NULL) {//se inserta entre dos registros existentes
				est->sigEdad = lista->sigEdad;
				lista->sigEdad = est;
			} else {
				lista->sigEdad = est;//queda de ultimo
			}
		}
	}
}

template <class T> void Multilista<T>::insertarEstudiante(string nom, string carr, string actv, int ed) {
	Estudiante *estudiante = new Estudiante();
	estudiante->nombre = nom;
	estudiante->carrera = carr;
	estudiante->actividad = actv;
	estudiante->edad = ed;
	estudiante->sigNombre = NULL;
	estudiante->sigCarrera = NULL;
	estudiante->sigActividad = NULL;
	estudiante->sigEdad = NULL;
	insertarNombre(estudiante);
	insertarCarrera(estudiante);
	insertarActividad(estudiante);
	insertarEdad(estudiante);
	tam++;
}

template <class T> T* Multilista<T>::mostrar(string id) {
	Nodo<T> *Aux = cabeza;
	while (Aux->ID!=id) {
		Aux = Aux->siguiente;
	}
	return (Aux->registro);
}

template <class T> int Multilista<T>::long_lista() {
	return tam;
}

template <class T> bool Multilista<T>::esta_vacia() {
	return (tam == 0);
}
