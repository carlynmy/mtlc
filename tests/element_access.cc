// Matrix element access tests

#include <gtest/gtest.h>

#include <stdexcept>

#include "matrix.h"
#include "tests.h"

TYPED_TEST(TestsMatrixElementAccess, OperatorBracketsRead) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixElementAccess<TypeParam>::data_3x2_;
  mtlc::Matrix<TypeParam> matrix =
      TestsMatrixElementAccess<TypeParam>::FromData(data);

  auto data_iter = data.data_.begin();
  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i < matrix.GetRows();
       ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0;
         j < matrix.GetCols(); ++j) {
      ASSERT_EQ(*data_iter, matrix(i, j));
      ++data_iter;
    }
  }
}

TYPED_TEST(TestsMatrixElementAccess, OperatorBracketsWrite) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixElementAccess<TypeParam>::data_3x2_;
  mtlc::Matrix<TypeParam> matrix(data.rows_, data.cols_);

  auto data_iter = data.data_.begin();
  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i < matrix.GetRows();
       ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0;
         j < matrix.GetCols(); ++j) {
      matrix(i, j) = *data_iter;
      ++data_iter;
    }
  }
  data_iter = data.data_.begin();
  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i < matrix.GetRows();
       ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0;
         j < matrix.GetCols(); ++j) {
      ASSERT_EQ(*data_iter, matrix(i, j));
      ++data_iter;
    }
  }
}

TYPED_TEST(TestsMatrixElementAccess, AtRead) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixElementAccess<TypeParam>::data_3x2_;
  mtlc::Matrix<TypeParam> matrix =
      TestsMatrixElementAccess<TypeParam>::FromData(data);

  auto data_iter = data.data_.begin();
  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i < matrix.GetRows();
       ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0;
         j < matrix.GetCols(); ++j) {
      ASSERT_EQ(*data_iter, matrix.At(i, j));
      ++data_iter;
    }
  }
}

TYPED_TEST(TestsMatrixElementAccess, AtWrite) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixElementAccess<TypeParam>::data_3x2_;
  mtlc::Matrix<TypeParam> matrix(data.rows_, data.cols_);

  auto data_iter = data.data_.begin();
  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i < matrix.GetRows();
       ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0;
         j < matrix.GetCols(); ++j) {
      matrix.At(i, j) = *data_iter;
      ++data_iter;
    }
  }
  data_iter = data.data_.begin();
  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i < matrix.GetRows();
       ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0;
         j < matrix.GetCols(); ++j) {
      ASSERT_EQ(*data_iter, matrix(i, j));
      ++data_iter;
    }
  }
}

TYPED_TEST(TestsMatrixElementAccess, AtExceptionOutOfRange) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixElementAccess<TypeParam>::data_3x2_;
  mtlc::Matrix<TypeParam> matrix =
      TestsMatrixElementAccess<TypeParam>::FromData(data);

  ASSERT_THROW(matrix.At(3, 1), std::out_of_range);
  ASSERT_THROW(matrix.At(1, 4), std::out_of_range);
}

TYPED_TEST(TestsMatrixElementAccess, DataRead) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixElementAccess<TypeParam>::data_3x2_;
  mtlc::Matrix<TypeParam> matrix =
      TestsMatrixElementAccess<TypeParam>::FromData(data);

  auto data_iter = data.data_.begin();
  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i < matrix.GetRows();
       ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0;
         j < matrix.GetCols(); ++j) {
      ASSERT_EQ(*data_iter, matrix.GetData()[i * matrix.GetCols() + j]);
      ++data_iter;
    }
  }
}

TYPED_TEST(TestsMatrixElementAccess, DataWrite) {
  const TestsMatrixData<TypeParam>& data =
      TestsMatrixElementAccess<TypeParam>::data_3x2_;
  mtlc::Matrix<TypeParam> matrix(data.rows_, data.cols_);

  auto data_iter = data.data_.begin();
  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i < matrix.GetRows();
       ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0;
         j < matrix.GetCols(); ++j) {
      matrix.GetData()[i * matrix.GetCols() + j] = *data_iter;
      ++data_iter;
    }
  }
  data_iter = data.data_.begin();
  for (typename mtlc::Matrix<TypeParam>::size_type i = 0; i < matrix.GetRows();
       ++i) {
    for (typename mtlc::Matrix<TypeParam>::size_type j = 0;
         j < matrix.GetCols(); ++j) {
      ASSERT_EQ(*data_iter, matrix(i, j));
      ++data_iter;
    }
  }
}
