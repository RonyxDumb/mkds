/* Decompiled C draft; module arm9_ov000; ROM address 021a8424. No matching claim. */
#include "types.h"
#include "deps/021a8424_FUN_021a8424.h"

void FUN_021a8424(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = func_0x0200fca0();
  piVar1 = DAT_021a8450;
  iVar3 = *DAT_021a8450;
  while (iVar3 != 0) {
    FUN_021a84c4();
    iVar3 = *piVar1;
  }
  func_0x0200fcb4(uVar2);
  return;
}

