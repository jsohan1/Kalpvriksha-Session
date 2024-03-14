#include<iostream>
using namespace std;
template<typename T>
class stack{
    private :
    T *ptr;
    int ind;
    int size;
    public:
    stack(int size){
        ind = -1;
        this->size=size;
        ptr = new T[size];
    }
    void push(T element){
        if(ind>=size){
            cout<<"Stack Overflow"<<endl;
        }
        ind++;
        ptr[ind]=element;
    }
    void pop(){
        if(ind==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        ind--;
    }
    T top(){
        if(ind<0){
            cout<<"Warning : Stack is Empty"<<endl;
            return -1;
        }
        return ptr[ind];
    }
    bool isEmpty(){
        return ind==-1;
    }
};
int main(){
    stack<int> stk(10);
    cout<<"Push 34"<<endl; 
    stk.push(34);
    cout<<"Push 4"<<endl; 
    stk.push(4);
    cout<<"Top Element"<<endl; 
    cout<<stk.top()<<endl;
    cout<<"Check,Is Stack empty ?"<<endl;
    if(stk.isEmpty()){
        cout<<"Stack is Empty"<<endl;
    }   
    else{
        cout<<"Stack is not emtpy"<<endl;
    }
    return 0;
}