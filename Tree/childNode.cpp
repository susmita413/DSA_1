//Chiled node
// Created by Sifat Ali on 12/8/2023.
//

#include <iostream>
#include <queue>
using namespace std;

class Tree {
    class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
    };
public:
    Node *root;

    Tree() {
        this->root = nullptr;
    }

    Node* insert(int value) {
        root = insertNode(root, value);
        return root;
    }

    Node* insertNode(Node *temp, int value) {
        if(temp == nullptr) {
            return new Node(value);
        }

        queue<Node*> q;
        q.push(temp);

        while (!q.empty()) {
            Node *current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = new Node(value);
                return temp;
            } if(current->left != nullptr)  {
                q.push(current->left);
            }
            if (current->right == nullptr) {
                current->right = new Node(value);
                return temp;
            } else {
                q.push(current->right);
            }
        }
        return temp;
    }

    Node* findNode(Node* temp, int value) {
        if (temp == nullptr || temp->data == value) {
            return temp;
        }

        Node* left = findNode(temp->left, value);
        if (left != nullptr) {
            return left;
        }

        return findNode(temp->right, value);
    }

    void displayChildren(int value) {
        Node* node = findNode(root, value);
        if (node == nullptr) {
            cout << "Node not found." << endl;
            return;
        }

        cout << "Children of node " << value << ": ";
        if (node->left != nullptr) {
            cout << node->left->data << " ";
        }
        if (node->right != nullptr) {
            cout << node->right->data << " ";
        }
        cout << endl;
    }

    void Print(Node* temp) {
        if (temp != nullptr) {
            Print(temp->left);
            cout << temp->data << " ";
            Print(temp->right);
        }
    }

    void Inorder() {
        cout << "In-order traversal: ";
        Print(root);
        cout << endl;
    }
};

int main() {
    Tree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(4);
    tree.insert(1);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);

tree.Inorder();
    int node = 3;
    tree.displayChildren(node);

   return 0;
}