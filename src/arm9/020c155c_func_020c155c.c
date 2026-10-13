/* Decompiled C draft; module arm9; ROM address 020c155c. No matching claim. */
#include "types.h"
#include "deps/020c155c_func_020c155c.h"

void func_020c155c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = DAT_020c1710;
  uVar3 = *(uint *)(DAT_020c1710 & 0xfffffffc) >> (DAT_020c1710 & 3) * 8 |
          *(uint *)(DAT_020c1710 & 0xfffffffc) << (DAT_020c1710 & 3) * -8 + 0x20;
  uVar4 = uVar3 + 0xb0;
  uVar2 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  *(uint *)(uVar3 + 0xb0) = uVar5 + 1;
  uVar2 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  uVar4 = uVar2 + 0xa8 & 3;
  uVar3 = *(uint *)(uVar2 + 0xa8 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((int)uVar4 < 1) {
    *(undefined4 *)(uVar2 + 0xac) = DAT_020c1720;
    *(undefined4 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xb0) = 0;
  }
  else if (uVar5 == DAT_020c1718 *
                    ((int)((longlong)DAT_020c1714 * (longlong)(int)uVar5 >> 0x21) -
                    ((int)uVar5 >> 0x1f))) {
    *(uint *)(uVar2 + 0xa8) = uVar4 - 1;
    uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    uVar4 = uVar3 + 0xa8;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(undefined4 *)(uVar3 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) * 4) = 1;
    uVar4 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xa8;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    switch(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) {
    case 0:
      NNSi_MaybeSndPlayerStartSeq(DAT_020c171c,0,0x2a);
      break;
    case 1:
      NNSi_MaybeSndPlayerStartSeq(DAT_020c171c,0,0x2b);
      break;
    case 2:
      NNSi_MaybeSndPlayerStartSeq(DAT_020c171c,0,0x2c);
      break;
    case 3:
      NNSi_MaybeSndPlayerStartSeq(DAT_020c171c,0,0x2d);
      break;
    case 4:
      NNSi_MaybeSndPlayerStartSeq(DAT_020c171c,0,0x2e);
      break;
    case 5:
      NNSi_MaybeSndPlayerStartSeq(DAT_020c171c,0,0x2f);
      break;
    case 6:
      NNSi_MaybeSndPlayerStartSeq(DAT_020c171c,0,0x30);
      break;
    case 7:
      NNSi_MaybeSndPlayerStartSeq(DAT_020c171c,0,0x31);
    }
  }
  uVar4 = DAT_020c1710;
  if ((*(ushort *)(DAT_020c1724 + 0x2e0) & 1) == 0) {
    return;
  }
  if ((int)uVar5 < 0x2d) {
    return;
  }
  *(undefined4 *)
   ((*(uint *)(DAT_020c1710 & 0xfffffffc) >> (DAT_020c1710 & 3) * 8 |
    *(uint *)(DAT_020c1710 & 0xfffffffc) << (DAT_020c1710 & 3) * -8 + 0x20) + 0xac) = DAT_020c1720;
  uVar2 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(undefined4 *)((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0xb0) = 0;
  return;
}

