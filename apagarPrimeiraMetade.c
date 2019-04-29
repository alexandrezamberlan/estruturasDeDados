//metodos para excluir a primeira metade de lista simples
Celula *apagarPrimeiraMetade(Celula *l) {
	Celula *p;
	int qtd;
	for (p = l, qtd = 0; p; qtd++, p = p->prox);
	
	if (qtd <= 1) return l; //nao ha exclusao
	
	for (p = l, l = l->prox, qtd/=2; qtd > 0; qtd--, p = l, l = l->prox) {
		free(p);
	}
	return p;
}

//metodos para excluir a primeira metade de lista simples
Celula *apagarPrimeiraMetadeC(Celula *l) {
	Celula *p;
	int qtd;
	for (p = l, qtd = 0; p->prox = !l; qtd++, p = p->prox);
	qtd++;
	
	if (qtd <= 1) return l; //nao ha exclusao
	
	pR = l; //copia de seguranca do 1o elemento
	
	for (p = l, l = l->prox, qtd/=2; qtd > 0; qtd--, p = l, l = l->prox) {
		free(p);
	}
	//levar o l ate o ultimo elemento para apontar para o elemento do meio em p
	for (;l->prox != pR; l = l->prox);
	
	l->prox = p;
	
	return p;
}
