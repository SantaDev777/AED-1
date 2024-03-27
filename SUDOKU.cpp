#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Função para verificar se uma linha, coluna ou região contém todos os números de 1 a 9
bool isValid(int arr[]) {
    bool visited[SIZE] = {false};

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < 1 || arr[i] > 9 || visited[arr[i] - 1])
            return false;
        visited[arr[i] - 1] = true;
    }

    return true;
}

// Função para verificar se a matriz é uma solução válida para o Sudoku
bool isValidSudoku(int grid[][SIZE]) {
    // Verifica cada linha
    for (int i = 0; i < SIZE; i++)
        if (!isValid(grid[i]))
            return false;

    // Verifica cada coluna
    for (int j = 0; j < SIZE; j++) {
        int col[SIZE];
        for (int i = 0; i < SIZE; i++)
            col[i] = grid[i][j];
        if (!isValid(col))
            return false;
    }

    // Verifica cada região 3x3
    for (int blockRow = 0; blockRow < SIZE; blockRow += 3) {
        for (int blockCol = 0; blockCol < SIZE; blockCol += 3) {
            int block[SIZE];
            int k = 0;
            for (int i = blockRow; i < blockRow + 3; i++) {
                for (int j = blockCol; j < blockCol + 3; j++) {
                    block[k++] = grid[i][j];
                }
            }
            if (!isValid(block))
                return false;
        }
    }

    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int instance = 1; instance <= n; instance++) {
        int grid[SIZE][SIZE];

        // Leitura da matriz
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                scanf("%d", &grid[i][j]);
            }
        }

        // Verificação e impressão do resultado
        printf("Instancia %d\n", instance);
        if (isValidSudoku(grid))
            printf("SIM\n");
        else
            printf("NAO\n");
        printf("\n");
    }

    return 0;
}

