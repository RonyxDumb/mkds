/* Decompiled C draft; module arm9; ROM address 02130380. No matching claim. */
#include "types.h"
#include "deps/02130380_func_02130380.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint func_02130380(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
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
  int iVar14;
  uint uVar15;
  bool bVar16;
  uint uStack_38;
  
  uVar15 = (param_2 ^ param_4) & 0x80000000;
  uVar12 = param_2 >> 0x14;
  uVar7 = param_2 << 0xb;
  uVar11 = param_1 >> 0x15;
  uVar5 = uVar7 | uVar11;
  uVar6 = param_1 << 0xb;
  uVar9 = uVar6;
  if (uVar12 * 0x200000 == 0 || uVar12 * 0x200000 == -0x200000) {
    if ((uVar12 & 0xfffff7ff) != 0) {
      if (uVar6 == 0 && ((uVar7 & 0x7fffffff) == 0 && uVar11 == 0)) {
        uVar7 = param_4 << 0xb | param_3 >> 0x15;
        iVar13 = (param_4 >> 0x14) * 0x200000;
        if (iVar13 == 0) {
          if (uVar7 != 0 || param_3 << 0xb != 0) {
            return 0;
          }
LAB_0213083c:
          puVar4 = (uint *)GetAlphaFlagsRef();
          uVar7 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
                  *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
          if ((uVar7 & 0x100) == 0) {
            *puVar4 = uVar7 | 1;
            return 0xffffffff;
          }
          goto code_r0x02130a2c;
        }
        if (iVar13 != -0x200000) {
          return 0;
        }
        if (param_3 << 0xb == 0 && ((param_4 << 0xb & 0x7fffffff) == 0 && param_3 >> 0x15 == 0)) {
          return 0;
        }
      }
      else {
        if ((uVar7 & 0x40000000) == 0) goto LAB_0213083c;
        uVar7 = param_4 << 0xb;
        iVar13 = (param_4 >> 0x14) * 0x200000;
        if (iVar13 == 0) {
          return 0xffffffff;
        }
        if (iVar13 != -0x200000) {
          return 0xffffffff;
        }
        if ((param_3 & 0x1fffff) == 0 && ((uVar7 & 0x7fffffff) == 0 && param_3 >> 0x15 == 0)) {
          return 0xffffffff;
        }
      }
LAB_021307ec:
      if ((uVar7 & 0x40000000) != 0) {
        return 0xffffffff;
      }
      puVar4 = (uint *)GetAlphaFlagsRef();
      uVar7 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
              *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
      if ((uVar7 & 0x100) == 0) {
        *puVar4 = uVar7 | 1;
        return 0xffffffff;
      }
code_r0x02130a2c:
      uVar7 = func_0213406c(param_1,param_2,param_3,param_4);
      return uVar7;
    }
    if (uVar6 == 0 && ((uVar7 & 0x7fffffff) == 0 && uVar11 == 0)) {
      uVar7 = param_4 << 0xb;
      iVar13 = (param_4 >> 0x14) * 0x200000;
      if (iVar13 == 0) {
        return 0;
      }
      if (iVar13 != -0x200000) {
        return 0;
      }
      if ((param_3 & 0x1fffff) == 0 && ((uVar7 & 0x7fffffff) == 0 && param_3 >> 0x15 == 0))
      goto LAB_0213083c;
      goto LAB_021307ec;
    }
    uVar12 = 1;
    if (uVar5 == 0) {
      uVar12 = 0xffffffe1;
      uVar9 = 0;
      uVar5 = uVar6;
      if (-1 < (int)uVar6) goto LAB_021305a8;
    }
    else {
LAB_021305a8:
      uVar7 = 0x20 - LZCOUNT(uVar5);
      uVar6 = uVar5 << LZCOUNT(uVar5) | uVar9 >> (uVar7 & 0xff);
      uVar7 = 0x20 - uVar7;
      uVar9 = uVar9 << (uVar7 & 0xff);
      uVar12 = uVar12 - uVar7;
    }
    uVar7 = param_4 << 0xb | param_3 >> 0x15;
    uVar11 = param_3 << 0xb;
    iVar13 = (param_4 >> 0x14) * 0x200000;
    if (iVar13 == 0 || iVar13 == -0x200000) goto LAB_02130570;
    uVar8 = uVar7 | 0x80000000;
    uVar10 = param_4 >> 0x14 & 0xfffff7ff;
  }
  else {
    uVar12 = uVar12 & 0xfffff7ff;
    uVar7 = param_4 << 0xb | param_3 >> 0x15;
    uVar11 = param_3 << 0xb;
    iVar13 = (param_4 >> 0x14) * 0x200000;
    uVar6 = uVar5 | 0x80000000;
    if (iVar13 == 0 || iVar13 == -0x200000) {
LAB_02130570:
      uVar8 = param_3 << 0xb;
      if ((param_4 >> 0x14 & 0xfffff7ff) != 0) {
        if (uVar8 == 0 && (uVar7 & 0x7fffffff) == 0) {
          return 0;
        }
        goto LAB_021307ec;
      }
      if (uVar8 == 0 && (uVar7 & 0x7fffffff) == 0) {
        return 0;
      }
      uVar10 = 1;
      uVar11 = uVar8;
      if (uVar7 == 0) {
        uVar10 = 0xffffffe1;
        uVar11 = 0;
        uVar7 = uVar8;
        if ((int)uVar8 < 0) goto LAB_021303d4;
      }
      uVar5 = 0x20 - LZCOUNT(uVar7);
      uVar8 = uVar7 << LZCOUNT(uVar7) | uVar11 >> (uVar5 & 0xff);
      uVar5 = 0x20 - uVar5;
      uVar11 = uVar11 << (uVar5 & 0xff);
      uVar10 = uVar10 - uVar5;
    }
    else {
      uVar8 = uVar7 | 0x80000000;
      uVar10 = param_4 >> 0x14 & 0xfffff7ff;
    }
  }
