/* Decompiled C draft; module arm9; ROM address 0211f91c. No matching claim. */
#include "types.h"
#include "deps/0211f91c_func_0211f91c.h"

undefined4 func_0211f91c(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(DAT_0211fa50 & 0xfffffffc) >> (DAT_0211fa50 & 3) * 8 |
          *(uint *)(DAT_0211fa50 & 0xfffffffc) << (DAT_0211fa50 & 3) * -8 + 0x20;
  uVar2 = uVar5 + 0x1f2c;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  switch(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    func_0211fa70();
    break;
  case 2:
    break;
  case 3:
    if (*(char *)((*(uint *)(DAT_0211fa54 & 0xfffffffc) >> (DAT_0211fa54 & 3) * 8 |
                  *(uint *)(DAT_0211fa54 & 0xfffffffc) << (DAT_0211fa54 & 3) * -8 + 0x20) + 0x28) ==
        '\0') {
      uVar4 = *(uint *)(DAT_0211fa58 & 0xfffffffc) >> (DAT_0211fa58 & 3) * 8 |
              *(uint *)(DAT_0211fa58 & 0xfffffffc) << (DAT_0211fa58 & 3) * -8 + 0x20;
      uVar2 = uVar4 + 0xc;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
        uVar2 = 0;
      }
      else {
        uVar4 = uVar4 + 0x10;
        uVar2 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
      }
    }
    else {
      uVar2 = 1;
    }
    if (uVar2 == 0) {
      PlayerProfileInfo_SomeFn_2_from_thumb(uVar5 + DAT_0211fa5c);
      iVar3 = func_0x0219bdec(0,DAT_0211fa64,0,DAT_0211fa68,0,DAT_0211fa60,0);
      if (iVar3 == 0) {
        *(undefined4 *)
         ((*(uint *)(DAT_0211fa50 & 0xfffffffc) >> (DAT_0211fa50 & 3) * 8 |
          *(uint *)(DAT_0211fa50 & 0xfffffffc) << (DAT_0211fa50 & 3) * -8 + 0x20) + 0x1f2c) = 7;
      }
      func_0x0219d934(DAT_0211fa6c,0);
      *(undefined4 *)
       ((*(uint *)(DAT_0211fa50 & 0xfffffffc) >> (DAT_0211fa50 & 3) * 8 |
        *(uint *)(DAT_0211fa50 & 0xfffffffc) << (DAT_0211fa50 & 3) * -8 + 0x20) + 0x1f2c) = 4;
    }
    break;
  case 4:
    break;
  case 5:
    return 1;
  case 6:
    func_0x0219c0f4();
    func_0x021a37dc();
    *(undefined4 *)
     ((*(uint *)(DAT_0211fa50 & 0xfffffffc) >> (DAT_0211fa50 & 3) * 8 |
      *(uint *)(DAT_0211fa50 & 0xfffffffc) << (DAT_0211fa50 & 3) * -8 + 0x20) + 0x1f2c) = 7;
    break;
  case 7:
  }
  return 0;
}

