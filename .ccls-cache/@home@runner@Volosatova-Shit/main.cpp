#include <iostream>
#include <vector>
using namespace std;

int main() {
  std::cout << "Hello World!\n";
  void PrintSubmatrix(vector<vector<int>> Triangle, int x1, int y1, int x2, int y2);
  void PrintTriangle(vector<vector<int>> Triangle);

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
      // cout << height << " " << width << endl;
      if (j > i) {
        Triangle[i].emplace_back(0);
      } else
      if (i == j || j == 0) {
        Triangle[i].emplace_back(1);
      } else {
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
          PrintSubmatrix(Triangle, l, k, j, i);
          AmountOfSubmatrixes++;
        }
      }
    }
  }
  cout << "Total amount of Submatrixes: " << AmountOfSubmatrixes << endl;
}


void PrintSubmatrix(vector<vector<int>> Triangle, int x1, int y1, int x2, int y2) {
  cout << "  === Submatrix " << x1 << ";" << y1 << " => " << x2 << ";" << y2 << " ===" << endl;
  for (int i = y2; i <= y1; i++) {
    for (int j = x1; j <= x2; j++) {
      printf("%5d", Triangle[i][j]);
    }
    cout << endl;
  }  
  cout << endl;
}

void PrintTriangle(vector<vector<int>> Triangle) {
  cout << "     ===== Pascal Right Triangle " << Triangle[0].size() << "x" << Triangle.size() << " =====" << endl; 
  for (int i = 0; i < Triangle.size(); i++) {
    for (int j = 0; j < Triangle[i].size(); j++) {
      // cout << Triangle[i][j] << " ";
      printf("%5d", Triangle[i][j]);
    }
    cout << endl;
  }
}
