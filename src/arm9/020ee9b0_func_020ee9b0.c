/* Decompiled C draft; module arm9; ROM address 020ee9b0. No matching claim. */
#include "types.h"
#include "deps/020ee9b0_func_020ee9b0.h"

void func_020ee9b0(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  *(undefined2 *)(param_1 + 0x174) = 0;
  *(undefined2 *)(param_1 + 0x176) = 600;
  *(undefined4 *)(param_1 + 0x178) = 0;
  *(undefined4 *)(param_1 + 0x17c) = 0;
  do {
    *(short *)(param_1 + uVar2 * 2 + 0x18c) = (short)uVar2;
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 3);
  uVar2 = param_1 + 0x8cU & 3;
  uVar3 = *(uint *)(param_1 + 0x8cU & 0xfffffffc);
  uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  lVar1 = (ulonglong)uRam020eea64 * (ulonglong)uVar2;
  VecFx32_AddScale1((uint)lVar1 >> 0xc |
                    (((int)uVar2 >> 0x1f) * uRam020eea64 + (int)((ulonglong)lVar1 >> 0x20)) *
                    0x100000,param_1 + 0x38,param_1 + 0x50,(int *)(uintptr_t)(param_1 + 0x180));
  func_020eea6c(param_1);
  if ((uint)*(ushort *)(param_1 + 0x28) ==
      (int)*(char *)((*(uint *)(uRam020eea68 & 0xfffffffc) >> (uRam020eea68 & 3) * 8 |
                     *(uint *)(uRam020eea68 & 0xfffffffc) << (uRam020eea68 & 3) * -8 + 0x20) + 0x62)
     ) {
    uVar2 = param_1 + 0xcU & 3;
    uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    uVar2 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0x1fc;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    func_020719bc(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,0xe7);
    return;
  }
  return;
}

