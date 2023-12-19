#include <stdio.h>
#include <stdlib.h>

// Fun��o para classificar os elementos do array e gerar as mensagens
char** classificarNumeros(int array[], int tamanho) {
	// Aloca��o din�mica de mem�ria
    char** mensagens = (char**)malloc(tamanho * sizeof(char*)); 
    if (mensagens == NULL) {
        printf("Erro de aloca��o de mem�ria!\n");
        exit(EXIT_FAILURE); //Encerra a execu��o, caso haja falha na aloca��o de mem�ria
    }
    
	int i;
	// La�o de repeti��o controlada,  para percorrer os elementos do array e retornar as mensagens
    for (i = 0; i < tamanho; i++) {
        mensagens[i] = (char*)malloc(20 * sizeof(char)); // Tamanho arbitr�rio para a mensagem
        if (array[i] > 0) {
            sprintf(mensagens[i], "O numero %d e Positivo", array[i]);
        } else if (array[i] < 0) {
            sprintf(mensagens[i], "O numero %d e Negativo", array[i]);
        } else {
            sprintf(mensagens[i], "O numero %d e Zero", array[i]);
        }
    }

    return mensagens;
}

//Fun��o principal do programa
int main() {
	
    int n;
    
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int array[n];

    printf("Digite os elementos do array:\n");
    
    int i;
    
    //La�o de repeti��o para inserir os elementos no array
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }
	
	//Chamada da fun��o no main
    char** mensagens = classificarNumeros(array, n);

	//Impress�o das mensagens
    printf("\nMensagens:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", mensagens[i]);
        free(mensagens[i]);
    }
    free(mensagens); //Libera o espa�o na mem�ria

    return 0;
}
