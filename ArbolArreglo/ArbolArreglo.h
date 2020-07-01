/*
 * ArbolArreglo.h
 *
 *  Created on: 16/10/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#ifndef ARBOLARREGLO_H_
#define ARBOLARREGLO_H_

struct Nodo {
	int clave, izq, der;
};

class ArbolArreglo {
	Nodo *arreglo;
	int tam;
public:
	ArbolArreglo(int t);
	~ArbolArreglo();
	bool insertar(int clave);
	void eliminarHoja(int padre, int hijo);
	void eliminarUnHijo(int padre, int hijo);
	bool eliminarDosHijos(int padre,  int hijo);
	bool eliminarRaiz();
	bool eliminar(int clave);
	int buscarPadre(int clave);
	int derMasIzq(int pos);
	int buscar(int clave);
	void inorden();
	void preorden();
	void postorden();
	void imprimirArreglo();
};

#endif /* ARBOLARREGLO_H_ */
