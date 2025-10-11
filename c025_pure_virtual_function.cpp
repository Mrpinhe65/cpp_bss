/*
 纯虚函数 pure virtual function
格式：
    virtul 返回值 函数名(参数表) = 0;
有纯虚函数的类为纯虚类/抽象类 不能实例化对象
需要具体的类继承抽象类 具体的类要编制同名虚函数
*/

#include <iostream>
using namespace std;

// 含有纯虚函数的类即为纯虚类/抽象类
class Animals {
public:
  // void Eat() { cout << "Animals Eat()" << endl; }
  virtual void Eat() = 0; // 改为纯虚函数

  // void Sleep() { cout << "Animals Sleep()" << endl; }
  virtual void Sleep() = 0; // 改为纯虚函数
};

// 需要具体的类继承抽象类 具体的类要编制所有的同名虚函数
// 否则这个类还是抽象类 还不能实例化对象
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

// 通过抽象类指针定义多态通用接口
void fun(Animals *pa) {
  pa->Eat();
  pa->Sleep();
}

int main(int argc, char *argv[]) {
  // Animals a; //错误 纯虚类/抽象类不能实例化对象
  // Animals *a; // 抽象类可以定义指针

  Person person; // 实例化对象
  Dog dog;
  // 通过传对象地址方式调用多态接口函数
  fun(&person);
  fun(&dog);

  return 0;
}
