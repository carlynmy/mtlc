#ifndef MTLC_MATRIX_H_
#define MTLC_MATRIX_H_

#include <cstddef>
#include <stdexcept>
#include <string>
#include <utility>

namespace mtlc {

/// @brief class Matrix
/// @tparam T value type
template <typename T>
class Matrix {
 public:
  using value_type = T;
  using size_type = size_t;
  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;

  // ----------------------------------------------------------------------- //
  //                              Constructors                               //
  // ----------------------------------------------------------------------- //

  /// @brief Construct 0x0 matrix
  Matrix();

  /// @brief Construct matrix with rows and cols size.
  Matrix(size_type rows, size_type cols, const_reference value = value_type(0));

  Matrix(const Matrix& other);
  Matrix(Matrix&& other) noexcept;
  Matrix& operator=(const Matrix& other);
  Matrix& operator=(Matrix&& other) noexcept;

  virtual ~Matrix();

  // ----------------------------------------------------------------------- //
  //                               Comparator                                //
  // ----------------------------------------------------------------------- //

  /// @brief Returns true if matrix have same size and all items are equal.
  /// Otherwise returns false.
  bool EqMatrix(const Matrix& other) const;

  /// @brief Returns true if matrix have same size and all items are equal.
  /// Otherwise returns false.
  bool operator==(const Matrix& other) const;

  /// @brief Returns false if matrix have same size and all items are equal.
  /// Otherwise returns true.
  bool operator!=(const Matrix& other) const;

  // ----------------------------------------------------------------------- //
  //                             Element access                              //
  // ----------------------------------------------------------------------- //

  /// @brief Get referense to item in row col position.
  /// @throw std::out_of_range if row not in [0, GetRows()) or col not in [0,
  /// GetCols()).
  reference At(size_type row, size_type col);

  /// @brief Get const_referense to item in row col position.
  /// @throw std::out_of_range if row not in [0, GetRows()) or col not in [0,
  /// GetCols()).
  const_reference At(size_type row, size_type col) const;

  /// @brief Get referense to item in row col position.
  /// @warning undefined behavior if row not in [0, GetRows()) or col not in [0,
  /// GetCols()).
  reference operator()(size_type row, size_type col);

  /// @brief Get const referense to item in row col position.
  /// @warning undefined behavior if row not in [0, GetRows()) or col not in [0,
  /// GetCols())
  const_reference operator()(size_type row, size_type col) const;

  /// @brief Returns pointer to the underlying array serving as element storage.
  /// @warning Undefined behavior if access to data not in range[0, GetRows() *
  /// GetCols())
  pointer GetData();

  /// @brief Returns const_pointer to the underlying array serving as element
  /// storage.
  /// @warning Undefined behavior if access to data not in range[0, GetRows() *
  /// GetCols())
  const_pointer GetData() const;

  // ----------------------------------------------------------------------- //
  //                               Modifiers                                 //
  // ----------------------------------------------------------------------- //

  /// @brief Set rows. if new rows is bigger, new data will be set to value. if
  /// new rows is lesser old data will lost.
  /// @warning if rows <= 0, set 0x0 matrix.
  /// @warning if GetCols() == 0, matrix will remain 0x0.
  void SetRows(size_type rows, const_reference value = value_type(0));

  /// @brief Set cols. if new cols is bigger, new data will be set to value. if
  /// new cols is lesser old data will lost.
  /// @warning if cols <= 0, set 0x0 matrix.
  /// @warning if GetRows() == 0, matrix will remain 0x0.
  void SetCols(size_type cols, const_reference value = value_type(0));

  /// @brief Set size. if new rows is bigger, new data will be set to value. if
  /// new rows is lesser old data will lost. if new cols is bigger, new data
  /// will value. if new cols is lesser old data will lost.
  /// @warning if rows <= 0, set 0x0 matrix.
  /// @warning if cols <= 0, set 0x0 matrix.
  void SetSize(size_type rows, size_type cols,
               const_reference value = value_type(0));

