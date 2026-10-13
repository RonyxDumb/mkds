/* Decompiled C draft; module arm9; ROM address 020e1e38. No matching claim. */
#include "types.h"
#include "deps/020e1e38_func_020e1e38.h"

void func_020e1e38(uint param_1,undefined4 param_2,code *param_3)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = *(ushort *)(param_1 + 4);
  iVar4 = 0;
  if (uVar2 != 0) {
    do {
      uVar3 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
              *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar4 * 4;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
      if (((*(ushort *)(uVar3 + 2) & 0x12) == 0) && (*(short *)(uVar3 + 0x66) != 0)) {
        (*param_3)(uVar3,param_2);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(uint)uVar2);
    return;
  }
  return;
}

