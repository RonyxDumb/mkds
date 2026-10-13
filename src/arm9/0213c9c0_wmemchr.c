/* Decompiled C draft; module arm9; ROM address 0213c9c0. No matching claim. */
#include "types.h"
#include "deps/0213c9c0_wmemchr.h"

wchar_t * wmemchr(wchar_t *__s,wchar_t __c,size_t __n)

{
  if (__n != 0) {
    do {
      if ((uint)(ushort)*__s == __c) {
        return __s;
      }
      __s = (wchar_t *)((int)__s + 2);
      __n = __n - 1;
    } while (__n != 0);
  }
  return (wchar_t *)0x0;
}

