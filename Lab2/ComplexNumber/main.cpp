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
        cout<<"Two Value"<<endl;
      real=R;
      imag=I;
    }
    Complex(int value){
        cout<<"One Value"<<endl;
    real=imag=value;
    }

    Complex(){
        cout<<"Zero Value"<<endl;
    real=imag=0;
    }
    ~Complex(){
    cout<<"Object is Ended"<<real<<imag<<endl;
    }

    Complex Sum(Complex C){  //in case &C  return 4 destractor
      Complex Res;
      Res.real=real+C.real;
      Res.imag=imag+C.imag;
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

int main()
{
   Complex c1(3,4),c2(5),c3;

   cout<<c3.getReal()<<endl;
   c3=c1.Sum(c2);
   c3.printComplix();
    return 0;
}
