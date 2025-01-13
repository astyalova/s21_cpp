#include <math.h>

#include <iostream>
#include <stdexcept>

class S21Matrix {
 private:
  int rows_;
  int cols_;
  double** matrix;

 public:
  int GetRows() const noexcept { return rows_; }
  void SetRows(const int& value) {
    if (value <= 0) throw std::invalid_argument("Array size can't be zero");
    rows_ = value;
  }
  int GetCols() const noexcept { return cols_; }
  void SetCols(const int& value) {
    if (value <= 0) throw std::invalid_argument("Array size can't be zero");
    cols_ = value;
  }
  int GetMatrix() { return **matrix; }
  void PrintMatrix(const S21Matrix& matrix) {
    for (int i = 0; i < matrix.GetRows(); ++i) {
      for (int j = 0; j < matrix.GetCols(); ++j) {
        std::cout << matrix(i, j) << " ";
      }
      std::cout << std::endl;
    }
  }
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  S21Matrix GetMinorMatrix(const int skip_row, const int skip_column);
  double Determinant() const;
  double s21_minor(int delete_row, int delete_col) const;
  double s21_complement(int delete_row, int delete_col) const;
  S21Matrix InverseMatrix() const;
  double& operator()(int i, int j) const;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator=(const S21Matrix& other);
  bool operator==(const S21Matrix& other) const;
};