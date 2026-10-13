/* Decompiled C draft; module arm9; ROM address 020bdf08. No matching claim. */
#include "types.h"
#include "deps/020bdf08_func_020bdf08.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020bdf08(int param_1)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  short sVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iStack_88;
  
  uVar3 = uRam020be158;
  uVar8 = 0;
  if (*(char *)((*(uint *)(uRam020be158 & 0xfffffffc) >> (uRam020be158 & 3) * 8 |
                *(uint *)(uRam020be158 & 0xfffffffc) << (uRam020be158 & 3) * -8 + 0x20) + 0x3d0) ==
      '\0') {
    return;
  }
  iStack_88 = 3;
  do {
    uVar5 = (*(uint *)(uRam020be154 & 0xfffffffc) >> (uRam020be154 & 3) * 8 |
            *(uint *)(uRam020be154 & 0xfffffffc) << (uRam020be154 & 3) * -8 + 0x20) + uVar8 * 4 +
            0x60;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar6 = GetB3C4_Cell_RaceS((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 0x34);
    sVar4 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar6);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar4;
    uVar5 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 8;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if (((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) == 2) &&
       (iVar7 = func_020a1084(uVar8), iVar7 != 0)) {
      bVar2 = true;
    }
    else {
      uVar5 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 8;
      uVar1 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      bVar2 = false;
      if (((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) != 2) &&
         ((iVar7 = func_020b1cf4(uVar8), iVar7 != 0 ||
          (iVar7 = IsDriverKilledOrBeingKilled(uVar8), bVar2 = false, iVar7 != 0)))) {
        bVar2 = true;
      }
    }
    iVar7 = iStack_88;
    if (!bVar2) {
      uVar5 = GetCurrentPlayerRacerId();
      if (uVar8 == uVar5) {
        iVar7 = 0;
      }
      else {
        uVar5 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
        if ((*(char *)(uVar5 + 0x58) == '\0') ||
           (uVar5 = uVar8 * 0x30 + uVar5 + 0x74, uVar1 = uVar5 & 3,
           uVar5 = *(uint *)(uVar5 & 0xfffffffc),
           (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) != 1)) {
          iVar7 = 1;
        }
        else {
          iVar7 = 2;
        }
      }
    }
    uVar6 = GetB3C4_Cell_RaceS(iVar7 + 0x75);
    sVar4 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar6);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar4;
    uVar8 = uVar8 + 1 & 0xffff;
  } while (uVar8 < *(byte *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                             *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x3d0));
  return;
}

