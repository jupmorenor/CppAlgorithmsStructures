/*
 * ListaCircular.h
 *
 *  Created on: 28/09/2014
 *      Author: Juanpa y Yami
 */

#ifndef LISTACIRCULAR_H_
#define LISTACIRCULAR_H_

template <typename S> struct Nodo {
	S dato;
	Nodo<S> *siguiente;
	Nodo<S> *anterior;
};

template <class T> class ListaCircular {
private:
	Nodo<T> *cabeza;
	int tam;
	Nodo<T> *crear_nodo(T val) {
		Nodo<T> *nodo = new Nodo<T>;
		nodo->dato = val;
		return nodo;
	}
public:
	ListaCircular();
	~ListaCircular();
	bool insertar_inicio(T elm);
	bool insertar_final(T elm);
	bool insertar_pos(T elm, int pos);
	bool suprimir(int pos);
	T buscar(int pos);
	T primero();
	T ultimo();
	int long_lista();
	bool esta_vacia();
	//bool esta_llena();
};



#endif /* LISTACIRCULAR_H_ */
