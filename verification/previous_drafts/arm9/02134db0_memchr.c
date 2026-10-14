/* Decompiled C draft; module arm9; ROM address 02134db0. No matching claim. */
#include "types.h"
#include "deps/02134db0_memchr.h"

void * memchr(void *__s,int __c,size_t __n)

{
  if (__n != 0) {
    do {
      if (((*(uint *)((uint)__s & 0xfffffffc) >> ((uint)__s & 3) * 8 |
           *(uint *)((uint)__s & 0xfffffffc) << ((uint)__s & 3) * -8 + 0x20) & 0xff) ==
          (__c & 0xffU)) {
        return __s;
      }
      __n = __n - 1;
      __s = (void *)((int)__s + 1);
    } while (__n != 0);
  }
  return (void *)0x0;
}

