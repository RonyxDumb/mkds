/* Decompiled C draft; module arm9; ROM address 020d7c84. No matching claim. */
#include "types.h"
#include "deps/020d7c84_func_020d7c84.h"

undefined4 func_020d7c84(int param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  *(uint *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) - uRam020d7d14;
  uVar3 = Multiply64(*(int *)(param_1 + 0x5c),*(int *)(param_1 + 0x5c) >> 0x1f,
                     *(int *)(param_1 + 0x30),*(int *)(param_1 + 0x30) >> 0x1f);
  *(uint *)(param_1 + 0x5c) = (uint)uVar3 >> 0xc | (int)((ulonglong)uVar3 >> 0x20) << 0x14;
  func_020d80e4((undefined4 *)(uintptr_t)(param_1),param_2,0,*param_3,(undefined4 *)(uintptr_t)(param_3[1]),(undefined4 *)(uintptr_t)(param_3[2]),param_3[3]);
  iVar2 = *(int *)(param_1 + 0x34);
  uVar1 = uRam020d7d14;
  if (iVar2 != 0) {
    uVar3 = Multiply64(*(int *)(param_1 + 0x5c),*(int *)(param_1 + 0x5c) >> 0x1f,iVar2,iVar2 >> 0x1f
                      );
    *(uint *)(param_1 + 0x5c) = (uint)uVar3 >> 0x18 | (int)((ulonglong)uVar3 >> 0x20) << 8;
    uVar3 = Multiply64(*(int *)(param_1 + 0x54),*(int *)(param_1 + 0x54) >> 0x1f,iVar2,iVar2 >> 0x1f
                      );
    uVar1 = (uint)uVar3 >> 0xc | (int)((ulonglong)uVar3 >> 0x20) << 0x14;
  }
  *(uint *)(param_1 + 0x58) = uVar1;
  if ((int)uRam020d7d14 <= *(int *)(param_1 + 0x5c)) {
    return 1;
  }
  return 0;
}

