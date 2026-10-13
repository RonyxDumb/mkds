/* Decompiled C draft; module arm9; ROM address 02075694. No matching claim. */
#include "types.h"
#include "deps/02075694_SomeLookAtHD_HD2.h"

int SomeLookAtHD_HD2(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  
  uVar1 = uRam020757cc;
  uVar6 = *(uint *)(uRam020757cc & 0xfffffffc) >> (uRam020757cc & 3) * 8 |
          *(uint *)(uRam020757cc & 0xfffffffc) << (uRam020757cc & 3) * -8 + 0x20;
  uVar2 = uVar6 + 0x218;
  uVar8 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20;
  if (uVar2 != 0) {
    if (*(short *)(uVar2 + 0x3e) == 4) {
      *(undefined4 *)
       ((*(uint *)(uRam020757d0 & 0xfffffffc) >> (uRam020757d0 & 3) * 8 |
        *(uint *)(uRam020757d0 & 0xfffffffc) << (uRam020757d0 & 3) * -8 + 0x20) + 0x24c) = 1;
      *(undefined4 *)
       ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
        *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x24c) = 2;
    }
    else {
      *(undefined4 *)(uVar6 + 0x24c) = 0;
      uVar2 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x24c;
      uVar8 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)((*(uint *)(uRam020757d0 & 0xfffffffc) >> (uRam020757d0 & 3) * 8 |
                *(uint *)(uRam020757d0 & 0xfffffffc) << (uRam020757d0 & 3) * -8 + 0x20) + 0x24c) =
           uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20;
    }
  }
  StructHD_SomeFn_0(*(uint *)(uRam020757d0 & 0xfffffffc) >> (uRam020757d0 & 3) * 8 |
                    *(uint *)(uRam020757d0 & 0xfffffffc) << (uRam020757d0 & 3) * -8 + 0x20);
  uVar6 = uRam020757d0;
  uVar1 = uRam020757cc;
  uVar3 = *(uint *)(uRam020757cc & 0xfffffffc) >> (uRam020757cc & 3) * 8 |
          *(uint *)(uRam020757cc & 0xfffffffc) << (uRam020757cc & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x24c;
  uVar8 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) == 2) {
    *(undefined2 *)(uVar3 + 0x68) =
         *(undefined2 *)
          ((*(uint *)(uRam020757d0 & 0xfffffffc) >> (uRam020757d0 & 3) * 8 |
           *(uint *)(uRam020757d0 & 0xfffffffc) << (uRam020757d0 & 3) * -8 + 0x20) + 0x68);
    *(undefined2 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x6a) =
         *(undefined2 *)
          ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
           *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x6a);
    uVar8 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
    uVar2 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    uVar5 = *(undefined4 *)(uVar8 + 0x28);
    uVar7 = *(undefined4 *)(uVar8 + 0x2c);
    *(undefined4 *)(uVar2 + 0x24) = *(undefined4 *)(uVar8 + 0x24);
    *(undefined4 *)(uVar2 + 0x28) = uVar5;
    *(undefined4 *)(uVar2 + 0x2c) = uVar7;
    uVar5 = *(undefined4 *)(uVar8 + 0x1c);
    uVar7 = *(undefined4 *)(uVar8 + 0x20);
    *(undefined4 *)(uVar2 + 0x18) = *(undefined4 *)(uVar8 + 0x18);
    *(undefined4 *)(uVar2 + 0x1c) = uVar5;
    *(undefined4 *)(uVar2 + 0x20) = uVar7;
  }
  else {
    StructHD_SomeFn_0();
  }
  iVar4 = func_02061f7c();
  if (iVar4 == 0) {
    StructHD_SomeLookAt((undefined4 *)(uintptr_t)(*(uint *)(uRam020757d0 & 0xfffffffc) >> (uRam020757d0 & 3) * 8 |
                        *(uint *)(uRam020757d0 & 0xfffffffc) << (uRam020757d0 & 3) * -8 + 0x20));
    uVar2 = *(uint *)(uRam020757d0 & 0xfffffffc) >> (uRam020757d0 & 3) * 8 |
            *(uint *)(uRam020757d0 & 0xfffffffc) << (uRam020757d0 & 3) * -8 + 0x20;
    *puRam020757d4 = uVar2;
    return uVar2 + 0x30;
  }
  StructHD_SomeLookAt((undefined4 *)(uintptr_t)(*(uint *)(uRam020757cc & 0xfffffffc) >> (uRam020757cc & 3) * 8 |
                      *(uint *)(uRam020757cc & 0xfffffffc) << (uRam020757cc & 3) * -8 + 0x20));
  uVar2 = *(uint *)(uRam020757cc & 0xfffffffc) >> (uRam020757cc & 3) * 8 |
          *(uint *)(uRam020757cc & 0xfffffffc) << (uRam020757cc & 3) * -8 + 0x20;
  *puRam020757d4 = uVar2;
  return uVar2 + 0x30;
}

