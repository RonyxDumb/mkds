/* Decompiled C draft; module arm9; ROM address 0212320c. No matching claim. */
#include "types.h"
#include "deps/0212320c_func_0212320c.h"

void func_0212320c(void)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  func_021225ac(uRam02123378);
  iVar3 = func_0x0219bb50();
  uVar4 = iVar3 * 0x44 +
          (*(uint *)(uRam0212337c & 0xfffffffc) >> (uRam0212337c & 3) * 8 |
          *(uint *)(uRam0212337c & 0xfffffffc) << (uRam0212337c & 3) * -8 + 0x20) + 0x1e50;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) == 2) {
    func_0x021a2ccc();
    func_0x0219bbfc();
    *(undefined4 *)
     ((*(uint *)(uRam0212337c & 0xfffffffc) >> (uRam0212337c & 3) * 8 |
      *(uint *)(uRam0212337c & 0xfffffffc) << (uRam0212337c & 3) * -8 + 0x20) + 0x1950) = 0xb;
    return;
  }
  uVar4 = GetSomeRacerIndex();
  if (uVar4 < *(byte *)((*(uint *)(uRam0212337c & 0xfffffffc) >> (uRam0212337c & 3) * 8 |
                        *(uint *)(uRam0212337c & 0xfffffffc) << (uRam0212337c & 3) * -8 + 0x20) +
                       0x1f53)) {
    uVar2 = func_0x0219bb50();
    iVar3 = func_0x0219bb50();
    uVar6 = uRam0212337c;
    iVar5 = (*(uint *)(uRam0212337c & 0xfffffffc) >> (uRam0212337c & 3) * 8 |
            *(uint *)(uRam0212337c & 0xfffffffc) << (uRam0212337c & 3) * -8 + 0x20) + iRam02123380;
    *(undefined4 *)(iVar5 + iVar3 * 0x44) = 8;
    iVar5 = iVar5 + iVar3 * 0x44;
    *(undefined4 *)(iVar5 + 4) = 0x44;
    *(undefined1 *)(iVar5 + 8) = uVar2;
    *(char *)(iVar5 + 9) = (char)uVar4;
    uVar1 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(undefined1 *)(iVar5 + 10) =
         *(undefined1 *)((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 0x1f55);
    iVar3 = func_0x0219bb50();
    func_0x021a32a0(uVar4,iVar3 * 0x44 +
                          (*(uint *)(uRam0212337c & 0xfffffffc) >> (uRam0212337c & 3) * 8 |
                          *(uint *)(uRam0212337c & 0xfffffffc) << (uRam0212337c & 3) * -8 + 0x20) +
                          iRam02123380);
  }
  iVar3 = func_02121580();
  if (iVar3 != 0) {
    iVar3 = func_0x0219bb50();
    uVar6 = uRam0212337c;
    uVar7 = *(uint *)(uRam0212337c & 0xfffffffc) >> (uRam0212337c & 3) * 8 |
            *(uint *)(uRam0212337c & 0xfffffffc) << (uRam0212337c & 3) * -8 + 0x20;
    uVar4 = iVar3 * 0x44 + uVar7 + 0x1e50;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    if (uVar4 >> uVar1 * 8 != 0 || uVar4 << uVar1 * -8 + 0x20 != 0) {
      *(undefined1 *)(uVar7 + 0x19aa) = 0;
      *(undefined1 *)
       ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x19ab) = 0;
      *(undefined4 *)
       ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x1950) = 4;
      *(undefined4 *)
       ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x1980) = 0;
      return;
    }
    return;
  }
  return;
}

