#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaração inicial de váriaveis e funções para randomizar o número
    int epoch = time(0);
    srand(epoch);
    int numeroAleatorio = rand();
    int numeroSecreto = numeroAleatorio % 100; 
    int tentativaAtual = 1, ganhou = 0, chute;
    double pontuacaoFinal = 1000, pontuacaoPerdida = 0;

    printf("----------------------------------------\n");
    printf("Boas vindas ao jogo da adivinhação em C!\n");
    printf("----------------------------------------\n");

    // Loop infinito para repetir o jogo até o jogador ganhar (break na validação se o jogador ganhou)
    while(1) {

            printf("Tentativa %d\n", tentativaAtual);

            printf("Qual é o seu chute? ");
            scanf("%d", &chute);
            printf("Seu chute foi %d\n", chute);

            // Validação de chute válido
            if (chute < 0) {

                printf("Você não pode chutar números negativos!\n");

                continue;

            }

            // Validação para verificar se o jogador acertou, chutou maior ou menor
            if (chute == numeroSecreto) {

                printf("Parabéns! Você acertou!\n");
                printf("Jogue de novo, você é um bom jogador!\n");

                break;

            } else if (chute > numeroSecreto) {
                
                    printf("Você errou!\n");
                    printf("Seu chute foi maior que o número secreto\n");
                    printf("Mas não desanime, tente denovo!");

            } else {

                    printf("Você errou!\n");
                    printf("Seu chute foi menor que o número secreto\n");
                    printf("Mas não desanime, tente denovo!");

            }

            tentativaAtual++;

            // Validação para contagem da pontuação
            if(chute > numeroSecreto){

                pontuacaoPerdida = abs(chute - numeroSecreto) / 2.0;

            }else{

                pontuacaoPerdida = abs(chute + numeroSecreto) / 2.0;

            }

            pontuacaoFinal = pontuacaoFinal - pontuacaoPerdida;

        }

        printf("Fim de jogo!\n");
        printf("Você acertou em %d tentativas!\n", tentativaAtual);
        printf("Total de Pontos: %.2f", pontuacaoFinal);

}