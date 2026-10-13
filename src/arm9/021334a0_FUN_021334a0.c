/* Decompiled C draft; module arm9; ROM address 021334a0. No matching claim. */
#include "types.h"
#include "deps/021334a0_FUN_021334a0.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint FUN_021334a0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  uint uStack_34;
  
  uVar7 = param_2 ^ param_4;
  uVar11 = uRam02133d90 & param_2 >> 0x13;
  uStack_34 = param_1;
  if (uVar11 == 0 || uVar11 == uRam02133d90) {
    if (param_1 == 0 && (param_2 & 0x7fffffff) == 0) {
      if (param_3 == 0 && (param_4 & 0x7fffffff) == 0) goto code_r0x02133c94;
      uVar7 = param_4 & 0x7fffffff;
      uVar11 = uRam02133d90 * 0x80000;
      if (uVar7 != uVar11 && uVar7 < uVar11 || uVar7 == uVar11 && param_3 == 0) {
        return param_1;
      }
    }
    else {
      if (uVar11 != uRam02133d90) {
        iVar8 = param_2 << 0xc;
        if (iVar8 == 0) {
          uStack_34 = param_1 << LZCOUNT(param_1);
          uVar5 = uStack_34 >> 0xb;
          uStack_34 = uStack_34 << 0x15;
          uVar11 = (-0x14 - LZCOUNT(param_1)) * 2 | uVar7 >> 0x1f;
        }
        else {
          iVar13 = uVar11 - LZCOUNT(iVar8);
          uVar11 = iVar13 + 0x1f;
          uVar5 = (uint)(iVar8 << LZCOUNT(iVar8)) >> 0xb | param_1 >> (uVar11 & 0xff);
          uStack_34 = param_1 << (0x20 - uVar11 & 0xff);
          uVar11 = iVar13 * 2 | uVar7 >> 0x1f;
        }
        goto code_r0x021334c4;
      }
      if (param_1 == 0 && (param_2 & 0xfffff) == 0) {
        if ((param_4 & 0x7fffffff) < uRam02133d90 << 0x13) {
          return param_1;
        }
        if (param_3 == 0 && (param_4 & 0xfffff) == 0) goto code_r0x02133c94;
      }
      else {
        if ((param_2 & 0x80000) == 0) goto code_r0x02133c94;
        uVar7 = param_4 & 0x7fffffff;
        uVar11 = uRam02133d90 * 0x80000;
        if (uVar7 != uVar11 && uVar7 < uVar11 || uVar7 == uVar11 && param_3 == 0) {
          return param_1;
        }
      }
    }
code_r0x02133c78:
    if ((param_4 & 0x80000) != 0) {
      return param_3;
    }
code_r0x02133c94:
    puVar3 = (uint *)GetAlphaFlagsRef();
    uVar11 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
             *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
    if ((uVar11 & 0x100) != 0) {
      uVar11 = func_0213406c(param_1,param_2,param_3,param_4);
      return uVar11;
    }
    *puVar3 = uVar11 | 1;
    return uStack_34;
  }
  uVar5 = param_2 & ~(uRam02133d90 << 0x14) | 0x100000;
  uVar11 = uVar11 - ((int)uVar7 >> 0x1f);
