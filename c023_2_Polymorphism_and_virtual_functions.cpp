#include <iostream>
using namespace std;

class Animals {
public:
  virtual void Eat() { cout << "Animals Eat()" << endl; }
  virtual void Sleep() { cout << "Animals Sleep()" << endl; }
};

class Person : public Animals {
public:
  void Eat() { cout << "Person Eat()" << endl; }
  void Sleep() { cout << "Person Sleep()" << endl; }
};

class Dog : public Animals {
public:
  void Eat() { cout << "Dog Eat()" << endl; }
  void Sleep() { cout << "Dog Sleep()" << endl; }
};
class Pig : public Animals {
public:
  void Eat() { cout << "Pig Eat()" << endl; }
  void Sleep() { cout << "Pig Sleep()" << endl; }
};

class Bird : public Animals {
public:
  void Eat() { cout << "Bird Eat()" << endl; }
  void Sleep() { cout << "Bird Sleep()" << endl; }

public:
  void Fly() { cout << "Bird fly()" << endl; }
};

class Ostrich : public Bird {
public:
  void Eat() { cout << "Ostrich Eat()" << endl; }
  void Sleep() { cout << "Ostrich Sleep()" << endl; }

private:
  void Fly();
};

// cout<<"// 多态函数同名，参数列表相同
// 返回值相同的唯一例外\n返回值不同:父类函数返回父类指针
// 基类函数返回基类指针\n函数名相同 参数列表相同  "<<endl;
class Base {
public:
  virtual Base *Show() {
    cout << "Base" << endl;
    return this;
  }

public:
  Base() { cout << "Create Base" << endl; }
  virtual ~Base() { cout << "Free Base" << endl; }
};

class D : public Base {
public:
  D *Show() {
    cout << "D" << endl;
    return this;
  }

public:
  D() { cout << "Create D" << endl; }
  ~D() { cout << "Free D" << endl; }
};

// 多态的接口函数
void fun(Animals *pa) {
  pa->Eat();
  pa->Sleep();
}

int main(int argc, char *argv[]) {
  Person person;
  Dog dog;
  Pig pig;
  fun(&person);
  fun(&dog);
  fun(&pig);

  Ostrich ostrich;
  fun(&ostrich);

  cout << "//基类函数返回值为基类指针 子类函数返回值为子类指针 "
          "不受虚函数返回值相同的约束"
       << endl;
  cout << "// 多态函数同名，参数列表相同 "
          "返回值相同的唯一例外\n返回值不同:父类函数返回父类指针 "
          "基类函数返回基类指针\n函数名相同 参数列表相同  "
       << endl;
  D d;
  Base *bb = &d;
  bb->Show();

  // 构造函数不能是虚函数 析构函数可以是虚函数
  cout << " //在子类和父类中使用多态 并用动态分配的内存时\n "
          "构造函数不能是虚函数 析构函数必须是虚函数"
       << endl;
  Base *ptr = new D;
  delete ptr;

  return 0;
}
