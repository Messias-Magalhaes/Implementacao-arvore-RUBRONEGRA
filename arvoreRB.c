No* buscaRN(No* raiz, int chave) {
    if (raiz == NULL || raiz->info == chave) {
        return raiz;
    }

    if (chave < raiz->info) {
        return buscaRN(raiz->esq, chave);
    } else {
        return buscaRN(raiz->dir, chave);
    }
}

No* inserirRN(No* raiz, int chave) {
    if (raiz == NULL) {
        return criarNo(chave);
    }

    if (chave < raiz->info) {
        raiz->esq = inserirRN(raiz->esq, chave);
    } else if (chave > raiz->info) {
        raiz->dir = inserirRN(raiz->dir, chave);
    } else {
        return raiz;
    }

    if (raiz->dir != NULL && raiz->esq != NULL) {
        if (raiz->dir->cor == VERMELHO && raiz->esq->cor == PRETO) {
            raiz = rotacionaEsquerda(raiz);
        }
        if (raiz->esq->cor == VERMELHO && raiz->esq->esq != NULL && raiz->esq->esq->cor == VERMELHO) {
            raiz = rotacionaDireita(raiz);
        }
        if (raiz->esq->cor == VERMELHO && raiz->dir->cor == VERMELHO) {
            inverterCores(raiz);
        }
    }

    return raiz;
}
