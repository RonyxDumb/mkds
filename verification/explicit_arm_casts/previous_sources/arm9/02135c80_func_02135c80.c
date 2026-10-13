/* Decompiled C draft; module arm9; ROM address 02135c80. No matching claim. */
#include "types.h"
#include "deps/02135c80_func_02135c80.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint * func_02135c80(undefined4 param_1,undefined4 param_2,int param_3,uint param_4,uint param_5,
                    undefined4 param_6,uint param_7)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 uStack_4;
  
  uVar11 = param_7;
  uVar3 = (int)&param_5 + 1U & 3;
  uVar12 = (param_5 >> uVar3 * 8 | param_5 << uVar3 * -8 + 0x20) & 0xff;
  uVar3 = (int)&uStack_4 + 3U & 3;
  uVar9 = (param_4 >> uVar3 * 8 | param_4 << uVar3 * -8 + 0x20) & 0xff;
  uVar3 = (int)&uStack_4 + 1U & 3;
  local_60 = local_60 & 0xffffff00;
  uVar10 = (param_4 >> uVar3 * 8 | param_4 << uVar3 * -8 + 0x20) & 0xff;
  uStack_4 = param_4;
  func_02140c28(&local_60,param_1,param_2,&local_5c);
  uVar3 = (int)&local_58 + (local_58 & 0xff) + 1;
  while ((1 < (local_58 & 0xff) &&
         (uVar3 = uVar3 - 1,
         ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) & 0xff) == 0x30))) {
    local_58 = (local_58 & 0xff) - 1 & 0xff | local_58 & 0xffffff00;
    local_5c = CONCAT22(MKDS_SLICE_2(local_5c,2) + 1,(undefined2)local_5c);
  }
  uVar3 = (int)&local_58 + 1U & 3;
  uVar3 = (local_58 >> uVar3 * 8 | local_58 << uVar3 * -8 + 0x20) & 0xff;
  if (uVar3 == 0x30) {
    local_5c = local_5c & 0xffff;
  }
  else {
    if (uVar3 == 0x49) {
      iVar6 = FUN_02131ce8(param_1,param_2,0,0);
      if (iVar6 == 0) {
        puVar8 = (uint *)(param_3 + -4);
        if (uVar12 < 0x80) {
          uVar2 = *(ushort *)(iRam02136608 + uVar12 * 2) & 0x200;
        }
        else {
          uVar2 = 0;
        }
        if (uVar2 == 0) {
          func_0213a2d0(puVar8,uRam02136618);
        }
        else {
          func_0213a2d0(puVar8,uRam02136614);
        }
      }
      else {
        puVar8 = (uint *)(param_3 + -5);
        if (uVar12 < 0x80) {
          uVar2 = *(ushort *)(iRam02136608 + uVar12 * 2) & 0x200;
        }
        else {
          uVar2 = 0;
        }
        if (uVar2 == 0) {
          func_0213a2d0(puVar8,uRam02136610);
        }
        else {
          func_0213a2d0(puVar8,uRam0213660c);
        }
      }
      return puVar8;
    }
    if (uVar3 == 0x4e) {
      if ((local_5c & 0xff) == 0) {
        puVar8 = (uint *)(param_3 + -4);
        if (uVar12 < 0x80) {
          uVar2 = *(ushort *)(iRam02136608 + uVar12 * 2) & 0x200;
        }
        else {
          uVar2 = 0;
        }
        if (uVar2 == 0) {
          func_0213a2d0(puVar8,uRam02136628);
        }
        else {
          func_0213a2d0(puVar8,uRam02136624);
        }
      }
      else {
        puVar8 = (uint *)(param_3 + -5);
        if (uVar12 < 0x80) {
          uVar2 = *(ushort *)(iRam02136608 + uVar12 * 2) & 0x200;
        }
        else {
          uVar2 = 0;
        }
        if (uVar2 == 0) {
          func_0213a2d0(puVar8,uRam02136620);
        }
        else {
          func_0213a2d0(puVar8,uRam0213661c);
        }
      }
      return puVar8;
    }
  }
  sVar1 = MKDS_SLICE_2(local_5c,2) + (((ushort)local_58 & 0xff) - 1);
  puVar8 = (uint *)(param_3 + -1);
  uVar4 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
          *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) & 0xffffff00;
  uVar3 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
  *puVar8 = uVar4 >> uVar3 | uVar4 << 0x20 - uVar3;
  if (uVar12 < 0x66) {
    if (uVar12 < 0x65) {
      if (0x47 < uVar12) {
        return puVar8;
      }
      if (uVar12 < 0x45) {
        return puVar8;
      }
      if (uVar12 != 0x45) {
        if (uVar12 != 0x46) {
          if (uVar12 != 0x47) {
            return puVar8;
          }
          goto LAB_02135fd0;
        }
        goto LAB_0213630c;
      }
    }
LAB_02136050:
    if ((int)(uVar11 + 1) < (int)(local_58 & 0xff)) {
      func_02136638(&local_5c);
    }
    iVar14 = iRam02136630;
    iVar13 = iRam0213662c;
    iVar6 = (int)sVar1;
    uVar3 = 0x2b;
    iVar15 = 0;
    if (iVar6 < 0) {
      iVar6 = -iVar6;
      uVar3 = 0x2d;
    }
    for (; (iVar6 != 0 || (iVar15 < 2)); iVar15 = iVar15 + 1) {
      puVar8 = (uint *)((int)puVar8 + -1);
      uVar5 = (iVar6 - iVar14 * ((int)((longlong)iVar13 * (longlong)iVar6 >> 0x22) - (iVar6 >> 0x1f)
                                )) + 0x30U & 0xff |
              (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
              *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) & 0xffffff00;
      uVar4 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
      *puVar8 = uVar5 >> uVar4 | uVar5 << 0x20 - uVar4;
      iVar6 = (int)((longlong)iVar13 * (longlong)iVar6 >> 0x22) - (iVar6 >> 0x1f);
    }
    puVar7 = (uint *)((int)puVar8 + -1);
    uVar3 = uVar3 | (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
                    *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) &
                    0xffffff00;
    uVar4 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
    *puVar7 = uVar3 >> uVar4 | uVar3 << 0x20 - uVar4;
    puVar7 = (uint *)((int)puVar8 + -2);
    uVar12 = uVar12 | (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
                      *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) &
                      0xffffff00;
    uVar3 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
    *puVar7 = uVar12 >> uVar3 | uVar12 << 0x20 - uVar3;
    if (iRam02136634 < (int)(uVar11 + (param_3 - (int)puVar7))) {
      return (uint *)0x0;
    }
    if ((int)(local_58 & 0xff) < (int)(uVar11 + 1)) {
      for (iVar6 = (uVar11 - (local_58 & 0xff)) + 1; iVar6 != 0; iVar6 = iVar6 + -1) {
        puVar7 = (uint *)((int)puVar7 + -1);
        uVar12 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
                 *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) &
                 0xffffff00 | 0x30;
        uVar3 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
        *puVar7 = uVar12 >> uVar3 | uVar12 << 0x20 - uVar3;
      }
    }
    uVar3 = local_58 & 0xff;
    uVar12 = (int)&local_58 + uVar3 + 1;
    while (uVar3 = uVar3 - 1, uVar3 != 0) {
      uVar12 = uVar12 - 1;
      puVar7 = (uint *)((int)puVar7 + -1);
      uVar5 = (*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
              *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) & 0xff |
              (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
              *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00;
      uVar4 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
      *puVar7 = uVar5 >> uVar4 | uVar5 << 0x20 - uVar4;
    }
    if ((uVar11 != 0) || (uVar9 != 0)) {
      puVar7 = (uint *)((int)puVar7 + -1);
      uVar11 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
               *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00
               | 0x2e;
      uVar3 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
      *puVar7 = uVar11 >> uVar3 | uVar11 << 0x20 - uVar3;
    }
    uVar3 = (int)&local_58 + 1U & 3;
    puVar8 = (uint *)((int)puVar7 + -1);
    uVar11 = (local_58 >> uVar3 * 8 | local_58 << uVar3 * -8 + 0x20) & 0xff |
             (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
             *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) & 0xffffff00;
    uVar3 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
    *puVar8 = uVar11 >> uVar3 | uVar11 << 0x20 - uVar3;
    if ((local_5c & 0xff) == 0) {
      if (uVar10 == 1) {
        puVar8 = (uint *)((int)puVar7 + -2);
        uVar11 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                 *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) &
                 0xffffff00 | 0x2b;
        uVar3 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
        *puVar8 = uVar11 >> uVar3 | uVar11 << 0x20 - uVar3;
      }
      else if (uVar10 == 2) {
        puVar8 = (uint *)((int)puVar7 + -2);
        uVar11 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                 *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) &
                 0xffffff00 | 0x20;
        uVar3 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
        *puVar8 = uVar11 >> uVar3 | uVar11 << 0x20 - uVar3;
      }
    }
    else {
      puVar8 = (uint *)((int)puVar7 + -2);
      uVar11 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
               *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) & 0xffffff00
               | 0x2d;
      uVar3 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
      *puVar8 = uVar11 >> uVar3 | uVar11 << 0x20 - uVar3;
    }
  }
  else {
    if (uVar12 < 0x67) {
      if (uVar12 != 0x66) {
        return puVar8;
      }
    }
    else {
      if (uVar12 != 0x67) {
        return puVar8;
      }
LAB_02135fd0:
      if ((int)uVar11 < (int)(local_58 & 0xff)) {
        func_02136638(&local_5c,uVar11);
      }
      iVar6 = (int)sVar1;
      if ((iVar6 < -4) || ((int)uVar11 <= iVar6)) {
        if (uVar9 == 0) {
          uVar11 = local_58 & 0xff;
        }
        uVar11 = uVar11 - 1;
        if (uVar12 == 0x67) {
          uVar12 = 0x65;
        }
        else {
          uVar12 = 0x45;
        }
        goto LAB_02136050;
      }
      if (uVar9 == 0) {
        uVar11 = (local_58 & 0xff) - (iVar6 + 1);
        if ((int)uVar11 < 0) {
          uVar11 = 0;
        }
      }
      else {
        uVar11 = uVar11 - (iVar6 + 1);
      }
    }
LAB_0213630c:
    uVar3 = local_58 & 0xff;
    iVar6 = (uVar3 - (int)sVar1) + -1;
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    if ((int)uVar11 < iVar6) {
      func_02136638(&local_5c,uVar3 - (iVar6 - uVar11));
      uVar3 = local_58 & 0xff;
      iVar6 = (uVar3 - (int)sVar1) + -1;
      if (iVar6 < 0) {
        iVar6 = 0;
      }
    }
    iVar13 = sVar1 + 1;
    if (iVar13 < 0) {
      iVar13 = 0;
    }
    if (iRam02136634 < iVar13 + iVar6) {
      return (uint *)0x0;
    }
    uVar3 = (int)&local_58 + uVar3 + 1;
    iVar14 = 0;
    if (0 < (int)(uVar11 - iVar6)) {
      do {
        puVar8 = (uint *)((int)puVar8 + -1);
        iVar14 = iVar14 + 1;
        uVar4 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) & 0xffffff00
                | 0x30;
        uVar12 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
        *puVar8 = uVar4 >> uVar12 | uVar4 << 0x20 - uVar12;
      } while (iVar14 < (int)(uVar11 - iVar6));
    }
    for (iVar14 = 0; (iVar14 < iVar6 && (iVar14 < (int)(local_58 & 0xff))); iVar14 = iVar14 + 1) {
      uVar3 = uVar3 - 1;
      puVar8 = (uint *)((int)puVar8 + -1);
      uVar4 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) & 0xff |
              (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
              *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) & 0xffffff00;
      uVar12 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
      *puVar8 = uVar4 >> uVar12 | uVar4 << 0x20 - uVar12;
    }
    for (; iVar14 < iVar6; iVar14 = iVar14 + 1) {
      puVar8 = (uint *)((int)puVar8 + -1);
      uVar4 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
              *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) & 0xffffff00 |
              0x30;
      uVar12 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
      *puVar8 = uVar4 >> uVar12 | uVar4 << 0x20 - uVar12;
    }
    if ((uVar11 != 0) || (uVar9 != 0)) {
      puVar8 = (uint *)((int)puVar8 + -1);
      uVar12 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
               *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) & 0xffffff00
               | 0x2e;
      uVar11 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
      *puVar8 = uVar12 >> uVar11 | uVar12 << 0x20 - uVar11;
    }
    if (iVar13 == 0) {
      puVar8 = (uint *)((int)puVar8 + -1);
      uVar11 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
               *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) & 0xffffff00
               | 0x30;
      uVar3 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
      *puVar8 = uVar11 >> uVar3 | uVar11 << 0x20 - uVar3;
    }
    else {
      iVar6 = 0;
      if (0 < (int)(iVar13 - (local_58 & 0xff))) {
        do {
          puVar8 = (uint *)((int)puVar8 + -1);
          uVar12 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                   *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) &
                   0xffffff00 | 0x30;
          uVar11 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
          *puVar8 = uVar12 >> uVar11 | uVar12 << 0x20 - uVar11;
          iVar6 = iVar6 + 1;
        } while (iVar6 < (int)(iVar13 - (local_58 & 0xff)));
      }
      for (; iVar6 < iVar13; iVar6 = iVar6 + 1) {
        uVar3 = uVar3 - 1;
        puVar8 = (uint *)((int)puVar8 + -1);
        uVar12 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                 *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) & 0xff |
                 (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                 *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) &
                 0xffffff00;
        uVar11 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
        *puVar8 = uVar12 >> uVar11 | uVar12 << 0x20 - uVar11;
      }
    }
    if ((local_5c & 0xff) == 0) {
      if (uVar10 == 1) {
        puVar8 = (uint *)((int)puVar8 + -1);
        uVar11 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                 *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) &
                 0xffffff00 | 0x2b;
        uVar3 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
        *puVar8 = uVar11 >> uVar3 | uVar11 << 0x20 - uVar3;
      }
      else if (uVar10 == 2) {
        puVar8 = (uint *)((int)puVar8 + -1);
        uVar11 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                 *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) &
                 0xffffff00 | 0x20;
        uVar3 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
        *puVar8 = uVar11 >> uVar3 | uVar11 << 0x20 - uVar3;
      }
    }
    else {
      puVar8 = (uint *)((int)puVar8 + -1);
      uVar11 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
               *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) & 0xffffff00
               | 0x2d;
      uVar3 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
      *puVar8 = uVar11 >> uVar3 | uVar11 << 0x20 - uVar3;
    }
  }
  return puVar8;
}

