/* Decompiled C draft; module arm9; ROM address 02062ef8. No matching claim. */
#include "types.h"
#include "deps/02062ef8_func_02062ef8.h"

void func_02062ef8(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar6;
  uint uVar7;
  uint uVar5;
  
  uVar5 = uRam02063028 + 4 & 3;
  uVar4 = *(uint *)(uRam02063028 + 4 & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if (uVar5 != 0) {
    uVar4 = uRam02063028 + 0xec & 3;
    uVar3 = *(uint *)(uRam02063028 + 0xec & 0xfffffffc);
    if ((uVar3 >> uVar4 * 8 == 0 && uVar3 << uVar4 * -8 + 0x20 == 0) || (param_1 != 0)) {
      uVar4 = uVar5 + 4 & 3;
      uVar5 = *(uint *)(uVar5 + 4 & 0xfffffffc);
      Maybe_helper_013044(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20,param_1);
    }
    else {
      uVar4 = uVar5 + 4 & 3;
      uVar5 = *(uint *)(uVar5 + 4 & 0xfffffffc);
      uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
      uVar4 = 0;
      if (*(char *)(uVar5 + 0x18) != '\0') {
        do {
          func_02013424(uVar5,uVar4);
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(byte *)(uVar5 + 0x18));
      }
    }
  }
  uVar4 = uRam02063028;
  uVar5 = uRam02063028 + 0xe0 & 3;
  uVar3 = *(uint *)(uRam02063028 + 0xe0 & 0xfffffffc);
  if (uVar3 >> uVar5 * 8 == 0 && uVar3 << uVar5 * -8 + 0x20 == 0) {
    return;
  }
  if (param_1 != 0) {
    uVar5 = (*(uint *)(uRam02063028 & 0xfffffffc) >> (uRam02063028 & 3) * 8 |
            *(uint *)(uRam02063028 & 0xfffffffc) << (uRam02063028 & 3) * -8 + 0x20) + 4;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    Maybe_helper_013044(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20,1);
    return;
  }
  uVar7 = 0;
  uVar5 = (*(uint *)(uRam02063028 & 0xfffffffc) >> (uRam02063028 & 3) * 8 |
          *(uint *)(uRam02063028 & 0xfffffffc) << (uRam02063028 & 3) * -8 + 0x20) + 4;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  if (*(char *)(uVar5 + 0x18) != '\0') {
    do {
      uVar3 = uVar4 + 0xe4;
      uVar1 = uVar3 & 3;
      uVar6 = *(uint *)(uVar3 & 0xfffffffc);
      uVar3 = uVar4 + 0xe8;
      uVar2 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if (((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & (1 << (uVar7 & 0xff)) >> 0x1f) == 0
          && ((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 1 << (uVar7 & 0xff)) == 0) {
        func_02013424(uVar5,uVar7,0);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(byte *)(uVar5 + 0x18));
    return;
  }
  return;
}

