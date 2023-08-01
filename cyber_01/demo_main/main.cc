#include <cyber/cyber.h>

int main(int argc, char const *argv[]) {
  apollo::cyber::Init(argv[0]);
  AINFO << "hello Apollo";
  AWARN << "hello Apollo";
  AERROR << "hello Apollo";
  AFATAL << "hello Apollo";
  return 0;
}