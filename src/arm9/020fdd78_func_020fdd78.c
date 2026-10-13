/* Decompiled C draft; module arm9; ROM address 020fdd78. No matching claim. */
#include "types.h"
#include "deps/020fdd78_func_020fdd78.h"

void func_020fdd78(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = param_1 + 0x17cU & 3;
  uVar3 = *(uint *)(param_1 + 0x17cU & 0xfffffffc);
  uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar2 = *(uint *)(uRam020fde10 & 0xfffffffc) >> (uRam020fde10 & 3) * 8 |
          *(uint *)(uRam020fde10 & 0xfffffffc) << (uRam020fde10 & 3) * -8 + 0x20;
  if (uVar3 != uVar2 * 0x40 && (int)(uVar3 + uVar2 * -0x40) < 0 == SBORROW4(uVar3,uVar2 * 0x40)) {
    return;
  }
  if (uVar3 != uVar2 * 0x10 && (int)(uVar3 + uVar2 * -0x10) < 0 == SBORROW4(uVar3,uVar2 * 0x10)) {
    uVar2 = param_1 + 0x170U & 3;
    uVar4 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
    uVar3 = *(uint *)(uRam020fde14 & 0xfffffffc) >> (uRam020fde14 & 3) * 8 |
            *(uint *)(uRam020fde14 & 0xfffffffc) << (uRam020fde14 & 3) * -8 + 0x20;
    if ((int)uVar3 < (int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20)) {
      *(uint *)(param_1 + 0x170) = uVar3;
    }
    return;
  }
  if (uVar3 != uVar2 * 4 && (int)(uVar3 + uVar2 * -4) < 0 == SBORROW4(uVar3,uVar2 * 4)) {
    uVar2 = param_1 + 0x170U & 3;
    uVar3 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
    iVar1 = (int)(*(uint *)(uRam020fde14 & 0xfffffffc) >> (uRam020fde14 & 3) * 8 |
                 *(uint *)(uRam020fde14 & 0xfffffffc) << (uRam020fde14 & 3) * -8 + 0x20) >> 1;
    if (iVar1 < (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20)) {
      *(int *)(param_1 + 0x170) = iVar1;
    }
    return;
  }
  if ((int)uVar3 <= (int)uVar2) {
    uVar2 = param_1 + 0x170U & 3;
    uVar3 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
    if (4 < (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20)) {
      *(undefined4 *)(param_1 + 0x170) = 4;
      *(undefined4 *)(param_1 + 0x174) = 3;
    }
    return;
  }
  uVar2 = param_1 + 0x170U & 3;
  uVar3 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
  iVar1 = (int)(*(uint *)(uRam020fde14 & 0xfffffffc) >> (uRam020fde14 & 3) * 8 |
               *(uint *)(uRam020fde14 & 0xfffffffc) << (uRam020fde14 & 3) * -8 + 0x20) >> 2;
  if (iVar1 < (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20)) {
    *(int *)(param_1 + 0x170) = iVar1;
  }
  return;
}

