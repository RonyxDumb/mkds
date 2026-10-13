/* Decompiled C draft; module arm9_ov001; ROM address 0219e858. No matching claim. */
#include "types.h"
#include "deps/0219e858_FUN_0219e858.h"

void FUN_0219e858(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  func_0x020ae6ac(*DAT_0219e894,*DAT_0219e894 + DAT_0219e898);
  FUN_02198554();
  func_0x020ae630(*DAT_0219e894,*DAT_0219e894 + DAT_0219e898);
  if ((param_1 != 0) && (iVar2 = FUN_0219853c(), iVar2 != -1)) {
    uVar1 = FUN_0219853c();
    *(undefined2 *)(param_1 + 4) = uVar1;
  }
  return;
}

