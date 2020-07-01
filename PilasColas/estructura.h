/*
 * estructura.h
 *
 *  Created on: 10/10/2014
 *      Author: Juanpa y Yami
 */

#ifndef ESTRUCTURA_H_
#define ESTRUCTURA_H_

template <typename T> struct nodo{
	T dato;
    nodo<T> *sig;
};

#endif /* ESTRUCTURA_H_ */
