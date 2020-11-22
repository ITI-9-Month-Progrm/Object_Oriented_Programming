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
      delete [] Append.Stk;
      Append.Stk=new int [Append.Size];
      for(int i=0;i<Tos;i++){
        Append.Stk[i]=Stk[i];
        c++;
      }
      int j=0;
      for(int i=c;i<Append.Size;i++){
        Append.Stk[i]=Right.Stk[j];
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

    Stack S1(7),S2;

    S1.Push(3);
    S1.Push(5);
    S1.Push(7);

   /** for ( int i=0 ; i < S1.GetTos();i++)
       cout << S1[i] << endl;**/

   /// S2 = S1;

      S2.Push(3);
    S2.Push(5);
    S2.Push(7);

    ///cout<< S2.Pop() <<endl;

    S2.Push(11);

   // cout<< S1.Pop()<<endl;

  Stack S3=S1+S2;


 for ( int i=0 ; i < S3.getSize();i++)
       cout << S3[i] << endl;

   return 0;
}
