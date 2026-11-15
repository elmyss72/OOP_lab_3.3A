// Автор: Ганжа Дмитро
// Базовий клас для роботи з матрицями
#pragma once
#include <iostream>
#include <string>

using namespace std;

class MatrixBase {
private:
    int** m;
    int R;
    int C;

    // Допоміжні методи для управління пам'яттю
    void allocate();
    void deallocate();

public:
    // Конструктори
    MatrixBase();
    MatrixBase(int r, int c);
    MatrixBase(const MatrixBase& other);

    // Деструктор
    ~MatrixBase();

    // Методи доступу (Геттери)
    int getR() const;
    int getC() const;
    int getM(int i, int j) const;

    // Методи запису (Сетери) з перевіркою коректності
    void setR(int r);
    void setC(int c);
    void setM(int i, int j, int val);

    // Базові методи за умовою Лабораторної 1.3
    void Init(int r, int c);
    void Read();
    void Display() const;
    string toString() const;
    int Element(int i, int j) const;

    // Математичні операції (Варіант 24)
    MatrixBase Add(const MatrixBase& other) const;
    MatrixBase Subtract(const MatrixBase& other) const;
    MatrixBase Multiply(const MatrixBase& other) const;
    MatrixBase Multiply(int num) const;

    // Дружні функції вводу-виводу (за умовою Лаб 3.2 для базового класу)
    friend ostream& operator<<(ostream& out, const MatrixBase& mat);
    friend istream& operator>>(istream& in, MatrixBase& mat);
};