code_r0x021334c4:
  uVar7 = uRam02133d90 & param_4 >> 0x13;
  if (uVar7 == 0 || uVar7 == uRam02133d90) {
    if (param_3 == 0 && (param_4 & 0x7fffffff) == 0) {
      puVar3 = (uint *)GetAlphaFlagsRef();
      uVar11 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
               *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
      if ((uVar11 & 0x200) != 0) {
        uVar11 = func_0213406c(param_1,param_2,param_3,param_4);
        return uVar11;
      }
      *puVar3 = uVar11 | 2;
      return 0;
    }
    if (uVar7 == uRam02133d90) {
      if (param_3 == 0 && (param_4 & 0xfffff) == 0) {
        return 0;
      }
      goto code_r0x02133c78;
    }
    iVar8 = param_4 << 0xc;
    if (iVar8 == 0) {
      iVar8 = LZCOUNT(param_3);
      param_3 = param_3 << iVar8;
      uVar6 = param_3 >> 0xb;
      param_3 = param_3 << 0x15;
      uVar7 = (-0x14 - iVar8) * 2;
    }
    else {
      iVar13 = uVar7 - LZCOUNT(iVar8);
      uVar7 = iVar13 + 0x1f;
      uVar6 = (uint)(iVar8 << LZCOUNT(iVar8)) >> 0xb | param_3 >> (uVar7 & 0xff);
      param_3 = param_3 << (0x20 - uVar7 & 0xff);
      uVar7 = iVar13 * 2;
    }
  }
  else {
    uVar6 = param_4 & ~(uRam02133d90 << 0x14) | 0x100000;
  }
  uVar11 = uVar11 - uVar7;
  bVar14 = uVar6 <= uVar5;
  if (uVar5 == uVar6) {
    bVar14 = param_3 <= uStack_34;
  }
  if (!bVar14) {
    bVar14 = CARRY4(uStack_34,uStack_34);
    uStack_34 = uStack_34 * 2;
    uVar5 = uVar5 * 2 + (uint)bVar14;
    uVar11 = uVar11 - 2;
  }
  uVar7 = (uint)*(byte *)((uVar6 >> 0xc) + 0x213357c);
  uVar2 = -param_3;
  iVar8 = uVar6 + (param_3 != 0);
  iVar13 = -iVar8;
  uVar7 = (uVar7 * iVar13 + 0x20000000 >> 7) * uVar7 >> 0xd;
  uVar7 = uVar7 * 0x4000 + (uVar7 * (uVar7 * (iVar8 * -0x400 | uVar2 >> 0x16) >> 0x10) >> 0x10);
  uVar9 = (uint)((ulonglong)(uVar5 << 10 | uStack_34 >> 0x16) * (ulonglong)uVar7 >> 0x20);
  uVar7 = (uint)((ulonglong)uVar7 *
                 (ulonglong)
                 (((uint)((ulonglong)uVar2 * (ulonglong)uVar9) >> 0x1a |
                  (iVar13 * uVar9 + (int)((ulonglong)uVar2 * (ulonglong)uVar9 >> 0x20)) * 0x40) +
                 uStack_34 * 4) >> 0x20);
  uVar6 = uVar7 + uVar9 * 0x1000000;
  uVar7 = (uVar9 >> 8) + (uint)CARRY4(uVar7,uVar9 * 0x1000000);
  if (0x7ff < (int)uVar11) {
    puVar3 = (uint *)GetAlphaFlagsRef();
    uVar5 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
            *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
    if ((uVar5 & 0x400) != 0) {
      uVar11 = func_0213412c(uVar6,(uVar7 | uVar11 * -0x80000000) +
                                   (uVar11 - 0x202 & 0xfffffffe) * 0x80000,uRam02133d94);
      return uVar11;
    }
    *puVar3 = uVar5 | 0x14;
    if ((int)(uVar11 << 0x1f) < 0) {
      if ((uVar5 & 0x400000) != 0) {
        return 0xffffffff;
      }
      return 0;
    }
    if ((uVar5 & 0x800000) != 0) {
      return 0xffffffff;
    }
    return 0;
  }
  uVar9 = uVar11 + 0x7fc;
  if (-1 < (int)uVar9) {
    uVar9 = (uVar7 | uVar11 << 0x1f) + (uVar9 & 0xfffffffe) * 0x80000;
    lVar1 = (ulonglong)uVar6 * (ulonglong)param_3 + ((ulonglong)(param_3 * uVar7) << 0x20);
    uVar11 = (uint)lVar1;
    iVar8 = -(iVar13 + (uint)(uVar2 != 0));
    iVar13 = uVar6 * iVar8 + (int)((ulonglong)lVar1 >> 0x20);
    if (iVar13 != uStack_34 * 0x100000 || uVar11 != 0) {
      iVar12 = iVar13 + iVar8 + (uint)CARRY4(uVar11,param_3);
      if ((int)(iVar12 + uStack_34 * -0x100000) < 0) {
        bVar14 = 0xfffffffe < uVar6;
        uVar6 = uVar6 + 1;
        uVar9 = uVar9 + bVar14;
        uVar11 = uVar11 + param_3;
        iVar13 = iVar12;
      }
      else if (iVar12 == uStack_34 * 0x100000 && uVar11 + param_3 == 0) goto LAB_02133630;
      puVar3 = (uint *)GetAlphaFlagsRef();
      uVar7 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
              *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
      if ((uVar7 & 0x1000) != 0) goto code_r0x02133d7c;
      *puVar3 = uVar7 | 0x10;
      if ((uVar7 & 0x800000) == 0) {
        if ((uVar7 & 0x400000) == 0) {
          if ((int)(iVar13 * 2 + (uint)CARRY4(uVar11,uVar11) + iVar8 +
                    (uint)CARRY4(uVar11 * 2,param_3) + uStack_34 * -0x200000) < 0) {
LAB_02133630:
            uVar9 = uVar9 + (0xfffffffe < uVar6);
            if (uVar9 * 2 < 0xffe00000) {
              return uVar6 + 1;
            }
            puVar3 = (uint *)GetAlphaFlagsRef();
            uVar11 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
                     *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
            if ((uVar11 & 0x400) != 0) {
              uVar11 = func_0213412c(0,uVar9 & 0x80000000 | 0x1ff00000,uRam02133d94);
              return uVar11;
            }
            *puVar3 = uVar11 | 0x14;
            return uVar6 + 1;
          }
        }
        else if ((uVar9 & 0x80000000) == 0) goto LAB_02133630;
      }
      else if (((uVar7 & 0x400000) == 0) && ((uVar9 & 0x80000000) != 0)) goto LAB_02133630;
    }
    return uVar6;
  }
  uVar4 = GetAlphaFlagsRef();
  if (((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
       *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) & 0x800) != 0) {
    uVar11 = func_0213412c(uVar6,(uVar7 | uVar11 << 0x1f) + (uVar11 + 0xdfc & 0xfffffffe) * 0x80000,
                           uRam02133d98);
    return uVar11;
  }
  uVar4 = ~((int)uVar9 >> 1);
  if (0x34 < (int)uVar4) {
    uVar9 = uVar11 << 0x1f;
    uStack_34 = 0;
    puVar3 = (uint *)GetAlphaFlagsRef();
    uVar11 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
             *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
    if ((uVar11 & 0x1000) == 0) {
      *puVar3 = uVar11 | 0x18;
      uVar11 = uVar11 & 0xc00000;
      if (uVar11 != 0 && uVar11 != 0xc00000) {
        uVar7 = (uint)(uVar11 == 0x400000 && uVar9 == 0);
        if (uVar11 != 0x400000 && uVar9 != 0) {
          uVar7 = uVar7 + 1;
        }
        return uVar7;
      }
      return 0;
    }
    goto code_r0x02133d7c;
  }
  if (uVar4 == 0x34) {
    uVar9 = uVar11 << 0x1f;
    uStack_34 = (uint)(uVar5 != -(iVar13 + (uint)(uVar2 != 0)) || uStack_34 != param_3);
    puVar3 = (uint *)GetAlphaFlagsRef();
    uVar7 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
            *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
    if ((uVar7 & 0x1000) == 0) {
      *puVar3 = uVar7 | 0x18;
      if ((uVar7 & 0x800000) != 0) {
        uVar5 = 0;
        if ((uVar7 & 0x400000) == 0) {
          uVar5 = uVar11 & 1;
        }
        return uVar5;
      }
      if ((uVar7 & 0x400000) != 0) {
        return uVar11 & 1 ^ 1;
      }
      return uStack_34;
    }
    goto code_r0x02133d7c;
  }
  if ((int)uVar4 < 0x14) {
    uVar5 = uStack_34 << (0x13 - uVar4 & 0xff);
    uVar9 = 0x14 - (0x13 - uVar4);
    uVar4 = 0x20 - uVar9;
    uStack_34 = uVar6 >> (uVar9 & 0xff) | uVar7 << (uVar4 & 0xff);
    uVar7 = uVar7 >> (0x20 - uVar4 & 0xff);
    uVar9 = uVar7 | uVar11 << 0x1f;
    uVar11 = 0;
  }
  else {
    uVar9 = uVar11 << 0x1f;
    uVar10 = 0x20 - (0x33 - uVar4);
    uVar5 = uVar5 << (0x33 - uVar4 & 0xff) | uStack_34 >> (uVar10 & 0xff);
    uVar10 = 0x20 - uVar10;
    uVar11 = uStack_34 << (uVar10 & 0xff);
    uStack_34 = (uVar6 >> 0x15 | uVar7 * 0x800) >> (0x1f - uVar10 & 0xff);
    uVar7 = 0;
  }
  lVar1 = (ulonglong)uStack_34 * (ulonglong)param_3 + ((ulonglong)(param_3 * uVar7) << 0x20);
  uVar6 = (uint)lVar1;
  iVar8 = -(iVar13 + (uint)(uVar2 != 0));
  uVar7 = uStack_34 * iVar8 + (int)((ulonglong)lVar1 >> 0x20);
  if (uVar7 == uVar5 && uVar6 == uVar11) {
    return uStack_34;
  }
  uVar4 = uVar6 + param_3;
  uVar7 = uVar7 + iVar8 + (uint)CARRY4(uVar6,param_3);
  if ((int)(uVar7 - uVar5) < 0) {
code_r0x0213399c:
    bVar14 = 0xfffffffe < uStack_34;
    uStack_34 = uStack_34 + 1;
    uVar9 = uVar9 + bVar14;
  }
  else {
    if (uVar7 == uVar5) {
      if (uVar4 == uVar11) goto code_r0x02133988;
      if (uVar4 < uVar11) goto code_r0x0213399c;
    }
    bVar14 = uVar4 < param_3;
    uVar4 = uVar4 + uVar2;
    uVar7 = uVar7 - (iVar8 + (uint)bVar14);
  }
  uVar6 = uVar4 * 2 + param_3;
  iVar8 = uVar7 * 2 + (uint)CARRY4(uVar4,uVar4) + iVar8 + (uint)CARRY4(uVar4 * 2,param_3);
  puVar3 = (uint *)GetAlphaFlagsRef();
  uVar7 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
          *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
  if ((uVar7 & 0x1000) == 0) {
    *puVar3 = uVar7 | 0x18;
    if ((uVar7 & 0x800000) != 0) {
      if ((uVar7 & 0x400000) == 0) {
        return uStack_34 - ((int)uVar9 >> 0x1f);
      }
      return uStack_34;
    }
    if ((uVar7 & 0x400000) != 0) {
      return uStack_34 - ((int)(uVar9 ^ 0x80000000) >> 0x1f);
    }
    iVar13 = uVar5 * 2 + (uint)CARRY4(uVar11,uVar11);
    if (-1 < iVar8 - iVar13) {
      if (iVar8 != iVar13) {
        return uStack_34;
      }
      if (uVar11 * 2 <= uVar6) {
        if (uVar6 != uVar11 * 2) {
          return uStack_34;
        }
        if ((uStack_34 & 1) == 0) {
          return uStack_34;
        }
      }
    }
code_r0x02133988:
    return uStack_34 + 1;
  }
code_r0x02133d7c:
  uVar11 = func_0213412c(uStack_34,uVar9,uRam02133da4);
  return uVar11;
}

