#include <iostream>
#include <limits> // Для std::numeric_limits
#include <cmath>

using namespace std;

void ignoreLine() {
     cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очищаем весь буфер вплоть до символа  \n
}


int main() {
    int n;


    cout << "Введите количество элементов в массиве: ";

    while (true) {
        cin >> n;

        // Проверка на ввод целого числа
         if (cin.fail() || n <= 0 || n > 20) {
             cout << "Ошибка ввода. Пожалуйста, введите положительное число(ограничение на размер = 20): ";
             cin.clear(); // Очищаем статус потока
             ignoreLine();
         } 
        else {
            ignoreLine();
            break; // Выход из цикла, если ввод корректен
        }
    }

    // Создаем массив заданного размера
    int* arr = new int[n];


    // ввод
    for (int i = 0; i < n; ++i) {
        cout << "Введите элемент " << i + 1 << ": ";
        
        // при неудачном вводе
        while (true) {
            cin >> arr[i];
            ignoreLine();

            if (cin.fail()) {
                cout << "Ошибка ввода. Повторите ввод: ";
                cin.clear();
                ignoreLine(); 

        } else {
            break;
            }
        }
    }



    // вывод
    cout << "Введенные элементы массива: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int s = 0; 
    bool flag = false;
    int imax = INT_MAX;
    
    // решение задачи
    for (int i = 0;i < n;i++) {
        if (arr[i] < 0) { //  начинаем поиск в массиве

            if (i == n - 1) {
                cout << "Отрицательный элемент последний в массиве." << endl;
                cout << "Завершаем работу." << endl;
                exit(0);
            }

            flag = true;
            for (int j = i + 1;j < n;j++) {
                if (s > imax) {
                    cout << "Слишком большая сумма. \n";
                    cout << "Завершение программы... \n";
                    break;
                } // ???

                s += std::abs(arr[j]);
            } 
            break; // как только дошли до конца - сразу выходим из внешнего цикла
        }
    }

    if (flag) {
        cout << "Сумма абсолютных значений после первого отрицательного элемента: " << s;
    } else {
        cout << "В массиве нет отрицательных элементов.";
    }
    

    // Освобождение памяти
    delete[] arr;

    return 0;
}
