/* Decompiled C draft; module arm9; ROM address 020f2028. No matching claim. */
#include "types.h"
#include "deps/020f2028_func_020f2028.h"

void func_020f2028(int param_1)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int local_10;
  int local_c;
  int local_8;
  
  uVar3 = param_1 + 0xfcU & 3;
  uVar1 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
  if (((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & uRam020f2140) != 0) {
    uVar3 = param_1 + 0xf0U & 3;
    uVar1 = *(uint *)(param_1 + 0xf0U & 0xfffffffc);
    local_10 = (int)(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) >> 2;
    uVar3 = param_1 + 0xf4U & 3;
    uVar1 = *(uint *)(param_1 + 0xf4U & 0xfffffffc);
    local_c = (int)(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) >> 2;
    uVar3 = param_1 + 0xf8U & 3;
    uVar1 = *(uint *)(param_1 + 0xf8U & 0xfffffffc);
    local_8 = (int)(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) >> 2;
    VecFx32_Subtract(param_1 + 0x5c,&local_10);
    return;
  }
  uVar3 = param_1 + 0x60U & 3;
  uVar1 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  uVar3 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  if ((int)uVar3 < 1) {
    *(uint *)(param_1 + 0x60) = uVar3 - iRam020f214c;
    uVar3 = param_1 + 0x60U & 3;
    uVar1 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
    if ((int)(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) < -0xa000) {
      uVar3 = param_1 + 0x74U & 3;
      uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
      if (((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0x20000) != 0) {
        *(undefined4 *)(param_1 + 0x60) = 0xffff6000;
      }
      return;
    }
    return;
  }
  piVar2 = (int *)(param_1 + 0x60);
  *(uint *)(param_1 + 0x60) = uVar3 - iRam020f2144;
  uVar3 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0x20000) == 0) {
    return;
  }
  uVar3 = param_1 + 0x60U & 3;
  uVar1 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  uVar3 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  if ((int)uVar3 < 0xa001) {
    *(uint *)(param_1 + 0x60) =
         (uint)((ulonglong)uRam020f2148 * (ulonglong)uVar3) >> 0xc |
         (((int)uVar3 >> 0x1f) * uRam020f2148 +
         (int)((ulonglong)uRam020f2148 * (ulonglong)uVar3 >> 0x20)) * 0x100000;
    return;
  }
  *piVar2 = (int)(*(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
                 *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20) >> 3;
  return;
}

