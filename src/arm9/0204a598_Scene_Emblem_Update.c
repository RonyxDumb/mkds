/* Decompiled C draft; module arm9; ROM address 0204a598. No matching claim. */
#include "types.h"
#include "deps/0204a598_Scene_Emblem_Update.h"

void Scene_Emblem_Update(short *param_1)

{
  int iVar1;
  
  iVar1 = func_0x021a23c8();
  if (param_1 == (short *)0x0) {
    return;
  }
  if (iVar1 != 0) {
    if (*param_1 != 7) {
      param_1[2] = 0;
      return;
    }
    param_1[2] = 7;
    return;
  }
  return;
}

