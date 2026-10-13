/* Decompiled C draft; module arm9; ROM address 02104e58. No matching claim. */
#include "types.h"
#include "deps/02104e58_func_02104e58.h"

void func_02104e58(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  *(undefined4 *)(param_1 + 0x148) = uRam02104ed4;
  uVar1 = param_1 + 0x134U & 3;
  uVar2 = *(uint *)(param_1 + 0x134U & 0xfffffffc);
  func_021053e4(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  *(uint *)(param_1 + 0x138) =
       (uint)((*(ushort *)(param_1 + 0x78) & 0xffff00ff) ==
             (int)*(char *)((*(uint *)(uRam02104ed8 & 0xfffffffc) >> (uRam02104ed8 & 3) * 8 |
                            *(uint *)(uRam02104ed8 & 0xfffffffc) << (uRam02104ed8 & 3) * -8 + 0x20)
                           + 0x62));
  uVar1 = param_1 + 0x138U & 3;
  uVar2 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    uVar1 = param_1 + 0x134U & 3;
    uVar2 = *(uint *)(param_1 + 0x134U & 0xfffffffc);
    *(undefined2 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0xb0) = 2;
  }
  *(undefined4 *)(iRam02104edc + (*(ushort *)(param_1 + 0x78) & 0xffff00ff) * 4) = 600;
  return;
}

