/* Decompiled C draft; module arm9; ROM address 020a1790. No matching claim. */
#include "types.h"
#include "deps/020a1790_func_020a1790.h"

void func_020a1790(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = *(uint *)(uRam020a18fc & 0xfffffffc) >> (uRam020a18fc & 3) * 8 |
          *(uint *)(uRam020a18fc & 0xfffffffc) << (uRam020a18fc & 3) * -8 + 0x20;
  uVar6 = (uint)*(byte *)((*(uint *)(uRam020a18f8 & 0xfffffffc) >> (uRam020a18f8 & 3) * 8 |
                          *(uint *)(uRam020a18f8 & 0xfffffffc) << (uRam020a18f8 & 3) * -8 + 0x20) +
                         0x3d0);
  uVar5 = 0;
  uVar2 = uVar4;
  do {
    if (*(short *)(uVar2 + 0x48) == 0) {
      uVar5 = uVar5 & 0xffff;
      goto LAB_020a17d8;
    }
    uVar5 = uVar5 + 1;
    uVar2 = uVar2 + 0x70;
  } while ((int)uVar5 < 8);
  uVar5 = 0;
LAB_020a17d8:
  uVar5 = (uint)*(ushort *)(uVar5 * 0x70 + uVar4 + 0x46);
  iVar3 = 0;
  do {
    uVar2 = uVar4 + 8 & 3;
    uVar1 = *(uint *)(uVar4 + 8 & 0xfffffffc);
    if ((uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) &&
       (uVar5 != *(ushort *)(uVar4 + 0x46))) {
      return;
    }
    iVar3 = iVar3 + 1;
    uVar4 = uVar4 + 0x70;
  } while (iVar3 < 8);
  uVar2 = 0;
  if (uVar6 != 0) {
    do {
      iVar3 = GetDriverEntry(uVar2 & 0xffff);
      uVar4 = iVar3 + 0x48U & 3;
      uVar1 = *(uint *)(iVar3 + 0x48U & 0xfffffffc);
      uVar2 = uVar2 + 1;
      *(uint *)(iVar3 + 0x48) = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20 | 0x2000;
      uVar4 = iVar3 + 0x7cU & 3;
      uVar1 = *(uint *)(iVar3 + 0x7cU & 0xfffffffc);
      *(uint *)(iVar3 + 0x7c) = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20 | 8;
    } while ((int)uVar2 < (int)uVar6);
  }
  uVar4 = uRam020a18fc;
  uVar2 = uRam020a18f8;
  *(uint *)((*(uint *)(uRam020a18fc & 0xfffffffc) >> (uRam020a18fc & 3) * 8 |
            *(uint *)(uRam020a18fc & 0xfffffffc) << (uRam020a18fc & 3) * -8 + 0x20) + 0x3b4) = uVar5
  ;
  uVar5 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar6 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  uVar5 = uVar6 + 8 & 3;
  uVar2 = *(uint *)(uVar6 + 8 & 0xfffffffc);
  uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  if (uVar5 != 2) {
    if (uVar5 == 4) {
      uVar5 = uVar4 & 3;
      uVar2 = *(uint *)(uVar4 & 0xfffffffc);
      uVar4 = (uint)*(char *)(uVar6 + 0x62);
      uVar5 = (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 0x3b4;
      uVar2 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      if ((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) == uVar4) {
        func_0203e74c(uVar4 & 0xffff);
      }
      else {
        func_0203cd04(uVar4 & 0xffff);
      }
      *(undefined4 *)
       ((*(uint *)(uRam020a18fc & 0xfffffffc) >> (uRam020a18fc & 3) * 8 |
        *(uint *)(uRam020a18fc & 0xfffffffc) << (uRam020a18fc & 3) * -8 + 0x20) + 0x3a8) = 0;
      return;
    }
    return;
  }
  uVar5 = uVar6 + 0x18 & 3;
  uVar2 = *(uint *)(uVar6 + 0x18 & 0xfffffffc);
  if ((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) == 1) {
    NNSi_MaybeSndPlayerStartSeq(uRam020a1900,0,0x4a);
  }
  *(undefined4 *)
   ((*(uint *)(uRam020a18fc & 0xfffffffc) >> (uRam020a18fc & 3) * 8 |
    *(uint *)(uRam020a18fc & 0xfffffffc) << (uRam020a18fc & 3) * -8 + 0x20) + 0x3a8) = 0x5a;
  return;
}

