/* Decompiled C draft; module arm9; ROM address 02043648. No matching claim. */
#include "types.h"
#include "deps/02043648_func_02043648.h"

void func_02043648(void)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  bool bVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar20;
  uint local_5c;
  uint local_58;
  uint local_40;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint uVar19;
  
  uVar3 = *(ushort *)
           ((*(uint *)(DAT_02043a08 & 0xfffffffc) >> (DAT_02043a08 & 3) * 8 |
            *(uint *)(DAT_02043a08 & 0xfffffffc) << (DAT_02043a08 & 3) * -8 + 0x20) + 2);
  uVar7 = (uint)uVar3;
  uVar8 = func_02046c10();
  uVar17 = *(uint *)(DAT_02043a10 & 0xfffffffc) >> (DAT_02043a10 & 3) * 8 |
           *(uint *)(DAT_02043a10 & 0xfffffffc) << (DAT_02043a10 & 3) * -8 + 0x20;
  uVar15 = (*(uint *)(DAT_02043a0c & 0xfffffffc) >> (DAT_02043a0c & 3) * 8 |
           *(uint *)(DAT_02043a0c & 0xfffffffc) << (DAT_02043a0c & 3) * -8 + 0x20) + 0x30;
  uVar9 = uVar15 & 3;
  uVar15 = *(uint *)(uVar15 & 0xfffffffc);
  uVar15 = (int)((uVar15 >> uVar9 * 8 | uVar15 << uVar9 * -8 + 0x20) << 0x1c) >> 0x1f;
  bVar14 = false;
  if (uVar17 == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = *(uint *)(uVar17 & 0xfffffffc) >> (uVar17 & 3) * 8 |
            *(uint *)(uVar17 & 0xfffffffc) << (uVar17 & 3) * -8 + 0x20;
  }
  if ((uVar9 != 0) &&
     (uVar9 = uVar17 + 4 & 3, uVar17 = *(uint *)(uVar17 + 4 & 0xfffffffc),
     (uVar17 >> uVar9 * 8 | uVar17 << uVar9 * -8 + 0x20) != 0xd)) {
    bVar14 = true;
  }
  local_5c = uVar7;
  local_58 = uVar8;
  if (bVar14) {
    uVar9 = (*(uint *)(DAT_02043a08 & 0xfffffffc) >> (DAT_02043a08 & 3) * 8 |
            *(uint *)(DAT_02043a08 & 0xfffffffc) << (DAT_02043a08 & 3) * -8 + 0x20) + 8;
    uVar17 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    func_02050064(uVar9 >> uVar17 * 8 | uVar9 << uVar17 * -8 + 0x20);
    local_5c = func_0204ffe8();
    uVar9 = (*(uint *)(DAT_02043a08 & 0xfffffffc) >> (DAT_02043a08 & 3) * 8 |
            *(uint *)(DAT_02043a08 & 0xfffffffc) << (DAT_02043a08 & 3) * -8 + 0x20) + 8;
    uVar17 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    iVar10 = func_02050064(uVar9 >> uVar17 * 8 | uVar9 << uVar17 * -8 + 0x20);
    uVar9 = (*(uint *)(DAT_02043a10 & 0xfffffffc) >> (DAT_02043a10 & 3) * 8 |
            *(uint *)(DAT_02043a10 & 0xfffffffc) << (DAT_02043a10 & 3) * -8 + 0x20) + 0x15c8;
    uVar17 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    local_58 = (uint)*(ushort *)
                      ((uVar9 >> uVar17 * 8 | uVar9 << uVar17 * -8 + 0x20) + iVar10 * 8 + 2);
    uVar9 = (*(uint *)(DAT_02043a08 & 0xfffffffc) >> (DAT_02043a08 & 3) * 8 |
            *(uint *)(DAT_02043a08 & 0xfffffffc) << (DAT_02043a08 & 3) * -8 + 0x20) + 8;
    uVar17 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    func_02050064(uVar9 >> uVar17 * 8 | uVar9 << uVar17 * -8 + 0x20);
  }
  uVar17 = 0;
  uVar9 = uVar7 & DAT_02043a14;
  bVar14 = false;
  local_28 = 0;
  local_2c = 0;
  local_30 = 0;
  local_34 = 0;
  local_40 = 0;
  do {
    uVar11 = DAT_02043a18;
    uVar19 = (uint)((*(ushort *)
                      ((*(uint *)(DAT_02043a08 & 0xfffffffc) >> (DAT_02043a08 & 3) * 8 |
                       *(uint *)(DAT_02043a08 & 0xfffffffc) << (DAT_02043a08 & 3) * -8 + 0x20) + 4)
                    & 1) != 0);
    iVar10 = GetCurrentSceneId();
    uVar2 = DAT_02043a18;
    if ((iVar10 != 2) ||
       (bVar5 = false,
       (*(ushort *)
         ((*(uint *)(DAT_02043a08 & 0xfffffffc) >> (DAT_02043a08 & 3) * 8 |
          *(uint *)(DAT_02043a08 & 0xfffffffc) << (DAT_02043a08 & 3) * -8 + 0x20) + 4) & 2) != 0)) {
      bVar5 = true;
    }
    iVar10 = uVar17 * 0x5c + DAT_02043a1c;
    uVar4 = *(ushort *)
             ((*(uint *)(DAT_02043a08 & 0xfffffffc) >> (DAT_02043a08 & 3) * 8 |
              *(uint *)(DAT_02043a08 & 0xfffffffc) << (DAT_02043a08 & 3) * -8 + 0x20) + 4);
    uVar12 = local_40;
    uVar20 = local_40;
    bVar6 = bVar14;
    if ((uVar4 & 8) != 0) goto switchD_020437e8_default;
    uVar1 = iVar10 + 0x3cU & 3;
    uVar16 = *(uint *)(iVar10 + 0x3cU & 0xfffffffc);
    if (uVar19 == 0) {
      uVar19 = iVar10 + 0x44U & 3;
      uVar18 = *(uint *)(iVar10 + 0x44U & 0xfffffffc);
      uVar19 = uVar18 >> uVar19 * 8 | uVar18 << uVar19 * -8 + 0x20;
    }
    switch(uVar16 >> uVar1 * 8 | uVar16 << uVar1 * -8 + 0x20) {
    case 0:
      uVar11 = uVar2;
      uVar12 = local_28;
      uVar20 = local_28;
      break;
    case 1:
      uVar20 = local_34;
      if (uVar19 == 0) {
        uVar11 = uVar2;
        if (bVar5) {
          uVar12 = func_0204a664(iVar10 + 0x28);
          uVar11 = DAT_02043a18;
        }
      }
      else {
        bVar6 = true;
        uVar11 = uVar2;
      }
      break;
    case 2:
      if (uVar19 == 0) {
        uVar11 = uVar8;
        uVar20 = uVar15;
        if (bVar5) {
          uVar12 = uVar7;
          if ((uVar4 & 4) != 0) {
            uVar12 = uVar9;
            if ((uVar3 & 0x20) != 0) {
              uVar12 = uVar9 | 0x10;
            }
            if ((uVar3 & 0x10) != 0) {
              uVar12 = uVar12 | 0x20;
            }
          }
          func_0204a798(iVar10 + 0x28,uVar12);
        }
      }
      else {
        uVar11 = uVar8;
        uVar20 = uVar15;
        bVar6 = true;
      }
      break;
    case 3:
      goto LAB_020438b0;
    case 4:
      if (uVar19 == 0) {
        if (bVar5) {
          func_02050064(uVar17);
          uVar11 = func_0204ffe8();
          uVar12 = uVar11;
          if ((*(ushort *)
                ((*(uint *)(DAT_02043a08 & 0xfffffffc) >> (DAT_02043a08 & 3) * 8 |
                 *(uint *)(DAT_02043a08 & 0xfffffffc) << (DAT_02043a08 & 3) * -8 + 0x20) + 4) & 4)
              != 0) {
            uVar12 = uVar11 & DAT_02043a14 & 0xffff;
            if ((uVar11 & 0x20) != 0) {
              uVar12 = uVar12 | 0x10;
            }
            if ((uVar11 & 0x10) != 0) {
              uVar12 = uVar12 | 0x20;
            }
          }
        }
      }
      else {
        bVar6 = true;
      }
      iVar13 = func_02050064(uVar17);
      uVar11 = (*(uint *)(DAT_02043a10 & 0xfffffffc) >> (DAT_02043a10 & 3) * 8 |
               *(uint *)(DAT_02043a10 & 0xfffffffc) << (DAT_02043a10 & 3) * -8 + 0x20) + 0x15c8;
      uVar2 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      uVar4 = *(ushort *)((uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) + iVar13 * 8 + 2);
      iVar13 = func_02050064(uVar17);
      uVar11 = (*(uint *)(DAT_02043a10 & 0xfffffffc) >> (DAT_02043a10 & 3) * 8 |
               *(uint *)(DAT_02043a10 & 0xfffffffc) << (DAT_02043a10 & 3) * -8 + 0x20) + 0x15c8;
      uVar2 = uVar11 & 3;
      uVar19 = *(uint *)(uVar11 & 0xfffffffc);
      uVar11 = (uint)uVar4;
      uVar20 = ((uint)*(byte *)((uVar19 >> uVar2 * 8 | uVar19 << uVar2 * -8 + 0x20) + iVar13 * 8 + 6
                               ) << 0x18) >> 0x1f;
      break;
    case 5:
      uVar11 = local_58;
      uVar12 = local_5c;
      uVar20 = local_2c;
      break;
    case 6:
      uVar11 = uVar8;
      uVar12 = uVar7;
      uVar20 = uVar15;
      break;
    case 7:
LAB_020438b0:
      if (uVar19 == 0) {
        uVar4 = *(ushort *)(iVar10 + 0x40);
        *(undefined2 *)(iVar10 + 0x40) = 0;
        uVar11 = uVar2;
        uVar12 = (uint)uVar4;
        uVar20 = local_30;
      }
      else {
        bVar6 = true;
      }
    }
switchD_020437e8_default:
    if (!bVar6) {
      StructG_UpdateInput(uVar12 & *(ushort *)(iVar10 + 0x42),iVar10);
    }
    func_02046ca8(iVar10 + 0x48,uVar11,uVar20);
    uVar17 = uVar17 + 1 & 0xff;
    if (9 < uVar17) {
      return;
    }
  } while( true );
}

