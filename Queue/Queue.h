/*
 * Queue.h
 *
 *  Created on: 28/09/2014
 *      Author: Juan Pablo Moreno Rico - 20111020059
                Diana Crithina Pérez Pérez - 20111020069
 */

#ifndef QUEUE_H_
#define QUEUE_H_

template <typename S> struct Nodo {
	S dato;
	Nodo<S> *siguiente;
	Nodo<S> *anterior;
};

template <class T> class Queue {
private:
	Nodo<T> *cabeza;
	int tam;
	Nodo<T> *crear_nodo(T val) {
		Nodo<T> *nodo = new Nodo<T>;
		nodo->dato = val;
		return nodo;
	}
public:
	Queue();
	~Queue();
	bool insertar_inicio(T elm);
	bool insertar_final(T elm);
	bool eliminar_inicio();
	bool eliminar_final();
	T buscar(int pos);
	T primero();
	T ultimo();
	int long_lista();
	bool esta_vacia();
	};



#endif /* QUEUE_H_ */
