/* Decompiled C draft; module arm9; ROM address 0204b138. No matching claim. */
#include "types.h"
#include "deps/0204b138_EncryptSaveData_from_thumb.h"

void EncryptSaveData_from_thumb(uint *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar6 = 0;
  uVar5 = 0;
  uVar4 = 0;
  uVar7 = Os_GetTick();
  iVar1 = _ull_mod((int)(uVar7 >> 0x10),(int)((uVar7 >> 0x10) >> 0x20),0x1d,0);
  uVar2 = FindTable0IndexForValue_from_thumb
                    (*(int *)(iRam0204b1fc + ((uint)(iVar1 << 0x10) >> 0xe)) +
                     *piRam0204b200 + *piRam0204b204 + *piRam0204b208 ^ *param_1);
  uVar2 = uVar2 & 0xffff;
  puVar3 = (uint *)((int)param_1 + param_2);
  do {
    *param_1 = *param_1 ^
               *(int *)(iRam0204b1fc + uVar2 * 4) +
               piRam0204b200[uVar6] + piRam0204b204[uVar4] + piRam0204b208[uVar5];
    param_1 = param_1 + 1;
    uVar4 = uVar4 + 1 & 0xffff;
    if (10 < uVar4) {
      uVar4 = 0;
      uVar5 = uVar5 + 1 & 0xffff;
      if (0x10 < uVar5) {
        uVar5 = 0;
        uVar6 = uVar6 + 1 & 0xffff;
        if (0x12 < uVar6) {
          uVar6 = 0;
          uVar2 = uVar2 + 1 & 0xffff;
          if (0x1c < uVar2) {
            uVar2 = 0;
          }
        }
      }
    }
  } while (param_1 < puVar3);
  return;
}

