/*****************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

******************************************************************************/

#include <iostream>

using namespace std;

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() {}
	Shape* add(Shape* p) {
		this->next = p;
		return p;
	}
	void paint() {
		draw();
	}
	Shape* getNext() { return next; }
};

class Line : public Shape {
protected:
	virtual void draw() {
		cout << "Line" << endl;
	}
};

class Circle : public Shape {
protected:
	virtual void draw() {
		cout << "Circle" << endl;
	}
};

class Rectangle : public Shape {
protected:
	virtual void draw() {
		cout << "Rectangle" << endl;
	}
};

class UI {
    public:
    static int getMenu(){
        int menu;
        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>";
        cin >> menu;
        return menu;
    }
    static int getShapeType(){
        int shapetype;
        cout << "선:1, 원:2, 사각형:3>>";
        cin >> shapetype;
        return shapetype;
    }
    static int getDeleteShape(){
        int deleteshape;
        cout << "삭제하고자 하는 도형의 인덱스>>";
        cin >> deleteshape;
        return deleteshape;
    }

};

class GraphicEditor {
    Shape *pStart;
    Shape *pLast;
    int node_size;
    public:
    GraphicEditor(){ 
        pStart = NULL;
        node_size = 0;
    }
    int run(){
        cout << "그래픽 에디터입니다." << endl;
    while(true){
    int menuNumber = UI::getMenu();
    if(menuNumber==1){
        int shapetypeNumber = UI::getShapeType();
        if(shapetypeNumber==1){
            if(node_size==0){
                pStart = new Line();
                pLast = pStart;
            }
            else
            pLast = pLast->add(new Line());
            node_size++;
        }
        else if(shapetypeNumber==2){
            if(node_size==0){
                pStart = new Circle();
                pLast = pStart;
            }
            else
            pLast = pLast->add(new Circle());
            node_size++;
        }
        else if(shapetypeNumber==3){
            if(node_size==0){
                pStart = new Rectangle();
                pLast = pStart;
            }
            else
            pLast = pLast->add(new Rectangle());
            node_size++;
        }
    }
    else if(menuNumber==2){
        int index = UI::getDeleteShape();
        Shape* pre = pStart;
		Shape* tmp = pStart;
		if (pStart == NULL) {
			cout << "도형이 없습니다" << endl;
		}
		else { //ex) 1.Line 2.Circle 3.Rectangle
			for (int i = 1; i < index; i++) { //링크드 리스트는 앞에서 부터 찾아야하기에 선택한 인덱스까지 주소를 타고 이동
				pre = tmp;  //pre=Line
				tmp = tmp->getNext(); //tmp=Circle
			}
			if (tmp == pStart) { //첫번째 노드를 삭제하는 경우
				pStart = tmp->getNext(); //링크드리스트 첫번째노드에 다음 노드를 불러주고 첫번째 노드 삭제
				delete tmp;
			}
			else {
				pre->add(tmp->getNext()); //Line에서 링크를 Rectangle로 옮긴다. //add(Rectangle)= Line의 next는 Rectangle add(Rectangle)은 객체포인터 Rectangle리턴
				delete tmp;
			}
			node_size--;
		}
        
    }
    else if(menuNumber==3){
        Shape *p = pStart;
        int i = 1;
        if(p == NULL)
        cout << "List Empty\n";
        else{
		while (p != NULL) {
			cout << i++ << ": ";
			p->paint();
			p = p->getNext();
		}
    }
}
    else if(menuNumber==4){
        return 0;
    }
}
    }
};    
int main()
{
    GraphicEditor GE;
    GE.run();
   
    return 0;
}
