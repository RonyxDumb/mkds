/* Decompiled C draft; module arm9_ov000; ROM address 0218338c. No matching claim. */
#include "types.h"
#include "deps/0218338c_FUN_0218338c.h"

void FUN_0218338c(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_02183430;
  *(undefined4 *)*DAT_02183430 = ((undefined4 *)*DAT_02183430)[1];
  switch(*(undefined4 *)*piVar1) {
  case 0:
    FUN_0218401c();
    break;
  case 1:
    FUN_02183b80();
    break;
  case 2:
    FUN_02183a0c();
    break;
  case 3:
    FUN_021839d0();
    break;
  case 4:
    FUN_02183858();
    break;
  case 5:
    FUN_0218381c();
    break;
  case 8:
    FUN_021837b8();
    break;
  case 9:
    FUN_021836f4();
    break;
  case 10:
    FUN_02183674();
    break;
  case 0xb:
    FUN_0218364c();
  }
  FUN_02183548();
  FUN_02183444();
  iVar3 = *DAT_02183430;
  uVar2 = func_ov000_021804e0();
  func_0x02124c30(*(undefined4 *)(iVar3 + DAT_02183438),*(undefined4 *)(iVar3 + DAT_0218343c),
                  *(undefined4 *)(iVar3 + DAT_02183440),uVar2,*(undefined4 *)(iVar3 + DAT_02183434))
  ;
  return;
}

