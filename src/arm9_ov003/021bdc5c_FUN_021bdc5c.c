/* Decompiled C draft; module arm9_ov003; ROM address 021bdc5c. No matching claim. */
#include "types.h"
#include "deps/021bdc5c_FUN_021bdc5c.h"

ushort * FUN_021bdc5c(ushort *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  ushort *puVar4;
  
  uVar1 = DAT_021bdcc8;
  uVar3 = 0;
  *param_2 = (int)(uint)*param_1 >> 8 | (uint)*param_1 << 8 & DAT_021bdcc8 & 0xffff;
  *param_3 = (int)(uint)param_1[1] >> 8 | (uint)param_1[1] << 8 & uVar1 & 0xffff;
  puVar4 = (ushort *)((int)param_1 + *param_3 + 6);
  puVar2 = param_1;
  if (param_1 < puVar4) {
    do {
      uVar3 = uVar3 + (byte)*puVar2;
      puVar2 = (ushort *)((int)puVar2 + 1);
    } while (puVar2 < puVar4);
  }
  if ((uVar3 & 0xffff) != ((int)(uint)*puVar4 >> 8 | (uint)*puVar4 << 8 & DAT_021bdcc8 & 0xffff)) {
    return (ushort *)0x0;
  }
  return param_1 + 3;
}

