```c++
template<class ...Args>
static void Info(const char* pformat, Args ... args) {
    printf(pformat, args...);
}
```

