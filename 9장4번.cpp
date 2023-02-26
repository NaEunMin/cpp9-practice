/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

#include <iostream>

using namespace std;

class LoopAdder {
	string name;
	int x, y, sum;
	void read();
	void write();
protected:
	LoopAdder(string name = "") { this->name = name; }
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;
public:
	void run();
};

void LoopAdder::read() {
	cout << name << ":" << endl;
	cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
	cin >> x >> y;
}
void LoopAdder::write() {
	cout << x << "에서 " << y << "까지의 합 = " << sum << "입니다." << endl;
}
void LoopAdder::run() {
	read();
	sum = calculate();
	write();
}

class WhileLoopAdder : public LoopAdder{
    public:
    WhileLoopAdder(string name) : LoopAdder(name){}
    int calculate(){
        int sum=0;
        int i = getX();
        int count=0;
        while(count<getY()-getX()+1){
            sum += i;
            i++;
            count++;
        }
        return sum;
    }
};

class DoWhileLoopAdder : public LoopAdder{
    public:
    DoWhileLoopAdder(string name) : LoopAdder(name){}
    int calculate(){
        int sum=0;
        int i = getX();
        int count=0;
        do{
            sum += i;
            i++;
            count++;
        }while(count<getY()-getX()+1);
        return sum;
    }
};

int main()
{
    WhileLoopAdder whileLoop("While Loop");
    DoWhileLoopAdder dowhileLoop("Do While Loop");
    
    whileLoop.run();
    dowhileLoop.run();
    return 0;
}