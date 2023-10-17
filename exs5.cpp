#include <iostream>
using namespace std;

// Функция для вставки блока элементов в массив, начиная с указанного индекса
void vstavit_block(int* arr, int& size, int* block, int size_of_block, int index) {
    // Проверка на корректность индекса
    if (index >= 0 && index <= size) {
        // Проверка на переполнение
        const int maxarr = 9; // Максимальный размер массива
        if (size + size_of_block <= maxarr) {
            // Сдвигаем элементы массива, чтобы освободить место для блока
            for (int i = size - 1; i >= index; i--) {
                arr[i + size_of_block] = arr[i];
            }

            // Вставляем элементы блока в массив
            for (int i = 0; i < size_of_block; i++) {
                arr[index + i] = block[i];
            }

            // Увеличиваем размер массива
            size += size_of_block;
        }
        else {
            cout << "Ошибка: массив переполнен!" << endl;
        }
    }
    else {
        cout << "Ошибка: некорректный индекс!" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int* arr = new int[9]; // Динамический массив
    int size = 0; // Текущий размер массива

    // Добавляю элементы в массив
    arr[size++] = 1;
    arr[size++] = 2;
    arr[size++] = 3;

    // Создаю блок элементов, который хочу вставить в массив
    int* block = new int[3]; // Динамический массив для блока
    block[0] = 4;
    block[1] = 5;
    block[2] = 6;
    int sizeofblock = 3;

    // Вставляем блок начиная с индекса 1
    vstavit_block(arr, size, block, sizeofblock, 1);

    // Выводим содержимое массива
    cout << "Массив после вставки блока:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Освобождаем выделенную память
    delete[] arr;
    delete[] block;

    return 0;
}
