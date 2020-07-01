/*
 * Multilista.h
 *
 *  Created on: 5/10/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 */

#include <string>
using std::string;


#ifndef MULTILISTA_H_
#define MULTILISTA_H_


struct Estudiante {
	string nombre;
	string carrera;
	string actividad;
	int edad;
	Estudiante *sigNombre, *sigCarrera, *sigActividad, *sigEdad;
};

template <typename S> struct Nodo {
	string ID;
	S *registro;
	Nodo<S> *siguiente;
};

template <class S> class Multilista {
	Nodo<S> *cabeza;
	int tam;
	Nodo<S> *crear_nodo(string id) {
		Nodo<S> *nodo = new Nodo<S>();
		nodo->ID = id;
		nodo->registro = NULL;
		nodo->siguiente = NULL;
		return nodo;
	}
public:
	Multilista();
	~Multilista();
	void insertarNombre(S *est);
	void insertarActividad(S *est);
	void insertarCarrera(S *est);
	void insertarEdad(S *est);
	void insertarEstudiante(string nom, string carr, string actv, int ed);
	S* mostrar(string id);
	int long_lista();
	bool esta_vacia();
};

#endif /* MULTILISTA_H_ */
