// Автор: Ганжа Дмитро
// Клас-нащадок (Закрите успадкування)
#pragma once
#include "MatrixBase.h"

class MatrixPrivate : private MatrixBase {
public:
    // Конструктори
    MatrixPrivate() : MatrixBase() {}
    MatrixPrivate(int r, int c) : MatrixBase(r, c) {}
    MatrixPrivate(const MatrixBase& other) : MatrixBase(other) {}
    MatrixPrivate(const MatrixPrivate& other) : MatrixBase(other) {}

    // Делегування необхідних методів
    using MatrixBase::Init;
    using MatrixBase::getR;
    using MatrixBase::getC;
    using MatrixBase::getM;
    using MatrixBase::setM;

    // Операція присвоєння
    MatrixPrivate& operator=(const MatrixPrivate& other);

    // Приведення типу до string
    operator string() const;

    // Інкремент та декремент
    MatrixPrivate& operator++();
    MatrixPrivate operator++(int);
    MatrixPrivate& operator--();
    MatrixPrivate operator--(int);

    // Бінарні операції 
    friend MatrixPrivate operator+(const MatrixPrivate& a, const MatrixPrivate& b);
    friend MatrixPrivate operator-(const MatrixPrivate& a, const MatrixPrivate& b);
    friend MatrixPrivate operator*(const MatrixPrivate& a, const MatrixPrivate& b);
    friend MatrixPrivate operator*(const MatrixPrivate& a, int num);

    // Функції вводу-виводу для закритого нащадка (оскільки базові приховані)
    friend ostream& operator<<(ostream& out, const MatrixPrivate& mat);
    friend istream& operator>>(istream& in, MatrixPrivate& mat);
};