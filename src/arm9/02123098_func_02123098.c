/* Decompiled C draft; module arm9; ROM address 02123098. No matching claim. */
#include "types.h"
#include "deps/02123098_func_02123098.h"

void func_02123098(void)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  func_021225ac(uRam02123200);
  uVar2 = GetSomeRacerIndex();
  if (uVar2 < *(byte *)((*(uint *)(uRam02123204 & 0xfffffffc) >> (uRam02123204 & 3) * 8 |
                        *(uint *)(uRam02123204 & 0xfffffffc) << (uRam02123204 & 3) * -8 + 0x20) +
                       0x1f53)) {
    uVar1 = func_0x0219bb50();
    iVar3 = func_0x0219bb50();
    uVar5 = uRam02123204;
    iVar4 = (*(uint *)(uRam02123204 & 0xfffffffc) >> (uRam02123204 & 3) * 8 |
            *(uint *)(uRam02123204 & 0xfffffffc) << (uRam02123204 & 3) * -8 + 0x20) + iRam02123208;
    *(undefined4 *)(iVar4 + iVar3 * 0x44) = 9;
    iVar4 = iVar4 + iVar3 * 0x44;
    *(undefined4 *)(iVar4 + 4) = 0x44;
    *(undefined1 *)(iVar4 + 8) = uVar1;
    *(char *)(iVar4 + 9) = (char)uVar2;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(undefined1 *)(iVar4 + 10) =
         *(undefined1 *)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x1f55);
    iVar3 = func_0x0219bb50();
    func_0x021a32a0(uVar2,iVar3 * 0x44 +
                          (*(uint *)(uRam02123204 & 0xfffffffc) >> (uRam02123204 & 3) * 8 |
                          *(uint *)(uRam02123204 & 0xfffffffc) << (uRam02123204 & 3) * -8 + 0x20) +
                          iRam02123208);
  }
  iVar3 = func_02121580();
  uVar2 = uRam02123204;
  if (iVar3 != 0) {
    uVar6 = *(uint *)(uRam02123204 & 0xfffffffc) >> (uRam02123204 & 3) * 8 |
            *(uint *)(uRam02123204 & 0xfffffffc) << (uRam02123204 & 3) * -8 + 0x20;
    if (*(char *)(uVar6 + 0x1f52) != '\x01') {
      *(undefined1 *)(uVar6 + 0x19aa) = 0;
      *(undefined1 *)
       ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
        *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x19ab) = 0;
      *(undefined4 *)
       ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
        *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x1950) = 5;
      *(undefined4 *)
       ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
        *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x1980) = 0;
      iVar3 = func_0x0219bb50();
      SetGlobalCA81_from_thumb
                (*(undefined1 *)
                  ((*(uint *)(uRam02123204 & 0xfffffffc) >> (uRam02123204 & 3) * 8 |
                   *(uint *)(uRam02123204 & 0xfffffffc) << (uRam02123204 & 3) * -8 + 0x20) + iVar3 +
                  0x1f4e));
      SetGlobalCA82_from_thumb
                (*(undefined1 *)
                  ((*(uint *)(uRam02123204 & 0xfffffffc) >> (uRam02123204 & 3) * 8 |
                   *(uint *)(uRam02123204 & 0xfffffffc) << (uRam02123204 & 3) * -8 + 0x20) + 0x1f52)
                );
      return;
    }
    func_0x021a2ccc();
    func_0x0219bbfc();
    uVar2 = *(uint *)(uRam02123204 & 0xfffffffc) >> (uRam02123204 & 3) * 8 |
            *(uint *)(uRam02123204 & 0xfffffffc) << (uRam02123204 & 3) * -8 + 0x20;
    *(undefined2 *)(uVar2 + 0x18) = 2;
    *(undefined2 *)(uVar2 + 0x1a) = 1;
    return;
  }
  return;
}

