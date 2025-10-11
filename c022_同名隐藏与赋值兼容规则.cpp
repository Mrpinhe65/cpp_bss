#include <iostream>
using namespace std;

class Base {
private:
  int x;

public:
  Base() : x(0) { cout << "Create in Base!" << endl; }
  ~Base() { cout << "Free in Base!" << endl; }
  void Show() { cout << "Show in Base!" << endl; }
  void Show(int) { cout << "Show in Base!" << endl; }
};

class D : public Base {
private:
  int y;

public:
  D() : y(0) { cout << "Create in D" << endl; }
  ~D() { cout << "Free in D" << endl; }
  void Print() { cout << "Print in D" << endl; }
  void List() { cout << "List() in D!" << endl; }

  // 与父类同名函数 隐藏父类同名函数
  // 如无子类同名函数 则调用父类同名函数
  void Show() { cout << "Show in D" << endl; }
};

int main(int argc, char *argv[]) {
  cout << "c022_同名隐藏与赋值兼容规则" << endl;

  D d;
  d.Print();
  cout << "// 子类同名函数(仅指函数名相同 不包含参数)会隐藏父类同名函数"
       << endl;

  // 调用子类同名函数
  d.Show();
  // 加作用域调用父类同名函数
  d.Base::Show();

  // 1.赋值兼容规则
  cout << " // 1.赋值兼容规则\n // 子类对象可以赋值给基类对象 反之不可以"
       << endl;
  Base b;
  D d1;
  D d2;
  b = d1; // 子类对象可以赋值给基类对象 反之不可以
  // d2=b;

  // 2.子类对象指针可以给父类指针赋值，反之不可以
  cout << " // "
          "2.子类对象指针可以给父类指针赋值，反之不可以\n//"
          "针获得子类指针赋值后，可访问父类方法但不能访问字类方法"
       << endl;
  Base *pb; // 父类指针
  D *pd;    // 子类指针
  pb = pd;  // 赋值
  // 父类指针获得子类指针赋值后，可访问父类方法
  pb->Show();
  // pb->List(); // 父类指针即使获得子类指针赋值也不能访问子类
  pb->Show(0);

  // 3.父类引用子类做别名，也只能访问父类
  Base &bf = d1;
  bf.Show();
  bf.Show(0);
  // bf.List(); // 不能访问子类新方法和属性
  cout << "//子类给父类赋值其实是将子类中继承而来的父类的方法，不包括子类的方法"
       << endl;

  return 0;
}
