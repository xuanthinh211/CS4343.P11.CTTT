#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <bitset>
#include <stack>
#include <climits>
#include <algorithm>  


// 1. File System Tree
class FileSystemNode {
public:
    std::string name;
    bool is_directory;
    std::vector<FileSystemNode*> children;

    FileSystemNode(std::string name, bool is_directory) : name(name), is_directory(is_directory) {}

    void add_child(FileSystemNode* node) {
        if (is_directory) {
            children.push_back(node);
        }
    }

    void remove_child(const std::string& name) {
        if (is_directory) {
            for (auto it = children.begin(); it != children.end(); ++it) {
                if ((*it)->name == name) {
                    children.erase(it);
                    break;
                }
            }
        }
    }
};

class FileSystem {
public:
    FileSystemNode* root;

    FileSystem() {
        root = new FileSystemNode("root", true);
    }

    FileSystemNode* find_node(const std::string& path, FileSystemNode* node = nullptr) {
        node = node ? node : root;
        if (path == node->name) {
            return node;
        }
        for (auto child : node->children) {
            FileSystemNode* result = find_node(path, child);
            if (result) return result;
        }
        return nullptr;
    }

    void create(const std::string& path, bool is_directory) {
        size_t pos = path.find_last_of('/');
        std::string parent_path = path.substr(0, pos);
        std::string name = path.substr(pos + 1);

        FileSystemNode* parent = find_node(parent_path);
        if (parent && parent->is_directory) {
            parent->add_child(new FileSystemNode(name, is_directory));
        }
    }

    void remove(const std::string& path) {
        size_t pos = path.find_last_of('/');
        std::string parent_path = path.substr(0, pos);
        std::string name = path.substr(pos + 1);

        FileSystemNode* parent = find_node(parent_path);
        if (parent && parent->is_directory) {
            parent->remove_child(name);
        }
    }
};

// 2. XML/HTML Parser
class XMLParser {
public:
    // Dummy implementation, can use actual XML parsing libraries like TinyXML2
    std::unordered_map<std::string, std::vector<std::string>> elements;

    void parse(const std::string& xml_data) {
        // Placeholder: This should parse the XML into a tree structure
        elements["child"] = {"item1", "item2"};
    }

    std::vector<std::string> find_elements(const std::string& tag) {
        return elements[tag];
    }

    std::vector<std::string> find_attribute(const std::string& tag, const std::string& attribute) {
        return elements[tag];  // Placeholder
    }
};

// 3. Huffman Coding
class HuffmanNode {
public:
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}

    bool operator>(const HuffmanNode& other) const {
        return freq > other.freq;
    }
};

class HuffmanTree {
public:
    HuffmanNode* build_tree(const std::string& data) {
        std::unordered_map<char, int> freq_map;
        for (char c : data) {
            freq_map[c]++;
        }

        std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, std::greater<HuffmanNode*>> min_heap;
        for (auto& pair : freq_map) {
            min_heap.push(new HuffmanNode(pair.first, pair.second));
        }

        while (min_heap.size() > 1) {
            HuffmanNode* left = min_heap.top(); min_heap.pop();
            HuffmanNode* right = min_heap.top(); min_heap.pop();
            HuffmanNode* merged = new HuffmanNode('\0', left->freq + right->freq);
            merged->left = left;
            merged->right = right;
            min_heap.push(merged);
        }

        return min_heap.top();
    }

    void generate_codes(HuffmanNode* root, std::unordered_map<char, std::string>& codebook, std::string code = "") {
        if (!root) return;
        if (root->data != '\0') {
            codebook[root->data] = code;
        }
        generate_codes(root->left, codebook, code + "0");
        generate_codes(root->right, codebook, code + "1");
    }

    std::string encode(const std::string& data, const std::unordered_map<char, std::string>& codebook) {
        std::string encoded = "";
        for (char c : data) {
            encoded += codebook.at(c);
        }
        return encoded;
    }

    std::string decode(const std::string& encoded_data, HuffmanNode* root) {
        std::string decoded = "";
        HuffmanNode* node = root;
        for (char c : encoded_data) {
            node = (c == '0') ? node->left : node->right;
            if (node->data != '\0') {
                decoded += node->data;
                node = root;
            }
        }
        return decoded;
    }
};

