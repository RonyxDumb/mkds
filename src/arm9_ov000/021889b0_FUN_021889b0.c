/* Decompiled C draft; module arm9_ov000; ROM address 021889b0. No matching claim. */
#include "types.h"
#include "deps/021889b0_FUN_021889b0.h"

void FUN_021889b0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_e4 [4];
  undefined4 local_e0;
  undefined4 local_dc;
  undefined1 auStack_d8 [196];
  
  iVar1 = param_2 + DAT_02188a68;
  param_2 = param_2 + DAT_02188a6c;
  iVar5 = param_1 + -1;
  if (-1 < iVar5) {
    iVar3 = iVar1 + iVar5 * 4;
    iVar4 = param_2 + iVar5 * 0xc0;
    do {
      if (*(byte *)(iVar1 + param_1 * 4 + 2) < *(byte *)(iVar3 + 2)) break;
      func_0x0214d02c((undefined4 *)(uintptr_t)(iVar3),(undefined4 *)(void *)(auStack_e4),4);
      iVar2 = iVar1 + param_1 * 4;
      func_0x0214d02c((undefined4 *)(uintptr_t)(iVar2),(undefined4 *)(uintptr_t)(iVar3),4);
      func_0x0214d02c((undefined4 *)(void *)(auStack_e4),(undefined4 *)(uintptr_t)(iVar2),4);
      func_0x0214d02c((undefined4 *)(uintptr_t)(iVar4),(undefined4 *)(void *)(auStack_d8),0xc0);
      iVar2 = param_2 + param_1 * 0xc0;
      func_0x0214d02c((undefined4 *)(uintptr_t)(iVar2),(undefined4 *)(uintptr_t)(iVar4),0xc0);
      func_0x0214d02c((undefined4 *)(void *)(auStack_d8),(undefined4 *)(uintptr_t)(iVar2),0xc0);
      iVar3 = iVar3 + -4;
      iVar4 = iVar4 + -0xc0;
      iVar2 = iVar5 + -1;
      param_1 = iVar5;
      iVar5 = iVar2;
    } while (-1 < iVar2);
  }
  local_e0 = 0;
  func_0x0214d018(0,(undefined4 *)(uintptr_t)(iVar1 + 0x28),4);
  local_dc = 0;
  func_0x0214d018(0,(undefined4 *)(uintptr_t)(param_2 + DAT_02188a70),0xc0);
  return;
}

