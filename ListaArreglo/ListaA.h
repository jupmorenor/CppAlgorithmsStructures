/**
 * ListaA.h
 *
 *  Created on: 24/09/2014
 *      Author: Juan Pablo Moreno Rico - 20111020059
 */

#ifndef LISTAA_H_
#define LISTAA_H_

class ListaA {
	int *L;
	int pos_libre;
	int tam;
public:
	ListaA(int _tam);
	~ListaA();
	bool insertar_inicio(int elm);
	bool insertar_final(int elm);
	bool insertar_pos(int elm, int pos);
	bool suprimir(int pos);
	int buscar(int val);
	int primero();
	int ultimo();
	int long_lista();
	bool esta_vacia();
	bool esta_llena();
};
#endif /* LISTAA_H_ */
