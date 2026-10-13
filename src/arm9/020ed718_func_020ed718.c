/* Decompiled C draft; module arm9; ROM address 020ed718. No matching claim. */
#include "types.h"
#include "deps/020ed718_func_020ed718.h"

void func_020ed718(uint param_1,undefined4 param_2,code *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar1 = iRam020ed798;
  uVar6 = param_1 + 0x10 & 3;
  uVar5 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  iVar4 = 0;
  if ((int)uVar6 < 1) {
    return;
  }
  do {
    uVar5 = param_1 + 4 & 3;
    uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
    uVar5 = (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + iVar4 * 4;
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar3 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
    uVar5 = uVar3 + 0x74 & 3;
    uVar2 = *(uint *)(uVar3 + 0x74 & 0xfffffffc);
    uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    if ((uVar5 & 0x10000) == 0) {
      if ((uVar5 & 0x1000) == 0) {
        LightInfo_MaybeApply((ushort *)(uintptr_t)(uVar3 + 0x7c));
      }
      else {
        uVar5 = uVar3 + 0x90 & 3;
        uVar2 = *(uint *)(uVar3 + 0x90 & 0xfffffffc);
        LightInfo_MaybeApply((ushort *)(uintptr_t)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20));
      }
      uVar5 = iVar1 + (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) * 4;
      uVar2 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      (*param_3)(uVar3,param_2,uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < (int)uVar6);
  return;
}

