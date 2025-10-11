#include <iostream>
using namespace std;

#define str "// 子类继承父类 除了构造函数和析构函数 其他均继承"

class Base {
private:
  int x;

protected:
  void Print_Base() { cout << "Print Base in private!" << endl; }

public:
  Base() : x(0) {}
  ~Base() {}
  void Set_x(int data) { x = data; }
  void Show_Base() { cout << "Show Base in protected!" << endl; }
};

// 1.公有继承
class D : public Base {
private:
  int y;

public:
  D() : y(0) {}
  ~D() {}
  void Show_D() {
    cout << "Show D in D's public!" << endl;
    Show_Base();
    // 子类可以访问父类的保护方法protected
    Print_Base();

    Print_D();
  }
  void Set_Data(int data) {
    y = data;
    Set_x(data); // 父类的公有方法才能访问父类的私有属性
  }

protected:
  void Print_D() { cout << "Print D in D's protected!" << endl; }
};

// 2.保护继承
class E : protected Base {
private:
  int z;

public:
  E() : z(0) {}
  ~E() {}
  void Show_E() {
    cout << "Show E in E's public!" << endl;
    Show_Base();
    // 子类可以访问父类的保护方法protected
    Print_Base();

    Print_E();
  }
  void Set_Data(int data) {
    z = data;
    Set_x(data); // 父类的公有方法才能访问父类的私有属性
  }

protected:
  void Print_E() { cout << "Print E in E's protected!" << endl; }
};

// 3.私有继承
class F : private Base {
private:
  int y;

public:
  F() : y(0) {}
  ~F() {}
  void Show_F() {
    cout << "Show F in F's public!" << endl;
    Show_Base();
    // 子类可以访问父类的保护方法protected
    Print_Base();

    Print_F();
  }
  void Set_Fata(int data) {
    y = data;
    Set_x(data); // 父类的公有方法才能访问父类的私有属性
  }

protected:
  void Print_F() { cout << "Print F in F's protected!" << endl; }
};

int main(int argc, char *argv[]) {
  cout << "\n//c019_继承访问属性细说" << endl;
  cout << str << endl;
  // 事实上 类D继承了类Base的 int x;
  cout << " 事实上 类D继承了类Base的 int x;" << endl;
  cout << "sizeof(D) = " << sizeof(D) << endl;

  // 1.公有继承 创建子类对象d
  D d;
  // 子类对象可以访问父类公有方法public
  d.Show_D();
  // 子类对象可以访问父类公有方法public
  d.Show_Base();
  // 对象不能访问保护方法和私有方法

  // 2.保护继承
  E e;

  return 0;
}
