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

    void printList() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void removeZeroSumSegments() {
        if (!head) return;

        Node* dummy = new Node(0); // Dummy node to handle edge cases
        dummy->next = head;
        Node* current = dummy;
        
        std::unordered_map<int, Node*> prefixSumMap; // Maps prefix sum to the last node with that sum
        int prefixSum = 0;

        while (current) {
            prefixSum += current->data;

            if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
                // Found a zero-sum segment
                Node* toRemove = prefixSumMap[prefixSum]->next; // Start removing from the next node
                int sumToRemove = prefixSum;
                while (toRemove != current) {
                    sumToRemove += toRemove->data;
                    prefixSumMap.erase(sumToRemove);
                    toRemove = toRemove->next;
                }
                prefixSumMap[prefixSum]->next = current->next; // Link the previous node to the next node
            } else {
                prefixSumMap[prefixSum] = current; // Store the current node for this prefix sum
            }
            current = current->next;
        }

        head = dummy->next; // Update head to the new list
        delete dummy; // Free dummy node
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

    list.removeZeroSumSegments();

    std::cout << "List after removing zero-sum segments: ";
    list.printList();

    return 0;
}
