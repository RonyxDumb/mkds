/* Decompiled C draft; module arm9; ROM address 020bb5ec. No matching claim. */
#include "types.h"
#include "deps/020bb5ec_func_020bb5ec.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020bb5ec(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  
  iVar2 = func_020b1a20();
  iVar8 = 0;
  iVar3 = func_020b1dbc();
  if (iVar3 == 6) {
    return;
  }
  uVar4 = (*(uint *)(uRam020bbba8 & 0xfffffffc) >> (uRam020bbba8 & 3) * 8 |
          *(uint *)(uRam020bbba8 & 0xfffffffc) << (uRam020bbba8 & 3) * -8 + 0x20) + 0xc;
  uVar7 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
  if (uVar4 == 4) {
    return;
  }
  if (uVar4 == 1) {
    return;
  }
  iVar3 = GetCurrentPlayerRacerId();
  uVar4 = iVar3 * 0x8c +
          (*(uint *)(uRam020bbbac & 0xfffffffc) >> (uRam020bbbac & 3) * 8 |
          *(uint *)(uRam020bbbac & 0xfffffffc) << (uRam020bbbac & 3) * -8 + 0x20) + 0x14;
  uVar7 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) != 3) {
    if (iVar2 != 0) {
      iVar5 = func_020b1a0c();
      iVar3 = iVar5 >> 0x1f;
      iVar3 = ((uint)(iVar5 * 0x10000000 + iVar3) >> 0x1c | iVar3 << 4) - iVar3;
      if (3 < iVar3) {
        if (iVar3 < 8) {
          iVar8 = 0xc;
        }
        else if (iVar3 < 0xc) {
          iVar8 = 0x18;
        }
        else {
          iVar8 = 0xc;
        }
      }
    }
    if (iVar2 == 0) {
      uVar6 = GetB3C4_Cell_RaceS(0x26);
      sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar6);
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
    }
    else {
      uVar6 = GetB3C4_Cell_RaceS(iVar8 + 0x27);
      sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar6);
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
    }
    uVar7 = *(uint *)(uRam020bbbb0 & 0xfffffffc) >> (uRam020bbbb0 & 3) * 8 |
            *(uint *)(uRam020bbbb0 & 0xfffffffc) << (uRam020bbbb0 & 3) * -8 + 0x20;
    uVar4 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar4 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
    if (uVar4 != 0) {
      uVar6 = GetB3C4_Cell_RaceS(iVar8 + 0x28 + uVar4);
      sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar6);
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
    }
    uVar4 = (*(uint *)(uRam020bbbb0 & 0xfffffffc) >> (uRam020bbbb0 & 3) * 8 |
            *(uint *)(uRam020bbbb0 & 0xfffffffc) << (uRam020bbbb0 & 3) * -8 + 0x20) + 4;
    uVar7 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar6 = GetB3C4_Cell_RaceS(iVar8 + 0x28 + (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20));
    sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar6);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
    uVar6 = GetB3C4_Cell_RaceS(iVar8 + 0x32);
    sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar6);
    uVar7 = uRam020bbbb0;
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
    uVar4 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar4 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 8;
    uVar7 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar6 = GetB3C4_Cell_RaceS(iVar8 + 0x28 + (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20));
    sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar6);
    uVar7 = uRam020bbbb0;
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
    uVar4 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar4 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 0xc;
    uVar7 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar6 = GetB3C4_Cell_RaceS(iVar8 + 0x28 + (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20));
    sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar6);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
    uVar6 = GetB3C4_Cell_RaceS(iVar8 + 0x32);
    sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar6);
    uVar7 = uRam020bbbb0;
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
    uVar4 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar4 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 0x10;
    uVar7 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar6 = GetB3C4_Cell_RaceS(iVar8 + 0x28 + (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20));
    sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar6);
    uVar7 = uRam020bbbb0;
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
    uVar4 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar4 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 0x14;
    uVar7 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar6 = GetB3C4_Cell_RaceS(iVar8 + 0x28 + (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20));
    sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar6);
    uVar7 = uRam020bbbb0;
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
    uVar4 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar4 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 0x18;
    uVar7 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar6 = GetB3C4_Cell_RaceS(iVar8 + 0x28 + (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20));
    sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar6);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
    return;
  }
  return;
}

