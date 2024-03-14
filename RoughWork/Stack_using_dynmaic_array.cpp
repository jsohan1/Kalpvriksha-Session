#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class stack{
    vector<T> vec;
    public :
    Stack(){

    }
    void push(T val){
        vec.push_back(val);
    }
    void pop(){
        if(isEmpty()){
            cout<<"Warning : Stack is Empty";
            return ;
        }
        vec.pop_back();
    }
    bool isEmpty(){
        return vec.empty();
    }
    T top(){
        if(isEmpty()){
            throw -1;
        }
        return vec[vec.size()-1];
    }
};

int main(){
    stack<int> stk;
  
    return 0;
}