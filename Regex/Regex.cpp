#include <regex>

/**
 * 正则表达式主要实现如下三个需求：
 *  1.检查一个字符串是否包含了某种形式的子串
 *  2.将匹配的子串替代
 *  3.从某个字符串中取出合适的子串
 * 
 * $ 匹配输入字符串的结尾位置
 * () 标记一个子表达式的开始及结束位置。子表达式可以获取供以后使用
 * *  匹配前面的子表达式零次或者多次
 * +  匹配前面的子表达式1次或者多次
 * .  匹配除去换行符\n之外的任何单字符
 * [] [a-z] a-z中任意一个字符 
 * ?  匹配一次或者零次
 * \  转义字符 \\ => \  \\ => \  \n => n
 * ^  输入位置开始
 * {  标记限定符表达式开始
 * \| 指明两项之间的选择
 */

 #include <iostream>
 #include <string>
 #include <regex>

 int main()
 {
    std::string fnames[] = {"foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt"};
    // 在C++中 \ 中会被作为字符串内的转义符号， 为使 \. 作为正则表达式传递进去生效
    // 需要对 \ 进行二次转义，从而有\\.

    /// std::regex_match 用于匹配字符串和正则表达式，有很多不同的重载形式。最简单的一个形式就是传入std::string以及一个std::regex进行匹配，
    /// 匹配成功后返回true, 否则返回为false。
    std::regex txtRegex("[a-z]+\\.txt");
    for(const auto &filename : fnames)
    {
        std::cout << filename << ":" << std::regex_match(filename, txtRegex) << std::endl;
    }

    std::regex baseRegex("([a-z]+)\\.txt");
    for (const auto &filename : fnames)
    {
        std::smatch smatch;
        if (std::regex_match(filename, smatch, baseRegex))
        {
            if (smatch.size() == 2)
            {
                std::cout << "smatch[0]:" << smatch[0].str() << " smatch[1]:" << smatch[1].str() << std::endl;
            }
        }
    }
 }