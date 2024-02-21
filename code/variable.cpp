//Variables and types
/*

*/

#include<iostream>


/*int main(){
    

    //Declaration of variable
    int  a,b;
    int res;      

    //Assigning value
    a = 5;
    b = 4;
    a = a +1;
    res = a - b;

    std::cout << res;

    return 0;
}*/

// variable initialization - assigning value when we declare them
/*
    3 ways to initialize -  c-like initialization (type iden = value)
                            constructor initialization (type iden(value))
                            uniform initialization  (type iden{value})
*/
int main(){
    int a = 5;
    int b(4);
    int c{3};
    int res;

    auto ab = a; //similar to int ab = a;
    decltype(b) abc; //similar to int abc;
    res = (a+b) - c;    
    std:: cout << res;
    std:: cout << std::endl << ab;

    return 0;

}