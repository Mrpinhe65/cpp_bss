#include <iostream>
#include <string.h>
using namespace std;

class String {
private:
  char *data;

public:
  String(const char *str = "") {
    if (str == nullptr) {
      cout << "Create String Object" << endl;
      data = new char[1];
      data[0] = '\0';
    } else {
      data = new char[strlen(str) + 1];
      strcpy(data, str);
    }
  }
  ~String() {

    cout << "Free String Object" << endl;
    delete[] data;
    data = nullptr;
  }
  //****通过new 和 delete 的重载，可以人为干预new的开辟空间过程
  void *operator new(size_t sz) {
    cout << "//new的重载 in class: \nvoid* operator new(size_t sz){" << endl;
    cout << " void*p=malloc(sz); return p;}" << endl;
    void *p = malloc(sz);
    return p;
  }

  //****通过new 和 delete 的重载，可以人为干预new的开辟空间过程
  void operator delete(void *p) noexcept {
    cout << "//delete的重载 in class: \nvoid operator delete(void*p) noexcept {"
         << endl;
    cout << "  free(p);}" << endl;
    free(p);
  }

  void *operator new[](size_t sz) {
    cout << "in class new[]" << endl;
    void *p = malloc(sz);
    return p;
  }

  void operator delete[](void *p) noexcept {
    cout << "in class delete[]" << endl;
    free(p);
  }
};

//****通过new 和 delete 的重载，可以人为干预new的开辟空间过程
void *operator new(size_t sz) {
  cout << "//new的重载: \nvoid* operator new(size_t sz){" << endl;
  cout << " void*p=malloc(sz); return p;}" << endl;
  void *p = malloc(sz);
  return p;
}

//****通过new 和 delete 的重载，可以人为干预new的开辟空间过程
void operator delete(void *p) noexcept {
  cout << "//delete的重载: \nvoid operator delete(void*p) noexcept {" << endl;
  cout << "  free(p);}" << endl;
  free(p);
}

void *operator new[](size_t sz) {
  cout << "new[]" << endl;
  void *p = malloc(sz);
  return p;
}

void operator delete[](void *p) noexcept {
  cout << "delete[]" << endl;
  free(p);
}

void *operator new(size_t sz, int *d, int pos) {
  return &d[pos]; // return d+pos;
}

int main(int argc, char *argv[]) {
  /*以下是
   // new operator
   // delete operator
   即两个工作同时做，缺一不可
   开辟空间  operator new  = malloc
   构造函数 constructor
   ****通过new 和 delete 的重载，可以人为干预new的开辟空间过程
  */
  String *str = new String("Hello world!");
  delete str;

  String *str_arr = new String[10];
  delete[] str_arr;

  int ar[10];
  new (ar) int(10);
  cout << "ar[0]=" << ar[0] << endl;
  cout << "ar[1]=" << ar[1] << endl;

  // placement new
  // void *operator new(size_t sz,int*d,int pos);
  cout << "//void *operator new(size_t sz, int*d, int pos);" << endl;
  new (ar, 3) int(3); // 重载new(size_t sz,int*p,int pos);
  cout << "ar[3] = " << ar[3] << endl;
  new (ar, 8) int(8); // 重载new(size_t sz,int*p,int pos);
  cout << "ar[8] = " << ar[8] << endl;
  return 0;
}
