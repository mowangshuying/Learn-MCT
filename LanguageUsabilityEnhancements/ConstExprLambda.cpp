/// c++17 满足常量表达式要求的Lambda表达式会隐式地成为constexpr
/// 也可以显示标注为constexpr, 从而能在编译期求值
constexpr auto add = [](int a, int b)  { return a + b; };
// static_assert(add(1, 2) == 3, "");

constexpr int result = add(3, 4);