/* Decompiled C draft; module arm9; ROM address 021329f8. No matching claim. */
#include "types.h"
#include "deps/021329f8_func_021329f8.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint func_021329f8(uint param_1,uint param_2)

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
  
  if (-1 < (int)(param_1 ^ param_2)) {
    uVar6 = param_2;
    uVar2 = param_1;
    if (param_1 < param_2) {
      uVar6 = param_1 - param_2 ^ 0x80000000;
      uVar2 = param_1 - uVar6;
      uVar6 = param_2 + uVar6;
    }
    uVar7 = uVar2 >> 0x17;
    uVar3 = uVar2 << 8 | 0x80000000;
    if ((uVar7 & 0xff) == 0 || (uVar7 & 0xff) == 0xff) {
      uVar4 = 0x80000000;
      if (uVar7 < 0x100) {
        uVar4 = 0;
      }
      if ((uVar7 & 0xff) != 0) {
        if (uVar2 << 9 == 0) {
          uVar2 = uVar6 * 0x200;
          uVar6 = uVar6 >> 0x17 & 0xff;
          if ((uVar6 == 0) || (uVar6 < 0xff)) goto LAB_02132d90;
          if (uVar2 == 0) goto LAB_02132ddc;
        }
        else {
          if ((uVar2 << 9 & 0x80000000) == 0) goto LAB_02132ddc;
          uVar2 = uVar6 * 0x200;
          uVar6 = uVar6 >> 0x17 & 0xff;
          if (uVar6 == 0) {
            return 0x7fffffff;
          }
          if (uVar6 < 0xff) {
            return 0x7fffffff;
          }
          if (uVar2 == 0) {
            return 0x7fffffff;
          }
        }
LAB_02132dc8:
        if ((uVar2 & 0x80000000) != 0) {
          return 0x7fffffff;
        }
LAB_02132ddc:
        puVar5 = (uint *)GetAlphaFlagsRef();
        uVar2 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
        if ((uVar2 & 0x100) == 0) {
          *puVar5 = uVar2 | 1;
          return 0x7fffffff;
        }
        uVar2 = func_021340d4(param_1,param_2,0x4000002);
        return uVar2;
      }
      if (uVar2 << 9 == 0) {
        uVar2 = uVar6 * 0x200;
        uVar4 = uVar6 >> 0x17 & 0xff;
        if (uVar4 != 0) {
          if (uVar4 < 0xff) {
            return uVar6;
          }
          if (uVar2 != 0) {
            if ((uVar2 & 0x80000000) != 0) {
              return 0x7fffffff;
            }
            puVar5 = (uint *)GetAlphaFlagsRef();
            *puVar5 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                      *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20 | 1;
            return 0x7fffffff;
          }
          goto LAB_02132d90;
        }
        if (uVar2 != 0) {
          return uVar6;
        }
        goto LAB_02132d00;
      }
      uVar3 = (uVar2 << 9) >> 1;
      uVar7 = 1;
      uVar2 = uVar6 << 8;
      uVar9 = uVar6 >> 0x17 & 0xff;
      if (uVar9 == 0) goto LAB_02132cbc;
      if (uVar9 == 0xff) goto LAB_02132c44;
      uVar2 = uVar2 | 0x80000000;
      uVar7 = uVar4 >> 0x17 | 1;
      uVar9 = uVar9 | uVar4 >> 0x17;
    }
    else {
      uVar9 = uVar6 >> 0x17;
      uVar2 = uVar6 << 8 | 0x80000000;
      if ((uVar9 & 0xff) == 0) {
        if (uVar9 < 0x100) {
          uVar4 = 0;
        }
        else {
          uVar4 = 0x80000000;
        }
        uVar7 = uVar7 & 0xff;
        if ((uVar9 & 0xff) != 0) {
LAB_02132c44:
          uVar4 = uVar4 ^ 0x80000000;
          uVar2 = uVar2 << 1;
          if (uVar2 == 0) {
LAB_02132d90:
            return uVar4 | 0x7f800000;
          }
          goto LAB_02132dc8;
        }
LAB_02132cbc:
        if ((uVar2 & 0x7fffffff) == 0) {
          if (-1 < (int)uVar3) {
            uVar7 = uVar7 - 1;
          }
          return uVar4 | uVar3 * 2 >> 9 | uVar7 << 0x17;
        }
        uVar2 = uVar2 & 0x7fffffff;
        uVar9 = uVar4 >> 0x17 | 1;
        uVar7 = uVar7 | uVar4 >> 0x17;
      }
    }
    uVar9 = uVar7 - uVar9;
    if (uVar9 == 0) {
      iVar8 = uVar3 - uVar2;
      if (iVar8 != 0) {
        uVar6 = (uVar7 & 0x100) << 0x17;
        uVar2 = iVar8 << LZCOUNT(iVar8);
        iVar8 = (uVar7 & 0xfffffeff) - LZCOUNT(iVar8);
        if (iVar8 < 1) {
          return uVar6 | uVar2 >> (9U - iVar8 & 0xff);
        }
        return uVar6 | uVar2 * 2 >> 9 | iVar8 * 0x800000;
      }
LAB_02132d00:
      uVar2 = GetAlphaFlagsRef();
      uVar2 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
      if ((uVar2 & 0x800000) == 0) {
        return 0;
      }
      if ((uVar2 & 0x400000) != 0) {
        return 0;
      }
      return 0x80000000;
    }
    if (0x1b < (int)uVar9) {
      uVar9 = 0x1f;
    }
    uVar6 = uVar2 << (0x20 - uVar9 & 0xff);
    uVar2 = uVar2 >> (uVar9 & 0xff);
    if (uVar6 != 0) {
      uVar2 = uVar2 | 1;
    }
    uVar3 = uVar3 - uVar2;
    if ((int)uVar3 < 0) {
      uVar2 = uVar3 * 2 >> 9;
      uVar4 = uVar2 | uVar7 << 0x17;
      if ((uVar3 & 0xff) == 0) {
        return uVar4;
      }
      puVar5 = (uint *)GetAlphaFlagsRef();
      uVar7 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
              *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
      if ((uVar7 & 0x1000) != 0) {
LAB_02132e0c:
        uVar2 = func_02134238(uVar4,0x40000002,uVar6);
        return uVar2;
      }
      uVar6 = uVar7 | 0x10;
      *puVar5 = uVar6;
      if ((uVar7 & 0x800000) != 0) {
LAB_02132ae8:
        if ((uVar6 & 0x400000) != 0) {
          return uVar4;
        }
        if ((int)uVar4 < 0) {
          uVar4 = uVar4 + 1;
        }
        return uVar4;
      }
      if ((uVar7 & 0x400000) == 0) {
        if ((uVar3 & 0x80) == 0) {
          return uVar4;
        }
        if ((uVar3 & 0x7f) != 0 || (uVar2 & 1) != 0) {
          uVar4 = uVar4 + 1;
        }
        return uVar4;
      }
    }
    else {
      uVar6 = (uVar7 & 0x100) << 0x17;
      uVar2 = uVar3 << LZCOUNT(uVar3);
      iVar8 = (uVar7 & 0xfffffeff) - LZCOUNT(uVar3);
      if (iVar8 < 1) {
        return uVar6 | uVar2 >> (9U - iVar8 & 0xff);
      }
      uVar7 = uVar2 * 2 >> 9;
      uVar4 = uVar6 | uVar7 | iVar8 * 0x800000;
      if ((uVar2 & 0xff) == 0) {
        return uVar4;
      }
      puVar5 = (uint *)GetAlphaFlagsRef();
      uVar3 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
              *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
      if ((uVar3 & 0x1000) != 0) goto LAB_02132e0c;
      uVar6 = uVar3 | 0x10;
      *puVar5 = uVar6;
      if ((uVar3 & 0x800000) != 0) goto LAB_02132ae8;
      if ((uVar3 & 0x400000) == 0) {
        if ((uVar2 & 0x80) == 0) {
          return uVar4;
        }
        if ((uVar2 & 0x7f) != 0 || (uVar7 & 1) != 0) {
          uVar4 = uVar4 + 1;
        }
        return uVar4;
      }
    }
    if (-1 < (int)uVar4) {
      uVar4 = uVar4 + 1;
    }
    return uVar4;
  }
  uVar6 = param_2 ^ 0x80000000;
  uVar2 = param_1;
  if (param_1 < uVar6) {
    uVar2 = param_1 - (param_1 - uVar6);
    uVar6 = uVar6 + (param_1 - uVar6);
  }
  uVar7 = uVar2 >> 0x17;
  uVar3 = uVar2 << 8 | 0x80000000;
  if ((uVar7 & 0xff) == 0 || (uVar7 & 0xff) == 0xff) {
    uVar9 = 0x80000000;
    if (uVar7 < 0x100) {
      uVar9 = 0;
    }
    if ((uVar7 & 0xff) != 0) {
      if (uVar2 << 9 == 0) {
        uVar2 = uVar6 * 0x200;
        uVar6 = uVar6 >> 0x17 & 0xff;
        if ((uVar6 == 0) || (uVar6 < 0xff)) goto LAB_021315a8;
joined_r0x021313b4:
        if (uVar2 == 0) {
LAB_021315a8:
          return uVar9 | 0x7f800000;
        }
      }
      else {
        if ((uVar2 << 9 & 0x80000000) == 0) goto LAB_021315f4;
        uVar2 = uVar6 * 0x200;
        uVar6 = uVar6 >> 0x17 & 0xff;
        if (uVar6 == 0) {
          return 0x7fffffff;
        }
        if (uVar6 < 0xff) {
          return 0x7fffffff;
        }
        if (uVar2 == 0) {
          return 0x7fffffff;
        }
      }
      if ((uVar2 & 0x80000000) != 0) {
        return 0x7fffffff;
      }
LAB_021315f4:
      puVar5 = (uint *)GetAlphaFlagsRef();
      uVar2 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
              *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
      if ((uVar2 & 0x100) == 0) {
        *puVar5 = uVar2 | 1;
        return 0x7fffffff;
      }
      uVar2 = func_021340d4(param_1,param_2,0x4000002);
      return uVar2;
    }
    if (uVar2 << 9 == 0) {
      uVar2 = uVar6 >> 0x17 & 0xff;
      if ((uVar2 == 0) || (uVar2 < 0xff)) {
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
    uVar7 = 1;
    uVar3 = (uVar2 << 9) >> 1;
    uVar2 = uVar6 << 8;
    uVar4 = uVar6 >> 0x17 & 0xff;
    if (uVar4 == 0) goto LAB_0213143c;
    if (uVar4 == 0xff) goto LAB_021313d4;
    uVar2 = uVar2 | 0x80000000;
    uVar7 = uVar9 >> 0x17 | 1;
    uVar4 = uVar4 | uVar9 >> 0x17;
LAB_0213127c:
    uVar4 = uVar7 - uVar4;
    if (uVar4 != 0) {
      if (0x1b < (int)uVar4) {
        uVar4 = 0x1f;
      }
      uVar9 = uVar2 << (0x20 - uVar4 & 0xff);
      uVar2 = uVar2 >> (uVar4 & 0xff);
      if (uVar9 != 0) {
        uVar2 = uVar2 | 1;
      }
    }
    uVar1 = uVar3 + uVar2;
    uVar6 = uVar7;
    if (CARRY4(uVar3,uVar2)) {
      uVar2 = (uint)CARRY4(uVar3,uVar2) << 0x1f | uVar1 >> 1;
      uVar1 = uVar1 & 1 | uVar2;
      uVar6 = uVar7 + 1;
      uVar9 = uVar6 & 0xff;
      if (uVar9 == 0xff) {
        uVar3 = 0xff;
        if (0xff < uVar6) {
          uVar3 = 0x80000000;
        }
        if ((int)(uVar7 - 0xff) < 0 != SBORROW4(uVar6,0x100)) {
          uVar3 = 0;
        }
        puVar5 = (uint *)GetAlphaFlagsRef();
        uVar6 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
        if ((uVar6 & 0x400) == 0) {
          *puVar5 = uVar6 | 0x14;
          uVar2 = uVar3 | 0x7f800000;
          if ((uVar6 & 0x800000) == 0) {
            if ((uVar6 & 0x400000) != 0) {
              uVar2 = uVar2 + ((int)uVar3 >> 0x1f);
            }
            return uVar2;
          }
          uVar2 = uVar2 - 1;
          if ((uVar6 & 0x400000) == 0) {
            uVar2 = uVar2 - ((int)uVar3 >> 0x1f);
          }
          return uVar2;
        }
        uVar2 = func_02134238((uVar3 | uVar2 >> 8) + 0x1f000000,0x10000001);
        return uVar2;
      }
    }
    uVar2 = uVar1 * 2 >> 9;
    uVar7 = uVar2 | uVar6 << 0x17;
    if ((uVar1 & 0xff) == 0) {
      return uVar7;
    }
    puVar5 = (uint *)GetAlphaFlagsRef();
    uVar6 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
            *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
    if ((uVar6 & 0x1000) != 0) {
LAB_0213167c:
      uVar2 = func_02134238(uVar7,0x40000001,uVar9);
      return uVar2;
    }
    uVar4 = uVar6 | 0x10;
    *puVar5 = uVar4;
    if ((uVar6 & 0x800000) != 0) {
LAB_02131360:
      if ((uVar4 & 0x400000) != 0) {
        return uVar7;
      }
      if (-1 < (int)uVar7) {
        return uVar7;
      }
      goto LAB_02131324;
    }
    if ((uVar6 & 0x400000) == 0) {
      if ((uVar1 & 0x80) == 0) {
        return uVar7;
      }
      if ((uVar1 & 0x7f) == 0 && (uVar2 & 1) == 0) {
        return uVar7;
      }
      goto LAB_02131324;
    }
  }
  else {
    uVar4 = uVar6 >> 0x17;
    uVar2 = uVar6 << 8 | 0x80000000;
    uVar9 = uVar4 & 0xff;
    if (uVar9 != 0) goto LAB_0213127c;
    if (uVar7 < 0x100) {
      uVar9 = 0;
    }
    else {
      uVar9 = 0x80000000;
    }
    uVar7 = uVar7 & 0xff;
    if ((uVar4 & 0xff) != 0) {
LAB_021313d4:
      uVar2 = uVar2 << 1;
      goto joined_r0x021313b4;
    }
LAB_0213143c:
    if ((uVar2 & 0x7fffffff) == 0) {
      if (-1 < (int)uVar3) {
        uVar7 = uVar7 - 1;
      }
      return uVar9 | uVar3 * 2 >> 9 | uVar7 << 0x17;
    }
    uVar2 = uVar2 & 0x7fffffff;
    uVar7 = uVar7 | uVar9 >> 0x17;
    uVar4 = uVar9 >> 0x17 | 1;
    if ((int)uVar3 < 0) goto LAB_0213127c;
    uVar6 = uVar3 + uVar2;
    if (CARRY4(uVar3,uVar2)) {
      uVar6 = (uint)CARRY4(uVar3,uVar2) << 0x1f | uVar6 >> 1;
      uVar4 = uVar4 + 1;
    }
    if (-1 < (int)uVar6) {
      uVar4 = uVar4 - 1;
    }
    uVar2 = uVar6 * 2 >> 9;
    uVar7 = uVar2 | uVar4 << 0x17;
    if ((uVar6 & 0xff) == 0) {
      return uVar7;
    }
    puVar5 = (uint *)GetAlphaFlagsRef();
    uVar3 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
            *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20;
    if ((uVar3 & 0x1000) != 0) goto LAB_0213167c;
    uVar4 = uVar3 | 0x10;
    *puVar5 = uVar4;
    if ((uVar3 & 0x800000) != 0) goto LAB_02131360;
    if ((uVar3 & 0x400000) == 0) {
      if ((uVar6 & 0xff) == 0) {
        return uVar7;
      }
      if ((uVar2 & 1) != 0) {
        uVar7 = uVar7 + 1;
      }
      return uVar7;
    }
  }
  if ((int)uVar7 < 0) {
    return uVar7;
  }
LAB_02131324:
  uVar2 = uVar7 + 1;
  if (uVar2 * 2 < 0xff000000) {
    return uVar2;
  }
  if ((uVar4 & 0x400) == 0) {
    *puVar5 = uVar4 | 0x14;
    return uVar2;
  }
  uVar2 = func_02134238(uVar7 + 0xa0000001,0x10000001,uVar9);
  return uVar2;
}

