/* Decompiled C draft; module arm9; ROM address 02045920. No matching claim. */
#include "types.h"
#include "deps/02045920_func_02045920.h"

undefined4 func_02045920(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar4;
  
  uVar4 = uRam02045a28;
  uVar1 = *(uint *)(uRam02045a28 & 0xfffffffc) >> (uRam02045a28 & 3) * 8 |
          *(uint *)(uRam02045a28 & 0xfffffffc) << (uRam02045a28 & 3) * -8 + 0x20;
  *(short *)(uVar1 + 0x248) = *(short *)(uVar1 + 0x248) + 1;
  uVar1 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  if ((1 < *(byte *)(uVar1 + 0x3d4)) && (iVar7 = 0, *(char *)(uVar1 + 0x3d0) != '\0')) {
    iVar5 = 0;
    do {
      uVar2 = uVar1 + iVar5 + 0x78;
      uVar3 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar6 = 3;
      if (uVar2 == 0) {
        uVar6 = 1;
      }
      else if (uVar2 == 1) {
        uVar6 = 0;
      }
      *(undefined4 *)(uVar1 + iVar5 + 0x260) = uVar6;
      uVar1 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
      iVar7 = iVar7 + 1;
      iVar5 = iVar5 + 0x30;
    } while (iVar7 < (int)(uint)*(byte *)(uVar1 + 0x3d0));
  }
  uVar2 = uRam02045a28;
  uVar4 = uVar1 + 0x20 & 3;
  uVar3 = *(uint *)(uVar1 + 0x20 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar4 != 0) {
    if ((uVar4 != 1) && (uVar4 != 2)) {
      return 1;
    }
    *(char *)(uVar1 + 0x3e0) = *(char *)(uVar1 + 0x3e0) + '\x01';
    uVar4 = uVar2 & 3;
    uVar1 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
    uVar4 = uVar2 + 0x3dc & 3;
    uVar1 = *(uint *)(uVar2 + 0x3dc & 0xfffffffc);
    if (*(char *)((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) + (uint)*(byte *)(uVar2 + 0x3e0)
                 ) == '\0') {
      *(undefined1 *)(uVar2 + 0x3e0) = 0;
    }
    uVar2 = *(uint *)(uRam02045a28 & 0xfffffffc) >> (uRam02045a28 & 3) * 8 |
            *(uint *)(uRam02045a28 & 0xfffffffc) << (uRam02045a28 & 3) * -8 + 0x20;
    uVar4 = uVar2 + 0x3dc & 3;
    uVar1 = *(uint *)(uVar2 + 0x3dc & 0xfffffffc);
    *(uint *)(uVar2 + 0x1e8) =
         (uint)*(byte *)((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) +
                        (uint)*(byte *)(uVar2 + 0x3e0));
    return 1;
  }
  return 0;
}

