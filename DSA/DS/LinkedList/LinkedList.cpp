#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node* next;
};

class LinkedList
{
private: 
    Node *head;
public:
    // Hàm khởi tạo danh sách liên kết rỗng.
    LinkedList();
    // Hàm khởi tạo danh sách liên kết từ một mảng a có n phần tử.
    LinkedList(int a[], int n);
    // Hàm chèn một node có giá trị value vào đầu danh sách liên kết.
    void insertHead(int value);
    // Hàm in các phần tử của danh sách liên kết lên màn hình, cách nhau bởi dấu cách.
    void print();
};

LinkedList::LinkedList() 
{
    head = NULL;
}

LinkedList::LinkedList(int a[], int n) 
{
    head = NULL;
    for (int i = n-1; i >= 0; i--)
        LinkedList::insertHead(a[i]);
}

void LinkedList::insertHead(int value)
{
    Node* insertnode = new Node;
    insertnode->value = value;
    insertnode->next = head;
    head = insertnode;
}

void LinkedList::print()
{
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
}

int main() {
    int a[] = {4, 1, 5};
    LinkedList list(a, 3);
    list.print();  
    return 0;
}