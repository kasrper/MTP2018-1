//Kátia S R Pereira
//11711ETE023
#include <stdio.h>
#include <stdlib.h>


float reduce(float * pini, float * pfim, float (*funcao)(float, float))
{
	if(pini==pfim)
	return 1;
	else
	return (*funcao)(*pini, reduce(pini+1, pfim, funcao));

}

void gera_numeros(float * vetor, int t) 
{
    int i;
    float num;
    for(i = 0; i < t;  i++)
      vetor[i] = (float) rand()/(float) RAND_MAX + 0.5f;
            
}

float som(float *inicio_vetor, float *fim_vetor)
{
	float x;
	x = *inicio_vetor;
	 
	

	if(inicio_vetor != fim_vetor)
	{
		return( x + som(inicio_vetor + 1, fim_vetor));
		
    }
	else
	return x;
	
}
float prod(float *inicio_vetor, float *fim_vetor)
{
	float x;
	x = *inicio_vetor;
	 


	if(inicio_vetor != fim_vetor)
	{
		return( x * som(inicio_vetor + 1, fim_vetor));
		
    }
	else
	return x;
	
}

int main ()
{
	srand(123456);
	int op;
	float vetor[100], soma = 0, produto = 0;
	
	
  gera_numeros(vetor, 100); 
	
	

	printf("DIGITE A OPCAO DESEJADA: \n  1 - SOMATORIO\n  2 - PRODUTORIO\n\n");
	
	scanf("%d", &op);
	getchar();
	
	
		if(op == 1){
		   	soma = som(vetor, vetor + 100);
		   	printf("%f\n", soma);
		   }
		if(op == 2){
		    produto = prod(vetor, vetor + 100);
		   	printf("%f\n", produto);
	    }

	
	return 0;
}
