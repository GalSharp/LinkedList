#include <iostream>
#include <string>

struct Exam // Структура нашего экзамена
{
	std::string name; // Имя экзамена
	std::string date; // Дата экзамена
	std::string teacher; // Фамилия преподавателя
	int num_of_grades; // Количество оценок
	int* grades = nullptr; // Оценки (массив)
};

struct Node {
    Exam data; // Данные элемента списка
    Node* next; // Указатель на следующий элемент
};

class LinkedList {

private:
    Node* head;
    // Создание списка
public: 
    LinkedList() {
        head = nullptr;
    }

    Node* createList() {
        return nullptr; // Возвращаем пустой список
    }

    // Добавление элемента в конец списка
    void append(Node** head, Exam newData) {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->next = nullptr;

        if (*head == nullptr) {
            *head = newNode;
        }
        else {
            Node* current = *head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Добавление элемента в начало списка
    void prepend(Node** head, Exam newData) {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->next = *head;
        *head = newNode;
    }

    // Удаление конечного элемента списка
    void removeLast(Node** head) {
        if (*head == nullptr) {
            return; // Список пуст
        }
        else if ((*head)->next == nullptr) {
            delete* head;
            *head = nullptr;
        }
        else {
            Node* current = *head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }

    // Удаление начального элемента списка
    void removeFirst(Node** head) {
        if (*head == nullptr) {
            return; // Список пуст
        }
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
    }

    // Поиск элемента по заданному значению поля структуры
    Node* search(Node* head, std::string targetName) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data.name == targetName) {
                return current; // Элемент найден
            }
            current = current->next;
        }

        std::cout << "Увы :( Запись не найдена" << std::endl;

        return nullptr; // Элемент не найден
    }

    // Вывод элемента списка
    void output(Node* current) {
        std::cout << "Найдена запись !!!" << std::endl
            << std::endl;

        std::cout << "Экзамен: " << current->data.name << std::endl;
        std::cout << "Дата: " << current->data.date << std::endl;
        std::cout << "Преподаватель: " << current->data.teacher << std::endl;
        std::cout << "Количество оценок: " << current->data.num_of_grades << std::endl;
        std::cout << "Оценки: ";

        for (int i = 0; i < current->data.num_of_grades; i++) {
            std::cout << current->data.grades[i] << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    // Добавление элемента после найденного
    void insertAfter(Node* prevNode, Exam newData) {
        if (prevNode == nullptr) {
            return; // Предыдущий элемент не найден
        }
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    // Удаление найденного элемента
    void remove(Node** head, Node* targetNode) {
        if (*head == nullptr || targetNode == nullptr) {
            return; // Список пуст или элемент не найден
        }
        if (*head == targetNode) {
            *head = (*head)->next;
            delete targetNode;
            return;
        }
        Node* current = *head;
        while (current->next != nullptr && current->next != targetNode) {
            current = current->next;
        }
        if (current->next == nullptr) {
            return; // Элемент не найден
        }
        current->next = targetNode->next;
        delete targetNode;
    }

    // Освобождение памяти и удаление списка
    void deleteList(Node** head) {
        Node* current = *head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        *head = nullptr;
    }

    // Отображение всего списка
    void displayList(Node* head)
    {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            std::cout << "Экзамен: " << currentNode->data.name << std::endl;
            std::cout << "Дата: " << currentNode->data.date << std::endl;
            std::cout << "Преподаватель: " << currentNode->data.teacher << std::endl;
            std::cout << "Количество оценок: " << currentNode->data.num_of_grades << std::endl;
            std::cout << "Оценки: ";
            for (int i = 0; i < currentNode->data.num_of_grades; i++) {
                std::cout << currentNode->data.grades[i] << " ";
            }
            std::cout << std::endl;
            std::cout << std::endl;
            currentNode = currentNode->next;
        }
    }
};


// Пользовательский ввод экзамена
Exam inputExam() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Exam exam;

    std::cout << "Введите название экзамена: ";
    std::getline(std::cin, exam.name);

    std::cout << "Введите дату экзамена: ";
    std::getline(std::cin, exam.date);

    std::cout << "Введите фамилию преподавателя: ";
    std::getline(std::cin, exam.teacher);

    std::cout << "Введите количество оценок: ";
    std::cin >> exam.num_of_grades;

    if (exam.num_of_grades > 0) 
    {   
        exam.grades = new int[exam.num_of_grades];
        for (int i = 0; i < exam.num_of_grades;i++) {
            std::cout << "Введите оценку: ";
            std::cin >> exam.grades[i];
        }
    }

    return exam;

}


int main()
{
    system("chcp 1251");

    LinkedList list;

    Node* head = nullptr;

    Node* temp_node;

    bool is_open = true;

    std::string temp;
    int int_temp;


    while (is_open) 
    {
        system("cls");

        std::cout << "Работа с односвязным списком (Экзамены)" << std::endl
            << std::endl
            << "Выберите операцию из предложенных: " << std::endl
            << std::endl
            << "1) Создание односвязного списка" << std::endl
            << "2) Добавление экзамена в конец списка" << std::endl
            << "3) Добавление экзамена в начало списка" << std::endl
            << "4) Удаление конечного элемента списка" << std::endl
            << "5) Удаление начального элемента списка" << std::endl
            << "6) Поиск элемента по заданому полю" << std::endl
            << "7) Добавление элемента после найденного" << std::endl
            << "8) Удаление найденного экзамена" << std::endl
            << "9) Вывод ввсего списка" << std::endl
            << std::endl
            << "10) Выход из программы" << std::endl
            << std::endl;

        std::cin >> int_temp;
        switch (int_temp) 
        {
        case 1:
            list.createList();
            std::cout << "Список создан" << std::endl;

            system("pause");
            break;
        case 2:
            system("cls");

            list.append(&head,inputExam());

            std::cout << "Запись добавлена успешно" << std::endl;

            system("pause");
            break;
        case 3:
            system("cls");

            list.prepend(&head, inputExam());

            std::cout << "Запись добавлена успешно" << std::endl;

            system("pause");
            break;
        case 4:
            system("cls");

            list.removeLast(&head);

            std::cout << "Запись удалена успешно" << std::endl;

            system("pause");
            break;
        case 5:
            system("cls");

            list.removeFirst(&head);

            std::cout << "Запись удалена успешно" << std::endl;

            system("pause");
            break;
        case 6:
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            system("cls");

            std::cout << "Ведите имя экзамена для поиска: ";   

            std::getline(std::cin,temp);

            std::cout << std::endl;

            temp_node = list.search(head, temp);

            if(temp_node != nullptr) list.output(temp_node);

            system("pause");
            break;
        case 7:
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            system("cls");

            std::cout << "Ведите имя экзамена для поиска: ";

            std::getline(std::cin, temp);

            temp_node = list.search(head, temp);

            std::cout << std::endl;

            list.insertAfter(temp_node, inputExam());

            system("pause");
            break;
        case 8:

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            system("cls");

            std::cout << "Ведите имя экзамена для поиска: ";

            std::getline(std::cin, temp);

            temp_node = list.search(head, temp);

            list.output(temp_node);

            std::cout << std::endl;

            list.remove(&head,temp_node);

            std::cout << "Запись успешно удалена" << std::endl;

            system("pause");

            break;
        case 9:
            system("cls");

            std::cout << "Экзамены:" << std::endl
                << std::endl;

            list.displayList(head);

            system("pause");
            break;
        case 10:
            is_open = false;

            std::cout << "До свидания !!!" << std::endl;

            break;
        default: 
            std::cout << "Введено неверное значение" << std::endl;
            break;
        }

    }
}


