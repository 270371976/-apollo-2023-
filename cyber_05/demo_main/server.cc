#include "cyber/cyber.h"
#include "cyber_demo/cyber_05/demo_proto/car.pb.h"

using apollo::cyber_demo::cyber_05::demo_proto::Car;

int main(int argc, char* argv[]) {
  // 初始化cyber框架
  apollo::cyber::Init(argv[0]);
  
  // 创建server node
  std::shared_ptr<apollo::cyber::Node> node(
      apollo::cyber::CreateNode("server"));

  // 并设置topic名称，定义响应函数
  auto server = node->CreateService<Car, Car>(
      "service_client",
      [](const std::shared_ptr<Car>& request, std::shared_ptr<Car>& response) {
        AINFO << "Hi, I am your car's server.";
        response->set_type("apollo");
        response->set_plate("京A8888888");
        response->set_owner("xxx");
        response->set_kilometers(5);
      });

  apollo::cyber::WaitForShutdown();
  return 0;
}