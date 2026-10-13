/* Decompiled C draft; module arm9_ov001; ROM address 021872e0. No matching claim. */
#include "types.h"
#include "deps/021872e0_FUN_021872e0.h"

void FUN_021872e0(int param_1,int param_2,int param_3,int param_4,int param_5,undefined2 param_6,
                 int param_7,int param_8,undefined4 param_9)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_58;
  short local_28;
  undefined2 local_26;
  short local_24;
  undefined1 auStack_20 [12];
  
  iVar6 = 0;
  local_58 = param_1 + 0xd0;
  iVar5 = param_1;
  do {
    if (*(int *)(iVar5 + 0xd0) == 0) {
      *(undefined4 *)(iVar5 + 0xbc) = 1;
      *(undefined4 *)(iVar5 + 0xc0) = param_9;
      *(int *)(iVar5 + 0xc4) = param_2 << 4;
      *(int *)(iVar5 + 200) = param_3 << 4;
      *(int *)(iVar5 + 0xcc) = param_4 << 4;
      FUN_02187684(param_1,iVar6,auStack_20);
      if (param_8 != 0) {
        if (*(int *)(iVar5 + 0xd0) != 0) {
          func_0x0208b6b0(local_58);
        }
        iVar1 = (int)(*(uint *)(param_1 + DAT_02187420) & 0xffff) >> 4;
        iVar4 = (int)*(short *)(DAT_02187424 + iVar1 * 4);
        uVar2 = func_0x02133048(param_7,param_7 >> 0x1f,iVar4,iVar4 >> 0x1f);
        iVar1 = (int)*(short *)(DAT_02187424 + (iVar1 * 2 + 1) * 2);
        uVar3 = func_0x02133048(param_5,param_5 >> 0x1f,iVar1,iVar1 >> 0x1f);
        local_28 = (short)(uVar2 >> 0xc) + (short)(uVar3 >> 0xc);
        local_26 = param_6;
        iVar1 = (int)(*(uint *)(param_1 + DAT_02187420) & 0xffff) >> 4;
        iVar4 = (int)*(short *)(DAT_02187424 + (iVar1 * 2 + 1) * 2);
        uVar2 = func_0x02133048(param_7,param_7 >> 0x1f,iVar4,iVar4 >> 0x1f);
        iVar1 = (int)*(short *)(DAT_02187424 + iVar1 * 4);
        uVar3 = func_0x02133048(param_5,param_5 >> 0x1f,iVar1,iVar1 >> 0x1f);
        local_24 = (short)(uVar2 >> 0xc) - (short)(uVar3 >> 0xc);
        func_0x0208b748(param_8,auStack_20,&local_28,DAT_02187428);
      }
    }
    iVar5 = iVar5 + 0x18;
    local_58 = local_58 + 0x18;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 5);
  return;
}

