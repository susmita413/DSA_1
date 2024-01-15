//Program to Determine if given Two Trees are Identical or not
// Copy
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
          root= insertNode(root,data);
        return root;
    }

    Node* insertNode(Node* temp,int data){
        if(temp== nullptr){
            return new Node(data);
        }


        queue<Node*>q;
        q.push(temp);

        while (!q.empty()){
            Node *current=q.front();
            q.pop();

            if(current->left== nullptr){
                current->left = new Node(data);
                return temp;
            } else{
                q.push(current->left);
            }


            if(current->right== nullptr){
                current->right = new Node(data);
                return temp;
            } else{
                q.push(current->right);
            }
        }
        return temp;
    }
    void Print(Node* temp) {
        if (temp != nullptr) {
            cout << temp->data << " ";
            Print(temp->left);
            Print(temp->right);
        }
    }

    bool IdenticalCheck(Node* root1, Node* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }

        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }

        return (root1->data == root2->data &&
                IdenticalCheck(root1->left, root2->left) &&
                IdenticalCheck(root1->right, root2->right));
    }

    bool isIdentical(Tree otherTree) {
        return IdenticalCheck(root, otherTree.root);
    }
};

int main(){
    Tree tree;

    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(1);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);


    Tree tree1;

    tree1.insert(5);
    tree1.insert(4);
    tree1.insert(3);
    tree1.insert(1);
    tree1.insert(6);
    tree1.insert(7);
    tree1.insert(8);

    if (tree1.isIdentical(tree1)) {
        cout << "Trees are identical" << endl;
    } else {
        cout << "Trees are not identical" << endl ;
    }

}