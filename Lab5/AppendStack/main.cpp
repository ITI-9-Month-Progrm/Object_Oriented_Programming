#include<iostream>
using namespace std;

class Stack
{
    int *Stk;
    int Tos , Size;
    static int StackCounter ; //Class Attribute not Object Attribute

public:





    static int GetStackCounter ()
    {
        return StackCounter;
    }

    Stack(int L=5)
    {

        Tos = 0;
        Size = L;
        Stk = new int[Size];
        StackCounter++;
    }

    ~Stack()
    {


        for ( int i=0 ; i < Tos ; i ++) Stk[i] = -1;

        delete []Stk;
        StackCounter--;
    }

    //Copy Ctor
    Stack(const Stack& OldS)
    {
        Size = OldS.Size;
        Tos = OldS.Tos;

        Stk = new int[Size];

        for ( int i=0 ; i < Tos ; i++)
            Stk[i] = OldS.Stk[i];


        StackCounter++;
    }


    int IsFull () { return (Tos == Size) ;}

    int IsEmpty() { return Tos ==0;}

    void Push (int n);

    int Pop();

    const Stack& operator = (const Stack & Right)
    {
        Size = Right.Size;
        Tos = Right.Tos;

        delete [] Stk;

        Stk = new int[Size];

        for (int i=0 ; i < Tos ; i++)
            Stk[i] = Right.Stk[i];


        return Right;
    }

    int GetTos () { return  Tos;}
     int getSize(){return Size;}


    int operator[] (int Index)
    {
        if ((Index >=0)&&(Index<Tos))
            return Stk[Index];
    }


    Stack operator + (Stack &Right){
      Stack Append;int c=0;
      Append.Size=Tos+Right.Tos;
      for(int i=0;i<Tos;i++){
        Append.Push(Stk[i]);
        c++;
      }
      int j=0;
      for(int i=c;i<Append.Size;i++){
        Append.Push(Right.Stk[j]);
        j++;

      }

       return Append;  ///call temp constructor
   }


};


int Stack::StackCounter = 0;

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



int main()
{

    Stack S1(7),S2,S3,S4;

    S1.Push(3);
    S1.Push(5);
    S1.Push(7);

    S2.Push(3);
    S2.Push(5);
    S2.Push(7);
    S2.Push(11);
    S2.Push(3);

     S3 = S1;
     cout<<"Elements of S3:"<<endl;

    for ( int i=0 ; i < S3.GetTos();i++)
       cout << S3[i] << endl;
S4=S1+S2;   ///3 5 7 3 5 7 11 3

cout<<"Elements of S4:"<<endl;
 for ( int i=0 ; i < S4.getSize();i++)   ///don't print True values but values found S4,Stk[i]
       cout << S4[i] << endl;

   return 0;
}
