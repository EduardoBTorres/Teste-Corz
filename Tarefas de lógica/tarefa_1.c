#include <stdio.h>

void gerarSequencia(int X); //Declarando a função

int main() {
    int quantidade;

    printf("Digite a quantidade de numeros extras a serem exibidos na sequencia: ");  //Impressão na tela para facilitar o entendimento do usuário
    scanf("%d", &quantidade);  //Insere a quantidade de elementos extras na sequência

    gerarSequencia(quantidade);  //Chamada da função no main (programa principal)

    return 0;
}

// Função para definição da sequência
void gerarSequencia(int X) {
    int numero = 2;
    int incremento = 2;
    
    printf("Sequencia: ");  //Impressão na tela para facilitar o entendimento do usuário
    
	int i;
    for (i = 0; i < X; i++) {
        printf("%d", numero);  //Impressão da sequência através de um laço de repetição FOR
        if (i != X - 1) {
            printf(", ");  // Separando os elementos da sequência por vírgulas
    	}
        incremento += 2;  // Incremento para o próximo número ímpar
        numero += incremento;  // Adiciona o próximo número ímpar à sequência
    }
    printf("\n");  //Quebra de linha
}

