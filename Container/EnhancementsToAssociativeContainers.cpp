#include <map>
#include <string>

/// C++ 17 为std::map/std::unodered_map等关联容器增加了若干更加精确，也更高效的操作。
/// try_emplace, 仅仅当键不存在时候才插入。
/// insert_or_assign, 插入新的元素，或者在键已存在时覆盖其值，并返回是否发生的插入

int main()
{
    std::map<int, std::string> m;
    m.try_emplace(1, "one");
    m.try_emplace(1, "uno");
    m.try_emplace(2, "two");
    m.try_emplace(4, "four");
    m.insert_or_assign(1, "ONE");

    std::map<int, std::string> other;
    other.insert(m.extract(1));

    std::map<int, std::string> more {{3, "three"}};
    m.merge(more);

    return 0;
}