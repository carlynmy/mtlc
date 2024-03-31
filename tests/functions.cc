// Matrix functions tests

#include <gtest/gtest.h>

#include "matrix.h"
#include "tests.h"

TYPED_TEST(TestsMatrixFunctions, TransposeNull) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_null_);
  mtlc::Matrix<TypeParam> matrix_transposed =
      TestsMatrixFunctions<TypeParam>::FromData(
          TestsMatrixFunctions<TypeParam>::data_null_);
  mtlc::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.Transpose();
  mtlc::Matrix<TypeParam> matrix_b = matrix.GetTransposed();

  ASSERT_EQ(matrix_transposed, matrix_a);
  ASSERT_EQ(matrix_transposed, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Transpose1x1) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_1x1_);
  mtlc::Matrix<TypeParam> matrix_transposed =
      TestsMatrixFunctions<TypeParam>::FromData(
          TestsMatrixFunctions<TypeParam>::data_1x1_);
  mtlc::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.Transpose();
  mtlc::Matrix<TypeParam> matrix_b = matrix.GetTransposed();

  ASSERT_EQ(matrix_transposed, matrix_a);
  ASSERT_EQ(matrix_transposed, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Transpose2x2) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_2x2_);
  mtlc::Matrix<TypeParam> matrix_transposed =
      TestsMatrixFunctions<TypeParam>::FromData(
          TestsMatrixFunctions<TypeParam>::data_2x2_transposed_);
  mtlc::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.Transpose();
  mtlc::Matrix<TypeParam> matrix_b = matrix.GetTransposed();

  ASSERT_EQ(matrix_transposed, matrix_a);
  ASSERT_EQ(matrix_transposed, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Transpose3x3) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_3x3_);
  mtlc::Matrix<TypeParam> matrix_transposed =
      TestsMatrixFunctions<TypeParam>::FromData(
          TestsMatrixFunctions<TypeParam>::data_3x3_transposed_);
  mtlc::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.Transpose();
  mtlc::Matrix<TypeParam> matrix_b = matrix.GetTransposed();

  ASSERT_EQ(matrix_transposed, matrix_a);
  ASSERT_EQ(matrix_transposed, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Transpose3x2) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_3x2_);
  mtlc::Matrix<TypeParam> matrix_transposed =
      TestsMatrixFunctions<TypeParam>::FromData(
          TestsMatrixFunctions<TypeParam>::data_3x2_transposed_);
  mtlc::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.Transpose();
  mtlc::Matrix<TypeParam> matrix_b = matrix.GetTransposed();

  ASSERT_EQ(matrix_transposed, matrix_a);
  ASSERT_EQ(matrix_transposed, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Transpose2x1) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_2x1_);
  mtlc::Matrix<TypeParam> matrix_transposed =
      TestsMatrixFunctions<TypeParam>::FromData(
          TestsMatrixFunctions<TypeParam>::data_2x1_transposed_);
  mtlc::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.Transpose();
  mtlc::Matrix<TypeParam> matrix_b = matrix.GetTransposed();

  ASSERT_EQ(matrix_transposed, matrix_a);
  ASSERT_EQ(matrix_transposed, matrix_b);
}

TYPED_TEST(TestsMatrixArithmetic, Inverse1x1) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_1x1_);
  mtlc::Matrix<TypeParam> matrix_inversed =
      TestsMatrixArithmetic<TypeParam>::FromData(
          TestsMatrixArithmetic<TypeParam>::data_1x1_inversed_);
  mtlc::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.Inverse();
  mtlc::Matrix<TypeParam> matrix_b = matrix.GetInversed();

  ASSERT_EQ(matrix_inversed, matrix_a);
  ASSERT_EQ(matrix_inversed, matrix_b);
}

TYPED_TEST(TestsMatrixArithmetic, Inverse2x2) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_2x2_);
  mtlc::Matrix<TypeParam> matrix_inversed =
      TestsMatrixArithmetic<TypeParam>::FromData(
          TestsMatrixArithmetic<TypeParam>::data_2x2_inversed_);
  mtlc::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.Inverse();
  mtlc::Matrix<TypeParam> matrix_b = matrix.GetInversed();

  ASSERT_EQ(matrix_inversed, matrix_a);
  ASSERT_EQ(matrix_inversed, matrix_b);
}

