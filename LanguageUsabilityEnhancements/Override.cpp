#pragma once

// class Base
// {
// public:
//     virtual void foo(int);
// };

// class SubClass : Base
// {
// public:
//     virtual void foo(int) override;
//     // virtual void foo(float) override; // 非法
// };


class Base 
{
public:
    virtual void foo() final;
};

class SubClass1 final : Base
{

};

// 非法
// class SubClass2 : SubClass1
// {

// };

class SubClass3 : Base 
{
public:
    // void foo(); //非法
};