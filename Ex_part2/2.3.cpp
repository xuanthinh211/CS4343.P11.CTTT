// Full Name: NGUYEN XUAN THINH
// STUDENT ID: 20521967
// CLASS: CS4343.P11.CTTT

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void swapNodes(int x, int y) {
        if (x == y) return;

        Node *prevX = nullptr, *currX = head;
        while (currX && currX->data != x) {
            prevX = currX;
            currX = currX->next;
        }

        Node *prevY = nullptr, *currY = head;
        while (currY && currY->data != y) {
            prevY = currY;
            currY = currY->next;
        }

        if (!currX || !currY) return;

        // Swap prev pointers
        if (prevX) {
            prevX->next = currY;
        } else {
            head = currY;
        }

        if (prevY) {
            prevY->next = currX;
        } else {
            head = currX;
        }

        // Swap next pointers
        Node* temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;
    }
};

int main() {
    LinkedList list;
    int n, value;

    std::cout << "Enter the number of nodes: ";
    std::cin >> n;

    std::cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        std::cin >> value;
        list.insert(value);
    }

    std::cout << "Current list: ";
    list.printList();

    int x, y;
    std::cout << "Enter two values of nodes to swap: ";
    std::cin >> x >> y;

    list.swapNodes(x, y);

    std::cout << "List after swapping: ";
    list.printList();

    return 0;
}
