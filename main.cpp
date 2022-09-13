#include <stdio.h>
#include <stdlib.h>

// Перечислить все подматрицы, которые можно выбрать из начального фрагмента прямоугольного треугольника Паскаля 

int main() {
    void PrintTriangle(int** Triangle, int width, int height);
	void CreatePascalTriangle(int** Triangle, int width, int height);
	void PrintEverySubmatrix(int** Triangle, int width, int height);
	
	// Creating the Triangle.
    int width = 0;
    int height = 0;
	printf("Input triangle width and height  (Example: 4 6)\n");
    scanf("%d %d", &width, &height);
	int** Triangle = (int**)calloc(height, sizeof(int*));
	CreatePascalTriangle(Triangle, width, height);

    // Printing the Triangle.
    PrintTriangle(Triangle, width, height);

	// Printing all the possible submatrices.
	PrintEverySubmatrix(Triangle, width, height);
}



void PrintEverySubmatrix(int** Triangle, int width, int height) {
    void PrintSubmatrix(int** Triangle, int width, int height, int LeftDownX, int LeftDownY, int RightUpX, int RightUpY);
	void HighlightSubmatrix(int** Triangle, int width, int height, int LeftDownX, int LeftDownY, int RightUpX, int RightUpY);
    int AmountOfSubmatrixes = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i && j < width; j++) {
            // Choosing left bottom conner
            for (int k = i; k < height; k++) {
                for (int l = 0; l <= j; l++) {
                    HighlightSubmatrix(Triangle, width, height, l, k, j, i);
                    AmountOfSubmatrixes++;
                }
            }
        }
    }

    printf("Total amount of Submatrixes: \033[41m%d\033[0m", AmountOfSubmatrixes);
}
	
void CreatePascalTriangle(int** Triangle, int width, int height) {
    for (int i = 0; i < height; i++) {
        Triangle[i] = (int*)calloc(width, sizeof(int));
        for (int j = 0; j < width; j++) {
            if (j > i) {
                Triangle[i][j] = 0;
            } else if (i == j || j == 0) {
				Triangle[i][j] = 1;
			} else {
				// Defining value as summ of previous values.
				Triangle[i][j] = Triangle[i - 1][j] + Triangle[i - 1][j - 1];
			}
        }
    }
}

void PrintSubmatrix(int** Triangle, int width, int height, int LeftDownX, int LeftDownY, int RightUpX, int RightUpY) {
	printf("=== Submatrix %d;%d => %d;%d ===\n", LeftDownX, LeftDownY, RightUpX, RightUpY);
    for (int i = RightUpY; i <= LeftDownY; i++) {  // Iterating through rows (Y).
        for (int j = LeftDownX; j <= RightUpX; j++) {   // Iterating through columns (X).
            printf("\033[43m%5d\033[0m", Triangle[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Hightlights given Submatrix in the Triangle
void HighlightSubmatrix(int** Triangle, int width, int height, int LeftDownX, int LeftDownY, int RightUpX, int RightUpY) {
	printf("=== Submatrix %d;%d => %d;%d ===\n", LeftDownX, LeftDownY, RightUpX, RightUpY);
    for (int i = 0; i < height; i++) {  // Iterating through rows (Y).
        for (int j = 0; j < width; j++) {   // Iterating through columns (X).
            if (i >= RightUpY && i <= LeftDownY && j >= LeftDownX && j <= RightUpX) {  // Hightligh element if it is included in Submatrix
                printf("\033[44m%4d\033[0m", Triangle[i][j]);
            }
            else {
                printf("%4d", Triangle[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}
		
// Prints Pascal Right Triangle
void PrintTriangle(int** Triangle, int width, int height) {
	printf("  ===== Pascal Right Triangle %dx%d\n", width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("\033[0m%4d\033[0m", Triangle[i][j]);
        }
        printf("\n");
    }
	printf("\n");
}
