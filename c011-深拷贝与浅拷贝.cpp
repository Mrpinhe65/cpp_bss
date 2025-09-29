#include <iostream>
#include <string.h>
using namespace std;

class Test {
public:
  Test(int d = 0) : data(d) {}

  Test(const Test &t) { this->data = t.data; }

  Test &operator=(const Test &t) {
    if (this != &t)
      this->data = t.data;
    return *this;
  }

  Test *operator&() {
    cout << "\noperator&\n" << endl;
    return this;
  }

  const Test *operator&() const { return this; }

  ~Test() {}

private:
  int data;
};

class String {
public:
  String(const char *str = "") {
    if (str == nullptr) {
      data = (char *)malloc(sizeof(char));
      data[0] = '\0';
    } else {
      data = (char *)malloc(sizeof(char) * strlen(str) + 1);
      strcpy(data, str);
    }
  }

  String(const String &s) {
    int n = sizeof(s.data) + 1;
    data = (char *)malloc(sizeof(char) * n);
    strcpy(data, s.data);
  }

  ~String() {
    free(data);
    data = nullptr;
  }
  char *GetData() { return data; }

  String &operator=(const String &s) {
    if (this->data != nullptr) {
      free(data);
      data = nullptr;
    }
    if (this != &s) {
      data = (char *)malloc(sizeof(char) * strlen(s.data) + 1);
      strcpy(data, s.data);
    }
    return *this;
  }

private:
  char *data;
};

int main(int argc, char *argv[]) {

  Test t;
  Test t1 = t;
  Test t2;
  t2 = t1;

  Test t3;
  cout << "\n&t3 = " << &t3 << endl;

  Test *ptr;
  ptr = &t3;
  cout << "\nptr = " << ptr << endl;

  const Test t4;
  const Test *pt1 = &t4;

  const char *str = "Hello";
  String s1(str);

  cout << "private s1.data = " << s1.GetData() << endl;

  String s2(s1);

  String s3("World");
  cout << "s3.data = " << s3.GetData() << endl;
  s3 = s2;
  cout << "s3.data = " << s3.GetData() << endl;

  return 0;
}
