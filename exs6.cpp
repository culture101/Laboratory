#include <iostream>
using namespace std;

// Функция для удаления блока элементов из массива, начиная с указанного индекса
void udalit_block(int* arr, int& size, int size_of_block, int index) {
    // Проверка на корректность индекса
    if (index >= 0 && index < size) {
        // Проверяю на корректность размера блока
        if (size_of_block >= 0 && index + size_of_block <= size) {
            // Сдвигаю элементы массива, чтобы удалить блок
            for (int i = index + size_of_block; i < size; i++) {
                arr[i - size_of_block] = arr[i];
            }

            // Уменьшаю размер массива
            size -= size_of_block;
        }
        else {
            cout << "Ошибка: некорректный размер блока!" << endl;
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
    arr[size++] = 2;
    arr[size++] = 4;
    arr[size++] = 6;

    // Создаем блок элементов, которые мы хотим удалить
    int index_to_delete = 1;
    int sizeofblock = 2;

    // Удаляем блок начиная с индекса 1
    udalit_block(arr, size, sizeofblock, index_to_delete);

    // Вывожу содержимое массива
    cout << "Массив после удаления блока:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Освобождаю выделенную память
    delete[] arr;

    return 0;
}
