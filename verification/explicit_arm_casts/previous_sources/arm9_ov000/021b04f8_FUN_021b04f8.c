/* Decompiled C draft; module arm9_ov000; ROM address 021b04f8. No matching claim. */
#include "types.h"
#include "deps/021b04f8_FUN_021b04f8.h"

void FUN_021b04f8(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = *DAT_021b0598;
  *DAT_021b059c = param_1;
  *DAT_021b0598 = 0;
  *DAT_021b05a0 = 0;
  *DAT_021b05a4 = 0;
  puVar1 = DAT_021b05a8;
  *DAT_021b05a8 = 0;
  puVar1[1] = 0;
  *DAT_021b05ac = 0;
  if (iVar2 != 0) {
    func_0x0214d168(DAT_021b05b0,0,0x60);
    iVar4 = DAT_021b05b8;
    puVar1 = DAT_021b05bc;
    for (iVar2 = *(int *)(DAT_021b05b4 + 8); DAT_021b05b8 = iVar4, DAT_021b05bc = puVar1, iVar2 != 0
        ; iVar2 = *(int *)(iVar2 + 0x68)) {
      piVar3 = *(int **)(iVar2 + 0xa4);
      if ((piVar3 != (int *)0x0) && (*piVar3 != 0)) {
        if (((char)piVar3[2] != '\n') && ((char)piVar3[2] != '\v')) {
          *(undefined1 *)(piVar3 + 2) = 0;
        }
        if (piVar3[1] != 0) {
          piVar3[1] = 0;
          func_0x0200df68(*piVar3);
        }
      }
      iVar4 = DAT_021b05b8;
      puVar1 = DAT_021b05bc;
    }
    iVar2 = 0;
    do {
      if (*(short *)(iVar4 + 4) != 0) {
        (*(code *)*puVar1)(*(undefined4 *)(iVar4 + 0x34));
        *(undefined2 *)(iVar4 + 4) = 0;
      }
      iVar4 = iVar4 + 0x38;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    FUN_021a91b4();
  }
  return;
}