TYPED_TEST(TestsMatrixArithmetic, Inverse3x3) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x3_);
  mtlc::Matrix<TypeParam> matrix_inversed =
      TestsMatrixArithmetic<TypeParam>::FromData(
          TestsMatrixArithmetic<TypeParam>::data_3x3_inversed_);
  mtlc::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.Inverse();
  mtlc::Matrix<TypeParam> matrix_b = matrix.GetInversed();

  ASSERT_EQ(matrix_inversed, matrix_a);
  ASSERT_EQ(matrix_inversed, matrix_b);
}

TYPED_TEST(TestsMatrixArithmetic, InverseExceptionNull) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_null_);
  mtlc::Matrix<TypeParam> matrix_a = matrix;
  ASSERT_THROW(matrix_a.Inverse(), std::logic_error);
  ASSERT_THROW(matrix.GetInversed(), std::logic_error);
}

TYPED_TEST(TestsMatrixArithmetic, InverseExceptionNotSquare) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x2_);
  mtlc::Matrix<TypeParam> matrix_a = matrix;
  ASSERT_THROW(matrix_a.Inverse(), std::logic_error);
  ASSERT_THROW(matrix.GetInversed(), std::logic_error);
}

TYPED_TEST(TestsMatrixArithmetic, InverseExceptionDetZero) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixArithmetic<TypeParam>::FromData(
      TestsMatrixArithmetic<TypeParam>::data_3x3_zero_det_);
  mtlc::Matrix<TypeParam> matrix_a = matrix;
  ASSERT_THROW(matrix_a.Inverse(), std::logic_error);
  ASSERT_THROW(matrix.GetInversed(), std::logic_error);
}

TYPED_TEST(TestsMatrixFunctions, Complements2x2) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_2x2_);
  mtlc::Matrix<TypeParam> matrix_complements =
      TestsMatrixFunctions<TypeParam>::FromData(
          TestsMatrixFunctions<TypeParam>::data_2x2_complements_);
  mtlc::Matrix<TypeParam> matrix_a = matrix.CalcComplements();

  ASSERT_EQ(matrix_complements, matrix_a);
}

TYPED_TEST(TestsMatrixFunctions, Complements3x3) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_3x3_);
  mtlc::Matrix<TypeParam> matrix_complements =
      TestsMatrixFunctions<TypeParam>::FromData(
          TestsMatrixFunctions<TypeParam>::data_3x3_complements_);
  mtlc::Matrix<TypeParam> matrix_a = matrix.CalcComplements();

  ASSERT_EQ(matrix_complements, matrix_a);
}

TYPED_TEST(TestsMatrixFunctions, ComplementsExceptionNull) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_null_);

  ASSERT_THROW(matrix.CalcComplements(), std::logic_error);
}

TYPED_TEST(TestsMatrixFunctions, ComplementsException1x1) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_1x1_);

  ASSERT_THROW(matrix.CalcComplements(), std::logic_error);
}

TYPED_TEST(TestsMatrixFunctions, ComplementsExceptionNotSquare) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_3x2_);

  ASSERT_THROW(matrix.CalcComplements(), std::logic_error);
}

