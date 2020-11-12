#include <iostream>

using namespace std;

struct Complex {
private:
    int real;
    int imag;
public:
    void setReal(int value){
    real=value;
    }
     void setImag(int value){
    imag=value;
    }

    int getReal(){
    return real;
    }

    int getImag(){
    return imag;
    }

  Complex subTwoNumbers(Complex C){
  Complex X;
  X.real=real-C.real;
  X.imag=imag-C.imag;
  return X;

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
Complex sumTwoNumbers(Complex c ,Complex x){
   Complex res;
   int re,ig;
   re=c.getReal()+x.getReal();
   res.setReal(re);
   ig=c.getImag()+x.getImag();
   res.setImag(ig);

   return res;
}





int main()
{
    Complex c1,c2,c3,c4;
    int num1,num2,num3,num4;
    cout<<"Please Enter Values of c1 "<<endl;
    cin>>num1>>num2;
    c1.setReal(num1);
    c1.setImag(num2);
    cout<<"RealNumber : "<<c1.getReal()<<endl;
    cout<<"ImagenNumber : "<<c1.getImag()<<endl;
    cout<<"Please Enter Values of c2"<<endl;
    cin>>num1>>num2;
    c2.setReal(num1);
    c2.setImag(num2);
    cout<<"RealNumber : "<<c2.getReal()<<endl;
    cout<<"ImagenNumber : "<<c2.getImag()<<endl;
    cout<<endl;
    c3=sumTwoNumbers(c1,c2);
    c4=c1.subTwoNumbers(c2);

    cout<<"The Result of Summation : "<<" ";c3.printComplix();cout<<endl;
    cout<<"The Result of Substation : "<<" ";c4.printComplix();cout<<endl;
    c1.printComplix();
    c2.printComplix();

    return 0;
}
