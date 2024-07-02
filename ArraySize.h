#pragma once

#define ARRAY_SIZE_IN_BYTES(A) sizeof(A)
#define ARRAY_SIZE(A) (ARRAY_SIZE_IN_BYTES(A) / sizeof(A[0]))
