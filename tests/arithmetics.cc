// Matrix comparator tests

#include <gtest/gtest.h>

#include <stdexcept>

#include "matrix.h"
#include "tests.h"

TYPED_TEST(TestsMatrixArithmetic, SumMatrix1x1) {
  mtlc::Matrix<TypeParam> matrix_a = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_1x1_);
  mtlc::Matrix<TypeParam> matrix_b = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_1x1_2_);
  mtlc::Matrix<TypeParam> matrix_res =
      TestsMatrixArithmetic<TypeParam>::FromData(
          TestsMatrixArithmetic<TypeParam>::data_1x1_sum_);

  mtlc::Matrix<TypeParam> matrix_res_func = matrix_a;
  matrix_res_func.SumMatrix(matrix_b);
  mtlc::Matrix<TypeParam> matrix_res_func_r = matrix_b;
  matrix_res_func_r.SumMatrix(matrix_a);

  mtlc::Matrix<TypeParam> matrix_res_operator_eq_plus = matrix_a;
  matrix_res_operator_eq_plus += matrix_b;
  mtlc::Matrix<TypeParam> matrix_res_operator_eq_plus_r = matrix_b;
  matrix_res_operator_eq_plus_r += matrix_a;

  mtlc::Matrix<TypeParam> matrix_res_operator_plus = matrix_a + matrix_b;
  mtlc::Matrix<TypeParam> matrix_res_operator_plus_r = matrix_b + matrix_a;

  ASSERT_EQ(matrix_res_func, matrix_res);
  ASSERT_EQ(matrix_res_operator_eq_plus, matrix_res);
  ASSERT_EQ(matrix_res_operator_eq_plus_r, matrix_res);
  ASSERT_EQ(matrix_res_operator_plus, matrix_res);
  ASSERT_EQ(matrix_res_operator_plus_r, matrix_res);
}

TYPED_TEST(TestsMatrixArithmetic, SumMatrix2x2) {
  mtlc::Matrix<TypeParam> matrix_a = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_2x2_);
  mtlc::Matrix<TypeParam> matrix_b = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_2x2_2_);
  mtlc::Matrix<TypeParam> matrix_res =
      TestsMatrixArithmetic<TypeParam>::FromData(
          TestsMatrixArithmetic<TypeParam>::data_2x2_sum_);

  mtlc::Matrix<TypeParam> matrix_res_func = matrix_a;
  matrix_res_func.SumMatrix(matrix_b);
  mtlc::Matrix<TypeParam> matrix_res_func_r = matrix_b;
  matrix_res_func_r.SumMatrix(matrix_a);

  mtlc::Matrix<TypeParam> matrix_res_operator_eq_plus = matrix_a;
  matrix_res_operator_eq_plus += matrix_b;
  mtlc::Matrix<TypeParam> matrix_res_operator_eq_plus_r = matrix_b;
  matrix_res_operator_eq_plus_r += matrix_a;

  mtlc::Matrix<TypeParam> matrix_res_operator_plus = matrix_a + matrix_b;
  mtlc::Matrix<TypeParam> matrix_res_operator_plus_r = matrix_b + matrix_a;

  ASSERT_EQ(matrix_res_func, matrix_res);
  ASSERT_EQ(matrix_res_operator_eq_plus, matrix_res);
  ASSERT_EQ(matrix_res_operator_eq_plus_r, matrix_res);
  ASSERT_EQ(matrix_res_operator_plus, matrix_res);
  ASSERT_EQ(matrix_res_operator_plus_r, matrix_res);
}

