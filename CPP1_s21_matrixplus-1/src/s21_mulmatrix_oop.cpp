#include "s21_matrix_oop.h"
void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.GetRows()) {
    throw std::invalid_argument(
        "The columns of the first matrix are equal to the rows of the second");
  } else {
    S21Matrix result(rows_, other.GetCols());
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < other.GetCols(); j++) {
        result(i, j) = 0;  // Инициализация элемента перед суммированием
        for (int k = 0; k < cols_; k++) {
          result(i, j) += matrix[i][k] * other.matrix[k][j];
        }
      }
    }
    *this = result;
  }
}