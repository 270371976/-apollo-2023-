#include "cyber/cyber.h"
#include "modules/common_msgs/sensor_msgs/sensor_image.pb.h"

using apollo::drivers::Image;

int main(int argc, char *argv[])
{
    apollo::cyber::Init(argv[0]);

    // 3.创建节点；
    auto talker_node = apollo::cyber::CreateNode("camear_sim_node");
    // 4.创建发布者；
    auto talker = talker_node->CreateWriter<Image>("/image_sim");
    // 5.组织数据并发布；
    
    size_t width = 500;
    size_t height = 350;
    size_t cell = 50; // 单元格宽度
    size_t step = width * 3; // 一行像素数
    char black = 200;
    char white = 10;
    
    apollo::cyber::Rate rate(10.0);
    while (apollo::cyber::OK())
    {
        // 组织数据
        auto msg = std::make_shared<Image>();
        
        msg->set_frame_id("camera");
        auto now = apollo::cyber::Time::Now();
        msg->set_measurement_time(now.ToSecond());

        msg->set_width(width);
        msg->set_height(height);

        msg->set_encoding("rgb8");
        msg->set_step(msg->width() * 3); // 一图片行的元素个数
        
        size_t length = msg->width() * msg->height() * 3;

        char value[length]; 


        for (size_t i = 0; i < height; i++) // 遍历像素行
        {
            for (size_t j = 0; j < step; j++) // 遍历列
            {
                // 当前字节索引 value[i * step + j]
                int index = i * step + j;

                // 行赋值
                if (i / cell % 2 == 0) // 偶数行
                {
                    value[index] = black;
                } else
                {
                    value[index] = white;
                }
                // 列赋值
                // 偶数列，无需更改
                if (j / 3 / cell % 2 == 1) // 奇数列，取反
                {
                    value[index] = value[index] == white ? black : white;
                }
            }
            
        }
        
        msg->set_data(value);

        //发布
        talker->Write(msg);
        rate.Sleep();
    }

    // 6.等待关闭。
    apollo::cyber::WaitForShutdown();

    return 0;
}