TYPED_TEST(TestsMatrixArithmetic, SumMatrix3x3) {
  mtlc::Matrix<TypeParam> matrix_a = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x3_);
  mtlc::Matrix<TypeParam> matrix_b = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x3_2_);
  mtlc::Matrix<TypeParam> matrix_res =
      TestsMatrixArithmetic<TypeParam>::FromData(
          TestsMatrixArithmetic<TypeParam>::data_3x3_sum_);

  mtlc::Matrix<TypeParam> matrix_res_func = matrix_a;
  matrix_res_func.SumMatrix(matrix_b);
  mtlc::Matrix<TypeParam> matrix_res_func_r = matrix_b;
  matrix_res_func_r.SumMatrix(matrix_a);

  mtlc::Matrix<TypeParam> matrix_res_operator_eq_plus = matrix_a;
  matrix_res_operator_eq_plus += matrix_b;
  mtlc::Matrix<TypeParam> matrix_res_operator_eq_plus_r = matrix_b;
  matrix_res_operator_eq_plus_r += matrix_a;

  mtlc::Matrix<TypeParam> matrix_res_operator_plus = matrix_a + matrix_b;
  mtlc::Matrix<TypeParam> matrix_res_operator_plus_r = matrix_b + matrix_a;

  ASSERT_EQ(matrix_res_func, matrix_res);
  ASSERT_EQ(matrix_res_operator_eq_plus, matrix_res);
  ASSERT_EQ(matrix_res_operator_eq_plus_r, matrix_res);
  ASSERT_EQ(matrix_res_operator_plus, matrix_res);
  ASSERT_EQ(matrix_res_operator_plus_r, matrix_res);
}

TYPED_TEST(TestsMatrixArithmetic, SumMatrix3x2) {
  mtlc::Matrix<TypeParam> matrix_a = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x2_);
  mtlc::Matrix<TypeParam> matrix_b = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x2_2_);
  mtlc::Matrix<TypeParam> matrix_res =
      TestsMatrixArithmetic<TypeParam>::FromData(
          TestsMatrixArithmetic<TypeParam>::data_3x2_sum_);

  mtlc::Matrix<TypeParam> matrix_res_func = matrix_a;
  matrix_res_func.SumMatrix(matrix_b);
  mtlc::Matrix<TypeParam> matrix_res_func_r = matrix_b;
  matrix_res_func_r.SumMatrix(matrix_a);

  mtlc::Matrix<TypeParam> matrix_res_operator_eq_plus = matrix_a;
  matrix_res_operator_eq_plus += matrix_b;
  mtlc::Matrix<TypeParam> matrix_res_operator_eq_plus_r = matrix_b;
  matrix_res_operator_eq_plus_r += matrix_a;

  mtlc::Matrix<TypeParam> matrix_res_operator_plus = matrix_a + matrix_b;
  mtlc::Matrix<TypeParam> matrix_res_operator_plus_r = matrix_b + matrix_a;

  ASSERT_EQ(matrix_res_func, matrix_res);
  ASSERT_EQ(matrix_res_operator_eq_plus, matrix_res);
  ASSERT_EQ(matrix_res_operator_eq_plus_r, matrix_res);
  ASSERT_EQ(matrix_res_operator_plus, matrix_res);
  ASSERT_EQ(matrix_res_operator_plus_r, matrix_res);
}

TYPED_TEST(TestsMatrixArithmetic, SumMatrix2x1) {
  mtlc::Matrix<TypeParam> matrix_a = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_2x1_);
  mtlc::Matrix<TypeParam> matrix_b = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_2x1_2_);
  mtlc::Matrix<TypeParam> matrix_res =
      TestsMatrixArithmetic<TypeParam>::FromData(
          TestsMatrixArithmetic<TypeParam>::data_2x1_sum_);

  mtlc::Matrix<TypeParam> matrix_res_func = matrix_a;
  matrix_res_func.SumMatrix(matrix_b);
  mtlc::Matrix<TypeParam> matrix_res_func_r = matrix_b;
  matrix_res_func_r.SumMatrix(matrix_a);

  mtlc::Matrix<TypeParam> matrix_res_operator_eq_plus = matrix_a;
  matrix_res_operator_eq_plus += matrix_b;
  mtlc::Matrix<TypeParam> matrix_res_operator_eq_plus_r = matrix_b;
  matrix_res_operator_eq_plus_r += matrix_a;

  mtlc::Matrix<TypeParam> matrix_res_operator_plus = matrix_a + matrix_b;
  mtlc::Matrix<TypeParam> matrix_res_operator_plus_r = matrix_b + matrix_a;

  ASSERT_EQ(matrix_res_func, matrix_res);
  ASSERT_EQ(matrix_res_operator_eq_plus, matrix_res);
  ASSERT_EQ(matrix_res_operator_eq_plus_r, matrix_res);
  ASSERT_EQ(matrix_res_operator_plus, matrix_res);
  ASSERT_EQ(matrix_res_operator_plus_r, matrix_res);
}

