//with copy Constructor and with passed by Reference

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
    friend void viewContent(Stack &s);
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
    if(IsEmpty()){
        return -111;
    }
    else
    return Stk[Tos-1];
}

void viewContent(Stack &s){


  for(int i=0;i<s.Tos;i++){
    cout<<s.Stk[i]<<endl;
  }


}
int main()
{
   Stack s1(5);
   s1.Push(3);
   s1.Push(4);
   s1.Push(5);
   cout<<"with copy Constructor and with passed by Reference"<<endl;
   viewContent(s1);
   cout<<endl<<endl;
   cout<<s1.Peak()<<endl;
   cout<<s1.Peak()<<endl;
   cout<<s1.Pop()<<endl;


    return 0;
}
