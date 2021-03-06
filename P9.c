//Kátia S R Pereira
//11711ETE023
#include <stdio.h>
#include <stdlib.h>

int tamanho(char str[]){
	int i = 0;
	while(str[i]!='\0')
	i++;
	return i;
	
}
typedef struct Dimensao{
    float larg;
    float alt;
    float profundidade;
}
Dimensao;

typedef struct Produto{
    char name[64];
    float preco;
    Dimensao dimensao;
}Produto;

void cadastra(Produto * p){

    printf("\nDigite o nome do produto: ");
    fgets(p->name, 64, stdin);
    p->name[tamanho(p->name)-1] = '\0';

    printf("\nDigite o preco: ");
    scanf("%f", &(p->preco));
    getchar();

    printf("\nDigite a larg: ");
    scanf("%f", &(p->dimensao.larg));
    getchar();

    printf("\nDigite a profundidade: ");
    scanf("%f", &(p->dimensao.profundidade));
    getchar();

    printf("\nDigite a alt: ");
    scanf("%f", &(p->dimensao.alt));
}

void consulta(Produto * p){
    char c;

    if(tamanho(p->name) == 0){
        printf("\nProduto nao cadastrado!\n");
        while((c=getchar()) != '\n');
        return;
    }

    printf("\n%s, R$ %.2f, L: %.2fm x P: %.2fm x A: %.2fm\n",
    p->name, p->preco,(p->dimensao.larg),(p->dimensao.profundidade), (p->dimensao.alt));
    while((c=getchar())!='\n');
}

int main(){
    int count=0, count1;
    Produto * prod = calloc(2, sizeof(Produto));
    char str[2][16] = {"Cadastro", "Consulta"};

    do{
            system("cls");
       printf("\n1 - Cadastrar\n2 - Consulta\n3 - Sair\n-- ");
        scanf("%d", &count);
        getchar();

        count1 = 0;

        	if(count==1){
        		printf("\nRealizar %s\n", str[count-1]);
         		printf("\n1 - Produto 1\n2 - Produto 2\n3 - Voltar\n-- ");
   	     		scanf("%d", &count1);
   	     		getchar();

   	     		switch(count1){

                        case 1:
                            printf("\nProduto %d\n", count1);
                            cadastra(&prod[count1-1]);
                          	break;

                        case 2:
                            printf("\nProduto %d\n", count1);
                            cadastra(&prod[count1-1]);
                          	break;
                    		}

                    	}

			if(count==2){
        		printf("\nRealizar %s\n", str[count-1]);
         		printf("\n1 - Produto 1\n2 - Produto 2\n3 - Voltar\n-- ");
   	     		scanf("%d", &count1);
   	     		getchar();

   	     		switch(count1){

                        case 1:
                            printf("\nProduto %d\n", count1);
                            consulta(&prod[count1-1]);
                          	break;

                        case 2:
                            printf("\nProduto %d\n", count1);
                            consulta(&prod[count1-1]);
                          	break;
                    		}

						}
	}while(count!=3);

	free(prod);

    return 0;
}
