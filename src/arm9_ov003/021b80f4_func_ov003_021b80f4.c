/* Decompiled C draft; module arm9_ov003; ROM address 021b80f4. No matching claim. */
#include "types.h"
#include "deps/021b80f4_func_ov003_021b80f4.h"

void func_ov003_021b80f4(undefined4 *param_1,int param_2,uint param_3,uint param_4)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  int extraout_r1;
  uint uVar5;
  int iVar6;
  uint local_18;
  
  iVar6 = param_1[2];
  uVar3 = 0;
  param_1[1] = 0;
  *param_1 = param_1[1];
  param_1[3] = param_4;
  if (param_4 != 0) {
    do {
      *(char *)(iVar6 + uVar3) = (char)uVar3;
      uVar3 = uVar3 + 1;
    } while (uVar3 < param_4);
  }
  iVar4 = 0;
  uVar3 = 0;
  uVar5 = 0;
  if (param_4 != 0) {
    local_18 = 0;
    do {
      bVar1 = *(byte *)(iVar6 + uVar5);
      func_0x02133274((uint)bVar1 + iVar4 + (uint)*(byte *)(param_2 + uVar3),param_1[3]);
      uVar2 = *(undefined1 *)(iVar6 + extraout_r1);
      *(byte *)(iVar6 + extraout_r1) = bVar1;
      *(undefined1 *)(iVar6 + uVar5) = uVar2;
      uVar3 = uVar3 + 1;
      if (param_3 <= uVar3) {
        uVar3 = local_18;
      }
      uVar5 = uVar5 + 1;
      iVar4 = extraout_r1;
    } while (uVar5 < param_4);
  }
  return;
}

