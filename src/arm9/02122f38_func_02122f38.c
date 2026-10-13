/* Decompiled C draft; module arm9; ROM address 02122f38. No matching claim. */
#include "types.h"
#include "deps/02122f38_func_02122f38.h"

void func_02122f38(void)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  func_021225ac(uRam0212308c);
  uVar3 = GetSomeRacerIndex();
  if (uVar3 < *(byte *)((*(uint *)(uRam02123090 & 0xfffffffc) >> (uRam02123090 & 3) * 8 |
                        *(uint *)(uRam02123090 & 0xfffffffc) << (uRam02123090 & 3) * -8 + 0x20) +
                       0x1f53)) {
    uVar2 = func_0x0219bb50();
    iVar4 = func_0x0219bb50();
    uVar6 = uRam02123090;
    iVar5 = (*(uint *)(uRam02123090 & 0xfffffffc) >> (uRam02123090 & 3) * 8 |
            *(uint *)(uRam02123090 & 0xfffffffc) << (uRam02123090 & 3) * -8 + 0x20) + iRam02123094;
    *(undefined4 *)(iVar5 + iVar4 * 0x44) = 3;
    iVar5 = iVar5 + iVar4 * 0x44;
    *(undefined4 *)(iVar5 + 4) = 0x44;
    *(undefined1 *)(iVar5 + 8) = uVar2;
    *(char *)(iVar5 + 9) = (char)uVar3;
    uVar1 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(undefined1 *)(iVar5 + 10) =
         *(undefined1 *)((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 0x1f55);
    iVar4 = func_0x0219bb50();
    func_0x021a32a0(uVar3,iVar4 * 0x44 +
                          (*(uint *)(uRam02123090 & 0xfffffffc) >> (uRam02123090 & 3) * 8 |
                          *(uint *)(uRam02123090 & 0xfffffffc) << (uRam02123090 & 3) * -8 + 0x20) +
                          iRam02123094);
  }
  iVar4 = func_02121580();
  if (iVar4 == 0) {
    return;
  }
  iVar4 = func_0x0219bb50();
  uVar3 = iVar4 * 0x44 +
          (*(uint *)(uRam02123090 & 0xfffffffc) >> (uRam02123090 & 3) * 8 |
          *(uint *)(uRam02123090 & 0xfffffffc) << (uRam02123090 & 3) * -8 + 0x20) + 0x1e40;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 0xffffffff) {
    return;
  }
  iVar4 = func_0x0219bb50();
  uVar6 = uRam02123090;
  uVar7 = *(uint *)(uRam02123090 & 0xfffffffc) >> (uRam02123090 & 3) * 8 |
          *(uint *)(uRam02123090 & 0xfffffffc) << (uRam02123090 & 3) * -8 + 0x20;
  uVar3 = iVar4 * 0x44 + uVar7 + 0x1e44;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) != 0xffffffff) {
    *(undefined1 *)(uVar7 + 0x19aa) = 0;
    *(undefined1 *)
     ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
      *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x19ab) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
      *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x1950) = 6;
    *(undefined4 *)
     ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
      *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x1980) = 0;
    return;
  }
  return;
}

