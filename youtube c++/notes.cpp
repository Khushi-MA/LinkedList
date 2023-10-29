#include<iostream>
using namespace std;

int main()
{
    int amt,hundred, tens, coins;
    int notes[10] = {0};
    cout<<"enter the amount:  ";
    cin>>amt;
    hundred = amt/100;
    amt -= hundred*100;
    tens = amt/20;
    amt -= tens*10;
    coins = amt;

    cout<<hundred<<" "<<tens<<" "<<coins;
    for(int i=0;i<10;i++)
    {
        cout<<endl<<notes[i];
    }
    return 0;
    

}