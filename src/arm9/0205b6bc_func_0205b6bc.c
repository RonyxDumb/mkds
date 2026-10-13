/* Decompiled C draft; module arm9; ROM address 0205b6bc. No matching claim. */
#include "types.h"
#include "deps/0205b6bc_func_0205b6bc.h"

void func_0205b6bc(undefined4 param_1,byte *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = uRam0205b774;
  uVar4 = *(uint *)(uRam0205b774 & 0xfffffffc) >> (uRam0205b774 & 3) * 8 |
          *(uint *)(uRam0205b774 & 0xfffffffc) << (uRam0205b774 & 3) * -8 + 0x20;
  if (*(short *)(uVar4 + 0xe) == 2) {
    uVar2 = 1 << (*param_2 & 3);
    if ((*(byte *)(uVar4 + 0xfa) & uVar2) == 0) {
      *(byte *)(uVar4 + 0xfa) = *(byte *)(uVar4 + 0xfa) | (byte)uVar2;
    }
    return;
  }
  if (-1 < *(short *)(uVar4 + 0x736)) {
    iVar3 = ((int)*(short *)(param_2 + 4) - (int)*(short *)(uVar4 + 0x736)) * 0x10000 >> 0x10;
    if (iVar3 < 1) {
      if (iVar3 < 0) {
        iVar3 = (iVar3 + -1) * 0x8000 >> 0x10;
      }
    }
    else {
      iVar3 = (iVar3 + 1) * 0x8000 >> 0x10;
    }
    uVar5 = *(uint *)(uRam0205b774 & 0xfffffffc) >> (uRam0205b774 & 3) * 8 |
            *(uint *)(uRam0205b774 & 0xfffffffc) << (uRam0205b774 & 3) * -8 + 0x20;
    uVar4 = uVar5 + 0xf4;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    iVar3 = iVar3 * 0x800 + ((int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) >> 1);
    *(int *)(uVar5 + 0xf4) = iVar3;
    uVar4 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    *(short *)(uVar2 + 0x736) =
         *(short *)(uVar2 + 0x736) + (short)((uint)((iVar3 + 0x800) * 0x10) >> 0x10);
    return;
  }
  return;
}

