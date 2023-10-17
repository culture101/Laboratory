#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int M, N;
    cout << "Введите размер массива A: ";
    cin >> M;

    cout << "Введите размер массива B: ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    cout << "Введите элементы массива A:" << endl;
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "Введите элементы массива B:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    // Создаю 3 массив который не будет иметь больше размера чем массив М
    int* C = new int[M];
    int sizeC = 0;

    // Перебиваю элементы массива А
    for (int i = 0; i < M; i++) {
        bool findB = false; // Найден ли элемент в массиве B

        // Перебираю элементы массива B и проверяю есть ли текущий элемент из A в B
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                findB = true;
                break; // Если элемент есть в B, выхожу из внутреннего цикла
            }
        }


        if (!findB) {
            C[sizeC++] = A[i];
        }
    }


    cout << "Элементы из массива A, не включенные в массив B:" << endl;
    for (int i = 0; i < sizeC; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
