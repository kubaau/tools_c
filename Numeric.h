#pragma once

#include <float.h>
#include <iso646.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "Allocs.h"
#include "BitCount.h"
#include "Repeat.h"
#include "Swap.h"

static inline unsigned factorial(unsigned n)
{
    unsigned result = 1;
    while (n)
        result *= n--;
    return result;
}

static inline bool isOdd(int n)
{
    return n & 1;
}

static inline bool isEven(int n)
{
    return not isOdd(n);
}

static inline u64 powerN(int n, unsigned power)
{
    u64 result = 1;
    for (unsigned i = 0; i < power; ++i)
        result *= n;
    return result;
}

static inline u64 powerLogN(int n, unsigned power)
{
    u64 result = 1;
    while (power)
    {
        if (isOdd(power))
        {
            result *= n;
            --power;
        }
        n *= n;
        power /= 2;
    }
    return result;
}

#define DEFINE_MASKS const Byte masks[] = {1, 2, 4, 8, 16, 32, 64, 128};

static inline void unsetBit(Byte* bitset, unsigned index)
{
    DEFINE_MASKS;
    const div_t d = div((int)index, BITS_IN(Byte));
    bitset[d.quot] &= ~masks[d.rem];
}

static inline bool isSetBit(const Byte* bitset, unsigned index)
{
    DEFINE_MASKS;
    const div_t d = div((int)index, BITS_IN(Byte));
    return bitset[d.quot] & masks[d.rem];
}

static inline Byte* primeSieve(int max)
{
    const size_t size_in_bytes = (size_t)(ceil((float)(max + 1) / BITS_IN(Byte)));
    Byte* sieve = MALLOC(Byte, size_in_bytes);
    memset(sieve, -1, size_in_bytes);
    unsetBit(sieve, 0);
    if (max > 1)
        unsetBit(sieve, 1);

    const int limit = (int)sqrt(max);
    for (int i = 2; i <= limit; ++i)
        if (isSetBit(sieve, i))
            for (int j = i * i; j <= max; j += i)
                unsetBit(sieve, j);

    return sieve;
}

static inline Count primesUpTo(int* dest, int max)
{
    Count ret = 0;
    Byte* sieve = primeSieve(max);
    for (int i = 2; i <= max; ++i)
        if (isSetBit(sieve, i))
            *(dest + ret++) = i;
    free(sieve);
    return ret;
}

static inline int gcd(int a, int b)
{
    while (true)
    {
        if (a == 0)
            return b;
        b %= a;
        if (b == 0)
            return a;
        a %= b;
    }
}

static inline int lcm(int a, int b)
{
    const int gcd_val = gcd(a, b);
    return gcd_val ? (a / gcd_val * b) : 0;
}

typedef struct
{
    int num;
    int den;
} Fraction;

static inline Fraction addFractions(Fraction f1, Fraction f2)
{
    Fraction ret = {0, 0};

    if (f1.den == 0 or f2.den == 0)
        return ret;

    const int denominator = lcm(f1.den, f2.den);
    const int numerator = f1.num * denominator / f1.den + f2.num * denominator / f2.den;
    const int gcd_val = gcd(numerator, denominator);
    ret.num = numerator / gcd_val;
    ret.den = denominator / gcd_val;
    return ret;
}

static inline void fibAdd(int* lhs, int* rhs)
{
    *lhs += *rhs;
    SWAP(int, *lhs, *rhs);
}

static inline void fibs(unsigned* dest, Count count)
{
    if (count > 0)
        *dest = 1;
    if (count > 1)
        *++dest = 1;
    for (Count i = 2; i < count; ++i)
    {
        ++dest;
        *dest = *(dest - 1) + *(dest - 2);
    }
}

static inline unsigned fib(unsigned n)
{
    const double sqrt5 = sqrt(5);
    const double a = (1 + sqrt5) / 2.0;
    const double b = (1 - sqrt5) / 2.0;
    return (unsigned)((pow(a, n) - pow(b, n)) / sqrt5);
}

static inline bool eqFloat(double lhs, double rhs, double epsilon)
{
    return fabs(lhs - rhs) < epsilon;
}

static inline bool eqd(double lhs, double rhs)
{
    return eqFloat(lhs, rhs, DBL_EPSILON);
}

static inline bool eqf(float lhs, float rhs)
{
    return eqFloat(lhs, rhs, FLT_EPSILON);
}

static inline unsigned mod(int val, int m)
{
    const int cpp_mod = val % m;
    return cpp_mod >= 0 ? cpp_mod : cpp_mod + abs(m);
}

#define SUM(Dest, Begin, Count) \
    Dest = 0;                   \
    repeat(Count) Dest += *(Begin + i);

#define AVG(Dest, Begin, Count) \
    {                           \
        double sum;             \
        SUM(sum, Begin, Count); \
        Dest = sum / Count;     \
    }

static inline int maxNoIf(int lhs, int rhs)
{
    return (lhs + rhs + ((lhs - rhs) >> (sizeof(int) * 8 - 1) | 1) * (lhs - rhs)) / 2;
}

static inline unsigned maxArr(unsigned lhs, unsigned rhs)
{
    unsigned arr[] = {lhs, rhs};
    return rhs ? arr[1 - !!(lhs / rhs)] : lhs;
}

static inline unsigned minArr(unsigned lhs, unsigned rhs)
{
    unsigned arr[] = {lhs, rhs};
    return lhs ? arr[1 - !!(rhs / lhs)] : lhs;
}
