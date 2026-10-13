/* Decompiled C draft; module arm9; ROM address 02148334. No matching claim. */
#include "types.h"
#include "deps/02148334_VecFx16_CrossProduct.h"

void VecFx16_CrossProduct(short *param_1,short *param_2,undefined2 *param_3)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  
  sVar1 = param_2[2];
  sVar2 = param_1[1];
  sVar3 = *param_1;
  sVar4 = param_2[1];
  sVar5 = param_1[2];
  sVar6 = *param_2;
  *param_3 = (short)(((int)sVar2 * (int)sVar1 - (int)sVar5 * (int)sVar4) + 0x800 >> 0xc);
  param_3[1] = (short)(((int)sVar5 * (int)sVar6 - (int)sVar3 * (int)sVar1) + 0x800 >> 0xc);
  param_3[2] = (short)(((int)sVar3 * (int)sVar4 - (int)sVar2 * (int)sVar6) + 0x800 >> 0xc);
  return;
}

