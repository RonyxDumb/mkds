/* Decompiled C draft; module arm9; ROM address 0213250c. No matching claim. */
#include "types.h"
#include "deps/0213250c_func_0213250c.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint func_0213250c(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  uVar5 = (param_1 ^ param_2) & 0x80000000;
  uVar6 = param_1 >> 0x17 & 0xff;
  if (uVar6 == 0 || uVar6 == 0xff) {
    if (uVar6 == 0) {
      if (param_1 << 9 != 0) {
        uVar2 = (param_1 << 9) >> 1;
        iVar8 = LZCOUNT(uVar2);
        uVar2 = uVar2 << iVar8;
        uVar6 = 1 - iVar8;
        uVar7 = param_2 >> 0x17 & 0xff;
        if (uVar7 == 0) goto LAB_021326dc;
        if (uVar7 == 0xff) goto LAB_02132674;
        uVar4 = param_2 << 8 | 0x80000000;
        goto LAB_02132544;
      }
      uVar6 = param_2 * 0x200;
      uVar2 = param_2 >> 0x17 & 0xff;
      if (uVar2 == 0) {
        return uVar5;
      }
      if (uVar2 < 0xff) {
        return uVar5;
      }
      if (uVar6 == 0) goto LAB_02132808;
    }
    else {
      if (param_1 << 9 == 0) {
        uVar6 = param_2 * 0x200;
        uVar2 = param_2 >> 0x17 & 0xff;
        if (uVar2 == 0) {
          if (uVar6 == 0) goto LAB_02132808;
          goto LAB_021327bc;
        }
        if (uVar2 < 0xff) goto LAB_021327bc;
        goto joined_r0x02132658;
      }
      if ((param_1 << 9 & 0x80000000) == 0) goto LAB_02132808;
      uVar6 = param_2 * 0x200;
      uVar5 = param_2 >> 0x17 & 0xff;
      if (uVar5 == 0) {
        return 0x7fffffff;
      }
      if (uVar5 < 0xff) {
        return 0x7fffffff;
      }
      if (uVar6 == 0) {
        return 0x7fffffff;
      }
    }
LAB_021327f4:
    if ((uVar6 & 0x80000000) != 0) {
      return 0x7fffffff;
    }
LAB_02132808:
    puVar3 = (uint *)GetAlphaFlagsRef();
    uVar5 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
            *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
    if ((uVar5 & 0x100) == 0) {
      *puVar3 = uVar5 | 1;
      return 0x7fffffff;
    }
    uVar5 = func_021340d4(param_1,param_2,0x4000003);
    return uVar5;
  }
  uVar2 = param_1 << 8 | 0x80000000;
  uVar7 = param_2 >> 0x17 & 0xff;
  if (uVar7 == 0 || uVar7 == 0xff) {
    if (uVar7 != 0) {
LAB_02132674:
      uVar6 = param_2 << 9;
joined_r0x02132658:
      if (uVar6 == 0) {
LAB_021327bc:
        return uVar5 | 0x7f800000;
      }
      goto LAB_021327f4;
    }
LAB_021326dc:
    if ((param_2 << 8 & 0x7fffffff) == 0) {
      return uVar5;
    }
    uVar4 = param_2 << 8 & 0x7fffffff;
    iVar8 = LZCOUNT(uVar4);
    uVar4 = uVar4 << iVar8;
    uVar7 = 1 - iVar8;
  }
  else {
    uVar4 = param_2 << 8 | 0x80000000;
  }
