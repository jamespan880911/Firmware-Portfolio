#include<iostream>
using namespace std;

class Circle{
    private:
        int radius;

    public:
        Circle(int r){
            radius = r;
        }

        void caculateArea(){
            float area = radius * radius * 3.14;
            cout << "area = " << area << endl;
        }
};

int main(){
    int a = 100;

    Circle obj1(a);

    obj1.caculateArea();

    return 0;
}