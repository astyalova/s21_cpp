#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(Constructor, 1) {
  S21Matrix m;
  EXPECT_EQ(m.GetRows(), 0);
  EXPECT_EQ(m.GetCols(), 0);
}

TEST(Constructor, 2) {
  S21Matrix m(22, 57);
  EXPECT_EQ(m.GetRows(), 22);
  EXPECT_EQ(m.GetCols(), 57);
}

TEST(Constructor, 3) {
  S21Matrix m(11, 11);
  S21Matrix c(m);
  EXPECT_EQ(m.GetRows(), 11);
  EXPECT_EQ(m.GetCols(), 11);
}

TEST(Constructor, 4) {
  S21Matrix m(22, 57);
  S21Matrix moved(std::move(m));
  EXPECT_EQ(m.GetRows(), 0);
  EXPECT_EQ(m.GetCols(), 0);
  EXPECT_EQ(moved.GetRows(), 22);
  EXPECT_EQ(moved.GetCols(), 57);
}

TEST(Destructor, 5) {
  const S21Matrix m(3, 3);
  ASSERT_EQ(m(0, 0), 0);
}

TEST(test_class, brackets_operator) {
  S21Matrix m(6, 9);
  EXPECT_EQ(m(0, 0), 0);

  m(0, 1) = 69;
  EXPECT_EQ(m(0, 1), 69);

  m(5, 8) = 69.420;
  EXPECT_EQ(m(5, 8), 69.420);
}

TEST(test_class, square_brackets_operator) {
  S21Matrix m(6, 9);
  EXPECT_EQ(m(0, 0), 0);

  m(5, 5) = 69;
  EXPECT_EQ(m(5, 5), 69);

  m(5, 8) = 69.420;
  EXPECT_EQ(m(5, 8), 69.420);
}

TEST(test_setters, set_rows_up) {
  S21Matrix m(2, 2);
  m(1, 1) = 6.9;

  m.SetRows(5);
  EXPECT_EQ(m.GetRows(), 5);
  EXPECT_EQ(m(1, 1), 6.9);
}

TEST(test_setters, set_rows_down) {
  S21Matrix m(2, 2);
  m(0, 0) = 6.9;

  m.SetRows(1);
  EXPECT_EQ(m.GetRows(), 1);
  EXPECT_EQ(m(0, 0), 6.9);
}

TEST(test_setters, set_rows_zero) {
  S21Matrix m;

  EXPECT_ANY_THROW(m.SetRows(0));
}

TEST(test_setters, set_cols_up) {
  S21Matrix m(2, 2);
  m(1, 1) = 6.9;

  m.SetCols(5);
  EXPECT_EQ(m.GetCols(), 5);
  EXPECT_EQ(m(1, 1), 6.9);
}

TEST(test_setters, set_cols_down) {
  S21Matrix m(2, 2);
  m(0, 0) = 6.9;

  m.SetCols(1);
  EXPECT_EQ(m.GetCols(), 1);
  EXPECT_EQ(m(0, 0), 6.9);
}

TEST(test_setters, set_cols_zero) {
  S21Matrix m;

  EXPECT_ANY_THROW(m.SetCols(0));
}

TEST(test_overload, equal_lvalue) {
    S21Matrix m;
    S21Matrix x(3, 6);
    x(1, 2) = 3;
    x(2, 2) = 3;

    m = x;

    EXPECT_EQ(m.GetRows(), 3);
    EXPECT_EQ(m.GetCols(), 6);
    EXPECT_EQ(m(1, 2), 3);
    EXPECT_EQ(m(2, 2), 3);
}

TEST(test_overload, equal_rvalue) {
    S21Matrix m(2, 2);
    S21Matrix n;

    n = std::move(m);

    EXPECT_EQ(n.GetRows(), 2);
    EXPECT_EQ(n.GetCols(), 2);
}

TEST(test_functional, eq_matrix) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  ASSERT_TRUE(m == n);
}

TEST(test_functional, eq_matrix1) {
  S21Matrix m(3, 2);
  S21Matrix n(3, 2);

  ASSERT_TRUE(m == n);
}

TEST(test_functional, sum_matrix) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  m(0, 0) = 1;
  n(0, 0) = 1;

  m(1, 1) = 1;
  n(1, 1) = 1;

  m.SumMatrix(n);

  EXPECT_EQ(m(0, 0), 2);
  EXPECT_EQ(m(1, 1), 2);
}

TEST(test_functional, add_operator_overload) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  m(0, 0) = 1;
  n(0, 0) = 1;

  m(1, 1) = 1;
  n(1, 1) = 1;

  m = m + n;

  EXPECT_EQ(m(0, 0), 2);
  EXPECT_EQ(m(1, 1), 2);
}

