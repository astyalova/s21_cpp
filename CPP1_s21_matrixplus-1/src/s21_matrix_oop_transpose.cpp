#include "s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() const {
  S21Matrix m(cols_, rows_);
  for (int i = 0; i < m.rows_; i++) {
    for (int j = 0; j < m.cols_; j++) {
      m.matrix[i][j] = matrix[j][i];
    }
  }
  return m;
}