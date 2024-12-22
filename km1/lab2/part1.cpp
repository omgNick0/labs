#include <queue>
#include <limits>
#include <iostream>
#include <stack>


using namespace std;

void ignoreLine() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очищаем весь буфер вплоть до символа  \n
}

int getSize(queue<int> q) {
    return q.size();
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

void initializeQueue(queue<int> &q, int n) {
    cout << endl;
    cout << "Введите элементы очереди: " << endl;

    int x; // то число, которое будем вводить

    for (int i = 0;i < n;i++) {
        cout << i+1 << "-й" << endl;
        while (!getInput(x)) {cout << "Ошибка ввода. Повторите: " << endl;}

        q.push(x);
    }
}

void printQueue(queue<int> &q) {
    queue<int> q2; // временная очередь
    while (!q.empty()) {
        int val = q.front();
        cout << val << " ";
        q2.push(val);
        q.pop();
    }
    cout << endl;
    // вернуть обратно в элементы по порядку в queue
    q2.swap(q);
}

void queueToStack(stack<int> &st, queue<int> &q) {
    while (!q.empty()) {
        int val = q.front();
        st.push(val);
        q.pop();
    }

    cout << "Преобразовано!" << endl;
}

void printStack(stack<int> st) {
  //  stack<int> s2;

    while (!st.empty()) {
        int v = st.top();
        cout << v << " ";
       // s2.push(v);
        st.pop();
    }

    //st.swap(s2);
    cout << endl;
}

void deleteStack(stack<int> &st) {
    while (!st.empty()) {
        st.pop();
    }

    cout << "Стек очищен!" << endl;
}


// очередь - стек

// stack - LIFO
// queue - FIFO

int main() {
    queue<int> q;
    stack<int> st;

    char c;
    // max length of list
    int mx_list_value = 20;

    do {
        cout << "Набор операций: " << endl;
        cout << "W - Добавление элемента в очередь" << endl;
        cout << "R - Удаление верхнего элемента из очереди" << endl;
        cout << "T - Очистка очереди" << endl;
        cout << "P - Просмотр очереди" << endl;
        cout << "Y - Преобразовать в стек" << endl;


        cout << "U - Просмотр стека" << endl;
        cout << "I - Удалить стек" << endl;
        cout << "E - Выход" << endl;

        cout << "Введите команду: ";

        getInput(c);

        cout << endl;
        c = toupper(c); // to upper case

        switch(c) {
            case 'W': {
                cout << "Введите кол-во элементов очереди: " << endl;
                int n;

                while (!getInput(n) || n <= 0) {cout << "Ошибка ввода. Повторите: " << endl;}

                if ((getSize(q) + n) > mx_list_value) {
                    cout << "Нельзя добавить столько элементов!";
                    break;
                }

                initializeQueue(q, n);
                break;
            }

            case 'R': {
                if (getSize(q) == 0) {
                    cout << "Очередь пуста!" <<  endl;
                    break;

                }
                int val = q.front();
                q.pop();
                cout << "Удалено: " << val << endl;
                break;
            }

            case 'T': {
                if (getSize(q) == 0) {
                    cout << "Очищать нечего. Очередь пуста!" << endl;
                    break;
                }
                while (!q.empty()) {
                    q.pop();
                }
                cout << "Очередь очищена!" << endl;
                break;
            }

            case 'P': {
                if (getSize(q) == 0) {
                    cout << "Пустая очередь!" << endl;
                    break;
                }
                printQueue(q);
                break;
            }

            case 'Y': {
                // преобразовать в стек
                if (getSize(q) == 0) {
                    cout << "Пустая очередь!" << endl;
                    break;
                }

                queueToStack(st, q);
                break;

            }

            case 'U': {
                if (st.empty()) {
                    cout << "Стек пуст!" << endl;
                    break;
                }
                printStack(st);
                break;
            }

            case 'I': {
                if (st.empty()) {
                    cout << "Стек пуст. Удалять нечего." << endl;
                    break;
                }
                deleteStack(st);
                break;
            }
            case 'E': break;


            default: {
                cout << "Такой команды нет!" << endl;
                break;
                }
            }
    } while (c != 'E');

    return 0;
}
