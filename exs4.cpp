#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int maxarr = 6; // Max размер массива
    int* arr = new int[maxarr]; // Динамический массив
    int size = 0; // Текущий размер массива

    // Добавляю элементы в массив
    arr[size++] = 1;
    arr[size++] = 2;
    arr[size++] = 3;


    // Создаю блок элементов, который нужно затем добавить в массив
    int* block = new int[3]; // Динамический массив для блока
    block[0] = 4;
    block[1] = 5;
    block[2] = 6;
    int sizeofblock = 3;

    // Проверка на переполнение
    if (size + sizeofblock <= maxarr) {
        // Копируем элементы блока в конец массива
        for (int i = 0; i < sizeofblock; i++) {
            arr[size + i] = block[i];
        }
        // Увеличиваем размер массива
        size += sizeofblock;
    }
    else {
        cout << "Ошибка: массив переполнен!" << endl;
    }

    // Выводим содержимое массива
    cout << "Массив после добавления блока:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Освобождаем выделенную память
    delete[] arr;
    delete[] block;

    return 0;
}
