#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char ch) {
        data = ch;
        left = nullptr;
        right = nullptr;
    }
};

bool isoperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

Node* Exptree(const string& prefix) {
    stack<Node*> s;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isalpha(ch)) {
            s.push(new Node(ch));
        }
        else if (isoperator(ch)) {
            Node* opNode = new Node(ch);
            opNode->left = s.top();
            s.pop();
            opNode->right = s.top();
            s.pop();
            s.push(opNode);
        }
    }
    return s.top();
}

void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    stack<Node*> s;
    stack<char> rs;
    s.push(root);
    while (!s.empty()) {
        Node* t = s.top();
        s.pop();
        rs.push(t->data);
        if (t->left) {
            s.push(t->left);
        }
        if (t->right) {
            s.push(t->right);
        }
    }
    while (!rs.empty()) {
        cout << rs.top();
        rs.pop();
    }
}

void deleteTree(Node* root) {
    if (root == nullptr)
        return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* t = s.top();
        s.pop();
        if (t->left) {
            s.push(t->left);
        }
        if (t->right) {
            s.push(t->right);
        }
        delete t;
    }
}

int main() {
    string prefix;
    cout << "Enter the prefix expression: ";
    cin >> prefix;

    Node* root = Exptree(prefix);     
    cout << "Post-order traversal: ";
    postorder(root);  
    cout << endl;

    deleteTree(root);
    cout << "Tree deleted successfully!!" << endl;

    return 0;
}
