//without copy Constructor and with passed by Value

#include <iostream>

using namespace std;

class Stack
{
    int *Stk;
    int Tos , Size;

public:

    Stack(int L)
    {
        cout<< "Ctor \n";
        Tos = 0;
        Size = L;
        Stk = new int[Size];
    }

   Stack(Stack& oldS){
    Size=oldS.Size;
    Tos=oldS.Tos;
    Stk=new int [Size];
    for(int i=0;i<Size;i++){
        Stk[i]=oldS.Stk[i];
    }
    cout<<"Copy Const"<<endl;
    }

    ~Stack()
    {
        cout<<"Dest."<<endl;

        for(int i=0;i<Size;i++) Stk[i]=-1;
        delete []Stk;
    }


    int IsFull () { return (Tos == Size) ;}

    int IsEmpty() { return Tos ==0;}

    void Push (int n);

    int Pop();

    int Peak();
    Stack Reverse();
};

//:: Called Scope Operator
Stack Stack::Reverse()
{
    Stack z(Size);

    while(!IsEmpty()){
         z.Push(Pop());
    }
    return z;

}
void Stack::Push (int n)
{
    if ( IsFull()== false)
        Stk[Tos++] = n;
    else
        cout << "Stack is Full \n";
}

int Stack::Pop()
{
    if ( !IsEmpty())
        return Stk[--Tos];
}

int Stack::Peak()
{
    if(!IsEmpty()){
        return Stk[Tos-1];
    }


}





int main()
{
   Stack s1(5),s(5);
   s1.Push(3);
   s1.Push(4);
   s1.Push(5);
   cout<<"without copy Constructor and passed by Value"<<endl;
   cout<<"Reverse"<<endl;

   cout<<s1.Reverse().Pop()<<endl;




    return 0;
}
