```c++
#include <chrono>

std::chrono::milliseconds t(10);   //设置延迟时间, 毫秒单位
std::this_thread::sleep_for(t);    //进入休眠, 10毫秒.
```

