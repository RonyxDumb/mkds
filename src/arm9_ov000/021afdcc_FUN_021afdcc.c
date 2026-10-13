/* Decompiled C draft; module arm9_ov000; ROM address 021afdcc. No matching claim. */
#include "types.h"
#include "deps/021afdcc_FUN_021afdcc.h"

int FUN_021afdcc(int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  puVar3 = DAT_021afe4c;
  piVar2 = DAT_021afe48;
  piVar1 = DAT_021afe44;
  if (*DAT_021afe44 == *DAT_021afe48) {
    do {
      *puVar3 = *(undefined4 *)(DAT_021afe50 + 4);
      func_0x0200e01c(0);
      *puVar3 = 0;
    } while (*piVar1 == *piVar2);
  }
  piVar1 = DAT_021afe44;
  iVar5 = *DAT_021afe54;
  iVar4 = *DAT_021afe58;
  while( true ) {
    if ((uint)(iVar5 - *piVar1) < 2) {
      *piVar1 = 0;
    }
    uVar6 = (uint)*(byte *)(iVar4 + *piVar1) + (uint)*(byte *)(iVar4 + *piVar1 + 1) * 0x100 & 0xffff
    ;
    if (uVar6 != 0) break;
    *piVar1 = 0;
  }
  *param_1 = uVar6 - 2;
  return *DAT_021afe58 + *DAT_021afe44 + 2;
}

