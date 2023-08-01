#include "cyber_demo/cyber_03/demo_proto/car_msg.pb.h"
using namespace std;

int main() {
  apollo::cyber_demo::cyber_03::proto::CarMsg car;

  car.set_owner("apollo");
  car.set_license_plate("京A88888");
  car.set_max_passenger(6);
  car.add_car_info("SUV");       // 车型
  car.add_car_info("Red");       // 车身颜色
  car.add_car_info("electric");  // 电动

  cout << "owner:" << car.owner() << endl;
  cout << "license_plate:" << car.license_plate() << endl;
  cout << "max_passenger:" << car.max_passenger() << endl;

  for (int i = 0; i < car.car_info_size(); ++i) {
    cout << car.car_info(i) << " ";
  }
  cout << endl;
  return 0;
}