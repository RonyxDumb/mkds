/* Decompiled C draft; module arm9_ov001; ROM address 02185dd0. No matching claim. */
#include "types.h"
#include "deps/02185dd0_FUN_02185dd0.h"

void FUN_02185dd0(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_r1;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined1 auStack_38 [36];
  
  func_0x020d2450();
  iVar2 = *(int *)(*(int *)(param_1 + 0x9c) + 0x10);
  func_0x02133048(iVar2,iVar2 >> 0x1f,DAT_02185ee0,0xb6);
  *(short *)(param_1 + 0x7e) = (short)(extraout_r1 + DAT_02185ee4 >> 0xc);
  iVar2 = (int)(uint)*(ushort *)(param_1 + 0x7e) >> 4;
  func_0x02146d44(auStack_38,(int)*(short *)(DAT_02185ee8 + iVar2 * 4),
                  (int)*(short *)(DAT_02185ee8 + (iVar2 * 2 + 1) * 2));
  func_0x02146dfc(auStack_38,param_1 + 0x28,param_1 + 0x28);
  uVar6 = func_0x02133048(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) >> 0x1f,DAT_02185eec,0);
  uVar4 = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
  uVar6 = func_0x02133048(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x20) >> 0x1f,DAT_02185ef0,0);
  uVar5 = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
  uVar1 = *(undefined2 *)(*(int *)(param_1 + 0x9c) + 0x28);
  *(undefined2 *)(*(int *)(param_1 + 0x9c) + 0x28) = 0x12;
  uVar3 = func_0x020d34d4(param_1,0x66);
  *(undefined4 *)(param_1 + 0xa0) = uVar3;
  uVar3 = func_0x020d34d4(param_1,0x66);
  *(undefined4 *)(param_1 + 0xa4) = uVar3;
  *(undefined2 *)(*(int *)(param_1 + 0x9c) + 0x28) = uVar1;
  func_0x02147fd8(-(*(int *)(param_1 + 0x58) + uVar4),param_1 + 0x28,param_1 + 4,
                  *(int *)(param_1 + 0xa0) + 4);
  func_0x02147fd8(*(int *)(param_1 + 0x58) + uVar4,param_1 + 0x28,param_1 + 4,
                  *(int *)(param_1 + 0xa4) + 4);
  func_0x020d2950(*(undefined4 *)(param_1 + 0xa0),uVar4);
  func_0x020d2950(*(undefined4 *)(param_1 + 0xa4),uVar4);
  func_0x020d2584(*(undefined4 *)(param_1 + 0xa0),uVar5);
  func_0x020d2584(*(undefined4 *)(param_1 + 0xa4),uVar5);
  return;
}

