#include<iostream>
using namespace std;
class account{
    // variable or function 
    private:
    int balance; //garbage 
    public:
    account(){
        balance = 0;
    }
    account(int startingMoney){
        balance = startingMoney;
    }
// constructor = initialize the object, member function, no return type, same name as of class

    int checkBalance(){ //operations
        return balance;
    }
    void deposit(int moneyDeposited){
        cout<<"Money Deposited"<<endl;
        balance = balance + moneyDeposited;
    }
    void withdraw(int moneyWithdrawn){
        if(balance<moneyWithdrawn){
            cout<<"Not Enough Cash"<<endl;
            return ;
        }
        cout<<"Money withdrawn"<<endl;
        balance = balance - moneyWithdrawn;
    }
};
int main(){
    int x ;
    x = abs(-1-1);
    cout<<x<<endl;
    return 0;
}