/* Decompiled C draft; module arm9; ROM address 020f2150. No matching claim. */
#include "types.h"
#include "deps/020f2150_func_020f2150.h"

void func_020f2150(int param_1)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0x60U & 3;
  uVar2 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((int)uVar3 < 1) {
    *(uint *)(param_1 + 0x60) = uVar3 - iRam020f2224;
    uVar3 = param_1 + 0x60U & 3;
    uVar2 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
    if ((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < -0xa000) {
      uVar3 = param_1 + 0x74U & 3;
      uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
      if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x20000) != 0) {
        *(undefined4 *)(param_1 + 0x60) = 0xffff6000;
      }
      return;
    }
    return;
  }
  piVar1 = (int *)(param_1 + 0x60);
  *(uint *)(param_1 + 0x60) = uVar3 - iRam020f221c;
  uVar3 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x20000) == 0) {
    return;
  }
  uVar3 = param_1 + 0x60U & 3;
  uVar2 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((int)uVar3 < 0xa001) {
    *(uint *)(param_1 + 0x60) =
         (uint)((ulonglong)uRam020f2220 * (ulonglong)uVar3) >> 0xc |
         (((int)uVar3 >> 0x1f) * uRam020f2220 +
         (int)((ulonglong)uRam020f2220 * (ulonglong)uVar3 >> 0x20)) * 0x100000;
    return;
  }
  *piVar1 = (int)(*(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
                 *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20) >> 3;
  return;
}

