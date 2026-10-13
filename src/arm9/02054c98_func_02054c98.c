/* Decompiled C draft; module arm9; ROM address 02054c98. No matching claim. */
#include "types.h"
#include "deps/02054c98_func_02054c98.h"

undefined4 func_02054c98(int param_1,undefined4 param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar4 = DAT_02054f2c;
  uVar5 = *(uint *)(DAT_02054f2c & 0xfffffffc) >> (DAT_02054f2c & 3) * 8 |
          *(uint *)(DAT_02054f2c & 0xfffffffc) << (DAT_02054f2c & 3) * -8 + 0x20;
  uVar7 = uVar5 + 0x1e3c & 3;
  uVar6 = *(uint *)(uVar5 + 0x1e3c & 0xfffffffc);
  if (uVar6 >> uVar7 * 8 != 0 || uVar6 << uVar7 * -8 + 0x20 != 0) {
    if ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
        *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) == 2) {
      uVar7 = (uint)*(ushort *)(uVar5 + 0x432);
    }
    else {
      uVar7 = 0;
    }
    if (uVar7 == DAT_02054f30) {
      return 2;
    }
  }
  bVar3 = false;
  if (uVar5 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
  }
  bVar2 = false;
  bVar1 = false;
  if ((uVar7 != 0) &&
     (uVar7 = uVar5 + 4 & 3, uVar6 = *(uint *)(uVar5 + 4 & 0xfffffffc),
     (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) != 0xd)) {
    bVar1 = true;
  }
  if ((bVar1) && ((*(ushort *)(uVar5 + 0x454) & 0x80) == 0)) {
    bVar2 = true;
  }
  if ((bVar2) &&
     (uVar7 = uVar5 + 8 & 3, uVar6 = *(uint *)(uVar5 + 8 & 0xfffffffc),
     (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) != 9)) {
    bVar3 = true;
  }
  if (bVar3) {
    return 3;
  }
  uVar7 = uVar5 + 0x10 & 3;
  uVar6 = *(uint *)(uVar5 + 0x10 & 0xfffffffc);
  if (uVar6 >> uVar7 * 8 != 0 || uVar6 << uVar7 * -8 + 0x20 != 0) {
    return 0;
  }
  uVar7 = uVar5 + 0xc & 3;
  uVar6 = *(uint *)(uVar5 + 0xc & 0xfffffffc);
  switch(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) {
  case 0:
    goto LAB_02054de0;
  case 1:
    *(undefined4 *)(uVar5 + 4) = 0xb;
    if (param_1 != 0) {
      func_020532dc(0x28);
      return 0;
    }
    func_020527c0(0,0,0);
    return 0;
  case 2:
    if (param_1 != 0) {
      func_020532dc(0x28);
      return 0;
    }
    func_020527c0(0,0,0);
    return 0;
  case 3:
    func_02053094(0);
    return 0;
  case 4:
    func_0204f814();
    func_0204f938(param_2);
    func_02052bf8();
    return 0;
  case 5:
    func_02052b60(0);
    return 0;
  case 6:
    func_0204ef1c();
    return 0;
  case 7:
    if (*(char *)(uVar5 + 0x1e45) == -1) {
      func_020527c0(0,0,0);
      return 0;
    }
    func_02051e98();
    return 0;
  case 8:
    break;
  case 9:
    func_02051d24(0,0,0,0);
    return 0;
  case 10:
    *(undefined4 *)(uVar5 + 0x1e3c) = 1;
    func_0204ef1c();
    return 0;
  case 0xb:
    if (param_1 == 0) {
      func_0204f408();
      func_0204ef88();
    }
    else {
      func_0204f468();
    }
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
LAB_02054de0:
    *(ushort *)(uVar5 + 0x454) = *(ushort *)(uVar5 + 0x454) & 0xffbf;
    uVar7 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(undefined4 *)((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 4) = 1;
    func_020536e0();
    return 0;
  }
  func_020533a0();
  return 0;
}

