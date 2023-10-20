No* buscaArvoreRN(No* raiz, int chave) {
    if (raiz == NULL || raiz->info == chave) {
        return raiz;
    }

    if (chave < raiz->info) {
        return buscaArvoreRN(raiz->esq, chave);
    } else {
        return buscaArvoreRN(raiz->dir, chave);
    }
}
