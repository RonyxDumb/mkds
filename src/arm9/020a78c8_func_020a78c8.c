/* Decompiled C draft; module arm9; ROM address 020a78c8. No matching claim. */
#include "types.h"
#include "deps/020a78c8_func_020a78c8.h"

void func_020a78c8(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar1 = uRam020a79bc;
  if (param_1 == 0) {
    return;
  }
  iVar6 = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iVar6) {
      return;
    }
    uVar5 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar6 * 4;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    if (uVar5 == 0) break;
    uVar4 = uVar5 + 0x9c & 3;
    uVar2 = *(uint *)(uVar5 + 0x9c & 0xfffffffc);
    iVar3 = (int)*(short *)((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x28) << 0xc;
    *(int *)(uVar5 + 0x1d4) =
         (int)((longlong)iRam020a79c0 * (longlong)iVar3 >> 0x25) - (iVar3 >> 0x1f);
    *(undefined2 *)(uVar5 + 0x1d0) = 4;
    iVar3 = 0;
    uVar4 = uVar5;
    iVar7 = 0;
    if (*(short *)(uVar5 + 0x1d0) != 0) {
      do {
        *(undefined2 *)(uVar4 + 0xcc) = 0;
        *(undefined4 *)(uVar4 + 0xd8) = 0;
        *(undefined4 *)(uVar4 + 0xdc) = uVar1;
        *(undefined4 *)(uVar4 + 0xe0) = 0;
        *(undefined4 *)(uVar4 + 0xe4) = 0x2d8;
        *(undefined4 *)(uVar4 + 0xe8) = 0;
        *(undefined4 *)(uVar4 + 200) = 0x1000;
        *(undefined4 *)(uVar4 + 0xec) = 0;
        *(int *)(uVar4 + 0xf4) = iVar3;
        iVar7 = iVar7 + 1;
        iVar3 = iVar3 + 0x14;
        uVar4 = uVar4 + 0x48;
      } while (iVar7 < (int)(uint)*(ushort *)(uVar5 + 0x1d0));
    }
    iVar6 = iVar6 + 1;
  }
  return;
}

