
#include "utilitarios.h"

void displayBits(unsigned value){

	const int SHIFT = 8 * sizeof( unsigned ) - 1;
	const unsigned MASK = 1 << SHIFT ;



	//cout<< setw(7) << value << " = ";

	for (unsigned c = 1; c <= SHIFT +1; c++){
		cout << (value & MASK ? '1' : '0');
		value <<= 1;
		if (c % 8 == 0)
			cout << ' ';

	}

	cout << endl;

}

void displayBitsll(unsigned long long value){

	const unsigned long long  SHIFT = 8 * sizeof( unsigned long long ) - 1;
	const unsigned long long MASK = (unsigned long long)1 << SHIFT ;// joga do menos para o mais significativo

	//cout<< setw(7) << value << " = ";

	for (unsigned long long c = 1; c <= SHIFT +1; c++){
		cout << (value & MASK ? '1' : '0');
		value <<= 1;
		if (c % 8 == 0)
			cout << ' ';

	}

	cout << endl;

}

void displayBitsCliquell(unsigned long long *clique){

	unsigned long long  value;
	const unsigned long long  SHIFT = 8 * sizeof( unsigned long long ) - 1;
	const unsigned long long MASK = (unsigned long long)1 << SHIFT ;// joga do menos para o mais significativo

	//cout<< setw(7) << value << " = ";

	for(int k = 0; k<qtd_palavrasULL;++k){
		value = clique[k];
		for (unsigned long long c = 1; c <= SHIFT +1; c++){
			cout << (value & MASK ? '1' : '0');
			value <<= 1;
			if (c % 8 == 0)
				cout << ' ';

		}
		cout<< endl;
	}

	cout << endl;

}


void inicializarRll(int linha){

	int palavraVerticeJ, posicaoVerticeJ;


	for(int col = 0; col<qtd_vertices; ++col)
		R(linha,col) = 0ULL;


	for(int j = 0; j<qtd_vertices;++j){

		palavraVerticeJ  = (int)(j/ULLONG);
		posicaoVerticeJ = j % ULLONG;

		R(linha,palavraVerticeJ) = R(linha,palavraVerticeJ) | (1ULL << posicaoVerticeJ);

	}
}


int isZero(unsigned long long *R, int i,int *j){

	//	printf("\n\t isZero, i = %d\n",i);
	if(i<0)
		return -1;

	for(int k = 0; k<qtd_palavrasULL; ++k){
		if(R(i,k)>0){
			*j = __builtin_ffsll(R(i,k)) -1;
			return k;
		}

	}
	//	printf("\t saindo isZero, i = %d\n",i);
	return -1;

}

int isZero(unsigned long long *vertice, int *j){


	for(int k = 0; k<qtd_palavrasULL; ++k){
		if(vertice[k]>0){
			*j = __builtin_ffsll(vertice[k]) -1;
			return k;
		}

	}

	return -1;

}

void imprimirLinhall(unsigned long long *R, int i){

	cout<<"\n\nImprimindo Linha "<< i<<" :\n";

	for(int j =0; j<N;++j){
		displayBitsll(R(i,j));

	}
}


void imprimirGrafoll(){

	cout<<"\n\nImprimindo Grafo "<<N<<" x "<<N<<" long long. \n";
	for(int i = 0; i<qtd_vertices; ++i){
		cout<<"\nLinha "<< i<< " : ";
		cout<<"\n";
		for(int j =0; j<qtd_palavrasULL;++j){
			cout<<"\n Coluna "<< j<< " : ";
			displayBitsll(G(i,j));
		}
	}
}

void imprimirGrafoll(unsigned long long *G){

	cout<<"\n\nImprimindo Grafo "<<N<<" x "<<N<<" long long. \n";
	for(int i = 0; i<qtd_vertices; ++i){
		cout<<"\nLinha "<< i<< " : ";
		cout<<"\n";
		for(int j =0; j<qtd_palavrasULL;++j){
			cout<<"\n Coluna "<< j<< " : ";
			displayBitsll(G(i,j));
		}
	}
}


int qtdUns(unsigned long long *R, int i){

	int qtd=0;
	for(int k = 0; k<qtd_palavrasULL; ++k){

		qtd += __builtin_popcountll(R(i,k));

	}

	return qtd;

}



void verticesDaClique(unsigned long long *vertices){

	int palavraPrimeiroUm;
	int j;

	do{

		palavraPrimeiroUm = isZero(vertices,&j);
		if(palavraPrimeiroUm>-1){

			//printf("\tPalavra primeiro um: %d, \n\t j: %d, \n\t posicao: %d. \n\n",palavraPrimeiroUm,j,palavraPrimeiroUm*ULLONG+j);
			cout<<palavraPrimeiroUm*ULLONG+j;
			cout<<" ";
			vertices[palavraPrimeiroUm] = vertices[palavraPrimeiroUm] &  ~(1ULL<<j);

		}
	}
	while(palavraPrimeiroUm> -1);



}

void inicializarVetorCll(){

	for(int i = 0; i<qtd_palavrasULL;++i)
		c[i] = 0LL;
}



