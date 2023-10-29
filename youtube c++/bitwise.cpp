#include<iostream>
using namespace std;

int main()
{
    int a = 4, b = 6;
    cout<<"4 = 00000200 and 6 = 00000220"<<endl;
    // the operations happen bitwise...
    cout<<"a = "<<a<<endl<<"b = "<<b<<endl;
    cout<<"a AND b = "<<(a&b)<<endl;
    cout<<"a OR b = "<<(a|b)<<endl;
    cout<<"NOT a = " <<(~a)<<endl;
    cout<<"a XOR b = "<<(a^b)<<endl;
    
    // therefore 
    // right shift will divide the number by 2
    // left shift will multiply the number by 2
    cout<<"b right shift 1 = "<<(b>>1)<<endl;
    cout<<"b right shift 2 = "<<(b>>2)<<endl;
    cout<<"b left shift 1 = "<<(b<<1)<<endl;
    cout<<"b left shift 2 = "<<(b<<2)<<endl;
    
    //
    /*   increments and decrements
    i++ is post-increment (increase after use)
    ++i is pre-increment  (increase and then use)
    i-- is post-decrement (decrease after use)
    --i is pre-decrement  (decrease and then use)
    i = i + number is also i += number for post-increment
    i = i - number is also i -= number for post-decrement
    */
    return 0;
}