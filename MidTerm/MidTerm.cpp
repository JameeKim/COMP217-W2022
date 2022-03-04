/**
 * COMP217 C++ for Game Development (Sec. 001)
 * Mid-Term Exam (Wed. Mar. 2, 2022)
 *
 * 301058465 Dohyun Kim
 */

#include <iomanip>

#include "Q1.h"
#include "Q2.h"

Bank::Card::Number strToNum(const char str[17])
{
    Bank::Card::Number num;
    std::copy_n(str, 16, num.begin());
    return num;
}

void testQ1()
{
    using namespace Bank;

    auto tom = new Customer("Tom", 19960208, "Somewhere");
    auto jane = new Customer("Jane", 19920825, "Someplace");

    tom->cards().assign({
        new CreditCard(strToNum("121234345656"), "RBC", 20240916, 100.f, tom),
        new RewardCard(strToNum("888833332222"), "CIBC", 20221020, 500.f, jane),
        new CreditCard(strToNum("123456789000"), "TD", 20240519, 500.f, 100.f, tom),
    });
    jane->cards().assign({
        new CreditCard(strToNum("987654321000"), "TD", 20220730, 500.f, 400.f, jane),
        new RewardCard(strToNum("999966663333"), "CIBC", 20231207, 500.f, jane),
        new RewardCard(strToNum("123412341234"), "RBC", 20251122, 500.f, tom),
    });

    std::cout << "--- Tom has:" << std::endl;
    for (const auto c : tom->cards()) std::cout << c << std::endl;
    std::cout << std::endl;

    std::cout << "--- Tom tries to pay" << std::endl;
    std::cout << std::endl;
    tom->pay(80);
    std::cout << std::endl;
    tom->pay(30);
    std::cout << std::endl;
    tom->pay(1000);
    std::cout << std::endl;

    std::cout << "--- Tom now has:" << std::endl;
    for (const auto c : tom->cards()) std::cout << c << std::endl;
    std::cout << std::endl;

    std::cout << "--- Jane has:" << std::endl;
    for (const auto c : jane->cards()) std::cout << c << std::endl;
    std::cout << std::endl;

    std::cout << "--- Jane tries to pay" << std::endl;
    std::cout << std::endl;
    jane->pay(150);
    std::cout << std::endl;
    jane->pay(50);
    std::cout << std::endl;
    jane->pay(400);
    std::cout << std::endl;
    std::cout << "--- Jane now has:" << std::endl;
    for (const auto c : jane->cards()) std::cout << c << std::endl;
    std::cout << std::endl;
}

void testQ2()
{
    using namespace Subset;

    std::cout << "--- Subsets of { 1, 2, 3 }" << std::endl;
    print(getAllSubsets({ 1, 2, 3 }));
    std::cout << std::endl;

    std::cout << "--- # of subsets of { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }"
        << std::endl << "Expected: " << (1ul << 10) << std::endl
        << "Actually got: ";
    auto list = getAllSubsets({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    std::cout << std::distance(list.begin(), list.end()) << std::endl;
}

int main(int argc, char* argv[])
{
    std::cout << std::fixed << std::setprecision(2);

    testQ1();
    testQ2();

    return 0;
}