TYPED_TEST(TestsMatrixArithmetic, SubMatrix1x1) {
  mtlc::Matrix<TypeParam> matrix_a = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_1x1_);
  mtlc::Matrix<TypeParam> matrix_b = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_1x1_2_);
  mtlc::Matrix<TypeParam> matrix_res =
      TestsMatrixArithmetic<TypeParam>::FromData(
          TestsMatrixArithmetic<TypeParam>::data_1x1_sub_);

  mtlc::Matrix<TypeParam> matrix_res_func = matrix_a;
  matrix_res_func.SubMatrix(matrix_b);

  mtlc::Matrix<TypeParam> matrix_res_operator_eq_minus = matrix_a;
  matrix_res_operator_eq_minus -= matrix_b;

  mtlc::Matrix<TypeParam> matrix_res_operator_minus = matrix_a - matrix_b;

  ASSERT_EQ(matrix_res_func, matrix_res);

  ASSERT_EQ(matrix_res_operator_eq_minus, matrix_res);

  ASSERT_EQ(matrix_res_operator_minus, matrix_res);
}

TYPED_TEST(TestsMatrixArithmetic, SubMatrix2x2) {
  mtlc::Matrix<TypeParam> matrix_a = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_2x2_);
  mtlc::Matrix<TypeParam> matrix_b = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_2x2_2_);
  mtlc::Matrix<TypeParam> matrix_res =
      TestsMatrixArithmetic<TypeParam>::FromData(
          TestsMatrixArithmetic<TypeParam>::data_2x2_sub_);

  mtlc::Matrix<TypeParam> matrix_res_func = matrix_a;
  matrix_res_func.SubMatrix(matrix_b);

  mtlc::Matrix<TypeParam> matrix_res_operator_eq_minus = matrix_a;
  matrix_res_operator_eq_minus -= matrix_b;

  mtlc::Matrix<TypeParam> matrix_res_operator_minus = matrix_a - matrix_b;

  ASSERT_EQ(matrix_res_func, matrix_res);
  ASSERT_EQ(matrix_res_operator_eq_minus, matrix_res);

  ASSERT_EQ(matrix_res_operator_minus, matrix_res);
}

TYPED_TEST(TestsMatrixArithmetic, SubMatrix3x3) {
  mtlc::Matrix<TypeParam> matrix_a = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x3_);
  mtlc::Matrix<TypeParam> matrix_b = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x3_2_);
  mtlc::Matrix<TypeParam> matrix_res =
      TestsMatrixArithmetic<TypeParam>::FromData(
          TestsMatrixArithmetic<TypeParam>::data_3x3_sub_);

  mtlc::Matrix<TypeParam> matrix_res_func = matrix_a;
  matrix_res_func.SubMatrix(matrix_b);

  mtlc::Matrix<TypeParam> matrix_res_operator_eq_minus = matrix_a;
  matrix_res_operator_eq_minus -= matrix_b;

  mtlc::Matrix<TypeParam> matrix_res_operator_minus = matrix_a - matrix_b;

  ASSERT_EQ(matrix_res_func, matrix_res);
  ASSERT_EQ(matrix_res_operator_eq_minus, matrix_res);
  ASSERT_EQ(matrix_res_operator_minus, matrix_res);
}

