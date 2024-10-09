// STT:02
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
private:
    Node* head;
    
public:
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

    void findMiddle() {
        if (!head) {
            std::cout << "The list is empty." << std::endl;
            return;
        }

        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;

        while (fast && fast->next) {
            prev = slow; // Keep track of the previous node
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast == nullptr) {
            // Even number of nodes
            std::cout << "The two middle nodes are: " 
                      << prev->data << " and " << slow->data << std::endl;
        } else {
            // Odd number of nodes
            std::cout << "The middle node is: " << slow->data << std::endl;
        }
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    LinkedList list;
    int n, value;

    std::cout << "\nEnter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter " << n << " elements:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        list.insert(value);
    }

    list.findMiddle();

    return 0;
}
