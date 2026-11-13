#include <type_traits>
#include <iostream>
#include <vector>

/// 左值：左值是表达式后依然存在的持久对象。
/// 右值：右边的值，是表达式后就不再存在的临时对象
/// 纯右值：纯粹的字面量、求值结果相当于字面量或者匿名临时变量。
///     非引用返回的临时变量，运算表达式产生的临时变量， 原始字面量，Lambda表达式都属于纯右值


///  左值 - 有地址，可以取&，表达式结束后仍然存在。
///  右值 - 无固定地址，即将销毁


std::vector<int> foo()
{
    std::vector<int> temp = {1, 2, 3, 4};
    return temp;
}

void __ref(const std::string& str)
{
    std::cout << "left value:" << str << std::endl;
}

void __ref(const std::string&& str)
{
    std::cout << "right value:" << str << std::endl;
}

int main(int argc, char** argv)
{

    /// ----------------------------------
    // left是左值
    const char (&left)[6] = "01234" ;

    /// 无法将左值绑定到右值
    // const char (&&right)[6] = "01234";

    // 右值引用 = 左值 是不行的
    // int a = 1;
    // int &&b = a;


    /// ----------------------------------
    const char* p = "01234";

    // 这个合法的原因是因为， "01234" 是左值，初始化const char*时候会触发隐式转换产生一个const char*类型的纯右值
    // 右值引用 绑定右值
    const char* &&pr = "01234";
    

    __ref("xxx");
    std::string lv1 = "string";
    __ref(lv1);
    std::string rv1 = std::move(lv1);

    const std::string& lv2 = lv1 + lv1;

    //具名变量是左值
    std::string&& rv2 = lv1 + lv2;
    __ref(rv2);
    rv2 += "Test";
    __ref(rv2);

    // 不合法，非常量左引用无法引用右值
    // int &a = std::move(1);

    // 合法 常量引用可以引用右值
    const int &b = std::move(1); 



    return 0;
}