/* Decompiled C draft; module arm9; ROM address 0212f884. No matching claim. */
#include "types.h"
#include "deps/0212f884_func_0212f884.h"

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint func_0212f884(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  
  if ((int)(param_2 ^ param_4) < 0) {
    uVar9 = param_4 ^ 0x80000000;
    uVar11 = param_1 - param_3;
    uVar3 = param_1;
    uVar5 = param_2;
    uVar7 = param_3;
    if (param_2 <= uVar9 && (uint)(param_3 <= param_1) <= param_2 - uVar9) {
      uVar5 = param_2 - (uVar9 + (param_3 > param_1)) ^ 0x80000000;
      uVar7 = param_3 + uVar11;
      uVar9 = uVar9 + uVar5 + (uint)CARRY4(param_3,uVar11);
      uVar3 = param_1 - uVar11;
      uVar5 = param_2 - (uVar5 + (param_1 < uVar11));
    }
    uVar12 = uVar5 >> 0x14;
    uVar5 = uVar5 << 0xb;
    uVar10 = uVar3 >> 0x15;
    uVar6 = uVar5 | 0x80000000 | uVar10;
    uVar11 = uVar3 * 0x800;
    if (uVar12 * 0x200000 == 0 || uVar12 * 0x200000 == -0x200000) {
      uVar8 = 0x80000000;
      if (uVar12 < 0x800) {
        uVar8 = 0;
      }
      if ((uVar12 & 0xfffff7ff) != 0) {
        if (uVar11 == 0 && ((uVar5 & 0x7fffffff) == 0 && uVar10 == 0)) {
          uVar5 = uVar9 << 0xb;
          iVar13 = (uVar9 >> 0x14) * 0x200000;
          if (iVar13 == 0) {
            return 0;
          }
          if (iVar13 != -0x200000) {
            return 0;
          }
          if ((uVar7 & 0x1fffff) == 0 && ((uVar5 & 0x7fffffff) == 0 && uVar7 >> 0x15 == 0)) {
LAB_02131174:
            puVar4 = (uint *)GetAlphaFlagsRef();
            uVar5 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
                    *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
            if ((uVar5 & 0x100) == 0) {
              *puVar4 = uVar5 | 1;
              return 0xffffffff;
            }
            goto LAB_021311f8;
          }
        }
        else {
          if ((uVar5 & 0x40000000) == 0) goto LAB_02131174;
          uVar5 = uVar9 << 0xb;
          iVar13 = (uVar9 >> 0x14) * 0x200000;
          if (iVar13 == 0) {
            return 0xffffffff;
          }
          if (iVar13 != -0x200000) {
            return 0xffffffff;
          }
          if ((uVar7 & 0x1fffff) == 0 && ((uVar5 & 0x7fffffff) == 0 && uVar7 >> 0x15 == 0)) {
            return 0xffffffff;
          }
        }
LAB_02131128:
        if ((uVar5 & 0x40000000) != 0) {
          return 0xffffffff;
        }
        puVar4 = (uint *)GetAlphaFlagsRef();
        uVar5 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
                *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
        if ((uVar5 & 0x100) == 0) {
          *puVar4 = uVar5 | 1;
          return 0xffffffff;
        }
LAB_021311f8:
        uVar5 = func_0213406c(param_1,param_2,param_3,param_4);
        return uVar5;
      }
      if (uVar11 == 0 && ((uVar5 & 0x7fffffff) == 0 && uVar10 == 0)) {
        uVar5 = uVar9 << 0xb;
        iVar13 = (uVar9 >> 0x14) * 0x200000;
        if (iVar13 == 0) {
          if (uVar7 << 0xb != 0 || ((uVar5 & 0x7fffffff) != 0 || uVar7 >> 0x15 != 0)) {
            return uVar7;
          }
          goto LAB_021311ac;
        }
        if (iVar13 != -0x200000) {
          return uVar7;
        }
        if (uVar7 << 0xb == 0 && ((uVar5 & 0x7fffffff) == 0 && uVar7 >> 0x15 == 0)) {
          return 0;
        }
        goto LAB_02131128;
      }
      uVar12 = 1;
      uVar6 = uVar5 & 0x7fffffff | uVar10;
      uVar5 = uVar9 << 0xb | uVar7 >> 0x15;
      iVar13 = (uVar9 >> 0x14) * 0x200000;
      uVar10 = uVar9 >> 0x14 & 0x7ff | uVar8 >> 0x14;
      if (iVar13 == 0 || iVar13 == -0x200000) goto LAB_02130fe8;
      uVar5 = uVar5 | 0x80000000;
      uVar12 = uVar8 >> 0x14 | 1;
    }
    else {
      uVar10 = uVar9 >> 0x14;
      uVar5 = uVar9 << 0xb | 0x80000000 | uVar7 >> 0x15;
      if ((uVar10 & 0x7ff) == 0) {
LAB_02130fe8:
        if (uVar10 < 0x800) {
          uVar9 = 0;
        }
        else {
          uVar9 = 0x80000000;
        }
        if ((uVar10 & 0xfffff7ff) != 0) {
          if (uVar7 << 0xb == 0 && (uVar5 & 0x7fffffff) == 0) {
            return 0;
          }
          goto LAB_02131128;
        }
        if (uVar7 << 0xb == 0 && (uVar5 & 0x7fffffff) == 0) {
          return uVar3 & 0x1fffff | uVar6 << 0x15;
        }
        uVar5 = uVar5 & 0x7fffffff;
        uVar12 = uVar12 & 0xfffff7ff | uVar9 >> 0x14;
        uVar10 = uVar9 >> 0x14 | 1;
      }
    }
    uVar3 = uVar7 * 0x800;
    uVar10 = uVar12 - uVar10;
    if (uVar10 == 0) {
      uVar7 = uVar11 + uVar7 * -0x800;
      uVar6 = uVar6 - (uVar5 + (uVar11 < uVar3));
      if (uVar6 == 0 && uVar7 == 0) {
LAB_021311ac:
        uVar5 = GetAlphaFlagsRef();
        uVar3 = 0;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
        if ((uVar5 & 0x800000) == 0) {
          return uVar3;
        }
        if ((uVar5 & 0x400000) != 0) {
          return uVar3;
        }
        return uVar3;
      }
      uVar12 = uVar12 & 0xfffff7ff;
      if ((int)uVar6 < 0) goto LAB_02130f04;
      uVar5 = uVar7;
      if (uVar6 == 0) {
        uVar12 = uVar12 - 0x20;
        uVar5 = 0;
        uVar6 = uVar7;
        if (-1 < (int)uVar7) goto LAB_02130ea8;
      }
      else {
LAB_02130ea8:
        uVar3 = 0x20 - LZCOUNT(uVar6);
        uVar6 = uVar6 << LZCOUNT(uVar6) | uVar5 >> (uVar3 & 0xff);
        uVar3 = 0x20 - uVar3;
        uVar5 = uVar5 << (uVar3 & 0xff);
        uVar12 = uVar12 - uVar3;
      }
      uVar7 = uVar5;
      if ((int)uVar12 < 1) {
        iVar13 = -uVar12;
        uVar3 = iVar13 + 0xc;
        if (0x1f < (int)uVar3) {
          uVar5 = uVar6;
        }
        if (iVar13 + -0x14 < 0 == SBORROW4(uVar3,0x20)) {
          uVar6 = 0;
          uVar3 = iVar13 - 0x14;
        }
        return uVar5 >> (uVar3 & 0xff) | uVar6 << (0x20 - uVar3 & 0xff);
      }
LAB_02130f04:
      return uVar7 >> 0xb | uVar6 << 0x15;
    }
    if ((int)uVar10 < 0x21) {
      uVar7 = uVar3 >> (uVar10 & 0xff) | uVar5 << (0x20 - uVar10 & 0xff);
      if (uVar3 << (0x20 - uVar10 & 0xff) != 0) {
        uVar7 = uVar7 | 1;
      }
      uVar5 = (uVar5 >> (uVar10 & 0xff)) + (uint)(uVar11 < uVar7);
    }
    else {
      if (0x37 < (int)uVar10) {
        uVar10 = 0x3f;
      }
      uVar7 = uVar5 >> (uVar10 - 0x20 & 0xff);
      if (uVar3 != 0 || uVar5 << (0x20 - (uVar10 - 0x20) & 0xff) != 0) {
        uVar7 = uVar7 | 1;
      }
      uVar5 = (uint)(uVar11 < uVar7);
    }
    uVar6 = uVar6 - uVar5;
    uVar11 = uVar11 - uVar7;
    if ((int)uVar6 < 0) goto LAB_02130d98;
    uVar3 = uVar12 & 0xfffff7ff;
    uVar5 = uVar11;
    if (uVar6 == 0) {
      uVar3 = uVar3 - 0x20;
      uVar5 = 0;
      uVar6 = uVar11;
      if (-1 < (int)uVar11) goto LAB_02130f48;
    }
    else {
LAB_02130f48:
      uVar7 = 0x20 - LZCOUNT(uVar6);
      uVar6 = uVar6 << LZCOUNT(uVar6) | uVar5 >> (uVar7 & 0xff);
      uVar7 = 0x20 - uVar7;
      uVar3 = uVar3 - uVar7;
      uVar5 = uVar5 << (uVar7 & 0xff);
    }
    uVar11 = uVar5;
    if ((int)uVar3 < 1) {
      iVar13 = -uVar3;
      uVar5 = iVar13 + 0xc;
      if (0x1f < (int)uVar5) {
        uVar11 = uVar6;
      }
      if (iVar13 + -0x14 < 0 == SBORROW4(uVar5,0x20)) {
        uVar6 = 0;
        uVar5 = iVar13 - 0x14;
      }
      return uVar11 >> (uVar5 & 0xff) | uVar6 << (0x20 - uVar5 & 0xff);
    }
    uVar12 = uVar3 | uVar12 & 0x800;
LAB_02130d98:
    uVar5 = uVar11 << 0x15;
    uVar3 = uVar11 >> 0xb | uVar6 << 0x15;
    uVar7 = uVar6 * 2 >> 0xc | uVar12 << 0x14;
    if (uVar5 == 0) {
      return uVar3;
    }
    puVar4 = (uint *)GetAlphaFlagsRef();
    uVar9 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
            *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
    if ((uVar9 & 0x1000) != 0) {
      uVar5 = func_0213412c(uVar3,uVar7,uRam02131230);
      return uVar5;
    }
    *puVar4 = uVar9 | 0x10;
    if ((uVar9 & 0x800000) != 0) {
      if ((uVar9 & 0x400000) != 0) {
        return uVar3;
      }
      return uVar3 - ((int)uVar7 >> 0x1f);
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar5 & 0x80000000) == 0) {
        return uVar3;
      }
      if ((uVar5 & 0x7fffffff) == 0 && (uVar11 >> 0xb & 1) == 0) {
        return uVar3;
      }
      return uVar3 + 1;
    }
    if ((int)uVar7 < 0) {
      return uVar3;
    }
    return uVar3 + 1;
  }
  uVar11 = param_1 - param_3;
  iVar13 = param_2 - (param_4 + (param_3 > param_1));
  uVar3 = param_1;
  uVar5 = param_2;
  uVar7 = param_3;
  uVar9 = param_4;
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    uVar7 = param_3 + uVar11;
    uVar9 = param_4 + iVar13 + (uint)CARRY4(param_3,uVar11);
    uVar3 = param_1 - uVar11;
    uVar5 = param_2 - (iVar13 + (uint)(param_1 < uVar11));
  }
  uVar12 = uVar5 >> 0x14;
  uVar5 = uVar5 << 0xb;
  uVar10 = uVar3 >> 0x15;
  uVar6 = uVar5 | 0x80000000 | uVar10;
  uVar11 = uVar3 * 0x800;
  if (uVar12 * 0x200000 == 0 || uVar12 * 0x200000 == -0x200000) {
    uVar8 = 0x80000000;
    if (uVar12 < 0x800) {
      uVar8 = 0;
    }
    if ((uVar12 & 0xfffff7ff) == 0) {
      if (uVar11 != 0 || ((uVar5 & 0x7fffffff) != 0 || uVar10 != 0)) {
        uVar12 = 1;
        uVar6 = uVar5 & 0x7fffffff | uVar10;
        uVar5 = uVar9 << 0xb | uVar7 >> 0x15;
        iVar13 = (uVar9 >> 0x14) * 0x200000;
        uVar10 = uVar9 >> 0x14 & 0x7ff | uVar8 >> 0x14;
        if (iVar13 == 0 || iVar13 == -0x200000) goto LAB_0212fa9c;
        uVar5 = uVar5 | 0x80000000;
        uVar12 = uVar8 >> 0x14 | 1;
        goto LAB_0212f8e8;
      }
      uVar5 = uVar9 << 0xb;
      iVar13 = (uVar9 >> 0x14) * 0x200000;
      if (iVar13 == 0) {
        return uVar7;
      }
      if (iVar13 != -0x200000) {
        return uVar7;
      }
      if ((uVar7 & 0x1fffff) == 0 && ((uVar5 & 0x7fffffff) == 0 && uVar7 >> 0x15 == 0)) {
        return 0;
      }
    }
    else if (uVar11 == 0 && ((uVar5 & 0x7fffffff) == 0 && uVar10 == 0)) {
      uVar5 = uVar9 << 0xb;
      iVar13 = (uVar9 >> 0x14) * 0x200000;
      if (iVar13 == 0) {
        return 0;
      }
      if (iVar13 != -0x200000) {
        return 0;
      }
      if ((uVar7 & 0x1fffff) == 0 && ((uVar5 & 0x7fffffff) == 0 && uVar7 >> 0x15 == 0)) {
        return 0;
      }
    }
    else {
      if ((uVar5 & 0x40000000) == 0) {
        puVar4 = (uint *)GetAlphaFlagsRef();
        uVar5 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
                *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
        if ((uVar5 & 0x100) == 0) {
          *puVar4 = uVar5 | 1;
          return 0xffffffff;
        }
        goto LAB_0212fddc;
      }
      uVar5 = uVar9 << 0xb;
      iVar13 = (uVar9 >> 0x14) * 0x200000;
      if (((iVar13 == 0) || (iVar13 != -0x200000)) ||
         ((uVar7 & 0x1fffff) == 0 && ((uVar5 & 0x7fffffff) == 0 && uVar7 >> 0x15 == 0))) {
        return 0xffffffff;
      }
    }
LAB_0212fc7c:
    if ((uVar5 & 0x40000000) != 0) {
      return 0xffffffff;
    }
    puVar4 = (uint *)GetAlphaFlagsRef();
    uVar5 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
            *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
    if ((uVar5 & 0x100) == 0) {
      *puVar4 = uVar5 | 1;
      return 0xffffffff;
    }
LAB_0212fddc:
    uVar5 = func_0213406c(param_1,param_2,param_3,param_4);
    return uVar5;
  }
  uVar10 = uVar9 >> 0x14;
  uVar5 = uVar9 << 0xb | 0x80000000 | uVar7 >> 0x15;
  if ((uVar10 & 0x7ff) == 0) {
LAB_0212fa9c:
    uVar9 = uVar7 * 0x800;
    if (uVar10 < 0x800) {
      uVar8 = 0;
    }
    else {
      uVar8 = 0x80000000;
    }
    uVar12 = uVar12 & 0xfffff7ff;
    if ((uVar10 & 0xfffff7ff) != 0) {
      if (uVar9 == 0 && (uVar5 & 0x7fffffff) == 0) {
        return 0;
      }
      goto LAB_0212fc7c;
    }
    if (uVar9 == 0 && (uVar5 & 0x7fffffff) == 0) {
      return uVar3 & 0x1fffff | uVar6 << 0x15;
    }
    uVar5 = uVar5 & 0x7fffffff;
    if ((int)uVar6 < 0) {
      uVar12 = uVar12 | uVar8 >> 0x14;
      uVar10 = uVar8 >> 0x14 | 1;
      goto LAB_0212f8e8;
    }
    uVar7 = uVar11 + uVar9;
    bVar1 = CARRY4(uVar6 + uVar5,(uint)CARRY4(uVar11,uVar9));
    uVar3 = uVar6 + uVar5 + (uint)CARRY4(uVar11,uVar9);
    if (CARRY4(uVar6,uVar5) || bVar1) {
      uVar12 = uVar12 + 1;
      bVar2 = (byte)uVar3;
      uVar3 = (uint)(CARRY4(uVar6,uVar5) || bVar1) << 0x1f | uVar3 >> 1;
      uVar7 = (uint)(bVar2 & 1) << 0x1f | uVar7 >> 1;
    }
    if (-1 < (int)uVar3) {
      uVar12 = uVar12 - 1;
    }
    uVar5 = uVar7 >> 0xb | uVar3 << 0x15;
    uVar3 = uVar8 | uVar3 * 2 >> 0xc | uVar12 << 0x14;
    if (uVar7 << 0x15 == 0) {
      return uVar5;
    }
    puVar4 = (uint *)GetAlphaFlagsRef();
    uVar9 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
            *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
    if ((uVar9 & 0x1000) != 0) goto LAB_0212fdf8;
    uVar11 = uVar9 | 0x10;
    *puVar4 = uVar11;
    if ((uVar9 & 0x800000) != 0) goto LAB_0212fa30;
    if ((uVar9 & 0x400000) == 0) {
      if (uVar7 << 0x15 == 0) {
        return uVar5;
      }
      uVar3 = uVar7 >> 0xb & 1;
      if (uVar3 != 0) {
        return uVar3;
      }
      return uVar5;
    }
  }
  else {
LAB_0212f8e8:
    uVar7 = uVar7 << 0xb;
    uVar10 = uVar12 - uVar10;
    uVar3 = uVar12;
    if (uVar10 == 0) {
LAB_0212f940:
      uVar10 = uVar11 + uVar7;
      uVar9 = uVar6 + uVar5 + (uint)CARRY4(uVar11,uVar7);
      if (CARRY4(uVar6,uVar5) || CARRY4(uVar6 + uVar5,(uint)CARRY4(uVar11,uVar7))) {
LAB_0212f94c:
        uVar3 = uVar12 + 1;
        bVar2 = (byte)uVar9;
        uVar9 = uVar9 >> 1;
        uVar5 = (uint)(bVar2 & 1) << 0x1f | uVar10 >> 1;
        uVar10 = uVar10 & 1 | uVar5;
        if ((uVar3 & 0x7ff) == 0x7ff) {
          uVar7 = 0xffe00000;
          if (0x7ff < uVar3) {
            uVar7 = 0x80000000;
          }
          if ((int)(uVar12 - 0x7ff) < 0 != SBORROW4(uVar3,0x800)) {
            uVar7 = 0;
          }
          puVar4 = (uint *)GetAlphaFlagsRef();
          uVar3 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
                  *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
          if ((uVar3 & 0x400) != 0) {
            uVar5 = func_0213412c(uVar5 >> 0xb | uVar9 << 0x15,
                                  uVar9 * 2 >> 0xc | iRam0212fe14 << 0x14 | uVar7,uRam0212fe10);
            return uVar5;
          }
          *puVar4 = uVar3 | 0x14;
          if ((uVar3 & 0x800000) == 0) {
            if ((uVar3 & 0x400000) == 0) {
              return 0;
            }
            return (int)uVar7 >> 0x1f;
          }
          if ((uVar3 & 0x400000) != 0) {
            return 0xffffffff;
          }
          return 0xffffffff - ((int)uVar7 >> 0x1f);
        }
      }
    }
    else {
      if ((int)uVar10 < 0x21) {
        iVar13 = uVar7 << (0x20 - uVar10 & 0xff);
        uVar7 = uVar7 >> (uVar10 & 0xff) | uVar5 << (0x20 - uVar10 & 0xff);
        uVar5 = uVar5 >> (uVar10 & 0xff);
        if (iVar13 != 0) {
          uVar7 = uVar7 | 1;
        }
        goto LAB_0212f940;
      }
      if (0x37 < (int)uVar10) {
        uVar10 = 0x3f;
      }
      uVar8 = uVar5 >> (uVar10 - 0x20 & 0xff);
      if (uVar7 != 0 || uVar5 << (0x20 - (uVar10 - 0x20) & 0xff) != 0) {
        uVar8 = uVar8 | 1;
      }
      uVar10 = uVar11 + uVar8;
      uVar9 = uVar6 + CARRY4(uVar11,uVar8);
      if (CARRY4(uVar6,(uint)CARRY4(uVar11,uVar8))) goto LAB_0212f94c;
    }
    uVar7 = uVar10 << 0x15;
    uVar5 = uVar10 >> 0xb | uVar9 << 0x15;
    uVar3 = uVar9 * 2 >> 0xc | uVar3 << 0x14;
    if (uVar7 == 0) {
      return uVar5;
    }
    puVar4 = (uint *)GetAlphaFlagsRef();
    uVar9 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
            *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
    if ((uVar9 & 0x1000) != 0) {
LAB_0212fdf8:
      uVar5 = func_0213412c(uVar5,uVar3,uRam0212fe1c);
      return uVar5;
    }
    uVar11 = uVar9 | 0x10;
    *puVar4 = uVar11;
    if ((uVar9 & 0x800000) != 0) {
LAB_0212fa30:
      if ((uVar11 & 0x400000) != 0) {
        return uVar5;
      }
      if (-1 < (int)uVar3) {
        return uVar5;
      }
      goto LAB_0212f9e4;
    }
    if ((uVar9 & 0x400000) == 0) {
      if ((uVar7 & 0x80000000) == 0) {
        return uVar5;
      }
      if ((uVar7 & 0x7fffffff) == 0 && (uVar10 >> 0xb & 1) == 0) {
        return uVar5;
      }
      goto LAB_0212f9e4;
    }
  }
  if ((int)uVar3 < 0) {
    return uVar5;
  }
LAB_0212f9e4:
  uVar7 = uVar5 + 1;
  iVar13 = uVar3 + (0xfffffffe < uVar5);
  if ((uint)(iVar13 * 2) < 0xffe00000) {
    return uVar7;
  }
  if ((uVar11 & 0x400) == 0) {
    *puVar4 = uVar11 | 0x14;
    return uVar7;
  }
  uVar5 = func_0213412c(uVar7,iVar13 + -0x60000000,uRam0212fe10);
  return uVar5;
}

