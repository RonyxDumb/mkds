/* Decompiled C draft; module arm9_ov000; ROM address 021b003c. No matching claim. */
#include "types.h"
#include "deps/021b003c_FUN_021b003c.h"

undefined4 FUN_021b003c(int param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = 1;
  bVar3 = true;
  bVar2 = true;
  bVar1 = true;
  if ((*DAT_021b008c != 0) && (param_1 != *DAT_021b008c)) {
    bVar1 = false;
  }
  if ((!bVar1) && (param_1 != DAT_021b0090)) {
    bVar2 = false;
  }
  if ((!bVar2) && (iVar4 = FUN_021b00b0(param_1), iVar4 == 0)) {
    bVar3 = false;
  }
  if ((!bVar3) && (iVar4 = FUN_021b0094(param_1), iVar4 == 0)) {
    uVar5 = 0;
  }
  return uVar5;
}

