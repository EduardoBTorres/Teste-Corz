#include <stdio.h>

// Fun��o para calcular o total da compra, aplicar descontos
void calcularCompra(float valores[], int qt_compras) {
    float valorTotalCompras = 0;
    float desconto = 0;
    int totalItens = qt_compras;

    // Nessa etapa � calculado o valor total da compra
    int i;
    for (i = 0; i < qt_compras; i++) {
        valorTotalCompras = valorTotalCompras + valores[i];
    }

    // Verifica e aplica os descontos conforme a l�gica que foi definida
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

// Fun��o principal
int main() {
    
    int qt_compras, i;
    float valores[qt_compras];
    
    // Usu�rio informa quantas compras realizou
    printf("Quantidade de compras: ");
    scanf("%d", &qt_compras);
	    
	// La�o de repeti��o controlada para ler os valores das compras    
	for(i=0; i<qt_compras; i++){
		printf("Preencha o array com os valores das compras: %d: R$ ", i+1);
		scanf("%f", &valores[i]);
	}
    
    // Chamada da fun��o para realiza��o do c�lculo
    calcularCompra(valores, qt_compras);

    return 0;
}

/* Explica��o do c�digo:

	Esse c�digo foi dividido em duas partes, foi utilizado uma fun��o espec�fica para calcular 
	os descontos, pre�os e contagem de compras  que foram realizdas. Optei por esse formato
	utilizando fun��es, para deixar o c�digo mais limpo e f�cil de ser visualizado. 
	
	A l�gica por tr�s desse c�digo � simples, um usu�rio dever� digitar a quantidade de compras 
	que ele realizou, al�m disso tamb�m fica a cargo dele, informar ao programa os valores 
	de suas compras, com isso a partir dessas informa��es, a fun��o "calcularCompra(float valores[], int tamanho)" 
	consegue realizar o c�lculo correto dos valores totais da compra, valores de descontos, 
	valor sem desconto e total de itens comprados.
	
	Na fun��o as vari�veis que recebem os valores das compras s�o do tipo float, pois o usu�rio 
	poder� digitar valores com casas decimais, o que � comum quando trabalhamos com pre�os.
	O n�mero de compras � um inteiro, pois ele serve apenas para informar a quantidade exata de compras 
	realizadas. A l�gica realizada em cada etapa do c�digo est� acima nos seus comandos respectivos.
*/			
