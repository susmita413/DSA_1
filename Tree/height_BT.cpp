//Find the Maximum Depth or Height of given Binary Tree
// Created by Sifat Ali on 12/8/2023.
//
#include <iostream>
#include <queue>

using namespace std;

class Tree{
    class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data=data;
            this->left= nullptr;
            this->right= nullptr;
        }
    };
    Node* root;
public:
    Tree(){
        this->root= nullptr;
    }

    Node* insert(int data){
        root=insertNode(root,data);
        return root;
    }

    Node* insertNode(Node* temp,int data){
        if(temp== nullptr){
            return new Node(data);
        }

        queue<Node*>q;
        q.push(temp);

        while(!q.empty()){
           Node* current=q.front();
           q.pop();

           if(current->left== nullptr){
               current->left=new Node(data);
               return temp;
           } else{
               q.push(current->left);
           }

            if(current->right== nullptr){
                current->right=new Node(data);
                return temp;
            } else{
                q.push(current->right);
            }
        }
        return temp;
    }

    int height(Node* temp) {
        if (temp == nullptr) {
            return 0;
        } else {
            int leftHeight = height(temp->left);
            int rightHeight = height(temp->right);

            return 1 + max(leftHeight, rightHeight);
        }
    }

    void printHeight() {
        cout << "Height: " << height(root) << endl;
    }
};

int main(){
    Tree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(4);
    tree.insert(1);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);
    tree.insert(10);
    tree.insert(11);
    tree.insert(12);
    tree.insert(13);
    tree.insert(14);
    tree.insert(15);

    tree.printHeight();
}