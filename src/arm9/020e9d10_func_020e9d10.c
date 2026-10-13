/* Decompiled C draft; module arm9; ROM address 020e9d10. No matching claim. */
#include "types.h"
#include "deps/020e9d10_func_020e9d10.h"

void func_020e9d10(void)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  bool bVar10;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  
  piVar1 = piRam020ea18c;
  uVar3 = (*(uint *)(uRam020ea180 & 0xfffffffc) >> (uRam020ea180 & 3) * 8 |
          *(uint *)(uRam020ea180 & 0xfffffffc) << (uRam020ea180 & 3) * -8 + 0x20) + 0xc;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) == 6) {
    return;
  }
  if (*(uint *)(uRam020ea184 & 0xfffffffc) >> (uRam020ea184 & 3) * 8 == 0 &&
      *(uint *)(uRam020ea184 & 0xfffffffc) << (uRam020ea184 & 3) * -8 + 0x20 == 0) {
    return;
  }
  if (*(short *)(iRam020ea188 + 0xe) != 0) {
    uVar3 = *(uint *)((uint)piRam020ea18c & 0xfffffffc) >> ((uint)piRam020ea18c & 3) * 8 |
            *(uint *)((uint)piRam020ea18c & 0xfffffffc) << ((uint)piRam020ea18c & 3) * -8 + 0x20;
    iVar5 = uVar3 + 1;
    *piRam020ea18c = iVar5;
    bVar10 = SBORROW4(iVar5,0x3c);
    if (0x3b < iVar5) {
      iVar5 = 0;
    }
    if ((int)(uVar3 - 0x3b) < 0 == bVar10) {
      *piVar1 = iVar5;
    }
    uVar3 = *(uint *)((uint)puRam020ea190 & 0xfffffffc) >> ((uint)puRam020ea190 & 3) * 8 |
            *(uint *)((uint)puRam020ea190 & 0xfffffffc) << ((uint)puRam020ea190 & 3) * -8 + 0x20;
    if (((uVar3 != 4) && (iVar5 = iRam020ea194 + uVar3 * 0x10, uVar3 != 0)) && (uVar3 != 1)) {
      uVar3 = iVar5 + 4;
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if (uVar3 >> uVar4 * 8 != 0 || uVar3 << uVar4 * -8 + 0x20 != 0) {
        Animation_Update();
      }
      uVar3 = iVar5 + 8;
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if (uVar3 >> uVar4 * 8 != 0 || uVar3 << uVar4 * -8 + 0x20 != 0) {
        Animation_Update();
      }
    }
    puVar2 = puRam020ea198;
    if ((*(short *)(iRam020ea188 + 0xe) != 4) &&
       ((*(short *)(iRam020ea188 + 0xe) != 5 ||
        ((*(uint *)((uint)puRam020ea190 & 0xfffffffc) >> ((uint)puRam020ea190 & 3) * 8 |
         *(uint *)((uint)puRam020ea190 & 0xfffffffc) << ((uint)puRam020ea190 & 3) * -8 + 0x20) != 4)
        ))) {
      uVar9 = *(uint *)(uRam020ea184 & 0xfffffffc) >> (uRam020ea184 & 3) * 8 |
              *(uint *)(uRam020ea184 & 0xfffffffc) << (uRam020ea184 & 3) * -8 + 0x20;
      uVar6 = *(undefined4 *)(uVar9 + 0x84);
      uVar8 = *(undefined4 *)(uVar9 + 0x88);
      *puRam020ea198 = *(undefined4 *)(uVar9 + 0x80);
      puVar2[1] = uVar6;
      puVar2[2] = uVar8;
      uVar3 = (uint)(puVar2 + 1) & 3;
      uVar7 = *(uint *)((uint)(puVar2 + 1) & 0xfffffffc);
      uVar4 = uVar9 + 700 & 3;
      uVar9 = *(uint *)(uVar9 + 700 & 0xfffffffc);
      puVar2[1] = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) -
                  (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20);
    }
    func_020e9658();
    func_020e8ac8();
  }
  StateDualHandler_Execute(iRam020ea188);
  if (*(short *)(iRam020ea188 + 0xe) != 0) {
    return;
  }
  uVar3 = (*(uint *)(uRam020ea180 & 0xfffffffc) >> (uRam020ea180 & 3) * 8 |
          *(uint *)(uRam020ea180 & 0xfffffffc) << (uRam020ea180 & 3) * -8 + 0x20) + 8;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar3 == 2) {
    return;
  }
  if (((uVar3 != 4) &&
      (uVar3 = (uint)*puRam020ea19c * 0x8c +
               (*(uint *)(uRam020ea1a0 & 0xfffffffc) >> (uRam020ea1a0 & 3) * 8 |
               *(uint *)(uRam020ea1a0 & 0xfffffffc) << (uRam020ea1a0 & 3) * -8 + 0x20) + 0x14,
      uVar4 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
      (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) == 1)) &&
     (uVar9 = *(uint *)(uRam020ea184 & 0xfffffffc) >> (uRam020ea184 & 3) * 8 |
              *(uint *)(uRam020ea184 & 0xfffffffc) << (uRam020ea184 & 3) * -8 + 0x20,
     uVar3 = uVar9 + 0x48 & 3, uVar4 = *(uint *)(uVar9 + 0x48 & 0xfffffffc),
     ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 0x800) == 0)) {
    *(undefined2 *)(iRam020ea1a4 + 0x18) = 2;
    puVar2 = puRam020ea198;
    uVar6 = *(undefined4 *)(uVar9 + 0x84);
    uVar8 = *(undefined4 *)(uVar9 + 0x88);
    *puRam020ea198 = *(undefined4 *)(uVar9 + 0x80);
    puVar2[1] = uVar6;
    puVar2[2] = uVar8;
    uVar3 = (uint)(puVar2 + 1) & 3;
    uVar7 = *(uint *)((uint)(puVar2 + 1) & 0xfffffffc);
    uVar4 = uVar9 + 700 & 3;
    uVar9 = *(uint *)(uVar9 + 700 & 0xfffffffc);
    puVar2[1] = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) -
                (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20);
    func_020e9658();
    iStack_1c = piRam020ea1a8[1];
    iStack_18 = piRam020ea1a8[2];
    iStack_20 = *piRam020ea1a8 +
                (*(uint *)(uRam020ea1ac & 0xfffffffc) >> (uRam020ea1ac & 3) * 8 |
                *(uint *)(uRam020ea1ac & 0xfffffffc) << (uRam020ea1ac & 3) * -8 + 0x20);
    func_02147288(&iStack_20,uRam020ea1b0);
    *puRam020ea190 = 3;
    iVar5 = func_0203c5e4();
    puVar2 = puRam020ea1bc;
    if ((iVar5 == 0) &&
       ((*(uint *)((uint)puRam020ea190 & 0xfffffffc) >> ((uint)puRam020ea190 & 3) * 8 |
        *(uint *)((uint)puRam020ea190 & 0xfffffffc) << ((uint)puRam020ea190 & 3) * -8 + 0x20) < 2))
    {
      *puRam020ea1b8 = 1;
      *puVar2 = 1;
    }
    StateDualHandler_SetState(iRam020ea188,6);
    return;
  }
  iVar5 = IsRacerFinishedRace(*puRam020ea19c);
  if (iVar5 != 0) {
    return;
  }
  if ((*(uint *)(uRam020ea1c0 & 0xfffffffc) >> (uRam020ea1c0 & 3) * 8 != 0 ||
       *(uint *)(uRam020ea1c0 & 0xfffffffc) << (uRam020ea1c0 & 3) * -8 + 0x20 != 0) &&
     (uVar3 = func_0203c8c0(*puRam020ea19c), puVar2 = puRam020ea198, *puRam020ea1c4 < uVar3)) {
    uVar9 = *(uint *)(uRam020ea184 & 0xfffffffc) >> (uRam020ea184 & 3) * 8 |
            *(uint *)(uRam020ea184 & 0xfffffffc) << (uRam020ea184 & 3) * -8 + 0x20;
    *puRam020ea1c4 = (ushort)uVar3;
    uVar6 = *(undefined4 *)(uVar9 + 0x84);
    uVar8 = *(undefined4 *)(uVar9 + 0x88);
    *puVar2 = *(undefined4 *)(uVar9 + 0x80);
    puVar2[1] = uVar6;
    puVar2[2] = uVar8;
    uVar3 = (uint)(puVar2 + 1) & 3;
    uVar7 = *(uint *)((uint)(puVar2 + 1) & 0xfffffffc);
    uVar4 = uVar9 + 700 & 3;
    uVar9 = *(uint *)(uVar9 + 700 & 0xfffffffc);
    puVar2[1] = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) -
                (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20);
    func_020e9658();
    iStack_10 = piRam020ea1c8[1];
    iStack_c = piRam020ea1c8[2];
    iStack_14 = *piRam020ea1c8 +
                (*(uint *)(uRam020ea1ac & 0xfffffffc) >> (uRam020ea1ac & 3) * 8 |
                *(uint *)(uRam020ea1ac & 0xfffffffc) << (uRam020ea1ac & 3) * -8 + 0x20);
    func_02147288(&iStack_14,uRam020ea1b0);
    if (*puRam020ea1c4 != *puRam020ea1cc) {
      *puRam020ea190 = 0;
      iVar5 = func_0203c5e4();
      puVar2 = puRam020ea1bc;
      if ((iVar5 == 0) &&
         ((*(uint *)((uint)puRam020ea190 & 0xfffffffc) >> ((uint)puRam020ea190 & 3) * 8 |
          *(uint *)((uint)puRam020ea190 & 0xfffffffc) << ((uint)puRam020ea190 & 3) * -8 + 0x20) < 2)
         ) {
        *puRam020ea1b8 = 1;
        *puVar2 = 1;
      }
      StateDualHandler_SetState(iRam020ea188,6);
      return;
    }
    *puRam020ea190 = 1;
    iVar5 = func_0203c5e4();
    puVar2 = puRam020ea1bc;
    if ((iVar5 == 0) &&
       ((*(uint *)((uint)puRam020ea190 & 0xfffffffc) >> ((uint)puRam020ea190 & 3) * 8 |
        *(uint *)((uint)puRam020ea190 & 0xfffffffc) << ((uint)puRam020ea190 & 3) * -8 + 0x20) < 2))
    {
      *puRam020ea1b8 = 1;
      *puVar2 = 1;
    }
    StateDualHandler_SetState(iRam020ea188,6);
    return;
  }
  uVar4 = *(uint *)(uRam020ea184 & 0xfffffffc) >> (uRam020ea184 & 3) * 8 |
          *(uint *)(uRam020ea184 & 0xfffffffc) << (uRam020ea184 & 3) * -8 + 0x20;
  uVar3 = uVar4 + 0x48 & 3;
  uVar9 = *(uint *)(uVar4 + 0x48 & 0xfffffffc);
  uVar3 = uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20;
  if ((uVar3 & 1) != 0) {
    return;
  }
  if (*(uint *)(uRam020ea1c0 & 0xfffffffc) >> (uRam020ea1c0 & 3) * 8 != 0 ||
      *(uint *)(uRam020ea1c0 & 0xfffffffc) << (uRam020ea1c0 & 3) * -8 + 0x20 != 0) {
    if (((*(ushort *)
           ((uint)*puRam020ea19c * 0x8c +
            (*(uint *)(uRam020ea1a0 & 0xfffffffc) >> (uRam020ea1a0 & 3) * 8 |
            *(uint *)(uRam020ea1a0 & 0xfffffffc) << (uRam020ea1a0 & 3) * -8 + 0x20) + 0x44) & 4) !=
         0) && ((uVar3 & 0x800) == 0)) {
      uVar3 = *(uint *)((uint)piRam020ea1d0 & 0xfffffffc) >> ((uint)piRam020ea1d0 & 3) * 8 |
              *(uint *)((uint)piRam020ea1d0 & 0xfffffffc) << ((uint)piRam020ea1d0 & 3) * -8 + 0x20;
      iVar5 = uVar3 + 1;
      *piRam020ea1d0 = iVar5;
      puVar2 = puRam020ea198;
      if (iVar5 != 0x3c && (int)(uVar3 - 0x3b) < 0 == SBORROW4(iVar5,0x3c)) {
        uVar6 = *(undefined4 *)(uVar4 + 0x84);
        uVar8 = *(undefined4 *)(uVar4 + 0x88);
        *puRam020ea198 = *(undefined4 *)(uVar4 + 0x80);
        puVar2[1] = uVar6;
        puVar2[2] = uVar8;
        uVar3 = (uint)(puVar2 + 1) & 3;
        uVar7 = *(uint *)((uint)(puVar2 + 1) & 0xfffffffc);
        uVar9 = uVar4 + 700 & 3;
        uVar4 = *(uint *)(uVar4 + 700 & 0xfffffffc);
        puVar2[1] = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) -
                    (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20);
        func_020e9658();
        StateDualHandler_SetState(iRam020ea188,1);
        return;
      }
      return;
    }
    *piRam020ea1d0 = 0;
    return;
  }
  return;
}

