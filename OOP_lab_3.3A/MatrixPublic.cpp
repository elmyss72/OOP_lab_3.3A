#include "MatrixPublic.h"

MatrixPublic& MatrixPublic::operator=(const MatrixPublic& other) {
    if (this != &other) {
        this->Init(other.getR(), other.getC());
        for (int i = 0; i < getR(); ++i) {
            for (int j = 0; j < getC(); ++j) {
                setM(i, j, other.getM(i, j));
            }
        }
    }
    return *this;
}

MatrixPublic::operator string() const {
    return this->toString();
}

MatrixPublic& MatrixPublic::operator++() {
    for (int i = 0; i < getR(); ++i) {
        for (int j = 0; j < getC(); ++j) {
            setM(i, j, getM(i, j) + 1);
        }
    }
    return *this;
}

MatrixPublic MatrixPublic::operator++(int) {
    MatrixPublic temp(*this);
    ++(*this);
    return temp;
}

MatrixPublic& MatrixPublic::operator--() {
    for (int i = 0; i < getR(); ++i) {
        for (int j = 0; j < getC(); ++j) {
            setM(i, j, getM(i, j) - 1);
        }
    }
    return *this;
}

MatrixPublic MatrixPublic::operator--(int) {
    MatrixPublic temp(*this);
    --(*this);
    return temp;
}

MatrixPublic operator+(const MatrixPublic& a, const MatrixPublic& b) {
    return MatrixPublic(a.Add(b));
}

MatrixPublic operator-(const MatrixPublic& a, const MatrixPublic& b) {
    return MatrixPublic(a.Subtract(b));
}

MatrixPublic operator*(const MatrixPublic& a, const MatrixPublic& b) {
    return MatrixPublic(a.Multiply(b));
}

MatrixPublic operator*(const MatrixPublic& a, int num) {
    return MatrixPublic(a.Multiply(num));
}