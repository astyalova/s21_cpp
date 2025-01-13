#include "s21_matrix_oop.h"
void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (cols_ != other.cols_ || rows_ != other.rows_) {
    throw std::invalid_argument("Matrices sizes do not match");
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix[i][j] -= other.matrix[i][j];
      }
    }
  }
}