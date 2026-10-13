/* Decompiled C draft; module arm9; ROM address 02022b44. No matching claim. */
#include "types.h"
#include "deps/02022b44_NFTR_SomeFn_0.h"

int NFTR_SomeFn_0(uint param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  code *pcVar5;
  
  local_24 = 0;
  local_20 = 0;
  uVar1 = param_1 + 4 & 3;
  uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
  pcVar5 = (code *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  iVar3 = 1;
  local_28 = param_3;
  iVar2 = (*pcVar5)(&local_28);
  while (iVar2 != 0) {
    if (iVar2 == 10) {
      iVar3 = iVar3 + 1;
    }
    iVar2 = (*pcVar5)(&local_28);
  }
  return iVar3 * (param_2 +
                 *(char *)((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 1)) -
         param_2;
}

