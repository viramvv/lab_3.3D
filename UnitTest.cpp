#include <gtest/gtest.h>
#include "RealPublic.h"
#include "RealPrivate.h"

// Тест базових операцій класу Number
TEST(NumberBaseTest, ArithmeticAndUnary) {
    Number n1(10.0);
    Number n2(3.0);

    Number diff = n1 - n2;
    EXPECT_DOUBLE_EQ(diff.GetValue(), 7.0);

    Number mult = n1 * n2;
    EXPECT_DOUBLE_EQ(mult.GetValue(), 30.0);

    ++n1;
    EXPECT_DOUBLE_EQ(n1.GetValue(), 11.0);
}

// Тест математичних функцій відкритого нащадка
TEST(RealPublicTest, MathMethods) {
    RealPublic r(16.0);
    // Корінь 4-го степеня з 16 = 2
    EXPECT_DOUBLE_EQ(r.Root(4), 2.0);

    RealPublic rZero(0.0);
    // Pi^0 = 1
    EXPECT_DOUBLE_EQ(rZero.PowerOfPi(), 1.0);
}

// Тест операцій відкритого нащадка
TEST(RealPublicTest, Operations) {
    RealPublic a(5.0);
    RealPublic b(2.0);

    RealPublic res = a * b;
    EXPECT_DOUBLE_EQ(res.GetValue(), 10.0);

    RealPublic old = a++;
    EXPECT_DOUBLE_EQ(old.GetValue(), 5.0);
    EXPECT_DOUBLE_EQ(a.GetValue(), 6.0);
}

// Тест закритого нащадка
TEST(RealPrivateTest, PrivateEncapsulation) {
    RealPrivate p(8.0);
    // Кубічний корінь з 8 = 2
    EXPECT_DOUBLE_EQ(p.Root(3), 2.0);

    ++p; // Стає 9
    EXPECT_DOUBLE_EQ(p.GetValue(), 9.0);
}