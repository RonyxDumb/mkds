/* Decompiled C draft; module arm9_ov001; ROM address 0218b640. No matching claim. */
#include "types.h"
#include "deps/0218b640_FUN_0218b640.h"

void FUN_0218b640(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0xa0) + DAT_0218b6d4);
  iVar2 = (int)*(short *)(DAT_0218b6dc +
                         ((int)(*(uint *)(param_1 + DAT_0218b6d8) & 0xffff) >> 4) * 4);
  uVar3 = func_0x02133048(iVar1,iVar1 >> 0x1f,iVar2,iVar2 >> 0x1f);
  *(uint *)(param_1 + 0x10) = (uint)uVar3 >> 0xc | (int)((ulonglong)uVar3 >> 0x20) << 0x14;
  *(undefined4 *)(param_1 + 0x14) = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 0xa0) + DAT_0218b6d4);
  iVar2 = (int)*(short *)(DAT_0218b6dc +
                         (((int)(*(uint *)(param_1 + DAT_0218b6d8) & 0xffff) >> 4) * 2 + 1) * 2);
  uVar3 = func_0x02133048(iVar1,iVar1 >> 0x1f,iVar2,iVar2 >> 0x1f);
  *(uint *)(param_1 + 0x18) = (uint)uVar3 >> 0xc | (int)((ulonglong)uVar3 >> 0x20) << 0x14;
  *(undefined4 *)(param_1 + DAT_0218b6e0) = 0xd;
  func_0x02073fb0(*(uint *)(param_1 + 0x78) & DAT_0218b6e4,DAT_0218b6e8);
  FUN_02188200(param_1,DAT_0218b6ec);
  if (*(int *)(param_1 + DAT_0218b6f0) == 0) {
    func_0x020d26ec(param_2,DAT_0218b6f4);
  }
  return;
}

