#include<iostream>
#include<climits>

using namespace std;


class Solution {
public:
    int reverse(int x) {
        
        int sol = 0, OG = x;
       // INT_MIN = 2^31    ...   INT_MAX = 2^-31 - 1
        while(x!=0){
            int digit = x%10;
            if(sol > (INT_MAX-1)/10 || sol < INT_MIN/10)
            return 0;
            sol = (sol*10) + digit;
            x = x/10;
        }
        
        return sol;
    }
};

int main()
{
    int number;
    cout<<"enter number to be reversed - ";
    cin>>number;
    number = reverse(number);
    cout<<"reverse of the given numebr is "<<number;
}
/// @brief /////////////////////////////////////////////////////
class test{
    public c:
    
}(

)
