#include <iostream>
#include <memory> // std::make_unique;
#include <utility> // std::move;

/// C++11;
/// lambda表达式基本语法如下:
    /// [捕获列表](参数列表) mutable(可选) 异常属性 -> 返回类型 { 函数体 }


void lambdaValueCapture()
{
    int nValue = 1;
    
    auto copyValue = [nValue]() {
        return nValue;
    };

    nValue = 100;


    /// storedValue = 1; 而nValue = 100;
    /// 因为copyValue在创建时候就保存了一份value的拷贝。
    auto storedValue = copyValue();
}

void lambdaReferenceCapture()
{
    int nValue = 1;
    auto referenceValue = [&nValue] {
        return nValue;
    };
    auto storedValue = referenceValue();
}

/// 隐式捕获
    /// [] 空列表
    /// [name1, name2, ....] 捕获一系列变量
    /// [&] 引用捕获
    /// [=] 值捕获


/// C++14 允许捕获的成员用任意表达式进行初始化，这允许了右值捕获。
void lambdaExpressionCapture()
{
    auto important = std::make_unique<int>(1);
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int {
        return x + y + v1 + (*v2);
    };
    std::cout << add(3, 4) << std::endl;
}

/// C++14 允许使用auto作为形参
auto add = [] (auto x, auto y)  {
    return x + y;
}
