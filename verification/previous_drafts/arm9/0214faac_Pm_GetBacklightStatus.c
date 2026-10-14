/* Decompiled C draft; module arm9; ROM address 0214faac. No matching claim. */
#include "types.h"
#include "deps/0214faac_Pm_GetBacklightStatus.h"

void Pm_GetBacklightStatus(uint *param_1,uint *param_2)

{
  int iVar1;
  ushort auStack_10 [2];
  
  iVar1 = Pm_GetBacklightFlags(0,(undefined4)(uintptr_t)(auStack_10));
  if (iVar1 != 0) {
    return;
  }
  if (param_1 != (uint *)0x0) {
    *param_1 = (uint)((auStack_10[0] & 8) != 0);
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = (uint)((auStack_10[0] & 4) != 0);
    return;
  }
  return;
}

