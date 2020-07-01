/*
 * ListaStruct.h
 *
 *  Created on: 25/09/2014
 *      Author: Juan Pablo Moreno Rico - 20111020059
 */

#ifndef LISTASTRUCT_H_
#define LISTASTRUCT_H_

template <typename S> struct Nodo {
	S dato;
	Nodo<S> *siguiente;
};

template <class T> class ListaS {
private:
	Nodo<T> *cabeza;
	int tam;
	Nodo<T> *crear_nodo(T val) {
		Nodo<T> *nodo = new Nodo<T>;
		nodo->dato = val;
		return nodo;
	}
public:
	ListaS();
	~ListaS();
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

#endif /* LISTASTRUCT_H_ */
