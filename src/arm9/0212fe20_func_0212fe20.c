/* Decompiled C draft; module arm9; ROM address 0212fe20. No matching claim. */
#include "types.h"
#include "deps/0212fe20_func_0212fe20.h"

uint func_0212fe20(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 in_lr;
  bool bVar9;
  
  uVar4 = param_2 & 0x80000000;
  uVar7 = param_2 >> 0x14 & 0xfffff7ff;
  uVar2 = uVar4;
  if (uVar7 == 0) {
    if (param_1 == 0 && (param_2 & 0xfffff) == 0) {
      return uVar4;
    }
    uVar7 = GetAlphaFlagsRef();
    uVar5 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
            *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
    bVar9 = (uVar5 & 0x800) != 0;
    if (bVar9) {
LAB_02130140:
      uVar2 = func_021341e0(param_1 & 0xe0000000,param_2 + 0xc000000,uRam0213018c,uVar5,in_lr);
      return uVar2;
    }
    if (bVar9) {
      return uVar4;
    }
  }
  else {
    if (0xffdfffff < uVar7 << 0x15) {
      if (param_1 == 0 && (param_2 & 0xfffff) == 0) {
        return uVar4 | 0x7f800000;
      }
      if ((param_2 & 0x80000) == 0) {
        puVar3 = (uint *)GetAlphaFlagsRef();
        uVar2 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
                *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
        if ((uVar2 & 0x100) != 0) {
          uVar2 = func_021341e0(param_1,param_2,uRam02130190,uVar2,in_lr);
          return uVar2;
        }
        *puVar3 = uVar2 | 1;
      }
      return 0x7fffffff;
    }
    iVar8 = uVar7 - 0x380;
    if (0x37f < uVar7 && iVar8 != 0) {
      if (0xfe < iVar8) {
        puVar3 = (uint *)GetAlphaFlagsRef();
        uVar2 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
                *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
        if ((uVar2 & 0x400) != 0) {
          uVar2 = func_021341e0(param_1 & 0xe0000000,param_2 + 0xf4000000,uRam02130184,uVar2,in_lr);
          return uVar2;
        }
        *puVar3 = uVar2 | 0x14;
        uVar4 = uVar4 | 0x7f800000;
        if ((uVar2 & 0x800000) != 0) {
          uVar4 = uVar4 - 1;
          if ((uVar2 & 0x400000) == 0) {
            uVar4 = uVar4 - ((int)param_2 >> 0x1f);
          }
          return uVar4;
        }
        if ((uVar2 & 0x400000) != 0) {
          uVar4 = uVar4 + ((int)param_2 >> 0x1f);
        }
        return uVar4;
      }
      uVar7 = param_1 << 3;
      uVar2 = uVar4 | (param_2 << 0xc) >> 9 | param_1 >> 0x1d | iVar8 * 0x800000;
      if (uVar7 == 0) {
        return uVar2;
      }
      puVar3 = (uint *)GetAlphaFlagsRef();
      uVar5 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
              *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
      if ((uVar5 & 0x1000) == 0) {
        *puVar3 = uVar5 | 0x10;
        if ((uVar5 & 0x800000) == 0) {
          if ((uVar5 & 0x400000) == 0) {
            if ((uVar7 & 0x80000000) == 0) {
              return uVar2;
            }
            if ((uVar7 & 0x7fffffff) == 0 && (param_1 >> 0x1d & 1) == 0) {
              return uVar2;
            }
          }
          else if (uVar4 != 0) {
            return uVar2;
          }
        }
        else {
          if ((uVar5 & 0x400000) != 0) {
            return uVar2;
          }
          if (uVar4 == 0) {
            return uVar2;
          }
        }
        uVar2 = uVar2 + 1;
        if (uVar2 * 2 < 0xff000000) {
          return uVar2;
        }
        if ((uVar5 & 0x400) != 0) {
          uVar2 = func_021341e0(0,uRam02130188,uRam02130184,uVar5 | 0x10,in_lr);
          return uVar2;
        }
        *puVar3 = uVar5 | 0x14;
        return uVar2;
      }
      goto LAB_02130170;
    }
    uVar5 = GetAlphaFlagsRef();
    uVar5 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
    if ((uVar5 & 0x800) != 0) goto LAB_02130140;
    if (iVar8 == -0x17) {
      puVar3 = (uint *)GetAlphaFlagsRef();
      uVar5 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
              *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
      if ((uVar5 & 0x1000) != 0) goto LAB_02130170;
      uVar7 = uVar5 | 0x18;
      *puVar3 = uVar7;
      if ((uVar5 & 0x800000) == 0) {
        if ((uVar5 & 0x400000) == 0) {
          if (param_1 != 0 || (param_2 & 0xfffff) != 0) {
            uVar4 = uVar4 + 1;
          }
          return uVar4;
        }
code_r0x0213000c:
        if (uVar4 == 0) {
          uVar2 = uVar2 + 1;
        }
        return uVar2;
      }
      goto LAB_02130018;
    }
    if (-1 < (int)(uVar7 - 0x369)) {
      uVar6 = (param_2 << 0xb | 0x80000000) >> 8 | param_1 >> 0x1d;
      uVar1 = uVar6 >> (1U - iVar8 & 0xff);
      uVar2 = uVar4 | uVar1;
      uVar6 = uVar6 << (0x20 - (1U - iVar8) & 0xff);
      if ((param_1 & 0x1fffffff) != 0) {
        uVar6 = uVar6 | 1;
      }
      if (uVar6 == 0) {
        return uVar2;
      }
      puVar3 = (uint *)GetAlphaFlagsRef();
      uVar5 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
              *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
      if ((uVar5 & 0x1000) != 0) goto LAB_02130170;
      uVar7 = uVar5 | 0x18;
      *puVar3 = uVar7;
      if ((uVar5 & 0x800000) == 0) {
        if ((uVar5 & 0x400000) == 0) {
          if ((uVar6 & 0x80000000) != 0) {
            if ((uVar6 & 0x7fffffff) != 0 || (uVar1 & 1) != 0) {
              uVar2 = uVar2 + 1;
            }
            return uVar2;
          }
          return uVar2;
        }
        goto code_r0x0213000c;
      }
      goto LAB_02130018;
    }
  }
  puVar3 = (uint *)GetAlphaFlagsRef();
  uVar5 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
          *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
  if ((uVar5 & 0x1000) == 0) {
    uVar7 = uVar5 | 0x18;
    *puVar3 = uVar7;
    if ((uVar5 & 0x800000) == 0) {
      if ((uVar5 & 0x400000) != 0) {
        if (uVar4 == 0) {
          uVar4 = 1;
        }
        return uVar4;
      }
      return uVar4;
    }
LAB_02130018:
    if ((uVar7 & 0x400000) == 0) {
      uVar2 = uVar2 - ((int)uVar2 >> 0x1f);
    }
    return uVar2;
  }
LAB_02130170:
  uVar2 = func_02134238(uVar2,uRam02130194,uVar4,uVar5,in_lr);
  return uVar2;
}

