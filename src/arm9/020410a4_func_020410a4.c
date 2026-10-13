/* Decompiled C draft; module arm9; ROM address 020410a4. No matching claim. */
#include "types.h"
#include "deps/020410a4_func_020410a4.h"

int func_020410a4(int param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(uRam0204116c & 0xfffffffc) >> (uRam0204116c & 3) * 8 |
          *(uint *)(uRam0204116c & 0xfffffffc) << (uRam0204116c & 3) * -8 + 0x20;
  uVar3 = uVar5 + 0x44;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) &&
     (uVar5 = uVar5 + 0x24, uVar3 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
     uVar5 >> uVar3 * 8 == 0 && uVar5 << uVar3 * -8 + 0x20 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar5 = *(uint *)(uRam0204116c & 0xfffffffc) >> (uRam0204116c & 3) * 8 |
            *(uint *)(uRam0204116c & 0xfffffffc) << (uRam0204116c & 3) * -8 + 0x20;
    uVar3 = uVar5 + 0xf8;
    uVar1 = uVar3 & 3;
    uVar4 = *(uint *)(uVar3 & 0xfffffffc);
    uVar5 = uVar5 + 0x24;
    uVar3 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar3 = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) +
            (uint)*(ushort *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + param_1 * 2) *
            0x20;
  }
  if (uVar3 == 0) {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    *param_3 = 0x1000;
    param_3[1] = 0;
    param_3[2] = 0;
    uVar3 = 0xffffffff;
  }
  else {
    *param_2 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
               *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    uVar5 = uVar3 + 4 & 3;
    uVar1 = *(uint *)(uVar3 + 4 & 0xfffffffc);
    param_2[1] = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
    uVar5 = uVar3 + 8 & 3;
    uVar1 = *(uint *)(uVar3 + 8 & 0xfffffffc);
    param_2[2] = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
    uVar5 = uVar3 + 0xc & 3;
    uVar1 = *(uint *)(uVar3 + 0xc & 0xfffffffc);
    *param_3 = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
    uVar5 = uVar3 + 0x10 & 3;
    uVar1 = *(uint *)(uVar3 + 0x10 & 0xfffffffc);
    param_3[1] = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
    uVar5 = uVar3 + 0x14 & 3;
    uVar1 = *(uint *)(uVar3 + 0x14 & 0xfffffffc);
    param_3[2] = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
    uVar3 = (uint)*(ushort *)(uVar3 + 0x18);
  }
  if (uVar3 == 0xffffffff) {
    iVar2 = 0;
  }
  else {
    uVar5 = (*(uint *)(uRam0204116c & 0xfffffffc) >> (uRam0204116c & 3) * 8 |
            *(uint *)(uRam0204116c & 0xfffffffc) << (uRam0204116c & 3) * -8 + 0x20) + 0xa0;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    iVar2 = uVar3 * 0x28 + (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
  }
  return iVar2;
}

