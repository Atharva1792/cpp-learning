//line comment
#include<iostream>  //instructs the preprocessor to include a section of standard C++ code, known as header iostream 
/*
    lines with (#) are directives read and interpreted by preprocessor
    these lines are not statements hence semicolon is not needed to show break in the line
    instead these are needed to write in new line only (each header in different lines)

*/



// type(int) name(main) paranthesis(())parameters are optional
int main()  //execution of all C++ programs begin with 'main' function  
{   //beginning of function
    std :: cout << "Learning cpp from basics.";
    std :: cout << "Line 2";
}

/*
    std:: can be omitted by using "namespace std" 
    it means that cout is a part of standard c++ library it needs to qualified that is std::cout
    or we can use using namespace std so we can use the elements without using std::
*/

/*
    cpp have no rules on lines or indentation
    it is only for readability of code to be more human friendly
    we can write whole code in 1 line also-
    int main(){std::cout<<"Learning cpp from basics";std::cout<<"Line 2";}
*/



