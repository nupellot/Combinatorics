#include <iostream>
#include <vector>
using namespace std;

int main() {
    void PrintSubmatrix(vector<vector<int>>, int, int, int, int);
    void PrintTriangle(vector<vector<int>>);
    void HighlightSubmatrix(vector<vector<int>>, int, int, int, int);

    // Creating the right pascal triangle.
    vector<vector<int>> Triangle;
    // vector<vector<int>> Triangle2(height, vector<int>(width, 0));
    int width = 0;
    int height = 0;
    cout << "Input triangle width and height  (Example: 4 6)" << endl;
    cin >> width >> height;
    for (int i = 0; i < height; i++) {
        Triangle.emplace_back(vector<int>());
        for (int j = 0; j < width; j++) {
            if (j > i) {
                Triangle[i].emplace_back(0);
            }
            else
                if (i == j || j == 0) {
                    Triangle[i].emplace_back(1);
                }
                else {
                    // Defining value as summ of previous values.
                    Triangle[i].emplace_back(Triangle[i - 1][j] + Triangle[i - 1][j - 1]);
                }
        }
    }

    // Printing the Triangle.
    PrintTriangle(Triangle);

    int AmountOfSubmatrixes = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i && j < width; j++) {
            // Choosing left bottom conner
            for (int k = i; k < height; k++) {
                for (int l = 0; l <= j; l++) {
                    HighlightSubmatrix(Triangle, l, k, j, i);
                    AmountOfSubmatrixes++;
                }
            }
        }
    }
    // cout << "Total amount of Submatrixes: " << AmountOfSubmatrixes << endl;
    printf("Total amount of Submatrixes: \033[41m%d\033[0m", AmountOfSubmatrixes);
}


void PrintSubmatrix(vector<vector<int>> Triangle, int LeftDownX, int LeftDownY, int RightUpX, int RightUpY) {
    cout << "  === Submatrix " << LeftDownX << ";" << LeftDownY << " => " << RightUpX << ";" << RightUpY << " ===" << endl;
    for (int i = RightUpY; i <= LeftDownY; i++) {  // Iterating through rows (Y).
        for (int j = LeftDownX; j <= RightUpX; j++) {   // Iterating through columns (X).
            printf("\033[43m%5d\033[0m", Triangle[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

// Hightlights given Submatrix in the Triangle
void HighlightSubmatrix(vector<vector<int>> Triangle, int LeftDownX, int LeftDownY, int RightUpX, int RightUpY) {
    cout << "  === Submatrix " << LeftDownX << ";" << LeftDownY << " => " << RightUpX << ";" << RightUpY << " ===" << endl;
    for (int i = 0; i < Triangle.size(); i++) {  // Iterating through rows (Y).
        for (int j = 0; j < Triangle[i].size(); j++) {   // Iterating through columns (X).
            if (i >= RightUpY && i <= LeftDownY && j >= LeftDownX && j <= RightUpX) {  // Hightligh element if it is included in Submatrix
                printf("\033[43m%4d\033[0m", Triangle[i][j]);
            }
            else {
                printf("%4d", Triangle[i][j]);
            }
        }
        cout << endl;
    }
    cout << endl;
}
// Prints Pascal Right Triangle
void PrintTriangle(vector<vector<int>> Triangle) {
    cout << "     ===== Pascal Right Triangle " << Triangle[0].size() << "x" << Triangle.size() << " =====" << endl;
    for (int i = 0; i < Triangle.size(); i++) {
        for (int j = 0; j < Triangle[i].size(); j++) {
            // cout << Triangle[i][j] << " ";
            printf("\033[0m%4d\033[0m", Triangle[i][j]);
        }
        cout << endl;
    }
}
