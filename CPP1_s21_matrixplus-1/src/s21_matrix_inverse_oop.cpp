#include "s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() const {
  if (rows_ != cols_) {
    throw std::invalid_argument("Incorrect matrix size for CalcComplements");
  }
  double det = Determinant();
  if (fabs(det) < 1e-7) {
    throw std::invalid_argument(
        "Incorrect matrix size for CalcComplements");  // если у матрицы нулевой
                                                       // определитель то нельзя
                                                       // найти обратную ей
  }
  if (rows_ == 1) {
    S21Matrix m(1, 1);
    m.matrix[0][0] = (double)1 / matrix[0][0];
    return m;
  }
  S21Matrix m = Transpose();
  S21Matrix adjugate = m.CalcComplements();
  adjugate.MulNumber((double)1 / det);
  return adjugate;
}
