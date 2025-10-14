#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Nível Novato: Mapa da Mansão com Árvore Binária

// Estrutura que representa cada sala da mansão
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// Cria dinamicamente uma nova sala
Sala* criarSala(const char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro ao criar sala!\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// Conecta duas salas (pai -> esquerda/direita)
void conectarSalas(Sala *origem, Sala *esquerda, Sala *direita) {
    if (origem != NULL) {
        origem->esquerda = esquerda;
        origem->direita = direita;
    }
}

// Permite que o jogador explore a mansão
void explorarSalas(Sala *atual) {
    char opcao;

    while (atual != NULL) {
        printf("\nVocê está em: %s\n", atual->nome);

        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Fim do caminho! Não há mais salas adiante.\n");
            break;
        }

        printf("Escolha um caminho (e - esquerda, d - direita, s - sair): ");
        scanf(" %c", &opcao);

        if (opcao == 'e' || opcao == 'E') {
            if (atual->esquerda != NULL)
                atual = atual->esquerda;
            else
                printf("Não há sala à esquerda!\n");
        } 
        else if (opcao == 'd' || opcao == 'D') {
            if (atual->direita != NULL)
                atual = atual->direita;
            else
                printf("Não há sala à direita!\n");
        } 
        else if (opcao == 's' || opcao == 'S') {
            printf("Você decidiu encerrar a exploração.\n");
            break;
        } 
        else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}

int main() {

    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária

    // Criação das salas principais
    Sala *hall = criarSala("Hall de Entrada");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *cozinha = criarSala("Cozinha");
    Sala *salaEstar = criarSala("Sala de Estar");
    Sala *jardim = criarSala("Jardim");
    Sala *sotao = criarSala("Sótão");

    // Conectando os cômodos (árvore binária fixa)
    conectarSalas(hall, biblioteca, cozinha);
    conectarSalas(biblioteca, salaEstar, jardim);
    conectarSalas(cozinha, sotao, NULL);

    printf("=== Detective Quest ===\n");
    printf("Bem-vindo(a) à Mansão Misteriosa!\n");

    // Inicia a exploração
    explorarSalas(hall);

    // Liberação de memória
    free(hall);
    free(biblioteca);
    free(cozinha);
    free(salaEstar);
    free(jardim);
    free(sotao);

    printf("\nExploração encerrada. Obrigado por jogar!\n");
    return 0;
}
