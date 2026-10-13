/* Decompiled C draft; module arm9_ov000; ROM address 0218a350. No matching claim. */
#include "types.h"
#include "deps/0218a350_FUN_0218a350.h"

uint FUN_0218a350(int param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int local_2c;
  uint local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  uVar1 = param_3 * 3 >> 2;
  if (param_4 < uVar1) {
    return 0xffffffff;
  }
  uVar5 = param_3 & 3;
  iVar2 = param_3 - uVar5;
  iVar8 = 0;
  if (0 < iVar2) {
    local_2c = 0;
    local_20 = 0;
    local_24 = 0;
    uVar6 = local_24;
    uVar7 = local_24;
    do {
      do {
        iVar3 = FUN_0218a444(*(undefined1 *)(param_1 + iVar8 + uVar6));
        uVar7 = uVar7 | iVar3 << ((3 - uVar6) * 6 & 0xff);
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 < 4);
      local_1c = uVar7;
      iVar4 = local_2c * 3;
      iVar3 = local_20;
      do {
        *(undefined1 *)(param_2 + iVar4) = *(undefined1 *)((int)&local_1c + (2 - iVar3));
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 3);
      local_2c = local_2c + 1;
      iVar8 = iVar8 + 4;
      uVar6 = local_24;
      uVar7 = local_24;
    } while (iVar8 < iVar2);
  }
  if (uVar5 != 0) {
    uVar6 = 0;
    local_18 = 0;
    iVar8 = 0;
    if (uVar5 != 0) {
      do {
        iVar3 = FUN_0218a444(*(undefined1 *)(param_1 + iVar2 + iVar8));
        uVar6 = uVar6 | iVar3 << ((3 - iVar8) * 6 & 0xffU);
        local_18 = local_18 | uVar6;
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)uVar5);
    }
    iVar8 = 0;
    if (uVar5 != 0) {
      iVar2 = func_0x02133068(iVar2 * 3,4);
      do {
        *(undefined1 *)(param_2 + iVar2) = *(undefined1 *)((int)&local_18 + (2 - iVar8));
        iVar2 = iVar2 + 1;
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)uVar5);
    }
  }
  return uVar1;
}

