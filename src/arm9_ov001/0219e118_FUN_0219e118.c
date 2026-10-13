/* Decompiled C draft; module arm9_ov001; ROM address 0219e118. No matching claim. */
#include "types.h"
#include "deps/0219e118_FUN_0219e118.h"

void FUN_0219e118(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_0219e1ac;
  *(undefined4 *)*DAT_0219e1ac = ((undefined4 *)*DAT_0219e1ac)[1];
  func_0x020ae6ac(*piVar1 + 0x68,0);
  switch(*(undefined4 *)*DAT_0219e1ac) {
  case 0:
    FUN_0219e34c();
    break;
  case 1:
    FUN_0219e310();
    break;
  case 2:
    FUN_0219e2f0();
    break;
  case 3:
    FUN_0219e2b4();
    break;
  case 4:
    FUN_0219e294();
    break;
  case 5:
    FUN_0219e1f8();
    break;
  case 6:
    FUN_0219e1d4();
    break;
  case 7:
    FUN_0219e1b0();
  }
  iVar2 = *DAT_0219e1ac;
  func_0x02124c30(*(undefined4 *)(iVar2 + 0x30),*(undefined4 *)(iVar2 + 0x24),
                  *(undefined4 *)(iVar2 + 0x34),iVar2 + 0x68,*(undefined4 *)(iVar2 + 0x20));
  func_0x020ae630(*DAT_0219e1ac + 0x68,0);
  return;
}

