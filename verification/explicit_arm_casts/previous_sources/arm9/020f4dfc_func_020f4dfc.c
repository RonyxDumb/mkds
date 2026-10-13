/* Decompiled C draft; module arm9; ROM address 020f4dfc. No matching claim. */
#include "types.h"
#include "deps/020f4dfc_func_020f4dfc.h"

void func_020f4dfc(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  *(ushort *)(uVar3 + 0x78) = *(ushort *)(uVar3 + 0x78) | *puRam020f4e70;
  func_020f9ca8(uVar3);
  func_020f9114(uVar3);
  func_020f30ec(uVar3,0,param_2);
  uVar1 = uVar3 + 0x74 & 3;
  uVar2 = *(uint *)(uVar3 + 0x74 & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x180000) == 0) {
    *(undefined4 *)(uVar3 + 0x120) = uRam020f4e74;
  }
  *(undefined4 *)(uVar3 + 0x130) = param_3;
  *param_1 = 0;
  return;
}

