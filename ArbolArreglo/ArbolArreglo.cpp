/*
 * ArbolArreglo.cpp
 *
 *  Created on: 16/10/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */
#include <iostream>
#include "ArbolArreglo.h"
#include "pilaArbol.h"

ArbolArreglo::ArbolArreglo(int t) {
	tam = t;
	arreglo = new Nodo[tam];
	arreglo[0].izq = 0;
	for (int i = 0; i < tam - 1; i++) {
		arreglo[i].der = i + 1;
	}
	arreglo[tam - 1].der = 0;
}

ArbolArreglo::~ArbolArreglo() {
	delete[] arreglo;
}

bool ArbolArreglo::insertar(int clave) {
	int aux, pos;
	if (arreglo[0].der == 0) {
		return false;
	}
	if (arreglo[0].izq == 0) {
		aux = arreglo[0].der;
		arreglo[0].izq = aux;
		arreglo[aux].clave = clave;
		arreglo[0].der = arreglo[aux].der;
		arreglo[aux].izq = 0;
		arreglo[aux].der = 0;

	} else {
		aux = arreglo[0].der;
		arreglo[0].der = arreglo[aux].der;
		arreglo[aux].clave = clave;
		arreglo[aux].izq = 0;
		arreglo[aux].der = 0;
		pos = arreglo[0].izq;
		while (pos != 0) {
			if (clave < arreglo[pos].clave) {
				if (arreglo[pos].izq == 0) {
					arreglo[pos].izq = aux;
					pos = 0;
				} else {
					pos = arreglo[pos].izq;
				}
			} else if (clave > arreglo[pos].clave) {
				if (arreglo[pos].der == 0) {
					arreglo[pos].der = aux;
					pos = 0;
				} else {
					pos = arreglo[pos].der;
				}
			}
		}
	}
	return true;
}

int ArbolArreglo::buscarPadre(int clave) {
	int aux;
	int pos = arreglo[0].izq;
	if (clave < arreglo[pos].clave)
		aux = arreglo[pos].izq;
	else if (clave > arreglo[pos].clave)
		aux = arreglo[pos].der;
	while (clave != arreglo[aux].clave) {
		if (clave < arreglo[aux].clave) {
			if (arreglo[aux].izq == 0) {
				aux = 0;
				break;
			} else {
				pos = aux;
				aux = arreglo[aux].izq;
			}
		} else if (clave > arreglo[aux].clave) {
			if (arreglo[aux].der == 0) {
				aux = 0;
				break;
			} else {
				pos = aux;
				aux = arreglo[aux].der;
			}
		}
	}
	return pos;
}

int ArbolArreglo::derMasIzq(int pos) {
	int aux = 0;
	if (arreglo[pos].der != 0) {
		aux = arreglo[pos].der;
		if (arreglo[aux].izq != 0)
			while (arreglo[aux].izq != 0)
				aux = arreglo[aux].izq;
		else
			aux = arreglo[pos].der;
	}
	return aux;
}

void ArbolArreglo::eliminarHoja(int padre, int hijo) {
	if (arreglo[hijo].clave < arreglo[padre].clave) {
		arreglo[padre].izq = 0;
	} else if (arreglo[hijo].clave > arreglo[padre].clave) {
		arreglo[padre].der = 0;
	}
	arreglo[hijo].clave = 0;
	arreglo[hijo].der = arreglo[0].der;
	arreglo[0].der = hijo;
}

void ArbolArreglo::eliminarUnHijo(int padre, int hijo) {
	int asd;
	if (arreglo[hijo].izq != 0) {
		asd = arreglo[hijo].izq;
		if (arreglo[hijo].clave < arreglo[padre].clave) {
			arreglo[padre].izq = asd;
		} else if (arreglo[hijo].clave > arreglo[padre].clave) {
			arreglo[padre].der = asd;
		}
		arreglo[hijo].der = arreglo[0].der;
		arreglo[0].der = hijo;
		arreglo[hijo].clave = 0;
		arreglo[hijo].izq = 0;
	} else if (arreglo[hijo].der != 0) {
		asd = arreglo[hijo].der;
		if (arreglo[hijo].clave < arreglo[padre].clave) {
			arreglo[padre].izq = asd;
		} else if (arreglo[hijo].clave > arreglo[padre].clave) {
			arreglo[padre].der = asd;
		}
		arreglo[hijo].der = arreglo[0].der;
		arreglo[0].der = hijo;
		arreglo[hijo].clave = 0;
		arreglo[hijo].izq = 0;

	}
}