TEST(test_functional, eqadd_operator_overload) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  m(0, 0) = 1;
  n(0, 0) = 1;

  m(1, 1) = 1;
  n(1, 1) = 1;

  m += m + n;

  EXPECT_EQ(m(0, 0), 3);
  EXPECT_EQ(m(1, 1), 3);
}

TEST(test_functional, sub_matrix) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  m(0, 0) = 1;
  n(0, 0) = 1;

  m(1, 1) = 1;
  n(1, 1) = 1;

  m.SubMatrix(n);

  EXPECT_EQ(m(0, 0), 0);
  EXPECT_EQ(m(1, 1), 0);
}

TEST(test_functional, eqsub_overloaded_operator) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  m(0, 0) = 1;
  n(0, 0) = 1;

  m(1, 1) = 1;
  n(1, 1) = 1;

  m -= n;

  EXPECT_EQ(m(0, 0), 0);
  EXPECT_EQ(m(1, 1), 0);
}

TEST(test_functional, sub_operator_overload) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  m(0, 0) = 1;
  n(0, 0) = 1;

  m(1, 1) = 1;
  n(1, 1) = 1;

  m = m - n;

  EXPECT_EQ(m(0, 0), 0);
  EXPECT_EQ(m(1, 1), 0);
}

void PrintMatrix(const S21Matrix& matrix) {
  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      std::cout << matrix(i, j) << " ";
    }
    std::cout << std::endl;
  }
}

TEST(test_functional, mul_matrices) {
  const int rows = 2;
  const int cols = 3;

  S21Matrix m(rows, cols);
  S21Matrix n(cols, rows);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m(i, j) = c++;

  for (int i = 0, c = 7; i < cols; i++)
    for (int j = 0; j < rows; j++) n(i, j) = c++;

  m.MulMatrix(n);

  S21Matrix res(2, 2);
  res(0, 0) = 58;
  res(0, 1) = 64;
  res(1, 0) = 139;
  res(1, 1) = 154;

  ASSERT_TRUE(m.EqMatrix(res));
}

TEST(test_functional, eqmul_operator) {
  int rows1 = 2;
  int cols1 = 3;
  int rows2 = 3;
  int cols2 = 2;

  S21Matrix m(rows1, cols1);
  S21Matrix n(rows2, cols2);

  for (int i = 0, c = 1; i < rows1; i++)
    for (int j = 0; j < cols1; j++) m(i, j) = c++;

  for (int i = 0, c = 7; i < rows2; i++)
    for (int j = 0; j < cols2; j++) n(i, j) = c++;
  m *= n;
  S21Matrix res(2, 2);
  res(0, 0) = 58;
  res(0, 1) = 64;
  res(1, 0) = 139;
  res(1, 1) = 154;

  ASSERT_TRUE(m.EqMatrix(res));
}

TEST(test_functional, eqmul_operator_num) {
  const int rows = 2;
  const int cols = 3;

  S21Matrix m(rows, cols);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m(i, j) = c++;

  m.MulNumber(2);

  S21Matrix res(2, 3);
  res(0, 0) = 2;
  res(0, 1) = 4;
  res(0, 2) = 6;
  res(1, 0) = 8;
  res(1, 1) = 10;
  res(1, 2) = 12;

  ASSERT_TRUE(m.EqMatrix(res));
}

TEST(test_functional, mul_operator) {
  const int rows = 2;
  const int cols = 3;

  S21Matrix m(rows, cols);
  S21Matrix n(cols, rows);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m(i, j) = c++;

  for (int i = 0, c = 7; i < cols; i++)
    for (int j = 0; j < rows; j++) n(i, j) = c++;

  m = m * n;

  S21Matrix res(2, 2);
  res(0, 0) = 58;
  res(0, 1) = 64;
  res(1, 0) = 139;
  res(1, 1) = 154;

  ASSERT_TRUE(m == res);
}

TEST(test_functional, mul_operator_num) {
  const int rows = 2;
  const int cols = 3;

  S21Matrix m(rows, cols);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m(i, j) = c++;

  m.MulNumber(2);

  S21Matrix res(2, 3);
  res(0, 0) = 2;
  res(0, 1) = 4;
  res(0, 2) = 6;
  res(1, 0) = 8;
  res(1, 1) = 10;
  res(1, 2) = 12;
  ASSERT_TRUE(m == res);
}

TEST(test_functional, transpose) {
  const int rows = 2;
  const int cols = 3;

  S21Matrix m(rows, cols);
  S21Matrix res(cols, rows);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++, c++) {
      m(i, j) = c;
      res(j, i) = c;
    }

  m = m.Transpose();
  ASSERT_TRUE(m == res);
}

