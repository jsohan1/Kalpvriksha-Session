#include<iostream>
using namespace std;

template<typename T>
class node{
    T val;
    node *next;
    public : 
    node(T val){
        this->val = val;
    }
    void setNext(node*val){
        next = val;
    }
    node* getNext(){
        return next;
    }
    T getValue(){
        return val;
    }
};

template<typename T>
class stack{
    node<T>* front;
    public:
    stack(){
        front=NULL;
    }
    public :
    void push(T element){
        node<T>* temp = new node<T>(element);
        temp->setNext(front);
        front = temp;
    }
    void pop(){
        if(isEmpty()){cout<<"Stack Overflow"<<endl; return ;}
        node<T> *del = front;
        front = front->getNext();
        delete del;
    }
    bool isEmpty(){
        return front == NULL;
    }
    T top(){
        if(isEmpty()){
            // cout<<"Warning : Stack is empty"<<endl;
            throw -1;
        }
        return front->getValue();
    }
};

int main(){
    stack<int> stk;
    // cout<<"Push 34"<<endl; 
    // stk.push(34);
    // cout<<"Push 4"<<endl; 
    stk.push(4);
    // cout<<"Top Element"<<endl; 
    // cout<<stk.top()<<endl;
    // cout<<"Check,Is Stack empty ?"<<endl;
    try{
        cout<<stk.top()<<endl;
    }
    catch(...){
        cout<<"Unexpected Acces : Stack is empty"<<endl;
    }
    if(stk.isEmpty()){
        cout<<"Stack is Empty"<<endl;
    }   
    else{
        cout<<"Stack is not emtpy"<<endl;
    }
    return 0;
}