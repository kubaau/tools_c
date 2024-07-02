#include "GtestWrapper.hpp"
#include "Numeric.h"

TEST(NumericC, factorial)
{
    EXPECT_EQ(1u, factorial(0));
    EXPECT_EQ(1u, factorial(1));
    EXPECT_EQ(2u, factorial(2));
    EXPECT_EQ(120u, factorial(5));
}

TEST(NumericC, isOdd)
{
    EXPECT_FALSE(isOdd(0));
    EXPECT_TRUE(isOdd(1));
    EXPECT_FALSE(isOdd(2));
    EXPECT_TRUE(isOdd(3));
}

TEST(NumericC, isEven)
{
    EXPECT_TRUE(isEven(0));
    EXPECT_FALSE(isEven(1));
    EXPECT_TRUE(isEven(2));
    EXPECT_FALSE(isEven(3));
}

TEST(NumericC, powerN)
{
    EXPECT_EQ(1, powerN(0, 0));
    EXPECT_EQ(0, powerN(0, 1));
    EXPECT_EQ(1, powerN(1, 0));
    EXPECT_EQ(1, powerN(1, 1));
    EXPECT_EQ(1, powerN(1, 2));
    EXPECT_EQ(1, powerN(2, 0));
    EXPECT_EQ(2, powerN(2, 1));
    EXPECT_EQ(4, powerN(2, 2));
    EXPECT_EQ(8, powerN(2, 3));
    EXPECT_EQ(27, powerN(3, 3));
}

TEST(NumericC, powerLogN)
{
    EXPECT_EQ(1, powerLogN(0, 0));
    EXPECT_EQ(0, powerLogN(0, 1));
    EXPECT_EQ(1, powerLogN(1, 0));
    EXPECT_EQ(1, powerLogN(1, 1));
    EXPECT_EQ(1, powerLogN(1, 2));
    EXPECT_EQ(1, powerLogN(2, 0));
    EXPECT_EQ(2, powerLogN(2, 1));
    EXPECT_EQ(4, powerLogN(2, 2));
    EXPECT_EQ(8, powerLogN(2, 3));
    EXPECT_EQ(27, powerLogN(3, 3));
}

TEST(NumericC, primeSieve)
{
    Byte* sieve = primeSieve(0);
    EXPECT_FALSE(isSetBit(sieve, 0));
    free(sieve);

    sieve = primeSieve(10);
    EXPECT_FALSE(isSetBit(sieve, 0));
    EXPECT_FALSE(isSetBit(sieve, 1));
    EXPECT_TRUE(isSetBit(sieve, 2));
    EXPECT_TRUE(isSetBit(sieve, 3));
    EXPECT_FALSE(isSetBit(sieve, 4));
    EXPECT_TRUE(isSetBit(sieve, 5));
    EXPECT_FALSE(isSetBit(sieve, 6));
    EXPECT_TRUE(isSetBit(sieve, 7));
    EXPECT_FALSE(isSetBit(sieve, 8));
    EXPECT_FALSE(isSetBit(sieve, 9));
    EXPECT_FALSE(isSetBit(sieve, 10));
    free(sieve);
}

TEST(NumericC, primesUpTo)
{
    int primes[4];
    EXPECT_EQ(0u, primesUpTo(primes, 0));
    EXPECT_EQ(0u, primesUpTo(primes, 1));
    EXPECT_EQ(1u, primesUpTo(primes, 2));
    EXPECT_EQ(2, primes[0]);
    EXPECT_EQ(2u, primesUpTo(primes, 3));
    EXPECT_EQ(2, primes[0]);
    EXPECT_EQ(3, primes[1]);
    EXPECT_EQ(4u, primesUpTo(primes, 10));
    EXPECT_EQ(2, primes[0]);
    EXPECT_EQ(3, primes[1]);
    EXPECT_EQ(5, primes[2]);
    EXPECT_EQ(7, primes[3]);
}

