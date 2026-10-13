/* Decompiled C draft; module arm9; ROM address 020c1728. No matching claim. */
#include "types.h"
#include "deps/020c1728_func_020c1728.h"

void func_020c1728(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = DAT_020c1940;
  uVar2 = *(uint *)(DAT_020c1940 & 0xfffffffc) >> (DAT_020c1940 & 3) * 8 |
          *(uint *)(DAT_020c1940 & 0xfffffffc) << (DAT_020c1940 & 3) * -8 + 0x20;
  uVar4 = uVar2 + 0xb0;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  *(uint *)(uVar2 + 0xb0) = uVar4 + 1;
  if ((int)uVar4 < 0x2d) {
    uVar5 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar5 = (uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) + 0xa8;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
    if (((int)uVar5 <
         (int)(uint)*(byte *)((*(uint *)(DAT_020c1944 & 0xfffffffc) >> (DAT_020c1944 & 3) * 8 |
                              *(uint *)(DAT_020c1944 & 0xfffffffc) << (DAT_020c1944 & 3) * -8 + 0x20
                              ) + 0x3d0)) &&
       (uVar4 == DAT_020c194c *
                 ((int)((longlong)DAT_020c1948 * (longlong)(int)uVar4 >> 0x21) -
                 ((int)uVar4 >> 0x1f)))) {
      switch(uVar5) {
      case 0:
        NNSi_MaybeSndPlayerStartSeq(DAT_020c1950,0,0x32);
        break;
      case 1:
        NNSi_MaybeSndPlayerStartSeq(DAT_020c1950,0,0x33);
        break;
      case 2:
        NNSi_MaybeSndPlayerStartSeq(DAT_020c1950,0,0x34);
        break;
      case 3:
        NNSi_MaybeSndPlayerStartSeq(DAT_020c1950,0,0x35);
        break;
      case 4:
        NNSi_MaybeSndPlayerStartSeq(DAT_020c1950,0,0x36);
        break;
      case 5:
        NNSi_MaybeSndPlayerStartSeq(DAT_020c1950,0,0x37);
        break;
      case 6:
        NNSi_MaybeSndPlayerStartSeq(DAT_020c1950,0,0x38);
        break;
      case 7:
        NNSi_MaybeSndPlayerStartSeq(DAT_020c1950,0,0x39);
      }
      uVar2 = DAT_020c1940;
      uVar6 = *(uint *)(DAT_020c1940 & 0xfffffffc) >> (DAT_020c1940 & 3) * 8 |
              *(uint *)(DAT_020c1940 & 0xfffffffc) << (DAT_020c1940 & 3) * -8 + 0x20;
      uVar5 = uVar6 + 0xa8;
      uVar1 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar3 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
      *(uint *)(uVar6 + 0xa8) = uVar3 + 1;
      uVar5 = uVar2 & 3;
      uVar1 = *(uint *)(uVar2 & 0xfffffffc);
      *(undefined4 *)((uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) + uVar3 * 4) = 0;
    }
  }
  else {
    func_020c1060();
    uVar1 = DAT_020c1940;
    *(undefined4 *)
     ((*(uint *)(DAT_020c1940 & 0xfffffffc) >> (DAT_020c1940 & 3) * 8 |
      *(uint *)(DAT_020c1940 & 0xfffffffc) << (DAT_020c1940 & 3) * -8 + 0x20) + 0xac) = DAT_020c1954
    ;
    uVar5 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    *(undefined4 *)((uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) + 0xb0) = 0;
  }
  uVar1 = DAT_020c1944;
  uVar5 = DAT_020c1940;
  if ((*(ushort *)(DAT_020c1958 + 0x2e0) & 1) == 0) {
    return;
  }
  if ((int)uVar4 < 0x2d) {
    return;
  }
  uVar4 = 0;
  uVar2 = (uint)*(byte *)((*(uint *)(DAT_020c1944 & 0xfffffffc) >> (DAT_020c1944 & 3) * 8 |
                          *(uint *)(DAT_020c1944 & 0xfffffffc) << (DAT_020c1944 & 3) * -8 + 0x20) +
                         0x3d0);
  if (uVar2 != 0) {
    do {
      uVar2 = uVar5 & 3;
      uVar3 = *(uint *)(uVar5 & 0xfffffffc);
      *(undefined4 *)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + uVar4 * 4) = 0;
      uVar2 = uVar1 & 3;
      uVar3 = *(uint *)(uVar1 & 0xfffffffc);
      uVar2 = (uint)*(byte *)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0x3d0);
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < uVar2);
  }
  *(uint *)((*(uint *)(DAT_020c1940 & 0xfffffffc) >> (DAT_020c1940 & 3) * 8 |
            *(uint *)(DAT_020c1940 & 0xfffffffc) << (DAT_020c1940 & 3) * -8 + 0x20) + 0xa8) = uVar2;
  func_020c1060();
  uVar5 = DAT_020c1940;
  *(undefined4 *)
   ((*(uint *)(DAT_020c1940 & 0xfffffffc) >> (DAT_020c1940 & 3) * 8 |
    *(uint *)(DAT_020c1940 & 0xfffffffc) << (DAT_020c1940 & 3) * -8 + 0x20) + 0xac) = DAT_020c1954;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(undefined4 *)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0xb0) = 0;
  return;
}

