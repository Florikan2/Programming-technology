#include <iostream>
#include <list>

using namespace std;

struct Node 
{
string name;
int age;
double salary;
Node* next;
};

class LinkedList 
{
private:
Node* head;
public:
LinkedList() {
head = NULL;
}
// Добавление элемента в начало списка
void add_to_begin(string name, int age, double salary)
{
Node* new_node = new Node;
new_node->name = name;
new_node->age = age;
new_node->salary = salary;
new_node->next = head;
head = new_node;
}
// Добавление элемента в конец списка
void add_to_end(string name, int age, double salary) 
{
Node* new_node = new Node;
new_node->name = name;
new_node->age = age;
new_node->salary = salary;
new_node->next = NULL;
if (head == NULL) 
{
head = new_node;
}
else
{
Node* current = head;
while (current->next != NULL)
{
current = current->next;
}
current->next = new_node;
}
}
// Добавление элемента после заданного элемента
void add_after(string name, int age, double salary, string after_name)
{
Node* new_node = new Node;
new_node->name = name;
new_node->age = age;
new_node->salary = salary;
Node* current = head;
while (current != NULL && current->name != after_name)
{
current = current->next;
}
if (current != NULL)
{
new_node->next = current->next;
current->next = new_node;
}
else 
{
cout << "Element not found!" << endl;
}
}
// Добавление элемента перед заданным элементом
void add_before(string name, int age, double salary, string before_name)
{
Node* new_node = new Node;
new_node->name = name;
new_node->age = age;
new_node->salary = salary;
if (head == NULL)
{
head = new_node;
} 
else if (head->name == before_name) 
{
new_node->next = head;
head = new_node;
} else {
Node* current = head;
while (current->next != NULL && current->next->name != before_name) {
current = current->next;
}
if (current->next != NULL) {
new_node->next = current->next;
current->next = new_node;
} else {
cout << "Element not found!" << endl;
}
}
}
// Удаление элемента с заданным именем
void remove(string name) 
{
if (head == NULL) {
return;
} else if (head->name == name)
{
Node* temp = head;
head = head->next;
delete temp;
}
else
{
Node* current = head;
while (current->next != NULL && current->next->name != name) 
{
current = current->next;
}
if (current->next != NULL) 
{
Node* temp = current->next;
current->next = temp->next;
delete temp;
}
else
{
cout << "Element not found!" << endl;
}
}
}
// Вывод содержания списка на экран
void print()
{
if (head == NULL)
{
cout << "List is empty!" << endl;
return;
}
Node* current = head;
while (current != NULL)
{
cout << "Name: " << current->name << " Age: " << current->age << " Salary: " << current->salary << endl;
current = current->next;
}
}
};

int main()
{
LinkedList list;

return 0;
}