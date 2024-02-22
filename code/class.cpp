#include<iostream>
using namespace std;

class Vehicle{
    int private_t=10;  //by default it takes it as private 
    //it can be accessed by members of this class
    public:     //access specifier
    string type;
    string company;
    float price;
    static int year;

    //constructors can also be overloaded (Change in parameters)
    Vehicle(){  //default constructor
        private_t = 5;type = "Bike";company = "Kawasaki";price = 4.5;
    }

    Vehicle(int pr, string t, string c, float p){   //constructor
        private_t = pr;                             
        type = t;
        company = c;
        price = p;
    }
    /*
        constructor help in avoiding undetermined result, since if we call the function
        without assigning the values then unknown output, so constructor help in initializing as 
        when the object is created it will need the values to create object
    */
    friend Vehicle price_INR(float p);
    void show();    // we can declare function and write the function later also
    void incr();
}; //object names

int Vehicle::year = 0;

void Vehicle::incr(){
    year++;
}

void Vehicle::show(){   //defining class function outside the class since we declared it already in class.
    cout << "Vehicle Type: "<<type<<endl;
    cout << "Vehicle Company: "<<company<<endl;
    cout << "Vehicle Price: "<<price<<endl;
    cout << "Private access: "<<private_t<<endl;
    cout << "Released:"<< year<<endl;
}

Vehicle price_INR(float p){     //friend class 
    Vehicle v;
    v.price = p*v.private_t;    // able to access private variable
    return v;
}


int main(){
    Vehicle v(10,"car","Honda",3.4);  //object creation this way also
    Vehicle v1; //without parameter we created constructor
    Vehicle * ptr;
    ptr = new Vehicle();   // accessing thru pointer (without creating any named object)
    v.incr();
    ptr->show();
    v.incr();
    v.show();  
    //we are able to access private (int) since we printed in the show function (as it is member of class)
    //through such functions we can access private keywords in other blocks of program
    //v1.show();
    v.incr();
    v1.show();

    /*
        year is defined as static,hence i incremented the value of year thru member function 'incr'
        with the object v but the value is reflected when i call the 'show' function through other objects also,
        year was initialized to 0 globally using the class scope
    */
    return 0;
}
