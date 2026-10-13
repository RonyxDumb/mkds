/* Decompiled C draft; module arm9_ov000; ROM address 02181758. No matching claim. */
#include "types.h"
#include "deps/02181758_FUN_02181758.h"

void FUN_02181758(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_021817e4;
  *(undefined4 *)*DAT_021817e4 = ((undefined4 *)*DAT_021817e4)[1];
  switch(*(undefined4 *)*piVar1) {
  case 0:
    FUN_02181dd0();
    break;
  case 1:
    FUN_02181d44();
    break;
  case 2:
    FUN_02181d20();
    break;
  case 3:
    FUN_02181b4c();
    break;
  case 4:
    FUN_02181ab8();
    break;
  case 5:
    FUN_0218198c();
    break;
  case 6:
    FUN_02181940();
    break;
  case 7:
    FUN_02181904();
    break;
  case 8:
    FUN_02181854();
  }
  FUN_021817e8();
  iVar3 = *DAT_021817e4;
  uVar2 = func_ov000_021804e0();
  func_0x02124c30(*(undefined4 *)(iVar3 + 0x2c),*(undefined4 *)(iVar3 + 0x20),0,uVar2,
                  *(undefined4 *)(iVar3 + 0x1c));
  return;
}

