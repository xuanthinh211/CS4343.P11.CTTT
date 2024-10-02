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

    void separateOddAndEvenValues() {
        if (!head || !head->next) return;

        Node* oddHead = nullptr; // Head of odd valued nodes
        Node* evenHead = nullptr; // Head of even valued nodes

        Node* oddCurrent = nullptr;
        Node* evenCurrent = nullptr;

        Node* current = head;

        while (current) {
            if (current->data % 2 != 0) { // Odd value
                if (!oddHead) {
                    oddHead = oddCurrent = current;
                } else {
                    oddCurrent->next = current;
                    oddCurrent = oddCurrent->next;
                }
            } else { // Even value
                if (!evenHead) {
                    evenHead = evenCurrent = current;
                } else {
                    evenCurrent->next = current;
                    evenCurrent = evenCurrent->next;
                }
            }
            current = current->next;
        }

        if (oddCurrent) oddCurrent->next = evenHead; // Connect the last odd to the head of even
        if (evenCurrent) evenCurrent->next = nullptr; // End the even list

        head = oddHead ? oddHead : evenHead; // Update head to the new list
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

    list.separateOddAndEvenValues();

    std::cout << "List after separating odd and even values: ";
    list.printList();

    return 0;
}
