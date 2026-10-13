/* Decompiled C draft; module arm9_ov000; ROM address 021afd00. No matching claim. */
#include "types.h"
#include "deps/021afd00_FUN_021afd00.h"

int * FUN_021afd00(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 extraout_var;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  
  uVar1 = func_0x0200fca0();
  piVar5 = DAT_021afd7c;
  if ((((param_1 != DAT_021afd74) && (param_1 != *DAT_021afd78)) &&
      (iVar2 = FUN_021b00b0(param_1), piVar5 = DAT_021afd80, iVar2 == 0)) &&
     (iVar2 = FUN_021b0094(param_1), piVar5 = DAT_021afd80, iVar2 == 0)) {
    uVar4 = 0;
    piVar3 = DAT_021afd84;
    do {
      if (param_1 == *piVar3) {
        func_0x0200f5ac();
        *(undefined2 *)(DAT_021afd88 + uVar4 * 0xc) = extraout_var;
        piVar5 = DAT_021afd84 + uVar4 * 3 + 1;
        break;
      }
      piVar3 = piVar3 + 3;
      uVar4 = uVar4 + 1;
      piVar5 = (int *)0x0;
    } while (uVar4 < 8);
  }
  func_0x0200fcb4(uVar1);
  return piVar5;
}

