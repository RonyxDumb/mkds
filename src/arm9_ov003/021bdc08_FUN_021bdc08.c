/* Decompiled C draft; module arm9_ov003; ROM address 021bdc08. No matching claim. */
#include "types.h"
#include "deps/021bdc08_FUN_021bdc08.h"

ushort * FUN_021bdc08(int *param_1,ushort *param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  ushort *puVar2;
  
  uVar1 = DAT_021bdc58;
  puVar2 = (ushort *)*param_1;
  if (param_2 <= puVar2) {
    return (ushort *)0x0;
  }
  *param_3 = (int)(uint)*puVar2 >> 8 | (uint)*puVar2 << 8 & DAT_021bdc58 & 0xffff;
  *param_4 = (int)(uint)puVar2[1] >> 8 | (uint)puVar2[1] << 8 & uVar1 & 0xffff;
  *param_1 = (int)(puVar2 + 2) + ((*param_4 + 0xb & 0xfffffff8) - 4);
  return puVar2 + 2;
}

