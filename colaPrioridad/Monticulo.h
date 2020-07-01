/*
 * Monticulo.h
 *
 *  Created on: 23/10/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#ifndef MONTICULO_H_
#define MONTICULO_H_

class Monticulo {
	int *arreglo;
	int tam, posActiva;
public:
	Monticulo(int _tam);
	~Monticulo();
	bool insertar(int prior);
	void imprimir();
	int maxi(int a, int b);
	int atender();
};

#endif /* MONTICULO_H_ */
