/* Decompiled C draft; module arm9; ROM address 0213a434. No matching claim. */
#include "types.h"
#include "deps/0213a434_strlen.h"

size_t strlen(char *__s)

{
  uint *puVar1;
  uint uVar2;
  size_t sVar3;
  
  sVar3 = 0xffffffff;
  do {
    puVar1 = (uint *)((uint)__s & 0xfffffffc);
    uVar2 = (uint)__s & 3;
    sVar3 = sVar3 + 1;
    __s = __s + 1;
  } while (((*puVar1 >> uVar2 * 8 | *puVar1 << uVar2 * -8 + 0x20) & 0xff) != 0);
  return sVar3;
}

