// reverse individual words// hello world --> olleh dlrow 
// stack using  linked list//
// 2nd way//

#include <iostream>
using namespace std;

struct StackList{
    string data;
    struct StackList* next;
};
typedef struct StackList node;
node* top= nullptr;

void push(string value){
   node* temp=new node;
  temp->data=value;
  temp->next=top;
  top=temp;
}

void WordReverse(string str) {
    int start = 0;
    int length = str.length();

    for (int i = 0; i <= length; i++) {
        if (str[i] == ' ' || i == length) {
            for (int j = i - 1; j >= start; j--) {
                cout << str[j];
            }
            start = i + 1;
            if (i != length) {
                cout << " ";
            }
        }
    }
}

void PrintList(){
    if(top== nullptr){
        cout<<"Stack Overflow";
        return;
    }
  node* temp =top;
    while (temp!= nullptr){
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<" ";
}


int main(){
    string str="I am Susmita";

    for(int i=0;i<=str.length();i++){
         string chr(1,str[i]);
        push(chr);
    }
    WordReverse(str);

}