/*
    OPERATOR OVERLOADING
    as we do addition(example) in integer ,i.e a=b+c(all of type int)
    there should be class_name (a = b+c)of same class (since it is like a type)
    but the result is not clear since class_name dont have any behaviour for class_name addition
    and will give error

    So we can overload operators to define the behaviour of operators of almost any type(classes)-
    almost all operators can be overloaded.
    Through Code example-

    Syntax -
    type operator sign(parameters){ code }
    class_name operator +(class_name object){}
*/
//Cartesian Vector - (two coordinates(x,y) - addition of CV is addition of respected coordinates)
#include<iostream>
using namespace std;

class CVector{
    public:
        int x,y;
        CVector(){};
        CVector(int a,int b) : x(a),y(b){}  //another way to define constructor 

        CVector operator+ (const CVector& param); //declared operator overloading
        CVector operator=(const CVector &param);
}; 

//defining operator behaviour

CVector CVector::operator+(const CVector& param){       //it can be non-member also of class
    CVector temp;
    temp.x = param.x + x;
    temp.y = param.y + y; 

    return temp;
}

CVector CVector::operator=(const CVector& param){
    x = param.x;
    y = param.y;
    return *this;
}

int main(){
    CVector cv1(2,3);
    CVector cv2(2,1);

    CVector res;
    res = cv1+cv2;

    cout << "("<<res.x <<","<<res.y<<")";

    CVector cv12 = cv1;
    cout << "(" << cv12.x << "," << cv12.y << ")";

    return 0;
}