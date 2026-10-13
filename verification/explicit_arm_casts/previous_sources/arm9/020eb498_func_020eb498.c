/* Decompiled C draft; module arm9; ROM address 020eb498. No matching claim. */
#include "types.h"
#include "deps/020eb498_func_020eb498.h"

void func_020eb498(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_r1;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 uVar10;
  undefined1 auStack_24 [16];
  
  iVar1 = func_01ffdee4(param_1 + 4,0,0,uRam020eb6e0,8,0xfffffffe,0,param_1 + 0xbc,0,0,0,0,0,0);
  if (iVar1 == 0) {
    uVar3 = puRam020eb6e4[1];
    puVar6 = puRam020eb6e4 + 2;
    *(undefined4 *)(param_1 + 0xbc) = *puRam020eb6e4;
    *(undefined4 *)(param_1 + 0xc0) = uVar3;
    *(undefined4 *)(param_1 + 0xc4) = *puVar6;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + *(int *)(param_1 + 0x58);
  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  Multiply64(*(int *)(param_2 + 0x10),*(int *)(param_2 + 0x10) >> 0x1f,uRam020eb6e8,0xb6);
  *(short *)(param_1 + 200) = (short)(extraout_r1 + iRam020eb6ec >> 0xc);
  func_020d7a3c(param_1 + 0xbc,*(undefined2 *)(param_1 + 200),auStack_24);
  func_01ffccd0(param_1 + 0x28,auStack_24);
  *(int *)(param_1 + 0xf4) = -*(int *)(param_1 + 0xbc);
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(int *)(param_1 + 0xfc) = -*(int *)(param_1 + 0xc4);
  iVar1 = *(int *)(param_1 + 0xf8);
  iVar5 = *(int *)(param_1 + 0xf4);
  iVar2 = *(int *)(param_1 + 0xfc);
  lVar7 = Multiply64(iVar2,iVar2 >> 0x1f,iVar2,iVar2 >> 0x1f);
  lVar8 = Multiply64(iVar5,iVar5 >> 0x1f,iVar5,iVar5 >> 0x1f);
  lVar9 = Multiply64(iVar1,iVar1 >> 0x1f,iVar1,iVar1 >> 0x1f);
  lVar7 = lVar7 + lVar8 + lVar9;
  if ((int)((ulonglong)lVar7 >> 0x20) < (int)(uint)((uint)lVar7 < 0x10)) {
    iVar1 = 0;
  }
  else {
    iVar1 = Vector3_MaybeNormalize(param_1 + 0xf4,param_1 + 0xf4);
  }
  if (iVar1 == 0) {
    *(int *)(param_1 + 0xf4) = -*(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0xfc) = -*(int *)(param_1 + 0x48);
  }
  func_020d6f20(param_1 + 0xf4,uRam020eb6f0,param_1 + iRam020eb6f4);
  func_020d6f20(param_1 + 0xf4,uRam020eb6f8,param_1 + 0xf4);
  uVar4 = *(uint *)(param_1 + 0xf4);
  *(uint *)(param_1 + 0xf4) =
       (uVar4 << 0xb) >> 0xc | (((int)uVar4 >> 0x1f) << 0xb | uVar4 >> 0x15) << 0x14;
  uVar4 = *(uint *)(param_1 + 0xf8);
  *(uint *)(param_1 + 0xf8) =
       (uVar4 << 0xb) >> 0xc | (((int)uVar4 >> 0x1f) << 0xb | uVar4 >> 0x15) << 0x14;
  uVar4 = *(uint *)(param_1 + 0xfc);
  *(uint *)(param_1 + 0xfc) =
       (uVar4 << 0xb) >> 0xc | (((int)uVar4 >> 0x1f) << 0xb | uVar4 >> 0x15) << 0x14;
  uVar4 = *(uint *)(param_1 + iRam020eb6f4);
  *(uint *)(param_1 + iRam020eb6f4) =
       (uVar4 << 0xb) >> 0xc | (((int)uVar4 >> 0x1f) << 0xb | uVar4 >> 0x15) << 0x14;
  uVar4 = *(uint *)(param_1 + iRam020eb6fc);
  *(uint *)(param_1 + iRam020eb6fc) =
       (uVar4 << 0xb) >> 0xc | (((int)uVar4 >> 0x1f) << 0xb | uVar4 >> 0x15) << 0x14;
  uVar4 = *(uint *)(param_1 + iRam020eb700);
  *(uint *)(param_1 + iRam020eb700) =
       (uVar4 << 0xb) >> 0xc | (((int)uVar4 >> 0x1f) << 0xb | uVar4 >> 0x15) << 0x14;
  *(short *)(param_1 + iRam020eb708) = (short)uRam020eb704;
  *(undefined2 *)(param_1 + iRam020eb70c) = *(undefined2 *)(param_2 + 0x28);
  *(undefined2 *)(param_1 + iRam020eb710) = *(undefined2 *)(param_2 + 0x2a);
  StateDualHandler_Create(param_1 + 0x80,uRam020eb714,4,param_1);
  *(undefined2 *)(param_1 + 0x90) = 0;
  *(undefined2 *)(param_1 + 0x92) = 1;
  uVar10 = Multiply64(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) >> 0x1f,uRam020eb718);
  func_020e516c(param_1 + iRam020eb71c,param_2,
                (uint)uVar10 >> 0xc | (int)((ulonglong)uVar10 >> 0x20) << 0x14,0xd);
  return;
}

