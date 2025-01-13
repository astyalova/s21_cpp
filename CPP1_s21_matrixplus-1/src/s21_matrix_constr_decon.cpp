#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix(nullptr) {}
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::invalid_argument("Incorrect matrix size");
  }
  matrix = new double*[rows];
  for (int i = 0; i < rows; i++) {
    matrix[i] = new double[cols];
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = 0.0;
    }
  }
}
S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  matrix = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix[i] = new double[cols_];
    for (int j = 0; j < cols_; j++) {
      matrix[i][j] = other.matrix[i][j];
    }
  }
}
// иници знач новой матрицы и обнуляю старые значения
S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix(other.matrix) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix = nullptr;
}
S21Matrix::~S21Matrix() {
  delete[] matrix;
  matrix = nullptr;
}
