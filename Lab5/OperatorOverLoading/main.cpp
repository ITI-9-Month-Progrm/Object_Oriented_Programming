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

    ~Complex(){

    }
///Operator (-)

///c3=c1-c2

    Complex operator- (Complex &C){
      Complex Res ;
      Res.real=real-C.real;
      Res.imag=imag-C.imag;
      return Res;
    }
///c3=c1-7

Complex operator- (int R){
Complex Res ;
      Res.real=real-R;
      Res.imag=imag;
      return Res;

}

///c1-=c2

Complex& operator-=(Complex &R){

    real-=R.real;
    imag-=R.imag;
    return *this;
}

///c1-=7
Complex& operator-=(int R){
   real-=R;
   return *this;
}
 ///--c1
 Complex& operator--(){
    real--;
    imag--;
    return *this;

 }

 ///c1--
 Complex operator--(int){
     Complex Res(*this);
     real--;
     imag--;
     return Res;
 }

 ///c1==c2
 int operator==(Complex &C){
   return  ((real==C.real)&&(imag==C.imag));
 }

 ///c1!=c2
 int operator !=(Complex &C){
          return ((real!=C.real)&&(imag!=C.imag));
}
/// c1>c2
int operator>(Complex &C){
 return ((real>C.real)&&(imag>C.imag));
}
/// c1>=c2
int operator>=(Complex &C){
 return ((real>=C.real)&&(imag>=C.imag));
}
/// c1<c2
int operator<(Complex &C){
 return ((real<C.real)&&(imag<C.imag));
}
/// c1<=c2
int operator<=(Complex &C){
 return ((real<=C.real)&&(imag<=C.imag));
}

/// int Casting

 operator int() {
    return real;
}
///char*
operator char*() {
    char* temp=new char[2];
    temp[0]='0'+real;
    temp[1]='0'+imag;

    return temp;
}

  void printComplix(){

      if(real>1 && imag>1){
        cout<<real<<"+"<<imag<<"i"<<endl;
      }
      else if((real<0 ) && (imag<0 && imag!=-1) ){
        cout<<real<<imag<<"i"<<endl;
      }
      else if((real<0 ) && (imag>0) ){
        cout<<real<<"+"<<imag<<"i"<<endl;
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

///c3=7-c2
Complex operator-(int L ,Complex &R){
    Complex Res;
    Res.setReal(L-R.getReal());
    Res.setImag(R.getImag());
    return Res;

}

///7-=C1

Complex operator-=(int L ,Complex &R){
    R.setReal(L-R.getReal());
     R.setImag(R.getImag());
     return R;


}

int main()
{
     Complex c1(3,4),c2(5),c3;
    c3=c1-c2;
    c3.printComplix(); ///(3,4)-(5,5)=(-2,-1)
    cout<<endl;
    c3=7-c1;
    c3.printComplix(); ///7-(3,4)=(4,4)
    cout<<endl;
    c3=c1-7;
    c3.printComplix();///(3,4)-7=(-4,4)
    cout<<endl;
    c1-=c2;
    c1.printComplix();///(3,4)-(5,5) =(-2,-1)
    cout<<endl;
    7-=c1;
    c1.printComplix();///7-(-2,-1)=(9,-1)
    c1--;
    c1.printComplix();///(8,-2)
    --c1;
    c1.printComplix();///(7,-3)
    ///c1=(7,-3) ///c2=(5,5)
    (c1==c2)?cout<<"True"<<endl:cout<<"False"<<endl; ///f
    (c1!=c2)?cout<<"True"<<endl:cout<<"False"<<endl; ///t
    (c1>c2)?cout<<"True"<<endl:cout<<"False"<<endl; ///f
    (c1>=c2)?cout<<"True"<<endl:cout<<"False"<<endl; ///f
    (c1<c2)?cout<<"True"<<endl:cout<<"False"<<endl; ///f
    (c1<=c2)?cout<<"True"<<endl:cout<<"False"<<endl; ///f

    int X ;
    char *pst;
    X=int(c1);
    cout<<X<<endl;///7
    pst=(char*)c1;
    cout<<pst[0]<<"+"<<pst[1]<<"i"<<endl;












    return 0;
}
