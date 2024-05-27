
#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

#include "ArbolBinario.h"

void construir(struct Lista &);
const bool esListaVacia(const struct Lista & tad);
void insertarAlInicio(struct Lista &, struct ArbolBinario);
struct ArbolBinario retornaCabeza(const struct Lista & tad);
void eliminaCabeza(struct Lista & tad);
struct ArbolBinario retornaCabeza(const struct Lista & tad);

#endif /* FUNCIONESLISTA_H */

