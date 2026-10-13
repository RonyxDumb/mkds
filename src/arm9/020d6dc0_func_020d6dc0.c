/* Decompiled C draft; module arm9; ROM address 020d6dc0. No matching claim. */
#include "types.h"
#include "deps/020d6dc0_func_020d6dc0.h"

char func_020d6dc0(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  
  uVar3 = iRam020d6dec + param_3 * 0x10 + param_2 * 4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  cVar2 = *(char *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + param_4);
  if (cVar2 == '\x01') {
    if (param_1 == 0) {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x02';
    }
  }
  return cVar2;
}

