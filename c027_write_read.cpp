#include <fstream>
#include <iostream>
using namespace std;
/*
 ifstream 仅输入
 ofstream 仅输出
 fstream  输入输出
 * */
int main(int argc, char *argv[]) {
  int ar[] = {12, 23, 43, 55, 46, 71, 86, 88, 92, 98};
  int num = sizeof(ar) / sizeof(ar[0]);

  // 文本模式 把数据写入文件
  fstream ofile("text.txt", ios::out);
  // ofile.open("text.txt", ios::out);
  if (!ofile) {
    cerr << "File Open Fail!" << endl;
    exit(1);
  }
  for (int i = 0; i < num; ++i) {
    // cout<<ar[i]<<" ";
    ofile << ar[i] << " ";
  }
  ofile.close();

  // 文本模式 从文件读入数据
  int br[num];
  fstream ifile("text.txt", ios::in);
  /*
   fstream ifile;
   ifile.open("text.txt",ios::in);
   */
  if (!ifile) {
    cerr << "File Open Fail!" << endl;
    exit(1);
  }
  for (int i = 0; i < num; ++i) {
    ifile >> br[i];
  }
  ifile.close();

  // 打印输入的数据
  for (int i = 0; i < num; ++i) {
    cout << br[i] << " ";
  }
  cout << endl;

  // 二进制模式 写入文件
  fstream binfile("text.dat", ios::out | ios::binary);
  if (!binfile) {
    cerr << "File Open Fail!" << endl;
    exit(1);
  }
  binfile.write((char *)ar, sizeof(ar));
  binfile.close();

  // 二进制模式 从文件读入数据
  int array[num];
  fstream bin_in_file("text.dat", ios::in | ios::binary);
  if (!bin_in_file) {
    cerr << "File Open Fail!" << endl;
    exit(1);
  }
  bin_in_file.read((char *)array, sizeof(array));
  bin_in_file.close();

  for (int i = 0; i < num; ++i)
    cout << array[i] << " ";
  cout << endl;

  // 文本文件的定位和随机读写

  // 二进制文件定位/随机读写
  fstream txtfile("text.dat", ios::in | ios::binary);
  if (!txtfile) {
    cout << "File Open Fail!" << endl;
    exit(1);
  }
  int pos;
  int value;
  while (1) {
    cout << "please input pos:>";
    cin >> pos;
    txtfile.seekg(pos * sizeof(value), ios::beg);
    txtfile.read(reinterpret_cast<char *>(&value), sizeof(value));
    cout << "value = " << value << endl;
    txtfile.seekg(0);
  }

  return 0;
}
