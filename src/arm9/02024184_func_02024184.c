/* Decompiled C draft; module arm9; ROM address 02024184. No matching claim. */
#include "types.h"
#include "deps/02024184_func_02024184.h"

int func_02024184(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  iVar5 = 0;
  do {
    uVar6 = param_4 & -1 << (param_6 & 0xff);
    uVar1 = -1 << (param_5 & 0xff);
    uVar2 = -1 << (param_6 & 0xff);
    uVar7 = param_3 & -1 << (param_5 & 0xff);
    if (param_2 < uVar6) {
      if (uVar7 <= param_1) {
        iVar5 = uVar7 * uVar6 + iVar5;
      }
      if (param_1 < uVar7) {
        return uVar7 * (param_2 & uVar2) + iVar5 + ((param_1 & uVar1) << (param_6 & 0xff)) +
               ((param_2 & ~uVar2) << (param_5 & 0xff)) + (param_1 & ~uVar1);
      }
      param_1 = param_1 - uVar7;
      uVar7 = param_3 - uVar7;
    }
    else {
      iVar5 = param_3 * uVar6 + iVar5;
      if (param_1 < uVar7) {
        param_2 = param_2 - uVar6;
        uVar6 = param_4 - uVar6;
      }
      else {
        iVar5 = uVar7 * (param_4 - uVar6) + iVar5;
        param_1 = param_1 - uVar7;
        param_2 = param_2 - uVar6;
        uVar7 = param_3 - uVar7;
        uVar6 = param_4 - uVar6;
      }
    }
    if ((int)uVar7 < 8) {
      iVar4 = 0x1f - LZCOUNT(uVar7);
    }
    else {
      iVar4 = 3;
    }
    if ((int)uVar6 < 8) {
      iVar3 = 0x1f - LZCOUNT(uVar6);
    }
    else {
      iVar3 = 3;
    }
    iVar3 = iRam02024288 + iVar3 * 8;
    param_5 = (uint)*(byte *)(iVar3 + iVar4 * 2);
    param_6 = (uint)*(byte *)(iVar3 + iVar4 * 2 + 1);
    param_3 = uVar7;
    param_4 = uVar6;
  } while( true );
}

