/* Decompiled C draft; module arm9; ROM address 02122d74. No matching claim. */
#include "types.h"
#include "deps/02122d74_func_02122d74.h"

void func_02122d74(void)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  func_021225ac(uRam02122f2c);
  uVar3 = GetSomeRacerIndex();
  if (uVar3 < *(byte *)((*(uint *)(uRam02122f30 & 0xfffffffc) >> (uRam02122f30 & 3) * 8 |
                        *(uint *)(uRam02122f30 & 0xfffffffc) << (uRam02122f30 & 3) * -8 + 0x20) +
                       0x1f53)) {
    uVar2 = func_0x0219bb50();
    iVar4 = func_0x0219bb50();
    uVar6 = uRam02122f30;
    iVar5 = (*(uint *)(uRam02122f30 & 0xfffffffc) >> (uRam02122f30 & 3) * 8 |
            *(uint *)(uRam02122f30 & 0xfffffffc) << (uRam02122f30 & 3) * -8 + 0x20) + iRam02122f34;
    *(undefined4 *)(iVar5 + iVar4 * 0x44) = 6;
    iVar5 = iVar5 + iVar4 * 0x44;
    *(undefined4 *)(iVar5 + 4) = 0x44;
    *(undefined1 *)(iVar5 + 8) = uVar2;
    *(char *)(iVar5 + 9) = (char)uVar3;
    uVar8 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(undefined1 *)(iVar5 + 10) =
         *(undefined1 *)((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 0x1f55);
    iVar4 = func_0x0219bb50();
    func_0x021a32a0(uVar3,iVar4 * 0x44 +
                          (*(uint *)(uRam02122f30 & 0xfffffffc) >> (uRam02122f30 & 3) * 8 |
                          *(uint *)(uRam02122f30 & 0xfffffffc) << (uRam02122f30 & 3) * -8 + 0x20) +
                          iRam02122f34);
  }
  iVar4 = func_02121580();
  uVar3 = uRam02122f30;
  if (iVar4 == 0) {
    return;
  }
  *(undefined1 *)
   ((*(uint *)(uRam02122f30 & 0xfffffffc) >> (uRam02122f30 & 3) * 8 |
    *(uint *)(uRam02122f30 & 0xfffffffc) << (uRam02122f30 & 3) * -8 + 0x20) + 0x19aa) = 0;
  uVar8 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(undefined1 *)((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) + 0x19ab) = 0;
  func_02122b14();
  MaybeVSSelectRandomCourseId();
  uVar3 = uRam02122f30;
  uVar8 = 0;
  if (*(char *)((*(uint *)(uRam02122f30 & 0xfffffffc) >> (uRam02122f30 & 3) * 8 |
                *(uint *)(uRam02122f30 & 0xfffffffc) << (uRam02122f30 & 3) * -8 + 0x20) + 0x1f53) !=
      '\0') {
    do {
      iVar4 = func_0x0219bb50();
      uVar7 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
      uVar6 = uVar7 + uVar8 * 0x44 + 0x1e44;
      uVar1 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      *(uint *)(iVar4 * 0x44 + uVar7 + uVar8 * 4 + 0x1e2c) =
           uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
      iVar4 = func_0x0219bb50();
      uVar7 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
      uVar6 = uVar7 + uVar8 * 0x44 + 0x1e40;
      uVar1 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      *(uint *)(iVar4 * 0x44 + uVar7 + uVar8 * 4 + 0x1e1c) =
           uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
      uVar8 = uVar8 + 1 & 0xff;
    } while (uVar8 < *(byte *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                               *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x1f53));
  }
  iVar4 = func_0x0219bb50();
  iVar5 = GetGlobalCA_from_thumb();
  uVar8 = uRam02122f30;
  uVar3 = iVar5 + 0xd0U & 3;
  uVar6 = *(uint *)(iVar5 + 0xd0U & 0xfffffffc);
  *(uint *)(iVar4 * 0x44 +
            (*(uint *)(uRam02122f30 & 0xfffffffc) >> (uRam02122f30 & 3) * 8 |
            *(uint *)(uRam02122f30 & 0xfffffffc) << (uRam02122f30 & 3) * -8 + 0x20) + 0x1e3c) =
       uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  *(undefined4 *)
   ((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
    *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0x1950) = 9;
  *(undefined4 *)
   ((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
    *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0x1980) = 0;
  return;
}

