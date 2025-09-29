#include <chrono>
#include <iostream>

int main() {
  // 开始时间点
  auto start = std::chrono::high_resolution_clock::now();

  // 要测试的代码
  for (long long i = 0; i < 10000000000; ++i) {
    // 一些操作
  }

  // 结束时间点
  auto end = std::chrono::high_resolution_clock::now();

  // 计算耗时
  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "耗时: " << duration.count() << " 微秒" << std::endl;

  return 0;
}
