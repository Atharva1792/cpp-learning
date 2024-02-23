#include<iostream>
#include<exception>

using namespace std;

class myException:public exception{
    virtual const char* what() const throw(){
        return "My Exception";
    }
};

int main(){
    myException myex;
    /*try{
        throw myex;
    }
    catch(exception& e){
        cout << "Custom Exception:"<<e.what();
    }*/

    try{
        int *arr = new int[10001000000000];
    }
    catch (bad_alloc e){
        cout <<endl<<"Standard Exception:"<<e.what();
    }

    return 0;
}