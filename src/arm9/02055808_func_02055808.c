/* Decompiled C draft; module arm9; ROM address 02055808. No matching claim. */
#include "types.h"
#include "deps/02055808_func_02055808.h"

undefined4 func_02055808(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = DAT_020559e8;
  uVar5 = 0;
  uVar4 = *(uint *)(DAT_020559e8 & 0xfffffffc) >> (DAT_020559e8 & 3) * 8 |
          *(uint *)(DAT_020559e8 & 0xfffffffc) << (DAT_020559e8 & 3) * -8 + 0x20;
  uVar6 = uVar4 + 0x10 & 3;
  uVar2 = *(uint *)(uVar4 + 0x10 & 0xfffffffc);
  if (uVar2 >> uVar6 * 8 != 0 || uVar2 << uVar6 * -8 + 0x20 != 0) {
    return 0;
  }
  uVar6 = uVar5;
  if (uVar4 != 0) {
    uVar6 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  }
  uVar2 = uVar5;
  if ((uVar6 != 0) &&
     (uVar6 = uVar4 + 4 & 3, uVar3 = *(uint *)(uVar4 + 4 & 0xfffffffc),
     (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) != 0xd)) {
    uVar2 = 1;
  }
  uVar6 = uVar5;
  if ((uVar2 != 0) && ((*(ushort *)(uVar4 + 0x454) & 0x80) == 0)) {
    uVar6 = 1;
  }
  if ((uVar6 != 0) &&
     (uVar6 = uVar4 + 8 & 3, uVar2 = *(uint *)(uVar4 + 8 & 0xfffffffc),
     (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) != 9)) {
    uVar5 = 1;
  }
  if (uVar5 != 0) {
    return 3;
  }
  uVar6 = uVar4 + 0xc & 3;
  uVar2 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
  uVar6 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
  if (0x15 < (int)uVar6) {
    if (uVar6 != 0x24) goto switchD_020558a4_default;
LAB_02055940:
    if (param_1 != 0) {
      func_020532dc(0x14);
      return 0;
    }
    *(undefined4 *)(uVar4 + 4) = 3;
    func_020527c0(1,0,0);
    return 1;
  }
  switch(uVar6) {
  case 0:
    goto LAB_02055910;
  case 1:
    func_02052ecc();
    return 0;
  case 2:
    goto LAB_02055940;
  case 3:
    func_02053094(0);
    return 0;
  case 4:
    func_0204f814();
    func_0204fb40(1);
    func_02052bf8();
    return 0;
  case 5:
    func_02052b60(0);
    return 0;
  case 6:
    func_02051a24();
    return 0;
  case 7:
    break;
  case 8:
    break;
  case 9:
    break;
  case 10:
    break;
  case 0xb:
    *(undefined4 *)(uVar4 + 4) = 2;
    *(undefined2 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x82) = 0;
    uVar6 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    *(byte *)(uVar6 + 0x8b) = *(byte *)(uVar6 + 0x8b) & 0xf7;
    return 1;
  case 0xc:
    break;
  case 0xd:
    break;
  case 0xe:
    break;
  case 0xf:
    break;
  case 0x10:
    break;
  case 0x11:
    break;
  case 0x12:
    break;
  case 0x13:
    break;
  case 0x14:
    break;
  case 0x15:
LAB_02055910:
    *(ushort *)(uVar4 + 0x454) = *(ushort *)(uVar4 + 0x454) & 0xffbf;
    *(undefined4 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 4) = 1;
    func_020536e0();
    return 0;
  }
switchD_020558a4_default:
  func_020533a0();
  return 0;
}

