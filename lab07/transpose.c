#include "transpose.h"

/* The naive transpose function as a reference. */
void transpose_naive(int n, int blocksize, int *dst, int *src) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            dst[y + x * n] = src[x + y * n];
        }
    }
}

void transpose_helper(int n, int blocksize, int i, int j, int *dst, int *src) {
    for (int x = i; x < blocksize + i; x++) {
        for (int y = j; y < blocksize + j; y++) {
          if (n > x && n > y) {
            dst[y + x * n] = src[x + y * n];
        }
    }
  }
}

/* Implement cache blocking below. You should NOT assume that n is a
 * multiple of the block size. */
void transpose_blocking(int n, int blocksize, int *dst, int *src) {
    for (int x = 0; x < n; x += blocksize) {
      for (int y = 0; y < n; y += blocksize) {
        transpose_helper(n, blocksize, x, y, dst, src);
      }
    }
}