  // ----------------------------------------------------------------------- //
  //                               Capacity                                  //
  // ----------------------------------------------------------------------- //

  size_type GetRows() const;
  size_type GetCols() const;

  // ----------------------------------------------------------------------- //
  //                               Arithmetic                                //
  // ----------------------------------------------------------------------- //

  /// @brief Add matrix to other.
  /// @throw std::logic_error if matrix sizes are different.
  /// @return reference to this
  Matrix& SumMatrix(const Matrix& other);

  /// @brief Sub matrix to other.
  /// @throw std::logic_error if matrix sizes are different.
  /// @return reference to this.
  Matrix& SubMatrix(const Matrix& other);

  /// @brief Mul matrix to matrix.
  /// @throw std::logic_error if this GetCols() not equal to other GetRows().
  /// @return reference to this.
  Matrix& MulMatrix(const Matrix& other);

  /// @brief Mul matrix to number.
  /// @return reference to this.
  Matrix& MulNumber(const_reference num);

  /// @brief Return sum matrix.
  /// @throw std::logic_error if matrix sizes are different.
  Matrix operator+(const Matrix& other) const;

  /// @brief Return sub matrix.
  /// @throw std::logic_error if matrix sizes are different.
  Matrix operator-(const Matrix& other) const;

  /// @brief Return sub matrix.
  /// @throw std::logic_error if this GetCols() not equal to other GetRows().
  Matrix operator*(const Matrix& other) const;

  /// @brief Mul matrix to value.
  Matrix operator*(const_reference value) const;

  /// @brief Add matrix to other.
  /// @throw std::logic_error if matrix sizes are different.
  /// @return reference to this.
  Matrix& operator+=(const Matrix& other);

  /// @brief Sub matrix to other.
  /// @throw std::logic_error if matrix sizes are different.
  /// @return reference to this.
  Matrix& operator-=(const Matrix& other);

  /// @brief Mul matrix to matrix.
  /// @throw std::logic_error if this GetCols() not equal to other GetRows().
  /// @return reference to this.
  Matrix& operator*=(const Matrix& other);

  /// @brief Mul matrix to number.
  /// @return reference to this.
  Matrix& operator*=(const_reference value);

  // ----------------------------------------------------------------------- //
  //                               Functions                                 //
  // ----------------------------------------------------------------------- //

  /// @brief Calc determinant.
  /// @throw std::logic_error if matrix not square.
  /// @throw std::logic_error if matrix size is 0x0.
  value_type Determinant() const;

  /// @brief Transpose matrix.
  /// @return reference to this.
  Matrix& Transpose();

  /// @brief Get transposed matrix
  Matrix GetTransposed();

  /// @brief Inverse matrix
  /// @throw std::logic_error if matrix not square.
  /// @throw std::logic_error if determinant is zero.
  /// @throw std::logic_error if matrix size is 0x0.
  /// @return reference to this.
  Matrix& Inverse();

  /// @brief Get inversed matrix.
  /// @throw std::logic_error if matrix not square.
  /// @throw std::logic_error if determinant is zero.
  /// @throw std::logic_error if matrix size is 0x0.
  Matrix GetInversed() const;

  /// @brief Return complements matrix
  /// @throw std::logic_error if matrix not square.
  /// @throw std::logic_error if matrix size is 0x0.
  /// @throw std::logic_error if matrix size is 1x1.
  Matrix CalcComplements() const;

  /// @brief Remove row row, column col. The result will be a matrix dimension
  /// (GetRows() - 1, GetCols() - 1).
  /// @throw std::out_of_range if row not in [0, GetRows()) or col not in [0,
  /// GetCols()).
  /// @throw std::logic_error if matrix size is 0.
  /// @return reference to this.
  Matrix& CutMatrix(size_type row, size_type col);

