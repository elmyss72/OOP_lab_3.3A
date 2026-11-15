#include "MatrixPublic.h"
#include "MatrixPrivate.h"
#include <iostream>

using namespace std;

// Структура для демонстрації #pragma pack(1)
#pragma pack(push, 1)
class MatrixPacked {
    int** m;
    int R;
    int C;
};
#pragma pack(pop)

// Функція, що повертає та одержує базовий клас (демонстрація підстановки)
MatrixBase ProcessMatrix(MatrixBase mat) {
    cout << "Processing matrix in function (substitution check)...\n";
    return mat.Multiply(2);
}

int main() {
    cout << "=== Memory Alignment Info ===" << endl;
    cout << "Size of MatrixBase without #pragma pack(1): " << sizeof(MatrixBase) << " bytes" << endl;
    cout << "Size of MatrixPacked with #pragma pack(1): " << sizeof(MatrixPacked) << " bytes" << endl;
    cout << "=============================\n\n";

    // Тестування відкритого нащадка
    cout << "--- Public Inheritance Test ---" << endl;
    MatrixPublic pubMat1;

    cout << "Введіть дані для pubMat1:\n";
    cin >> pubMat1; // Користувач вводить розміри та елементи самостійно

    MatrixPublic pubMat2;
    pubMat2 = pubMat1;    // Перевантажений оператор =

    pubMat2++; // Перевантажений постфіксний інкремент

    cout << "\npubMat1:\n" << pubMat1 << endl;
    cout << "pubMat2 (after ++):\n" << pubMat2 << endl;

    MatrixPublic pubResult = pubMat1 + pubMat2;
    cout << "Result of pubMat1 + pubMat2:\n" << pubResult << endl;

    // Принцип підстановки працює для Public нащадка
    MatrixBase baseResult = ProcessMatrix(pubResult);
    cout << "After processing:\n" << baseResult << endl;

    // Тестування закритого нащадка
    cout << "--- Private Inheritance Test ---" << endl;
    MatrixPrivate privMat1;

    cout << "Enter data privMat1:\n";
    cin >> privMat1; // Користувач вводить розміри та елементи самостійно

    // Перевірка перевантаженого вводу/виводу
    cout << "\nprivMat1 initialized:\n" << privMat1 << endl;

    --privMat1; // Перевантажений декремент
    cout << "privMat1 after --:\n" << (string)privMat1 << endl; // Перевірка касту в string (відступи тепер рівні)

    MatrixPrivate privMat2 = privMat1 * 2;
    cout << "privMat1 * 2:\n" << privMat2 << endl;

    return 0;
}