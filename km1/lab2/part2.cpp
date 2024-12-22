#include <iostream>
#include <forward_list>
#include <limits>
#include <map>


using namespace std;

void ignoreLine() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очищаем весь буфер вплоть до символа  \n
}


template <typename T> 
bool getInput(T& value) { 
    cin >> value; 
    if (cin.fail()) { 
        cin.clear(); 
        ignoreLine();
        return false; 
    } 
    ignoreLine();
    return true; 
} 



void printList(forward_list<int> fl) {
    if (fl.empty()) {
        cout << "Список пуст!" << endl;
        return;
    }
    for (int c: fl) {
        cout << c << " ";
    }

    cout << endl;
}

int getSize(forward_list<int> v1) {
    return distance(v1.begin(), v1.end());
}




void initializeList(forward_list<int>& v1, int n) {
    cout << endl;
    cout << endl << "Введите элементы списка: " << endl; // проверить ввод через запятую !
    int x;

   //  .end() указывает на элемент ПОСЛЕ ПОСЛЕДНЕГО

    // before_begin, before_end - удалить первый\последний

    for (int i = 0;i < n;i++) {
        cout << i+1  << "-й" << ": ";
        while (!getInput(x)) {cout << "Ошибка ввода. Повторите: " << endl;}
        if (v1.empty()) {
            v1.push_front(x);
            printList(v1);

        } else {
            auto i = v1.begin();

            // iterate throw end; 
             for (auto it = v1.begin(); it != v1.end();++it) {
                i = it;
             }

            //  тут нужен .end() и я этого не понимаю... никто это не использует
            
            i = v1.insert_after(i, x);
            //v1.push_front(x);
        }
    }
}


void insert(forward_list<int> &vl, int pos, int value) {
    auto i = vl.begin();
    if (pos == 1) {
        vl.insert_after(i, value);
        return ;
    } else if (pos == getSize(vl)) {
    for (auto it = vl.begin(); it != vl.end();++it) {
        i = it;
    }
        vl.insert_after(i, value);
        return;
    }
    i = vl.begin();

    for (int j = 0;j < pos - 1;j++) {
        ++i;
    }

    i = vl.insert_after(i, value);
}

// val - то, что хотим удвоить
int fillInTheMap(forward_list<int> fl, int val) {
    map<int, int> map;

    for (int i: fl) {
        if (map.find(i) == map.end()) { // не нашли такого ключа
            map[i] = 1;
        } else {
            map[i]++;
        }
    }

   for(auto it = map.cbegin(); it != map.cend(); ++it)
{
    if (it->first == val) {
        return it->second; // вернём количество этих элементов в мапе
    }
}

}


void doubleValues(forward_list<int> &fl, int val) {

    int i = val;

    //auto current = fl.begin(); // итератор на начало списка
     // auto end = fl.end();       // указатель на конец списка
    for (auto it = fl.begin(); it != fl.end(); ++it) {
        if (*it == val) {
            it = fl.insert_after(it, *it);
            // After inserting the duplicate, increment the iterator to skip the newly added value
        }
    }

    cout << "Удвоено!" << endl;

}


void deleteFirst(forward_list<int> &fl) {
    auto ptr = fl.before_begin();
    fl.erase_after(ptr);
    cout << "Первый элемент удалён!" << endl;
}

void freeList(forward_list<int> &fl) {
    fl.clear();
    cout << "Список успешно очищен!" << endl;
}



// увеличить кол-во с 20 до 50 ? . мб


int main() {
    forward_list<int> fl;

    char c;
    // max length of list
    int mx_list_value = 20;

    do {
        cout << "Набор операций: " << endl;
        cout << "N - Формирование списка из n эл-ов" << endl;
        cout << "V - Вставка элемента после элемента с номером №" << endl;
        cout << "F - Удвоить все вхождения эл-та E" << endl;

        cout << "D - Удаление первого элемента" << endl;
        cout << "X - Очистка списка" << endl;
        cout << "P - Вывод списка" << endl;
        cout << "E - Выход" << endl;

        cout << "Введите команду: ";

        getInput(c);

        cout << endl;
        c = toupper(c); // to upper case


        switch (c) {
        case 'N': {
            if (getSize(fl) >= 20) {
                cout << "Удалите элементы прежде чем добавлять новые!";
                break;
            }



            cout << "Введите кол-во элементов списка: " << endl;
            int n;

            while (!getInput(n) || n <= 0) {cout << "Ошибка ввода. Повторите: " << endl;}

            if ((getSize(fl) + n) > 20) {
                cout << "Нельзя добавить столько элементов!";
                break;
            }

            initializeList(fl, n);

            break;
        }

        case 'F': {

            // теперь максимальные действительно нельзя добавить, но мне нужно проверять val значения.

            int val;
        
            if (getSize(fl) == 0) {
                cout << "Пустой список!" << endl;
                break;

            }

            cout << "Введите значение: ";
            while (!getInput(val)) {cout << "Ошибка ввода. Повторите: " << endl;}
            
            int c = fillInTheMap(fl, val); // наше искомое кол-во элементов

             
             
            // не должно превосходить значение mx_list_value

            if (getSize(fl) >= 20) {
                cout << "Удалите элементы прежде чем удваивать!" << endl;
                break;
            }

            
            if ((mx_list_value - (c*2)) <= 0) { // или просто <
                cout << "Нельзя удвоить такое количество элементов!" << endl;
                break;
            } else {
                doubleValues(fl, val);
                break;
            }

        }

         case 'V': {
             int pos, val;
             if (getSize(fl) >= 20) {
                cout << "Кол-во эл-ов не может превышать 20!" << endl;
                break;
             }

             if (getSize(fl) != 0) {
                 cout << "Введите номер, ПОСЛЕ КАКОГО элемента вставить: " << endl;
                 while (!getInput(pos) || pos <= 0 || pos > getSize((fl))) {
                    cout << "Ошибка ввода позиции. Повторите: " << endl; 
                 }

                 cout << "Введите значение: " << endl;

                 while (!getInput(val)) {
                     cout << "Ошибка ввода данных. Повторите: " << endl;
                 }

                 insert(fl, pos, val);
                 break;

             } else {
                 cout << "Пустой список!" << endl;
                 break;
             }
        }
         case 'P': {
            cout << "size = " << getSize(fl) << endl;
            printList(fl);
            break;
         }

         case 'D': deleteFirst(fl); break;

         case 'X': freeList(fl); break;

         case 'E': ; break;

        default: cout << "Такой команды нет" << endl;


    }
    } while (c != 'E');

    
    return 0;
}
