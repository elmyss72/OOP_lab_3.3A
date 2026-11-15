#include "MatrixPrivate.h"

MatrixPrivate& MatrixPrivate::operator=(const MatrixPrivate& other) {
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

MatrixPrivate::operator string() const {
    return MatrixBase::toString();
}

MatrixPrivate& MatrixPrivate::operator++() {
    for (int i = 0; i < getR(); ++i) {
        for (int j = 0; j < getC(); ++j) {
            setM(i, j, getM(i, j) + 1);
        }
    }
    return *this;
}

MatrixPrivate MatrixPrivate::operator++(int) {
    MatrixPrivate temp(*this);
    ++(*this);
    return temp;
}

MatrixPrivate& MatrixPrivate::operator--() {
    for (int i = 0; i < getR(); ++i) {
        for (int j = 0; j < getC(); ++j) {
            setM(i, j, getM(i, j) - 1);
        }
    }
    return *this;
}

MatrixPrivate MatrixPrivate::operator--(int) {
    MatrixPrivate temp(*this);
    --(*this);
    return temp;
}

MatrixPrivate operator+(const MatrixPrivate& a, const MatrixPrivate& b) {
    return MatrixPrivate(a.Add(b));
}

MatrixPrivate operator-(const MatrixPrivate& a, const MatrixPrivate& b) {
    return MatrixPrivate(a.Subtract(b));
}

MatrixPrivate operator*(const MatrixPrivate& a, const MatrixPrivate& b) {
    return MatrixPrivate(a.Multiply(b));
}

MatrixPrivate operator*(const MatrixPrivate& a, int num) {
    return MatrixPrivate(a.Multiply(num));
}

ostream& operator<<(ostream& out, const MatrixPrivate& mat) {
    out << "Private Matrix Output:\n";
    for (int i = 0; i < mat.getR(); ++i) {
        for (int j = 0; j < mat.getC(); ++j) {
            out << mat.getM(i, j) << "\t";
        }
        out << "\n";
    }
    return out;
}

istream& operator>>(istream& in, MatrixPrivate& mat) {
    int r, c, val;
    cout << "Rows: "; in >> r;
    cout << "Cols: "; in >> c;
    mat.Init(r, c);
    for (int i = 0; i < mat.getR(); ++i) {
        for (int j = 0; j < mat.getC(); ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            in >> val;
            mat.setM(i, j, val);
        }
    }
    return in;
}