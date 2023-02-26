/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Printer{
    protected:
    string model;
    string manufacturer;
    int printedCount;
    int availbleCount;
    public:
    Printer(string model, string manufacturer, int availbleCount){
        this->model = model;
        this->manufacturer = manufacturer;
        this->availbleCount = availbleCount;
    }
    virtual void print(int pages) = 0;
    virtual void show() = 0;
};

class InkJetPrinter : public Printer{
    int ink;
    public:
    InkJetPrinter(string model, string manufacturer, int availbleCount, int ink) : Printer(model, manufacturer, availbleCount){
        this->ink = ink;
    }
    void show(){
        cout << "잉크젯 : " << model << " ," << manufacturer << " ,남은 종이 " << availbleCount << " ,남은 잉크 " << ink << endl;
    }
    void print(int pages){
        if(availbleCount>pages){
            cout << "프린트하였습니다." << endl;
            availbleCount -= pages;
            ink -= pages;
        }
        else{
            cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
        }
    }
};

class LaserPrinter : public Printer{
    int toner;
    public:
    LaserPrinter(string model, string manufacturer, int availbleCount, int toner) : Printer(model, manufacturer, availbleCount){
        this->toner = toner;
    }
    void show(){
        cout << "레이저 : " << model << " ," << manufacturer << " ,남은 종이 " << availbleCount << " ,남은 토너 " << toner << endl;
    }
    void print(int pages){
        if(availbleCount>pages){
            cout << "프린트하였습니다." << endl;
            availbleCount -= pages;
            toner--;
        }
        else{
            cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
        }
    }
};

int main()
{
    int printerNumber;
    int pages;
    char ch;
    InkJetPrinter *inkjetprinter = new InkJetPrinter("Officejet V40", "HP", 5, 10);
    LaserPrinter *laserprinter = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);
    
    cout << "현재 작동중인 2 대의 프린터는 아래와 같다." << endl;
    inkjetprinter->show();
    laserprinter->show();
    
    cout << endl << endl;
    while(true){
    cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
    cin >> printerNumber >> pages;
    
    if(printerNumber==1){
        inkjetprinter->print(pages);
        inkjetprinter->show();
        laserprinter->show();
    }
    else{
        laserprinter->print(pages);
        inkjetprinter->show();
        laserprinter->show();
    }
    cout << "계속 프린트 하시겠습니까(y/n)>>";
    cin >> ch;
    
    cout << endl << endl;
    if(ch=='n')
    break;
       
}
    return 0;
}
