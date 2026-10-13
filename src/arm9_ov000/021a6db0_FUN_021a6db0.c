/* Decompiled C draft; module arm9_ov000; ROM address 021a6db0. No matching claim. */
#include "types.h"
#include "deps/021a6db0_FUN_021a6db0.h"

void FUN_021a6db0(void)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  puVar1 = DAT_021a6e78;
  piVar6 = (int *)*DAT_021a6e7c;
  func_0x0214d168(DAT_021a6e78,0,0x30);
  puVar1[1] = piVar6[6];
  puVar1[2] = piVar6[7];
  puVar1[4] = DAT_021a6e80;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[0xb] = *DAT_021a6e84;
  if (piVar6[9] == 0) {
    puVar1[8] = DAT_021a6e88;
  }
  else {
    puVar1[8] = piVar6[9];
  }
  if (piVar6[10] == 0) {
    uVar3 = (**(code **)(*DAT_021a6e7c + 0x18))(puVar1[8]);
    puVar1[7] = uVar3;
  }
  else {
    puVar1[7] = piVar6[10];
  }
  iVar5 = piVar6[0xc];
  if (piVar6[0xc] == 0) {
    iVar5 = DAT_021a6e8c;
  }
  iVar4 = piVar6[0xd];
  if (piVar6[0xd] == 0) {
    iVar4 = DAT_021a6e90;
  }
  puVar1[9] = iVar5 + -0x28;
  *(short *)(DAT_021a6e94 + 2) = (short)iVar4;
  uVar2 = func_0x02133068(iVar4,2);
  *(undefined2 *)(DAT_021a6e94 + 4) = uVar2;
  *DAT_021a6e98 = 0;
  if (*piVar6 == 0) {
    *DAT_021a6e9c = 0;
    *puVar1 = 1;
    puVar1[3] = DAT_021a6ea8;
  }
  else {
    *DAT_021a6e9c = 1;
    *puVar1 = 0;
    puVar1[3] = DAT_021a6ea0;
    puVar1[10] = *DAT_021a6ea4;
  }
  iVar5 = piVar6[0xb];
  if (iVar5 == 0) {
    iVar5 = 0xb;
  }
  FUN_021b0240(iVar5);
  FUN_021a6aa0(DAT_021a6eac);
  FUN_021b02b0(DAT_021a6eb0);
  FUN_021b02fc(puVar1);
  return;
}

