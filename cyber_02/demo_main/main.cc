#include <iostream>

#include "cyber_demo/cyber_02/demo_lib/getName.h"

int main() {
  for (int i = 0; i < 5; ++i) {
    std::cout << get_name(" Apollo ") << std::endl;
  }
  return 0;
}