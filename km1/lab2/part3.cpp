#include <vector>
#include <iostream>

#include <iostream>
#include <limits> // Для std::numeric_limits
#include <cmath>

using namespace std;


void ignoreLine() {
     cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очищаем весь буфер вплоть до символа  \n
}


int main() {
    int n;

    int mx_value = 1000;


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

    vector<int> a;


    // ввод
    for (int i = 0; i < n; ++i) {
        cout << "Введите элемент " << i + 1 << ": ";
        
        // при неудачном вводе
        while (true) {
            int x;
            cin >> x;
            ignoreLine();

            if (cin.fail() || std::abs(x) > mx_value) {
                cout << "Ошибка ввода. Повторите ввод: ";
                cin.clear();
                ignoreLine(); 

        } else {
            a.push_back(x);
            break;
            }
        }
    }

 //  for (auto i: a) {
   //     cout << i << " ";
   // }


    int s = 0; 
    bool flag = false;
    int imax = INT_MAX;
    
    // решение задачи
    for (int i = 0;i < a.size();i++) {
        if (a[i] < 0) { //  начинаем поиск в массиве
            flag = true;
            if (i == n - 1) {
                cout << "Отрицательный элемент последний в массиве." << endl;
                exit(0);
            }

            // скопировать элементы из старой структуры в новую
            vector<int> b;

            for (int j = i + 1;j < a.size();j++) {
                b.push_back(a[j]);
            }

            for (int i = 0;i < b.size();i++) {
                cout << b[i] << " ";
            }
        

            for (int j = 0; j < b.size();j++) {
                if (s > imax) {
                    cout << "Слишком большая сумма. \n";
                    cout << "Завершение программы... \n";
                    break;
                } // ???

                s += std::abs(b[j]);
            } 
            break; // как только дошли до конца - сразу выходим из внешнего цикла
        }
    }

    if (flag) {
        cout << "Сумма абсолютных значений после первого отрицательного элемента: " << s;
    } else {
        cout << "В массиве нет отрицательных элементов.";
    }
}