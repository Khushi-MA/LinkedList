#include <iostream>
using namespace std;

// use loop to initialise array

class test
{
public:
    int data[5];

    test() {}
    test()
    {
        for (int i = 0; i < 5; i++)
            cin>>this->data[i];
    }

    void printdata()
    {
        for (int i = 0; i < 5; i++)
            cout << data[i] << "\t";

        cout << endl;
    }
};

int main()
{
    //int data[5] = {1, 2, 3, 4, 5};
    test obj();
    obj.printdata();
    return 0;
}

/*

class test{
    public:
    int &data;

    void printdata()
    {
        int i;
        for(i=0;i<5;i++)
        cout<<data[i]<<"\t";
        cout<<endl;
    }
}
*/