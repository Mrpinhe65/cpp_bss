/*
 * 多态和虚函数的使用
 */

#include <iostream>
using namespace std;

class Base {
public:
  // void Show() { cout << "Show() in Base" << endl; }
  virtual void Show() { cout << "Show() in Base" << endl; }
};

class D : public Base {
public:
  void Show() { cout << "Show() in D" << endl; }
  void Print() { cout << "Print() in D" << endl; }
};

class C : public D {
public:
  void Show() { cout << "Show() in C" << endl; }
};

int main(int argc, char *argv[]) {
  cout << "\n//子类对象给父类赋值" << endl;
  D d;
  Base b;
  b = d;

  cout << "\n//父类指针指向子类对象地址" << endl;
  Base *pb = &d;

  cout << "\n//子类对象初始化父类的引用" << endl;
  Base &bf = d;

  cout << "\n//多态的实现" << endl;
  cout << "//1.父类指针指向子类地址 Base*pb=&d; bp->Show();" << endl;
  // pb->Show(); // 父类指针目前只能访问子类中继承父类来的方法
  cout << "\n// 在父类的方法名前加virtual 就可以调动子类的方法" << endl;
  pb->Show(); // 在父类方法前加virtuall 父类指针可以调用子类方法

  cout << "\n//多态的实现" << endl;
  cout << "//1.子类对象初始化父类引用 Base &br=d; br.Show();" << endl;
  Base &br = d;
  br.Show();

  cout << "//继承可以传承,C类继承D类，Show()方法是Base类虚函数\n从Base->D->C "
          "Show()都是虚函数\n而D类中的新增的Printf()则不是虚函数"
       << endl;
  cout << "某个类中的函数/方法声明为虚函数之后 在整个继承体系中都是虚函数\n "
          "可以加virtual 声明 也可以不加virtul\n 条件 函数名相同 返回值相同 "
          "参数列表相同"
       << endl;
  C c;
  D *pd = &c;
  pd->Show();
  pd->Print();
  cout << "//c对象调用D类的Printf()方法 c.Print();" << endl;
  c.Print();

  return 0;
}
