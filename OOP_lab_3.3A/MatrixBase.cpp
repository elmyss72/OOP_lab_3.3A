#include "MatrixBase.h"
#include <sstream>
#include <stdexcept>

// Реалізація виділення та очищення пам'яті
void MatrixBase::allocate() {
    if (m != nullptr) {
        deallocate();
    }
    m = new int* [R];
    for (int i = 0; i < R; ++i) {
        m[i] = new int[C] {0};
    }
}

void MatrixBase::deallocate() {
    if (m != nullptr) {
        for (int i = 0; i < R; ++i) {
            delete[] m[i];
        }
        delete[] m;
        m = nullptr;
    }
}

// Сетери з контролем аргументів
void MatrixBase::setR(int r) {
    if (r > 0) R = r;
    else R = 1;
}

void MatrixBase::setC(int c) {
    if (c > 0) C = c;
    else C = 1;
}

void MatrixBase::setM(int i, int j, int val) {
    if (i >= 0 && i < R && j >= 0 && j < C) {
        m[i][j] = val;
    }
}

// Геттери
int MatrixBase::getR() const { return R; }
int MatrixBase::getC() const { return C; }
int MatrixBase::getM(int i, int j) const {
    if (i >= 0 && i < R && j >= 0 && j < C) {
        return m[i][j];
    }
    return 0;
}

// Конструктор без аргументів (звертається безпосередньо до сетерів)
MatrixBase::MatrixBase() {
    m = nullptr;
    setR(1);
    setC(1);
    allocate();
    setM(0, 0, 0);
}

// Конструктор ініціалізації
MatrixBase::MatrixBase(int r, int c) {
    m = nullptr;
    setR(r); // Пряме використання сетерів
    setC(c);
    allocate();
    for (int i = 0; i < getR(); ++i) {
        for (int j = 0; j < getC(); ++j) {
            setM(i, j, 0);
        }
    }
}

// Конструктор копіювання
MatrixBase::MatrixBase(const MatrixBase& other) {
    m = nullptr;
    setR(other.getR());
    setC(other.getC());
    allocate();
    for (int i = 0; i < getR(); ++i) {
        for (int j = 0; j < getC(); ++j) {
            setM(i, j, other.getM(i, j));
        }
    }
}

MatrixBase::~MatrixBase() {
    deallocate();
}

void MatrixBase::Init(int r, int c) {
    // ВИПРАВЛЕННЯ: Спочатку очищаємо стару пам'ять, поки R та C ще старі!
    deallocate();

    // Тепер безпечно встановлюємо нові розміри
    setR(r);
    setC(c);

    // Виділяємо нову пам'ять (m тут уже nullptr, тому помилки не буде)
    allocate();

    // Заповнюємо нулями
    for (int i = 0; i < getR(); ++i) {
        for (int j = 0; j < getC(); ++j) {
            setM(i, j, 0);
        }
    }
}

void MatrixBase::Read() {
    int r, c, val;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of cols: ";
    cin >> c;
    Init(r, c);

    for (int i = 0; i < getR(); ++i) {
        for (int j = 0; j < getC(); ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> val;
            setM(i, j, val);
        }
    }
}

void MatrixBase::Display() const {
    cout << "Matrix (" << getR() << "x" << getC() << "):\n";
    for (int i = 0; i < getR(); ++i) {
        for (int j = 0; j < getC(); ++j) {
            // Використання методів доступу (геттерів) для операції виводу згідно вимог
            cout << getM(i, j) << "\t";
        }
        cout << "\n";
    }
}

string MatrixBase::toString() const {
    stringstream ss;
    for (int i = 0; i < getR(); ++i) {
        for (int j = 0; j < getC(); ++j) {
            ss << getM(i, j) << "\t"; // Змінено пробіл на табуляцію для рівних відступів
        }
        ss << "\n";
    }
    return ss.str();
}

int MatrixBase::Element(int i, int j) const {
    return getM(i, j);
}

// Математичні операції
MatrixBase MatrixBase::Add(const MatrixBase& other) const {
    MatrixBase res(getR(), getC());
    if (getR() != other.getR() || getC() != other.getC()) {
        cout << "Error: Matrix dimensions mismatch for addition.\n";
        return res;
    }
    for (int i = 0; i < getR(); ++i) {
        for (int j = 0; j < getC(); ++j) {
            res.setM(i, j, getM(i, j) + other.getM(i, j));
        }
    }
    return res;
}

MatrixBase MatrixBase::Subtract(const MatrixBase& other) const {
    MatrixBase res(getR(), getC());
    if (getR() != other.getR() || getC() != other.getC()) {
        cout << "Error: Matrix dimensions mismatch for subtraction.\n";
        return res;
    }
    for (int i = 0; i < getR(); ++i) {
        for (int j = 0; j < getC(); ++j) {
            res.setM(i, j, getM(i, j) - other.getM(i, j));
        }
    }
    return res;
}

MatrixBase MatrixBase::Multiply(const MatrixBase& other) const {
    if (getC() != other.getR()) {
        cout << "Error: Matrix dimensions mismatch for multiplication.\n";
        return MatrixBase(1, 1);
    }
    MatrixBase res(getR(), other.getC());
    for (int i = 0; i < getR(); ++i) {
        for (int j = 0; j < other.getC(); ++j) {
            int sum = 0;
            for (int k = 0; k < getC(); ++k) {
                sum += getM(i, k) * other.getM(k, j);
            }
            res.setM(i, j, sum);
        }
    }
    return res;
}

MatrixBase MatrixBase::Multiply(int num) const {
    MatrixBase res(getR(), getC());
    for (int i = 0; i < getR(); ++i) {
        for (int j = 0; j < getC(); ++j) {
            res.setM(i, j, getM(i, j) * num);
        }
    }
    return res;
}

// Перевантаження вводу-виводу для базового класу
ostream& operator<<(ostream& out, const MatrixBase& mat) {
    out << "Matrix Output:\n";
    for (int i = 0; i < mat.getR(); ++i) {
        for (int j = 0; j < mat.getC(); ++j) {
            // Звернення до елементів виключно через геттери
            out << mat.getM(i, j) << "\t";
        }
        out << "\n";
    }
    return out;
}

istream& operator>>(istream& in, MatrixBase& mat) {
    int r, c, val;
    cout << "Rows: "; in >> r;
    cout << "Cols: "; in >> c;
    mat.Init(r, c); // Init викликає сетери та перестворює масив
    for (int i = 0; i < mat.getR(); ++i) {
        for (int j = 0; j < mat.getC(); ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            in >> val;
            mat.setM(i, j, val); // Пряме звернення до сетерів під час вводу
        }
    }
    return in;
}