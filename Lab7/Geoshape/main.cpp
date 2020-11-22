#include <iostream>
using namespace std;

///General Class
class Shape
{
protected:
    int X,Y;
public:
    Shape() {X = Y = 0; }
    Shape(int _X , int _Y) {X = _X ; Y = _Y ; }
    Shape (Shape& P) { X = P.X ; Y = P.Y; }
    ~Shape() {}

    int GetX() { return X;}
    int GetY() { return Y;}

    void SetX(int _X) { X = _X;}
    void SetY(int _Y) { Y = _Y;}
    virtual float calcArea()=0;  ///for overriding


};

class Rect : public Shape {
public:
     Rect(int x1,int y1):Shape(x1,y1)
    {

    }
    float calcArea()
    {
        cout<<X*Y<<endl;
        return X*Y;
    }

    ~Rect() { }
};
class circ:public Shape{

public:
    circ (int l): Shape(l,l)
    {
    }
     float calcArea()
    {
        cout<<3.14*X*X<<endl;
        return 3.14*X*X;
    }
};

class trian :public Shape{

public:
    trian (int x,int y):Shape(x,y)
    {

    }
    float calcArea()
    {
        cout<<0.5*X*Y<<endl;
        return  0.5*X*Y;
    }
};
float sumofArea(Shape** arr,int sizee)
{
    float sum=0;
    for(int i=0;i<sizee;i++)
    {
      sum+=  arr[i]->calcArea();
    }
    cout<<sum<<endl;
    return sum;
}
int main()
{
    Shape* myarr[5]={new Rect(5,5),new Rect(2,2),new circ(3),new trian(4,4),new trian(5,4)};
    sumofArea(myarr,5);
    return 0;
}
