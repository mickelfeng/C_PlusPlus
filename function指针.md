```c++
#include  <functional>

void num(int a){};

std::function<void(int)> fun = num;
fun(10);


std::function<void (char c)>  notFun = [](char c){ };
notFun('c');
```

