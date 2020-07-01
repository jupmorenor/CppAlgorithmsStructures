/*
 * RojoNegro.cpp
 *
 *  Created on:
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */
#include "conio.h"
#include <iostream>
using namespace std;

const bool ROJO = 1;
const bool NEGRO = 0;

struct NODO {
	int info;
	NODO *izq, *der, *padre;
	bool color;
};

class ARBOL {
	NODO *raiz;
public:
	ARBOL() {
		raiz = NULL;
	}
	NODO *raiz_arbol();
	int ins_arbol(int);
	NODO *buscar_arbol(int, NODO *, NODO *);
	void borrar_nodo(NODO *, NODO *);
	NODO *buscar(int, NODO **, NODO *);
	int retira_arbol(int);
	void rojosSeguidos(NODO *p, NODO *x, bool pos);
	void ajustarBorrado(NODO *p, NODO *x);
	void inorden(NODO *p);
	void preorden(NODO *p);
	void posorden(NODO *p);
	void destruir(NODO *p);
	~ARBOL();
};

NODO *ARBOL::raiz_arbol() {
	return raiz;
}

NODO *ARBOL::buscar_arbol(int n, NODO *p, NODO *q) {
	if (p == NULL)
		return q;
	if (n < p->info) {
		q = p;
		q = buscar_arbol(n, p->izq, q);
		return q;
	} else if (n > p->info) {
		q = p;
		q = buscar_arbol(n, p->der, q);
		return q;
	} else
		return NULL;
}

int ARBOL::ins_arbol(int n) {
	NODO *q;
	bool pos;
	if (raiz == NULL) {
		raiz = new NODO;
		raiz->info = n;
		raiz->izq = raiz->der = raiz->padre = NULL;
		raiz->color = NEGRO;
		return 0;
	}
	q = buscar_arbol(n, raiz, NULL);
	if (q == NULL)
		return -1;
	NODO *nuevo;
	nuevo = new NODO;
	nuevo->info = n;
	nuevo->izq = nuevo->der = NULL;
	nuevo->color = ROJO;
	if (n < q->info) {
		q->izq = nuevo;
		pos = 0;
	}
	else {
		q->der = nuevo;
		pos = 1;
	}
	nuevo->padre = q;
	if (nuevo->color == q->color) {
		rojosSeguidos(q, nuevo, pos);
	}
	return 0;
}

void ARBOL::borrar_nodo(NODO *q, NODO *p) {
	NODO *r, *s, *t;
	if (p->izq == NULL)
		r = p->der;
	else if (p->der == NULL)
		r = p->izq;
	else {
		s = p;
		r = p->der;
		t = r->izq;
		while (t != NULL) {
			s = r;
			r = t;
			t = t->izq;
		}
		if (p != s) {
			s->izq = r->der;
			r->der = p->der;
			if (s->izq != NULL) {
				s->izq->padre = s;
			}
			if (r->der != NULL) {
				r->der->padre = r;
			}
		}
		r->izq = p->izq;
		if (r->izq != NULL) {
			r->izq->padre = r;
		}
	}
	ajustarBorrado(q, p);
	if (q == NULL) {
		r->padre = NULL;
		raiz = r;
	}
	else if (p == q->izq) {
		q->izq = r;
	} else {
		q->der = r;
	}
	if (r != NULL) {
		r->padre = q;
		r->color = p->color;
	}
	delete p;
}

void ARBOL::ajustarBorrado(NODO *p, NODO *x) {
	NODO *w, *a, *b;
	while ((x != raiz) && x->color == NEGRO) {
		if (p->izq == x) {
			w = p->der;
			if (w->color == ROJO) {
				/**
				 * caso 1
				 */
				w->color = NEGRO;
				p->color = ROJO;
				p->der = w->izq;
				w->izq = p;
				w->padre = p->padre;
				p->padre = w;
				if (w->padre != NULL) {
					if (w->padre->izq == p) {
						w->padre->izq = w;
					} else if (w->padre->der == p) {
						w->padre->der = w;
					}
				} else {
					raiz = w;
				}
				w = p->der;
			}
			if (w != NULL) {
				/**
				 * caso 2
				 */
				a = w->izq;
				b = w->der;
				if ((a == NULL ? true : (a->color == NEGRO)) &&
						(b == NULL ? true : (b->color == NEGRO))) {
					w->color = ROJO;
					x = x->padre;
				} else {
					if ((b == NULL ? true : (b->color == NEGRO))) {
						/**
						 * caso 3
						 */
						if (a != NULL) {
							a->color = NEGRO;
							w->color = ROJO;
							w->izq = a->der;
							a->der = w;
							a->padre = w->padre;
							w->padre = a;
							if (a->padre->izq == w) {
								a->padre->izq = a;
							} else if (a->padre->der == w) {
								a->padre->der = a;
							}
							w = p->der;
						}
					}
					/**
					 * caso 4
					 */
					w->color = p->color;
					p->color = NEGRO;
					if (w->der != NULL) {
						w->der->color = NEGRO;
					}
					p->der = w->izq;
					w->izq = p;
					w->padre = p->padre;
					p->padre = w;
					if (w->padre != NULL) {
						if (w->padre->izq == p) {
							w->padre->izq = w;
						} else if (w->padre->der == p) {
							w->padre->der = w;
						}
					} else {
						raiz = w;
					}
					x = raiz;

				}
			}
		} else if (p->der == x) {
			w = p->izq;
			if (w->color == ROJO) {
				/**
				 * caso 1
				 */
				w->color = NEGRO;
				p->color = ROJO;
				p->izq = w->der;
				w->der = p;
				w->padre = p->padre;
				p->padre = w;
				if (w->padre != NULL) {
					if (w->padre->izq == p) {
						w->padre->izq = w;
					} else if (w->padre->der == p) {
						w->padre->der = w;
					}
				} else {
					raiz = w;
				}
				w = p->izq;
			}
			if (w != NULL) {
				/**
				 * caso 2
				 */
				a = w->der;
				b = w->izq;
				if ((a == NULL ? true : (a->color == NEGRO)) &&
						(b == NULL ? true : (b->color == NEGRO))) {
					w->color = ROJO;
					x = x->padre;
				} else {
					if ((b == NULL ? true : (b->color == NEGRO))) {
						/**
						 * caso 3
						 */
						if (a != NULL) {
							a->color = NEGRO;
							w->color = ROJO;
							w->der = a->izq;
							a->izq = w;
							a->padre = w->padre;
							w->padre = a;
							if (a->padre->izq == w) {
								a->padre->izq = a;
							} else if (a->padre->der == w) {
								a->padre->der = a;
							}
							w = p->izq;
						}
					}
					/**
					 * caso 4
					 */
					w->color = p->color;
					p->color = NEGRO;
					if (w->izq != NULL) {
						w->izq->color = NEGRO;
					}
					p->izq = w->der;
					w->der = p;
					w->padre = p->padre;
					p->padre = w;
					if (w->padre != NULL) {
						if (w->padre->izq == p) {
							w->padre->izq = w;
						} else if (w->padre->der == p) {
							w->padre->der = w;
						}
					} else {
						raiz = w;
					}
					x = raiz;
				}
			}
		}
	}
	x->color = NEGRO;
}

