/* Decompiled C draft; module arm9; ROM address 02055564. No matching claim. */
#include "types.h"
#include "deps/02055564_func_02055564.h"

undefined4 func_02055564(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  undefined4 uVar8;
  
  uVar8 = 0;
  uVar6 = *(uint *)(DAT_02055700 & 0xfffffffc) >> (DAT_02055700 & 3) * 8 |
          *(uint *)(DAT_02055700 & 0xfffffffc) << (DAT_02055700 & 3) * -8 + 0x20;
  uVar3 = uVar6 + 0x10 & 3;
  uVar5 = *(uint *)(uVar6 + 0x10 & 0xfffffffc);
  if (uVar5 >> uVar3 * 8 != 0 || uVar5 << uVar3 * -8 + 0x20 != 0) {
    uVar3 = uVar6 + 0xc & 3;
    uVar5 = *(uint *)(uVar6 + 0xc & 0xfffffffc);
    if ((((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) == 7) &&
        (*(char *)(uVar6 + 0x43b) == '\x01')) && (iVar2 = func_020501b0(), iVar2 == 0)) {
      func_02050e60(5);
    }
    return 0;
  }
  if (uVar6 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
  }
  bVar1 = false;
  bVar7 = false;
  bVar4 = false;
  if ((uVar3 != 0) &&
     (uVar3 = uVar6 + 4 & 3, uVar5 = *(uint *)(uVar6 + 4 & 0xfffffffc),
     (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) != 0xd)) {
    bVar4 = true;
  }
  if ((bVar4) && ((*(ushort *)(uVar6 + 0x454) & 0x80) == 0)) {
    bVar7 = true;
  }
  if ((bVar7) &&
     (uVar3 = uVar6 + 8 & 3, uVar5 = *(uint *)(uVar6 + 8 & 0xfffffffc),
     (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) != 9)) {
    bVar1 = true;
  }
  if (bVar1) {
    return 3;
  }
  uVar3 = uVar6 + 0xc & 3;
  uVar5 = *(uint *)(uVar6 + 0xc & 0xfffffffc);
  switch(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    goto LAB_02055694;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    func_02051e98();
    break;
  case 8:
    break;
  case 9:
    func_02051d24(0,0,0,DAT_02055704);
    break;
  case 10:
LAB_02055694:
    if (*(ushort *)(uVar6 + 0x432) == DAT_02055708) {
      if (*DAT_0205570c == 2) {
        func_02050e60(5);
        return 3;
      }
      uVar8 = 2;
    }
    else {
      func_02051a24();
    }
    break;
  case 0xb:
    *(undefined4 *)(uVar6 + 4) = 6;
    func_02059878();
    uVar8 = 1;
  }
  return uVar8;
}

