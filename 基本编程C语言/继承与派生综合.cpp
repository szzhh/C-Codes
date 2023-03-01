#include<iostream>
using namespace std;class Point
{public:
     Point(float, float);                   //构造函数
     void setPoint(float, float);      //设置坐标值
     float getX( ) const {return x;}//读x坐标
     float getY( ) const {return y;}//读y坐标
     friend ostream & operator << (ostream &, 
                            const Point &);  //重载运算符“<<”
protected: 
     float x, y;
};
//Point的构造函数
Point::Point(float a=0, float b=0) { x = a; y = b;} //对x, y初始化
//设置x和y的坐标值
void Point::setPoint(float a, float b)         //为x, y赋新值
{x=a; y=b;}
//重载运算符“<<”，使之能输出点的坐标
ostream & operator<<(ostream & output, const Point & p)
{
     output<<"["<<p.x<<","<<p.y<<"]"<<endl;
     return output;
}
class Circle: public Point  //circle是Point类的公用派生类
{public:
     Circle(float, float, float);  //构造函数
     void setRadius(float);       //设置半径值
     float getRadius( ) const;   //读取半径值
     float area ( ) const;            //计算圆面积
     friend ostream & operator << (ostream &,
                          const Circle &);        //重载运算符“<<”
 private:
  float radius;
};
//定义构造函数，对圆心坐标和半径初始化
Circle::Circle(float a = 0, float b = 0, float r = 0)
     :Point(a, b) { radius = r; }
//设置半径值
void Circle::setRadius(float r) {radius = r;}
//读取半径值
float Circle::getRadius( ) const {return radius;}
//计算圆面积
//计算圆面积
float Circle::area( ) const {return 3.14159*radius*radius;}
//重载运算符“<<”，使之按规定的形式输出圆的信息
ostream &operator<<(ostream &output,const Circle &c)
{ output << "Center=[" << c.x << "," << c.y << "],r=" << 
               c.radius << ",area=" << c.area() << endl;
 return output;
}
class Cylinder: public Circle// 从Circle类公有继承过来
{public:
     Cylinder (float, float, float, float);//构造函数
     void setHeight(float);                     //设置圆柱高
     float getHeight( ) const;                 //读取圆柱高
     float area( ) const;                          //计算圆表面积
     float volume( ) const;                     //计算圆柱体积
     friend ostream & operator << (ostream&,
                      const Cylinder&);         //重载运算符“<<”
 protected:  float height;                               //圆柱高
};
//定义构造函数
Cylinder::Cylinder(float a = 0, float b = 0, float r = 0, 
           float h= 0): Circle(a,b,r), height(h) {  }
//设置圆柱高
void Cylinder::setHeight(float h) {height = h;}
//读取圆柱高
float Cylinder::getHeight( ) const {return height;}//计算圆表面积
float Cylinder::area( ) const
{ return 2*Circle::area( )+2*3.14159*Circle::getRadius()*height;}
//计算圆柱体积
float Cylinder::volume() const {return Circle::area()*height;}
//重载运算符“<<”
ostream & operator << (ostream & output, const Cylinder & cy)
{
     output << "Center=[" << cy.x << "," << cy.y << "],r=" << 
               cy. getRadius() << ",h=" << cy.height << "\narea=" << 
               cy.area() << ", volume=" << cy.volume( ) << endl;
     return output;
}
main( )
{
     Cylinder cy1(3.5,6.4,5.2,10);//定义Cylinder类对象cy1
     cout << "original cylinder:\nx=" << cy1.getX() << ", y="
             << cy1.getY() << ", r=" <<cy1.getRadius( ) << ", h=" 
             << cy1.getHeight() << "\narea=" << cy1.area()
             << ",volume=" << cy1.volume() << endl;//用系统定义的运
             cout<<"\n"<<cy1;                                           //算符“<<”输出cy1的数据
     cy1.setHeight(15);                    //设置圆柱高
     cy1.setRadius(7.5);                  //设置圆半径
cy1.setPoint(5,5);                     //设置圆心坐标值x, y
     cout << "\nnew cylinder:\n" << cy1;   //用重载运算符“<<”
                                                        //输出cy1的数据
     Point & pRef = cy1;        //pRef是Point类对象的引用变量
     cout << "\npRef as a Point:" << pRef; //pRef作为“点”输出
     Circle &cRef=cy1;          //cRef是Circle类对象的引用变量
     cout << "\ncRef as a Circle:" << cRef; //cRef作为“圆”输出
     return 0;
}
