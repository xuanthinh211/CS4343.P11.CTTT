// Full Name: NGUYEN XUAN THINH
// STUDENT ID: 20521967
// CLASS: CS4343.P11.CTTT

#include <iostream>
#include <unordered_map>

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

    void removeZeroSumConsecutives() {
        std::unordered_map<int, Node*> prefixSumMap;
        Node* dummy = new Node(0);  // Create a dummy node to handle edge cases
        dummy->next = head;
        Node* current = dummy;
        int prefixSum = 0;

        while (current) {
            prefixSum += current->data;

            // Check if this prefixSum has been seen before
            if (prefixSumMap.count(prefixSum)) {
                Node* nodeToDelete = prefixSumMap[prefixSum]->next; // Start from the next node
                int sumToRemove = prefixSum;
                
                // Remove nodes until we reach the current node
                while (nodeToDelete != current) {
                    sumToRemove += nodeToDelete->data;
                    prefixSumMap.erase(sumToRemove); // Erase from map
                    nodeToDelete = nodeToDelete->next;
                }

                // Link the previous node to the current node
                prefixSumMap[prefixSum]->next = current->next;
            } else {
                prefixSumMap[prefixSum] = current;
            }

            current = current->next;
        }

        head = dummy->next;  // Update head
        delete dummy;  // Clean up dummy node
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }
};

int main() {
    LinkedList list;
    int n, value;

    std::cout << "Enter the number of nodes in the linked list: ";
    std::cin >> n;

    std::cout << "Enter the values for the nodes:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        list.insert(value);
    }

    std::cout << "Original Linked List:\n";
    list.printList();

    list.removeZeroSumConsecutives();

    std::cout << "Linked List after removing zero-sum consecutive nodes:\n";
    list.printList();

    return 0;
}
