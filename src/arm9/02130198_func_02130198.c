/* Decompiled C draft; module arm9; ROM address 02130198. No matching claim. */
#include "types.h"
#include "deps/02130198_func_02130198.h"

uint func_02130198(uint param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 in_lr;
  
  if ((param_2 & 0x80000000) == 0) {
    uVar4 = iRam021302f8 - (param_2 >> 0x14);
    if ((int)(param_2 >> 0x14) <= iRam021302f8) {
      if ((int)uVar4 < 0x40) {
        uVar5 = param_2 << 0xb | 0x80000000 | param_1 >> 0x15;
        if ((int)uVar4 < 0x21) {
          uVar3 = uVar5 >> (uVar4 & 0xff);
          uVar2 = (param_1 << 0xb) >> (uVar4 & 0xff) | uVar5 << (0x20 - uVar4 & 0xff);
          if ((param_1 << 0xb) << (0x20 - uVar4 & 0xff) == 0) {
            return uVar2;
          }
          puVar1 = (uint *)GetAlphaFlagsRef();
          uVar4 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
          if ((uVar4 & 0x1000) == 0) {
            *puVar1 = uVar4 | 0x10;
            return uVar2;
          }
        }
        else {
          uVar2 = uVar5 >> (uVar4 - 0x20 & 0xff);
          if ((param_1 & 0x1fffff) == 0 && uVar5 << (0x20 - (uVar4 - 0x20) & 0xff) == 0) {
            return uVar2;
          }
          puVar1 = (uint *)GetAlphaFlagsRef();
          uVar3 = 0;
          uVar4 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
          if ((uVar4 & 0x1000) == 0) {
            *puVar1 = uVar4 | 0x10;
            return uVar2;
          }
        }
      }
      else {
        if (param_2 == 0 && param_1 == 0) {
          return param_1;
        }
        puVar1 = (uint *)GetAlphaFlagsRef();
        uVar2 = 0;
        uVar3 = 0;
        uVar4 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
        if ((uVar4 & 0x1000) == 0) {
          *puVar1 = uVar4 | 0x10;
          return uVar2;
        }
      }
      uVar4 = func_0213412c(uVar2,uVar3,uRam02130300,uVar4,in_lr);
      return uVar4;
    }
  }
  else if (param_2 < 0xfff00000 || param_2 == 0xfff00000 && param_1 == 0) {
    return 0;
  }
  puVar1 = (uint *)GetAlphaFlagsRef();
  uVar4 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
          *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
  if ((uVar4 & 0x100) == 0) {
    *puVar1 = uVar4 | 1;
    return 0xffffffff;
  }
  uVar4 = func_0213412c(param_1,param_2,uRam021302fc,uVar4,in_lr);
  return uVar4;
}

