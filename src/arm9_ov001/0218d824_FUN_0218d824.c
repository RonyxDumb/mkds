/* Decompiled C draft; module arm9_ov001; ROM address 0218d824. No matching claim. */
#include "types.h"
#include "deps/0218d824_FUN_0218d824.h"

void FUN_0218d824(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xa0);
  uVar1 = func_0x02133068(param_2 * *(int *)(iVar2 + 0x90),100);
  FUN_02188cd8(param_1,uVar1,*(undefined4 *)(iVar2 + 0x94));
  iVar2 = *(int *)(param_1 + 0xa0);
  uVar1 = func_0x02133068(param_2 * *(int *)(iVar2 + 0x98),100);
  FUN_02188c48(param_1,uVar1,*(undefined4 *)(iVar2 + 0x9c));
  uVar1 = FUN_02187ee8(param_1);
  FUN_02188998(param_1,(undefined4 *)(uintptr_t)(uVar1));
  return;
}