TYPED_TEST(TestsMatrixArithmetic, SubMatrix3x2) {
  mtlc::Matrix<TypeParam> matrix_a = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x2_);
  mtlc::Matrix<TypeParam> matrix_b = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x2_2_);
  mtlc::Matrix<TypeParam> matrix_res =
      TestsMatrixArithmetic<TypeParam>::FromData(
          TestsMatrixArithmetic<TypeParam>::data_3x2_sub_);

  mtlc::Matrix<TypeParam> matrix_res_func = matrix_a;
  matrix_res_func.SubMatrix(matrix_b);

  mtlc::Matrix<TypeParam> matrix_res_operator_eq_minus = matrix_a;
  matrix_res_operator_eq_minus -= matrix_b;

  mtlc::Matrix<TypeParam> matrix_res_operator_minus = matrix_a - matrix_b;

  ASSERT_EQ(matrix_res_func, matrix_res);
  ASSERT_EQ(matrix_res_operator_eq_minus, matrix_res);

  ASSERT_EQ(matrix_res_operator_minus, matrix_res);
}

TYPED_TEST(TestsMatrixArithmetic, SubMatrix2x1) {
  mtlc::Matrix<TypeParam> matrix_a = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_2x1_);
  mtlc::Matrix<TypeParam> matrix_b = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_2x1_2_);
  mtlc::Matrix<TypeParam> matrix_res =
      TestsMatrixArithmetic<TypeParam>::FromData(
          TestsMatrixArithmetic<TypeParam>::data_2x1_sub_);

  mtlc::Matrix<TypeParam> matrix_res_func = matrix_a;
  matrix_res_func.SubMatrix(matrix_b);

  mtlc::Matrix<TypeParam> matrix_res_operator_eq_minus = matrix_a;
  matrix_res_operator_eq_minus -= matrix_b;

  mtlc::Matrix<TypeParam> matrix_res_operator_minus = matrix_a - matrix_b;

  ASSERT_EQ(matrix_res_func, matrix_res);
  ASSERT_EQ(matrix_res_operator_eq_minus, matrix_res);
  ASSERT_EQ(matrix_res_operator_minus, matrix_res);
}

