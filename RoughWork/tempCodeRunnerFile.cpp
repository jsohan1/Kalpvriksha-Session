#include<iostream>
// #include<stack>
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
    public :
     stack(){
        front=NULL;
    }
    stack(stack &obj){
        // stack<T> demo ;
        // while(!obj.isEmpty()){
        //     demo.push(obj.top());
        //     obj.pop();
        // }
        //  while(!demo.isEmpty()){
        //     obj.push(demo.top());
        //     push(demo.top());
        //     demo.pop();
        // }
        node<T>* curr = obj.front;
        while(curr){
            push(curr->getValue());
            curr = curr->getNext();
        }
    }
    void push(T element){
        node<T>* temp = new node<T>(element);
        temp->setNext(front);
        front = temp;
    }
    void pop(){
        if(!front){cout<<"Stack Overflow"<<endl; return ;}
        node<T> *del = front;
        front = front->getNext();
        delete del;
    }
    bool isEmpty(){
        return front == NULL;
    }
    T top(){
        if(isEmpty()){
            cout<<"Warning : Stack is empty"<<endl;
            T();
        }
        return front->getValue();
    }
};

int main(){
    stack<int> stk;
    stk.push(94);
    stk.push(455);
    stack<int> obj(stk);
    obj.pop();
    cout<<stk.top()<<endl;
    return 0;
}