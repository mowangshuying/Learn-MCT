/// C++ 17之前
namespace A {
    namespace B {
        namespace C {
            int value1;
        }
    }
}

/// C++17之后
namespace A::B::C {
    int value2;
}