TYPED_TEST(TestsMatrixArithmetic, MulNumber3x2) {
  TypeParam value = TypeParam(3);
  mtlc::Matrix<TypeParam> matrix = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x2_);

  mtlc::Matrix<TypeParam> matrix_res_a = matrix;
  matrix_res_a.MulNumber(value);
  mtlc::Matrix<TypeParam> matrix_res_b = matrix;
  matrix_res_b *= value;

  mtlc::Matrix<TypeParam> matrix_res_operator_a = matrix * value;
  mtlc::Matrix<TypeParam> matrix_res_operator_b = value * matrix;

  ASSERT_EQ(matrix.GetRows(), matrix_res_a.GetRows());
  ASSERT_EQ(matrix.GetCols(), matrix_res_a.GetCols());
  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i != matrix.GetRows();
       ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0;
         j != matrix.GetCols(); ++j) {
      ASSERT_EQ(matrix(i, j) * value, matrix_res_a(i, j));
    }
  }
  ASSERT_EQ(matrix.GetRows(), matrix_res_b.GetRows());
  ASSERT_EQ(matrix.GetCols(), matrix_res_b.GetCols());
  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i != matrix.GetRows();
       ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0;
         j != matrix.GetCols(); ++j) {
      ASSERT_EQ(matrix(i, j) * value, matrix_res_b(i, j));
    }
  }
  ASSERT_EQ(matrix.GetRows(), matrix_res_operator_a.GetRows());
  ASSERT_EQ(matrix.GetCols(), matrix_res_operator_a.GetCols());
  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i != matrix.GetRows();
       ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0;
         j != matrix.GetCols(); ++j) {
      ASSERT_EQ(matrix(i, j) * value, matrix_res_operator_a(i, j));
    }
  }
  ASSERT_EQ(matrix.GetRows(), matrix_res_operator_b.GetRows());
  ASSERT_EQ(matrix.GetCols(), matrix_res_operator_b.GetCols());
  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i != matrix.GetRows();
       ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0;
         j != matrix.GetCols(); ++j) {
      ASSERT_EQ(matrix(i, j) * value, matrix_res_operator_b(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixArithmetic, MulNumber3x3) {
  TypeParam value = TypeParam(-1);
  mtlc::Matrix<TypeParam> matrix = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x3_);

  mtlc::Matrix<TypeParam> matrix_res_a = matrix;
  matrix_res_a.MulNumber(value);
  mtlc::Matrix<TypeParam> matrix_res_b = matrix;
  matrix_res_b *= value;

  mtlc::Matrix<TypeParam> matrix_res_operator_a = matrix * value;
  mtlc::Matrix<TypeParam> matrix_res_operator_b = value * matrix;

  ASSERT_EQ(matrix.GetRows(), matrix_res_a.GetRows());
  ASSERT_EQ(matrix.GetCols(), matrix_res_a.GetCols());
  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i != matrix.GetRows();
       ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0;
         j != matrix.GetCols(); ++j) {
      ASSERT_EQ(matrix(i, j) * value, matrix_res_a(i, j));
    }
  }
  ASSERT_EQ(matrix.GetRows(), matrix_res_b.GetRows());
  ASSERT_EQ(matrix.GetCols(), matrix_res_b.GetCols());
  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i != matrix.GetRows();
       ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0;
         j != matrix.GetCols(); ++j) {
      ASSERT_EQ(matrix(i, j) * value, matrix_res_b(i, j));
    }
  }
  ASSERT_EQ(matrix.GetRows(), matrix_res_operator_a.GetRows());
  ASSERT_EQ(matrix.GetCols(), matrix_res_operator_a.GetCols());
  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i != matrix.GetRows();
       ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0;
         j != matrix.GetCols(); ++j) {
      ASSERT_EQ(matrix(i, j) * value, matrix_res_operator_a(i, j));
    }
  }
  ASSERT_EQ(matrix.GetRows(), matrix_res_operator_b.GetRows());
  ASSERT_EQ(matrix.GetCols(), matrix_res_operator_b.GetCols());
  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i != matrix.GetRows();
       ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0;
         j != matrix.GetCols(); ++j) {
      ASSERT_EQ(matrix(i, j) * value, matrix_res_operator_b(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixArithmetic, MulMatrix1x1) {
  mtlc::Matrix<TypeParam> matrix_a = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_1x1_);
  mtlc::Matrix<TypeParam> matrix_b = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_1x1_2_);
  mtlc::Matrix<TypeParam> matrix_res =
      TestsMatrixArithmetic<TypeParam>::FromData(
          TestsMatrixArithmetic<TypeParam>::data_1x1_mul_);

  mtlc::Matrix<TypeParam> matrix_res_func = matrix_a;
  matrix_res_func.MulMatrix(matrix_b);

  mtlc::Matrix<TypeParam> matrix_res_operator_eq_mul = matrix_a;
  matrix_res_operator_eq_mul *= matrix_b;

  mtlc::Matrix<TypeParam> matrix_res_operator_mul = matrix_a * matrix_b;

  ASSERT_EQ(matrix_res_func, matrix_res);
  ASSERT_EQ(matrix_res_operator_eq_mul, matrix_res);
  ASSERT_EQ(matrix_res_operator_mul, matrix_res);
}

TYPED_TEST(TestsMatrixArithmetic, MulMatrix2x2) {
  mtlc::Matrix<TypeParam> matrix_a = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_2x2_);
  mtlc::Matrix<TypeParam> matrix_b = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_2x2_2_);
  mtlc::Matrix<TypeParam> matrix_res =
      TestsMatrixArithmetic<TypeParam>::FromData(
          TestsMatrixArithmetic<TypeParam>::data_2x2_mul_);

  mtlc::Matrix<TypeParam> matrix_res_func = matrix_a;
  matrix_res_func.MulMatrix(matrix_b);

  mtlc::Matrix<TypeParam> matrix_res_operator_eq_mul = matrix_a;
  matrix_res_operator_eq_mul *= matrix_b;

  mtlc::Matrix<TypeParam> matrix_res_operator_mul = matrix_a * matrix_b;

  ASSERT_EQ(matrix_res_func, matrix_res);
  ASSERT_EQ(matrix_res_operator_eq_mul, matrix_res);
  ASSERT_EQ(matrix_res_operator_mul, matrix_res);
}

