/* Decompiled C draft; module arm9_ov001; ROM address 02193344. No matching claim. */
#include "types.h"
#include "deps/02193344_FUN_02193344.h"

void FUN_02193344(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_021933d8;
  *(undefined4 *)*DAT_021933d8 = ((undefined4 *)*DAT_021933d8)[1];
  switch(*(undefined4 *)*piVar1) {
  case 0:
    FUN_02193a00();
    break;
  case 1:
    FUN_02193944();
    break;
  case 2:
    FUN_02193924();
    break;
  case 3:
    FUN_02193774();
    break;
  case 4:
    FUN_02193730();
    break;
  case 5:
    FUN_021935f8();
    break;
  case 6:
    FUN_02193578();
    break;
  case 7:
    FUN_02193514();
    break;
  case 8:
    FUN_0219348c();
    break;
  case 9:
    FUN_02193448();
  }
  FUN_021933dc();
  iVar3 = *DAT_021933d8;
  uVar2 = FUN_0219e90c();
  func_0x02124c30(*(undefined4 *)(iVar3 + 0x30),*(undefined4 *)(iVar3 + 0x24),0,uVar2,
                  *(undefined4 *)(iVar3 + 0x20));
  return;
}

