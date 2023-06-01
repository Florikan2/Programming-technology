#include <iostream>
#include <vector>
using namespace std;

class Matrix {
  private:
    int rows;
    int cols;
    vector<vector<double>> data;
  
  public:
    // Конструктор по умолчанию
    Matrix() {
      rows = 0;
      cols = 0;
    }
  
    // Конструктор, создающий пустую матрицу размера rows x cols 
    Matrix(int rows, int cols) {
      this->rows = rows;
      this->cols = cols;
      data.resize(rows);
      for (int i = 0; i < rows; i++) {
        data[i].resize(cols);
        for (int j = 0; j < cols; j++) {
          data[i][j] = 0;
        }
      }
    }

    // Конструктор, создающий матрицу из двумерного массива 
    Matrix(vector<vector<double>> a) {
      rows = a.size();
      if (rows > 0) {
        cols = a[0].size();
      } else {
        cols = 0;
      }
      data.resize(rows);
      for (int i = 0; i < rows; i++) {
        data[i].resize(cols);
        for (int j = 0; j < cols; j++) {
          data[i][j] = a[i][j];
        }
      }
    }

    // Оператор []
    vector<double>& operator[](int i) {
      return data[i];
    }

    // Константный оператор [] 
    const vector<double>& operator[](int i) const {
      return data[i];
    }

    // Функция возврата количества строк 
    int numRows() const {
      return rows;
    }

    // Функция возврата количества столбцов 
    int numCols() const {
      return cols;
    }

    // Оператор вывода 
    friend ostream& operator<<(ostream& os, const Matrix& m) {
      for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
          os << m[i][j] << " ";
        }
        os << endl;
      }
      return os;
    }

    // Оператор умножения 
    Matrix operator*(const Matrix& other) const {
      Matrix res(rows, other.cols);
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
          for (int k = 0; k < cols; k++) {
            res[i][j] += data[i][k] * other[k][j];
          }
        }
      }
      return res;
    }

    // Оператор деления 
    Matrix operator/(const Matrix& other) const {
      Matrix inv(other.cols, other.rows);
      for (int i = 0; i < other.cols; i++) {
        for (int j = 0; j < other.rows; j++) {
          inv[i][j] = other[j][i];
        }
      }
      return (*this) * inv;
    }

    // Оператор сложения
    Matrix operator+(const Matrix& other) const {
      Matrix res(rows, other.cols);
      if (rows == other.rows && cols == other.cols) {
        for (int i = 0; i < rows; i++) {
          for (int j = 0; j < cols; j++) {
            res[i][j] = data[i][j] + other[i][j];
          }
        }
      }
      return res;
    }

    // Оператор вычитания
    Matrix operator-(const Matrix& other) const {
      Matrix res(rows, other.cols);
      if (rows == other.rows && cols == other.cols) {
        for (int i = 0; i < rows; i++) {
          for (int j = 0; j < cols; j++) {
            res[i][j] = data[i][j] - other[i][j];
          }
        }
      }
      return res;
    }

    // Оператор умножения на число
    Matrix operator*(double num) const {
      Matrix res(rows, cols);
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          res[i][j] = data[i][j] * num;
        }
      }
      return res;
    }

    // Оператор деления на число
    Matrix operator/(double num) const {
      Matrix res(rows, cols);
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          res[i][j] = data[i][j] / num;
        }
      }
      return res;
    }
};

int main() {
  vector<vector<double>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Matrix A(a);
  cout << "Matrix A:\n" << A << endl;

  vector<vector<double>> b = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  Matrix B(b);
  cout << "Matrix B:\n" << B << endl;

  Matrix C = A * B;
  cout << "Matrix C = A * B:\n" << C << endl;

  Matrix D = B / A;
  cout << "Matrix D = B / A:\n" << D << endl;

  Matrix E = A + B;
  cout << "Matrix E = A + B:\n" << E << endl;

  Matrix F = A - B;
  cout << "Matrix F = A - B:\n" << F << endl;

  Matrix G = A * 3;
  cout << "Matrix G = A * 3:\n" << G << endl;

  Matrix H = B / 2;
  cout << "Matrix H = B / 2:\n" << H << endl;

  return 0;
}
