/* Decompiled C draft; module arm9_ov001; ROM address 0219e960. No matching claim. */
#include "types.h"
#include "deps/0219e960_FUN_0219e960.h"

void FUN_0219e960(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  func_0x020ae6ac(*DAT_0219e99c,*DAT_0219e99c + DAT_0219e9a0);
  FUN_02192ee4();
  func_0x020ae630(*DAT_0219e99c,*DAT_0219e99c + DAT_0219e9a0);
  if ((param_1 != 0) && (iVar2 = FUN_02192e84(), iVar2 != -1)) {
    uVar1 = FUN_02192e84();
    *(undefined2 *)(param_1 + 4) = uVar1;
  }
  return;
}

