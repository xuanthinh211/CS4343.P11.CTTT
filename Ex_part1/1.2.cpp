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

    void createCycle(int pos) {
        if (pos < 0) return; // No cycle
        
        Node* temp = head;
        Node* cycleNode = nullptr;
        int count = 0;

        while (temp->next) {
            if (count == pos) {
                cycleNode = temp; // Node where cycle starts
            }
            temp = temp->next;
            count++;
        }
        
        if (cycleNode) {
            temp->next = cycleNode; // Create cycle
        }
    }

    bool hasCycle() {
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next; // Move slow by 1
            fast = fast->next->next; // Move fast by 2

            if (slow == fast) {
                return true; // Cycle detected
            }
        }
        return false; // No cycle
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

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter " << n << " elements:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        list.insert(value);
    }

    // Option to create a cycle for testing
    int cyclePos;
    std::cout << "Enter the position (0-indexed) to create a cycle (or -1 for no cycle): ";
    std::cin >> cyclePos;
    list.createCycle(cyclePos);

    if (list.hasCycle()) {
        std::cout << "Cycle detected in the linked list." << std::endl;
    } else {
        std::cout << "No cycle detected in the linked list." << std::endl;
    }

    return 0;
}