LAB_02132544:
  iVar8 = uVar6 + uVar7;
  uVar6 = (uint)((ulonglong)uVar4 * (ulonglong)uVar2 >> 0x20);
  if ((int)((ulonglong)uVar4 * (ulonglong)uVar2) != 0) {
    uVar6 = uVar6 | 1;
  }
  if (-1 < (int)uVar6) {
    uVar6 = uVar6 * 2;
    iVar8 = iVar8 + -1;
  }
  iVar9 = iVar8 + -0x7f;
  iVar1 = (int)(param_1 ^ param_2) >> 0x1f;
  if (iVar9 < 0) {
    uVar2 = GetAlphaFlagsRef();
    if (((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
         *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) & 0x800) != 0) {
      uVar5 = func_02134238((uVar5 | uVar6 >> 8) + (iVar8 + 0x41) * 0x800000,0x20000003);
      return uVar5;
    }
    uVar2 = uVar5;
    if (iVar9 == -0x18) {
      puVar3 = (uint *)GetAlphaFlagsRef();
      uVar7 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
              *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
      if ((uVar7 & 0x1000) == 0) {
        uVar2 = uVar7 | 0x18;
        *puVar3 = uVar2;
        if ((uVar7 & 0x800000) == 0) {
          if ((uVar7 & 0x400000) != 0) {
            if (uVar5 == 0) {
              uVar5 = 1;
            }
            return uVar5;
          }
          if ((uVar6 & 0x7fffffff) != 0) {
            uVar5 = uVar5 + 1;
          }
          return uVar5;
        }
code_r0x02132948:
        if ((uVar2 & 0x400000) == 0) {
          uVar5 = uVar5 - iVar1;
        }
        return uVar5;
      }
    }
    else if (iVar8 + -0x67 < 0) {
      puVar3 = (uint *)GetAlphaFlagsRef();
      uVar6 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
              *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
      if ((uVar6 & 0x1000) == 0) {
        uVar2 = uVar6 | 0x18;
        *puVar3 = uVar2;
        if ((uVar6 & 0x800000) == 0) {
          if ((uVar6 & 0x400000) != 0) {
            if (uVar5 == 0) {
              uVar5 = 1;
            }
            return uVar5;
          }
          return uVar5;
        }
        goto code_r0x02132948;
      }
    }
    else {
      uVar7 = (uVar6 >> 8) >> (-iVar9 & 0xffU);
      uVar2 = uVar5 | uVar7;
      uVar6 = uVar6 << (iVar8 - 0x67U & 0xff);
      if (uVar6 == 0) {
        return uVar2;
      }
      puVar3 = (uint *)GetAlphaFlagsRef();
      uVar4 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
              *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
      if ((uVar4 & 0x1000) == 0) {
        *puVar3 = uVar4 | 0x18;
        if ((uVar4 & 0x800000) != 0) {
          if ((uVar4 & 0x400000) == 0) {
            uVar2 = uVar2 - ((int)uVar2 >> 0x1f);
          }
          return uVar2;
        }
        if ((uVar4 & 0x400000) != 0) {
          if (uVar5 == 0) {
            uVar2 = uVar2 + 1;
          }
          return uVar2;
        }
        if ((uVar6 & 0x80000000) != 0) {
          if ((uVar6 & 0x7fffffff) != 0 || (uVar7 & 1) != 0) {
            uVar2 = uVar2 + 1;
          }
          return uVar2;
        }
        return uVar2;
      }
    }
  }
  else {
    if (0xfd < iVar9) {
      puVar3 = (uint *)GetAlphaFlagsRef();
      uVar2 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
              *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
      if ((uVar2 & 0x400) != 0) {
        uVar5 = func_02134238((uVar5 | uVar6 >> 8) + (iVar8 + -0x13f) * 0x800000,0x10000003);
        return uVar5;
      }
      *puVar3 = uVar2 | 0x14;
      uVar5 = uVar5 | 0x7f800000;
      if ((uVar2 & 0x800000) != 0) {
        uVar5 = uVar5 - 1;
        if ((uVar2 & 0x400000) == 0) {
          uVar5 = uVar5 - iVar1;
        }
        return uVar5;
      }
      if ((uVar2 & 0x400000) != 0) {
        uVar5 = uVar5 + iVar1;
      }
      return uVar5;
    }
    uVar2 = (uVar5 | uVar6 >> 8) + iVar9 * 0x800000;
    if ((uVar6 & 0xff) == 0) {
      return uVar2;
    }
    puVar3 = (uint *)GetAlphaFlagsRef();
    uVar7 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
            *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
    if ((uVar7 & 0x1000) == 0) {
      *puVar3 = uVar7 | 0x10;
      if ((uVar7 & 0x800000) == 0) {
        if ((uVar7 & 0x400000) == 0) {
          if ((uVar6 & 0x80) == 0) {
            return uVar2;
          }
          if ((uVar6 & 0x7f) == 0 && (uVar2 & 1) == 0) {
            return uVar2;
          }
        }
        else if (uVar5 != 0) {
          return uVar2;
        }
      }
      else {
        if ((uVar7 & 0x400000) != 0) {
          return uVar2;
        }
        if (uVar5 == 0) {
          return uVar2;
        }
      }
      uVar5 = uVar2 + 1;
      if (uVar5 * 2 < 0xff000000) {
        return uVar5;
      }
      if ((uVar7 & 0x400) != 0) {
        uVar5 = func_02134238(uVar2 + 0xa0000001,0x10000003);
        return uVar5;
      }
      *puVar3 = uVar7 | 0x14;
      return uVar5;
    }
  }
  uVar5 = func_02134238(uVar2,0x40000003,uVar5);
  return uVar5;
}

