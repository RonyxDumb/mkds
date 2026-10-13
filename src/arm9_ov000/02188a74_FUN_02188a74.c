/* Decompiled C draft; module arm9_ov000; ROM address 02188a74. No matching claim. */
#include "types.h"
#include "deps/02188a74_FUN_02188a74.h"

void FUN_02188a74(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_3 + DAT_02188ac8 + param_1 * 4;
  iVar4 = param_3 + DAT_02188acc;
  uVar1 = *(ushort *)(param_2 + 2);
  if ((uVar1 & 2) == 0) {
    uVar2 = ((int)(uint)uVar1 >> 2) + 0x19U & 0xff;
  }
  else {
    uVar2 = ((uint)uVar1 << 0x16) >> 0x18;
  }
  if (*(byte *)(iVar3 + 2) < uVar2) {
    *(char *)(iVar3 + 2) = (char)uVar2;
    *(char *)(iVar3 + 3) = *(char *)(param_3 + DAT_02188ad0) + '\x01';
  }
  func_0x0214d02c((undefined4 *)(uintptr_t)(param_2),(undefined4 *)(uintptr_t)(iVar4 + param_1 * 0xc0),0xc0);
  return;
}

