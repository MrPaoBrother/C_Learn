#include "test.h"

int main(){

    // TODO 读配置文件

    // 营业时间
    int serverTime = 240;

    // 同时提供服务的窗口数量
    int serviceNum = 4;

    // 模拟排队的次数
    int simulateNum = 100000;

    Test::run(serverTime, serviceNum, simulateNum);

    return 0;
}