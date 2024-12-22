#include <iostream>
#include <limits>


using namespace std;


// очищение статуса потока и буфера
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

struct Node {
	int data;
	Node* next;
};


int getLength(Node* head) {
    int c = 0;

    while (head != nullptr) {
        c++;
        head = head->next;
    }
    return c;
}


Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    return newNode;
}


void doubleValues(Node*& head, int data) { 
    Node* current = head; 
    bool f = false;
    if (getLength(head) > 100) {
        cout << "Удалите элементы прежде чем добавлять новые!";
        return;
    }

    while (current != nullptr) { 
        if (current->data == data) { 
            Node* newNode = createNode(data); 
            newNode->next = current->next; 
            current->next = newNode; 
            current = newNode->next; 
            f = true;
        } else { 
            current = current->next; 
        } 
    }

    if (!f) {
        cout << "Значение не найдено!" << endl;
    } else {
        cout << "Успешно!" << endl;
    }
} 

bool isEmpty(Node* head) {return head == nullptr;}


void initializeList(Node*& head, int n) {
    if (getLength(head) > 100) {
        cout << "Удалите элементы прежде чем добавлять новые!";
        return;
    }
    cout << endl;
    cout << endl << "Введите элементы стека: " << endl; // проверить ввод через запятую !
    int x;
    for (int i = 0;i < n;i++) {
        cout << i+1  << "-й" << ": ";
        while (!getInput(x)) {cout << "Ошибка ввода. Повторите: " << endl;}
        if (head == nullptr) {
            head = createNode(x);
        } else {
            Node* tmp = head;
            while (tmp->next != nullptr) {
                tmp = tmp->next;
            }
            tmp->next = createNode(x); // or maybe tmp->next = createNode(x) ? 
        }
    }
}



void insert(Node*& head, int pos, int val) { 
    if (getLength(head) > 100) {
        cout << "Удалите элементы прежде чем добавлять новые!";
        return;
    }

    if (pos <= 0) { 
        cout << "Позиция должна быть положительным числом!" << endl; 
        return; 
    } 

    
 
    Node* temp = head; 
    for (int i = 1; temp != nullptr && i < pos; i++) { 
        temp = temp->next; 
    } 
    if (temp != nullptr) { 
        Node* newNode = createNode(val); 
        newNode->next = temp->next; 
        temp->next = newNode; 
    } else { 
        cout << "Позиция выходит за границы списка!" << endl; 
    }
} 



void deleteFirst(Node*& head) { 
    if (head != nullptr) { 
        Node* temp = head; 
        head = head->next; 
        delete temp; 
        cout << "Удалено!";
    } else { 
        cout << "Список пуст!" << endl; 
    } 
} 


void freeList(Node*& head) { 
    if (head == nullptr) {
        cout << "Пустой список!";
        return;
    }

    while (head != nullptr) { 
        Node* temp = head; 
        head = head->next; 
        delete temp; 
    } 

    cout << "Успешно очищено!";
} 


void printList(Node* head) { 
    if (head == nullptr) { 
        cout << "Список пуст!" << endl; 
        return; 
    } 
 
    Node* temp = head; 
    while (temp != nullptr) { 
        cout << temp->data << " "; 
        temp = temp->next; 
    } 
    cout << endl; 
} 




int main(int argc, char const *argv[])
{

    char c;
    Node* head = nullptr;


    do {
        cout << "Набор операций: " << endl;
        cout << "N - Формирование списка из n эл-ов" << endl;
        cout << "V - Вставка элемента после элемента с номером №" << endl;
        cout << "F - удвоить все вхождения эл-та E" << endl;

        cout << "D - Удаление первого элемента" << endl;
        cout << "X - Очистка списка" << endl;
        cout << "P - Вывод списка" << endl;
        cout << "E - Выход" << endl;

        cout << "Введите команду: ";

        getInput(c);

        cout << endl;
        c = toupper(c); // to upper case

        switch(c) {
        case 'N': {
            cout << "Введите кол-во элементов списка: " << endl;
            int n;

            while (!getInput(n) || n <= 0) {cout << "Ошибка ввода. Повторите: " << endl;}

            initializeList(head, n);

            break;
        }

        case 'F': {
            int val;
            if (isEmpty(head)) {
                cout << "Пустой список!" << endl;
                break;
            } else {
                cout << "Введите значение: ";
                while (!getInput(val)) {cout << "Ошибка ввода. Повторите: " << endl;}

                doubleValues(head, val);
                break;
            }
        }

        case 'V': {
            int pos, val;
            if (!isEmpty(head)) {
                cout << "Введите номер, ПЕРЕД КАКИМ элементом вставить: " << endl;
                while (!getInput(pos) || pos <= 0 || pos > getLength(head)) {
                    cout << "Ошибка ввода позиции. Повторите: " << endl; 
                }

                cout << "Введите значение: " << endl;

                while (!getInput(val)) {
                    cout << "Ошибка ввода данных. Повторите: " << endl;
                }

                insert(head, pos, val);
            } else {
                cout << "Пустой список!" << endl;
                break;
            }
        }
        case 'P': printList(head); break;

        case 'D': deleteFirst(head); break;

        case 'X': freeList(head); break;

        case 'E': ; break;

        default: cout << "Такой команды нет" << endl;


    }
    } while (c != 'E');

    
    return 0;
}