TYPED_TEST(TestsMatrixFunctions, Cut3x3_0_0) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_3x3_);
  mtlc::Matrix<TypeParam> matrix_cuted =
      TestsMatrixFunctions<TypeParam>::FromData(
          TestsMatrixFunctions<TypeParam>::data_3x3_cut_0_0_);

  mtlc::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.CutMatrix(0, 0);
  mtlc::Matrix<TypeParam> matrix_b = matrix.GetCutedMatrix(0, 0);

  ASSERT_EQ(matrix_cuted, matrix_a);
  ASSERT_EQ(matrix_cuted, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Cut3x3_1_2) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_3x3_);
  mtlc::Matrix<TypeParam> matrix_cuted =
      TestsMatrixFunctions<TypeParam>::FromData(
          TestsMatrixFunctions<TypeParam>::data_3x3_cut_1_2_);

  mtlc::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.CutMatrix(1, 2);
  mtlc::Matrix<TypeParam> matrix_b = matrix.GetCutedMatrix(1, 2);

  ASSERT_EQ(matrix_cuted, matrix_a);
  ASSERT_EQ(matrix_cuted, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Cut3x3_2_1) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_3x3_);
  mtlc::Matrix<TypeParam> matrix_cuted =
      TestsMatrixFunctions<TypeParam>::FromData(
          TestsMatrixFunctions<TypeParam>::data_3x3_cut_2_1_);

  mtlc::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.CutMatrix(2, 1);
  mtlc::Matrix<TypeParam> matrix_b = matrix.GetCutedMatrix(2, 1);

  ASSERT_EQ(matrix_cuted, matrix_a);
  ASSERT_EQ(matrix_cuted, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, Cut3x3_2_2) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_3x3_);
  mtlc::Matrix<TypeParam> matrix_cuted =
      TestsMatrixFunctions<TypeParam>::FromData(
          TestsMatrixFunctions<TypeParam>::data_3x3_cut_2_2_);

  mtlc::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.CutMatrix(2, 2);
  mtlc::Matrix<TypeParam> matrix_b = matrix.GetCutedMatrix(2, 2);

  ASSERT_EQ(matrix_cuted, matrix_a);
  ASSERT_EQ(matrix_cuted, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, CutToZero) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_2x1_);
  mtlc::Matrix<TypeParam> matrix_cuted(1, 0);

  mtlc::Matrix<TypeParam> matrix_a = matrix;
  matrix_a.CutMatrix(0, 0);
  mtlc::Matrix<TypeParam> matrix_b = matrix.GetCutedMatrix(0, 0);

  ASSERT_EQ(matrix_cuted, matrix_a);
  ASSERT_EQ(matrix_cuted, matrix_b);
}

TYPED_TEST(TestsMatrixFunctions, CutExceptionNull) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_null_);

  mtlc::Matrix<TypeParam> matrix_a = matrix;
  ASSERT_THROW(matrix_a.CutMatrix(0, 0), std::logic_error);
  ASSERT_THROW(matrix.GetCutedMatrix(2, 2), std::logic_error);
}

TYPED_TEST(TestsMatrixFunctions, CutExceptionOutOfRange) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_3x3_);

  mtlc::Matrix<TypeParam> matrix_a = matrix;
  ASSERT_THROW(matrix_a.CutMatrix(2, 56), std::logic_error);
  ASSERT_THROW(matrix.GetCutedMatrix(1241442, 123), std::logic_error);
}

TYPED_TEST(TestsMatrixFunctions, Determenant1x1) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_1x1_);
  TypeParam exp_det = TestsMatrixFunctions<TypeParam>::det_1x1_;

  TypeParam det = matrix.Determinant();

  ASSERT_EQ(exp_det, det);
}

TYPED_TEST(TestsMatrixFunctions, Determenant2x2) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_2x2_);
  TypeParam exp_det = TestsMatrixFunctions<TypeParam>::det_2x2_;

  TypeParam det = matrix.Determinant();

  ASSERT_EQ(exp_det, det);
}

TYPED_TEST(TestsMatrixFunctions, Determenant3x3) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_3x3_);
  TypeParam exp_det = TestsMatrixFunctions<TypeParam>::det_3x3_;

  TypeParam det = matrix.Determinant();

  ASSERT_EQ(exp_det, det);
}

TYPED_TEST(TestsMatrixFunctions, DetermenantExceptionNull) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_null_);

  ASSERT_THROW(matrix.Determinant(), std::logic_error);
}

TYPED_TEST(TestsMatrixFunctions, DetermenantExceptionNotSquare) {
  mtlc::Matrix<TypeParam> matrix = TestsMatrixFunctions<TypeParam>::FromData(
      TestsMatrixFunctions<TypeParam>::data_3x2_);

  ASSERT_THROW(matrix.Determinant(), std::logic_error);
}
