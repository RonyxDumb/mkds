/* Decompiled C draft; module arm9_ov003; ROM address 021b807c. No matching claim. */
#include "types.h"
#include "deps/021b807c_func_ov003_021b807c.h"

undefined1 func_ov003_021b807c(uint *param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint extraout_r1;
  uint extraout_r1_00;
  int extraout_r1_01;
  uint uVar4;
  uint uVar5;
  
  uVar4 = param_1[2];
  uVar3 = param_1[3];
  func_0x02133274(*param_1 + 1,uVar3);
  uVar5 = extraout_r1 & 0xff;
  bVar1 = *(byte *)(uVar4 + uVar5);
  func_0x02133274((uint)bVar1 + param_1[1],uVar3);
  uVar3 = extraout_r1_00 & 0xff;
  bVar2 = *(byte *)(uVar4 + uVar3);
  *param_1 = uVar5;
  param_1[1] = uVar3;
  *(byte *)(uVar4 + uVar3) = bVar1;
  *(byte *)(uVar4 + uVar5) = bVar2;
  func_0x02133274((uint)bVar1 + (uint)bVar2,param_1[3]);
  return *(undefined1 *)(uVar4 + extraout_r1_01);
}

