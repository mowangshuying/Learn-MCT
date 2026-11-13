struct NonMovable 
{
    NonMovable() = default;
    NonMovable(const NonMovable&) = delete;
    NonMovable(const NonMovable&&) = delete;
};

NonMovable make() 
{
    // C++17之前不合法; 必须拥有可访问或者移动的构造函数。
    return NonMovable{}; // C++17 合法： 强制复制消除，无需复制。
}


int main()
{
    NonMovable n = make();
}
