/* Decompiled C draft; module arm9; ROM address 0200973c. No matching claim. */
#include "types.h"
#include "deps/0200973c_func_0200973c.h"

void func_0200973c(int param_1,undefined4 param_2,uint param_3,undefined2 param_4)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = '\x01';
  CopyMemory16(param_2,param_1 + iRam02009794,uRam02009798);
  uVar1 = 0;
  do {
    if ((param_3 & 2 << (uVar1 & 0xff)) != 0) {
      cVar2 = cVar2 + '\x01';
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 0xf);
  *(char *)(param_1 + iRam0200979c) = cVar2;
  *(ushort *)(param_1 + iRam020097a0) = (ushort)param_3 | 1;
  *(undefined2 *)(param_1 + iRam020097a4) = param_4;
  *(char *)(param_1 + iRam020097a8) = *(char *)(param_1 + iRam020097a8) + '\x01';
  return;
}

