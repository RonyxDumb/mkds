/* Decompiled C draft; module arm9; ROM address 020aa4e8. No matching claim. */
#include "types.h"
#include "deps/020aa4e8_func_020aa4e8.h"

void func_020aa4e8(int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0;
  iVar1 = 0;
  if (0 < (int)(param_5 - param_3)) {
    uVar5 = 0;
    do {
      uVar4 = uVar4 | param_2 << (uVar5 & 0xff);
      uVar5 = uVar5 + 4;
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)(param_5 - param_3));
  }
  uVar4 = uVar4 << ((param_3 & 0x3f) << 2);
  if (param_4 < param_6) {
    puVar3 = (uint *)(param_1 + param_4 * 4);
    do {
      uVar2 = *puVar3;
      uVar5 = uVar4;
      if ((uVar2 & uRam020aa5a8) == 0) {
        uVar5 = uVar4 & uRam020aa5ac;
      }
      if ((uVar2 & uRam020aa5b0) == 0) {
        uVar5 = uVar5 & uRam020aa5b4;
      }
      if ((uVar2 & uRam020aa5b8) == 0) {
        uVar5 = uVar5 & uRam020aa5bc;
      }
      if ((uVar2 & uRam020aa5c0) == 0) {
        uVar5 = uVar5 & uRam020aa5c4;
      }
      if ((uVar2 & uRam020aa5c8) == 0) {
        uVar5 = uVar5 & uRam020aa5cc;
      }
      if ((uVar2 & uRam020aa5d0) == 0) {
        uVar5 = uVar5 & uRam020aa5d4;
      }
      if ((uVar2 & 0xf0) == 0) {
        uVar5 = uVar5 & 0xffffff0f;
      }
      if ((uVar2 & 0xf) == 0) {
        uVar5 = uVar5 & 0xfffffff0;
      }
      *puVar3 = *puVar3 + uVar5;
      puVar3 = puVar3 + 1;
      param_4 = param_4 + 1;
    } while (param_4 < param_6);
  }
  return;
}

