/* Decompiled C draft; module arm9; ROM address 02054b44. No matching claim. */
#include "types.h"
#include "deps/02054b44_func_02054b44.h"

undefined4 func_02054b44(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  undefined4 uVar7;
  
  uVar7 = 0;
  uVar2 = *(uint *)(uRam02054c90 & 0xfffffffc) >> (uRam02054c90 & 3) * 8 |
          *(uint *)(uRam02054c90 & 0xfffffffc) << (uRam02054c90 & 3) * -8 + 0x20;
  bVar1 = false;
  if (uVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
  }
  bVar6 = false;
  bVar5 = false;
  if ((uVar3 != 0) &&
     (uVar3 = uVar2 + 4 & 3, uVar4 = *(uint *)(uVar2 + 4 & 0xfffffffc),
     (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) != 0xd)) {
    bVar5 = true;
  }
  if ((bVar5) && ((*(ushort *)(uVar2 + 0x454) & 0x80) == 0)) {
    bVar6 = true;
  }
  if ((bVar6) &&
     (uVar3 = uVar2 + 8 & 3, uVar4 = *(uint *)(uVar2 + 8 & 0xfffffffc),
     (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) != 9)) {
    bVar1 = true;
  }
  if (bVar1) {
    return 3;
  }
  uVar3 = uVar2 + 0x1e3c & 3;
  uVar4 = *(uint *)(uVar2 + 0x1e3c & 0xfffffffc);
  if (uVar4 >> uVar3 * 8 != 0 || uVar4 << uVar3 * -8 + 0x20 != 0) {
    if ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
        *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) == 2) {
      uVar3 = (uint)*(ushort *)(uVar2 + 0x432);
    }
    else {
      uVar3 = 0;
    }
    if (uVar3 == uRam02054c94) {
      return 2;
    }
  }
  uVar3 = uVar2 + 0x10 & 3;
  uVar4 = *(uint *)(uVar2 + 0x10 & 0xfffffffc);
  if (uVar4 >> uVar3 * 8 != 0 || uVar4 << uVar3 * -8 + 0x20 != 0) {
    return 0;
  }
  if (uVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
  }
  if (uVar3 == 1) {
    return 1;
  }
  uVar3 = uVar2 + 0xc & 3;
  uVar4 = *(uint *)(uVar2 + 0xc & 0xfffffffc);
  uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  if ((uVar3 == 0x28) || (uVar3 == 0x29)) {
    func_0204f148();
  }
  else if (uVar3 == 0x2a) {
    if (uVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
    }
    if (uVar3 == 1) {
      *(undefined4 *)(uVar2 + 0xc) = 0x28;
    }
    else if (uVar3 == 2) {
      *(undefined4 *)(uVar2 + 0xc) = 0x29;
    }
    uVar7 = 1;
  }
  return uVar7;
}

