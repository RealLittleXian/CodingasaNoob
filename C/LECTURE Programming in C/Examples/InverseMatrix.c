#include <stdio.h>

#define N 10

void matrixInverse(float a[N][N], float inv[N][N], int n);
void matrixPrint(float a[N][N], int n);
int matrixDeterminant(float matrix[N][N], int n);

int main() {
    int n;
    printf("Enter the dimension of the matrix: ");
    scanf("%d", &n);

    if (n > N || n <= 0) {
        printf("Invalid matrix dimension.\n");
        return 1;
    }

    float matrix[N][N];
    float inverse[N][N];
    
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    float determinant = matrixDeterminant(matrix,n);

    if (determinant == 0) {
        printf("Matrix is not invertible.\n");
        return 1;
    }

    matrixInverse(matrix, inverse, n);

    printf("Inverse of the matrix:\n");
    matrixPrint(inverse, n);

    return 0;
}

void matrixInverse(float a[N][N], float inv[N][N], int n) {
    float adjoint[N][N];

    // Calculate adjoint of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Calculate cofactor of element a[i][j]
            float cofactor[N - 1][N - 1];
            int cofactorRow = 0, cofactorCol = 0;
            for (int row = 0; row < n; row++) {
                for (int col = 0; col < n; col++) {
                    if (row != i && col != j) {
                        cofactor[cofactorRow][cofactorCol++] = a[row][col];
                        if (cofactorCol == n - 1) {
                            cofactorRow++;
                            cofactorCol = 0;
                        }
                    }
                }
            }

            // Calculate determinant of cofactor matrix
            float cofactorDeterminant = 0;
            if (n == 2) {
                cofactorDeterminant = cofactor[0][0] * cofactor[1][1] - cofactor[0][1] * cofactor[1][0];
            } else {
                // Recursive call if matrix size is larger than 2x2
                matrixInverse(cofactor, adjoint, n - 1);
                cofactorDeterminant = 0;
                for (int k = 0; k < n - 1; k++) {
                    cofactorDeterminant += a[i][k] * adjoint[k][j];
                }
            }

            // Calculate cofactor of element a[i][j]
            float sign = ((i + j) % 2 == 0) ? 1 : -1;
            adjoint[j][i] = sign * cofactorDeterminant;
        }
    }

    // Calculate determinant of the matrix
    float determinant = 0;
    for (int i = 0; i < n; i++) {
        determinant += (a[0][i] * adjoint[i][0]);
    }

    // Calculate inverse of the matrix by dividing adjoint by determinant
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inv[i][j] = adjoint[i][j] / determinant;
        }
    }
}

int matrixDeterminant(float matrix[N][N], int n) {
    int det = 0;
    int submatrix[N][N];
    
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x) {
                        continue;
                    }
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * matrixDeterminant(submatrix, n - 1);
        }
    }
    
    return det;
}

void matrixPrint(float a[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }
}
