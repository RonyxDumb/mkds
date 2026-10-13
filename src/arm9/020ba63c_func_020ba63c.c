/* Decompiled C draft; module arm9; ROM address 020ba63c. No matching claim. */
#include "types.h"
#include "deps/020ba63c_func_020ba63c.h"

void func_020ba63c(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  
  uVar8 = (*(uint *)(uRam020bab50 & 0xfffffffc) >> (uRam020bab50 & 3) * 8 |
          *(uint *)(uRam020bab50 & 0xfffffffc) << (uRam020bab50 & 3) * -8 + 0x20) + 8;
  uVar4 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar8 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
  if (*(char *)((*(uint *)(uRam020bab4c & 0xfffffffc) >> (uRam020bab4c & 3) * 8 |
                *(uint *)(uRam020bab4c & 0xfffffffc) << (uRam020bab4c & 3) * -8 + 0x20) + 0x58) ==
      '\0') {
    uVar2 = 8;
  }
  else {
    iVar3 = GetCurrentPlayerRacerId(param_1);
    uVar4 = iVar3 * 0x30 +
            (*(uint *)(uRam020bab4c & 0xfffffffc) >> (uRam020bab4c & 3) * 8 |
            *(uint *)(uRam020bab4c & 0xfffffffc) << (uRam020bab4c & 3) * -8 + 0x20) + 0x74;
    uVar11 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    if (uVar4 >> uVar11 * 8 == 0 && uVar4 << uVar11 * -8 + 0x20 == 0) {
      uVar2 = 9;
    }
    else {
      uVar2 = 10;
    }
  }
  uVar2 = GetB3C4_Cell_RaceM(uVar2);
  uVar4 = (*(uint *)(uRam020bab4c & 0xfffffffc) >> (uRam020bab4c & 3) * 8 |
          *(uint *)(uRam020bab4c & 0xfffffffc) << (uRam020bab4c & 3) * -8 + 0x20) + 0xc;
  uVar11 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar11 * 8 | uVar4 << uVar11 * -8 + 0x20;
  if (uVar4 != 4) {
    if (uVar4 != 1) {
      uVar5 = GetB3C4_Cell_RaceM(0xc);
      sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar5);
      puVar7 = (ushort *)(param_1 + 0x400);
      *puVar7 = *puVar7 + sVar1;
      uVar11 = (uint)*puVar7;
      puVar10 = (uint *)(param_1 + uVar11 * 8);
      sVar1 = MaybeMakeOamSlot(puVar10,0x80 - uVar11 & 0xffff,uVar2);
      puVar7 = (ushort *)(param_1 + 0x400);
      *puVar7 = *puVar7 + sVar1;
      uVar4 = (uint)*puVar7;
      if (uVar11 < uVar4) {
        do {
          uVar11 = uVar11 + 1;
          *puVar10 = (*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
                     *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20) &
                     0xfffff3ff | 0x800;
          uVar4 = (uint)(puVar10 + 1) & 3;
          uVar6 = *(uint *)((uint)(puVar10 + 1) & 0xfffffffc);
          puVar10[1] = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & 0xfffff3ff | 0x400;
          uVar4 = (uint)*puVar7;
          puVar10 = puVar10 + 2;
        } while ((int)uVar11 < (int)uVar4);
      }
      iVar3 = param_1 + uVar4 * 8;
      sVar1 = MaybeMakeOamSlot(iVar3,0x80 - uVar4 & 0xffff,uVar2);
      puVar7 = (ushort *)(param_1 + 0x400);
      *puVar7 = *puVar7 + sVar1;
      if (uVar4 < *puVar7) {
        do {
          uVar11 = iVar3 + 4U & 3;
          uVar6 = *(uint *)(iVar3 + 4U & 0xfffffffc);
          uVar4 = uVar4 + 1;
          *(uint *)(iVar3 + 4) =
               (uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20) & 0xfffff3ff | 0x400;
          iVar3 = iVar3 + 8;
        } while ((int)uVar4 < (int)(uint)*puVar7);
      }
      uVar4 = (*(uint *)(uRam020bab50 & 0xfffffffc) >> (uRam020bab50 & 3) * 8 |
              *(uint *)(uRam020bab50 & 0xfffffffc) << (uRam020bab50 & 3) * -8 + 0x20) + 0x18;
      uVar11 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      if (uVar4 >> uVar11 * 8 == 0 && uVar4 << uVar11 * -8 + 0x20 == 0) {
        func_020b846c(uVar8);
        uVar2 = GetB3C4_Cell_RaceM();
        sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar2);
        uVar4 = uRam020bab50;
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
        uVar8 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        uVar8 = (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) + 0xc;
        uVar4 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        func_020b846c(uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20);
        uVar2 = GetB3C4_Cell_RaceM();
        sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                                 0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar2);
        *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
      }
      else {
        iVar3 = func_020ae5c4(param_1);
        uVar4 = (*(uint *)(uRam020bab50 & 0xfffffffc) >> (uRam020bab50 & 3) * 8 |
                *(uint *)(uRam020bab50 & 0xfffffffc) << (uRam020bab50 & 3) * -8 + 0x20) + 0x1c;
        uVar11 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        iStack_34 = FX_Div(0x1000,uVar4 >> uVar11 * 8 | uVar4 << uVar11 * -8 + 0x20);
        iStack_30 = 0;
        iStack_2c = 0;
        uVar4 = (*(uint *)(uRam020bab50 & 0xfffffffc) >> (uRam020bab50 & 3) * 8 |
                *(uint *)(uRam020bab50 & 0xfffffffc) << (uRam020bab50 & 3) * -8 + 0x20) + 0x20;
        uVar11 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        iStack_28 = FX_Div(0x1000,uVar4 >> uVar11 * 8 | uVar4 << uVar11 * -8 + 0x20);
        func_020b846c(uVar8);
        uVar2 = GetB3C4_Cell_RaceM();
        uVar8 = (uint)*(ushort *)(param_1 + 0x400);
        iVar9 = param_1 + uVar8 * 8;
        sVar1 = MaybeMakeOamSlot(iVar9,0x80 - uVar8 & 0xffff,uVar2,&iStack_34);
        puVar7 = (ushort *)(param_1 + 0x400);
        *puVar7 = *puVar7 + sVar1;
        if (uVar8 < *puVar7) {
          do {
            uVar4 = iVar9 + 4U & 3;
            uVar11 = *(uint *)(iVar9 + 4U & 0xfffffffc);
            uVar8 = uVar8 + 1;
            *(uint *)(iVar9 + 4) =
                 (uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) & 0xfffff3ff | 0x400;
            iVar9 = iVar9 + 8;
          } while ((int)uVar8 < (int)(uint)*puVar7);
        }
        uVar8 = (*(uint *)(uRam020bab50 & 0xfffffffc) >> (uRam020bab50 & 3) * 8 |
                *(uint *)(uRam020bab50 & 0xfffffffc) << (uRam020bab50 & 3) * -8 + 0x20) + 0xc;
        uVar4 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        func_020b846c(uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20);
        uVar2 = GetB3C4_Cell_RaceM();
        uVar8 = (uint)*(ushort *)(param_1 + 0x400);
        iVar9 = param_1 + uVar8 * 8;
        sVar1 = MaybeMakeOamSlot(iVar9,0x80 - uVar8 & 0xffff,uVar2,&iStack_34);
        puVar7 = (ushort *)(param_1 + 0x400);
        *puVar7 = *puVar7 + sVar1;
        if (uVar8 < *puVar7) {
          do {
            uVar4 = iVar9 + 4U & 3;
            uVar11 = *(uint *)(iVar9 + 4U & 0xfffffffc);
            uVar8 = uVar8 + 1;
            *(uint *)(iVar9 + 4) =
                 (uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) & 0xfffff3ff | 0x400;
            iVar9 = iVar9 + 8;
          } while ((int)uVar8 < (int)(uint)*puVar7);
        }
        iVar3 = param_1 + iVar3 * 0x20;
        *(short *)(iVar3 + 6) = (short)(iStack_34 >> 4);
        *(short *)(iVar3 + 0xe) = (short)(iStack_30 >> 4);
        *(short *)(iVar3 + 0x16) = (short)(iStack_2c >> 4);
        *(short *)(iVar3 + 0x1e) = (short)(iStack_28 >> 4);
      }
      uVar2 = GetB3C4_Cell_RaceM(0xb);
      sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                               0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar2);
      *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
      return;
    }
    return;
  }
  return;
}

