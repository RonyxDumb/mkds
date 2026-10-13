/* Decompiled C draft; module arm9; ROM address 020c525c. No matching claim. */
#include "types.h"
#include "deps/020c525c_func_020c525c.h"

void func_020c525c(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar5;
  uint uVar4;
  
  if (*(uint *)(uRam020c539c & 0xfffffffc) >> (uRam020c539c & 3) * 8 == 0 &&
      *(uint *)(uRam020c539c & 0xfffffffc) << (uRam020c539c & 3) * -8 + 0x20 == 0) {
    return;
  }
  uVar1 = (*(uint *)(uRam020c53a0 & 0xfffffffc) >> (uRam020c53a0 & 3) * 8 |
          *(uint *)(uRam020c53a0 & 0xfffffffc) << (uRam020c53a0 & 3) * -8 + 0x20) + 0x20;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if (uVar1 >> uVar3 * 8 == 0 && uVar1 << uVar3 * -8 + 0x20 == 0) {
    return;
  }
  uVar1 = (*(uint *)(uRam020c53a4 & 0xfffffffc) >> (uRam020c53a4 & 3) * 8 |
          *(uint *)(uRam020c53a4 & 0xfffffffc) << (uRam020c53a4 & 3) * -8 + 0x20) + 8;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) != 5) {
    uVar1 = (*(uint *)(uRam020c53ac & 0xfffffffc) >> (uRam020c53ac & 3) * 8 |
            *(uint *)(uRam020c53ac & 0xfffffffc) << (uRam020c53ac & 3) * -8 + 0x20) + 4;
    uVar3 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    if (uVar1 >> uVar3 * 8 == 0 && uVar1 << uVar3 * -8 + 0x20 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = func_021431d8();
    }
    *(undefined4 *)
     (*(uint *)(uRam020c539c & 0xfffffffc) >> (uRam020c539c & 3) * 8 |
     *(uint *)(uRam020c539c & 0xfffffffc) << (uRam020c539c & 3) * -8 + 0x20) = uVar2;
    return;
  }
  uVar2 = func_021205e8();
  uVar3 = uRam020c539c;
  *(undefined4 *)
   ((*(uint *)(uRam020c539c & 0xfffffffc) >> (uRam020c539c & 3) * 8 |
    *(uint *)(uRam020c539c & 0xfffffffc) << (uRam020c539c & 3) * -8 + 0x20) + 4) = uVar2;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = uVar4 + 0x10;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  *(uint *)(uVar4 + 0xc) = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  uVar2 = func_0212a8d0();
  uVar3 = uRam020c539c;
  *(undefined4 *)
   ((*(uint *)(uRam020c539c & 0xfffffffc) >> (uRam020c539c & 3) * 8 |
    *(uint *)(uRam020c539c & 0xfffffffc) << (uRam020c539c & 3) * -8 + 0x20) + 0x10) = uVar2;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = uVar3 + 0x10;
  uVar4 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar4 * 8 != 0 || uVar1 << uVar4 * -8 + 0x20 != 0) &&
     (uVar3 = uVar3 + 0xc, uVar1 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
     uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0)) {
    NNSi_MaybeSndPlayerStartSeq(uRam020c53a8,0,0x26);
  }
  uVar3 = uRam020c539c;
  uVar5 = *(uint *)(uRam020c539c & 0xfffffffc) >> (uRam020c539c & 3) * 8 |
          *(uint *)(uRam020c539c & 0xfffffffc) << (uRam020c539c & 3) * -8 + 0x20;
  uVar1 = uVar5 + 0x10 & 3;
  uVar4 = *(uint *)(uVar5 + 0x10 & 0xfffffffc);
  if (uVar4 >> uVar1 * 8 == 0 && uVar4 << uVar1 * -8 + 0x20 == 0) {
    *(undefined4 *)(uVar5 + 8) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0xc) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10) = 0;
    return;
  }
  uVar1 = uVar5 + 8 & 3;
  uVar4 = *(uint *)(uVar5 + 8 & 0xfffffffc);
  *(uint *)(uVar5 + 8) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 1;
  uVar4 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  uVar1 = uVar4 + 8;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if (0x77 < (int)(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20)) {
    *(undefined4 *)(uVar4 + 8) = 0;
  }
  return;
}

