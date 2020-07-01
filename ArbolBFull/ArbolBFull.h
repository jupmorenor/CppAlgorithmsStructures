/*
 * ArbolBFull.h
 *
 *  Created on: 14/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#ifndef ARBOLBFULL_H_
#define ARBOLBFULL_H_

struct nodo {
	int *claves;
	nodo **hijos;
	int Nclaves;
	bool hoja;
};

class arbolB {
	nodo * raiz;
	int d;
public:
	arbolB(int ord) {
		d = ord;
		raiz = crear_nodo();
		raiz->Nclaves = 0;
		raiz->hoja = true;
	}
	nodo* crear_nodo();
	nodo* dar_raiz();
	int dividir_nodo(nodo *actual, nodo **hermano, nodo **nuevo);
	void insertar(int clave);
	nodo* buscar_nodo(int clave, nodo *Actual, nodo **padre);
	int InsertarNodoNormal(int clave, nodo *Actual);
	void InsertarNodoLleno(int clave, nodo *Actual, nodo *padre);
	nodo * buscar_padre(int clave, nodo *Actual, nodo *padre);
	int borrar(int clave);
	int buscar_clave(int clave, nodo **actual, nodo **padre);
	int borrarEn_hoja(int clave, int pos, nodo * actual, nodo * padre);
	void Ajustar_nodo(int pos, nodo * actual);
	int buscar_lugarEntreHnos(int clave, nodo* padre);
	bool Ayuda_hnoDer(nodo *padre, int posActual);
	bool Ayuda_hnoIzq(nodo *padre, int posActual);
	void juntar(nodo *padre, int pos, int posActual);
	void reemplazar_Der(nodo *actual, nodo *padre, int posActual);
	void reemplazar_Izq(nodo *actual, nodo *padre, int posActual);
	void unir_Hno_Der(nodo *padre, int posClave, int posActual);
	void unir_Hno_Izq(nodo *padre, int posClave, int posActual);
	void AjustarNivelPadre(nodo *actual, int posclave);
	void borrarEn_Ninterno(int pos, nodo* actual);
	bool verificar_der(nodo **hijo, nodo**padre);
	bool verificar_izq(nodo **hijo, nodo**padre);
	void imprimirArbol(nodo *raiz);
};

#endif /* ARBOLBFULL_H_ */
