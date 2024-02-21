#include<iostream>
using namespace std;

enum months_t
{
        Jan = 1, Feb, Mar, Apr, May, June, July, Aug, Sep, Oct, Nov, Dec
}month;

void Janua(){
    cout << Jan;
}
int main(){
    for(int i=Jan;i<=Dec;i++){
        cout << i<<" ";
    }
    Janua();
    
    return 0;
}
