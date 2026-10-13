/* Decompiled C draft; module arm9_ov000; ROM address 0218536c. No matching claim. */
#include "types.h"
#include "deps/0218536c_FUN_0218536c.h"

void FUN_0218536c(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = DAT_021853c0;
  *(undefined4 *)*DAT_021853c0 = ((undefined4 *)*DAT_021853c0)[1];
  iVar2 = *(int *)*piVar1;
  if (iVar2 == 0) {
    FUN_021854a8();
  }
  else if (iVar2 == 1) {
    FUN_02185418();
  }
  else if (iVar2 == 2) {
    FUN_021853c4();
  }
  FUN_021854f8();
  iVar2 = *DAT_021853c0;
  uVar3 = func_ov000_021804f4();
  func_0x02124c30(*(undefined4 *)(iVar2 + 0x40),*(undefined4 *)(iVar2 + 0x34),
                  *(undefined4 *)(iVar2 + 0x48),uVar3,*(undefined4 *)(iVar2 + 0x30));
  return;
}

