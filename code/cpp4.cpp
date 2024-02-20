#include<iostream>


using namespace std;

int main(){
    int a,b;
    a =10;
    b=2;
    a=b;
    a*=b;
    cout << "a:"<<a;
    cout << "\nb:"<<b;

    cout << "\na*b:"<<a;
    int x=3,z=3;
    int y=x++;
    int p=++z;

    cout <<"\nPrefix:"<<p;
    cout<<"\nPostfix:"<<y;

    cout << "\n"<<(a==x);
    cout << "\n"<<(a==b)<<endl;

    cout << (!true)<<endl;

    cout << ((3==5) && (3>1))<<endl;
    cout << ((3==5) || (3>1))<<endl;
    a=10;
    y = 20;
    int c = (a>y)?a:y;
    //cout << "Greater between a and y:\n"<<(a>y)?a:y;
    cout << c;
    return 0;
}