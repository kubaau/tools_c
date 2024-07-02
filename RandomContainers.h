#pragma once

#include "Allocs.h"
#include "Iota.h"
#include "MinMax.h"
#include "Random.h"

static inline void fillWithRandomInts(int* dest, Count count, int min, int max)
{
    repeat_count(count) dest[i] = randomInt(min, max);
}

static inline void fillWithRandomFloats(float* dest, Count count, float min, float max)
{
    repeat_count(count) dest[i] = randomFloat(min, max);
}

static inline unsigned* shuffledIndexes(Count count)
{
    unsigned* indexes = MALLOC(unsigned, count);
    iota(indexes, count);
    shuffle(indexes, count);
    return indexes;
}

static inline void sample_unstable(int* dest, const int* src, Count dest_count, Count src_count)
{
    unsigned* indexes = shuffledIndexes(src_count);
    const Count limit = MIN(dest_count, src_count);
    repeat_count(limit)* dest++ = *(src + indexes[i]);
    free(indexes);
}

static inline void fillWithRandomUniqueInts(int* dest, Count count, int min, int max)
{
    repeat_count(count) dest[i] = randomInt(min, max);

    const int width = max - min + 1;
    int* ints = MALLOC(int, width);
    iota(ints, count);
    repeat_count(count) ints[i] += min;
    sample_unstable(dest, ints, width, count);
    free(ints);
}

static inline unsigned randomIndex(Count count)
{
    return randomInt(0, (int)count - 1);
}

static inline const void* randomElement(const void* a, size_t elem_size, Count count)
{
    return (const Byte*)a + elem_size * randomIndex(count);
}
