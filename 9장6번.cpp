/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

#include <iostream>

using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0;
	virtual bool pop(int& n) = 0;
	virtual int size() = 0;
};

class IntStack : public AbstractStack{
    int stack[5];
    int top = -1;
    public:
    bool push(int n){
        if(top>4){
           cout << "스택이 꽉 찼습니다." << endl; 
           return false;  
        }
        
        stack[++top] = n;
        return true;

    }
    bool pop(int &n){
        if(top<0){
            cout << "스택이 비었습니다." << endl;
            return false;
        }
        
        n = stack[top--];
        return true;
    }
    int size(){
        return top+1;
    }
    
    void show(){
        for(int i=0; i<size(); i++){
            cout << stack[i] << " ";
        }
    }
};

int main()
{
    IntStack intstack;
    
    intstack.push(1);
    intstack.push(2);
    intstack.push(3);
    intstack.push(4);
    intstack.push(5);
    
    intstack.show();
    
    int n;
    intstack.pop(n);
    cout << endl;
    intstack.show();
    return 0;
}