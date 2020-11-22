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
      real=R;
      imag=I;
    }
    Complex(int value){

    real=imag=value;
    }

    Complex(){

    real=imag=0;
    }
    //copy constructor
    Complex(Complex& oldC){
     real=oldC.real;
     imag=oldC.imag;


    }

    ~Complex(){}



/// Cout Overloading
  friend ostream &operator<<( ostream &output, const Complex &C ) {
         if(C.imag<0){
            output << C.real << C.imag<<"i";
         }
         if else(C.imag==0){
                output << C.real ;
         }
           else
           {
               output<<C.real<<"+("<<C.imag<<"i)"<<endl;
           }
         return output;
      }
/// Cin overloading
  friend   istream &operator>>( istream  &input, Complex &C) {
         input >> C.real>>C.imag;
         return input;
      }

};

int main()
{
    Complex c1;
    cout<<"Please Enter Complex Number"<<endl;
    cin>>c1;
    cout<<"Complex Number is : "<<endl;
    cout<<c1;












    return 0;
}
