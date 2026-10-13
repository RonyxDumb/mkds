/* Decompiled C draft; module arm9; ROM address 02123384. No matching claim. */
#include "types.h"
#include "deps/02123384_func_02123384.h"

void func_02123384(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  
  func_021225ac(uRam02123564);
  uVar4 = GetSomeRacerIndex();
  uVar5 = *(uint *)(uRam02123568 & 0xfffffffc) >> (uRam02123568 & 3) * 8 |
          *(uint *)(uRam02123568 & 0xfffffffc) << (uRam02123568 & 3) * -8 + 0x20;
  if (uVar4 < *(byte *)(uVar5 + 0x1f53)) {
    uVar8 = 1 << (uVar4 & 0xff);
    if ((*(byte *)(uVar5 + 0x19aa) & uVar8) == 0) {
      local_18 = func_0x0219bb50();
      local_1c = 0xc;
      local_20 = 2;
      local_16 = *(undefined1 *)
                  ((*(uint *)(uRam02123568 & 0xfffffffc) >> (uRam02123568 & 3) * 8 |
                   *(uint *)(uRam02123568 & 0xfffffffc) << (uRam02123568 & 3) * -8 + 0x20) + 0x1f55)
      ;
      local_17 = (char)uVar4;
      func_0x021a32a0(uVar4,&local_20);
    }
    else {
      uVar3 = func_0x0219bb50();
      iVar6 = func_0x0219bb50();
      uVar7 = uRam02123568;
      iVar9 = (*(uint *)(uRam02123568 & 0xfffffffc) >> (uRam02123568 & 3) * 8 |
              *(uint *)(uRam02123568 & 0xfffffffc) << (uRam02123568 & 3) * -8 + 0x20) + 0x21c;
      *(undefined4 *)(iVar9 + iVar6 * 0x244) = 1;
      iVar9 = iVar9 + iVar6 * 0x244;
      *(undefined4 *)(iVar9 + 4) = 0x244;
      *(undefined1 *)(iVar9 + 8) = uVar3;
      *(char *)(iVar9 + 9) = (char)uVar4;
      uVar5 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      *(undefined1 *)(iVar9 + 10) =
           *(undefined1 *)((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) + 0x1f55);
      iVar6 = func_0x0219bb50();
      func_0x021a32a0(uVar4,iVar6 * 0x244 +
                            (*(uint *)(uRam02123568 & 0xfffffffc) >> (uRam02123568 & 3) * 8 |
                            *(uint *)(uRam02123568 & 0xfffffffc) << (uRam02123568 & 3) * -8 + 0x20)
                            + 0x21c);
      uVar4 = *(uint *)(uRam02123568 & 0xfffffffc) >> (uRam02123568 & 3) * 8 |
              *(uint *)(uRam02123568 & 0xfffffffc) << (uRam02123568 & 3) * -8 + 0x20;
      *(byte *)(uVar4 + 0x19aa) = *(byte *)(uVar4 + 0x19aa) & ~(byte)uVar8;
    }
  }
  iVar9 = func_02121580();
  iVar6 = iRam0212356c;
  if (iVar9 == 0) {
    return;
  }
  iVar9 = 0;
  uVar5 = *(uint *)(uRam02123568 & 0xfffffffc) >> (uRam02123568 & 3) * 8 |
          *(uint *)(uRam02123568 & 0xfffffffc) << (uRam02123568 & 3) * -8 + 0x20;
  uVar4 = 0;
  if (*(byte *)(uVar5 + 0x1f53) != 0) {
    do {
      uVar8 = uVar4 * 0x244 + uVar5 + 0x45c;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar4 = uVar4 + 1 & 0xff;
      iVar9 = iVar9 + (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20);
    } while (uVar4 < *(byte *)(uVar5 + 0x1f53));
  }
  *(int *)(uVar5 + 0x1954) = iVar9;
  uVar1 = uRam02123570;
  iVar6 = uVar5 + iVar6;
  *(undefined4 *)(iVar6 + 4) = 0;
  uVar2 = uRam02123574;
  *(undefined4 *)(iVar6 + 8) = uVar1;
  uVar1 = uRam02123578;
  *(undefined4 *)(iVar6 + 0xc) = uVar2;
  *(undefined4 *)(iVar6 + 0x10) = uVar1;
  *(undefined4 *)(iVar6 + 0x14) = 0;
  func_0205e5c4();
  uVar4 = uRam02123568;
  *(undefined1 *)
   ((*(uint *)(uRam02123568 & 0xfffffffc) >> (uRam02123568 & 3) * 8 |
    *(uint *)(uRam02123568 & 0xfffffffc) << (uRam02123568 & 3) * -8 + 0x20) + 0x19aa) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x19ab) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x1980) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x1950) = 2;
  return;
}

