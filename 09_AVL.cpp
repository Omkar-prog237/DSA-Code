#include <iostream>
#include <string>
using namespace std;

struct Node {
    string keyword, meaning;
    Node* left;
    Node* right;
    int height;

    Node(string k, string m) {
        keyword = k;
        meaning = m;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

int height(Node* node) {
    if (node == nullptr)
        return 0;
    else
        return node->height;
}

int getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    else
        return height(node->left) - height(node->right);
}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* insert(Node* node, string key, string meaning) {
    if (node == nullptr)
        return new Node(key, meaning);
    if (key < node->keyword)
        node->left = insert(node->left, key, meaning);
    else if (key > node->keyword)
        node->right = insert(node->right, key, meaning);
    else {
        cout << "Keyword already exists. Use update to modify meaning.\n";
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->keyword)
        return rightRotate(node);
    if (balance < -1 && key > node->right->keyword)
        return leftRotate(node);
    if (balance > 1 && key > node->left->keyword) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->keyword) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, string key) {
    if (root == nullptr)
        return root;

    if (key < root->keyword)
        root->left = deleteNode(root->left, key);
    else if (key > root->keyword)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;
            root->right = deleteNode(root->right, temp->keyword);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* search(Node* root, string key) {
    if (root == nullptr || root->keyword == key)
        return root;
    if (key < root->keyword)
        return search(root->left, key);
    return search(root->right, key);
}

void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->keyword << " : " << root->meaning << endl;
        inOrder(root->right);
    }
}

void reverseInOrder(Node* root) {
    if (root != nullptr) {
        reverseInOrder(root->right);
        cout << root->keyword << " : " << root->meaning << endl;
        reverseInOrder(root->left);
    }
}

int calculateHeight(Node* node) {
    if (node == nullptr)
        return 0;
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    return 1 + max(leftHeight, rightHeight);
}

void addKeyword(Node*& root) {
    string key, meaning;
    cout << "Enter keyword: ";
    getline(cin, key);
    cout << "Enter meaning: ";
    getline(cin, meaning);
    root = insert(root, key, meaning);
    cout << "Keyword added successfully.\n";
}

void deleteKeyword(Node*& root) {
    string key;
    cout << "Enter keyword to delete: ";
    getline(cin, key);
    root = deleteNode(root, key);
        cout << "Keyword deleted successfully.\n";
}

void updateMeaning(Node* root) {
    string key, meaning;
    cout << "Enter keyword to update: ";
    getline(cin, key);
    Node* node = search(root, key);
    if (node != nullptr) {
        cout << "Enter new meaning: ";
        getline(cin, meaning);
        node->meaning = meaning;
        cout << "Meaning updated successfully.\n";
    } else {
        cout << "Keyword not found.\n";
    }
}

void searchKeyword(Node* root) {
    string key;
    cout << "Enter keyword to search: ";
    getline(cin, key);
    Node* node = search(root, key);
    if (node != nullptr)
        cout << "Meaning: " << node->meaning << endl;
    else
        cout << "Keyword not found.\n";
}

void displayAscending(Node* root) {
    cout << "Dictionary in ascending order:\n";
    inOrder(root);
}

void displayDescending(Node* root) {
    cout << "Dictionary in descending order:\n";
    reverseInOrder(root);
}


int main() {
    Node* root = nullptr;
    int choice;

    while (true) {
        cout << "\nDictionary Operations:\n";
        cout << "1. Add Keyword\n";
        cout << "2. Delete Keyword\n";
        cout << "3. Update Meaning\n";
        cout << "4. Search Keyword\n";
        cout << "5. Display in Ascending Order\n";
        cout << "6. Display in Descending Order\n";
        cout << "7. Display Maximum Comparisons\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) 
        {
            case 1: {
                    cin.ignore(); 
                    addKeyword(root);
                    break;
                   }
            case 2: {
                    cin.ignore(); 
                    deleteKeyword(root);
                    break;
                }
            case 3: {
                    cin.ignore(); 
                    updateMeaning(root);
                    break;
                }
            case 4: {
                cin.ignore();
                searchKeyword(root);
                break;
            }       
            case 5: {
                cin.ignore(); 
                displayAscending(root);
                break;
            }
            case 6: {
                cin.ignore(); 
                displayDescending(root);
                break;
            }
            case 7: {
                cin.ignore(); 
                cout << "Maximum number of comparisons to find any keyword: " << calculateHeight(root) << endl;
                break;
            }
            case 8: {
                cout << "Exiting the program" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
}
    }
}            
