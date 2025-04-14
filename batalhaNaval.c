#include <stdio.h>

// Função para calcular o valor absoluto
int myAbs(int n) {
    return (n < 0) ? -n : n;
}

int main() {
    int y, x;
    
    // Letras do cabeçalho
    char letra[10] = {'A','B','C','D','E','F','G','H','I','J'};
    
    // Tabuleiro 10x10 preenchido com 0
    int tabuleiro[10][10] = {0};
    
    // Navios horizontais e verticais
    int navioHorizLinha = 2, navioHorizColuna = 5, tamanhoHoriz = 3;
    int navioVertLinha = 6, navioVertColuna = 3, tamanhoVert = 3;
    
    // Navios diagonais (tamanho 3)
    int diag1Linha = 0, diag1Coluna = 0; // Diagonal principal (crescente)
    int diag2Linha = 0, diag2Coluna = 9; // Diagonal secundária (decrescente)
    int tamanhoDiag = 3;
    
    // Habilidades - ponto central para cada uma
    int coneLinha = 4, coneColuna = 5;
    int cruzLinha = 7, cruzColuna = 8;
    int octaedroLinha = 5, octaedroColuna = 2;
    
    // Preenche o tabuleiro com os navios:
    // Navio horizontal
    for (x = navioHorizColuna; x < navioHorizColuna + tamanhoHoriz; x++) {
        tabuleiro[navioHorizLinha][x] = 3;
    }
    // Navio vertical
    for (y = navioVertLinha; y < navioVertLinha + tamanhoVert; y++) {
        tabuleiro[y][navioVertColuna] = 3;
    }
    // Diagonal principal
    for (x = 0; x < tamanhoDiag; x++) {
        if (diag1Linha + x < 10 && diag1Coluna + x < 10)
            tabuleiro[diag1Linha + x][diag1Coluna + x] = 3;
    }
    // Diagonal secundária
    for (x = 0; x < tamanhoDiag; x++) {
        if (diag2Linha + x < 10 && diag2Coluna - x >= 0)
            tabuleiro[diag2Linha + x][diag2Coluna - x] = 3;
    }
    
    // Criação das matrizes de área de efeito para as habilidades.
    // As matrizes são 5x5 e usam o valor 1 para indicar células afetadas.
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};
    
    // Matriz CONE:
    // Preenche a matriz de forma que a região afetada seja em formato de cone
    // com a ponta no topo.
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 5; x++) {
            // Para formar o cone, usamos a condição:
            // célula afetada se y >= (x - 2) e y >= (2 - x)
            if (y >= x - 2 && y >= 2 - x) {
                cone[y][x] = 1;
            }
        }
    }
    
    // Matriz CRUZ:
    // Linha central inteira e colunas centrais nas demais linhas.
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 5; x++) {
            if (x == 2 || y == 2) {
                cruz[y][x] = 1;
            }
        }
    }
    
    // Matriz OCTAEDRO (losango):
    // Células cuja soma dos valores absolutos da distância do centro (posição 2,2)
    // é menor ou igual a 2 serão afetadas.
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 5; x++) {
            if (myAbs(2 - y) + myAbs(2 - x) <= 2) {
                octaedro[y][x] = 1;
            }
        }
    }
    
    // Exibição do tabuleiro completo (com navios e áreas de efeito sobrepostas)
    // As áreas de efeito serão aplicadas se a célula estiver dentro do alcance da matriz 5x5.
    // A prioridade é: navios (3) e, se a célula estiver no alcance da habilidade, ela recebe o valor 5.
    printf("Tabuleiro com Navios e Áreas de Efeito:\n");
    printf("  ");
    for (x = 0; x < 10; x++) {
        printf("%c ", letra[x]);
    }
    printf("\n");
    
    for (y = 0; y < 10; y++) {
        printf("%d ", y + 1);
        for (x = 0; x < 10; x++) {
            int valor = tabuleiro[y][x];
            
            // Sobreposição da habilidade CONE
            if (y >= coneLinha - 2 && y <= coneLinha + 2 &&
                x >= coneColuna - 2 && x <= coneColuna + 2) {
                if (cone[y - (coneLinha - 2)][x - (coneColuna - 2)] == 1) {
                    valor = 5;
                }
            }
            // Sobreposição da habilidade CRUZ
            if (y >= cruzLinha - 2 && y <= cruzLinha + 2 &&
                x >= cruzColuna - 2 && x <= cruzColuna + 2) {
                if (cruz[y - (cruzLinha - 2)][x - (cruzColuna - 2)] == 1) {
                    valor = 5;
                }
            }
            // Sobreposição da habilidade OCTAEDRO
            if (y >= octaedroLinha - 2 && y <= octaedroLinha + 2 &&
                x >= octaedroColuna - 2 && x <= octaedroColuna + 2) {
                if (octaedro[y - (octaedroLinha - 2)][x - (octaedroColuna - 2)] == 1) {
                    valor = 5;
                }
            }
            
            printf("%d ", valor);
        }
        printf("\n");
    }
    
    // Impressão separada das áreas de efeito para visualização
    printf("\nÁrea de efeito - Habilidade CONE:\n");
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 5; x++) {
            if (cone[y][x] == 1)
                printf("3 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
    
    printf("\nÁrea de efeito - Habilidade CRUZ:\n");
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 5; x++) {
            if (cruz[y][x] == 1)
                printf("3 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
    
    printf("\nÁrea de efeito - Habilidade OCTAEDRO:\n");
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 5; x++) {
            if (octaedro[y][x] == 1)
                printf("3 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
    
    return 0;
}