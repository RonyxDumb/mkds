/* Decompiled C draft; module arm9; ROM address 020c0dd8. No matching claim. */
#include "types.h"
#include "deps/020c0dd8_func_020c0dd8.h"

void func_020c0dd8(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar3 = *(uint *)(uRam020c0ed4 & 0xfffffffc) >> (uRam020c0ed4 & 3) * 8 |
          *(uint *)(uRam020c0ed4 & 0xfffffffc) << (uRam020c0ed4 & 3) * -8 + 0x20;
  uVar4 = uVar3 + 0x1c & 3;
  uVar1 = *(uint *)(uVar3 + 0x1c & 0xfffffffc);
  if (((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) == 1) ||
     (uVar4 = uVar3 + 8 & 3, uVar1 = *(uint *)(uVar3 + 8 & 0xfffffffc),
     (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) == 2)) {
    if (*(char *)(uVar3 + 0x58) == '\0') {
      uVar3 = *(uint *)(uRam020c0edc & 0xfffffffc) >> (uRam020c0edc & 3) * 8 |
              *(uint *)(uRam020c0edc & 0xfffffffc) << (uRam020c0edc & 3) * -8 + 0x20;
      uVar4 = uVar3 + 0x40 & 3;
      uVar1 = *(uint *)(uVar3 + 0x40 & 0xfffffffc);
      uVar4 = uVar3 + (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) * 4 + 0x20;
      uVar1 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    }
    else {
      iVar2 = GetSomeLUMaxIndex();
      uVar4 = (uint)*(byte *)((*(uint *)(uRam020c0ed8 & 0xfffffffc) >> (uRam020c0ed8 & 3) * 8 |
                              *(uint *)(uRam020c0ed8 & 0xfffffffc) << (uRam020c0ed8 & 3) * -8 + 0x20
                              ) + iVar2 * 8 + 0x146);
      iVar2 = GetSomeLUMaxIndex();
      uVar3 = (*(uint *)(uRam020c0ed8 & 0xfffffffc) >> (uRam020c0ed8 & 3) * 8 |
              *(uint *)(uRam020c0ed8 & 0xfffffffc) << (uRam020c0ed8 & 3) * -8 + 0x20) + 0x144;
      uVar1 = (uint)*(byte *)(uVar3 + iVar2 * 8 + 6);
      if (uVar4 <= uVar1) {
        uVar4 = uVar1;
      }
    }
    uVar1 = (uint)*(ushort *)
                   ((*(uint *)(uRam020c0ed4 & 0xfffffffc) >> (uRam020c0ed4 & 3) * 8 |
                    *(uint *)(uRam020c0ed4 & 0xfffffffc) << (uRam020c0ed4 & 3) * -8 + 0x20) + 0x3d8)
    ;
    if ((int)uVar1 <= (int)uVar4) {
      uVar3 = 1;
    }
    if ((int)uVar4 < (int)uVar1) {
      uVar3 = 0;
    }
    *(uint *)((*(uint *)(uRam020c0edc & 0xfffffffc) >> (uRam020c0edc & 3) * 8 |
              *(uint *)(uRam020c0edc & 0xfffffffc) << (uRam020c0edc & 3) * -8 + 0x20) + 0xb4) =
         uVar3;
  }
  else {
    uVar4 = (uint)*(ushort *)(uVar3 + 0x60);
    bVar5 = *(ushort *)(uVar3 + 0x3d8) <= uVar4;
    if (bVar5) {
      uVar4 = 1;
    }
    if (!bVar5) {
      uVar4 = 0;
    }
    *(uint *)((*(uint *)(uRam020c0edc & 0xfffffffc) >> (uRam020c0edc & 3) * 8 |
              *(uint *)(uRam020c0edc & 0xfffffffc) << (uRam020c0edc & 3) * -8 + 0x20) + 0xb4) =
         uVar4;
  }
  uVar1 = uRam020c0edc;
  *(undefined4 *)
   ((*(uint *)(uRam020c0edc & 0xfffffffc) >> (uRam020c0edc & 3) * 8 |
    *(uint *)(uRam020c0edc & 0xfffffffc) << (uRam020c0edc & 3) * -8 + 0x20) + 0xac) = uRam020c0ee0;
  uVar4 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  *(undefined4 *)((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) + 0xb0) = 0;
  return;
}

