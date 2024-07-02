#pragma once

#include <stdlib.h>

#define MALLOC(T, Count) ((T*)malloc(Count * sizeof(T)))
#define CALLOC(T, Count) ((T*)calloc(Count, sizeof(T)))
#define REALLOC(T, Ptr, Count) ((T*)realloc(Ptr, Count * sizeof(T)))
