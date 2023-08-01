// 1、包含头文件
#include <memory>

#include "cyber/component/component.h"
#include "cyber_demo/cyber_07/proto/examples.pb.h"

using apollo::cyber::Component;
using apollo::cyber::ComponentBase;
using apollo::cyber_demo::cyber_07::proto::Chatter;
using apollo::cyber_demo::cyber_07::proto::Driver;

// 有两个消息源，继承以Driver和Chatter为参数的Component模版类
class CommonComponentSample : public Component<Driver, Chatter> {
 public:
  bool Init() override;
  // Proc() 函数的两个参数表示两个channel中的最新的信息
  bool Proc(const std::shared_ptr<Driver>& msg0,
            const std::shared_ptr<Chatter>& msg1) override;
};
// 将CommonComopnentSample注册在cyber中
CYBER_REGISTER_COMPONENT(CommonComponentSample)