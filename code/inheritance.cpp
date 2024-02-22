#include<iostream>
using namespace std;

class Polygon{
    protected:
        int width,height;
    public:
        void set_values(int x,int y){
            width = x;
            height =y;
        }
};

class Rectangle:public Polygon{
    public:
        int area(){
            return (width*height);
        }
};

class Triangle : public Polygon
{
public:
    int area()
    {
        return (width * height)/2;
    }
};
//here created objects of respected classes, for polymorphism we use pointers,same example in polymorphism.cpp
int main(){
    Rectangle rt;
    Triangle tr;
    rt.set_values(2,5);
    tr.set_values(2,3);

    cout << "Rectangle:"<<rt.area()<<endl;
    cout << "Triangle:"<<tr.area()<<endl;

    return 0;
}