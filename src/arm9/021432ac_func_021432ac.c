/* Decompiled C draft; module arm9; ROM address 021432ac. No matching claim. */
#include "types.h"
#include "deps/021432ac_func_021432ac.h"

int func_021432ac(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int aiStack_50 [16];
  
  iVar2 = Wm_GetGlobal();
  iVar3 = Wm_CheckInitialized();
  if (iVar3 != 0) {
    return 0;
  }
  if ((param_2 == 0) || (0xf < param_2)) {
    return 0;
  }
  uVar1 = iVar2 + 4U & 3;
  uVar4 = *(uint *)(iVar2 + 4U & 0xfffffffc);
  DC_InvalidateRangeNoClean((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + iRam021433ac,2);
  uVar1 = iVar2 + 4U & 3;
  uVar4 = *(uint *)(iVar2 + 4U & 0xfffffffc);
  if (((uint)*(ushort *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x17e) &
      1 << (param_2 & 0xff)) == 0) {
    return 0;
  }
  if (*(short *)(param_1 + 4) != 0) {
    iVar2 = 0;
    do {
      if (param_2 == *(ushort *)(aiStack_50[iVar2] + 4)) {
        return aiStack_50[iVar2];
      }
      iVar3 = iVar2 + 1;
      aiStack_50[iVar3] = (uint)*(ushort *)(param_1 + 6) + aiStack_50[iVar2];
      iVar2 = iVar3;
    } while (iVar3 < (int)(uint)*(ushort *)(param_1 + 4));
    return 0;
  }
  return 0;
}

