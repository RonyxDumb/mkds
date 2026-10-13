/* Decompiled C draft; module arm9_ov001; ROM address 0219e5d4. No matching claim. */
#include "types.h"
#include "deps/0219e5d4_FUN_0219e5d4.h"

void FUN_0219e5d4(int param_1)

{
  int iVar1;
  
  param_1 = param_1 * 4;
  iVar1 = *(int *)(*DAT_0219e65c + param_1 + 0x38);
  func_0x02016468(4,0,*(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(iVar1 + 0x10));
  iVar1 = *(int *)(*DAT_0219e65c + param_1 + 0x40);
  func_0x02016468(8,0,iVar1 + 0xc,*(undefined4 *)(iVar1 + 8));
  iVar1 = *(int *)(*DAT_0219e65c + param_1 + 0x48);
  func_0x02016468(0xf,0,*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
  iVar1 = *(int *)(*DAT_0219e65c + param_1 + 0x50);
  func_0x02016468(0x14,0,*(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(iVar1 + 0x10));
  iVar1 = *(int *)(*DAT_0219e65c + param_1 + 0x58);
  func_0x02016468(0x18,0,iVar1 + 0xc,*(undefined4 *)(iVar1 + 8));
  iVar1 = *(int *)(*DAT_0219e65c + param_1 + 0x60);
  func_0x02016468(0x1f,0,*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
  return;
}

