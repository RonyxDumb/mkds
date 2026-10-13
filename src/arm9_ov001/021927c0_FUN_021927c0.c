/* Decompiled C draft; module arm9_ov001; ROM address 021927c0. No matching claim. */
#include "types.h"
#include "deps/021927c0_FUN_021927c0.h"

void FUN_021927c0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (0 < *(int *)(param_1 + DAT_02192858)) {
    *(undefined4 *)(param_1 + DAT_0219285c) = 2;
    FUN_02188200(param_1,DAT_02192860);
    return;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0xa0) + DAT_02192864);
  iVar2 = (int)*(short *)(DAT_0219286c +
                         ((int)(*(uint *)(param_1 + DAT_02192868) & 0xffff) >> 4) * 4);
  uVar3 = func_0x02133048(iVar1,iVar1 >> 0x1f,iVar2,iVar2 >> 0x1f);
  *(uint *)(param_1 + 0x10) = (uint)uVar3 >> 0xc | (int)((ulonglong)uVar3 >> 0x20) << 0x14;
  *(undefined4 *)(param_1 + 0x14) = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 0xa0) + DAT_02192864);
  iVar2 = (int)*(short *)(DAT_0219286c +
                         (((int)(*(uint *)(param_1 + DAT_02192868) & 0xffff) >> 4) * 2 + 1) * 2);
  uVar3 = func_0x02133048(iVar1,iVar1 >> 0x1f,iVar2,iVar2 >> 0x1f);
  *(uint *)(param_1 + 0x18) = (uint)uVar3 >> 0xc | (int)((ulonglong)uVar3 >> 0x20) << 0x14;
  *(undefined4 *)(param_1 + DAT_0219285c) = 0xd;
  FUN_02188200(param_1,DAT_02192860);
  func_0x02073fb0(*(uint *)(param_1 + 0x78) & DAT_02192870,DAT_02192874);
  return;
}