  /// @brief Get new matrix with removed row row, column col. The result will be
  /// a matrix dimension (GetRows() - 1, GetCols() - 1).
  /// @throw std::out_of_range if row not in [0, GetRows()) or col not in [0,
  /// GetCols()).
  /// @throw std::logic_error if matrix size is 0.
  Matrix GetCutedMatrix(size_type row, size_type col) const;

 private:
  static const std::string kStrErrorOutOfRange_;
  static const std::string kStrErrorCantGetData_;
  static const std::string kStrErrorDiffSizes_;
  static const std::string kStrErrorInvalidSizes_;
  static const std::string kStrErrorZeroDeterminant_;
  static const std::string kStrErrorMatrixNotSquare_;
  static const std::string kStrErrorEmptyMatrix_;

  value_type AlgComplement(size_type row, size_type col) const;
  static bool IsEven(size_type val);

  size_type rows_, cols_;
  pointer data_;
};

/// @brief Mul matrix to value.
template <typename T>
Matrix<T> operator*(typename Matrix<T>::const_reference value,
                    const Matrix<T>& matrix);

// ------------------------------------------------------------------------- //
//                               Constructors                                //
// ------------------------------------------------------------------------- //

template <typename T>
Matrix<T>::Matrix() : Matrix(0, 0) {}

template <typename T>
Matrix<T>::Matrix(size_type rows, size_type cols, const_reference value) {
  rows_ = rows;
  cols_ = cols;
  data_ = new value_type[rows_ * cols_];
  for (size_type i = size_type(0); i < rows_; ++i) {
    for (size_type j = size_type(0); j < cols; ++j) {
      (*this)(i, j) = value;
    }
  }
}

template <typename T>
Matrix<T>::Matrix(const Matrix& other) : Matrix(other.rows_, other.cols_) {
  for (size_type i = size_type(0); i != rows_; ++i) {
    for (size_type j = size_type(0); j != cols_; ++j) {
      (*this)(i, j) = other(i, j);
    }
  }
}

template <typename T>
Matrix<T>::Matrix(Matrix&& other) noexcept {
  rows_ = other.rows_;
  cols_ = other.cols_;
  data_ = other.data_;

  other.rows_ = 0;
  other.cols_ = 0;
  other.data_ = new value_type[other.rows_ * other.cols_];
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other) {
  if (this == &other) return *this;

  Matrix tmp(other);
  *this = std::move(tmp);

  return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept {
  if (this == &other) return *this;

  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(data_, other.data_);

  return *this;
}

template <typename T>
Matrix<T>::~Matrix() {
  delete[] data_;
}

// ------------------------------------------------------------------------- //
//                                Comparator                                 //
// ------------------------------------------------------------------------- //

template <typename T>
bool Matrix<T>::EqMatrix(const Matrix& other) const {
  if (GetRows() != other.GetRows() || GetCols() != other.GetCols())
    return false;

  for (size_type i = 0; i < GetRows(); ++i) {
    for (size_type j = 0; j < GetCols(); ++j) {
      if ((*this)(i, j) != other(i, j)) return false;
    }
  }

  return true;
}

template <typename T>
bool Matrix<T>::operator==(const Matrix& other) const {
  return this->EqMatrix(other);
}

template <typename T>
bool Matrix<T>::operator!=(const Matrix& other) const {
  return !this->EqMatrix(other);
}

// ------------------------------------------------------------------------- //
//                             Element access                              //
// ------------------------------------------------------------------------- //

template <typename T>
typename Matrix<T>::reference Matrix<T>::At(size_type row, size_type col) {
  if (row >= GetRows() || col >= GetCols())
    throw std::out_of_range(kStrErrorOutOfRange_);
  return this->operator()(row, col);
}

template <typename T>
typename Matrix<T>::const_reference Matrix<T>::At(size_type row,
                                                  size_type col) const {
  if (row >= GetRows() || col >= GetCols())
    throw std::out_of_range(kStrErrorOutOfRange_);
  return this->operator()(row, col);
}

template <typename T>
typename Matrix<T>::reference Matrix<T>::operator()(size_type row,
                                                    size_type col) {
  return data_[row * GetCols() + col];
}

template <typename T>
typename Matrix<T>::const_reference Matrix<T>::operator()(size_type row,
                                                          size_type col) const {
  return data_[row * GetCols() + col];
}

template <typename T>
typename Matrix<T>::pointer Matrix<T>::GetData() {
  return data_;
}

template <typename T>
typename Matrix<T>::const_pointer Matrix<T>::GetData() const {
  return data_;
}

// ------------------------------------------------------------------------- //
//                                Modifiers                                  //
// ------------------------------------------------------------------------- //

template <typename T>
void Matrix<T>::SetRows(size_type rows, const_reference value) {
  SetSize(rows, cols_, value);
}

template <typename T>
void Matrix<T>::SetCols(size_type cols, const_reference value) {
  SetSize(rows_, cols, value);
}

template <typename T>
void Matrix<T>::SetSize(size_type rows, size_type cols, const_reference value) {
  Matrix res(rows, cols, value);

  size_type copy_rows = (rows_ < rows ? rows_ : rows);
  size_type copy_cols = (cols_ < cols ? cols_ : cols);
  for (size_type i = size_type(0); i < copy_rows; ++i) {
    for (size_type j = size_type(0); j < copy_cols; ++j) {
      res(i, j) = (*this)(i, j);
    }
  }

  (*this) = std::move(res);
}

// ------------------------------------------------------------------------- //
//                                Capacity                                   //
// ------------------------------------------------------------------------- //

template <typename T>
typename Matrix<T>::size_type Matrix<T>::GetRows() const {
  return rows_;
}

template <typename T>
typename Matrix<T>::size_type Matrix<T>::GetCols() const {
  return cols_;
}

// ------------------------------------------------------------------------- //
//                                Arithmetic                                 //
// ------------------------------------------------------------------------- //

template <typename T>
Matrix<T>& Matrix<T>::SumMatrix(const Matrix& other) {
  if (GetRows() != other.GetRows() || GetCols() != other.GetCols())
    throw std::logic_error(kStrErrorDiffSizes_);

  for (size_type i = size_type(0); i < GetRows(); i++) {
    for (size_type j = size_type(0); j < GetCols(); j++) {
      (*this)(i, j) = (*this)(i, j) + other(i, j);
    }
  }

  return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::SubMatrix(const Matrix& other) {
  if (GetRows() != other.GetRows() || GetCols() != other.GetCols())
    throw std::logic_error(kStrErrorDiffSizes_);

  for (size_type i = size_type(0); i < GetRows(); i++) {
    for (size_type j = size_type(0); j < GetCols(); j++) {
      (*this)(i, j) = (*this)(i, j) - other(i, j);
    }
  }

  return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::MulMatrix(const Matrix& other) {
  if (GetCols() != other.GetRows())
    throw std::logic_error(kStrErrorInvalidSizes_);

  Matrix new_matrix(GetRows(), other.GetCols());
  for (size_type i = size_type(0); i < GetRows(); i++) {
    for (size_type j = size_type(0); j < other.GetCols(); j++) {
      value_type tmp_sum = value_type(0);
      for (size_type k = size_type(0); k < GetCols(); k++)
        tmp_sum += (*this)(i, k) * other(k, j);
      new_matrix(i, j) = tmp_sum;
    }
  }

  *this = std::move(new_matrix);
  return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::MulNumber(const_reference num) {
  for (size_type i = size_type(0); i < GetRows(); i++) {
    for (size_type j = size_type(0); j < GetCols(); j++) {
      (*this)(i, j) = (*this)(i, j) * num;
    }
  }

  return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& other) const {
  if (GetRows() != other.GetRows() || GetCols() != other.GetCols())
    throw std::logic_error(kStrErrorDiffSizes_);

  Matrix res(GetRows(), GetCols());
  for (size_type i = size_type(0); i < GetRows(); i++) {
    for (size_type j = size_type(0); j < GetCols(); j++) {
      res(i, j) = (*this)(i, j) + other(i, j);
    }
  }

  return res;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& other) const {
  if (GetRows() != other.GetRows() || GetCols() != other.GetCols())
    throw std::logic_error(kStrErrorDiffSizes_);

  Matrix res(GetRows(), GetCols());
  for (size_type i = size_type(0); i < GetRows(); i++) {
    for (size_type j = size_type(0); j < GetCols(); j++) {
      res(i, j) = (*this)(i, j) - other(i, j);
    }
  }

  return res;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& other) const {
  if (GetCols() != other.GetRows())
    throw std::logic_error(kStrErrorInvalidSizes_);

  Matrix res(GetRows(), other.GetCols());
  for (size_type i = size_type(0); i < GetRows(); i++) {
    for (size_type j = size_type(0); j < other.GetCols(); j++) {
      value_type tmp_sum = value_type(0);
      for (size_type k = size_type(0); k < GetCols(); k++)
        tmp_sum += (*this)(i, k) * other(k, j);
      res(i, j) = tmp_sum;
    }
  }

  return res;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const_reference value) const {
  Matrix res(GetRows(), GetCols());
  for (size_type i = size_type(0); i < GetRows(); i++) {
    for (size_type j = size_type(0); j < GetCols(); j++) {
      res(i, j) = (*this)(i, j) * value;
    }
  }

  return res;
}

template <typename T>
Matrix<T> operator*(typename Matrix<T>::const_reference value,
                    const Matrix<T>& matrix) {
  Matrix<T> res(matrix.GetRows(), matrix.GetCols());
  for (typename Matrix<T>::size_type i = typename Matrix<T>::size_type(0);
       i < matrix.GetRows(); i++) {
    for (typename Matrix<T>::size_type j = typename Matrix<T>::size_type(0);
         j < matrix.GetCols(); j++) {
      res(i, j) = matrix(i, j) * value;
    }
  }

  return res;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix& other) {
  return this->SumMatrix(other);
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix& other) {
  return this->SubMatrix(other);
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix& other) {
  return this->MulMatrix(other);
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const_reference value) {
  return this->MulNumber(value);
}

// ------------------------------------------------------------------------- //
//                                Functions                                  //
// ------------------------------------------------------------------------- //

template <typename T>
typename Matrix<T>::value_type Matrix<T>::Determinant() const {
  if (GetRows() != GetCols()) throw std::logic_error(kStrErrorMatrixNotSquare_);
  if (GetRows() == 0) throw std::logic_error(kStrErrorEmptyMatrix_);
  if (GetRows() == 1) return (*this)(size_type(0), size_type(0));

  value_type answer = value_type(0);
  for (size_type j = size_type(0); j < GetRows(); j++)
    answer += (*this)(size_type(0), j) * AlgComplement(size_type(0), j);
  return answer;
}

template <typename T>
Matrix<T>& Matrix<T>::Transpose() {
  *this = std::move(GetTransposed());
  return *this;
}

template <typename T>
Matrix<T> Matrix<T>::GetTransposed() {
  Matrix new_matrix(GetCols(), GetRows());
  for (size_type i = size_type(0); i < new_matrix.GetRows(); i++) {
    for (size_type j = size_type(0); j < new_matrix.GetCols(); j++) {
      new_matrix(i, j) = (*this)(j, i);
    }
  }
  return new_matrix;
}

template <typename T>
Matrix<T>& Matrix<T>::Inverse() {
  *this = std::move(GetInversed());
  return *this;
}

template <typename T>
Matrix<T> Matrix<T>::GetInversed() const {
  if (GetRows() == 0) throw std::logic_error(kStrErrorEmptyMatrix_);
  if (GetCols() == 1 && GetRows() == 1) {
    Matrix res(1, 1);
    if ((*this)(size_type(0), size_type(0)) == value_type(0))
      throw std::logic_error(kStrErrorZeroDeterminant_);
    res(size_type(0), size_type(0)) =
        value_type(1) / (*this)(size_type(0), size_type(0));
    return res;
  }

  value_type det = Determinant();
  if (det == value_type(0)) throw std::logic_error(kStrErrorZeroDeterminant_);
  Matrix res = CalcComplements();
  res.Transpose();
  res.MulNumber(value_type(1) / det);

  return res;
}

template <typename T>
Matrix<T> Matrix<T>::CalcComplements() const {
  if (GetRows() != GetCols()) throw std::logic_error(kStrErrorMatrixNotSquare_);
  if (GetRows() == 0) throw std::logic_error(kStrErrorEmptyMatrix_);
  if (GetRows() == 1) throw std::logic_error(kStrErrorInvalidSizes_);

  Matrix result_matrix(GetRows(), GetCols());
  for (size_type i = size_type(0); i < GetRows(); i++) {
    for (size_type j = size_type(0); j < GetCols(); j++) {
      result_matrix(i, j) = AlgComplement(i, j);
    }
  }

  return result_matrix;
}

template <typename T>
Matrix<T>& Matrix<T>::CutMatrix(size_type row, size_type col) {
  *this = std::move(GetCutedMatrix(row, col));
  return *this;
}

template <typename T>
Matrix<T> Matrix<T>::GetCutedMatrix(size_type row, size_type col) const {
  if (row >= GetRows() || col >= GetCols())
    throw std::out_of_range(kStrErrorOutOfRange_);
  if (GetRows() == size_type(0)) throw std::logic_error(kStrErrorEmptyMatrix_);

  Matrix res(GetRows() - 1, GetCols() - 1);

  for (size_type i = size_type(0); i != row; ++i) {
    for (size_type j = size_type(0); j != col; ++j) {
      res(i, j) = (*this)(i, j);
    }
  }

  for (size_type i = row; i != res.GetRows(); ++i) {
    for (size_type j = size_type(0); j != col; ++j) {
      res(i, j) = (*this)(i + 1, j);
    }
  }

  for (size_type i = size_type(0); i != row; ++i) {
    for (size_type j = col; j != res.GetCols(); ++j) {
      res(i, j) = (*this)(i, j + 1);
    }
  }

  for (size_type i = row; i != res.GetRows(); ++i) {
    for (size_type j = col; j != res.GetCols(); ++j) {
      res(i, j) = (*this)(i + 1, j + 1);
    }
  }

  return res;
}

template <typename T>
typename Matrix<T>::value_type Matrix<T>::AlgComplement(size_type row,
                                                        size_type col) const {
  Matrix cut_matrix = GetCutedMatrix(row, col);
  value_type minor = cut_matrix.Determinant();
  value_type alg_complement =
      (IsEven(row + col) ? value_type(1) : value_type(-1)) * minor;
  return alg_complement;
}

template <typename T>
bool Matrix<T>::IsEven(size_type val) {
  return (val % 2 == size_type(0));
}
template <typename T>
const std::string Matrix<T>::kStrErrorOutOfRange_ = "Out of range";
template <typename T>
const std::string Matrix<T>::kStrErrorDiffSizes_ =
    "Matrixes with different sizes";
template <typename T>
const std::string Matrix<T>::kStrErrorInvalidSizes_ = "Invalid sizes";
template <typename T>
const std::string Matrix<T>::kStrErrorZeroDeterminant_ = "Determenant is zero";
template <typename T>
const std::string Matrix<T>::kStrErrorMatrixNotSquare_ = "Matrix not square";
template <typename T>
const std::string Matrix<T>::kStrErrorEmptyMatrix_ =
    "Operatrion with zero matrix";

}  // namespace mtlc

#endif  // MTLC_MATRIX_H_
