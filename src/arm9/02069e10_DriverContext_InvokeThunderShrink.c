/* Decompiled C draft; module arm9; ROM address 02069e10. No matching claim. */
#include "types.h"
#include "deps/02069e10_DriverContext_InvokeThunderShrink.h"

void DriverContext_InvokeThunderShrink(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar4 = 0;
  func_02061874();
  func_02082e4c(*(undefined2 *)(param_1 + 0x74));
  uVar3 = uRam02069ea4;
  uVar2 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x200;
  if (uVar2 != 0) {
    if (uVar2 != 0) {
      uVar2 = param_1 + 0x514U & 3;
      uVar3 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar1 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
      uVar2 = uVar1 + 0x2c;
      uVar3 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(uVar1 + 0x2c) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) ^ 0x4000;
    }
    return;
  }
  if (*(char *)((*(uint *)(uRam02069ea4 & 0xfffffffc) >> (uRam02069ea4 & 3) * 8 |
                *(uint *)(uRam02069ea4 & 0xfffffffc) << (uRam02069ea4 & 3) * -8 + 0x20) + 0x3d0) !=
      '\0') {
    do {
      if (uVar4 != *(ushort *)(param_1 + 0x74)) {
        GetDriverEntry(uVar4);
        DriverContext_ApplyThunderShrink();
      }
      uVar2 = uVar3 & 3;
      uVar1 = *(uint *)(uVar3 & 0xfffffffc);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(byte *)((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x3d0));
    return;
  }
  return;
}

