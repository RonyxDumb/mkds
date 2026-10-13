/* Decompiled C draft; module arm9; ROM address 0212357c. No matching claim. */
#include "types.h"
#include "deps/0212357c_func_0212357c.h"

void func_0212357c(void)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  
  func_021225ac(uRam021236f0);
  uVar3 = GetSomeRacerIndex();
  uVar4 = *(uint *)(uRam021236f4 & 0xfffffffc) >> (uRam021236f4 & 3) * 8 |
          *(uint *)(uRam021236f4 & 0xfffffffc) << (uRam021236f4 & 3) * -8 + 0x20;
  if (uVar3 < *(byte *)(uVar4 + 0x1f53)) {
    uVar1 = 1 << (uVar3 & 0xff);
    if ((*(byte *)(uVar4 + 0x19aa) & uVar1) == 0) {
      if ((*(byte *)(uVar4 + 0x19ab) & uVar1) == 0) {
        local_18 = func_0x0219bb50();
        local_1c = 0xc;
        local_20 = 0;
        local_16 = *(undefined1 *)
                    ((*(uint *)(uRam021236f4 & 0xfffffffc) >> (uRam021236f4 & 3) * 8 |
                     *(uint *)(uRam021236f4 & 0xfffffffc) << (uRam021236f4 & 3) * -8 + 0x20) +
                    0x1f55);
        local_17 = (char)uVar3;
        func_0x021a32a0(uVar3,&local_20);
      }
    }
    else {
      uVar2 = func_0x0219bb50();
      iVar5 = func_0x0219bb50();
      uVar6 = uRam021236f4;
      iVar7 = (*(uint *)(uRam021236f4 & 0xfffffffc) >> (uRam021236f4 & 3) * 8 |
              *(uint *)(uRam021236f4 & 0xfffffffc) << (uRam021236f4 & 3) * -8 + 0x20) + 0x21c;
      *(undefined4 *)(iVar7 + iVar5 * 0x244) = 1;
      iVar7 = iVar7 + iVar5 * 0x244;
      *(undefined4 *)(iVar7 + 4) = 0x244;
      *(undefined1 *)(iVar7 + 8) = uVar2;
      *(char *)(iVar7 + 9) = (char)uVar3;
      uVar4 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      *(undefined1 *)(iVar7 + 10) =
           *(undefined1 *)((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + 0x1f55);
      iVar5 = func_0x0219bb50();
      func_0x021a32a0(uVar3,iVar5 * 0x244 +
                            (*(uint *)(uRam021236f4 & 0xfffffffc) >> (uRam021236f4 & 3) * 8 |
                            *(uint *)(uRam021236f4 & 0xfffffffc) << (uRam021236f4 & 3) * -8 + 0x20)
                            + 0x21c);
      uVar3 = *(uint *)(uRam021236f4 & 0xfffffffc) >> (uRam021236f4 & 3) * 8 |
              *(uint *)(uRam021236f4 & 0xfffffffc) << (uRam021236f4 & 3) * -8 + 0x20;
      *(byte *)(uVar3 + 0x19aa) = *(byte *)(uVar3 + 0x19aa) & ~(byte)uVar1;
    }
  }
  iVar5 = func_02121580();
  uVar3 = uRam021236f4;
  if (iVar5 != 0) {
    *(undefined1 *)
     ((*(uint *)(uRam021236f4 & 0xfffffffc) >> (uRam021236f4 & 3) * 8 |
      *(uint *)(uRam021236f4 & 0xfffffffc) << (uRam021236f4 & 3) * -8 + 0x20) + 0x19aa) = 0;
    *(undefined1 *)
     ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x19ab) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x1980) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x1950) = 1;
    return;
  }
  return;
}

