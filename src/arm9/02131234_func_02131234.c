/* Decompiled C draft; module arm9; ROM address 02131234. No matching claim. */
#include "types.h"
#include "deps/02131234_func_02131234.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint func_02131234(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  if ((int)(param_1 ^ param_2) < 0) {
    uVar6 = param_2 ^ 0x80000000;
    uVar1 = param_1;
    if (param_1 < uVar6) {
      uVar4 = param_1 - uVar6 ^ 0x80000000;
      uVar1 = param_1 - uVar4;
      uVar6 = uVar6 + uVar4;
    }
    uVar4 = uVar1 >> 0x17;
    uVar2 = uVar1 << 8 | 0x80000000;
    if ((uVar4 & 0xff) == 0 || (uVar4 & 0xff) == 0xff) {
      uVar9 = 0x80000000;
      if (uVar4 < 0x100) {
        uVar9 = 0;
      }
      if ((uVar4 & 0xff) != 0) {
        if (uVar1 << 9 == 0) {
          uVar1 = uVar6 * 0x200;
          uVar6 = uVar6 >> 0x17 & 0xff;
          if ((uVar6 == 0) || (uVar6 < 0xff)) goto LAB_02132d90;
          if (uVar1 == 0) goto LAB_02132ddc;
        }
        else {
          if ((uVar1 << 9 & 0x80000000) == 0) goto LAB_02132ddc;
          uVar1 = uVar6 * 0x200;
          uVar6 = uVar6 >> 0x17 & 0xff;
          if (uVar6 == 0) {
            return 0x7fffffff;
          }
          if (uVar6 < 0xff) {
            return 0x7fffffff;
          }
          if (uVar1 == 0) {
            return 0x7fffffff;
          }
        }
LAB_02132dc8:
        if ((uVar1 & 0x80000000) != 0) {
          return 0x7fffffff;
        }
LAB_02132ddc:
        puVar5 = (uint *)GetAlphaFlagsRef();
        uVar1 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
        if ((uVar1 & 0x100) == 0) {
          *puVar5 = uVar1 | 1;
          return 0x7fffffff;
        }
        uVar1 = func_021340d4(param_1,param_2,0x4000001);
        return uVar1;
      }
      if (uVar1 << 9 == 0) {
        uVar1 = uVar6 * 0x200;
        uVar9 = uVar6 >> 0x17 & 0xff;
        if (uVar9 != 0) {
          if (uVar9 < 0xff) {
            return uVar6;
          }
          if (uVar1 != 0) {
            if ((uVar1 & 0x80000000) != 0) {
              return 0x7fffffff;
            }
            puVar5 = (uint *)GetAlphaFlagsRef();
            *puVar5 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                      *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20 | 1;
            return 0x7fffffff;
          }
          goto LAB_02132d90;
        }
        if (uVar1 != 0) {
          return uVar6;
        }
        goto LAB_02132d00;
      }
      uVar2 = (uVar1 << 9) >> 1;
      uVar4 = 1;
      uVar1 = uVar6 << 8;
      uVar7 = uVar6 >> 0x17 & 0xff;
      if (uVar7 == 0) goto LAB_02132cbc;
      if (uVar7 == 0xff) goto LAB_02132c44;
      uVar1 = uVar1 | 0x80000000;
      uVar4 = uVar9 >> 0x17 | 1;
      uVar7 = uVar7 | uVar9 >> 0x17;
    }
    else {
      uVar7 = uVar6 >> 0x17;
      uVar1 = uVar6 << 8 | 0x80000000;
      if ((uVar7 & 0xff) == 0) {
        if (uVar7 < 0x100) {
          uVar9 = 0;
        }
        else {
          uVar9 = 0x80000000;
        }
        uVar4 = uVar4 & 0xff;
        if ((uVar7 & 0xff) != 0) {
LAB_02132c44:
          uVar9 = uVar9 ^ 0x80000000;
          uVar1 = uVar1 << 1;
          if (uVar1 == 0) {
LAB_02132d90:
            return uVar9 | 0x7f800000;
          }
          goto LAB_02132dc8;
        }
LAB_02132cbc:
        if ((uVar1 & 0x7fffffff) == 0) {
          if (-1 < (int)uVar2) {
            uVar4 = uVar4 - 1;
          }
          return uVar9 | uVar2 * 2 >> 9 | uVar4 << 0x17;
        }
        uVar1 = uVar1 & 0x7fffffff;
        uVar7 = uVar9 >> 0x17 | 1;
        uVar4 = uVar4 | uVar9 >> 0x17;
      }
    }
    uVar7 = uVar4 - uVar7;
    if (uVar7 == 0) {
      iVar8 = uVar2 - uVar1;
      if (iVar8 != 0) {
        uVar6 = (uVar4 & 0x100) << 0x17;
        uVar1 = iVar8 << LZCOUNT(iVar8);
        iVar8 = (uVar4 & 0xfffffeff) - LZCOUNT(iVar8);
        if (iVar8 < 1) {
          return uVar6 | uVar1 >> (9U - iVar8 & 0xff);
        }
        return uVar6 | uVar1 * 2 >> 9 | iVar8 * 0x800000;
      }
LAB_02132d00:
      uVar1 = GetAlphaFlagsRef();
      uVar1 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      if ((uVar1 & 0x800000) == 0) {
        return 0;
      }
      if ((uVar1 & 0x400000) != 0) {
        return 0;
      }
      return 0x80000000;
    }
    if (0x1b < (int)uVar7) {
      uVar7 = 0x1f;
    }
    uVar6 = uVar1 << (0x20 - uVar7 & 0xff);
    uVar1 = uVar1 >> (uVar7 & 0xff);
    if (uVar6 != 0) {
      uVar1 = uVar1 | 1;
    }
    uVar2 = uVar2 - uVar1;
    if ((int)uVar2 < 0) {
      uVar1 = uVar2 * 2 >> 9;
      uVar9 = uVar1 | uVar4 << 0x17;
      if ((uVar2 & 0xff) == 0) {
        return uVar9;
      }
      puVar5 = (uint *)GetAlphaFlagsRef();
      uVar4 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
              *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
      if ((uVar4 & 0x1000) != 0) {
LAB_02132e0c:
        uVar1 = func_02134238(uVar9,0x40000002,uVar6);
        return uVar1;
      }
      uVar6 = uVar4 | 0x10;
      *puVar5 = uVar6;
      if ((uVar4 & 0x800000) != 0) {
LAB_02132ae8:
        if ((uVar6 & 0x400000) != 0) {
          return uVar9;
        }
        if ((int)uVar9 < 0) {
          uVar9 = uVar9 + 1;
        }
        return uVar9;
      }
      if ((uVar4 & 0x400000) == 0) {
        if ((uVar2 & 0x80) == 0) {
          return uVar9;
        }
        if ((uVar2 & 0x7f) != 0 || (uVar1 & 1) != 0) {
          uVar9 = uVar9 + 1;
        }
        return uVar9;
      }
    }
    else {
      uVar6 = (uVar4 & 0x100) << 0x17;
      uVar1 = uVar2 << LZCOUNT(uVar2);
      iVar8 = (uVar4 & 0xfffffeff) - LZCOUNT(uVar2);
      if (iVar8 < 1) {
        return uVar6 | uVar1 >> (9U - iVar8 & 0xff);
      }
      uVar4 = uVar1 * 2 >> 9;
      uVar9 = uVar6 | uVar4 | iVar8 * 0x800000;
      if ((uVar1 & 0xff) == 0) {
        return uVar9;
      }
      puVar5 = (uint *)GetAlphaFlagsRef();
      uVar2 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
              *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
      if ((uVar2 & 0x1000) != 0) goto LAB_02132e0c;
      uVar6 = uVar2 | 0x10;
      *puVar5 = uVar6;
      if ((uVar2 & 0x800000) != 0) goto LAB_02132ae8;
      if ((uVar2 & 0x400000) == 0) {
        if ((uVar1 & 0x80) == 0) {
          return uVar9;
        }
        if ((uVar1 & 0x7f) != 0 || (uVar4 & 1) != 0) {
          uVar9 = uVar9 + 1;
        }
        return uVar9;
      }
    }
    if (-1 < (int)uVar9) {
      uVar9 = uVar9 + 1;
    }
    return uVar9;
  }
  uVar6 = param_2;
  uVar1 = param_1;
  if (param_1 < param_2) {
    uVar1 = param_1 - (param_1 - param_2);
    uVar6 = param_2 + (param_1 - param_2);
  }
  uVar4 = uVar1 >> 0x17;
  uVar2 = uVar1 << 8 | 0x80000000;
  if ((uVar4 & 0xff) == 0 || (uVar4 & 0xff) == 0xff) {
    uVar7 = 0x80000000;
    if (uVar4 < 0x100) {
      uVar7 = 0;
    }
    if ((uVar4 & 0xff) != 0) {
      if (uVar1 << 9 == 0) {
        uVar1 = uVar6 * 0x200;
        uVar6 = uVar6 >> 0x17 & 0xff;
        if ((uVar6 == 0) || (uVar6 < 0xff)) goto LAB_021315a8;
joined_r0x021313b4:
        if (uVar1 == 0) {
LAB_021315a8:
          return uVar7 | 0x7f800000;
        }
      }
      else {
        if ((uVar1 << 9 & 0x80000000) == 0) goto LAB_021315f4;
        uVar1 = uVar6 * 0x200;
        uVar6 = uVar6 >> 0x17 & 0xff;
        if (uVar6 == 0) {
          return 0x7fffffff;
        }
        if (uVar6 < 0xff) {
          return 0x7fffffff;
        }
        if (uVar1 == 0) {
          return 0x7fffffff;
        }
      }
      if ((uVar1 & 0x80000000) != 0) {
        return 0x7fffffff;
      }
LAB_021315f4:
      puVar5 = (uint *)GetAlphaFlagsRef();
      uVar1 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
              *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
      if ((uVar1 & 0x100) == 0) {
        *puVar5 = uVar1 | 1;
        return 0x7fffffff;
      }
      uVar1 = func_021340d4(param_1,param_2,0x4000001);
      return uVar1;
    }
    if (uVar1 << 9 == 0) {
      uVar1 = uVar6 >> 0x17 & 0xff;
      if ((uVar1 == 0) || (uVar1 < 0xff)) {
        return uVar6;
      }
      if (uVar6 * 0x200 != 0) {
        if ((uVar6 * 0x200 & 0x80000000) != 0) {
          return 0x7fffffff;
        }
        puVar5 = (uint *)GetAlphaFlagsRef();
        *puVar5 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                  *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20 | 1;
        return 0x7fffffff;
      }
      goto LAB_021315a8;
    }
    uVar4 = 1;
    uVar2 = (uVar1 << 9) >> 1;
    uVar1 = uVar6 << 8;
    uVar9 = uVar6 >> 0x17 & 0xff;
    if (uVar9 == 0) goto LAB_0213143c;
    if (uVar9 == 0xff) goto LAB_021313d4;
    uVar1 = uVar1 | 0x80000000;
    uVar4 = uVar7 >> 0x17 | 1;
    uVar9 = uVar9 | uVar7 >> 0x17;
LAB_0213127c:
    uVar9 = uVar4 - uVar9;
    if (uVar9 != 0) {
      if (0x1b < (int)uVar9) {
        uVar9 = 0x1f;
      }
      uVar7 = uVar1 << (0x20 - uVar9 & 0xff);
      uVar1 = uVar1 >> (uVar9 & 0xff);
      if (uVar7 != 0) {
        uVar1 = uVar1 | 1;
      }
    }
    uVar3 = uVar2 + uVar1;
    uVar6 = uVar4;
    if (CARRY4(uVar2,uVar1)) {
      uVar1 = (uint)CARRY4(uVar2,uVar1) << 0x1f | uVar3 >> 1;
      uVar3 = uVar3 & 1 | uVar1;
      uVar6 = uVar4 + 1;
      uVar7 = uVar6 & 0xff;
      if (uVar7 == 0xff) {
        uVar2 = 0xff;
        if (0xff < uVar6) {
          uVar2 = 0x80000000;
        }
        if ((int)(uVar4 - 0xff) < 0 != SBORROW4(uVar6,0x100)) {
          uVar2 = 0;
        }
        puVar5 = (uint *)GetAlphaFlagsRef();
        uVar6 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
        if ((uVar6 & 0x400) == 0) {
          *puVar5 = uVar6 | 0x14;
          uVar1 = uVar2 | 0x7f800000;
          if ((uVar6 & 0x800000) == 0) {
            if ((uVar6 & 0x400000) != 0) {
              uVar1 = uVar1 + ((int)uVar2 >> 0x1f);
            }
            return uVar1;
          }
          uVar1 = uVar1 - 1;
          if ((uVar6 & 0x400000) == 0) {
            uVar1 = uVar1 - ((int)uVar2 >> 0x1f);
          }
          return uVar1;
        }
        uVar1 = func_02134238((uVar2 | uVar1 >> 8) + 0x1f000000,0x10000001);
        return uVar1;
      }
    }
    uVar1 = uVar3 * 2 >> 9;
    uVar4 = uVar1 | uVar6 << 0x17;
    if ((uVar3 & 0xff) == 0) {
      return uVar4;
    }
    puVar5 = (uint *)GetAlphaFlagsRef();
    uVar6 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
            *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
    if ((uVar6 & 0x1000) != 0) {
LAB_0213167c:
      uVar1 = func_02134238(uVar4,0x40000001,uVar7);
      return uVar1;
    }
    uVar9 = uVar6 | 0x10;
    *puVar5 = uVar9;
    if ((uVar6 & 0x800000) != 0) {
LAB_02131360:
      if ((uVar9 & 0x400000) != 0) {
        return uVar4;
      }
      if (-1 < (int)uVar4) {
        return uVar4;
      }
      goto LAB_02131324;
    }
    if ((uVar6 & 0x400000) == 0) {
      if ((uVar3 & 0x80) == 0) {
        return uVar4;
      }
      if ((uVar3 & 0x7f) == 0 && (uVar1 & 1) == 0) {
        return uVar4;
      }
      goto LAB_02131324;
    }
  }
  else {
    uVar9 = uVar6 >> 0x17;
    uVar1 = uVar6 << 8 | 0x80000000;
    uVar7 = uVar9 & 0xff;
    if (uVar7 != 0) goto LAB_0213127c;
    if (uVar4 < 0x100) {
      uVar7 = 0;
    }
    else {
      uVar7 = 0x80000000;
    }
    uVar4 = uVar4 & 0xff;
    if ((uVar9 & 0xff) != 0) {
LAB_021313d4:
      uVar1 = uVar1 << 1;
      goto joined_r0x021313b4;
    }
LAB_0213143c:
    if ((uVar1 & 0x7fffffff) == 0) {
      if (-1 < (int)uVar2) {
        uVar4 = uVar4 - 1;
      }
      return uVar7 | uVar2 * 2 >> 9 | uVar4 << 0x17;
    }
    uVar1 = uVar1 & 0x7fffffff;
    uVar4 = uVar4 | uVar7 >> 0x17;
    uVar9 = uVar7 >> 0x17 | 1;
    if ((int)uVar2 < 0) goto LAB_0213127c;
    uVar6 = uVar2 + uVar1;
    if (CARRY4(uVar2,uVar1)) {
      uVar6 = (uint)CARRY4(uVar2,uVar1) << 0x1f | uVar6 >> 1;
      uVar9 = uVar9 + 1;
    }
    if (-1 < (int)uVar6) {
      uVar9 = uVar9 - 1;
    }
    uVar1 = uVar6 * 2 >> 9;
    uVar4 = uVar1 | uVar9 << 0x17;
    if ((uVar6 & 0xff) == 0) {
      return uVar4;
    }
    puVar5 = (uint *)GetAlphaFlagsRef();
    uVar2 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
            *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
    if ((uVar2 & 0x1000) != 0) goto LAB_0213167c;
    uVar9 = uVar2 | 0x10;
    *puVar5 = uVar9;
    if ((uVar2 & 0x800000) != 0) goto LAB_02131360;
    if ((uVar2 & 0x400000) == 0) {
      if ((uVar6 & 0xff) == 0) {
        return uVar4;
      }
      if ((uVar1 & 1) != 0) {
        uVar4 = uVar4 + 1;
      }
      return uVar4;
    }
  }
  if ((int)uVar4 < 0) {
    return uVar4;
  }
LAB_02131324:
  uVar1 = uVar4 + 1;
  if (uVar1 * 2 < 0xff000000) {
    return uVar1;
  }
  if ((uVar9 & 0x400) == 0) {
    *puVar5 = uVar9 | 0x14;
    return uVar1;
  }
  uVar1 = func_02134238(uVar4 + 0xa0000001,0x10000001,uVar7);
  return uVar1;
}

