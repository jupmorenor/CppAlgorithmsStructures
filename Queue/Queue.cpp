/*
 * Queue.cpp
 *
 *  Created on: 29/09/2014
 *      Author: Juan Pablo Moreno Rico - 20111020059
 */

#include <stddef.h>
#include "Queue.h"

template <typename T> Queue<T>::Queue() {
	cabeza = NULL;
	tam = 0;
}

template <typename T> Queue<T>::~Queue() {
	Nodo<T> *Aux;
	if (!esta_vacia()) {
		for(Aux=cabeza->siguiente; Aux->siguiente!=Aux; Aux=Aux->siguiente) {
			Aux->anterior = cabeza->anterior;
			(Aux->anterior)->siguiente = Aux;
			delete cabeza;
			cabeza = Aux;
			tam--;
		}
		delete Aux;
		delete cabeza;
	}
}

template <typename T> bool Queue<T>::insertar_inicio(T elm) {
	if (esta_vacia()) {
		cabeza = crear_nodo(elm);
		cabeza->siguiente = cabeza;
		cabeza->anterior = cabeza;
	} else {
		Nodo<T> *Aux = cabeza;
		cabeza = crear_nodo(elm);
		cabeza->siguiente = Aux;
		cabeza->anterior = Aux->anterior;
		Aux->anterior = cabeza;
		(cabeza->anterior)->siguiente = cabeza;
	}
	tam++;
	return true;
}

template <typename T> bool Queue<T>::insertar_final(T elm) {
	if(esta_vacia()) {
		cabeza = crear_nodo(elm);
		cabeza->siguiente = cabeza;
		cabeza->anterior = cabeza;
	} else {
		Nodo<T> *Aux = crear_nodo(elm);
		Aux->siguiente = cabeza;
		Aux->anterior = cabeza->anterior;
		cabeza->anterior = Aux;
		(Aux->anterior)->siguiente = Aux;
	}
	tam++;
	return true;
}

template <typename T> bool Queue<T>::eliminar_inicio() {
	Nodo<T> *Aux = cabeza;
	if (esta_vacia()) {
		return false;
	} else if (tam == 1) {
		delete cabeza;
	} else {
		(Aux->siguiente)->anterior = Aux->anterior;
		(Aux->anterior)->siguiente = Aux->siguiente;
		cabeza = Aux->siguiente;
		delete Aux;
	}
	tam--;
	return true;
}

template <typename T> bool Queue<T>::eliminar_final() {
	Nodo<T> *Aux = cabeza->anterior;
	if (esta_vacia()) {
		return false;
	} else if (tam == 1) {
		delete cabeza;
	} else {
		(Aux->siguiente)->anterior = Aux->anterior;
		(Aux->anterior)->siguiente = Aux->siguiente;
		delete Aux;
	}
	tam--;
	return true;
}

template <typename T> T Queue<T>::buscar(int pos) {
	Nodo<T> *Aux = cabeza;
	while (pos > tam) {
		pos-=tam;
	}
	if (!esta_vacia()) {
		if (pos == 0) {
			return primero();
		}else if (pos == tam-1) {
			return ultimo();
		} else {
			for(int i=0; i<pos; i++) {
				Aux = Aux->siguiente;
			}
			return Aux->dato;
		}
	}
}

template <typename T> T Queue<T>::primero() {
	return cabeza->dato;
}

template <typename T> T Queue<T>::ultimo() {
	return (cabeza->anterior)->dato;
}

template <typename T> int Queue<T>::long_lista() {
	return tam;
}

template <typename T> bool Queue<T>::esta_vacia() {
	return (tam == 0);
}
