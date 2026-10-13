/* Decompiled C draft; module arm9; ROM address 02132e4c. No matching claim. */
#include "types.h"
#include "deps/02132e4c__ull_mod.h"

/* WARNING: Removing unreachable block (ram,0x02132fe0) */
/* WARNING: Removing unreachable block (ram,0x02132fdc) */
/* WARNING: Removing unreachable block (ram,0x02133020) */

ulonglong _ull_mod(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint extraout_r1;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  
  if (param_4 == 0 && param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  if (param_2 == 0 && param_4 == 0) {
    FUN_0213327c(param_1,param_3);
    return (ulonglong)extraout_r1;
  }
  if (param_2 == 0 && param_1 == 0) {
    uVar4 = 0;
  }
  else {
    uVar6 = 0;
    iVar7 = 1;
    if (-1 < (int)param_4) {
      do {
        uVar4 = uVar6;
        uVar6 = uVar4 + 1;
        bVar9 = CARRY4(param_3,param_3);
        param_3 = param_3 * 2;
        param_4 = param_4 * 2 + (uint)bVar9;
      } while (-1 < (int)param_4);
      iVar7 = uVar4 + 2;
    }
    if (-1 < (int)param_2) {
      do {
        if (iVar7 == 1) break;
        iVar7 = iVar7 + -1;
        bVar9 = CARRY4(param_1,param_1);
        param_1 = param_1 * 2;
        param_2 = param_2 * 2 + (uint)bVar9;
      } while (-1 < (int)param_2);
    }
    iVar8 = 0;
    while( true ) {
      uVar3 = param_1 - param_3;
      uVar4 = param_2 - (param_4 + (param_3 > param_1));
      for (iVar8 = iVar8 - (uint)(param_2 <= param_4 &&
                                 (uint)(param_3 <= param_1) <= param_2 - param_4); iVar8 < 0;
          iVar8 = iVar8 * 2 + (uint)(bVar9 || CARRY4(uVar2,(uint)bVar10)) +
                  (uint)(CARRY4(uVar5,param_4) ||
                        CARRY4(uVar5 + param_4,(uint)CARRY4(uVar1,param_3)))) {
        iVar7 = iVar7 + -1;
        if (iVar7 == 0) {
          bVar9 = CARRY4(uVar3,param_3);
          uVar3 = uVar3 + param_3;
          uVar4 = uVar4 + param_4 + (uint)bVar9;
          goto LAB_02132fd8;
        }
        bVar10 = CARRY4(uVar3,uVar3);
        uVar1 = uVar3 * 2;
        uVar2 = uVar4 * 2;
        bVar9 = CARRY4(uVar4,uVar4);
        uVar5 = uVar4 * 2 + (uint)bVar10;
        uVar3 = uVar1 + param_3;
        uVar4 = uVar5 + param_4 + (uint)CARRY4(uVar1,param_3);
      }
      iVar7 = iVar7 + -1;
      if (iVar7 == 0) break;
      param_1 = uVar3 * 2;
      param_2 = uVar4 * 2 + (uint)CARRY4(uVar3,uVar3);
      iVar8 = iVar8 * 2 + (uint)(CARRY4(uVar4,uVar4) || CARRY4(uVar4 * 2,(uint)CARRY4(uVar3,uVar3)))
      ;
    }
LAB_02132fd8:
    if ((int)uVar6 < 0x20) {
      return CONCAT44(uVar4 >> (uVar6 & 0xff),
                      uVar3 >> (uVar6 & 0xff) | uVar4 << (0x20 - uVar6 & 0xff));
    }
    uVar4 = uVar4 >> (uVar6 - 0x20 & 0xff);
  }
  return (ulonglong)uVar4;
}

