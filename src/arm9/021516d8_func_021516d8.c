/* Decompiled C draft; module arm9; ROM address 021516d8. No matching claim. */
#include "types.h"
#include "deps/021516d8_func_021516d8.h"

char func_021516d8(int param_1)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  
  iVar2 = 0;
  cVar3 = '\0';
  do {
    uVar1 = 0;
    do {
      if (((int)(uint)*(byte *)(param_1 + iVar2) >> (uVar1 & 0xff) & 1U) != 0) {
        cVar3 = cVar3 + '\x01';
      }
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 < 8);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  return cVar3;
}

