#include <iostream>

using namespace std;

class Complex {
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
  void printComplix(Complex c){
      if(c.real>1 && c.imag>1){
        cout<<c.real<<"+"<<c.imag<<"i"<<endl;
      }
      else if((c.real<0 && c.real!=-1) && (c.imag<0 && c.imag!=-1) ){
        cout<<c.real<<c.imag<<"i"<<endl;
      }
      else if(c.real>0 && (c.imag<0 && c.imag!=-1) ){
        cout<<c.real<<c.imag<<"i"<<endl;
      }
      else if( (c.real>0 || c.real<0) && c.imag==1){

        cout<<c.real<<"+"<<"i"<<endl;
      }
      else if( (c.real>0 || c.real<0)&& c.imag==-1){

        cout<<c.real<<"-"<<"i"<<endl;
      }
      else if(c.real==0 && c.imag>1 ){
        cout<<c.imag<<"i"<<endl;
      }
      else if(c.imag==0 && c.real>1){
        cout<<c.real<<endl;
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
    cout<<"Please Enter Values of c2"<<endl;
    cin>>num1>>num2;
    c2.setReal(num1);
    c2.setImag(num2);
    c3=sumTwoNumbers(c1,c2);
    c4=c1.subTwoNumbers(c2);
    cout<<"res : "<<" RealNumber: "<<c3.getReal()<<" ImagNumber: "<<c3.getImag()<<endl;
    c4.printComplix(c4);
    return 0;
}
