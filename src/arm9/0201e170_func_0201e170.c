/* Decompiled C draft; module arm9; ROM address 0201e170. No matching claim. */
#include "types.h"
#include "deps/0201e170_func_0201e170.h"

void func_0201e170(ushort *param_1,int param_2)

{
  ushort uVar1;
  undefined1 auStack_30 [40];
  
  uVar1 = param_1[1];
  if (uVar1 == 0) {
    MTX_RotX33__from_thumb
              ((undefined4 *)(void *)(auStack_30),(int)*(short *)(iRam0201e244 + ((int)(uint)*param_1 >> 4) * 4),
               (int)*(short *)(iRam0201e244 + (((int)(uint)*param_1 >> 4) * 2 + 1) * 2));
  }
  else if (uVar1 == 1) {
    MTX_RotY33__from_thumb
              ((undefined4 *)(void *)(auStack_30),(int)*(short *)(iRam0201e244 + ((int)(uint)*param_1 >> 4) * 4),
               (int)*(short *)(iRam0201e244 + (((int)(uint)*param_1 >> 4) * 2 + 1) * 2));
  }
  else if (uVar1 == 2) {
    MTX_RotZ33__from_thumb
              ((undefined4 *)(void *)(auStack_30),(int)*(short *)(iRam0201e244 + ((int)(uint)*param_1 >> 4) * 4),
               (int)*(short *)(iRam0201e244 + (((int)(uint)*param_1 >> 4) * 2 + 1) * 2));
  }
  MTX_MultVec33(param_2 + 8,(uint)(uintptr_t)(auStack_30),(uint *)(uintptr_t)(param_2 + 8));
  return;
}

