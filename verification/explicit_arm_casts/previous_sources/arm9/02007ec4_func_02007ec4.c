/* Decompiled C draft; module arm9; ROM address 02007ec4. No matching claim. */
#include "types.h"
#include "deps/02007ec4_func_02007ec4.h"

void func_02007ec4(int param_1,undefined2 param_2,undefined2 param_3,int param_4,int param_5)

{
  byte bVar1;
  short *psVar2;
  byte bVar3;
  
  if (*psRam02007f34 == 2) {
    psVar2 = psRam02007f34 + 1;
  }
  else {
    psVar2 = (short *)0x0;
  }
  Mem_CpuCopy8(psVar2,param_1,0x3c);
  *(undefined2 *)(param_1 + 0x3c) = 0x10;
  *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_1 + 0xc);
  *(undefined2 *)(param_1 + 0x48) = *(undefined2 *)(param_1 + 0x10);
  bVar1 = 0;
  *(undefined1 *)(param_1 + 0x4a) = 0;
  *(undefined2 *)(param_1 + 0x4c) = param_2;
  *(undefined2 *)(param_1 + 0x4e) = param_3;
  if (param_5 != 0) {
    bVar1 = 8;
  }
  if (param_4 == 0) {
    bVar3 = 0;
  }
  else {
    bVar3 = 4;
  }
  *(byte *)(param_1 + 0x4b) = bVar3 | bVar1 | 1;
  return;
}

