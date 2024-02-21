#include<iostream>
#include<sstream>

using namespace std;

int main(){
    string str;
    float price = 0;
    int quantity = 0;

    cout << "Enter price: ";
    getline(cin,str);   //str is price value we took
    stringstream(str) >> price; // and now the str value is extracted and stored in price variable
    cout << "Enter quantity: ";
    getline(cin, str);
    stringstream(str) >> quantity;  // float also same
    cout << "Total price: " << price * quantity << endl;
    return 0;
}