NODO *ARBOL::buscar(int n, NODO **p, NODO *q) {
	if (*p == NULL)
		return NULL;
	if (n < (*p)->info) {
		q = *p;
		*p = (*p)->izq;
		q = buscar(n, p, q);
		return q;
	} else if (n > (*p)->info) {
		q = *p;
		*p = (*p)->der;
		q = buscar(n, p, q);
		return q;
	} else
		return q;
}

int ARBOL::retira_arbol(int n) {
	NODO *q, *p = raiz;
	q = buscar(n, &p, NULL);
	if (p == NULL)
		return -1;
	borrar_nodo(q, p);
	return 0;
}

void ARBOL::rojosSeguidos(NODO *p, NODO *x, bool pos) {
	NODO *abuelo = p->padre;
	NODO *tio;
	bool posTio;
	if (abuelo->izq == p) {
		tio = abuelo->der;
		posTio = 1;
	} else if (abuelo->der == p) {
		tio = abuelo->izq;
		posTio = 0;
	}

	if (tio==NULL ? false : (tio->color == ROJO)) {
		/**
		 * caso 1 ok
		 */
		p->color = !p->color;
		abuelo->color = !abuelo->color ;
		if (tio!=NULL) {
			tio->color = !tio->color;
		}
		if (abuelo == raiz) {
			abuelo->color = NEGRO;
		} else {
			if (abuelo->padre->izq == abuelo) {
				pos = 0;
			} else {
				pos = 1;
			}
			if (abuelo->color == ROJO && abuelo->padre->color == ROJO) {
				rojosSeguidos(abuelo->padre, abuelo, pos);
			}
		}
	} else if (tio==NULL ? true : (tio->color == NEGRO)){
		if (posTio == pos) {
			/**
			 * caso 2
			 */
			if (pos == 1) {
				abuelo->izq = x;
				x->padre = abuelo;
				x->izq = p;
				p->padre = x;
				p->der = NULL;
				pos = 0;
			} else {
				abuelo->der = x;
				x->padre = abuelo;
				x->der = p;
				p->padre = x;
				p->der = NULL;
				pos = 1;
			}
			rojosSeguidos(x, p, pos);

		} else {
			/**
			 * caso 3
			 */
			abuelo->color = ROJO;
			p->color = 0;
			if (pos == 0) {
				abuelo->izq = p->der;
				p->der = abuelo;
				p->padre = abuelo->padre;
				abuelo->padre = p;

			} else {
				abuelo->der = p->izq;
				p->izq = abuelo;
				p->padre = abuelo->padre;
				abuelo->padre = p;
			}
			if (abuelo == raiz) {
				raiz = p;
			} else {
				if (p->padre->izq == abuelo) {
					p->padre->izq = p;
					pos = 0;
				} else if (p->padre->der == abuelo) {
					p->padre->der = p;
					pos = 1;
				}
				if (p->color == ROJO && p->padre->color == ROJO) {
					rojosSeguidos(p->padre, p, pos);
				}
			}
		}
	}
}

void ARBOL::inorden(NODO *p) {
	if (p != NULL) {
		inorden(p->izq);
		cout << p->info << "." << p->color << "  ";
		inorden(p->der);
	}
}

void ARBOL::preorden(NODO *p) {
	if (p != NULL) {
		cout << p->info <<  "." << p->color << "  ";
		preorden(p->izq);
		preorden(p->der);
	}
}

void ARBOL::posorden(NODO *p) {
	if (p != NULL) {
		posorden(p->izq);
		posorden(p->der);
		cout << p->info << "." << p->color << "  ";
	}
}

void ARBOL::destruir(NODO *p) {
	if (p != NULL) {
		destruir(p->izq);
		destruir(p->der);
		delete p;
		cout << "Nodo destruido..." << endl;
	}
}
ARBOL::~ARBOL() {
	destruir(raiz);
}

