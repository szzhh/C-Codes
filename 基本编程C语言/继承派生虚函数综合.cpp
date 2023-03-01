#include<iostream>
using namespace std;
class Shape
{
   public:
         virtual float area( ) const {return 0.0;}      //虚函数
         virtual float volume() const {return 0.0;}  //虚函数
         virtual void shapeName() const = 0;          //纯虚函数
};
class Point: public Shape //Point是Shape的公用派生类
{  public:
         Point(float,float);
         void setPoint(float a=0, float b=0);
         float getX( ) const {return x;}
         float getY( ) const {return y;}
         virtual void shapeName( ) const {cout << "Point:";} 
                                     //对虚函数进行再定义
         friend ostream & operator<<(ostream &, const Point &);
   protected:    float x,y;
};
 Point::Point(float a=0 , float b=0 )
{x=a;y=b;
}

void Point::setPoint(float a, float b)
{x = a; y = b;}

ostream & operator<<(ostream & output, const Point &p)
{
     output << "[" << p.x << "," << p.y << "]";
     return output;
}
class Circle: public Point
{  public:
         Circle(float, float, float);
         void setRadius(float);
         float getRadius() const;
         virtual float area() const;
         virtual void shapeName() const { cout << "Circle:";}
                                               //对虚函数进行再定义
         friend ostream &operator<<(ostream &, const Circle &);
   protected: float radius;
};
Circle::Circle(float a = 0, float b = 0, float r = 0)
     : Point(a, b), radius(r) { }

void Circle::setRadius(float r){ radius=r;}

float Circle::getRadius( ) const {return radius;}

float Circle::area() const {return 3.14159*radius*radius;}

ostream &operator<<(ostream & output, const Circle &c)
{   output << "[" << c.x <<"," << c.y << "], r=" << c.radius;
     return output;
}
class Cylinder: public Circle
{  public:
         Cylinder (float a , float , float , float );
         void setHeight(float);
         virtual float area() const;
         virtual float volume() const;
         virtual void shapeName() const {cout << "Cylinder:";}
                                           //对虚函数进行再定义
         friend ostream & operator<<(ostream&, const Cylinder&);
    protected:   float height;
};
Cylinder::Cylinder(float a = 0, float b = 0, float r = 0, float h = 0)
    :Circle(a,b,r), height(h){ }
void Cylinder::setHeight(float h) {height = h;}
float Cylinder::area( ) const
{ return 2*Circle::area( )+2*3.14159*radius*height;}
float Cylinder::volume( ) const
{return Circle::area( )*height;}
ostream &operator<<(ostream &output, const Cylinder& cy)
{   output << "[" << cy.x <<"," << cy.y << "], r=" 
                << cy.radius << ", h="<< cy.height;
     return output;     
}
main( )
{    Point point(3.2,4.5);                          //建立Point类对象
     Circle circle(2.4,1.2,5.6);                  //建立Circle类对象
     Cylinder cylinder(3.5,6.4,5.2,10.5); //建立Cylinder类对象
     point.shapeName(); cout << point << endl;              //静态关联
     circle.shapeName(); cout << circle << endl;             //静态关联
     cylinder.shapeName(); cout << cylinder << endl;
     Shape *pt;                                     //定义基类指针
     pt = &point;                                  //指针指向Point类对象
     pt->shapeName();                        //动态关联
     cout << "x=" << point.getX() << ",y=" << point.getY()
             << "\narea=" << pt->area() << "\nvolume="
             << pt->volume() << "\n\n";
     pt = &circle;                                    //指针指向Circle类对象
     pt->shapeName();                       //动态关联
     cout << "x=" << circle.getX() << ",y=" << circle.getY() 
             << "\narea=" << pt->area() << "\nvolume="
             << pt->volume() << "\n\n";
     pt=&cylinder;                              //指针指向Cylinder类对象
     pt->shapeName( );                                //动态关联
     cout << "x=" << cylinder.getX() << ",y=" << cylinder.getY() 
             << "\narea=" << pt->area() << "\nvolume="
             << pt->volume() << "\n\n";
}
