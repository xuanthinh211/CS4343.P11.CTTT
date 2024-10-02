// Full Name: NGUYEN XUAN THINH
// STUDENT ID: 20521967
// CLASS: CS4343.P11.CTTT

#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    Node* getHead() {
        return head;
    }

    int size() {
        int count = 0;
        Node* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }
};

std::vector<Node*> splitListIntoParts(Node* head, int k) {
    int totalSize = 0;
    Node* current = head;

    // Tính kích thước của danh sách liên kết
    while (current) {
        totalSize++;
        current = current->next;
    }

    int partSize = totalSize / k;      // Kích thước tối thiểu của mỗi phần
    int extraNodes = totalSize % k;    // Các nút thừa để phân phối

    std::vector<Node*> parts(k, nullptr);
    current = head;

    for (int i = 0; i < k; ++i) {
        Node* partHead = current; // Đầu của phần này
        Node* prev = nullptr;

        // Tính kích thước cho phần này
        int currentPartSize = partSize + (i < extraNodes ? 1 : 0);

        // Di chuyển con trỏ `current` đến cuối phần hiện tại
        for (int j = 0; j < currentPartSize && current; ++j) {
            prev = current;
            current = current->next;
        }

        // Kết thúc phần này
        if (prev) {
            prev->next = nullptr;
        }

        parts[i] = partHead; // Lưu đầu của phần này
    }

    return parts;
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    LinkedList list;
    int numElements, k;

    std::cout << "Nhập số lượng phần tử trong danh sách liên kết: ";
    std::cin >> numElements;

    std::cout << "Nhập các phần tử: " << std::endl;
    for (int i = 0; i < numElements; ++i) {
        int value;
        std::cin >> value;
        list.append(value);
    }

    std::cout << "Nhập số lượng phần k để chia danh sách: ";
    std::cin >> k;

    std::vector<Node*> parts = splitListIntoParts(list.getHead(), k);

    // In từng phần
    for (int i = 0; i < k; ++i) {
        std::cout << "Phần " << (i + 1) << ": ";
        printList(parts[i]);
    }

    return 0;
}