// 4. Tic-Tac-Toe Minimax Algorithm
char check_winner(const std::vector<char>& board) {
    std::vector<std::vector<int>> winning_combinations = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // Columns
        {0, 4, 8}, {2, 4, 6}              // Diagonals
    };
    for (auto& comb : winning_combinations) {
        if (board[comb[0]] == board[comb[1]] && board[comb[1]] == board[comb[2]] && board[comb[0]] != ' ') {
            return board[comb[0]];
        }
    }
    return ' ';
}

int minimax(std::vector<char>& board, int depth, bool is_maximizing) {
    char winner = check_winner(board);
    if (winner == 'X') return 1;
    if (winner == 'O') return -1;
    if (std::none_of(board.begin(), board.end(), [](char c) { return c == ' '; })) return 0;

    if (is_maximizing) {
        int best = INT_MIN;
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board[i] = 'X';
                best = std::max(best, minimax(board, depth + 1, false));
                board[i] = ' ';
            }
        }
        return best;
    } else {
        int best = INT_MAX;
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board[i] = 'O';
                best = std::min(best, minimax(board, depth + 1, true));
                board[i] = ' ';
            }
        }
        return best;
    }
}

// 5. Infix Expression Parser
class ExpressionParser {
public:
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    bool is_operator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    std::string to_postfix(const std::string& infix) {
        std::stack<char> operators;
        std::string postfix;

        for (char c : infix) {
            if (isdigit(c)) {
                postfix += c;
            } else if (c == '(') {
                operators.push(c);
            } else if (c == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.pop();
            } else if (is_operator(c)) {
                while (!operators.empty() && precedence(c) <= precedence(operators.top())) {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.push(c);
            }
        }
        while (!operators.empty()) {
            postfix += operators.top();
            operators.pop();
        }
        return postfix;
    }

    int evaluate_postfix(const std::string& postfix) {
        std::stack<int> values;
        for (char c : postfix) {
            if (isdigit(c)) {
                values.push(c - '0');
            } else if (is_operator(c)) {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                if (c == '+') values.push(a + b);
                if (c == '-') values.push(a - b);
                if (c == '*') values.push(a * b);
                if (c == '/') values.push(a / b);
            }
        }
        return values.top();
    }
};

int main() {
    // Example for FileSystem
    FileSystem fs;
    fs.create("root/dir1", true);
    fs.create("root/dir1/file1.txt", false);
    fs.remove("root/dir1/file1.txt");

    // Example for XMLParser
    XMLParser parser;
    parser.parse("<root><child name='item1' /><child name='item2' /></root>");
    std::vector<std::string> children = parser.find_elements("child");
    for (const auto& child : children) {
        std::cout << "Child: " << child << std::endl;
    }

    // Example for Huffman Coding
    std::string data = "this is an example for huffman encoding";
    HuffmanTree huffman;
    HuffmanNode* root = huffman.build_tree(data);
    std::unordered_map<char, std::string> codebook;
    huffman.generate_codes(root, codebook);
    std::string encoded = huffman.encode(data, codebook);
    std::cout << "Encoded: " << encoded << std::endl;

    // Example for Tic-Tac-Toe
    std::vector<char> board(9, ' ');
    for (int turn = 0; turn < 9; turn++) {
        int best_move = -1;
        int best_value = INT_MIN;
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board[i] = 'X';
                int move_value = minimax(board, 0, false);
                board[i] = ' ';
                if (move_value > best_value) {
                    best_value = move_value;
                    best_move = i;
                }
            }
        }
        board[best_move] = 'X';  // AI's move
        std::cout << "Board after move " << turn + 1 << ":\n";
        for (int i = 0; i < 9; i++) {
            std::cout << board[i] << " ";
            if (i % 3 == 2) std::cout << std::endl;
        }
        if (check_winner(board) != ' ') break;
    }

    // Example for Expression Parser
    std::string infix = "3+(2*2)";
    ExpressionParser expr_parser;
    std::string postfix = expr_parser.to_postfix(infix);
    std::cout << "Postfix: " << postfix << std::endl;
    std::cout << "Result: " << expr_parser.evaluate_postfix(postfix) << std::endl;

    return 0;
}