LAB_021303d4:
  iVar13 = uVar10 + uVar12;
  lVar2 = (ulonglong)uVar8 * (ulonglong)uVar9 + ((ulonglong)uVar11 * (ulonglong)uVar9 >> 0x20);
  uVar12 = (uint)((ulonglong)lVar2 >> 0x20);
  lVar1 = (ulonglong)uVar11 * (ulonglong)uVar6;
  uVar7 = (uint)((ulonglong)lVar1 >> 0x20);
  lVar3 = (ulonglong)uVar8 * (ulonglong)uVar6 +
          (ulonglong)
          CONCAT14(CARRY4(uVar7,uVar12) ||
                   CARRY4(uVar7 + uVar12,(uint)CARRY4((uint)lVar1,(uint)lVar2)),
                   (int)((ulonglong)(lVar2 + lVar1) >> 0x20));
  uVar7 = (uint)lVar3;
  uVar6 = (uint)((ulonglong)lVar3 >> 0x20);
  if ((int)(lVar2 + lVar1) != 0 || (int)((ulonglong)uVar11 * (ulonglong)uVar9) != 0) {
    uVar7 = uVar7 | 1;
  }
  if (-1 < lVar3) {
    iVar13 = iVar13 + -1;
    bVar16 = CARRY4(uVar7,uVar7);
    uVar7 = uVar7 * 2;
    uVar6 = uVar6 * 2 + (uint)bVar16;
  }
  iVar14 = iVar13 + -0x3fe;
  if ((iVar14 < 0) || (iVar14 == 0)) {
    uVar12 = GetAlphaFlagsRef();
    if (((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
         *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) & 0x800) != 0) {
      uVar7 = func_0213412c(uVar7 >> 0xb | uVar6 << 0x15,
                            uVar15 | uVar6 * 2 >> 0xc | (iVar13 + 0x202) * 0x100000,uRam02130a64);
      return uVar7;
    }
    uVar12 = uVar15;
    if (iVar14 == -0x34) {
      uStack_38 = 0;
      puVar4 = (uint *)GetAlphaFlagsRef();
      uVar11 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
               *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
      if ((uVar11 & 0x1000) == 0) {
        uVar9 = uVar11 | 0x18;
        *puVar4 = uVar9;
        if ((uVar11 & 0x800000) == 0) {
          if ((uVar11 & 0x400000) == 0) {
            return (uint)(uVar7 != 0 || (uVar6 & 0x7fffffff) != 0);
          }
code_r0x02130754:
          if (uVar15 != 0) {
            return uStack_38;
          }
          return uStack_38 + 1;
        }
        goto code_r0x02130778;
      }
    }
    else if (iVar13 + -0x3ca < 0) {
      uStack_38 = 0;
      puVar4 = (uint *)GetAlphaFlagsRef();
      uVar7 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
              *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
      if ((uVar7 & 0x1000) == 0) {
        uVar9 = uVar7 | 0x18;
        *puVar4 = uVar9;
        if ((uVar7 & 0x800000) == 0) {
          if ((uVar7 & 0x400000) == 0) {
            return 0;
          }
          return (uint)(uVar15 == 0);
        }
        goto code_r0x02130778;
      }
    }
    else {
      uVar11 = iVar13 - 0x3ca;
      uVar12 = uVar6;
      if (0x1f < (int)uVar11) {
        uVar12 = uVar7;
      }
      uVar9 = uVar7;
      if (iVar13 + -0x3ea < 0 == SBORROW4(uVar11,0x20)) {
        uVar9 = 0;
        uVar11 = iVar13 - 0x3ea;
      }
      uVar5 = uVar12 << (uVar11 & 0xff) | uVar9 >> (0x20 - uVar11 & 0xff);
      if (uVar9 << (uVar11 & 0xff) != 0) {
        uVar5 = uVar5 | 1;
      }
      iVar14 = -iVar14;
      uVar12 = iVar14 + 0xc;
      if (0x1f < (int)uVar12) {
        uVar7 = uVar6;
      }
      if (iVar14 + -0x14 < 0 == SBORROW4(uVar12,0x20)) {
        uVar6 = 0;
        uVar12 = iVar14 - 0x14;
      }
      uStack_38 = uVar7 >> (uVar12 & 0xff) | uVar6 << (0x20 - uVar12 & 0xff);
      uVar12 = uVar15 | uVar6 >> (uVar12 & 0xff);
      if (uVar5 == 0) {
        return uStack_38;
      }
      puVar4 = (uint *)GetAlphaFlagsRef();
      uVar7 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
              *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
      if ((uVar7 & 0x1000) == 0) {
        uVar9 = uVar7 | 0x18;
        *puVar4 = uVar9;
        if ((uVar7 & 0x800000) == 0) {
          if ((uVar7 & 0x400000) == 0) {
            if ((uVar5 & 0x80000000) == 0) {
              return uStack_38;
            }
            if ((uVar5 & 0x7fffffff) == 0 && (uStack_38 & 1) == 0) {
              return uStack_38;
            }
            return uStack_38 + 1;
          }
          goto code_r0x02130754;
        }
code_r0x02130778:
        if ((uVar9 & 0x400000) != 0) {
          return uStack_38;
        }
        return uStack_38 - ((int)uVar12 >> 0x1f);
      }
    }
  }
  else {
    if (iVar14 * 0x100000 + 0x100000 < 0) {
      puVar4 = (uint *)GetAlphaFlagsRef();
      uVar12 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
               *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
      if ((uVar12 & 0x400) != 0) {
        uVar7 = func_0213412c(uVar7 >> 0xb | uVar6 << 0x15,
                              uVar15 | uVar6 * 2 >> 0xc | (iVar13 + -0x9fe) * 0x100000,uRam02130a60)
        ;
        return uVar7;
      }
      *puVar4 = uVar12 | 0x14;
      uVar7 = (int)(param_2 ^ param_4) >> 0x1f;
      if ((uVar12 & 0x800000) == 0) {
        if ((uVar12 & 0x400000) == 0) {
          return 0;
        }
        return uVar7;
      }
      if ((uVar12 & 0x400000) != 0) {
        return 0xffffffff;
      }
      return 0xffffffff - uVar7;
    }
    uVar11 = uVar7 << 0x15;
    uStack_38 = uVar7 >> 0xb | uVar6 << 0x15;
    uVar12 = uVar15 | uVar6 * 2 >> 0xc | iVar14 * 0x100000;
    if (uVar11 == 0) {
      return uStack_38;
    }
    puVar4 = (uint *)GetAlphaFlagsRef();
    uVar6 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
            *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
    if ((uVar6 & 0x1000) == 0) {
      *puVar4 = uVar6 | 0x10;
      if ((uVar6 & 0x800000) == 0) {
        if ((uVar6 & 0x400000) == 0) {
          if ((uVar11 & 0x80000000) == 0) {
            return uStack_38;
          }
          if ((uVar11 & 0x7fffffff) == 0 && (uVar7 >> 0xb & 1) == 0) {
            return uStack_38;
          }
        }
        else if (uVar15 != 0) {
          return uStack_38;
        }
      }
      else {
        if ((uVar6 & 0x400000) != 0) {
          return uStack_38;
        }
        if (uVar15 == 0) {
          return uStack_38;
        }
      }
      uVar7 = uStack_38 + 1;
      iVar13 = uVar12 + (0xfffffffe < uStack_38);
      if ((uint)(iVar13 * 2) < 0xffe00000) {
        return uVar7;
      }
      if ((uVar6 & 0x400) == 0) {
        *puVar4 = uVar6 | 0x14;
        return uVar7;
      }
      uVar7 = func_0213412c(uVar7,iVar13 + -0x60000000,uRam02130a60);
      return uVar7;
    }
  }
  uVar7 = func_0213412c(uStack_38,uVar12,uRam02130a6c);
  return uVar7;
}