TEST(NumericC, gcd)
{
    EXPECT_EQ(0, gcd(0, 0));
    EXPECT_EQ(5, gcd(0, 5));
    EXPECT_EQ(5, gcd(5, 0));
    EXPECT_EQ(1, gcd(1, 1));
    EXPECT_EQ(1, gcd(1, 5));
    EXPECT_EQ(1, gcd(5, 1));
    EXPECT_EQ(3, gcd(3, 6));
    EXPECT_EQ(3, gcd(6, 3));
    EXPECT_EQ(5, gcd(15, 25));
    EXPECT_EQ(5, gcd(25, 15));
}

TEST(NumericC, lcm)
{
    EXPECT_EQ(0, lcm(0, 0));
    EXPECT_EQ(0, lcm(0, 5));
    EXPECT_EQ(0, lcm(5, 0));
    EXPECT_EQ(1, lcm(1, 1));
    EXPECT_EQ(5, lcm(1, 5));
    EXPECT_EQ(5, lcm(5, 1));
    EXPECT_EQ(6, lcm(3, 6));
    EXPECT_EQ(6, lcm(6, 3));
    EXPECT_EQ(75, lcm(15, 25));
    EXPECT_EQ(75, lcm(25, 15));
}

static auto operator==(const Fraction& lhs, const Fraction& rhs)
{
    return lhs.num == rhs.num and lhs.den == rhs.den;
}

TEST(NumericC, addFractions)
{
    EXPECT_EQ((Fraction{0, 0}), addFractions(Fraction{0, 0}, Fraction{0, 0}));
    EXPECT_EQ((Fraction{0, 0}), addFractions(Fraction{0, 0}, Fraction{0, 1}));
    EXPECT_EQ((Fraction{0, 0}), addFractions(Fraction{1, 1}, Fraction{1, 0}));
    EXPECT_EQ((Fraction{2, 1}), addFractions(Fraction{1, 1}, Fraction{1, 1}));
    EXPECT_EQ((Fraction{1, 1}), addFractions(Fraction{1, 2}, Fraction{1, 2}));
    EXPECT_EQ((Fraction{5, 6}), addFractions(Fraction{1, 3}, Fraction{1, 2}));
    EXPECT_EQ((Fraction{1, 2}), addFractions(Fraction{1, 4}, Fraction{1, 4}));
    EXPECT_EQ((Fraction{1, 1}), addFractions(Fraction{1, 4}, Fraction{3, 4}));
    EXPECT_EQ((Fraction{7, 4}), addFractions(Fraction{1, 4}, Fraction{3, 2}));
}

TEST(NumericC, fibAdd)
{
    int a = 1, b = 1;
    fibAdd(&a, &b);
    EXPECT_EQ(1, a);
    EXPECT_EQ(2, b);
    fibAdd(&a, &b);
    fibAdd(&a, &b);
    fibAdd(&a, &b);
    fibAdd(&a, &b);
    EXPECT_EQ(8, a);
    EXPECT_EQ(13, b);
    fibAdd(&a, &b);
    EXPECT_EQ(13, a);
    EXPECT_EQ(21, b);
}

TEST(NumericC, fibs)
{
    unsigned f[7];
    fibs(f, 0);
    fibs(f, 1);
    EXPECT_EQ(1u, f[0]);
    fibs(f, 2);
    EXPECT_EQ(1u, f[0]);
    EXPECT_EQ(1u, f[1]);
    fibs(f, 3);
    EXPECT_EQ(1u, f[0]);
    EXPECT_EQ(1u, f[1]);
    EXPECT_EQ(2u, f[2]);
    fibs(f, 7);
    EXPECT_EQ(1u, f[0]);
    EXPECT_EQ(1u, f[1]);
    EXPECT_EQ(2u, f[2]);
    EXPECT_EQ(3u, f[3]);
    EXPECT_EQ(5u, f[4]);
    EXPECT_EQ(8u, f[5]);
    EXPECT_EQ(13u, f[6]);
}

TEST(NumericC, fib)
{
    EXPECT_EQ(0u, fib(0));
    EXPECT_EQ(1u, fib(1));
    EXPECT_EQ(1u, fib(2));
    EXPECT_EQ(2u, fib(3));
    EXPECT_EQ(13u, fib(7));
}

