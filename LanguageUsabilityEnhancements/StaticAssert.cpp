static_assert(sizeof(int) >= 2); // c++17 第二个参数可以省略
static_assert(sizeof(int) >= 2, "int 至少需要两个字节");