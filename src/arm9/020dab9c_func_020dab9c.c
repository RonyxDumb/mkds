/* Decompiled C draft; module arm9; ROM address 020dab9c. No matching claim. */
#include "types.h"
#include "deps/020dab9c_func_020dab9c.h"

void func_020dab9c(int param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 + 0xc4U & 3;
  uVar3 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  lVar1 = (ulonglong)uRam020dabf4 * (ulonglong)uVar4;
  *(uint *)(param_1 + 0xc4) =
       (uint)lVar1 >> 0xc |
       (((int)uVar4 >> 0x1f) * uRam020dabf4 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar4 = param_1 + 0xc4U & 3;
  uVar3 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  iVar2 = iRam020dabf8;
  if ((int)uVar4 < iRam020dabf8) {
    iVar2 = 4;
  }
  if ((int)uVar4 < iRam020dabf8) {
    *(short *)(param_1 + 0x90) = (short)iVar2;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return;
}

