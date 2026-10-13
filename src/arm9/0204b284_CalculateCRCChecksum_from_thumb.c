/* Decompiled C draft; module arm9; ROM address 0204b284. No matching claim. */
#include "types.h"
#include "deps/0204b284_CalculateCRCChecksum_from_thumb.h"

void CalculateCRCChecksum_from_thumb(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  undefined1 extraout_var;
  undefined1 extraout_r1;
  
  param_1 = param_1 + param_2;
  if (param_3 == 0) {
    *(undefined1 *)(param_1 + -4) = 0;
    *(undefined1 *)(param_1 + -3) = 0;
  }
  *(undefined1 *)(param_1 + -2) = 0;
  *(undefined1 *)(param_1 + -1) = 0;
  uVar1 = ComputeCRC_from_thumb();
  if (param_3 == 0) {
    Os_GetTick();
    *(undefined1 *)(param_1 + -4) = extraout_var;
    Os_GetTick();
    *(undefined1 *)(param_1 + -3) = extraout_r1;
  }
  *(char *)(param_1 + -2) = (char)((ushort)uVar1 >> 8);
  *(char *)(param_1 + -1) = (char)uVar1;
  return;
}

