#include<iostream>
using namespace std;
class A
{ public :
      void  get_XY()   {  cin >> x >> y ; }
      void  put_XY()  { cout << "x = "<< x << ", y = " << y << '\n' ; }
   protected:    int x, y ;
};
class B : public A
{ public :
      int  get_S() { return s ; };
      void  make_S()  { s = x * y ; }; // 使用基类数据成员x，y
   protected:   int s;
};
class C : public B
{ public : 
      void  get_H()   {  cin >> h ; } 
      int  get_V() {  return v ; }
      void  make_V() {make_S();v=get_S()*h;} //使用基类成员函数
   protected:    int h, v;
};
main()
{ A objA ;
   B objB ;
   C objC ;
   cout << "It is object_A :\n" ;
   objA.get_XY() ;
   objA.put_XY() ;
   cout << "It is object_B :\n" ;
   objB.get_XY() ;
   objB.make_S() ;
   cout << "S = " << objB.get_S() << endl ;
   cout << "It is object_C :\n" ;
   objC.get_XY();
   objC.get_H();
   objC.make_V();
   cout << "V = " << objC.get_V() << endl ;
}
