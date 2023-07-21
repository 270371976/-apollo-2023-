
#include "cyber/cyber.h"
#include "cyber_demo/cyber_05/demo_proto/car.pb.h"

using apollo::cyber_demo::cyber_05::demo_proto::Car;

int main(int argc, char* argv[]) {
  // 初始化cyber框架
  apollo::cyber::Init(argv[0]);

  // 创建client node
  std::shared_ptr<apollo::cyber::Node> node(
      apollo::cyber::CreateNode("client"));

  // 从节点创建一个Service,来实现对车辆信息的查看
  auto client = node->CreateClient<Car, Car>("service_client");
  AINFO << "Hi server, I want to know car's information";

  // 创建一个请求
  auto request = std::make_shared<Car>();

  // 发送请求并获得回应数据
  auto response = client->SendRequest(request);
  if (apollo::cyber::OK) {
    if (response != nullptr) {
      AINFO << "this car owner is : " << response->owner();
      AINFO << "this car plate is : " << response->plate();
      AINFO << "this car type is : " << response->type();
      AINFO << "this car has run : " << response->kilometers() << "kilometers";
    } else {
      AINFO << "service may not ready.";
    }
  }

  apollo::cyber::WaitForShutdown();
  return 0;
}