#include<bits/stdc++.h>
#include "cpp7.cpp"

using namespace std;
int pqr;//global variable
int addition(int x,int y){
    x = x+y;
    return x;
}

void duplicate(int& a,int& b, int& c){
    a*=2;
    b*=2;
    c*=2;
}

template <class T>
T sum1(T a,T b){
    T x;
    x = a+b;
    return x;
}

int main(){
    int p=2,q=3;
    int x=2,y=3,z=4;

    //by value
    cout <<"P before function call:"<<p<<endl;
    int sum = addition(p,q);    
    cout <<"P after function call:"<< p<<endl;  
    //value of p should change since in the function it is updated but didn't change in this block
    //by reference
    cout << "X,Y,Z before function:"<<x<<","<<y<<","<<z<<endl;
    duplicate(x,y,z);
    cout << "X,Y,Z after function:" << x << "," << y << "," << z << endl;
    //values were changed in this block bc in reference the variable as a whole is passed.

    int res1 = sum1<int>(10,20);
    double res2 = sum1<double>(10.0,15.5);
    cout <<"int sum:"<<res1<<endl;
    cout <<"double sum:"<<res2<<endl;


    //storage class
    cout << "Storage class:\n";
    int abcd;//local variable
    cout << "Global:"<<pqr<<endl;
    cout <<"Local:"<<abcd<<endl;
    
    extern int global_x;
    cout << "Accessing variable from cpp7:"<<global_x; //use of extern
    return 0;
}