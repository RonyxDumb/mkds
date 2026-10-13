/* Decompiled C draft; module arm9_ov001; ROM address 021999a8. No matching claim. */
#include "types.h"
#include "deps/021999a8_FUN_021999a8.h"

void FUN_021999a8(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_02199a1c;
  *(undefined4 *)*DAT_02199a1c = ((undefined4 *)*DAT_02199a1c)[1];
  switch(*(undefined4 *)*piVar1) {
  case 0:
    FUN_02199e1c();
    break;
  case 1:
    FUN_02199d88();
    break;
  case 2:
    FUN_02199d68();
    break;
  case 3:
    FUN_02199bb0();
    break;
  case 4:
    FUN_02199b6c();
    break;
  case 5:
    FUN_02199a8c();
  }
  FUN_02199a20();
  iVar3 = *DAT_02199a1c;
  uVar2 = FUN_0219e90c();
  func_0x02124c30(*(undefined4 *)(iVar3 + 0x2c),*(undefined4 *)(iVar3 + 0x20),0,uVar2,
                  *(undefined4 *)(iVar3 + 0x1c));
  return;
}

