/* Decompiled C draft; module arm9; ROM address 02122bf0. No matching claim. */
#include "types.h"
#include "deps/02122bf0_func_02122bf0.h"

void func_02122bf0(void)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = GetSomeRacerIndex();
  if (uVar2 < *(byte *)((*(uint *)(uRam02122d6c & 0xfffffffc) >> (uRam02122d6c & 3) * 8 |
                        *(uint *)(uRam02122d6c & 0xfffffffc) << (uRam02122d6c & 3) * -8 + 0x20) +
                       0x1f53)) {
    uVar1 = func_0x0219bb50();
    iVar3 = func_0x0219bb50();
    uVar5 = uRam02122d6c;
    iVar4 = (*(uint *)(uRam02122d6c & 0xfffffffc) >> (uRam02122d6c & 3) * 8 |
            *(uint *)(uRam02122d6c & 0xfffffffc) << (uRam02122d6c & 3) * -8 + 0x20) + iRam02122d70;
    *(undefined4 *)(iVar4 + iVar3 * 0x44) = 7;
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
                          (*(uint *)(uRam02122d6c & 0xfffffffc) >> (uRam02122d6c & 3) * 8 |
                          *(uint *)(uRam02122d6c & 0xfffffffc) << (uRam02122d6c & 3) * -8 + 0x20) +
                          iRam02122d70);
  }
  iVar3 = func_021225ac(0x78);
  uVar2 = uRam02122d6c;
  if (iVar3 == 0) {
    return;
  }
  uVar5 = 0;
  uVar6 = *(uint *)(uRam02122d6c & 0xfffffffc) >> (uRam02122d6c & 3) * 8 |
          *(uint *)(uRam02122d6c & 0xfffffffc) << (uRam02122d6c & 3) * -8 + 0x20;
  if (*(char *)(uVar6 + 0x1f53) != '\0') {
    do {
      uVar6 = func_0x0219bb50();
      if (((uVar5 != uVar6) &&
          (uVar6 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20,
          ((uint)*(byte *)(uVar6 + 0x1f55) & 1 << uVar5) != 0)) &&
         (iVar3 = func_0x021a3264(uVar5,uVar6 + 0x1c + uVar5 * 0x80,0x80), iVar3 == 0)) {
        return;
      }
      uVar6 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
      uVar5 = uVar5 + 1 & 0xff;
    } while (uVar5 < *(byte *)(uVar6 + 0x1f53));
  }
  uVar2 = uRam02122d6c;
  *(undefined1 *)(uVar6 + 0x19aa) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x19ab) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x1950) = 10;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x1980) = 0;
  return;
}

