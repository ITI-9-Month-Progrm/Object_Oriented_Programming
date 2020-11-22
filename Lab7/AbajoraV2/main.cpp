#include <iostream>
#include "graphics.h"
using namespace std;

class Point
{
    int X,Y;
public:
    Point() {X = Y = 0; }
    Point(int _X , int _Y) {X = _X ; Y = _Y ; }
    Point (Point& P) { X = P.X ; Y = P.Y; }
    ~Point() {}

    int GetX() { return X;}
    int GetY() { return Y;}

    void SetX(int _X) { X = _X;}
    void SetY(int _Y) { Y = _Y;}

    void Show()
    {
        cout<<"("<<X<<","<<Y<<")\n";
    }

};
class shape{

protected:
    int color;
public:
    shape()
    {

    }
    virtual void print()
    {
    }
    ~shape(){}
};
class Rect :public shape{
public:
    Point UL ,LR;

     Rect()
    {
        color = 0;

    }

    Rect(int X1 , int Y1 , int X2 , int Y2 , int C):UL(X1,Y1) , LR(X2,Y2)
    {
        color = C;

    }
    Rect (Point P1 , Point P2,int C): UL(P1) , LR(P2)
    {
        color = C;
    }
    void print()
    {
        setcolor(color);
        rectangle(UL.GetX(),UL.GetY(),LR.GetX(),LR.GetY());
    }

    ~Rect() { }
};
class circ:public shape{
    Point p1;
    int rad;
public:
    circ (Point P1 , int radi,int C): p1(P1)
    {
        color = C;
        rad=radi;
    }
     void print()
    {
        setcolor(color);
        circle(p1.GetX(),p1.GetY(),rad);
    }
};
class Line :public shape{
    Point p1,p2;
public:
    Line (Point P1 , Point P2,int C):p1(P1),p2(P2)
    {
        color = C;
    }
    void print()
    {
        setcolor(color);
        line(p1.GetX(),p1.GetY(),p2.GetX(),p2.GetY());
    }
};
class trian :public shape{
    Point p1,p2,p3;
public:
    trian (Point P1 , Point P2,Point P3,int C):p1(P1),p2(P2),p3(P3)
    {
        color=C;
    }
    void print()
    {
        setcolor(color);
        line(p1.GetX(),p1.GetY(),p2.GetX(),p2.GetY());
        line(p1.GetX(),p1.GetY(),p3.GetX(),p3.GetY());
        line(p2.GetX(),p2.GetY(),p3.GetX(),p3.GetY());
    }
};
class picture{
protected:
    shape** myarr;
    int sizee;
public:
    picture(shape** arr,int s)
    {
        myarr=arr;
        sizee=s;
    }
    ~picture(){}
    void printPic()
    {
        for(int i=0;i<sizee;i++)
        {
            myarr[i]->print();
        }
    }
};
int main()
{

initgraph();
Point p1(200,100);
Point p2(600,600);
Point pc(200,250);
Point v1(100,350);
Point v2(300,400);
Point T1(260,350);
Point T2(220,400);
Point T3(300,400);

circ c(p1,60,7);

circ c2(pc,130,7);

Rect r(v1,v2,5);

trian t(T1,T2,T3,5);

Point line1(170,100);
Point line2(130,250);
Line l (line1,line2,7);

Point lin1(230,100);
Point lin2(270,250);
Line l2 (lin1,lin2,7);

Point li1(230,310);
Point li2(230,350);
Line l3 (li1,li2,7);

Point lii1(180,310);
Point lii2(180,350);
Line l4 (lii1,lii2,7);

shape* myarr[8]={new circ(p1,60,7),
                 new circ(pc,130,7),new Rect(v1,v2,5),
                 new trian(T1,T2,T3,5),new Line(line1,line2,7),
                 new Line(lin1,lin2,7),new Line(li1,li2,7),
                 new Line(lii1,lii2,7)};
picture p(myarr,8);
p.printPic();
    return 0;
}
