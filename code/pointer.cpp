#include<iostream>

using namespace std;

char ch1 = 'a', ch2 = 'b';
char ch3[4] = {'c', 'd', 'e', 'f'};
char *ptr[3];

int *ptr1;

int arr[3] = {5, 12, 31};
int *ptr10 = new int[3];

int **ptr4;
int *ptr5;
int in = 10;

int **ptr6;

int ***ptr7;

int *sum(int *i, int *j);

int *sum(int *i, int *j)
{
    int *result = new int;

    *result = *i + *j;

    return result; // it is equivalent to (int *unnamed = result) since new keyword is used we created memory space for it
}

int sum1(int a, int b)
{
    return a + b;
}

int (*ptr_sum)(int, int) = &sum1; // ptr_sum is a pointer which pointing to function 
                                // "sum" which takes 2 ints as argument and returns an int.

void increment_all(int *start, int *stop)
{
    int *current = start;
    while (current != stop)
    {
        ++(*current); // increment value pointed
        ++current;    // increment pointer
    }
}

void print_all(const int *start, const int *stop)
{
    const int *current = start;
    while (current != stop)
    {
        cout << *current << '\n';
        ++current; // increment pointer
    }
}

int main(){

    int i= 10;

    cout << "The value of variable i = " <<i <<endl;
    cout << "The memory address of i = " <<&i << endl; //hexadecimal format
    cout << "The value of variable i using * operator = " << *(&i)<<endl; 
    //    The * operator gives the value when provided with a memory address. the datatype is inferred from the variable name. 
    
    cout << "\n------------------------\n\n";
    i = 10;
    int *x = &i;  // x stores address of i
    int *y;

    y = &i; //can also assign like this


    cout << "The pointer x is stored at the memory address : " << &x << endl;
    cout << "The pointer x stores the memory address of i : " << x << endl;


    cout << "The value of i accessed through pointer x is : "<<*x << endl; 
    
    //manipulate value of i using pointer x

    *x = *x +1;

    cout << "i (through pointer) = " << *x <<" which equals i (direct access) = " << i <<endl;

    cout << "The memory allocated to the pointer x is : " << sizeof(x) << " bytes." ; 
    
    cout<<"\n\n-----------ARRAY POINTERS-------------\n\n";

    ptr[0] = &ch1;
    ptr[1] = &ch2;
    ptr[2] = ch3;


    cout << "Initial characters stored in ptr[0] and ptr[1]: " << *ptr[0]<<" "<<*ptr[1]<<endl;
    //changing the value stored via pointer
    *ptr[0] = 'z'; 
    *ptr[1] = 'y'; 
    cout << "Final characters stored in ptr[0] and ptr[1]: " << *ptr[0] <<" "<<*ptr[1]<<endl;
    cout << "Array accessed through pointer:"<<*ptr[2]<<endl;

    cout<<"\n-----------Dynamic memory allocation----\n\n";

    ptr1 = new int; // 'new' allocates memory for an unnamed integer.We can freely access the unnamed variable through the pointer
    
    *ptr1 = 10;
    *ptr1 = 2 + *ptr1;

    cout << "Dynamic memory allocation: Value of ptr1 is : " << *ptr1<<endl;

    delete ptr1; //free up allocated memory.

    //can use the same pointer again to another memory address

    ptr1 = new int[3]; // same pointer now allocated to base address of an array

    //array can be accessed easily using the pointer ptr1


    *(ptr1+0) =2;   //can add array members like this also
    *(ptr1+1) =4;
    ptr1[2] =6;    //normal method

    cout << "Printing array of pointers: \n";
    for(int i=0;i<3;i++){
        cout << "*(ptr1+"<<i<<") =" << *(ptr1+i) << endl; //other way to print array when pointer is used
    }

    cout << "Reprinting:\n";
    for(int i=0;i<3;i++){
        cout << "ptr1[" << i << "] = "<<ptr1[i] <<endl; // normal way to print array
    }

    delete[ ] ptr1; //free up memory, array size need not be specified.
    
    cout<< "\n-----------------Array and Pointer---------------\n\n";

    *(ptr10+0) = 2; //pointer way
    ptr10[1] = 4; // normal way (array)
    *(ptr10+2) = 6;
    //same way to access(print) them also 

    cout << "arr[0] using array notation = "<< arr[0]<<endl;
    cout << "arr[1] using pointer notation = "<<arr[1]<<endl;

    //access base address of array that pointer points to

    cout << "Base address of array ptr points to: " << ptr <<endl;

    // access base address of arr
    cout << "Base address of array arr is : " << arr << endl;

    cout << "------------Multi dimensional Pointer-----\n";

    ptr5 = &in;
    cout << *ptr5<< endl;

    ptr4 = &ptr5; // assigned base address of ptr(pointer itself,not where it points to) to ptr2

    //accessing i in different ways
    cout << "Through i : " << i <<endl;
    cout << "Through ptr : "<< *ptr5 << endl;
    cout << "Through ptr2: "<< **ptr4 << endl;

    cout <<"\n---------pointers to return value from functions-----------\n\n";
 
    int p = 10, q =15;
    int *r = sum(&p,&q);    //pointer r stores the base address of the memory allocated with new operator in the function sum.

    cout << "The sum is : " << *r << endl;

    //since memory is not being deleted with delete,a memory leak is created.


    cout<< "\n-------------Dynamic memory allocation(Multidimensional pointer)-------\n\n";

    ptr6 = new int *[3]; // ptr stores the base address of an array of three pointers to an int or int array

    for (int i=0;i<3;i++){
        *(ptr6+i) = new int[4];
    }
    // this loop can be written as - ptr = new int[3][4]


    //manipulate allocated memory

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            *(*(ptr6+i)+j) = i+j; // this means ptr[i][j] = i+j
        
            cout << "ptr["<<i<<"]["<<j<<"] = "<<ptr6[i][j]<<" ";
        }
        cout << endl;
    }
    //free the allocated space, delete must used as much as new is used

    for(int i=0;i<3;i++){
        delete[] *(ptr6+i);
    }
    delete[] ptr6;

    cout<<"\n\n---------------3d array pointer-----------\n\n";


    ptr7 = new int **[2]; 

    for (int i=0;i<2;i++){
        *(ptr7+i) = new int *[3];
        for(int j=0;j<3;j++){
            *(*(ptr7+i)+j) = new int[4];
        }
    }

    //manipulate allocated memory

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<4;k++){
                *(*(*(ptr7+i)+j)+k) = i+j+k; // this means ptr[i][j] = i+j
       
                cout << "ptr["<<i<<"]["<<j<<"]["<<k<<"] ="<<*(*(*(ptr7+i)+j)+k)<<" ";
            }
        }
        cout << endl;
    }
    //free the allocated space, delete must used as much as new is used

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            delete[] *(*(ptr7+i)+j);
        }
        delete[] *(ptr7+i);
    }
    delete[] ptr7;

    cout<< "\n\n-------------function pointers----------\n\n";

    int a = 10,b =2;

    if(ptr_sum != &sum1)
        cout << "Error!";
    int res = (*ptr_sum)(a,b);  //function call through pointer
    cout <<"Sum is : "<<res<<endl;

    cout<< "\n\n------------using typedef-----------\n\n";

    typedef int (*ptr_sum_type)(int,int); 
    int a1 = 10,b1 =2;

    ptr_sum_type ptr_sum = &sum1;

    int res1 = (*ptr_sum)(a1,b1);  //function call through pointer
    cout <<"Sum is : "<<res1<<endl;


    cout<<"\n\n---------pointers as arguments-----------\n\n";

    int numbers[] = {10, 20, 30};
    increment_all(numbers, numbers + 3);
    print_all(numbers, numbers + 3);


    return 0;
}