/* Decompiled C draft; module arm9; ROM address 020d6d34. No matching claim. */
#include "types.h"
#include "deps/020d6d34_func_020d6d34.h"

char func_020d6d34(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  uVar3 = param_3 * 0x38 + iRam020d6d88 + param_2 * 4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  puVar4 = auStack_8;
  if (param_1 == 0) {
    puVar4 = auStack_4;
  }
  cVar2 = *(char *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + param_4);
  if (param_1 != 0) {
    if (cVar2 == '\x01') {
      cVar2 = '\x01';
      if (*(int *)(puVar4 + 8) != 0) {
        cVar2 = '\x02';
      }
      return cVar2;
    }
    return cVar2;
  }
  return cVar2;
}

