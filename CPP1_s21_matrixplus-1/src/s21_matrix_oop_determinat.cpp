#include "s21_matrix_oop.h"

double S21Matrix::s21_minor(int delete_row, int delete_col) const {
  S21Matrix m{rows_ - 1, cols_ - 1};
  int mi = 0;
  int mj = 0;
  for (int i = 0; i < rows_; ++i) {
    if (i == delete_row) {
      continue;
    }
    mj = 0;
    for (int j = 0; j < cols_; ++j) {
      if (j == delete_col) {
        continue;
      }
      m.matrix[mi][mj] = matrix[i][j];
      mj++;
    }
    mi++;
  }
  return m.Determinant();
}

double S21Matrix::s21_complement(int delete_row, int delete_col) const {
  if (cols_ == 1 && rows_ == 1) {
    return 1;
  }
  if ((delete_row + delete_col) % 2 == 0) {
    // printf("even compl i=%d, j=%d\n", delete_row, delete_col);
    return s21_minor(delete_row, delete_col);
  }
  // printf("odd compl i=%d, j=%d\n", delete_row, delete_col);
  return -1 * s21_minor(delete_row, delete_col);
}

double S21Matrix::Determinant() const {
  if (rows_ != cols_) {
    throw std::invalid_argument("Incorrect matrix size for Determinant");
  }
  double result = 0;
  if (rows_ == 1) {
    result = matrix[0][0];
    return result;
  }
  result = 0;
  for (int i = 0; i < cols_; ++i) {
    result = result + matrix[0][i] * s21_complement(0, i);
  }
  return result;
}
// //int s21_determinant(matrix_t *A, double *result) {
//   if (check_matrix(A) == UNCORRECT_MATRIX || result == NULL) {
//     return UNCORRECT_MATRIX;
//   }
//   if (A->rows != A->columns) {
//     return CALCULATION_ERROR;
//   }
//   if (A->rows == 1) {
//     *result = A->matrix[0][0];
//     return OK;
//   }
//   *result = 0;
//   for (int i = 0; i < A->columns; ++i) {
//     double compl = 0;
//     s21_complement(A, &compl, 0, i);
//     *result = *result + A->matrix[0][i] * compl ;
//   }
//   return OK;
// }
