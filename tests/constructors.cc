// Matrix constructors tests

#include <gtest/gtest.h>

#include <utility>

#include "matrix.h"
#include "tests.h"

TYPED_TEST(TestsMatrixConstructor, ConstructorDefault) {
  typename mtlc::Matrix<TypeParam>::size_type exp_rows = 0;
  typename mtlc::Matrix<TypeParam>::size_type exp_cols = 0;

  mtlc::Matrix<TypeParam> matrix;

  typename mtlc::Matrix<TypeParam>::size_type res_rows = matrix.GetRows();
  typename mtlc::Matrix<TypeParam>::size_type res_cols = matrix.GetCols();

  ASSERT_EQ(exp_rows, res_rows);
  ASSERT_EQ(exp_cols, res_cols);
}

TYPED_TEST(TestsMatrixConstructor, ConstructorSize) {
  typename mtlc::Matrix<TypeParam>::size_type exp_rows = 2;
  typename mtlc::Matrix<TypeParam>::size_type exp_cols = 3;
  TypeParam exp_value = TypeParam(0);

  mtlc::Matrix<TypeParam> matrix(exp_rows, exp_cols, exp_value);

  typename mtlc::Matrix<TypeParam>::size_type res_rows = matrix.GetRows();
  typename mtlc::Matrix<TypeParam>::size_type res_cols = matrix.GetCols();

  ASSERT_EQ(exp_rows, res_rows);
  ASSERT_EQ(exp_cols, res_cols);

  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i < exp_rows; ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0; j < exp_cols; ++j) {
      ASSERT_EQ(exp_value, matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixConstructor, ConstructorSize0) {
  typename mtlc::Matrix<TypeParam>::size_type exp_rows = 0;
  typename mtlc::Matrix<TypeParam>::size_type exp_cols = 0;
  TypeParam exp_value = TypeParam(0);

  mtlc::Matrix<TypeParam> matrix(exp_rows, exp_cols, exp_value);

  typename mtlc::Matrix<TypeParam>::size_type res_rows = matrix.GetRows();
  typename mtlc::Matrix<TypeParam>::size_type res_cols = matrix.GetCols();

  ASSERT_EQ(exp_rows, res_rows);
  ASSERT_EQ(exp_cols, res_cols);

  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i < exp_rows; ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0; j < exp_cols; ++j) {
      ASSERT_EQ(exp_value, matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixConstructor, ConstructorSize1) {
  typename mtlc::Matrix<TypeParam>::size_type exp_rows = 1;
  typename mtlc::Matrix<TypeParam>::size_type exp_cols = 1;
  TypeParam exp_value = TypeParam(0);

  mtlc::Matrix<TypeParam> matrix(exp_rows, exp_cols, exp_value);

  typename mtlc::Matrix<TypeParam>::size_type res_rows = matrix.GetRows();
  typename mtlc::Matrix<TypeParam>::size_type res_cols = matrix.GetCols();

  ASSERT_EQ(exp_rows, res_rows);
  ASSERT_EQ(exp_cols, res_cols);

  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i < exp_rows; ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0; j < exp_cols; ++j) {
      ASSERT_EQ(exp_value, matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixConstructor, ConstructorSizeFill) {
  typename mtlc::Matrix<TypeParam>::size_type exp_rows = 4;
  typename mtlc::Matrix<TypeParam>::size_type exp_cols = 4;
  TypeParam exp_value = TypeParam(3);

  mtlc::Matrix<TypeParam> matrix(exp_rows, exp_cols, exp_value);

  typename mtlc::Matrix<TypeParam>::size_type res_rows = matrix.GetRows();
  typename mtlc::Matrix<TypeParam>::size_type res_cols = matrix.GetCols();

  ASSERT_EQ(exp_rows, res_rows);
  ASSERT_EQ(exp_cols, res_cols);

  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i < exp_rows; ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0; j < exp_cols; ++j) {
      ASSERT_EQ(exp_value, matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixConstructor, ConstructorSizeBadSizeRow) {
  typename mtlc::Matrix<TypeParam>::size_type exp_rows = 0;
  typename mtlc::Matrix<TypeParam>::size_type exp_cols = 3;
  TypeParam exp_value = TypeParam(0);

  mtlc::Matrix<TypeParam> matrix(0, 3, exp_value);

  typename mtlc::Matrix<TypeParam>::size_type res_rows = matrix.GetRows();
  typename mtlc::Matrix<TypeParam>::size_type res_cols = matrix.GetCols();

  ASSERT_EQ(exp_rows, res_rows);
  ASSERT_EQ(exp_cols, res_cols);

  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i < exp_rows; ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0; j < exp_cols; ++j) {
      ASSERT_EQ(exp_value, matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixConstructor, ConstructorSizeBadSizeCol) {
  typename mtlc::Matrix<TypeParam>::size_type exp_rows = 3;
  typename mtlc::Matrix<TypeParam>::size_type exp_cols = 0;
  TypeParam exp_value = TypeParam(0);

  mtlc::Matrix<TypeParam> matrix(3, 0, exp_value);

  typename mtlc::Matrix<TypeParam>::size_type res_rows = matrix.GetRows();
  typename mtlc::Matrix<TypeParam>::size_type res_cols = matrix.GetCols();

  ASSERT_EQ(exp_rows, res_rows);
  ASSERT_EQ(exp_cols, res_cols);

  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i < exp_rows; ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0; j < exp_cols; ++j) {
      ASSERT_EQ(exp_value, matrix(i, j));
    }
  }
}

TYPED_TEST(TestsMatrixConstructor, ConstructorCopy) {
  const TestsMatrixData<TypeParam>& exp_data =
      TestsMatrixConstructor<TypeParam>::data_2x2_;
  mtlc::Matrix<TypeParam> matrix_copied =
      TestsMatrixConstructor<TypeParam>::FromData(exp_data);
  mtlc::Matrix<TypeParam> matrix(matrix_copied);
  ASSERT_TRUE(TestsMatrixConstructor<TypeParam>::MatrixEq(matrix, exp_data));
}

TYPED_TEST(TestsMatrixConstructor, ConstructorCopyNull) {
  const TestsMatrixData<TypeParam>& exp_data =
      TestsMatrixConstructor<TypeParam>::data_null_;
  mtlc::Matrix<TypeParam> matrix_copied =
      TestsMatrixConstructor<TypeParam>::FromData(exp_data);
  mtlc::Matrix<TypeParam> matrix(matrix_copied);
  ASSERT_TRUE(TestsMatrixConstructor<TypeParam>::MatrixEq(matrix, exp_data));
}

TYPED_TEST(TestsMatrixConstructor, OperatorCopy) {
  const TestsMatrixData<TypeParam>& exp_data =
      TestsMatrixConstructor<TypeParam>::data_3x2_;
  mtlc::Matrix<TypeParam> matrix_copied =
      TestsMatrixConstructor<TypeParam>::FromData(exp_data);
  mtlc::Matrix<TypeParam> matrix;
  matrix = matrix_copied;
  ASSERT_TRUE(TestsMatrixConstructor<TypeParam>::MatrixEq(matrix, exp_data));
}

TYPED_TEST(TestsMatrixConstructor, OperatorCopyNull) {
  const TestsMatrixData<TypeParam>& exp_data =
      TestsMatrixConstructor<TypeParam>::data_null_;
  mtlc::Matrix<TypeParam> matrix_copied =
      TestsMatrixConstructor<TypeParam>::FromData(exp_data);
  mtlc::Matrix<TypeParam> matrix;
  matrix = matrix_copied;
  ASSERT_TRUE(TestsMatrixConstructor<TypeParam>::MatrixEq(matrix, exp_data));
}

TYPED_TEST(TestsMatrixConstructor, ConstructorMove) {
  const TestsMatrixData<TypeParam>& exp_data =
      TestsMatrixConstructor<TypeParam>::data_3x3_;
  mtlc::Matrix<TypeParam> matrix_copied =
      TestsMatrixConstructor<TypeParam>::FromData(exp_data);
  mtlc::Matrix<TypeParam> matrix(std::move(matrix_copied));
  ASSERT_TRUE(TestsMatrixConstructor<TypeParam>::MatrixEq(matrix, exp_data));
}

TYPED_TEST(TestsMatrixConstructor, ConstructorMoveNull) {
  const TestsMatrixData<TypeParam>& exp_data =
      TestsMatrixConstructor<TypeParam>::data_null_;
  mtlc::Matrix<TypeParam> matrix_copied =
      TestsMatrixConstructor<TypeParam>::FromData(exp_data);
  mtlc::Matrix<TypeParam> matrix(std::move(matrix_copied));
  ASSERT_TRUE(TestsMatrixConstructor<TypeParam>::MatrixEq(matrix, exp_data));
}

TYPED_TEST(TestsMatrixConstructor, OperatorMove) {
  const TestsMatrixData<TypeParam>& exp_data =
      TestsMatrixConstructor<TypeParam>::data_2x1_;
  mtlc::Matrix<TypeParam> matrix_copied =
      TestsMatrixConstructor<TypeParam>::FromData(exp_data);
  mtlc::Matrix<TypeParam> matrix;
  matrix = std::move(matrix_copied);
  ASSERT_TRUE(TestsMatrixConstructor<TypeParam>::MatrixEq(matrix, exp_data));
}

TYPED_TEST(TestsMatrixConstructor, OperatorMoveNull) {
  const TestsMatrixData<TypeParam>& exp_data =
      TestsMatrixConstructor<TypeParam>::data_null_;
  mtlc::Matrix<TypeParam> matrix_copied =
      TestsMatrixConstructor<TypeParam>::FromData(exp_data);
  mtlc::Matrix<TypeParam> matrix;
  matrix = std::move(matrix_copied);
  ASSERT_TRUE(TestsMatrixConstructor<TypeParam>::MatrixEq(matrix, exp_data));
}
