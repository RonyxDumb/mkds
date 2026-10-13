/* Decompiled C draft; module arm9_ov003; ROM address 021d2288. No matching claim. */
#include "types.h"
#include "deps/021d2288_FUN_021d2288.h"

int FUN_021d2288(int param_1,int param_2)

{
  ushort *puVar1;
  ushort *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar6 = *DAT_021d2360 + DAT_021d2364 + param_1 * 0x38;
  uVar7 = (uint)*(ushort *)(DAT_021d2368 + param_1 * 4);
  uVar3 = (uint)*(ushort *)(DAT_021d236c + param_1 * 4);
  uVar4 = FUN_021d285c(uVar7 * uVar3 * 0x20,0x20);
  *(undefined4 *)(iVar6 + 0x30) = uVar4;
  puVar2 = DAT_021d2378;
  puVar1 = DAT_021d2370;
  if (param_1 == 1) {
    *DAT_021d2370 = *DAT_021d2370 & 0xffbf;
    *puVar1 = *puVar1 & 0x43 | (ushort)DAT_021d2374;
  }
  else {
    *DAT_021d2378 = *DAT_021d2378 & 0xffbf;
    *puVar2 = *puVar2 & 0x43 | (ushort)DAT_021d2374;
  }
  func_0x02023408(iVar6,*(undefined4 *)(iVar6 + 0x30),uVar3,uVar7,4);
  iVar5 = *DAT_021d2360;
  *(int *)(iVar6 + 0x20) = iVar6;
  *(int *)(iVar6 + 0x24) = iVar5 + param_2 * 0xc;
  *(undefined4 *)(iVar6 + 0x28) = 1;
  *(undefined4 *)(iVar6 + 0x2c) = 1;
  if (param_1 == 1) {
    uVar4 = func_0x0214a2f4();
  }
  else {
    uVar4 = func_0x0214a314();
  }
  func_0x020232b0(uVar4,uVar3,uVar7,0,0,0x20,*(undefined2 *)(DAT_021d237c + param_1 * 2),0xf);
  FUN_021d2060(iVar6,0);
  uVar4 = FUN_021d3544(1,DAT_021d2380,*DAT_021d2360 + DAT_021d2384 + param_1,200);
  *(undefined4 *)(iVar6 + 0x34) = uVar4;
  return iVar6;
}

