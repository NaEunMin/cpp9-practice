/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
		cout << getSourceString() << "을 입력하세요>> ";
		cin >> src;
		cout << "변환 결과: " << convert(src) << getDestString() << endl;
	}
};

class WonToBollar : public Converter{
    public:
    WonToBollar(double ratio) : Converter(ratio){}
    double convert(double src){ //src는 원 ex) 10000원
        src = src / ratio;
        return src;
    }
    string getSourceString(){
        return "원";
    }
    string getDestString(){
        return "달러";
    }
};

int main()
{
    WonToBollar wd(1010); //1달러에 1010원
    wd.run();

    return 0;
}
