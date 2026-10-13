/* Decompiled C draft; module arm9; ROM address 020a2558. No matching claim. */
#include "types.h"
#include "deps/020a2558_func_020a2558.h"

void func_020a2558(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar7;
  uint uVar6;
  
  if (2 < *(ushort *)
           ((*(uint *)(uRam020a2664 & 0xfffffffc) >> (uRam020a2664 & 3) * 8 |
            *(uint *)(uRam020a2664 & 0xfffffffc) << (uRam020a2664 & 3) * -8 + 0x20) + 2)) {
    return;
  }
  func_0208b8c8();
  uVar5 = uRam020a2664;
  uVar4 = *(uint *)(uRam020a2664 & 0xfffffffc) >> (uRam020a2664 & 3) * 8 |
          *(uint *)(uRam020a2664 & 0xfffffffc) << (uRam020a2664 & 3) * -8 + 0x20;
  *(short *)(uVar4 + 4) = *(short *)(uVar4 + 4) + 0x6d;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar6 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar4 = uVar6 + 0x20 & 3;
  uVar5 = *(uint *)(uVar6 + 0x20 & 0xfffffffc);
  *(ushort *)(uVar6 + 8) =
       *(short *)(uVar6 + 8) + ((ushort)(uVar5 >> uVar4 * 8) | (ushort)(uVar5 << uVar4 * -8 + 0x20))
  ;
  uVar1 = Maybe_get_15d4b4_8(*(undefined2 *)(uVar6 + 8));
  uVar4 = uVar6 + 0x18 & 3;
  uVar5 = *(uint *)(uVar6 + 0x18 & 0xfffffffc);
  iVar2 = func_020a2668(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20,uVar1);
  uVar4 = uVar6 + 0x14 & 3;
  uVar7 = *(uint *)(uVar6 + 0x14 & 0xfffffffc);
  uVar5 = uVar6 + 0xc & 3;
  uVar3 = *(uint *)(uVar6 + 0xc & 0xfffffffc);
  *(uint *)(uVar6 + 0x10) =
       ((uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + iVar2) -
       (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
  uVar4 = uVar6 + 0xc & 3;
  uVar7 = *(uint *)(uVar6 + 0xc & 0xfffffffc);
  uVar5 = uVar6 + 0x10 & 3;
  uVar3 = *(uint *)(uVar6 + 0x10 & 0xfffffffc);
  *(uint *)(uVar6 + 0xc) =
       (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) +
       (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
  uVar4 = uVar6 + 0x18 & 3;
  uVar5 = *(uint *)(uVar6 + 0x18 & 0xfffffffc);
  uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  if ((int)uVar4 < 1) {
    if ((int)uVar4 < 0) {
      uVar5 = uVar6 + 0x1c & 3;
      uVar3 = *(uint *)(uVar6 + 0x1c & 0xfffffffc);
      iVar2 = uVar4 + (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
      if (-1 < iVar2) {
        iVar2 = 0;
      }
      *(int *)(uVar6 + 0x18) = iVar2;
    }
  }
  else {
    uVar5 = uVar6 + 0x1c & 3;
    uVar3 = *(uint *)(uVar6 + 0x1c & 0xfffffffc);
    iVar2 = uVar4 + (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
    if (iVar2 < 1) {
      iVar2 = 0;
    }
    *(int *)(uVar6 + 0x18) = iVar2;
  }
  uVar4 = uVar6 + 0x20 & 3;
  uVar5 = *(uint *)(uVar6 + 0x20 & 0xfffffffc);
  uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  if ((int)uVar4 < 1) {
    if ((int)uVar4 < 0) {
      uVar5 = uVar6 + 0x24 & 3;
      uVar3 = *(uint *)(uVar6 + 0x24 & 0xfffffffc);
      iVar2 = uVar4 + (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
      if (-1 < iVar2) {
        iVar2 = 0;
      }
      *(int *)(uVar6 + 0x20) = iVar2;
      return;
    }
    return;
  }
  uVar5 = uVar6 + 0x24 & 3;
  uVar3 = *(uint *)(uVar6 + 0x24 & 0xfffffffc);
  iVar2 = uVar4 + (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
  if (iVar2 < 1) {
    iVar2 = 0;
  }
  *(int *)(uVar6 + 0x20) = iVar2;
  return;
}

