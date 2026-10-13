/* Decompiled C draft; module arm9_ov000; ROM address 02182084. No matching claim. */
#include "types.h"
#include "deps/02182084_FUN_02182084.h"

void FUN_02182084(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_0218213c;
  *(undefined4 *)*DAT_0218213c = ((undefined4 *)*DAT_0218213c)[1];
  switch(*(undefined4 *)*piVar1) {
  case 0:
    FUN_02182d74();
    break;
  case 1:
    FUN_02182d28();
    break;
  case 2:
    FUN_02182cb8();
    break;
  case 3:
    FUN_02182c60();
    break;
  case 4:
    FUN_021828e4();
    break;
  case 5:
    FUN_02182878();
    break;
  case 6:
    FUN_02182688();
    break;
  case 7:
    FUN_021825b8();
    break;
  case 8:
    FUN_021824e8();
    break;
  case 9:
    FUN_02182474();
    break;
  case 10:
    FUN_021823e4();
    break;
  case 0xb:
    FUN_021823b0();
  }
  func_0x0212b80c();
  FUN_02182270();
  FUN_021821e0();
  FUN_02182150();
  iVar3 = *DAT_0218213c;
  uVar2 = func_ov000_021804e0();
  func_0x02124c30(*(undefined4 *)(iVar3 + DAT_02182144),*(undefined4 *)(iVar3 + DAT_02182148),
                  *(undefined4 *)(iVar3 + DAT_0218214c),uVar2,*(undefined4 *)(iVar3 + DAT_02182140))
  ;
  return;
}

