#include <iostream>
#include <string>
using namespace std;

struct node {
    string keyword;
    string meaning;
    node* left;
    node* right;

    node(string keyword, string meaning) {
        this->keyword = keyword;
        this->meaning = meaning;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void insert(node*& root, string KEYWORD, string MEANING) {
    if (!root) {
        root = new node(KEYWORD, MEANING);
        cout << "Inserted: " << KEYWORD << endl;
        return;
    } else {
        if (KEYWORD < root->keyword) {
            insert(root->left, KEYWORD, MEANING);
        } else if (KEYWORD > root->keyword) {
            insert(root->right, KEYWORD, MEANING);
        } else {
            cout << "Keyword " << KEYWORD << " already exists!" << endl;
        }
    }
}

void inorder(node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->keyword << ": " << root->meaning << endl;
    inorder(root->right);
}

string search(node* root, string KEYWORD) {
    if (!root) return "Keyword not found!";
    if (root->keyword == KEYWORD) {
        return root->keyword + ": " + root->meaning;
    } else if (KEYWORD < root->keyword) {
        return search(root->left, KEYWORD);
    } else {
        return search(root->right, KEYWORD);
    }
}

void deleteNode(node*& root, string KEYWORD) {
    if (!root) return;

    if (KEYWORD < root->keyword) {
        deleteNode(root->left, KEYWORD);
    } else if (KEYWORD > root->keyword) {
        deleteNode(root->right, KEYWORD);
    } else {
        if (!root->left && !root->right) {
            delete root;
            root = nullptr;
        } else if (!root->left) {
            node* temp = root;
            root = root->right;
            delete temp;
        } else if (!root->right) {
            node* temp = root;
            root = root->left;
            delete temp;
        } else {
            node* temp = root->right;
            while (temp && temp->left) {
                temp = temp->left;
            }
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;
            deleteNode(root->right, temp->keyword);  // <- this was missing (clean-up)
        }
    }
}

void menu() {
    cout << "\nDictionary Menu:\n";
    cout << "1. Insert a new keyword\n";
    cout << "2. Delete a keyword\n";
    cout << "3. Search for a keyword\n";
    cout << "4. Display all keywords (in-order)\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    node* root = nullptr;
    int choice;
    string keyword, meaning;

    while (true) {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                cin >> keyword;
                cin.ignore();
                cout << "Enter meaning: ";
                getline(cin, meaning);
                insert(root, keyword, meaning);
                break;

            case 2:
                cout << "Enter keyword to delete: ";
                cin >> keyword;
                deleteNode(root, keyword);
                break;

            case 3:
                cout << "Enter keyword to search: ";
                cin >> keyword;
                cout << search(root, keyword) << endl;
                break;

            case 4:
                cout << "Displaying all keywords (in-order):\n";
                inorder(root);
                break;

            case 5:
                cout << "Exiting the program.\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
