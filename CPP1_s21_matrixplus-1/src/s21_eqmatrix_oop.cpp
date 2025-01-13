#include "s21_matrix_oop.h"
bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (rows_ != other.GetRows() || cols_ != other.GetCols()) return false;

  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j)
      if (std::fabs(matrix[i][j] - other(i, j)) > 1e-7) return false;

  return true;
}
