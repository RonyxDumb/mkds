/* Decompiled C draft; module arm9; ROM address 020dbf7c. No matching claim. */
#include "types.h"
#include "deps/020dbf7c_func_020dbf7c.h"

void func_020dbf7c(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_r1;
  int extraout_r1_00;
  uint uVar4;
  undefined4 *puVar5;
  
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0xa8);
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  puVar1 = puRam020dc0d4;
  uVar3 = puRam020dc0d4[1];
  puVar5 = puRam020dc0d4 + 2;
  *(undefined4 *)(param_1 + 0xc4) = *puRam020dc0d4;
  *(undefined4 *)(param_1 + 200) = uVar3;
  uVar3 = puVar1[3];
  *(undefined4 *)(param_1 + 0xcc) = *puVar5;
  *(undefined4 *)(param_1 + 0xd0) = uVar3;
  iVar2 = func_02148538(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x18),
                        param_1 + 0xd4,puVar1 + 4);
  Multiply64(iVar2,iVar2 >> 0x1f,uRam020dc0d8,uRam020dc0dc);
  func_020d7b34((uint)((extraout_r1 + iRam020dc0e0) * 0x10) >> 0x10,param_1 + 0xd4);
  func_020d7938(param_1 + 0xc4,param_1 + 0xd4,param_1 + 0xb4);
  func_01ffccd0(param_1 + 0x28,param_1 + 0xb4);
  *(undefined4 *)(param_1 + 0xe4) = 0;
  if (*(int *)(param_1 + 0xfc) == 0) {
    func_020de184(*(undefined4 *)(param_1 + iRam020dc0e4));
  }
  if (*(int *)(param_1 + 0xfc) == 0) {
    *(int *)(param_1 + iRam020dc0ec) = param_1 + iRam020dc0e8;
    *(int *)(param_1 + iRam020dc0f4) = param_1 + iRam020dc0f0;
    *(int *)(param_1 + iRam020dc0fc) = param_1 + iRam020dc0f8;
    *(int *)(param_1 + iRam020dc104) = param_1 + iRam020dc100;
    if (*(int *)(*piRam020dc108 + 0xc) == 3) {
      VecFx32_AddScale1(uRam020dc10c,param_1 + iRam020dc110,param_1 + 4,param_1 + 4);
      uVar4 = *(uint *)(param_1 + iRam020dc110);
      *(uint *)(param_1 + 0x10) =
           (uVar4 << 10) >> 0xc | (((int)uVar4 >> 0x1f) << 10 | uVar4 >> 0x16) << 0x14;
      uVar4 = *(uint *)(param_1 + iRam020dc114);
      *(uint *)(param_1 + 0x14) =
           (uVar4 << 10) >> 0xc | (((int)uVar4 >> 0x1f) << 10 | uVar4 >> 0x16) << 0x14;
      uVar4 = *(uint *)(param_1 + iRam020dc118);
      *(uint *)(param_1 + 0x18) =
           (uVar4 << 10) >> 0xc | (((int)uVar4 >> 0x1f) << 10 | uVar4 >> 0x16) << 0x14;
      iVar2 = func_02148538(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x18));
      Multiply64(iVar2,iVar2 >> 0x1f,uRam020dc0d8,uRam020dc0dc);
      func_020d7b34((uint)((extraout_r1_00 + iRam020dc0e0) * 0x10) >> 0x10,param_1 + 0xd4);
      *(undefined2 *)(param_1 + 0x90) = 4;
      *(undefined2 *)(param_1 + 0x92) = 1;
      return;
    }
    *(undefined2 *)(param_1 + 0x90) = 0;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return;
}

