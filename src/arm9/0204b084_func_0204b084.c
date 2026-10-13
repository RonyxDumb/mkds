/* Decompiled C draft; module arm9; ROM address 0204b084. No matching claim. */
#include "types.h"
#include "deps/0204b084_func_0204b084.h"

undefined4 func_0204b084(uint *param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0;
  uVar4 = 0;
  uVar3 = 0;
  uVar1 = FindTable0IndexForValue_from_thumb(*param_1,param_3);
  if (uVar1 == 0xffffffff) {
    return 0;
  }
  uVar1 = uVar1 & 0xffff;
  puVar2 = (uint *)((int)param_1 + param_2);
  do {
    *param_1 = *param_1 ^
               *(int *)(iRam0204b128 + uVar1 * 4) +
               *(int *)(iRam0204b12c + uVar5 * 4) +
               *(int *)(iRam0204b130 + uVar3 * 4) + *(int *)(iRam0204b134 + uVar4 * 4);
    param_1 = param_1 + 1;
    uVar3 = uVar3 + 1 & 0xffff;
    if (10 < uVar3) {
      uVar3 = 0;
      uVar4 = uVar4 + 1 & 0xffff;
      if (0x10 < uVar4) {
        uVar4 = 0;
        uVar5 = uVar5 + 1 & 0xffff;
        if (0x12 < uVar5) {
          uVar5 = 0;
          uVar1 = uVar1 + 1 & 0xffff;
          if (0x1c < uVar1) {
            uVar1 = 0;
          }
        }
      }
    }
  } while (param_1 < puVar2);
  return 1;
}

