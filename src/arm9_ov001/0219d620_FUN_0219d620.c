/* Decompiled C draft; module arm9_ov001; ROM address 0219d620. No matching claim. */
#include "types.h"
#include "deps/0219d620_FUN_0219d620.h"

void FUN_0219d620(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_0219d6a8;
  *(undefined4 *)*DAT_0219d6a8 = ((undefined4 *)*DAT_0219d6a8)[1];
  switch(*(undefined4 *)*piVar1) {
  case 0:
    FUN_0219de18();
    break;
  case 1:
    FUN_0219dd94();
    break;
  case 2:
    FUN_0219dd74();
    break;
  case 3:
    FUN_0219dadc();
    break;
  case 4:
    FUN_0219daa0();
    break;
  case 5:
    FUN_0219d998();
    break;
  case 6:
    FUN_0219d934();
  }
  FUN_0219d858();
  FUN_0219d810();
  FUN_0219d730();
  FUN_0219d6ac();
  iVar3 = *DAT_0219d6a8;
  uVar2 = FUN_0219e90c();
  func_0x02124c30(*(undefined4 *)(iVar3 + 0x44),*(undefined4 *)(iVar3 + 0x38),
                  *(undefined4 *)(iVar3 + 0x4c),uVar2,*(undefined4 *)(iVar3 + 0x34));
  return;
}

