/* Decompiled C draft; module arm9; ROM address 02130ccc. No matching claim. */
#include "types.h"
#include "deps/02130ccc_func_02130ccc.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

longlong func_02130ccc(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  longlong lVar15;
  
  if (-1 < (int)(param_2 ^ param_4)) {
    uVar10 = param_1 - param_3;
    uVar3 = param_1;
    uVar13 = param_2;
    uVar7 = param_3;
    uVar8 = param_4;
    if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
      uVar13 = param_2 - (param_4 + (param_3 > param_1)) ^ 0x80000000;
      uVar7 = param_3 + uVar10;
      uVar8 = param_4 + uVar13 + (uint)CARRY4(param_3,uVar10);
      uVar3 = param_1 - uVar10;
      uVar13 = param_2 - (uVar13 + (param_1 < uVar10));
    }
    uVar11 = uVar13 >> 0x14;
    uVar13 = uVar13 << 0xb;
    uVar9 = uVar3 >> 0x15;
    uVar6 = uVar13 | 0x80000000 | uVar9;
    uVar10 = uVar3 * 0x800;
    if (uVar11 * 0x200000 == 0 || uVar11 * 0x200000 == -0x200000) {
      uVar14 = 0x80000000;
      if (uVar11 < 0x800) {
        uVar14 = 0;
      }
      if ((uVar11 & 0xfffff7ff) == 0) {
        if (uVar10 != 0 || ((uVar13 & 0x7fffffff) != 0 || uVar9 != 0)) {
          uVar11 = 1;
          uVar6 = uVar13 & 0x7fffffff | uVar9;
          uVar13 = uVar8 << 0xb | uVar7 >> 0x15;
          iVar12 = (uVar8 >> 0x14) * 0x200000;
          uVar9 = uVar8 >> 0x14 & 0x7ff | uVar14 >> 0x14;
          if (iVar12 == 0 || iVar12 == -0x200000) goto LAB_02130fe8;
          uVar13 = uVar13 | 0x80000000;
          uVar11 = uVar14 >> 0x14 | 1;
          goto LAB_02130d34;
        }
        uVar13 = uVar8 << 0xb;
        iVar12 = (uVar8 >> 0x14) * 0x200000;
        if (iVar12 == 0) {
          if (uVar7 << 0xb != 0 || ((uVar13 & 0x7fffffff) != 0 || uVar7 >> 0x15 != 0))
          goto LAB_021310a0;
          goto LAB_021311ac;
        }
        if (iVar12 != -0x200000) {
LAB_021310a0:
          return CONCAT44(uVar8,uVar7);
        }
        if (uVar7 << 0xb == 0 && ((uVar13 & 0x7fffffff) == 0 && uVar7 >> 0x15 == 0))
        goto LAB_021310dc;
      }
      else if (uVar10 == 0 && ((uVar13 & 0x7fffffff) == 0 && uVar9 == 0)) {
        uVar13 = uVar8 << 0xb;
        iVar12 = (uVar8 >> 0x14) * 0x200000;
        if ((iVar12 == 0) || (iVar12 != -0x200000)) goto LAB_021310dc;
        if ((uVar7 & 0x1fffff) == 0 && ((uVar13 & 0x7fffffff) == 0 && uVar7 >> 0x15 == 0))
        goto LAB_02131174;
      }
      else {
        if ((uVar13 & 0x40000000) == 0) {
LAB_02131174:
          puVar4 = (uint *)GetAlphaFlagsRef();
          uVar13 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
                   *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
          if ((uVar13 & 0x100) == 0) {
            *puVar4 = uVar13 | 1;
            return 0x7fffffffffffffff;
          }
          goto LAB_021311f8;
        }
        uVar13 = uVar8 << 0xb;
        iVar12 = (uVar8 >> 0x14) * 0x200000;
        if (iVar12 == 0) {
          return 0x7fffffffffffffff;
        }
        if (iVar12 != -0x200000) {
          return 0x7fffffffffffffff;
        }
        if ((uVar7 & 0x1fffff) == 0 && ((uVar13 & 0x7fffffff) == 0 && uVar7 >> 0x15 == 0)) {
          return 0x7fffffffffffffff;
        }
      }
LAB_02131128:
      if ((uVar13 & 0x40000000) != 0) {
        return 0x7fffffffffffffff;
      }
      puVar4 = (uint *)GetAlphaFlagsRef();
      uVar13 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
               *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
      if ((uVar13 & 0x100) == 0) {
        *puVar4 = uVar13 | 1;
        return 0x7fffffffffffffff;
      }
LAB_021311f8:
      lVar15 = func_0213406c(param_1,param_2,param_3,param_4);
      return lVar15;
    }
    uVar9 = uVar8 >> 0x14;
    uVar13 = uVar8 << 0xb | 0x80000000 | uVar7 >> 0x15;
    if ((uVar9 & 0x7ff) == 0) {
LAB_02130fe8:
      if (uVar9 < 0x800) {
        uVar14 = 0;
      }
      else {
        uVar14 = 0x80000000;
      }
      uVar11 = uVar11 & 0xfffff7ff;
      if ((uVar9 & 0xfffff7ff) != 0) {
        if (uVar7 << 0xb == 0 && (uVar13 & 0x7fffffff) == 0) {
LAB_021310dc:
          return (ulonglong)(uVar14 | uRam02131228) << 0x20;
        }
        goto LAB_02131128;
      }
      if (uVar7 << 0xb == 0 && (uVar13 & 0x7fffffff) == 0) {
        if (-1 < (int)uVar6) {
          uVar11 = uVar11 - 1;
        }
        return CONCAT44(uVar14 | uVar6 * 2 >> 0xc | uVar11 << 0x14,uVar3 & 0x1fffff | uVar6 << 0x15)
        ;
      }
      uVar13 = uVar13 & 0x7fffffff;
      uVar11 = uVar11 | uVar14 >> 0x14;
      uVar9 = uVar14 >> 0x14 | 1;
    }
LAB_02130d34:
    uVar3 = uVar7 * 0x800;
    uVar9 = uVar11 - uVar9;
    if (uVar9 == 0) {
      uVar7 = uVar10 + uVar7 * -0x800;
      uVar6 = uVar6 - (uVar13 + (uVar10 < uVar3));
      if (uVar6 == 0 && uVar7 == 0) {
LAB_021311ac:
        uVar13 = GetAlphaFlagsRef();
        uVar13 = *(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                 *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20;
        if ((uVar13 & 0x800000) == 0) {
          return 0;
        }
        if ((uVar13 & 0x400000) == 0) {
          return -0x8000000000000000;
        }
        return 0;
      }
      uVar13 = (uVar11 & 0x800) << 0x14;
      uVar11 = uVar11 & 0xfffff7ff;
      if ((int)uVar6 < 0) {
        if (-1 < (int)uVar6) {
          uVar11 = uVar11 - 1;
        }
        goto LAB_02130f04;
      }
      uVar3 = uVar7;
      if (uVar6 == 0) {
        uVar11 = uVar11 - 0x20;
        uVar3 = 0;
        uVar6 = uVar7;
        if (-1 < (int)uVar7) goto LAB_02130ea8;
      }
      else {
LAB_02130ea8:
        uVar7 = 0x20 - LZCOUNT(uVar6);
        uVar6 = uVar6 << LZCOUNT(uVar6) | uVar3 >> (uVar7 & 0xff);
        uVar7 = 0x20 - uVar7;
        uVar3 = uVar3 << (uVar7 & 0xff);
        uVar11 = uVar11 - uVar7;
      }
      uVar7 = uVar3;
      if ((int)uVar11 < 1) {
        iVar12 = -uVar11;
        uVar7 = iVar12 + 0xc;
        if (0x1f < (int)uVar7) {
          uVar3 = uVar6;
        }
        if (iVar12 + -0x14 < 0 == SBORROW4(uVar7,0x20)) {
          uVar6 = 0;
          uVar7 = iVar12 - 0x14;
        }
        return CONCAT44(uVar13 | uVar6 >> (uVar7 & 0xff),
                        uVar3 >> (uVar7 & 0xff) | uVar6 << (0x20 - uVar7 & 0xff));
      }
LAB_02130f04:
      return CONCAT44(uVar13 | uVar6 * 2 >> 0xc | uVar11 << 0x14,uVar7 >> 0xb | uVar6 << 0x15);
    }
    if ((int)uVar9 < 0x21) {
      uVar7 = uVar3 >> (uVar9 & 0xff) | uVar13 << (0x20 - uVar9 & 0xff);
      if (uVar3 << (0x20 - uVar9 & 0xff) != 0) {
        uVar7 = uVar7 | 1;
      }
      uVar13 = (uVar13 >> (uVar9 & 0xff)) + (uint)(uVar10 < uVar7);
    }
    else {
      if (0x37 < (int)uVar9) {
        uVar9 = 0x3f;
      }
      uVar7 = uVar13 >> (uVar9 - 0x20 & 0xff);
      if (uVar3 != 0 || uVar13 << (0x20 - (uVar9 - 0x20) & 0xff) != 0) {
        uVar7 = uVar7 | 1;
      }
      uVar13 = (uint)(uVar10 < uVar7);
    }
    uVar6 = uVar6 - uVar13;
    uVar10 = uVar10 - uVar7;
    if ((int)uVar6 < 0) goto LAB_02130d98;
    uVar3 = uVar11 & 0xfffff7ff;
    uVar13 = uVar10;
    if (uVar6 == 0) {
      uVar3 = uVar3 - 0x20;
      uVar13 = 0;
      uVar6 = uVar10;
      if (-1 < (int)uVar10) goto LAB_02130f48;
    }
    else {
LAB_02130f48:
      uVar7 = 0x20 - LZCOUNT(uVar6);
      uVar6 = uVar6 << LZCOUNT(uVar6) | uVar13 >> (uVar7 & 0xff);
      uVar7 = 0x20 - uVar7;
      uVar3 = uVar3 - uVar7;
      uVar13 = uVar13 << (uVar7 & 0xff);
    }
    uVar10 = uVar13;
    if ((int)uVar3 < 1) {
      iVar12 = -uVar3;
      uVar13 = iVar12 + 0xc;
      if (0x1f < (int)uVar13) {
        uVar10 = uVar6;
      }
      if (iVar12 + -0x14 < 0 == SBORROW4(uVar13,0x20)) {
        uVar6 = 0;
        uVar13 = iVar12 - 0x14;
      }
      return CONCAT44((uVar11 & 0x800) << 0x14 | uVar6 >> (uVar13 & 0xff),
                      uVar10 >> (uVar13 & 0xff) | uVar6 << (0x20 - uVar13 & 0xff));
    }
    uVar11 = uVar3 | uVar11 & 0x800;
LAB_02130d98:
    uVar13 = uVar10 << 0x15;
    uVar3 = uVar10 >> 0xb | uVar6 << 0x15;
    uVar7 = uVar6 * 2 >> 0xc | uVar11 << 0x14;
    if (uVar13 == 0) {
      return CONCAT44(uVar7,uVar3);
    }
    puVar4 = (uint *)GetAlphaFlagsRef();
    uVar8 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
            *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
    if ((uVar8 & 0x1000) != 0) {
      lVar15 = func_0213412c(uVar3,uVar7,uRam02131230);
      return lVar15;
    }
    *puVar4 = uVar8 | 0x10;
    if ((uVar8 & 0x800000) != 0) {
      if ((uVar8 & 0x400000) == 0) {
        return CONCAT44(uVar7 + CARRY4(uVar3,-((int)uVar7 >> 0x1f)),uVar3 + -((int)uVar7 >> 0x1f));
      }
      return CONCAT44(uVar7,uVar3);
    }
    if ((uVar8 & 0x400000) != 0) {
      if (-1 < (int)uVar7) {
        return CONCAT44(uVar7 + (0xfffffffe < uVar3),uVar3 + 1);
      }
      return CONCAT44(uVar7,uVar3);
    }
    if ((uVar13 & 0x80000000) == 0) {
      return CONCAT44(uVar7,uVar3);
    }
    if ((uVar13 & 0x7fffffff) != 0 || (uVar10 >> 0xb & 1) != 0) {
      return CONCAT44(uVar7 + (0xfffffffe < uVar3),uVar3 + 1);
    }
    return CONCAT44(uVar7,uVar3);
  }
  uVar8 = param_4 ^ 0x80000000;
  uVar10 = param_1 - param_3;
  iVar12 = param_2 - (uVar8 + (param_3 > param_1));
  uVar7 = param_1;
  uVar13 = param_2;
  uVar3 = param_3;
  if (param_2 <= uVar8 && (uint)(param_3 <= param_1) <= param_2 - uVar8) {
    uVar3 = param_3 + uVar10;
    uVar8 = uVar8 + iVar12 + (uint)CARRY4(param_3,uVar10);
    uVar7 = param_1 - uVar10;
    uVar13 = param_2 - (iVar12 + (uint)(param_1 < uVar10));
  }
  uVar11 = uVar13 >> 0x14;
  uVar13 = uVar13 << 0xb;
  uVar9 = uVar7 >> 0x15;
  uVar6 = uVar13 | 0x80000000 | uVar9;
  uVar10 = uVar7 * 0x800;
  if (uVar11 * 0x200000 == 0 || uVar11 * 0x200000 == -0x200000) {
    uVar14 = 0x80000000;
    if (uVar11 < 0x800) {
      uVar14 = 0;
    }
    if ((uVar11 & 0xfffff7ff) == 0) {
      if (uVar10 != 0 || ((uVar13 & 0x7fffffff) != 0 || uVar9 != 0)) {
        uVar11 = 1;
        uVar6 = uVar13 & 0x7fffffff | uVar9;
        uVar13 = uVar8 << 0xb | uVar3 >> 0x15;
        iVar12 = (uVar8 >> 0x14) * 0x200000;
        uVar9 = uVar8 >> 0x14 & 0x7ff | uVar14 >> 0x14;
        if (iVar12 == 0 || iVar12 == -0x200000) goto LAB_0212fa9c;
        uVar13 = uVar13 | 0x80000000;
        uVar11 = uVar14 >> 0x14 | 1;
        goto LAB_0212f8e8;
      }
      uVar13 = uVar8 << 0xb;
      iVar12 = (uVar8 >> 0x14) * 0x200000;
      if ((iVar12 == 0) || (iVar12 != -0x200000)) goto LAB_0212fbf4;
      if ((uVar3 & 0x1fffff) == 0 && ((uVar13 & 0x7fffffff) == 0 && uVar3 >> 0x15 == 0))
      goto LAB_0212fc30;
    }
    else if (uVar10 == 0 && ((uVar13 & 0x7fffffff) == 0 && uVar9 == 0)) {
      uVar13 = uVar8 << 0xb;
      iVar12 = (uVar8 >> 0x14) * 0x200000;
      if (((iVar12 == 0) || (iVar12 != -0x200000)) ||
         ((uVar3 & 0x1fffff) == 0 && ((uVar13 & 0x7fffffff) == 0 && uVar3 >> 0x15 == 0)))
      goto LAB_0212fc30;
    }
    else {
      if ((uVar13 & 0x40000000) == 0) {
        puVar4 = (uint *)GetAlphaFlagsRef();
        uVar13 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
                 *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
        if ((uVar13 & 0x100) == 0) {
          *puVar4 = uVar13 | 1;
          return 0x7fffffffffffffff;
        }
        goto LAB_0212fddc;
      }
      uVar13 = uVar8 << 0xb;
      iVar12 = (uVar8 >> 0x14) * 0x200000;
      if (((iVar12 == 0) || (iVar12 != -0x200000)) ||
         ((uVar3 & 0x1fffff) == 0 && ((uVar13 & 0x7fffffff) == 0 && uVar3 >> 0x15 == 0))) {
        return 0x7fffffffffffffff;
      }
    }
LAB_0212fc7c:
    if ((uVar13 & 0x40000000) != 0) {
      return 0x7fffffffffffffff;
    }
    puVar4 = (uint *)GetAlphaFlagsRef();
    uVar13 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
             *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
    if ((uVar13 & 0x100) == 0) {
      *puVar4 = uVar13 | 1;
      return 0x7fffffffffffffff;
    }
LAB_0212fddc:
    lVar15 = func_0213406c(param_1,param_2,param_3,param_4);
    return lVar15;
  }
  uVar9 = uVar8 >> 0x14;
  uVar13 = uVar8 << 0xb | 0x80000000 | uVar3 >> 0x15;
  if ((uVar9 & 0x7ff) == 0) {
LAB_0212fa9c:
    uVar8 = uVar3 * 0x800;
    if (uVar9 < 0x800) {
      uVar14 = 0;
    }
    else {
      uVar14 = 0x80000000;
    }
    uVar11 = uVar11 & 0xfffff7ff;
    if ((uVar9 & 0xfffff7ff) != 0) {
      if (uVar8 == 0 && (uVar13 & 0x7fffffff) == 0) {
LAB_0212fc30:
        return (ulonglong)(uVar14 | uRam0212fe0c) << 0x20;
      }
      goto LAB_0212fc7c;
    }
    if (uVar8 == 0 && (uVar13 & 0x7fffffff) == 0) {
      if (-1 < (int)uVar6) {
        uVar11 = uVar11 - 1;
      }
      return CONCAT44(uVar14 | uVar6 * 2 >> 0xc | uVar11 << 0x14,uVar7 & 0x1fffff | uVar6 << 0x15);
    }
    uVar13 = uVar13 & 0x7fffffff;
    if ((int)uVar6 < 0) {
      uVar11 = uVar11 | uVar14 >> 0x14;
      uVar9 = uVar14 >> 0x14 | 1;
      goto LAB_0212f8e8;
    }
    uVar7 = uVar10 + uVar8;
    bVar1 = CARRY4(uVar6 + uVar13,(uint)CARRY4(uVar10,uVar8));
    uVar3 = uVar6 + uVar13 + (uint)CARRY4(uVar10,uVar8);
    if (CARRY4(uVar6,uVar13) || bVar1) {
      uVar11 = uVar11 + 1;
      bVar2 = (byte)uVar3;
      uVar3 = (uint)(CARRY4(uVar6,uVar13) || bVar1) << 0x1f | uVar3 >> 1;
      uVar7 = (uint)(bVar2 & 1) << 0x1f | uVar7 >> 1;
    }
    if (-1 < (int)uVar3) {
      uVar11 = uVar11 - 1;
    }
    uVar13 = uVar7 >> 0xb | uVar3 << 0x15;
    uVar10 = uVar14 | uVar3 * 2 >> 0xc | uVar11 << 0x14;
    if (uVar7 << 0x15 == 0) {
      return CONCAT44(uVar10,uVar13);
    }
    puVar4 = (uint *)GetAlphaFlagsRef();
    uVar3 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
            *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
    if ((uVar3 & 0x1000) != 0) goto LAB_0212fdf8;
    uVar8 = uVar3 | 0x10;
    *puVar4 = uVar8;
    if ((uVar3 & 0x800000) != 0) goto LAB_0212fa30;
    if ((uVar3 & 0x400000) == 0) {
      if (uVar7 << 0x15 == 0) {
        return CONCAT44(uVar10,uVar13);
      }
      uVar3 = uVar7 >> 0xb & 1;
      if (uVar3 == 0) {
        return CONCAT44(uVar10,uVar13);
      }
LAB_0212fbf4:
      return CONCAT44(uVar8,uVar3);
    }
  }
  else {
LAB_0212f8e8:
    uVar3 = uVar3 << 0xb;
    uVar9 = uVar11 - uVar9;
    uVar7 = uVar11;
    if (uVar9 == 0) {
LAB_0212f940:
      uVar9 = uVar10 + uVar3;
      uVar8 = uVar6 + uVar13 + (uint)CARRY4(uVar10,uVar3);
      if (CARRY4(uVar6,uVar13) || CARRY4(uVar6 + uVar13,(uint)CARRY4(uVar10,uVar3))) {
LAB_0212f94c:
        uVar7 = uVar11 + 1;
        bVar2 = (byte)uVar8;
        uVar8 = uVar8 >> 1;
        uVar13 = (uint)(bVar2 & 1) << 0x1f | uVar9 >> 1;
        uVar9 = uVar9 & 1 | uVar13;
        if ((uVar7 & 0x7ff) == 0x7ff) {
          uVar3 = 0xffe00000;
          if (0x7ff < uVar7) {
            uVar3 = 0x80000000;
          }
          if ((int)(uVar11 - 0x7ff) < 0 != SBORROW4(uVar7,0x800)) {
            uVar3 = 0;
          }
          puVar4 = (uint *)GetAlphaFlagsRef();
          uVar7 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
                  *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
          if ((uVar7 & 0x400) != 0) {
            lVar15 = func_0213412c(uVar13 >> 0xb | uVar8 << 0x15,
                                   uVar8 * 2 >> 0xc | iRam0212fe14 << 0x14 | uVar3,uRam0212fe10);
            return lVar15;
          }
          *puVar4 = uVar7 | 0x14;
          uVar13 = uVar3 | uRam0212fe0c;
          if ((uVar7 & 0x800000) != 0) {
            if ((uVar7 & 0x400000) == 0) {
              iVar12 = -((int)uVar3 >> 0x1f);
              return CONCAT44((uVar13 - 1) + (uint)(iVar12 != 0),iVar12 + -1);
            }
            return CONCAT44(uVar13 - 1,0xffffffff);
          }
          if ((uVar7 & 0x400000) != 0) {
            return CONCAT44(uVar13 - ((int)uVar3 < 0),(int)uVar3 >> 0x1f);
          }
          return (ulonglong)uVar13 << 0x20;
        }
      }
    }
    else {
      if ((int)uVar9 < 0x21) {
        iVar12 = uVar3 << (0x20 - uVar9 & 0xff);
        uVar3 = uVar3 >> (uVar9 & 0xff) | uVar13 << (0x20 - uVar9 & 0xff);
        uVar13 = uVar13 >> (uVar9 & 0xff);
        if (iVar12 != 0) {
          uVar3 = uVar3 | 1;
        }
        goto LAB_0212f940;
      }
      if (0x37 < (int)uVar9) {
        uVar9 = 0x3f;
      }
      uVar14 = uVar13 >> (uVar9 - 0x20 & 0xff);
      if (uVar3 != 0 || uVar13 << (0x20 - (uVar9 - 0x20) & 0xff) != 0) {
        uVar14 = uVar14 | 1;
      }
      uVar9 = uVar10 + uVar14;
      uVar8 = uVar6 + CARRY4(uVar10,uVar14);
      if (CARRY4(uVar6,(uint)CARRY4(uVar10,uVar14))) goto LAB_0212f94c;
    }
    uVar3 = uVar9 << 0x15;
    uVar13 = uVar9 >> 0xb | uVar8 << 0x15;
    uVar10 = uVar8 * 2 >> 0xc | uVar7 << 0x14;
    if (uVar3 == 0) {
      return CONCAT44(uVar10,uVar13);
    }
    puVar4 = (uint *)GetAlphaFlagsRef();
    uVar7 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
            *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
    if ((uVar7 & 0x1000) != 0) {
LAB_0212fdf8:
      lVar15 = func_0213412c(uVar13,uVar10,uRam0212fe1c);
      return lVar15;
    }
    uVar8 = uVar7 | 0x10;
    *puVar4 = uVar8;
    if ((uVar7 & 0x800000) != 0) {
LAB_0212fa30:
      if ((uVar8 & 0x400000) != 0) {
        return CONCAT44(uVar10,uVar13);
      }
      if (-1 < (int)uVar10) {
        return CONCAT44(uVar10,uVar13);
      }
      goto LAB_0212f9e4;
    }
    if ((uVar7 & 0x400000) == 0) {
      if ((uVar3 & 0x80000000) == 0) {
        return CONCAT44(uVar10,uVar13);
      }
      if ((uVar3 & 0x7fffffff) == 0 && (uVar9 >> 0xb & 1) == 0) {
        return CONCAT44(uVar10,uVar13);
      }
      goto LAB_0212f9e4;
    }
  }
  if ((int)uVar10 < 0) {
    return CONCAT44(uVar10,uVar13);
  }
LAB_0212f9e4:
  iVar12 = uVar13 + 1;
  iVar5 = uVar10 + (0xfffffffe < uVar13);
  if ((uint)(iVar5 * 2) < 0xffe00000) {
    return CONCAT44(iVar5,iVar12);
  }
  if ((uVar8 & 0x400) != 0) {
    lVar15 = func_0213412c(iVar12,iVar5 + -0x60000000,uRam0212fe10);
    return lVar15;
  }
  *puVar4 = uVar8 | 0x14;
  return CONCAT44(iVar5,iVar12);
}

