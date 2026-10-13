/* Decompiled C draft; module arm9; ROM address 0203c4d0. No matching claim. */
#include "types.h"
#include "deps/0203c4d0_func_0203c4d0.h"

uint func_0203c4d0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar3;
  
  uVar5 = 0;
  uVar1 = (*(uint *)(uRam0203c590 & 0xfffffffc) >> (uRam0203c590 & 3) * 8 |
          *(uint *)(uRam0203c590 & 0xfffffffc) << (uRam0203c590 & 3) * -8 + 0x20) + 0x4dc;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar1 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  if (uVar1 != 0) {
    uVar4 = *(uint *)(uRam0203c594 & 0xfffffffc) >> (uRam0203c594 & 3) * 8 |
            *(uint *)(uRam0203c594 & 0xfffffffc) << (uRam0203c594 & 3) * -8 + 0x20;
    uVar3 = uVar4 + 8 & 3;
    uVar2 = *(uint *)(uVar4 + 8 & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if (uVar3 != 0) {
      if (uVar3 == 3) {
        iVar6 = 1;
        if (*(char *)(uVar4 + 0x58) != '\0') {
          if (*(byte *)(uVar4 + 0x3d0) < 4) {
            iVar6 = 8;
          }
          else if ((*(byte *)(uVar4 + 0x3d2) < 2) || (*(byte *)(uVar4 + 0x3d3) < 2)) {
            iVar6 = 8;
          }
          else {
            iVar6 = 0xf;
          }
        }
        uVar5 = (iVar6 + 8) - (uint)*(byte *)(uVar4 + 0x3d0) & 0xffff;
      }
      else if (uVar3 == 5) {
        uVar5 = 9 - *(byte *)(uVar4 + 0x3d0) & 0xffff;
      }
    }
    uVar5 = (uint)*(byte *)(uVar1 + uVar5 * 8 + param_1 + 7);
  }
  return uVar5;
}

