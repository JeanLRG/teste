#include <stdio.h>
#include <math.h>

int main() {
    int pesos_a1 = 8, pesos_a2 = 7, pesos_a3 = 6, pesos_a4 = 5;
    int pesos_op1 = 4, pesos_op2 = 3, pesos_op3 = 2;
    int pesos_cont1 = 9, pesos_cont2 = 8, pesos_cont3 = 7, pesos_cont4 = 6;
    int pesos_cont5 = 5, pesos_cont6 = 4, pesos_cont7 = 3, pesos_cont8 = 2;
    int agencia, operacao, conta;
    float valor_inicial, transferencia, saldo_parcial, deposito, saldo_final;
    int soma = 0, dv;

    //Aqui é onde vai aparecer a "parte mais bonitinha" na tela
    printf("---------------------\n");
    printf("||BANCO DO JEAN||\n");
    printf("---------------------\n");
    printf("> Digite o numero da agencia (4 digitos): ");
    scanf("%d", &agencia);
    printf("> Digite o numero de operacao (3 digitos): ");
    scanf("%d", &operacao);
    printf("> Digite o numero da conta sem DV (8 digitos): ");
    scanf("%d", &conta);

    // Cálculo do soma com os pesos da agência
    soma = soma + (agencia / 1000 % 10) * pesos_a1;
    soma = soma + (agencia / 100 % 10) * pesos_a2;
    soma = soma + (agencia / 10 % 10) * pesos_a3;
    soma = soma + (agencia % 10) * pesos_a4;

    // Cálculo do soma com os pesos da operação
    soma = soma + (operacao / 100 % 10) * pesos_op1;
    soma = soma + (operacao / 10 % 10) * pesos_op2;
    soma = soma + (operacao % 10) * pesos_op3;

    // Cálculo do soma com os pesos da conta
    soma = soma + (conta / 10000000 % 10) * pesos_cont1;
    soma = soma + (conta / 1000000 % 10) * pesos_cont2;
    soma = soma + (conta / 100000 % 10) * pesos_cont3;
    soma = soma + (conta / 10000 % 10) * pesos_cont4;
    soma = soma + (conta / 1000 % 10) * pesos_cont5;
    soma = soma + (conta / 100 % 10) * pesos_cont6;
    soma = soma + (conta / 10 % 10) * pesos_cont7;
    soma = soma + (conta % 10) * pesos_cont8;

    // Cálculo do DV
    dv = (soma * 10) % 11;
    dv = dv - (dv == 10) * dv;  // Simplificação da lógica de "if"

    // Mostra a conta com o DV
    printf("< Sua conta (com DV) é: %04d %03d%08d-%d\n", agencia, operacao, conta, dv);

    // Leitura do saldo e das operações financeiras
    printf("> Digite o saldo inicial: R$ ");
    scanf("%f", &valor_inicial);

    printf("> Digite o valor da transferencia realizada: R$ ");
    scanf("%f", &transferencia);

    // Cálculo pra saber o saldo parcial
    saldo_parcial = valor_inicial - (transferencia * 1.05);
    printf("< Saldo parcial da conta: R$ %.2f\n", saldo_parcial);
    printf("> Digite o valor do deposito recebido: R$ ");
    scanf("%f", &deposito);
   
    // Cálculo do saldo final depois que foi inserido o valor do depósito
    saldo_final = saldo_parcial + deposito;
    printf("< Saldo final da conta: R$ %.2f\n", saldo_final);

    printf("* FIM *\n");

}
