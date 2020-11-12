#include <iostream>

using namespace std;

void swapByValue(int num1,int num2){
int temp;
temp=num1;
num1=num2;
num2=temp;
cout<<"number1 : "<<num1<<" "<<"number2 : "<<num2<<endl;
}

void swapByAddress(int *num1,int *num2){
int temp;
temp=*num1;
*num1=*num2;
*num2=temp;
}

void swapByReference(int &num1,int &num2){
int temp;
temp=num1;
num1=num2;
num2=temp;

}


int main()
{
    int choice ,number1,number2;

    cout<<"Please Enter Values of Number1 and Number2"<<endl;
    cin>>number1>>number2;
    cout<<"number1 : "<<number1<<" "<<"number2 : "<<number2<<endl;
    cout<<"Please Enter 1 to swap by value"<<endl;
    cout<<"Please Enter 2 to swap by address"<<endl;
    cout<<"Please Enter 3 to swap by Reference"<<endl;
    cin>>choice;

    switch(choice){
        case 1:
            swapByValue(number1,number2);
        break;
        case 2:
            swapByAddress(&number1,&number2);
            cout<<"number1 : "<<number1<<" "<<"number2 : "<<number2<<endl;
        break;
        case 3:
            swapByReference(number1,number2);
            cout<<"number1 : "<<number1<<" "<<"number2 : "<<number2<<endl;
        break;

    }



    return 0;
}
