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

    ~Stack()
    {
        cout<<"Dest.";
        delete []Stk;
    }

    int IsFull () { return (Tos == Size) ;}

    int IsEmpty() { return Tos ==0;}

    void Push (int n);

    int Pop();

    int Peak();
};

//:: Called Scope Operator
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
    return Stk[Tos-1];
}

int main()
{
   Stack s1(5);
   s1.Push(3);
   s1.Push(4);
   s1.Push(5);


   cout<<s1.Peak()<<endl;
   cout<<s1.Peak()<<endl;

   cout<<s1.Pop()<<endl;


    return 0;
}
