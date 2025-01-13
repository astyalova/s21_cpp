#include "s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() const {
  if (rows_ != cols_) {
    throw std::invalid_argument("Incorrect matrix size for CalcComplements");
  }
  S21Matrix result{rows_, cols_};

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result.matrix[i][j] = s21_complement(i, j);
    }
  }
  return result;
}
