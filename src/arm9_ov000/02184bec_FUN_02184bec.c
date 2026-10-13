/* Decompiled C draft; module arm9_ov000; ROM address 02184bec. No matching claim. */
#include "types.h"
#include "deps/02184bec_FUN_02184bec.h"

void FUN_02184bec(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_02184c70;
  *(undefined4 *)*DAT_02184c70 = ((undefined4 *)*DAT_02184c70)[1];
  switch(*(undefined4 *)*piVar1) {
  case 0:
    FUN_02185164();
    break;
  case 1:
    FUN_021850d0();
    break;
  case 2:
    FUN_021850b0();
    break;
  case 3:
    FUN_02184f1c();
    break;
  case 4:
    FUN_02184ed4();
    break;
  case 5:
    FUN_02184dbc();
    break;
  case 6:
    FUN_02184d4c();
    break;
  case 7:
    FUN_02184ce0();
  }
  FUN_02184c74();
  iVar3 = *DAT_02184c70;
  uVar2 = func_ov000_021804e0();
  func_0x02124c30(*(undefined4 *)(iVar3 + 0x2c),*(undefined4 *)(iVar3 + 0x20),0,uVar2,
                  *(undefined4 *)(iVar3 + 0x1c));
  return;
}

