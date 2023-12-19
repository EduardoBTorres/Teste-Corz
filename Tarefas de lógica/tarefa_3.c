#include <stdio.h>

// Função para calcular o total da compra, aplicar descontos
void calcularCompra(float valores[], int qt_compras) {
    float valorTotalCompras = 0;
    float desconto = 0;
    int totalItens = qt_compras;

    // Nessa etapa é calculado o valor total da compra
    int i;
    for (i = 0; i < qt_compras; i++) {
        valorTotalCompras = valorTotalCompras + valores[i];
    }

    // Verifica e aplica os descontos conforme a lógica que foi definida
    if (valorTotalCompras > 100) {
        desconto = desconto + valorTotalCompras * 0.05; // 5% de desconto
    }
    if (valorTotalCompras > 200) {
        desconto = desconto + valorTotalCompras * 0.10; // 10% de desconto adicional
    }

    // Calcula o valor total com os descontos aplicados
    float valorComDesconto = valorTotalCompras - desconto;

    // Resultados apresentados na tela
    printf("Valor total da compra: R$ %.2f\n", valorTotalCompras);
    printf("Valor total com desconto: R$ %.2f\n", valorComDesconto);
    printf("Valor do desconto concedido: R$ %.2f\n", desconto);
    printf("Total de itens comprados: %d\n", totalItens);
}

// Função principal
int main() {
    
    int qt_compras, i;
    float valores[qt_compras];
    
    // Usuário informa quantas compras realizou
    printf("Quantidade de compras: ");
    scanf("%d", &qt_compras);
	    
	// Laço de repetição controlada para ler os valores das compras    
	for(i=0; i<qt_compras; i++){
		printf("Preencha o array com os valores das compras: %d: R$ ", i+1);
		scanf("%f", &valores[i]);
	}
    
    // Chamada da função para realização do cálculo
    calcularCompra(valores, qt_compras);

    return 0;
}

/* Explicação do código:

	Esse código foi dividido em duas partes, foi utilizado uma função específica para calcular 
	os descontos, preços e contagem de compras  que foram realizdas. Optei por esse formato
	utilizando funções, para deixar o código mais limpo e fácil de ser visualizado. 
	
	A lógica por trás desse código é simples, um usuário deverá digitar a quantidade de compras 
	que ele realizou, além disso também fica a cargo dele, informar ao programa os valores 
	de suas compras, com isso a partir dessas informações, a função "calcularCompra(float valores[], int tamanho)" 
	consegue realizar o cálculo correto dos valores totais da compra, valores de descontos, 
	valor sem desconto e total de itens comprados.
	
	Na função as variáveis que recebem os valores das compras são do tipo float, pois o usuário 
	poderá digitar valores com casas decimais, o que é comum quando trabalhamos com preços.
	O número de compras é um inteiro, pois ele serve apenas para informar a quantidade exata de compras 
	realizadas. A lógica realizada em cada etapa do código está acima nos seus comandos respectivos.
*/			