TYPED_TEST(TestsMatrixArithmetic, MulMatrix3x3) {
  mtlc::Matrix<TypeParam> matrix_a = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x3_);
  mtlc::Matrix<TypeParam> matrix_b = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x3_2_);
  mtlc::Matrix<TypeParam> matrix_res =
      TestsMatrixArithmetic<TypeParam>::FromData(
          TestsMatrixArithmetic<TypeParam>::data_3x3_mul_);

  mtlc::Matrix<TypeParam> matrix_res_func = matrix_a;
  matrix_res_func.MulMatrix(matrix_b);

  mtlc::Matrix<TypeParam> matrix_res_operator_eq_mul = matrix_a;
  matrix_res_operator_eq_mul *= matrix_b;

  mtlc::Matrix<TypeParam> matrix_res_operator_mul = matrix_a * matrix_b;

  ASSERT_EQ(matrix_res_func, matrix_res);
  ASSERT_EQ(matrix_res_operator_eq_mul, matrix_res);
  ASSERT_EQ(matrix_res_operator_mul, matrix_res);
}

TYPED_TEST(TestsMatrixArithmetic, MulMatrix3x2To2x1) {
  mtlc::Matrix<TypeParam> matrix_a = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x2_);
  mtlc::Matrix<TypeParam> matrix_b = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_2x1_);
  mtlc::Matrix<TypeParam> matrix_res =
      TestsMatrixArithmetic<TypeParam>::FromData(
          TestsMatrixArithmetic<TypeParam>::data_3x2_2x1_mul_);

  mtlc::Matrix<TypeParam> matrix_res_func = matrix_a;
  matrix_res_func.MulMatrix(matrix_b);

  mtlc::Matrix<TypeParam> matrix_res_operator_eq_mul = matrix_a;
  matrix_res_operator_eq_mul *= matrix_b;

  mtlc::Matrix<TypeParam> matrix_res_operator_mul = matrix_a * matrix_b;

  ASSERT_EQ(matrix_res_func, matrix_res);
  ASSERT_EQ(matrix_res_operator_eq_mul, matrix_res);
  ASSERT_EQ(matrix_res_operator_mul, matrix_res);
}

TYPED_TEST(TestsMatrixArithmetic, SumMatrixExceptionDiffSize) {
  mtlc::Matrix<TypeParam> matrix_a = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x2_);
  mtlc::Matrix<TypeParam> matrix_b = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_2x1_);

  ASSERT_THROW(matrix_a.SumMatrix(matrix_b), std::logic_error);
  ASSERT_THROW(matrix_a + matrix_b, std::logic_error);
  ASSERT_THROW(matrix_a += matrix_b, std::logic_error);
  ASSERT_THROW(matrix_b.SumMatrix(matrix_a), std::logic_error);
  ASSERT_THROW(matrix_b + matrix_a, std::logic_error);
  ASSERT_THROW(matrix_b += matrix_a, std::logic_error);
}

TYPED_TEST(TestsMatrixArithmetic, SubMatrixExceptionDiffSize) {
  mtlc::Matrix<TypeParam> matrix_a = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x2_);
  mtlc::Matrix<TypeParam> matrix_b = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_2x1_);

  ASSERT_THROW(matrix_a.SubMatrix(matrix_b), std::logic_error);
  ASSERT_THROW(matrix_a - matrix_b, std::logic_error);
  ASSERT_THROW(matrix_a -= matrix_b, std::logic_error);
  ASSERT_THROW(matrix_b.SubMatrix(matrix_a), std::logic_error);
  ASSERT_THROW(matrix_b - matrix_a, std::logic_error);
  ASSERT_THROW(matrix_b -= matrix_a, std::logic_error);
}

TYPED_TEST(TestsMatrixArithmetic, MulMatrixExceptionBadSize) {
  mtlc::Matrix<TypeParam> matrix_a = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x2_);
  mtlc::Matrix<TypeParam> matrix_b = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_2x1_);

  ASSERT_THROW(matrix_b.MulMatrix(matrix_a), std::logic_error);
  ASSERT_THROW(matrix_b * matrix_a, std::logic_error);
  ASSERT_THROW(matrix_b *= matrix_a, std::logic_error);
}
