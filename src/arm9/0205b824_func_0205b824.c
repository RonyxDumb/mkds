/* Decompiled C draft; module arm9; ROM address 0205b824. No matching claim. */
#include "types.h"
#include "deps/0205b824_func_0205b824.h"

void func_0205b824(uint param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar10;
  uint uVar12;
  int iVar13;
  uint uVar14;
  byte bVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  uint uVar20;
  uint uVar21;
  undefined8 uVar22;
  uint uVar9;
  uint uVar11;
  uint uVar19;
  
  iVar13 = param_2 * 0x38;
  uVar14 = *(uint *)(uRam0205b94c & 0xfffffffc) >> (uRam0205b94c & 3) * 8 |
           *(uint *)(uRam0205b94c & 0xfffffffc) << (uRam0205b94c & 3) * -8 + 0x20;
  bVar15 = *(byte *)(uVar14 + iVar13 + 0x48);
  if (bVar15 < 0xc) {
    if (bVar15 == 0) {
      bVar2 = true;
    }
    else {
      uVar4 = param_1 + 0x18 & 3;
      uVar8 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
      uVar9 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
      uVar5 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
              *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
      uVar4 = param_1 + 0x1c & 3;
      uVar21 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
      uVar8 = param_1 + 4 & 3;
      uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
      uVar6 = uVar9 - uVar5;
      uVar1 = param_1 + 0x10 & 3;
      uVar18 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
      uVar19 = uVar18 >> uVar1 * 8 | uVar18 << uVar1 * -8 + 0x20;
      uVar1 = param_1 + 0x14 & 3;
      uVar16 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
      uVar18 = param_1 + 8 & 3;
      uVar10 = *(uint *)(param_1 + 8 & 0xfffffffc);
      uVar11 = uVar10 >> uVar18 * 8 | uVar10 << uVar18 * -8 + 0x20;
      uVar18 = param_1 + 0xc & 3;
      uVar10 = *(uint *)(param_1 + 0xc & 0xfffffffc);
      uVar12 = uVar19 - uVar11;
      uVar20 = uVar6 - uVar12;
      iVar17 = ((uVar21 >> uVar4 * 8 | uVar21 << uVar4 * -8 + 0x20) -
               ((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) + (uint)(uVar9 < uVar5))) -
               (((uVar16 >> uVar1 * 8 | uVar16 << uVar1 * -8 + 0x20) -
                ((uVar10 >> uVar18 * 8 | uVar10 << uVar18 * -8 + 0x20) + (uint)(uVar19 < uVar11))) +
               (uint)(uVar6 < uVar12));
      uVar22 = _ll_udiv(uVar20 * 0x40,iVar17 * 0x40 | uVar20 >> 0x1a,uRam0205b950,0);
      uVar4 = uRam0205b94c;
      bVar2 = false;
      if ((int)((ulonglong)uVar22 >> 0x20) == 0 && (uint)uVar22 < 1000) {
        iVar7 = uVar14 + 0x3c;
        uVar14 = iVar7 + iVar13 & 3;
        uVar4 = *(uint *)(iVar7 + iVar13 & 0xfffffffc);
        uVar8 = uVar4 >> uVar14 * 8 | uVar4 << uVar14 * -8 + 0x20;
        uVar14 = iVar7 + iVar13 + 4;
        uVar4 = uVar14 & 3;
        uVar14 = *(uint *)(uVar14 & 0xfffffffc);
        *(uint *)(iVar7 + iVar13) = uVar8 + uVar20;
        *(uint *)(iVar7 + iVar13 + 4) =
             (uVar14 >> uVar4 * 8 | uVar14 << uVar4 * -8 + 0x20) + iVar17 +
             (uint)CARRY4(uVar8,uVar20);
        bVar2 = true;
      }
      else {
        *(char *)(uVar14 + 0x49 + iVar13) = *(char *)(uVar14 + 0x49 + iVar13) + '\x01';
        uVar14 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        uVar14 = uVar4 >> uVar14 * 8 | uVar4 << uVar14 * -8 + 0x20;
        if (0x40 < *(byte *)(uVar14 + iVar13 + 0x49)) {
          *(byte *)(uVar14 + 0x748) = *(byte *)(uVar14 + 0x748) | (byte)(1 << (param_2 & 0xff));
        }
      }
    }
    if (bVar2) {
      bVar15 = bVar15 + 1;
    }
    *(byte *)((*(uint *)(uRam0205b94c & 0xfffffffc) >> (uRam0205b94c & 3) * 8 |
              *(uint *)(uRam0205b94c & 0xfffffffc) << (uRam0205b94c & 3) * -8 + 0x20) + iVar13 +
             0x48) = bVar15;
    return;
  }
  return;
}

