#include "s21_matrix_oop.h"

double& S21Matrix::operator()(int i, int j) const { return matrix[i][j]; }

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Matrices sizes do not match");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix[i][j] += other(i, j);
    }
  }
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix m = S21Matrix(*this);
  return m += other;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Mtrices sizes do not match");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix[i][j] -= other(i, j);
    }
  }
  return *this;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix m = S21Matrix(*this);
  return m -= other;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix result(rows_, other.GetCols());
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.GetCols(); ++j) {
      for (int k = 0; k < cols_; ++k) {
        result(i, j) += matrix[i][k] * other(k, j);
      }
    }
  }
  return result;
}

S21Matrix S21Matrix::operator=(const S21Matrix& other) {
  if (this == &other) {
    return *this;  // Проверка на самоприсваивание
  }
  // Освобождение ресурсов текущей матрицы
  for (int i = 0; i < rows_; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
  // Копирование размеров
  rows_ = other.rows_;
  cols_ = other.cols_;
  // Выделение новой памяти под матрицу
  matrix = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix[i] = new double[cols_];
    for (int j = 0; j < cols_; ++j) {
      matrix[i][j] = other.matrix[i][j];
    }
  }
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  if (rows_ != other.GetRows() || cols_ != other.GetCols()) return false;

  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j)
      if (std::fabs(matrix[i][j] - other.matrix[i][j]) > 1e-7) return false;

  return true;
}
