#include <iostream>
#include <string>
#include <sw/redis++/redis++.h>

using namespace std;

using namespace std::chrono_literals;

// int main()
// {
//     sw::redis::Redis redis("tcp://1.94.136.155:6379");
//     std::string result = redis.ping();
//     cout << result << endl;
//     return 0;

// };

int main() {
    // 使用 chrono 字面量表示时间
    auto duration1 = 5s;   // 5 秒
    auto duration2 = 100ms; // 100 毫秒
    auto duration3 = 1min;  // 1 分钟
    auto duration4 = 2h;    // 2 小时

    std::cout << "Duration 1 (in seconds): " << duration1.count() << " seconds" << std::endl;
    std::cout << "Duration 2 (in milliseconds): " << duration2.count() << " milliseconds" << std::endl;
    std::cout << "Duration 3 (in minutes): " << duration3.count() << " minutes" << std::endl;
    std::cout << "Duration 4 (in hours): " << duration4.count() << " hours" << std::endl;

    // 休眠 2 秒
    std::cout << "Sleeping for 2 seconds..." << std::endl;
    std::this_thread::sleep_for(2s);  // 休眠 2 秒

    std::cout << "Awoke from sleep!" << std::endl;

    return 0;
}