bool ArbolArreglo::eliminarDosHijos(int padre, int hijo) {
	int r, pR;
	r = derMasIzq(hijo);
	pR = buscarPadre(r);
	if (arreglo[r].der == 0 && arreglo[r].izq == 0) {
		arreglo[r].der = arreglo[hijo].der;
		arreglo[r].izq = arreglo[hijo].izq;
	}

	else if (arreglo[r].der != 0 && arreglo[r].izq == 0) {
		if (arreglo[r].clave < arreglo[pR].clave)
			arreglo[pR].izq = arreglo[r].der;
		else if (arreglo[r].clave > arreglo[pR].clave)
			arreglo[pR].der = arreglo[r].der;
		arreglo[r].der = arreglo[hijo].der;
		arreglo[r].izq = arreglo[hijo].izq;
	}
	if (arreglo[hijo].clave > arreglo[padre].clave)
		arreglo[padre].der = r;
	else if (arreglo[hijo].clave < arreglo[padre].clave)
		arreglo[padre].izq = r;
	arreglo[hijo].der = arreglo[0].der;
	arreglo[0].der = hijo;
	arreglo[hijo].clave = 0;
	arreglo[hijo].izq = 0;
	return true;

}

bool ArbolArreglo::eliminarRaiz() {
	int r, pR, aux;
	aux = arreglo[0].izq;
	if (arreglo[aux].der != 0) {
		r = derMasIzq(aux);
		pR = buscarPadre(r);
		if (arreglo[r].der == 0 && arreglo[r].izq == 0) {

			arreglo[r].der = arreglo[aux].der;
			arreglo[r].izq = arreglo[aux].izq;

		} else if (arreglo[r].der != 0 && arreglo[r].izq == 0) {
			if (arreglo[r].clave < arreglo[pR].clave)
				arreglo[pR].izq = arreglo[r].der;
			else if (arreglo[r].clave > arreglo[pR].clave)
				arreglo[pR].der = arreglo[r].der;
			arreglo[r].der = arreglo[aux].der;
			arreglo[r].izq = arreglo[aux].izq;
		}
	}
	arreglo[aux].der = arreglo[0].der;
	arreglo[aux].clave = 0;
	arreglo[aux].izq = 0;
	arreglo[0].der = aux;
	arreglo[0].izq = r;
	return true;
}

///Falta revisar y completar cuando dos hijos
bool ArbolArreglo::eliminar(int clave) {
	int padre, posE;
	posE = buscar(clave);
	if (posE == arreglo[0].izq) {
		eliminarRaiz();
	} else if (posE != arreglo[0].izq) {
		padre = buscarPadre(clave);
		if (posE == 0) {
			return false;
		} else {
			if (arreglo[posE].izq == 0 && arreglo[posE].der == 0)
				eliminarHoja(padre, posE);
			else if ((arreglo[posE].izq == 0 && arreglo[posE].der != 0)
					|| (arreglo[posE].izq != 0 && arreglo[posE].der == 0))
				eliminarUnHijo(padre, posE);
			else if (arreglo[posE].izq != 0 && arreglo[posE].der != 0)
				eliminarDosHijos(padre, posE);

		}
	}
	return true;
}

int ArbolArreglo::buscar(int clave) {
	int pos = arreglo[0].izq;
	while (clave != arreglo[pos].clave) {
		if (clave < arreglo[pos].clave) {
			if (arreglo[pos].izq == 0) {
				pos = 0;
				break;
			} else {
				pos = arreglo[pos].izq;
			}
		} else if (clave > arreglo[pos].clave) {
			if (arreglo[pos].der == 0) {
				pos = 0;
				break;
			} else {
				pos = arreglo[pos].der;
			}
		}
	}
	return pos;
}

//Terminar

void ArbolArreglo::inorden() {
	int pos = arreglo[0].izq;
	Pila pila;
	pila.push(pos);
	while (!pila.pilaVacia()) {
		pos = pila.pop();
		while (pos != 0) {
			pila.push(arreglo[pos].der);
			pila.push(pos);
			pos = arreglo[pos].izq;
		}
		if (!pila.pilaVacia()) {
			pos = pila.pop();
			std::cout << arreglo[pos].clave << " ";
		}
	}
	std::cout << std::endl;
}

//ok
void ArbolArreglo::preorden() {
	int pos = arreglo[0].izq;
	Pila pila;
	pila.push(pos);
	while (!pila.pilaVacia()) {
		pos = pila.pop();
		while (pos != 0) {
			std::cout << arreglo[pos].clave << " ";
			pila.push(arreglo[pos].der);
			pos = arreglo[pos].izq;
		}
	}
	std::cout << std::endl;
}

//ok
void ArbolArreglo::postorden() {
	int pos = arreglo[0].izq;
	Pila pila;
	pila.push(0);
	while (!pila.pilaVacia()) {
		while (pos != 0) {
			pila.push(pos);
			if (arreglo[pos].der != 0) {
				pila.push(arreglo[pos].der);
				pila.push(0);
			}
			pos = arreglo[pos].izq;
		}
		pos = pila.pop();
		while (pos != 0) {
			std::cout << arreglo[pos].clave << " ";
			pos = pila.pop();
		}
		if (!pila.pilaVacia()) {
			if (pos == 0) {
				pos = pila.pop();
			}
		}
	}
	std::cout << std::endl;
}

void ArbolArreglo::imprimirArreglo() {
	int i;
	for (i = 0; i < tam; i++) {
		std::cout << arreglo[i].clave << "[" << arreglo[i].izq << ", "
				<< arreglo[i].der << "]  ";
	}
	std::cout << std::endl;
}

