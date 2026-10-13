/* Decompiled C draft; module arm9; ROM address 02049b6c. No matching claim. */
#include "types.h"
#include "deps/02049b6c_func_02049b6c.h"

undefined4 func_02049b6c(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar4 = 0;
  uVar5 = (*(uint *)(uRam02049c30 & 0xfffffffc) >> (uRam02049c30 & 3) * 8 |
          *(uint *)(uRam02049c30 & 0xfffffffc) << (uRam02049c30 & 3) * -8 + 0x20) + 8;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) == 5) {
    bVar1 = false;
    uVar5 = *(uint *)(uRam02049c34 & 0xfffffffc) >> (uRam02049c34 & 3) * 8 |
            *(uint *)(uRam02049c34 & 0xfffffffc) << (uRam02049c34 & 3) * -8 + 0x20;
    if ((uVar5 != 0) && ((*(ushort *)(uVar5 + 0x75c) & 0x10) != 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      uVar4 = 1;
    }
  }
  bVar3 = false;
  uVar5 = *(uint *)(uRam02049c38 & 0xfffffffc) >> (uRam02049c38 & 3) * 8 |
          *(uint *)(uRam02049c38 & 0xfffffffc) << (uRam02049c38 & 3) * -8 + 0x20;
  bVar1 = false;
  if (uVar5 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
  }
  bVar2 = false;
  if ((uVar6 != 0) &&
     (uVar6 = uVar5 + 4 & 3, uVar7 = *(uint *)(uVar5 + 4 & 0xfffffffc),
     (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) != 0xd)) {
    bVar2 = true;
  }
  if ((bVar2) && ((*(ushort *)(uVar5 + 0x454) & 0x80) == 0)) {
    bVar1 = true;
  }
  if ((bVar1) && ((*(ushort *)(uVar5 + 0x454) & 0x10) != 0)) {
    bVar3 = true;
  }
  if (bVar3) {
    uVar4 = 1;
  }
  return uVar4;
}

