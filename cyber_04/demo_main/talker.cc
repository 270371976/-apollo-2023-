// 头文件引用
#include "cyber/cyber.h"
#include "cyber/time/rate.h"
#include "cyber_demo/cyber_04/demo_proto/car.pb.h"

// car数据定义的引用，可以看出其定义来源于一个proto
using apollo::cyber_demo::cyber_04::demo_proto::Car;

int main(int argc, char *argv[]) {
  // 初始化一个cyber框架
  apollo::cyber::Init(argv[0]);

  // 创建talker节点
  auto talker_node = apollo::cyber::CreateNode("talker");

  // 从节点创建一个Topic,来实现对车速的查看
  auto talker = talker_node->CreateWriter<Car>("car_speed");
  AINFO << "I'll start telling you the current speed of the car.";

  // 设置初始速度为0，然后速度每秒增加5km/h
  uint64_t speed = 0;
  while (apollo::cyber::OK()) {
    auto msg = std::make_shared<Car>();
    msg->set_speed(speed);
    // 假设车速持续增加
    speed += 5;
    talker->Write(msg);
    sleep(1);
  }
  return 0;
}