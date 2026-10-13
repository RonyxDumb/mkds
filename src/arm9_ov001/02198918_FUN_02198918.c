/* Decompiled C draft; module arm9_ov001; ROM address 02198918. No matching claim. */
#include "types.h"
#include "deps/02198918_FUN_02198918.h"

void FUN_02198918(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_021989b8;
  *(undefined4 *)*DAT_021989b8 = ((undefined4 *)*DAT_021989b8)[1];
  switch(*(undefined4 *)*piVar1) {
  case 0:
    FUN_021992dc();
    break;
  case 1:
    FUN_021992a0();
    break;
  case 2:
    FUN_02198ec0();
    break;
  case 3:
    FUN_02198e94();
    break;
  case 4:
    FUN_02198d8c();
    break;
  case 5:
    FUN_02198d20();
  }
  func_0x0212b80c();
  FUN_02198bbc();
  FUN_02198b58();
  FUN_02198a6c();
  FUN_021989bc();
  iVar3 = *DAT_021989b8;
  uVar2 = FUN_0219e920();
  func_0x02124c30(*(undefined4 *)(iVar3 + 0x74),*(undefined4 *)(iVar3 + 0x5c),
                  *(undefined4 *)(iVar3 + 0x80),uVar2,*(undefined4 *)(iVar3 + 0x54));
  iVar3 = *DAT_021989b8;
  uVar2 = FUN_0219e90c();
  func_0x02124c30(*(undefined4 *)(iVar3 + 0x78),*(undefined4 *)(iVar3 + 0x60),
                  *(undefined4 *)(iVar3 + 0x84),uVar2,*(undefined4 *)(iVar3 + 0x58));
  return;
}