TEST(NumericC, eq_float)
{
    float f = 0.0f;
    EXPECT_TRUE(eqf(f, 0.0f));
    EXPECT_FALSE(eqf(f, 0.0f + FLT_EPSILON));
    EXPECT_FALSE(eqf(f, 0.0f - FLT_EPSILON));
    f = 3.14f;
    EXPECT_TRUE(eqf(f, 3.14f));
    EXPECT_FALSE(eqf(f, 3.14f + FLT_EPSILON));
    EXPECT_FALSE(eqf(f, 3.14f - FLT_EPSILON));

    double d = 0.0;
    EXPECT_TRUE(eqd(d, 0.0));
    EXPECT_FALSE(eqd(d, 0.0 + DBL_EPSILON));
    EXPECT_FALSE(eqd(d, 0.0 - DBL_EPSILON));
    d = 3.14;
    EXPECT_TRUE(eqd(d, 3.14));
    EXPECT_FALSE(eqd(d, 3.14 + DBL_EPSILON));
    EXPECT_FALSE(eqd(d, 3.14 - DBL_EPSILON));
}

TEST(NumericC, mod)
{
    EXPECT_EQ(0u, mod(1, 1));
    EXPECT_EQ(1u, mod(1, 2));

    EXPECT_EQ(2u, mod(8, 3));
    EXPECT_EQ(1u, mod(-8, 3));
    EXPECT_EQ(2u, mod(8, -3));
    EXPECT_EQ(1u, mod(-8, -3));

    EXPECT_EQ(0u, mod(8, 4));
    EXPECT_EQ(0u, mod(-8, 4));
    EXPECT_EQ(0u, mod(8, -4));
    EXPECT_EQ(0u, mod(-8, -4));
}

TEST(NumericC, avg)
{
    double avg;

    int v1[] = {1, 2};
    AVG(avg, v1, 1);
    EXPECT_EQ(1, avg);

    int v2[] = {1, 2};
    AVG(avg, v2, 2);
    EXPECT_EQ(1.5, avg);

    int v3[] = {3, 1, 3, 3, 7};
    AVG(avg, v3, 5);
    EXPECT_EQ(3.4, avg);

    int v4[] = {-3, 1, -3, 3, -7};
    AVG(avg, v4, 5);
    EXPECT_EQ(-1.8, avg);

    double vd[] = {-3.1, 1.2, -3.3, 3.4, -7.5};
    AVG(avg, vd, 5);
    EXPECT_EQ(-1.86, avg);
}

TEST(NumericC, maxNoIf)
{
    EXPECT_EQ(0, maxNoIf(0, 0));
    EXPECT_EQ(-1, maxNoIf(-1, -1));
    EXPECT_EQ(5, maxNoIf(3, 5));
    EXPECT_EQ(5, maxNoIf(5, 3));
    EXPECT_EQ(3, maxNoIf(3, -5));
    EXPECT_EQ(3, maxNoIf(-5, 3));
    EXPECT_EQ(-3, maxNoIf(-5, -3));
}

static const unsigned minus_1 = unsigned(-1);
static const unsigned minus_3 = unsigned(-3);
static const unsigned minus_5 = unsigned(-5);

TEST(NumericC, maxArr)
{
    EXPECT_EQ(0u, maxArr(0u, 0u));
    EXPECT_EQ(minus_1, maxArr(minus_1, minus_1));
    EXPECT_EQ(5u, maxArr(3u, 5u));
    EXPECT_EQ(5u, maxArr(5u, 3u));
    EXPECT_EQ(minus_5, maxArr(3u, minus_5));
    EXPECT_EQ(minus_5, maxArr(minus_5, 3u));
    EXPECT_EQ(minus_3, maxArr(minus_5, minus_3));
}

TEST(NumericC, minArr)
{
    EXPECT_EQ(0u, minArr(0u, 0u));
    EXPECT_EQ(minus_1, minArr(minus_1, minus_1));
    EXPECT_EQ(3u, minArr(3u, 5u));
    EXPECT_EQ(3u, minArr(5u, 3u));
    EXPECT_EQ(3u, minArr(3u, minus_5));
    EXPECT_EQ(3u, minArr(minus_5, 3u));
    EXPECT_EQ(minus_5, minArr(minus_5, minus_3));
}
