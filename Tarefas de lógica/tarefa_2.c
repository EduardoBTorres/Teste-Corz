#include <stdio.h>
#include <stdlib.h>

// Função para classificar os elementos do array e gerar as mensagens
char** classificarNumeros(int array[], int tamanho) {
	// Alocação dinâmica de memória
    char** mensagens = (char**)malloc(tamanho * sizeof(char*)); 
    if (mensagens == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(EXIT_FAILURE); //Encerra a execução, caso haja falha na alocação de memória
    }
    
	int i;
	// Laço de repetição controlada,  para percorrer os elementos do array e retornar as mensagens
    for (i = 0; i < tamanho; i++) {
        mensagens[i] = (char*)malloc(20 * sizeof(char)); // Tamanho arbitrário para a mensagem
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

//Função principal do programa
int main() {
	
    int n;
    
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int array[n];

    printf("Digite os elementos do array:\n");
    
    int i;
    
    //Laço de repetição para inserir os elementos no array
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }
	
	//Chamada da função no main
    char** mensagens = classificarNumeros(array, n);

	//Impressão das mensagens
    printf("\nMensagens:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", mensagens[i]);
        free(mensagens[i]);
    }
    free(mensagens); //Libera o espaço na memória

    return 0;
}
