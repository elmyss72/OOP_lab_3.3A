// Автор: Ганжа Дмитро
// Клас-нащадок (Відкрите успадкування)
#pragma once
#include "MatrixBase.h"

class MatrixPublic : public MatrixBase {
public:
    // Конструктори
    MatrixPublic() : MatrixBase() {}
    MatrixPublic(int r, int c) : MatrixBase(r, c) {}
    MatrixPublic(const MatrixBase& other) : MatrixBase(other) {}

    // Операція присвоєння (метод класу)
    MatrixPublic& operator=(const MatrixPublic& other);

    // Приведення типу до string
    operator string() const;

    // Інкремент та декремент (унарні - методи класу)
    MatrixPublic& operator++();       // префіксний
    MatrixPublic operator++(int);     // постфіксний
    MatrixPublic& operator--();       // префіксний
    MatrixPublic operator--(int);     // постфіксний

    // Бінарні операції як дружні функції
    friend MatrixPublic operator+(const MatrixPublic& a, const MatrixPublic& b);
    friend MatrixPublic operator-(const MatrixPublic& a, const MatrixPublic& b);
    friend MatrixPublic operator*(const MatrixPublic& a, const MatrixPublic& b);
    friend MatrixPublic operator*(const MatrixPublic& a, int num);
};