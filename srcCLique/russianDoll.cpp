
#include "russianDoll.h"


bool decide(unsigned long long  R, int l){

	unsigned long long W;
	unsigned long long novoR;
	int v;

	if(R==0)
		return (l==0);

	W = 0ULL;

	while(R!=0){

		v =  __builtin_ffsll(R) -1;//smallest v in R\W


		R &= ~(1ULL<<v);

		novoR = W&G(v,0);



		if(decide(novoR,l-1)){
			return true;
		}
		W = W | (1ULL<<v);

	}

	return false;

}


void recursiveRussianDoll(){


	cout<<"\n\n<<<<Russian Doll>>>>";
	int v;
	int MAX = 0;
	int i = 0;
	unsigned long long V[qtd_vertices];
	unsigned long long verticesAux;
//	unsigned long long c,cMax;

//	c = 0ULL;
	for(int k = 0; k<qtd_vertices; ++k)
		V[k] = 0ULL;

	while(i<qtd_vertices){

		v =  (qtd_vertices - i)-1;//


		verticesAux = V[i] & G(v,0);

		if(decide(verticesAux,MAX)){

			MAX++;
			V[i+1] = V[i] | (1ULL<<v);
			i++;


		}
		else{
			V[i+1] = V[i] | (1ULL<<v);
			i++;

		}

	}

	cout<<"\n\nTamanho do Clique Maximo: "<<MAX<<". \n";


}



void MWNonRecursiveRussianDoll(){

	cout<<"\n\n<<<<Multiple Words Non Recursive Russian Doll>>>>";
	int v;
	int palavraV;
	int posicaoV;

	int MAX = 0;
	int i = 0;
	int profundidade;

	bool decide;
	int vertices[qtd_vertices];
	int l;

	int palavraUtilizada[qtd_vertices];
	int palavraPrimeiroUm;

	int verticeEmQuestao;
	register unsigned long long cMax[qtd_palavrasULL];


	/*
	 *
	 * */
	for(int col = 0; col<qtd_palavrasULL; ++col)
		V(0,col) = 0ULL;


	while(i<qtd_vertices){

		inicializarVetorCll();

		v =  (qtd_vertices - i)-1;//

		palavraV  = (int)(v/ULLONG);
		posicaoV= v % ULLONG;


		//ira' comecar a decidir
		profundidade = 0;

		for(int col = 0; col<qtd_palavrasULL;++col)
			R(0,col) = V(i,col) & G(v,col);

		for(int col = 0; col<qtd_palavrasULL;++col)//W[0] = 0ULL;
			W(0,col) = 0ULL;

		//variaveis do decide

		l = MAX;
		decide = false;


		/*
		 * DECIDE NAO RECURSIVO
		 * */

		while(profundidade >= 0){

			palavraPrimeiroUm=isZero(R,profundidade,&vertices[profundidade]); //Trocar vertices por posicao

			while(palavraPrimeiroUm>=0){

				palavraUtilizada[profundidade] = palavraPrimeiroUm;

				R(profundidade,palavraPrimeiroUm) &= ~(1ULL<<vertices[profundidade]);

				c[palavraPrimeiroUm] |= (1ULL<<(vertices[profundidade]));

				verticeEmQuestao = palavraPrimeiroUm*ULLONG+vertices[profundidade];


				for(int col = 0; col<qtd_palavrasULL;++col){

					R((profundidade+1),col) = W(profundidade,col) & G(verticeEmQuestao,col);
				}


				l--;
				profundidade++;

				//				for(int col = 0; col<qtd_palavrasULL;++col)
				//					W((profundidade+1),col) = 0ULL;
				/*(?)
				 * w[p++]=0 ?
				 *
				 * */

				palavraPrimeiroUm=isZero(R,profundidade,&vertices[profundidade]);
			}


			if(l>0){

				l++;
				profundidade--;

				if(profundidade==-1){
					break;
				}

				c[palavraUtilizada[profundidade]] &= ~(1ULL<<vertices[profundidade]);

				W(profundidade,palavraUtilizada[profundidade]) |= (1ULL<<vertices[profundidade]);

				for(int col = 0; col<qtd_palavrasULL;++col)
					W((profundidade+1),col) = 0ULL;
			}
			else{
				decide = true;
				break;
			}


		}//while(p>=0)

		/*fim de decide
		 * */
		if(decide){


			for(int col = 0; col<qtd_palavrasULL;++col)
				V((i+1),col) = V(i,col);

			V((i+1),palavraV) |= (1ULL<<posicaoV);

			c[palavraV] |= (1ULL<<posicaoV);

			memcpy(cMax,c,sizeof(c));

			MAX++;
			i++;

		}
		else{

			for(int col = 0; col<qtd_palavrasULL;++col)
				V((i+1),col) = V(i,col);

			V((i+1),palavraV) |= (1ULL<<posicaoV);

			i++;

		}

	}

	cout<<"\n\nTamanho do Clique Maximo: "<<MAX<<". \n";

	verticesDaClique(cMax);

}


void nonRecursiveRussianDoll(){

	cout<<"\n\n<<<<Non Recursive Russian Doll>>>>";
	int v;
	int MAX = 0;
	int i = 0;
	int profundidade;
	unsigned long long V[qtd_vertices];
	unsigned long long verticesAux;
	unsigned long long c,cMax;


	unsigned long long W[qtd_vertices];
	unsigned long long R[qtd_vertices];
	bool decide;
	int vertices[qtd_vertices];
	int l;


	c = 0ULL;
	for(int k = 0; k<qtd_vertices; ++k)
		V[k] = 0ULL;

	while(i<qtd_vertices){

		v =  (qtd_vertices - i)-1;//

		profundidade = 0; //ira comecar a decide NR

		R[0] = V[i] & G(v,0);
		W[0] = 0ULL;
		l = MAX;
		decide = false;
		//?? preciso zerar os W

		/*
		 * DECIDE NAO RECURSIVO DEVE VIR AQUI
		 * */

		while(profundidade >= 0){

			while(R[profundidade]!=0){

				vertices[profundidade] =  __builtin_ffsll(R[profundidade]) -1;//smallest v in R\W
				R[profundidade] &= ~(1ULL<<vertices[profundidade] );
				R[profundidade+1] = W[profundidade]&G(vertices[profundidade],0);

				l--;
				profundidade++;

			}


			if(l>0){
				//flag esta false
				l++;
				profundidade--;
				W[profundidade] |= (1ULL<<vertices[profundidade]);
				W[profundidade+1] = 0ULL;
			}
			else{
				decide = true;
				break;
			}


		}//while(p>=0)

		/*fim de decide
		 * */
		if(decide){

			//	printf("\nTrue para %d\n",v );
			MAX++;
			V[i+1] = V[i] | (1ULL<<v);
			i++;
			c = c | (1ULL<<v);
			cMax = c;

		}
		else{
			V[i+1] = V[i] | (1ULL<<v);
			i++;
			c=0;
		}

	}

	cout<<"\n\nTamanho do Clique Maximo: "<<MAX<<". \n";

}

