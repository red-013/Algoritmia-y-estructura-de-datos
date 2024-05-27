
#ifndef FUNCIONESPILA_H
#define FUNCIONESPILA_H

#include "ArbolBinario.h"


void construir(struct Pila & );
bool esPilaVacia(const struct Pila &);
void apilar(struct Pila &, struct ArbolBinario ); 
struct ArbolBinario desapilar(struct Pila &);
struct ArbolBinario cima(const struct Pila &);

#endif /* FUNCIONESPILA_H */

