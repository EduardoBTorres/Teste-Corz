#include <stdio.h>

void gerarSequencia(int X); //Declarando a fun��o

int main() {
    int quantidade;

    printf("Digite a quantidade de numeros extras a serem exibidos na sequencia: ");  //Impress�o na tela para facilitar o entendimento do usu�rio
    scanf("%d", &quantidade);  //Insere a quantidade de elementos extras na sequ�ncia

    gerarSequencia(quantidade);  //Chamada da fun��o no main (programa principal)

    return 0;
}

// Fun��o para defini��o da sequ�ncia
void gerarSequencia(int X) {
    int numero = 2;
    int incremento = 2;
    
    printf("Sequencia: ");  //Impress�o na tela para facilitar o entendimento do usu�rio
    
	int i;
    for (i = 0; i < X; i++) {
        printf("%d", numero);  //Impress�o da sequ�ncia atrav�s de um la�o de repeti��o FOR
        if (i != X - 1) {
            printf(", ");  // Separando os elementos da sequ�ncia por v�rgulas
    	}
        incremento += 2;  // Incremento para o pr�ximo n�mero �mpar
        numero += incremento;  // Adiciona o pr�ximo n�mero �mpar � sequ�ncia
    }
    printf("\n");  //Quebra de linha
}

