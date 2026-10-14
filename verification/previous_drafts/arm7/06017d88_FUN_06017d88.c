/* Decompiled C draft; module arm7; ROM address 06017d88. No matching claim. */
#include "types.h"
#include "deps/06017d88_FUN_06017d88.h"

undefined4 FUN_06017d88(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = *(uint *)(DAT_06017e5c & 0xfffffffc) >> (DAT_06017e5c & 3) * 8 |
          *(uint *)(DAT_06017e5c & 0xfffffffc) << (DAT_06017e5c & 3) * -8 + 0x20;
  if (*(short *)(uVar1 + 0x34c) == 0x40) {
    iVar3 = FUN_0600a578((short *)(uintptr_t)(param_1 + 0x1e),(short *)(uintptr_t)(uVar1 + 0x3a8));
    if ((iVar3 == 0) || (iVar3 = FUN_0600a578((short *)(uintptr_t)(param_1 + 0x24),(short *)(uintptr_t)(uVar1 + 0x3c6)), iVar3 == 0)) {
      uVar2 = 1;
    }
    else {
      *(short *)(param_1 + 6) = *(short *)(param_1 + 0x10) + -0x1c;
      *(short *)(param_1 + -4) = (short)DAT_06017e60;
      *(undefined2 *)(param_1 + -2) = 0x18;
      uVar4 = DAT_06017e5c;
      *(ushort *)(param_1 + 8) =
           *(ushort *)(param_1 + 8) |
           *(ushort *)
            ((*(uint *)(DAT_06017e5c & 0xfffffffc) >> (DAT_06017e5c & 3) * 8 |
             *(uint *)(DAT_06017e5c & 0xfffffffc) << (DAT_06017e5c & 3) * -8 + 0x20) + 0x4e2) |
           (ushort)((int)(*DAT_06017e68 & 0x8000) >> 4) |
           (ushort)((int)(*DAT_06017e64 & 0x8000) >> 3);
      uVar1 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      FUN_0600f19c((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x188);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

