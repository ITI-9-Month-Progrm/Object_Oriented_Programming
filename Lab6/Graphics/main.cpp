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
    print()
    {

    }
};
class Rect :protected shape{
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
    print()
    {
        setcolor(color);
        rectangle(UL.GetX(),UL.GetY(),LR.GetX(),LR.GetY());
    }

    ~Rect() { }
};
class circ:protected shape{
    Point p1;
    int rad;
public:
    circ (Point P1 , int radi,int C): p1(P1)
    {
        color = C;
        rad=radi;
    }
     print()
    {
        setcolor(color);
        circle(p1.GetX(),p1.GetY(),rad);
    }
};
class Line :protected shape{
    Point p1,p2;
public:
    Line (Point P1 , Point P2,int C):p1(P1),p2(P2)
    {
        color = C;
    }
    print()
    {
        setcolor(color);
        line(p1.GetX(),p1.GetY(),p2.GetX(),p2.GetY());
    }
};
class trian :protected shape{
    Point p1,p2,p3;
public:
    trian (Point P1 , Point P2,Point P3,int C):p1(P1),p2(P2),p3(P3)
    {
        color = C;
    }
    print()
    {
        setcolor(color);
        line(p1.GetX(),p1.GetY(),p2.GetX(),p2.GetY());
        line(p1.GetX(),p1.GetY(),p3.GetX(),p3.GetY());
        line(p2.GetX(),p2.GetY(),p3.GetX(),p3.GetY());
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
c.print();

circ c2(pc,130,7);
c2.print();

Rect r(v1,v2,5);
r.print();

trian t(T1,T2,T3,5);
t.print();

Point line1(170,100);
Point line2(130,250);
Line l (line1,line2,7);
l.print();

Point lin1(230,100);
Point lin2(270,250);
Line l2 (lin1,lin2,7);
l2.print();

Point lin3(230,310);
Point lin4(230,350);
Line l3 (lin3,lin4,7);
l3.print();

Point lin5(180,310);
Point lin6(180,350);
Line l4 (lin5,lin6,7);
l4.print();

    return 0;
}
