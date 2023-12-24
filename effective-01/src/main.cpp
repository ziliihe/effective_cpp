#include "effective.hpp"
#include <iostream> 
#include <vector>

static void test_const_usage() {
    FUNC_TAG();
    int a = 0;
    const int *b = &a;
    // *b = 223;
    int c = 222;
    b = &c;
    std::cout << "1. b ordinary pointer, point to a const data,"
                 " [const before * tag, b can point to another data,"
                 " but can not modify original data by b]" << ", old *b = a = 0, new *b = " << *b << std::endl;

    int d = 110;
    int * const e = &d;
    // e = &a;
    *e = 100000;
    std::cout << "2. e is a const pointer, point to a ordinary data, [* before const tag, e can not point to another data,"
                 " but can modify original data by e]" << ", old *e = d = 110, new *e = " << *e << std::endl;

    const int * const f = &d;
    // *f = 200000; // not modified
    // f = &a; // not modified

    std::cout << "3. f is a const pointer, point to a const data, [ const int * const f = &d;]"
                 " can not modify both totally." << std::endl;

    int g = 111;
    const int &h = g;
    // h = 2; // const reference, can not modified

}

static void test_macro_const() {
    FUNC_TAG();
    float a = ASPECT_RATIO + 1.1;
    float b = AspectRatio + 2.2;

    std::cout << "char* based str: " << authorName << std::endl;
    std::cout << "std::string based str: " << sauthorName << std::endl;

    int c = 55, d = 6;
    std::cout << "0: c = " << c  << std::endl;
    std::cout << "macro func-like: " << CALL_WITH_MAX(c++, d) << std::endl;
    std::cout << "1: c = " << c  << std::endl;
    std::cout << "macro func-like: " << CALL_WITH_MAX(c++, d) << std::endl;
    std::cout << "2: c = " << c  << std::endl;
}

static void test_inline() {
    FUNC_TAG();
    int a = 10, b = 20;
    std::cout << callWithMax(a++, b) << std::endl;
    std::cout << callWithMax(a++, b) << std::endl;
    std::cout << "after twice call a = " << a << std::endl;

    a += 30;
    std::cout << "new a = " << a << std::endl;
    std::cout << callWithMax(a++, b) << std::endl;
    std::cout << callWithMax(a++, b) << std::endl;
    std::cout << "after twice call a = " << a << std::endl;
}

static void test_enum_usage() {
    FUNC_TAG();

    Color c1 = Color::Red;
    // int num = Color::Red; // 强类型，不能隐式转换

    OldColor c2 = Red;
    int num = c2;
    std::cout << "strong enum class not allowd implicit convertion" << std::endl;
    std::cout << "old enum ok, num = " << num << std::endl;
}

static void test_const_iter() {
    FUNC_TAG();

    std::vector<int> v1 {1, 2, 3, 4};
    auto i1 = v1.begin();
    *i1 *= 20;
    std::cout << "ordinary i1 = " << *i1 << std::endl;

    auto i2 = v1.cbegin() + 1;
    std::cout << "const i2 = " << *i2 << std::endl;
    // *i2 += 20;
} 

static void test_item_03() {
    FUNC_TAG();
    Rational r1;
    Rational r2(22);
    Rational r3 = r1 * r2;
    Rational r4(111);
    r3.printRational();
    r4.printRational();
    // if operator* remove const works
    // (r2 * r4) = r1;
    std::cout << "Declaring operator*’s return value const prevents error like: [(a * b) = c] assignments" << std::endl;
    std::cout << "const member functions identify which member functions may be invoked on const objects." << std::endl;
    std::cout << "1. easy to know which functions may modify an object and which may not." << std::endl;
    std::cout << "2. can work with const objects." << std::endl;

    TextBlock t1("hello");
    const TextBlock t2("world");
    std::cout << "TextBlock: t1 " << t1[0] << std::endl;
    std::cout << "TextBlock: t2 " << t2[0] << std::endl;
    t1[0] = 'u';
    t1.printText();

    std::cout << "--------------------------------------------" << std::endl;
    CTextBlock t3("hello");
    t3.printText();

    const CTextBlock cctb("world");
    cctb.printText();
    char *pc = &cctb[0];
    *pc = 'h';
    cctb.printText();
}

void test_main() {
    test_macro_const();
    test_const_usage();
    test_inline();
    test_enum_usage();
    test_const_iter();
    test_item_03();
}

int main() {
    test_main();
    return 0;
}
