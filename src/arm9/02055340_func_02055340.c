/* Decompiled C draft; module arm9; ROM address 02055340. No matching claim. */
#include "types.h"
#include "deps/02055340_func_02055340.h"

void func_02055340(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  
  uVar4 = DAT_020554e0;
  bVar5 = false;
  uVar6 = *(uint *)(DAT_020554e0 & 0xfffffffc) >> (DAT_020554e0 & 3) * 8 |
          *(uint *)(DAT_020554e0 & 0xfffffffc) << (DAT_020554e0 & 3) * -8 + 0x20;
  if (uVar6 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
  }
  if ((uVar1 != 0) &&
     (uVar1 = uVar6 + 4 & 3, uVar2 = *(uint *)(uVar6 + 4 & 0xfffffffc),
     (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != 0xd)) {
    bVar5 = true;
  }
  if (!bVar5) {
    return;
  }
  uVar1 = uVar6 + 4 & 3;
  uVar2 = *(uint *)(uVar6 + 4 & 0xfffffffc);
  switch(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    uVar1 = *(uint *)(DAT_020554e0 & 0xfffffffc) >> (DAT_020554e0 & 3) * 8 |
            *(uint *)(DAT_020554e0 & 0xfffffffc) << (DAT_020554e0 & 3) * -8 + 0x20;
    uVar2 = (uint)*(ushort *)(uVar1 + 0x82);
    if (7 < uVar2) {
      *(short *)(uVar6 + 0x82) = *(short *)(uVar6 + 0x82) + 1;
      uVar6 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar4 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
      if (0x2c < *(ushort *)(uVar4 + 0x82)) {
        *(undefined2 *)(uVar4 + 0x82) = 0;
      }
      return;
    }
    if (((*(byte *)(uVar1 + 0x87) | 1) & 1 << (uVar2 & 7)) != 0) {
      iVar3 = func_020504a4();
      if (iVar3 == 0) {
        return;
      }
      uVar4 = *(uint *)(DAT_020554e0 & 0xfffffffc) >> (DAT_020554e0 & 3) * 8 |
              *(uint *)(DAT_020554e0 & 0xfffffffc) << (DAT_020554e0 & 3) * -8 + 0x20;
      *(short *)(uVar4 + 0x82) = *(short *)(uVar4 + 0x82) + 1;
      return;
    }
    *(short *)(uVar6 + 0x82) = *(short *)(uVar6 + 0x82) + 1;
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    goto LAB_020553bc;
  case 8:
    goto LAB_020553bc;
  case 9:
LAB_020553bc:
    iVar3 = func_0205373c();
    if (iVar3 == 0) {
      uVar4 = *(uint *)(DAT_020554e0 & 0xfffffffc) >> (DAT_020554e0 & 3) * 8 |
              *(uint *)(DAT_020554e0 & 0xfffffffc) << (DAT_020554e0 & 3) * -8 + 0x20;
      *(ushort *)(uVar4 + 0x454) = *(ushort *)(uVar4 + 0x454) | 0x10;
    }
    uVar1 = *(uint *)(DAT_020554e0 & 0xfffffffc) >> (DAT_020554e0 & 3) * 8 |
            *(uint *)(DAT_020554e0 & 0xfffffffc) << (DAT_020554e0 & 3) * -8 + 0x20;
    uVar4 = uVar1 + 4 & 3;
    uVar6 = *(uint *)(uVar1 + 4 & 0xfffffffc);
    if ((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) != 9) {
      return;
    }
    if (uVar1 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    }
    if (uVar4 != 1) {
      return;
    }
    func_02001000();
    return;
  }
  return;
}

