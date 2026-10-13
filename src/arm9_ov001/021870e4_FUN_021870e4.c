/* Decompiled C draft; module arm9_ov001; ROM address 021870e4. No matching claim. */
#include "types.h"
#include "deps/021870e4_FUN_021870e4.h"

void FUN_021870e4(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int extraout_r1;
  
  if ((param_1 != 0) && (param_3 != 0)) {
    uVar1 = FUN_0219b478(param_1,param_3);
    puVar3 = (undefined4 *)(param_2 + DAT_021871a8);
    *puVar3 = uVar1;
    if (param_4 != 0) {
      FUN_0219b3b4(*puVar3,param_4);
    }
  }
  if (param_5 != 0) {
    uVar1 = FUN_0219b4d8();
    *(undefined4 *)(param_2 + 0xa0) = uVar1;
  }
  iVar2 = *(int *)(*(int *)(param_2 + 0x9c) + 0x10);
  func_0x02133048(iVar2,iVar2 >> 0x1f,DAT_021871ac,0xb6);
  *(uint *)(param_2 + DAT_021871b4) = (uint)((extraout_r1 + DAT_021871b0) * 0x10) >> 0x10;
  *(undefined4 *)(param_2 + DAT_021871bc) = DAT_021871b8;
  if (*(int *)(param_2 + 0xa0) != 0) {
    func_0x020d2950(param_2,*(int *)(*(int *)(param_2 + 0xa0) + 0xc) << 2);
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(*(int *)(param_2 + 0xa0) + 4);
    *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(*(int *)(param_2 + 0xa0) + 4);
    *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(*(int *)(param_2 + 0xa0) + 4);
  }
  puVar3 = (undefined4 *)(param_2 + DAT_021871c0);
  uVar1 = *(undefined4 *)(param_2 + 8);
  *puVar3 = *(undefined4 *)(param_2 + 4);
  puVar3[1] = uVar1;
  puVar3[2] = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_2 + DAT_021871c4) = 0;
  *(undefined4 *)(param_2 + DAT_021871c8) = 1;
  *(int *)(param_2 + DAT_021871cc) = (int)*(short *)(*(int *)(param_2 + 0x9c) + 0x26);
  return;
}

