/* Decompiled C draft; module arm9; ROM address 020c4f08. No matching claim. */
#include "types.h"
#include "deps/020c4f08_func_020c4f08.h"

void func_020c4f08(int param_1)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = 0;
  iVar7 = 0;
  if (*(uint *)(uRam020c5250 & 0xfffffffc) >> (uRam020c5250 & 3) * 8 == 0 &&
      *(uint *)(uRam020c5250 & 0xfffffffc) << (uRam020c5250 & 3) * -8 + 0x20 == 0) {
    return;
  }
  uVar2 = (*(uint *)(uRam020c5254 & 0xfffffffc) >> (uRam020c5254 & 3) * 8 |
          *(uint *)(uRam020c5254 & 0xfffffffc) << (uRam020c5254 & 3) * -8 + 0x20) + 0x20;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0) {
    iVar8 = func_020b1d20();
    if (iVar8 == 0) {
      uVar2 = (*(uint *)(uRam020c5258 & 0xfffffffc) >> (uRam020c5258 & 3) * 8 |
              *(uint *)(uRam020c5258 & 0xfffffffc) << (uRam020c5258 & 3) * -8 + 0x20) + 8;
      uVar4 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 5) {
        uVar2 = (*(uint *)(uRam020c5250 & 0xfffffffc) >> (uRam020c5250 & 3) * 8 |
                *(uint *)(uRam020c5250 & 0xfffffffc) << (uRam020c5250 & 3) * -8 + 0x20) + 4;
        uVar4 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        iVar8 = GetB3C4_Cell_RaceM((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x28);
      }
      else {
        uVar4 = *(uint *)(uRam020c5250 & 0xfffffffc) >> (uRam020c5250 & 3) * 8 |
                *(uint *)(uRam020c5250 & 0xfffffffc) << (uRam020c5250 & 3) * -8 + 0x20;
        uVar2 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        iVar8 = GetB3C4_Cell_RaceM((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0x28);
      }
    }
    else {
      uVar2 = (*(uint *)(uRam020c5258 & 0xfffffffc) >> (uRam020c5258 & 3) * 8 |
              *(uint *)(uRam020c5258 & 0xfffffffc) << (uRam020c5258 & 3) * -8 + 0x20) + 8;
      uVar4 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 5) {
        uVar2 = (*(uint *)(uRam020c5250 & 0xfffffffc) >> (uRam020c5250 & 3) * 8 |
                *(uint *)(uRam020c5250 & 0xfffffffc) << (uRam020c5250 & 3) * -8 + 0x20) + 4;
        uVar4 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        iVar8 = GetB3C4_Cell_RaceGoalM((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x3c);
      }
      else {
        uVar4 = *(uint *)(uRam020c5250 & 0xfffffffc) >> (uRam020c5250 & 3) * 8 |
                *(uint *)(uRam020c5250 & 0xfffffffc) << (uRam020c5250 & 3) * -8 + 0x20;
        uVar2 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        iVar8 = GetB3C4_Cell_RaceGoalM((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0x3c);
      }
    }
    uVar2 = (*(uint *)(uRam020c5258 & 0xfffffffc) >> (uRam020c5258 & 3) * 8 |
            *(uint *)(uRam020c5258 & 0xfffffffc) << (uRam020c5258 & 3) * -8 + 0x20) + 8;
    uVar4 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 5) &&
        (uVar4 = *(uint *)(uRam020c5250 & 0xfffffffc) >> (uRam020c5250 & 3) * 8 |
                 *(uint *)(uRam020c5250 & 0xfffffffc) << (uRam020c5250 & 3) * -8 + 0x20,
        uVar2 = uVar4 + 0x10, uVar3 = uVar2 & 3, uVar2 = *(uint *)(uVar2 & 0xfffffffc),
        uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0)) &&
       (uVar4 = uVar4 + 8, uVar2 = uVar4 & 3, uVar4 = *(uint *)(uVar4 & 0xfffffffc),
       (int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) < 0x69)) {
      iVar7 = func_020b1d20();
      if (iVar7 == 0) {
        iVar7 = GetB3C4_Cell_RaceM(0x2c);
      }
      else {
        iVar7 = GetB3C4_Cell_RaceGoalM(0x42);
      }
    }
  }
  if (iVar8 != 0) {
    uVar2 = (uint)*(ushort *)(param_1 + 0x400);
    puVar6 = (uint *)(param_1 + uVar2 * 8);
    sVar1 = MaybeMakeOamSlot(puVar6,0x80 - uVar2 & 0xffff,iVar8);
    puVar5 = (ushort *)(param_1 + 0x400);
    *puVar5 = *puVar5 + sVar1;
    if (uVar2 < *puVar5) {
      do {
        uVar2 = uVar2 + 1;
        *puVar6 = (*(uint *)((uint)puVar6 & 0xfffffffc) >> ((uint)puVar6 & 3) * 8 |
                  *(uint *)((uint)puVar6 & 0xfffffffc) << ((uint)puVar6 & 3) * -8 + 0x20) &
                  0xfffff3ff | 0x800;
        uVar4 = (uint)(puVar6 + 1) & 3;
        uVar3 = *(uint *)((uint)(puVar6 + 1) & 0xfffffffc);
        puVar6[1] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xfffff3ff | 0x400;
        puVar6 = puVar6 + 2;
      } while ((int)uVar2 < (int)(uint)*puVar5);
    }
    sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,iVar8);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
  }
  if (iVar7 != 0) {
    uVar2 = (uint)*(ushort *)(param_1 + 0x400);
    puVar6 = (uint *)(param_1 + uVar2 * 8);
    sVar1 = MaybeMakeOamSlot(puVar6,0x80 - uVar2 & 0xffff,iVar7);
    puVar5 = (ushort *)(param_1 + 0x400);
    *puVar5 = *puVar5 + sVar1;
    if (uVar2 < *puVar5) {
      do {
        uVar2 = uVar2 + 1;
        *puVar6 = (*(uint *)((uint)puVar6 & 0xfffffffc) >> ((uint)puVar6 & 3) * 8 |
                  *(uint *)((uint)puVar6 & 0xfffffffc) << ((uint)puVar6 & 3) * -8 + 0x20) &
                  0xfffff3ff | 0x800;
        uVar4 = (uint)(puVar6 + 1) & 3;
        uVar3 = *(uint *)((uint)(puVar6 + 1) & 0xfffffffc);
        puVar6[1] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xfffff3ff | 0x400;
        puVar6 = puVar6 + 2;
      } while ((int)uVar2 < (int)(uint)*puVar5);
    }
    sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,iVar7);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
    return;
  }
  return;
}

