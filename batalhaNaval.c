#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define LINHAS 10
#define COLUNAS 10

// Verificar limites do tabuleiro
int VerificarLimites(int linha, int coluna){
    return linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS; 
}

// Criando e preenchendo toda a matriz 10 x 10 com 0s
void PreencherMatriz(int mat[][COLUNAS]){
    for(int i = 0; i < LINHAS; i++){
        for(int j = 0;  j < COLUNAS; j++){
            mat[i][j] = 0;
        }
    }
}

// Criando e preenchendo a matriz em formato da habilidade cone
void PreencherCone(int cone[][5]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if(j >=2 - i && j <= 2 + i){
                cone[i][j] = 5;
            }else{
                cone[i][j] = 0;
            }
        }
    }
}

// Criando e preenchendo a matriz em formato da habilidade cruz
void PreencherCruz(int cruz[][5]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if(i == 1 || j == 2){
                cruz[i][j] = 5;
            }else{
                cruz[i][j] = 0;
            }
        }
    }
}

// Criando e preenchendo a matriz em formato de habilidade octaedro
void PreencherOctaedro(int octaedro[][5]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if(j >= 2 - i && j <= 2 + i && i <= 1){
                octaedro[i][j] = 5;
            }else if(i == 2 && j == 2){
                octaedro[i][j] = 5;
            }else{
                octaedro[i][j] = 0;
            }
        }
    }
}

// Sobrepondo a matriz 10 x 10 (tabuleiro) com as habilidades
void SobreporHabilidades(int mat[][COLUNAS], int habilidades[][5], int linhaInicio, int colunaInicio){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            int linha = linhaInicio + i;
            int coluna = colunaInicio + j;
            if(habilidades[i][j] != 0 && VerificarLimites(linha,coluna)){
                mat[linha][coluna] = habilidades[i][j];
            }
        }
    }
}

// Posicionamento dos navios
void PosicionarNavios(int mat[][COLUNAS], int navio1[], int navio2[], int navio3[], int navio4[]){
    for(int i = 0; i < 3; i++){
        mat[5][3 + i] = navio1[i]; // navio1 horizontal
        mat[7 + i][9] = navio2[i]; // navio2 vertical
        mat[6 + i][7 - i] = navio3[i]; // navio3 diagonal secundária
        mat[1 + i][1 + i] = navio4[i]; // navio4 diagonal principal
    } 
}

// Imprimi a matriz completa adicionando letras as colunas e números as linhas
void ImprimirMatriz(int mat[][COLUNAS]){
    printf("  ");
    for(int j = 0; j < COLUNAS; j++){
        printf(" %3c", 'A' + j);
    }
    printf("\n\n");

    for(int i = 0; i < LINHAS; i++){
        printf("%2d", i + 1);
        for(int j = 0; j < COLUNAS; j++){
            printf("%4d", mat[i][j]);
        }
        printf("\n\n");
    }
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    //Declarando variáveis das matrizes e vetores
    int mat[LINHAS][COLUNAS];
    int cone[3][5];
    int cruz[3][5];
    int octaedro[3][5];
    int navio1[3] = {3,3,3};
    int navio2[3] = {3,3,3};
    int navio3[3] = {3,3,3};
    int navio4[3] = {3,3,3};

    //Imprimindo o título
    printf("         TABULEIRO BATALHA NAVAL     \n\n");

    //Chamando as funções
    PreencherMatriz(mat);
    PosicionarNavios(mat, navio1, navio2, navio3, navio4);

    PreencherCone(cone);
    SobreporHabilidades(mat, cone, 5, 0);

    PreencherCruz(cruz);
    SobreporHabilidades(mat, cruz, 3 , 4);

    PreencherOctaedro(octaedro);
    SobreporHabilidades(mat, octaedro, 0, 1);

    ImprimirMatriz(mat);

    return 0;
}
