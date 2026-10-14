/* Decompiled C draft; module arm7; ROM address 037fcc94. No matching claim. */
#include "types.h"
#include "deps/037fcc94_FUN_037fcc94.h"

int FUN_037fcc94(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_2 != 0) {
    switch(*(undefined1 *)(param_1 + 2)) {
    case 0:
      uVar1 = param_1 + 0x10U & 3;
      uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
      *(int *)(param_1 + 0x10) =
           -((int)(-(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) *
                  (uint)*(byte *)(param_1 + 0x1c)) >> 8);
      uVar1 = param_1 + 0x10U & 3;
      uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
      if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
        *(undefined1 *)(param_1 + 2) = 1;
      }
      break;
    case 1:
      iVar3 = (int)*(short *)(DAT_037fcd44 + (uint)*(byte *)(param_1 + 0x1d) * 2);
      uVar1 = iVar3 * 0x80;
      uVar2 = param_1 + 0x10U & 3;
      uVar4 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
      *(uint *)(param_1 + 0x10) =
           (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) - (uint)*(ushort *)(param_1 + 0x1e);
      uVar2 = param_1 + 0x10U & 3;
      uVar4 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
      uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
      if (uVar2 == uVar1 || (int)(uVar2 + iVar3 * -0x80) < 0 != SBORROW4(uVar2,uVar1)) {
        *(uint *)(param_1 + 0x10) = uVar1;
        *(undefined1 *)(param_1 + 2) = 2;
      }
      break;
    case 2:
      break;
    case 3:
      uVar1 = param_1 + 0x10U & 3;
      uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
      *(uint *)(param_1 + 0x10) =
           (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - (uint)*(ushort *)(param_1 + 0x20);
    }
  }
  uVar1 = param_1 + 0x10U & 3;
  uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  return (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 7;
}

