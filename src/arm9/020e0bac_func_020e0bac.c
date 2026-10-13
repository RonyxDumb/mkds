/* Decompiled C draft; module arm9; ROM address 020e0bac. No matching claim. */
#include "types.h"
#include "deps/020e0bac_func_020e0bac.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4
func_020e0bac(int param_1,undefined4 param_2,uint param_3,uint param_4,uint *param_5,uint *param_6,
             uint *param_7,undefined2 *param_8,undefined4 param_9)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar14;
  int iVar15;
  int iVar16;
  bool bVar17;
  uint uStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  uint uVar13;
  
  VecFx32_Subtract(param_2,param_1 + 0xf4);
  iVar5 = VecFx32_CrossProduct_0((uint)(uintptr_t)(&uStack_48),param_1 + 0x28);
  if (iVar5 < 1) {
    uVar13 = param_1 + 0x100U & 3;
    uVar12 = *(uint *)(param_1 + 0x100U & 0xfffffffc);
    uVar13 = uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20;
    if ((int)(iVar5 + uVar13 + param_3) < 0 != SBORROW4(iVar5,-(uVar13 + param_3))) {
      return 0;
    }
    if ((int)(iVar5 + uVar13) < 0 == SBORROW4(iVar5,-uVar13)) {
      uVar13 = 0x500;
    }
    else {
      uVar13 = 0x600;
    }
  }
  else {
    uVar13 = param_1 + 0x100U & 3;
    uVar12 = *(uint *)(param_1 + 0x100U & 0xfffffffc);
    uVar13 = uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20;
    if ((int)(uVar13 + param_3) < iVar5) {
      return 0;
    }
    if ((int)uVar13 < iVar5) {
      uVar13 = 0xa00;
    }
    else {
      uVar13 = 0x900;
    }
  }
  iVar6 = VecFx32_CrossProduct_0((uint)(uintptr_t)(&uStack_48),param_1 + 0x34);
  if (iVar6 < 1) {
    uVar12 = param_1 + 0x104U & 3;
    uVar14 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
    uVar12 = uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20;
    if ((int)(iVar6 + uVar12 + param_3) < 0 != SBORROW4(iVar6,-(uVar12 + param_3))) {
      return 0;
    }
    if ((int)(iVar6 + uVar12) < 0 == SBORROW4(iVar6,-uVar12)) {
      uVar13 = uVar13 | 0x50;
    }
    else {
      uVar13 = uVar13 | 0x60;
    }
  }
  else {
    uVar12 = param_1 + 0x104U & 3;
    uVar14 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
    uVar12 = uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20;
    if ((int)(uVar12 + param_3) < iVar6) {
      return 0;
    }
    if ((int)uVar12 < iVar6) {
      uVar13 = uVar13 | 0xa0;
    }
    else {
      uVar13 = uVar13 | 0x90;
    }
  }
  iVar7 = VecFx32_CrossProduct_0((uint)(uintptr_t)(&uStack_48),param_1 + 0x40);
  if (iVar7 < 1) {
    uVar12 = param_1 + 0x10cU & 3;
    uVar14 = *(uint *)(param_1 + 0x10cU & 0xfffffffc);
    uVar12 = uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20;
    if ((int)(iVar7 + uVar12 + param_3) < 0 != SBORROW4(iVar7,-(uVar12 + param_3))) {
      return 0;
    }
    if ((int)(iVar7 + uVar12) < 0 == SBORROW4(iVar7,-uVar12)) {
      uVar13 = uVar13 | 5;
    }
    else {
      uVar13 = uVar13 | 6;
    }
  }
  else {
    uVar12 = param_1 + 0x108U & 3;
    uVar14 = *(uint *)(param_1 + 0x108U & 0xfffffffc);
    uVar12 = uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20;
    if ((int)(uVar12 + param_3) < iVar7) {
      return 0;
    }
    if ((int)uVar12 < iVar7) {
      uVar13 = uVar13 | 10;
    }
    else {
      uVar13 = uVar13 | 9;
    }
  }
  if (((param_4 & 4) != 0) &&
     (uVar12 = param_1 + 0x13cU & 3, uVar14 = *(uint *)(param_1 + 0x13cU & 0xfffffffc),
     uVar14 >> uVar12 * 8 != 0 || uVar14 << uVar12 * -8 + 0x20 != 0)) {
    return 0;
  }
  if ((uVar13 & 0x100) == 0) {
    uVar12 = uVar13 & 0x800;
    if (uVar12 == 0) {
      uVar14 = param_1 + 0x100U & 3;
      uVar8 = *(uint *)(param_1 + 0x100U & 0xfffffffc);
      uVar14 = uVar8 >> uVar14 * 8 | uVar8 << uVar14 * -8 + 0x20;
    }
    else {
      uVar14 = param_1 + 0x100U & 3;
      uVar8 = *(uint *)(param_1 + 0x100U & 0xfffffffc);
      uVar14 = uVar8 >> uVar14 * 8 | uVar8 << uVar14 * -8 + 0x20;
    }
    if ((uVar13 & 0x10) == 0) {
      if ((uVar13 & 1) != 0) {
        if (uVar12 != 0) {
          uVar14 = -uVar14;
        }
        if ((uVar13 & 0x80) == 0) {
          uVar12 = param_1 + 0x104U & 3;
          uVar8 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
          uVar12 = uVar8 >> uVar12 * 8 | uVar8 << uVar12 * -8 + 0x20;
        }
        else {
          uVar12 = param_1 + 0x104U & 3;
          uVar8 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
          uVar12 = -(uVar8 >> uVar12 * 8 | uVar8 << uVar12 * -8 + 0x20);
        }
        uVar9 = func_020e16dc(param_3,iVar5 + uVar14,iVar6 + uVar12,uVar13);
        return uVar9;
      }
      bVar3 = false;
      if ((param_4 & 0x60) == 0) {
        bVar17 = false;
        uVar8 = param_1 + 0x110U & 3;
        uVar10 = *(uint *)(param_1 + 0x110U & 0xfffffffc);
        bVar2 = true;
        bVar4 = true;
        if (uVar10 >> uVar8 * 8 != 0 || uVar10 << uVar8 * -8 + 0x20 != 0) {
          if (uVar12 == 0) {
            uVar8 = param_1 + 0x2cU & 3;
            uVar10 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
            uVar8 = -(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
          }
          else {
            uVar8 = param_1 + 0x2cU & 3;
            uVar10 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
            uVar8 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
          }
          uVar10 = param_1 + 0x120U & 3;
          uVar11 = *(uint *)(param_1 + 0x120U & 0xfffffffc);
          if ((int)(uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) < (int)uVar8) {
            bVar17 = true;
          }
        }
        if (!bVar17) {
          bVar17 = false;
          uVar8 = param_1 + 0x114U & 3;
          uVar10 = *(uint *)(param_1 + 0x114U & 0xfffffffc);
          if (uVar10 >> uVar8 * 8 != 0 || uVar10 << uVar8 * -8 + 0x20 != 0) {
            if ((uVar13 & 0x80) == 0) {
              uVar8 = param_1 + 0x38U & 3;
              uVar10 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
              uVar8 = -(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
            }
            else {
              uVar8 = param_1 + 0x38U & 3;
              uVar10 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
              uVar8 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
            }
            uVar10 = param_1 + 0x120U & 3;
            uVar11 = *(uint *)(param_1 + 0x120U & 0xfffffffc);
            if ((int)(uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) < (int)uVar8) {
              bVar17 = true;
            }
          }
          if (!bVar17) {
            bVar2 = false;
          }
        }
        if (!bVar2) {
          bVar17 = false;
          uVar8 = param_1 + 0x118U & 3;
          uVar10 = *(uint *)(param_1 + 0x118U & 0xfffffffc);
          if (uVar10 >> uVar8 * 8 != 0 || uVar10 << uVar8 * -8 + 0x20 != 0) {
            if ((uVar13 & 8) == 0) {
              uVar8 = param_1 + 0x44U & 3;
              uVar10 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
              uVar8 = -(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
            }
            else {
              uVar8 = param_1 + 0x44U & 3;
              uVar10 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
              uVar8 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
            }
            uVar10 = param_1 + 0x120U & 3;
            uVar11 = *(uint *)(param_1 + 0x120U & 0xfffffffc);
            if ((int)(uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) < (int)uVar8) {
              bVar17 = true;
            }
          }
          if (!bVar17) {
            bVar4 = false;
          }
        }
        if (bVar4) {
          bVar3 = true;
        }
      }
      if (uVar12 != 0) {
        uVar14 = -uVar14;
      }
      iVar5 = iVar5 + uVar14;
      uVar12 = param_1 + 0x28U & 3;
      uVar8 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
      uVar14 = uVar13 & 0x80;
      bVar17 = uVar14 != 0;
      if (bVar17) {
        uVar14 = param_1 + 0x104U & 3;
        uVar10 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
        uVar14 = uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20;
      }
      lVar1 = (longlong)(int)(uVar8 >> uVar12 * 8 | uVar8 << uVar12 * -8 + 0x20) * (longlong)iVar5;
      if (bVar17) {
        iVar6 = iVar6 - uVar14;
      }
      else {
        uVar12 = param_1 + 0x104U & 3;
        uVar14 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
        uVar14 = uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20;
      }
      if (!bVar17) {
        iVar6 = iVar6 + uVar14;
      }
      uVar13 = uVar13 & 8;
      bVar17 = uVar13 != 0;
      uVar12 = uVar13;
      if (bVar17) {
        uVar12 = param_1 + 0x108U & 3;
        uVar14 = *(uint *)(param_1 + 0x108U & 0xfffffffc);
        uVar12 = uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20;
      }
      uStack_48 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      if (bVar17) {
        iVar7 = iVar7 - uVar12;
      }
      else {
        uVar12 = param_1 + 0x10cU & 3;
        uVar14 = *(uint *)(param_1 + 0x10cU & 0xfffffffc);
        uVar12 = uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20;
      }
      uVar14 = param_1 + 0x2cU & 3;
      uVar8 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
      if (!bVar17) {
        iVar7 = iVar7 + uVar12;
      }
      lVar1 = (longlong)(int)(uVar8 >> uVar14 * 8 | uVar8 << uVar14 * -8 + 0x20) * (longlong)iVar5;
      uStack_44 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar12 = param_1 + 0x30U & 3;
      uVar14 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) * (longlong)iVar5
      ;
      uStack_40 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar12 = param_1 + 0x34U & 3;
      uVar14 = *(uint *)(param_1 + 0x34U & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) * (longlong)iVar6
      ;
      uStack_3c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar12 = param_1 + 0x38U & 3;
      uVar14 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) * (longlong)iVar6
      ;
      uStack_38 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar12 = param_1 + 0x3cU & 3;
      uVar14 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) * (longlong)iVar6
      ;
      uStack_34 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      VecFx32_Add((uint)(uintptr_t)(&uStack_3c),(uint)(uintptr_t)(&uStack_48),&uStack_48);
      uVar12 = param_1 + 0x40U & 3;
      uVar14 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) * (longlong)iVar7
      ;
      uStack_3c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar12 = param_1 + 0x44U & 3;
      uVar14 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) * (longlong)iVar7
      ;
      uStack_38 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar12 = param_1 + 0x48U & 3;
      uVar14 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) * (longlong)iVar7
      ;
      uStack_34 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      VecFx32_Add((uint)(uintptr_t)(&uStack_3c),(uint)(uintptr_t)(&uStack_48),&uStack_48);
      uStack_48 = uStack_48 << 10;
      uStack_44 = uStack_44 << 10;
      uStack_40 = uStack_40 << 10;
      iVar5 = func_020d70ac((uint)(uintptr_t)(&uStack_48),&uStack_3c);
      if (iVar5 != param_3 * 0x400 &&
          (int)(iVar5 + param_3 * -0x400) < 0 == SBORROW4(iVar5,param_3 * 0x400)) {
        return 0;
      }
      if (iVar5 == 0) {
        uStack_3c = *(uint *)(param_1 + 0x34);
        uStack_38 = *(uint *)(param_1 + 0x38);
        uStack_34 = *(uint *)(param_1 + 0x3c);
        uStack_30 = (uint)((longlong)(int)uStack_3c * (longlong)(int)param_3) >> 0xc |
                    (int)((ulonglong)((longlong)(int)uStack_3c * (longlong)(int)param_3) >> 0x20) <<
                    0x14;
        uStack_2c = (uint)((longlong)(int)uStack_38 * (longlong)(int)param_3) >> 0xc |
                    (int)((ulonglong)((longlong)(int)uStack_38 * (longlong)(int)param_3) >> 0x20) <<
                    0x14;
        uStack_28 = (uint)((longlong)(int)uStack_34 * (longlong)(int)param_3) >> 0xc |
                    (int)((ulonglong)((longlong)(int)uStack_34 * (longlong)(int)param_3) >> 0x20) <<
                    0x14;
      }
      else {
        uStack_30 = (uint)((longlong)(int)uStack_3c * (longlong)(int)param_3) >> 0xc |
                    (int)((ulonglong)((longlong)(int)uStack_3c * (longlong)(int)param_3) >> 0x20) <<
                    0x14;
        uStack_2c = (uint)((longlong)(int)uStack_38 * (longlong)(int)param_3) >> 0xc |
                    (int)((ulonglong)((longlong)(int)uStack_38 * (longlong)(int)param_3) >> 0x20) <<
                    0x14;
        uStack_28 = (uint)((longlong)(int)uStack_34 * (longlong)(int)param_3) >> 0xc |
                    (int)((ulonglong)((longlong)(int)uStack_34 * (longlong)(int)param_3) >> 0x20) <<
                    0x14;
        uStack_48 = (int)uStack_48 >> 10;
        uStack_44 = (int)uStack_44 >> 10;
        uStack_40 = (int)uStack_40 >> 10;
        VecFx32_Subtract(&uStack_30,&uStack_48);
        param_3 = VecFx32_Norm((uint)(uintptr_t)(&uStack_30));
      }
      if (bVar3) {
        uVar12 = param_1 + 0x11cU & 3;
        uVar14 = *(uint *)(param_1 + 0x11cU & 0xfffffffc);
        if ((uVar14 >> uVar12 * 8 == 0 && uVar14 << uVar12 * -8 + 0x20 == 0) || (uVar13 == 0)) {
          *param_8 = 0;
          param_6 = param_5;
        }
        else {
          *param_8 = 0x1e;
        }
      }
      else {
        *param_8 = 8;
      }
      uVar13 = (uint)(param_6 + 6) & 3;
      uVar12 = *(uint *)((uint)(param_6 + 6) & 0xfffffffc);
      if ((int)(uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20) <= (int)param_3) {
        param_6[6] = param_3;
        param_6[7] = uStack_3c;
        param_6[8] = uStack_38;
        param_6[9] = uStack_34;
      }
      uStack_30 = uStack_30 * 0x400;
      uStack_2c = uStack_2c << 10;
      uStack_28 = uStack_28 << 10;
      if ((int)(*(uint *)((uint)param_6 & 0xfffffffc) >> ((uint)param_6 & 3) * 8 |
               *(uint *)((uint)param_6 & 0xfffffffc) << ((uint)param_6 & 3) * -8 + 0x20) <
          (int)uStack_30) {
        *param_6 = uStack_30;
      }
      else {
        uVar13 = (uint)(param_6 + 3) & 3;
        uVar12 = *(uint *)((uint)(param_6 + 3) & 0xfffffffc);
        if ((int)uStack_30 < (int)(uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20)) {
          param_6[3] = uStack_30;
        }
      }
      uVar13 = (uint)(param_6 + 1) & 3;
      uVar12 = *(uint *)((uint)(param_6 + 1) & 0xfffffffc);
      if ((int)(uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20) < (int)uStack_2c) {
        param_6[1] = uStack_2c;
      }
      else {
        uVar13 = (uint)(param_6 + 4) & 3;
        uVar12 = *(uint *)((uint)(param_6 + 4) & 0xfffffffc);
        if ((int)uStack_2c < (int)(uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20)) {
          param_6[4] = uStack_2c;
        }
      }
      uVar13 = (uint)(param_6 + 2) & 3;
      uVar12 = *(uint *)((uint)(param_6 + 2) & 0xfffffffc);
      if ((int)(uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20) < (int)uStack_28) {
        param_6[2] = uStack_28;
      }
      else {
        uVar13 = (uint)(param_6 + 5) & 3;
        uVar12 = *(uint *)((uint)(param_6 + 5) & 0xfffffffc);
        if ((int)uStack_28 < (int)(uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20)) {
          param_6[5] = uStack_28;
        }
      }
      if (param_7 != (uint *)0x0) {
        uStack_48 = -uStack_48;
        uStack_44 = -uStack_44;
        uStack_40 = -uStack_40;
        uVar13 = (uint)(param_7 + 1) & 3;
        uVar12 = *(uint *)((uint)(param_7 + 1) & 0xfffffffc);
        if ((int)uStack_44 < (int)(uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20)) {
          *param_7 = uStack_48;
          param_7[1] = uStack_44;
          param_7[2] = uStack_40;
        }
      }
      if (bVar3) {
        func_020e0680(param_1,param_2,&uStack_3c,param_9);
      }
      return 1;
    }
    if ((uVar13 & 1) == 0) {
      if ((uVar13 & 8) == 0) {
        uVar8 = param_1 + 0x10cU & 3;
        uVar10 = *(uint *)(param_1 + 0x10cU & 0xfffffffc);
        uVar8 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
      }
      else {
        uVar8 = param_1 + 0x108U & 3;
        uVar10 = *(uint *)(param_1 + 0x108U & 0xfffffffc);
        uVar8 = -(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
      }
      if (uVar12 != 0) {
        uVar14 = -uVar14;
      }
      uVar9 = func_020e16dc(param_3,iVar7 + uVar8,iVar5 + uVar14,uVar13);
      return uVar9;
    }
LAB_020e0f14:
    func_020e1a80(param_3);
    return 1;
  }
  if ((uVar13 & 0x10) == 0) {
    if ((uVar13 & 0x80) == 0) {
      uVar12 = param_1 + 0x104U & 3;
      uVar14 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
      uVar12 = uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20;
      iVar15 = -(uVar12 + param_3 + iVar6);
    }
    else {
      uVar12 = param_1 + 0x104U & 3;
      uVar14 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
      uVar12 = uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20;
      iVar15 = (uVar12 + param_3) - iVar6;
    }
    if ((uVar13 & 1) == 0) {
      if ((uVar13 & 0x80) != 0) {
        uVar12 = -uVar12;
      }
      if ((uVar13 & 8) == 0) {
        uVar14 = param_1 + 0x10cU & 3;
        uVar8 = *(uint *)(param_1 + 0x10cU & 0xfffffffc);
        uVar14 = uVar8 >> uVar14 * 8 | uVar8 << uVar14 * -8 + 0x20;
      }
      else {
        uVar14 = param_1 + 0x108U & 3;
        uVar8 = *(uint *)(param_1 + 0x108U & 0xfffffffc);
        uVar14 = -(uVar8 >> uVar14 * 8 | uVar8 << uVar14 * -8 + 0x20);
      }
      uVar9 = func_020e16dc(param_3,iVar6 + uVar12,iVar7 + uVar14,uVar13);
      return uVar9;
    }
    iVar6 = iVar15;
    if (iVar15 < 1) {
      iVar6 = -iVar15;
    }
  }
  else {
    if ((uVar13 & 8) == 0) {
      uVar12 = param_1 + 0x10cU & 3;
      uVar14 = *(uint *)(param_1 + 0x10cU & 0xfffffffc);
      iVar7 = -((uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) + param_3 + iVar7);
    }
    else {
      uVar12 = param_1 + 0x108U & 3;
      uVar14 = *(uint *)(param_1 + 0x108U & 0xfffffffc);
      iVar7 = ((uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) + param_3) - iVar7;
    }
    iVar16 = iVar7;
    if ((uVar13 & 1) == 0) {
      if (iVar7 < 1) {
        iVar16 = -iVar7;
      }
LAB_020e0fec:
      func_020e1a80(param_3,iVar7,iVar16,uVar13);
      return 1;
    }
    if ((uVar13 & 0x800) == 0) {
      uVar12 = param_1 + 0x100U & 3;
      uVar14 = *(uint *)(param_1 + 0x100U & 0xfffffffc);
      iVar5 = -((uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) + param_3 + iVar5);
    }
    else {
      uVar12 = param_1 + 0x100U & 3;
      uVar14 = *(uint *)(param_1 + 0x100U & 0xfffffffc);
      iVar5 = ((uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) + param_3) - iVar5;
    }
    if ((uVar13 & 0x80) == 0) {
      uVar12 = param_1 + 0x104U & 3;
      uVar14 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
      iVar15 = -((uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) + param_3 + iVar6);
    }
    else {
      uVar12 = param_1 + 0x104U & 3;
      uVar14 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
      iVar15 = ((uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) + param_3) - iVar6;
    }
    if (iVar5 < 1) {
      iVar5 = -iVar5;
    }
    iVar6 = iVar15;
    if (iVar15 < 1) {
      iVar6 = -iVar15;
    }
    if (iVar7 < 1) {
      iVar16 = -iVar7;
    }
    if (iVar5 < iVar16) {
      if (iVar5 < iVar6) goto LAB_020e0f14;
    }
    else if (iVar16 < iVar6) goto LAB_020e0fec;
  }
  func_020e1a80(param_3,iVar15,iVar6,uVar13);
  return 1;
}

