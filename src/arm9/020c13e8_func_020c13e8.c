/* Decompiled C draft; module arm9; ROM address 020c13e8. No matching claim. */
#include "types.h"
#include "deps/020c13e8_func_020c13e8.h"

void func_020c13e8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  uVar3 = *(uint *)(uRam020c154c & 0xfffffffc) >> (uRam020c154c & 3) * 8 |
          *(uint *)(uRam020c154c & 0xfffffffc) << (uRam020c154c & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0xb0;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  *(uint *)(uVar3 + 0xb0) = uVar2 + 1;
  if (0x3b < (int)uVar2) {
    uVar3 = *(uint *)(uRam020c1550 & 0xfffffffc) >> (uRam020c1550 & 3) * 8 |
            *(uint *)(uRam020c1550 & 0xfffffffc) << (uRam020c1550 & 3) * -8 + 0x20;
    uVar2 = uVar3 + 0x1c & 3;
    uVar1 = *(uint *)(uVar3 + 0x1c & 0xfffffffc);
    if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 1) ||
       (uVar2 = uVar3 + 8 & 3, uVar1 = *(uint *)(uVar3 + 8 & 0xfffffffc),
       (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 2)) {
      if (*(char *)(uVar3 + 0x58) == '\0') {
        uVar3 = *(uint *)(uRam020c154c & 0xfffffffc) >> (uRam020c154c & 3) * 8 |
                *(uint *)(uRam020c154c & 0xfffffffc) << (uRam020c154c & 3) * -8 + 0x20;
        uVar2 = uVar3 + 0x40 & 3;
        uVar1 = *(uint *)(uVar3 + 0x40 & 0xfffffffc);
        uVar2 = uVar3 + (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) * 4 + 0x20;
        uVar1 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      }
      else {
        iVar5 = GetSomeLUMaxIndex();
        uVar2 = (uint)*(byte *)((*(uint *)(uRam020c1554 & 0xfffffffc) >> (uRam020c1554 & 3) * 8 |
                                *(uint *)(uRam020c1554 & 0xfffffffc) <<
                                (uRam020c1554 & 3) * -8 + 0x20) + iVar5 * 8 + 0x146);
        iVar5 = GetSomeLUMaxIndex();
        uVar3 = (*(uint *)(uRam020c1554 & 0xfffffffc) >> (uRam020c1554 & 3) * 8 |
                *(uint *)(uRam020c1554 & 0xfffffffc) << (uRam020c1554 & 3) * -8 + 0x20) + 0x144;
        uVar1 = (uint)*(byte *)(uVar3 + iVar5 * 8 + 6);
        if (uVar2 <= uVar1) {
          uVar2 = uVar1;
        }
      }
      uVar1 = (uint)*(ushort *)
                     ((*(uint *)(uRam020c1550 & 0xfffffffc) >> (uRam020c1550 & 3) * 8 |
                      *(uint *)(uRam020c1550 & 0xfffffffc) << (uRam020c1550 & 3) * -8 + 0x20) +
                     0x3d8);
      if ((int)uVar1 <= (int)uVar2) {
        uVar3 = 1;
      }
      if ((int)uVar2 < (int)uVar1) {
        uVar3 = 0;
      }
      *(uint *)((*(uint *)(uRam020c154c & 0xfffffffc) >> (uRam020c154c & 3) * 8 |
                *(uint *)(uRam020c154c & 0xfffffffc) << (uRam020c154c & 3) * -8 + 0x20) + 0xb4) =
           uVar3;
    }
    else {
      uVar2 = (uint)*(ushort *)(uVar3 + 0x60);
      bVar6 = *(ushort *)(uVar3 + 0x3d8) <= uVar2;
      if (bVar6) {
        uVar2 = 1;
      }
      if (!bVar6) {
        uVar2 = 0;
      }
      *(uint *)((*(uint *)(uRam020c154c & 0xfffffffc) >> (uRam020c154c & 3) * 8 |
                *(uint *)(uRam020c154c & 0xfffffffc) << (uRam020c154c & 3) * -8 + 0x20) + 0xb4) =
           uVar2;
    }
    uVar1 = uRam020c154c;
    *(undefined4 *)
     ((*(uint *)(uRam020c154c & 0xfffffffc) >> (uRam020c154c & 3) * 8 |
      *(uint *)(uRam020c154c & 0xfffffffc) << (uRam020c154c & 3) * -8 + 0x20) + 0xac) = uRam020c1558
    ;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    *(undefined4 *)((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0xb0) = 0;
    return;
  }
  func_020c1060();
  uVar1 = uRam020c1550;
  uVar2 = uRam020c154c;
  iVar5 = 0;
  if (*(char *)((*(uint *)(uRam020c1550 & 0xfffffffc) >> (uRam020c1550 & 3) * 8 |
                *(uint *)(uRam020c1550 & 0xfffffffc) << (uRam020c1550 & 3) * -8 + 0x20) + 0x3d0) ==
      '\0') {
    return;
  }
  do {
    uVar3 = uVar2 & 3;
    uVar4 = *(uint *)(uVar2 & 0xfffffffc);
    *(undefined4 *)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + iVar5 * 4) = 1;
    uVar3 = uVar1 & 3;
    uVar4 = *(uint *)(uVar1 & 0xfffffffc);
    iVar5 = iVar5 + 1;
  } while (iVar5 < (int)(uint)*(byte *)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x3d0));
  return;
}

