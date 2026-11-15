#include <iostream>
#include <fstream>
#include <filesystem>

int main()
{
    const std::filesystem::path base = std::filesystem::temp_directory_path() / "modern-cpp-fs-demo";
    std::filesystem::remove_all(base);

    std::filesystem::create_directories(base / "sub"); // 递归创建中间目录
    std::ofstream hellotxt(base / "hello.txt");
    hellotxt << "hello, filesytem!";
    hellotxt.flush(); // 落盘

    const std::filesystem::path p = base / "hello.txt";
    std::cout << "filename:" << p.filename() << "\n";
    std::cout << "extension:" << p.extension() << "\n";
    std::cout << "parent:" << p.parent_path() << "\n";

    std::cout << "exists:" << std::filesystem::exists(p) << std::endl;
    std::cout << "is_regular_file:" << std::filesystem::is_regular_file(p) << std::endl;
    std::cout << "file_size:" << std::filesystem::file_size(p) << std::endl;

    /// 遍历目录树
    std::cout << "entries:\n";
    for (const auto& entry : std::filesystem::recursive_directory_iterator(base))
    {
        std::cout << " " << entry.path() << "\n";
    }

    std::filesystem::copy_file(p, base / "copy.txt");
    std::filesystem::rename(base / "copy.txt", base / "renamed.txt");

    // std::filesystem::remove_all(base);
 }