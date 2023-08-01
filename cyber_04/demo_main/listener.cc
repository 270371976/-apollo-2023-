// 头文件引用
#include "cyber/cyber.h"
#include "cyber_demo/cyber_04/demo_proto/car.pb.h"

using apollo::cyber_demo::cyber_04::demo_proto::Car;

// 接收到消息后的响应函数
void message_callback(const std::shared_ptr<Car>& msg) {
  AINFO << "now speed is: " << msg->speed();
}

int main(int argc, char* argv[]) {
  // 初始化cyber框架
  apollo::cyber::Init(argv[0]);

  // 创建监听节点
  auto listener_node = apollo::cyber::CreateNode("listener");

  // 创建监听响应进行消息读取
  auto listener =
      listener_node->CreateReader<Car>("car_speed", message_callback);
  apollo::cyber::WaitForShutdown();
  return 0;
}