#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct contaBancaria_{
    int numeroDaConta;
    char nomeDeTitular[250];
    float saldo;
    char tipoConta[250];
};

struct contaBancaria_ Conta;

struct contaBancaria_ depositar(struct contaBancaria_ conta, float valor){
    conta.saldo += valor;
    printf("Depósito de R$%.2f realizado\n",valor);
    return conta;
}

struct contaBancaria_ sacar(struct contaBancaria_ conta, float valor){
    if (conta.saldo >= valor){
        conta.saldo -= valor;
        printf("Saque de R$%.2f realizado\n",valor);
    } else {
        printf("Saldo insuficiente para o saque.\n");
    }
    return conta;
}

void saldo(struct contaBancaria_ conta){
    printf("Saldo atual: R$%.2f\n",conta.saldo);
}

void menu(){
    printf("1 - Depositar\n");
    printf("2 - Sacar\n");
    printf("3 - Imprimir Saldo\n");
    printf("4 - Sair\n");
    printf("Escolha uma opção (1 a 4): ");
}

int main(){
    setlocale(LC_ALL, "portuguese");

    int opcao;
    float valor;

    do{
    printf("\nEscolha o tipo de conta(Poupança ou corrente).\n");
	gets(Conta.tipoConta);
    menu();
    scanf("%d", &opcao);
	switch (opcao){
        case 1:
        printf("Digite o valor para depósito: ");
        scanf("%f", &valor);
        Conta = depositar(Conta, valor);
        break;

            case 2:
            printf("Digite o valor para saque: ");
            scanf("%f", &valor);
            Conta = sacar(Conta, valor);
            break;

            case 3:
            saldo(Conta);
            break;

            default:
            printf("Opção inválida.\n");
        }

    } while (opcao >= 1 && opcao <= 3);

    return 0;
}
