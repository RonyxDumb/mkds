/* Decompiled C draft; module arm9; ROM address 0210050c. No matching claim. */
#include "types.h"
#include "deps/0210050c_func_0210050c.h"

void func_0210050c(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if ((*(ushort *)(param_1 + 0x78) & 0x8000) == 0) {
    uVar1 = *(ushort *)(param_1 + 0x78) & 0xffff00ff;
  }
  else {
    uVar1 = 8;
  }
  iVar3 = uVar1 * 0x210 +
          (*(uint *)(uRam02100560 & 0xfffffffc) >> (uRam02100560 & 3) * 8 |
          *(uint *)(uRam02100560 & 0xfffffffc) << (uRam02100560 & 3) * -8 + 0x20);
  uVar1 = iVar3 + 0x14;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) != 0x10) {
    return;
  }
  uVar1 = param_1 + 0x158U & 3;
  uVar2 = *(uint *)(param_1 + 0x158U & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != 0xffffffc0) {
    *(undefined4 *)(iVar3 + 0x14) = 0x13;
  }
  return;
}

