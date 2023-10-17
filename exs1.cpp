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

    int maxSize = (M < N) ? M : N; // "?:" Условный оператор для определния значения переменной maxsize
    int* C = new int[maxSize];
    int sizeC = 0; //предположения что в начале (до итераций в каждом массиве) нет общих элементов и следовательно = 0

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                C[sizeC++] = A[i]; //Если есть общие элементы между А и B, то добавляю элемент из А в С. С++ увеличивает на 1
                break; // Выходим из цикла
            }
        }
    }

    cout << "Общие элементы без повторений:" << endl;
    for (int i = 0; i < sizeC; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