TEST(test_functional, determinant) {
  S21Matrix m(2, 3);

  EXPECT_ANY_THROW(m.Determinant());
}

TEST(test_functional, determinant_zero) {
  const int size = 5;
  S21Matrix m(5, 5);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m(i, j) = j;

  ASSERT_NEAR(0, m.Determinant(), 1e-06);
}

TEST(test_functional, determinant_5x5) {
  int size = 5;
  S21Matrix m(size, size);

  m(0, 1) = 6;
  m(0, 2) = -2;
  m(0, 3) = -1;
  m(0, 4) = 5;
  m(1, 3) = -9;
  m(1, 4) = -7;
  m(2, 1) = 15;
  m(2, 2) = 35;
  m(3, 1) = -1;
  m(3, 2) = -11;
  m(3, 3) = -2;
  m(3, 4) = 1;
  m(4, 0) = -2;
  m(4, 1) = -2;
  m(4, 2) = 3;
  m(4, 4) = -2;

  double res = m.Determinant();
  ASSERT_NEAR(res, 2480, 1e-6);
}

TEST(test_functional, determinant_3x3) {
  const int size = 3;
  S21Matrix m(size, size);

  m(0, 0) = 2;
  m(0, 1) = 3;
  m(0, 2) = 1;
  m(1, 0) = 7;
  m(1, 1) = 4;
  m(1, 2) = 1;
  m(2, 0) = 9;
  m(2, 1) = -2;
  m(2, 2) = 1;

  double res = m.Determinant();
  ASSERT_NEAR(res, -32, 1e-6);
}

TEST(test_functional, determinant_2x2) {
  const int size = 2;
  S21Matrix m(size, size);

  m(0, 0) = -5;
  m(0, 1) = -4;
  m(1, 0) = -2;
  m(1, 1) = -3;

  double res = m.Determinant();
  ASSERT_NEAR(res, 7, 1e-6);
}

TEST(test_functional, complements_3x3) {
  const int rows = 3;
  const int cols = 3;

  S21Matrix given(rows, cols);
  S21Matrix expected(rows, cols);

  expected(0, 0) = 0;
  expected(0, 1) = 10;
  expected(0, 2) = -20;
  expected(1, 0) = 4;
  expected(1, 1) = -14;
  expected(1, 2) = 8;
  expected(2, 0) = -8;
  expected(2, 1) = -2;
  expected(2, 2) = 4;

  given(0, 0) = 1;
  given(0, 1) = 2;
  given(0, 2) = 3;
  given(1, 0) = 0;
  given(1, 1) = 4;
  given(1, 2) = 2;
  given(2, 0) = 5;
  given(2, 1) = 2;
  given(2, 2) = 1;

  S21Matrix res = given.CalcComplements();
  ASSERT_EQ(res, expected);
}

TEST(test_functional, CalcComplements_throw) {
  S21Matrix m(3, 12);
  EXPECT_ANY_THROW(m.CalcComplements());
}

TEST(test_functional, complements_3x3_1) {
  const int rows = 3;
  const int cols = 3;

  S21Matrix given(rows, cols);
  S21Matrix expected(rows, cols);

  given(0, 0) = 1.0;
  given(0, 1) = 2.0;
  given(0, 2) = 3.0;
  given(1, 0) = 0.0;
  given(1, 1) = 4.0;
  given(1, 2) = 2.0;
  given(2, 0) = 5.0;
  given(2, 1) = 2.0;
  given(2, 2) = 1.0;

  expected(0, 0) = 0.0;
  expected(0, 1) = 10.0;
  expected(0, 2) = -20.0;
  expected(1, 0) = 4.0;
  expected(1, 1) = -14.0;
  expected(1, 2) = 8.0;
  expected(2, 0) = -8.0;
  expected(2, 1) = -2.0;
  expected(2, 2) = 4.0;

  S21Matrix res = given.CalcComplements();

  ASSERT_TRUE(res == expected);
}

TEST(test_class, zero_size) { EXPECT_ANY_THROW(S21Matrix(0, 1)); }

TEST(test_functional, complements_3x3_2) {
  const int rows = 3;
  const int cols = 3;

  S21Matrix given(rows, cols);
  S21Matrix expected(rows, cols);

  given(0, 0) = 1;
  given(0, 1) = 2;
  given(0, 2) = 3;
  given(1, 1) = 4;
  given(1, 2) = 2;
  given(2, 0) = 5;
  given(2, 1) = 2;
  given(2, 2) = 1;

  // posm
  expected(0, 0) = 0;
  expected(0, 1) = 10;
  expected(0, 2) = -20;
  expected(1, 0) = 4;
  expected(1, 1) = -14;
  expected(1, 2) = 8;
  expected(2, 0) = -8;
  expected(2, 1) = -2;
  expected(2, 2) = 4;

  S21Matrix res = given.CalcComplements();
  ASSERT_TRUE(res == expected);
}

