#include <cyber/cyber.h>

int main(int argc, char const *argv[])
{
    apollo::cyber::Init(argv[0]);
    AINFO << "相机仿真案例!";
    
    return 0;
}