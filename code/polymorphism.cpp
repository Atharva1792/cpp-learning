#include <iostream>
using namespace std;

class Polygon
{
protected:
    int width, height;

public:
    void set_values(int x, int y)
    {
        width = x;
        height = y;
    }
    virtual int area(){return 0;}
};

class Rectangle : public Polygon
{
public:
    int area()
    {
        return (width * height);
    }
};

class Triangle : public Polygon
{
public:
    int area()
    {
        return (width * height) / 2;
    }
};

int main()
{   
    Rectangle rt;
    Triangle tr;
    Polygon* ptr1 = &rt;
    Polygon* ptr2 = &tr;
    ptr1->set_values(2,5);
    ptr2->set_values(2,5);
    //both objects of polygon class (pointers of polygon class) which are assigned address 
    //of rectangle and triangle class objects
    cout << "Rectangle:" << rt.area() << endl;
    cout << "Triangle:" << tr.area() << endl;

    //because of virtual member
    cout << "Rectangle(virtual):"<<ptr1->area()<<endl;
    cout << "Triangle(virtual):" << ptr2->area() << endl;
    return 0;
}
/*
    since set_values is member of polygon we can access it with pointer and set value according of 
    the respected pointer that is whichever object it is pointing to
    but we cant access area member since it is of derived class and we cant access derived class members
    from base class
    to access it from base class, we have virtual members, can redefine in the derived class 
    and access from base class
*/