TEST(test_functional, inverese_3x3) {
  const int size = 3;
  S21Matrix given(size, size);
  S21Matrix expected(size, size);

  expected(0, 0) = 44300.0 / 367429.0;
  expected(0, 1) = -236300.0 / 367429.0;
  expected(0, 2) = 200360.0 / 367429.0;
  expected(1, 0) = 20600.0 / 367429.0;
  expected(1, 1) = 56000.0 / 367429.0;
  expected(1, 2) = -156483.0 / 367429.0;
  expected(2, 0) = 30900.0 / 367429.0;
  expected(2, 1) = 84000.0 / 367429.0;
  expected(2, 2) = -51010.0 / 367429.0;

  given(0, 0) = 2.8;
  given(0, 1) = 1.3;
  given(0, 2) = 7.01;
  given(1, 0) = -1.03;
  given(1, 1) = -2.3;
  given(1, 2) = 3.01;
  given(2, 0) = 0;
  given(2, 1) = -3;
  given(2, 2) = 2;

  ASSERT_TRUE(given.InverseMatrix() == expected);
}

TEST(test_functional, inverese_3x3_1) {
  const int size = 3;
  S21Matrix given(size, size);
  S21Matrix expected(size, size);
  expected(0, 0) = 1.0;
  expected(0, 1) = -1.0;
  expected(0, 2) = 1.0;
  expected(1, 0) = -38.0;
  expected(1, 1) = 41.0;
  expected(1, 2) = -34.0;
  expected(2, 0) = 27.0;
  expected(2, 1) = -29.0;
  expected(2, 2) = 24.0;

  given(0, 0) = 2.0;
  given(0, 1) = 5.0;
  given(0, 2) = 7.0;
  given(1, 0) = 6.0;
  given(1, 1) = 3.0;
  given(1, 2) = 4.0;
  given(2, 0) = 5.0;
  given(2, 1) = -2.0;
  given(2, 2) = -3.0;

  ASSERT_TRUE(given.InverseMatrix() == expected);
}

TEST(test_functional, inverse_throw) {
  S21Matrix m(2, 3);
  EXPECT_ANY_THROW(m.InverseMatrix());

  S21Matrix n(2, 2);
  EXPECT_ANY_THROW(n.InverseMatrix());
}

TEST(test_functional, inverse_1x1) {
  S21Matrix m(1, 1);
  m(0, 0) = 69.420;
  double expected = 1 / m(0, 0);
  double result = m.InverseMatrix()(0, 0);
  ASSERT_NEAR(expected, result, 1e-06);
}

TEST(test_functional, inverese_3x3_2) {
  const int size = 3;
  S21Matrix given(size, size);
  S21Matrix expected(size, size);

  given(0, 0) = 2;
  given(0, 1) = 5;
  given(0, 2) = 7;
  given(1, 0) = 6;
  given(1, 1) = 3;
  given(1, 2) = 4;
  given(2, 0) = 5;
  given(2, 1) = -2;
  given(2, 2) = -3;

  expected(0, 0) = 1;
  expected(0, 1) = -1;
  expected(0, 2) = 1;
  expected(1, 0) = -38;
  expected(1, 1) = 41;
  expected(1, 2) = -34;
  expected(2, 0) = 27;
  expected(2, 1) = -29;
  expected(2, 2) = 24;
  ASSERT_TRUE(given.InverseMatrix() == expected);
}

TEST(test_functional, inverese_3x3_3) {
  const int size = 3;
  S21Matrix given(size, size);
  S21Matrix expected(size, size);

  given(0, 0) = 2;
  given(0, 1) = 5;
  given(0, 2) = 7;
  given(1, 0) = 6;
  given(1, 1) = 3;
  given(1, 2) = 4;
  given(2, 0) = 5;
  given(2, 1) = -2;
  given(2, 2) = -3;

  expected(0, 0) = 1;
  expected(0, 1) = -1;
  expected(0, 2) = 1;
  expected(1, 0) = -38;
  expected(1, 1) = 41;
  expected(1, 2) = -34;
  expected(2, 0) = 27;
  expected(2, 1) = -29;
  expected(2, 2) = 24;
  ASSERT_TRUE(given.InverseMatrix() == expected);
}
