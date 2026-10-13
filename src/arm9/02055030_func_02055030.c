/* Decompiled C draft; module arm9; ROM address 02055030. No matching claim. */
#include "types.h"
#include "deps/02055030_func_02055030.h"

undefined4 func_02055030(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  
  uVar4 = *(uint *)(DAT_0205533c & 0xfffffffc) >> (DAT_0205533c & 3) * 8 |
          *(uint *)(DAT_0205533c & 0xfffffffc) << (DAT_0205533c & 3) * -8 + 0x20;
  uVar3 = uVar4 + 4 & 3;
  uVar2 = *(uint *)(uVar4 + 4 & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
    *(ushort *)(uVar4 + 0x454) = *(ushort *)(uVar4 + 0x454) & 0xff7f;
    return 1;
  }
  uVar3 = uVar4 + 0xc & 3;
  uVar2 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
  switch(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) {
  case 0x16:
    goto LAB_020550f0;
  case 0x17:
    goto LAB_020550f0;
  case 0x18:
    goto LAB_020550f0;
  case 0x19:
    goto LAB_020550f0;
  case 0x1a:
    break;
  case 0x1b:
    break;
  case 0x1c:
    break;
  case 0x1d:
    goto LAB_020550e0;
  case 0x1e:
LAB_020550e0:
    func_0204e074();
    break;
  case 0x1f:
    break;
  case 0x20:
    break;
  case 0x21:
    break;
  case 0x22:
    StructZE_StateFn_28_29_30_33_34_35_from_thumb();
    break;
  case 0x23:
    break;
  case 0x24:
    break;
  case 0x25:
    break;
  case 0x26:
    break;
  case 0x27:
    goto LAB_020550f0;
  case 0x28:
    goto LAB_020550f0;
  case 0x29:
    goto LAB_020550f0;
  case 0x2a:
    goto LAB_020550f0;
  case 0x2b:
    goto LAB_020550f0;
  case 0x2c:
    goto LAB_020550f0;
  case 0x2d:
    break;
  case 0x2e:
LAB_020550f0:
    *(undefined4 *)(uVar4 + 0x10) = 0;
  }
  uVar4 = *(uint *)(DAT_0205533c & 0xfffffffc) >> (DAT_0205533c & 3) * 8 |
          *(uint *)(DAT_0205533c & 0xfffffffc) << (DAT_0205533c & 3) * -8 + 0x20;
  uVar3 = uVar4 + 0x10 & 3;
  uVar2 = *(uint *)(uVar4 + 0x10 & 0xfffffffc);
  if (((uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0) &&
      (uVar3 = uVar4 + 0xc & 3, uVar2 = *(uint *)(uVar4 + 0xc & 0xfffffffc),
      (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) == 7)) &&
     (*(char *)(uVar4 + 0x43b) == '\x01')) {
    *(undefined1 *)(uVar4 + 0x43b) = 0;
  }
  uVar4 = *(uint *)(DAT_0205533c & 0xfffffffc) >> (DAT_0205533c & 3) * 8 |
          *(uint *)(DAT_0205533c & 0xfffffffc) << (DAT_0205533c & 3) * -8 + 0x20;
  uVar3 = uVar4 + 0x10 & 3;
  uVar2 = *(uint *)(uVar4 + 0x10 & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0) {
    return 0;
  }
  bVar1 = false;
  if (uVar4 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  }
  bVar6 = false;
  bVar5 = false;
  if ((uVar3 != 0) &&
     (uVar3 = uVar4 + 4 & 3, uVar2 = *(uint *)(uVar4 + 4 & 0xfffffffc),
     (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) != 0xd)) {
    bVar5 = true;
  }
  if ((bVar5) && ((*(ushort *)(uVar4 + 0x454) & 0x80) == 0)) {
    bVar6 = true;
  }
  if ((bVar6) &&
     (uVar3 = uVar4 + 8 & 3, uVar2 = *(uint *)(uVar4 + 8 & 0xfffffffc),
     (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) != 9)) {
    bVar1 = true;
  }
  if (bVar1) {
    return 3;
  }
  uVar3 = uVar4 + 0xc & 3;
  uVar2 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
  switch(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) {
  case 0:
    CleanSaveDataHolderFlagBytes_from_thumb();
    uVar2 = DAT_0205533c;
    *(undefined4 *)
     ((*(uint *)(DAT_0205533c & 0xfffffffc) >> (DAT_0205533c & 3) * 8 |
      *(uint *)(DAT_0205533c & 0xfffffffc) << (DAT_0205533c & 3) * -8 + 0x20) + 4) = 0;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    *(ushort *)(uVar3 + 0x454) = *(ushort *)(uVar3 + 0x454) & 0xff7f;
    return 1;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    goto LAB_020552d4;
  case 7:
    goto LAB_020552c4;
  case 8:
LAB_020552c4:
    func_02051e98();
    return 0;
  case 9:
    break;
  case 10:
    goto LAB_020552d4;
  case 0xb:
    goto LAB_020552cc;
  case 0xc:
    goto LAB_020552cc;
  case 0xd:
    goto LAB_020552cc;
  case 0xe:
    goto LAB_02055304;
  case 0xf:
    goto LAB_02055304;
  case 0x10:
    goto LAB_020552d4;
  case 0x11:
LAB_020552cc:
    func_0205146c();
    return 0;
  case 0x12:
LAB_020552d4:
    if (uVar4 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    }
    if (uVar3 != 1) {
      if (uVar3 != 2) {
        return 0;
      }
      func_02051230();
      return 0;
    }
    func_020513ac();
    return 0;
  case 0x13:
    break;
  case 0x14:
    break;
  case 0x15:
    *(undefined4 *)(uVar4 + 0xc) = 0;
    return 0;
  case 0x16:
    goto LAB_0205530c;
  case 0x17:
    goto LAB_0205530c;
  case 0x18:
    goto LAB_0205530c;
  case 0x19:
LAB_0205530c:
    StructZE_StateFn22_23_24_25_from_thumb();
    return 0;
  case 0x1a:
  default:
    func_020533a0();
    return 0;
  case 0x1b:
    break;
  case 0x1c:
    goto LAB_02055314;
  case 0x1d:
    goto LAB_02055314;
  case 0x1e:
    goto LAB_02055314;
  case 0x1f:
    break;
  case 0x20:
    break;
  case 0x21:
    goto LAB_02055314;
  case 0x22:
    goto LAB_02055314;
  case 0x23:
LAB_02055314:
    StructZE_StateFn_28_29_30_33_34_35_from_thumb();
    return 0;
  case 0x24:
    break;
  case 0x25:
LAB_02055304:
    func_020514c0();
    return 0;
  case 0x26:
    func_02050ec0();
    return 0;
  case 0x27:
    goto LAB_0205531c;
  case 0x28:
    goto LAB_0205531c;
  case 0x29:
    goto LAB_0205531c;
  case 0x2a:
    goto LAB_0205531c;
  case 0x2b:
    goto LAB_0205531c;
  case 0x2c:
    goto LAB_0205531c;
  case 0x2d:
    func_0205146c();
    return 0;
  case 0x2e:
LAB_0205531c:
    func_0204eca0();
    return 0;
  }
  func_02052cf4();
  return 0;
}

