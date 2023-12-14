#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct contaBancaria{
    int numeroConta;
    char nomeTitular[250];
    float saldo;
    char tipoConta[250];
}; 

struct contaBancaria Conta;

struct contaBancaria depositar(struct contaBancaria conta, float valor){
conta.saldo += valor;
 printf("\n Depósito de %.2f realizado",valor);
    return conta;
}

struct contaBancaria sacar(struct contaBancaria conta, float valor){
 if (conta.saldo >= valor){
 conta.saldo -= valor;
 printf("\n Saque de %.2f realizado",valor);
    } else {
        printf("\n Saldo insuficiente para o saque.");
    }
    return conta;
}

void saldo(struct contaBancaria conta){
printf("\n Saldo atual: %2f",conta.saldo);
}

void exibirMenu(){
printf("\n 1 - Depositar");
printf("\n 2 - Sacar");
printf("\n 3 - Saldo"); 
printf("\n 4 - Sair");
printf("\n Escolha uma opção: ");
}

int main(){
    setlocale(LC_ALL, "portuguese");

    int opcao;
    float valor;

    do{
    exibirMenu();
    scanf("%i",&opcao);
    
	switch(opcao){
        case 1:
        printf("Digite o valor do depósito: ");
        scanf("%f", &valor);
        Conta = depositar(Conta, valor);
        break;

            case 2:
            printf("Digite o valor se for sacar: ");
            scanf("%f", &valor);
            Conta = sacar(Conta, valor);
break;

            case 3:
            saldo(Conta);
            break;
            
            case 4:
            	printf("Opção inválida. Tente novamente\n");
            	break;
            	
            default:
            printf("\n Opção inválida.");
            break;
};

    } while(opcao != 4);

    return 0;
}
