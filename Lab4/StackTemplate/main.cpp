#include <iostream>

using namespace std;

class Complex{
int real,imag;
public:
    void setReal(int R){
        real=R;}
     void setImag(int I){

     imag=I;
     }

     int getReal(){
     return real;}

     int getImag(){
     return imag;
     }
    Complex(int R,int I){
       /// cout<<"Two Value"<<endl;
      real=R;
      imag=I;
    }
    Complex(int value){
        ///cout<<"One Value"<<endl;
    real=imag=value;
    }

    Complex(){
       /// cout<<"Zero Value"<<endl;
    real=imag=0;
    }
    //copy constructor
    Complex(Complex& oldC){
     real=oldC.real;
     imag=oldC.imag;
    ///cout<<"Copy Const"<<endl;

    }

    ~Complex(){

    ///cout<<"Object is Ended"<<real<<imag<<endl;
    }

    static Complex Sum(Complex Cx,Complex Cy){///don't need to caller
      Complex Res;
      Res.real=Cx.real+Cy.real;
      Res.imag=Cx.imag+Cy.imag;
      return Res;

    }

    static Complex Sub(Complex Cx,Complex Cy){
      Complex Res;
      Res.real=Cx.real-Cy.real;
      Res.imag=Cx.imag-Cy.imag;
      return Res;

    }


  void printComplix(){

      if(real>1 && imag>1){
        cout<<real<<"+"<<imag<<"i"<<endl;
      }
      else if((real<0 && real!=-1) && (imag<0 && imag!=-1) ){
        cout<<real<<imag<<"i"<<endl;
      }
      else if(real>0 && (imag<0 && imag!=-1) ){
        cout<<real<<imag<<"i"<<endl;
      }
      else if( (real>0 || real<0) && imag==1){

        cout<<real<<"+"<<"i"<<endl;
      }
      else if( (real>0 || real<0)&& imag==-1){

        cout<<real<<"-"<<"i"<<endl;
      }
      else if(real==0 && imag>1 ){
        cout<<imag<<"i"<<endl;
      }
      else if(imag==0 && real>1){
        cout<<real<<endl;
      }

  }
};
template<class T>
class Stack
{
    T *Stk;
    int Tos , Size;
    static int stackCounter;


public:

    Stack(int L=5) //default Value
    {
       /// cout<< "Constructor \n";
        Tos = 0;
        Size = L;
        Stk = new T[Size];
    }
///Copy Constructor

    Stack(Stack<T>& oldS){
        ///cout<<"Copy Constructor"<<endl;
    Size=oldS.Size;
    Tos=oldS.Tos;
    Stk=new T [Size];
    for(int i=0;i<Size;i++){
        Stk[i]=oldS.Stk[i];
    }
     ++stackCounter;
    }

    ~Stack()
    {
        ///cout<<"Destructor"<<endl;

        for(int i=0;i<Size;i++) Stk[i]=-1;
        delete []Stk;
        --stackCounter;
    }

    static int GetStackCounter ()
    {
        return stackCounter;
    }

    int IsFull () { return (Tos == Size) ;}

    int IsEmpty() { return Tos ==0;}

    void Push (T n);

    T Pop();

    T Peak();

    friend void viewContent(Stack<T> &s){
     for(int i=0;i<s.Tos;i++){
    cout<<s.Stk[i]<<endl;
  }

    }
};

//:: Called Scope Operator

template<class T>
int Stack<T>::stackCounter=0;

template<class T>
void Stack<T>::Push (T n)
{
    if ( IsFull()== false)
        Stk[Tos++] = n;
    else
        cout << "Stack is Full \n";
}

template<class T>
T Stack<T>::Pop()
{
    if ( !IsEmpty())
        return Stk[--Tos];
}

template<class T>
T Stack<T>::Peak()
{
    if(IsEmpty()){
        return -111;
    }
    else
    return Stk[Tos-1];
}

int main()
{
    Stack<int> s1;

    Stack<char> s2;

    Stack <Complex> s3;

    Complex c1(3,4),c2(5),c3,c4;
    c3=Complex::Sum(c1,c2);
    c4=Complex::Sub(c1,c2);

  cout<<"number of Stack int: "<<Stack<int>::GetStackCounter()<<endl;
  cout<<"View Content of S1"<<endl;
   s1.Push(3);
   s1.Push(4);
   s1.Push(5);
   viewContent(s1);

  cout<<"number of Stack char: "<<Stack<char>::GetStackCounter()<<endl;
  cout<<"View Content of S2"<<endl;
   s2.Push('A');
   s2.Push('S');
   s2.Push('M');
   s2.Push('A');
   s2.Push('A');
   viewContent(s2);

   cout<<"number of Stack Complex: "<<Stack<Complex>::GetStackCounter()<<endl;
   cout<<"View Content of S3"<<endl;
   s3.Push(c1);
   s3.Push(c2);
   s3.Push(c3);
   s3.Push(c4);
   cout<<"The c4"<<endl;
   s3.Pop().printComplix();
   cout<<"The c3"<<endl;
   s3.Pop().printComplix();
   cout<<"The c2"<<endl;
   s3.Pop().printComplix();
   cout<<"The c1"<<endl;
   s3.Pop().printComplix();










    return 0;
}
