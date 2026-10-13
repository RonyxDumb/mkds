/* Decompiled C draft; module arm9_ov001; ROM address 021a0e7c. No matching claim. */
#include "types.h"
#include "deps/021a0e7c_FUN_021a0e7c.h"

void FUN_021a0e7c(void)

{
  undefined4 uVar1;
  int iVar2;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10 [2];
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10[0] = 0;
  uVar1 = func_0x0204799c(*DAT_021a1064);
  func_0x020b4934(&local_1c,uVar1);
  uVar1 = func_0x0204799c(*DAT_021a1068);
  func_0x020b4a44(local_10,uVar1);
  uVar1 = func_0x0204799c(*DAT_021a106c);
  func_0x020b47d8(&local_18,uVar1);
  uVar1 = func_0x0204799c(*DAT_021a1070);
  func_0x020b47d8(&local_14,uVar1);
  uVar1 = func_0x02036bec(*(undefined4 *)(*DAT_021a1074 + 0x5c),DAT_021a1078);
  *(undefined4 *)(*DAT_021a1074 + 0x48) = uVar1;
  uVar1 = func_0x0204799c(*DAT_021a107c);
  *(undefined4 *)(*DAT_021a1074 + 4) = uVar1;
  uVar1 = func_0x0204799c(*DAT_021a1080);
  *(undefined4 *)(*DAT_021a1074 + 8) = uVar1;
  uVar1 = func_0x0204799c(*DAT_021a1084);
  func_0x020b49bc(&local_28,uVar1);
  uVar1 = func_0x0204799c(*DAT_021a1088);
  func_0x020b48b4((int *)(uintptr_t)(*DAT_021a1074),uVar1);
  uVar1 = func_0x0204799c(*DAT_021a108c);
  func_0x020b4a44(&local_24,uVar1);
  uVar1 = func_0x0204799c(*DAT_021a1090);
  *(undefined4 *)(*DAT_021a1074 + 0x10) = uVar1;
  uVar1 = func_0x0204799c(*DAT_021a1094);
  *(undefined4 *)(*DAT_021a1074 + 0x14) = uVar1;
  uVar1 = func_0x0204799c(*DAT_021a1098);
  *(undefined4 *)(*DAT_021a1074 + 0x18) = uVar1;
  uVar1 = func_0x0204799c(*DAT_021a109c);
  func_0x020b49bc(&local_20,uVar1);
  uVar1 = func_0x0204799c(*DAT_021a10a0);
  func_0x020b48b4((int *)(uintptr_t)(*DAT_021a1074 + 0xc),uVar1);
  uVar1 = func_0x0204799c(*DAT_021a10a4);
  func_0x020b4a44((int *)(uintptr_t)(*DAT_021a1074 + 0x1c),uVar1);
  iVar2 = *(int *)(local_24 + 0xc);
  func_0x02016468(4,0,*(undefined4 *)(local_1c + 0x14),*(undefined4 *)(local_1c + 0x10));
  func_0x02016468(0xf,0,*(undefined4 *)(local_10[0] + 0xc),0x40);
  func_0x02016468(8,0,local_18 + 0xc,*(undefined4 *)(local_18 + 8));
  func_0x02016468(8,DAT_021a1078,*(undefined4 *)(*DAT_021a1074 + 0x48),DAT_021a1078);
  func_0x02016468(8,DAT_021a10a8,*(undefined4 *)(*DAT_021a1074 + 0x48),DAT_021a1078);
  func_0x02016468(8,DAT_021a10ac,*(undefined4 *)(*DAT_021a1074 + 0x48),DAT_021a1078);
  func_0x02016468(9,0,local_14 + 0xc,*(undefined4 *)(local_14 + 8));
  func_0x02016468(9,DAT_021a1078,*(undefined4 *)(*DAT_021a1074 + 0x48),DAT_021a1078);
  func_0x02016468(0x13,0,*(undefined4 *)(local_28 + 0x14),*(undefined4 *)(local_28 + 0x10));
  func_0x02016468(0xe,0,*(undefined4 *)(local_24 + 0xc),DAT_021a10b0);
  func_0x02016468(0xe,DAT_021a10b4,iVar2 + DAT_021a10b4,0x40);
  func_0x02016468(0x23,0,*(undefined4 *)(local_20 + 0x14),*(undefined4 *)(local_20 + 0x10));
  func_0x02016468(0x1e,0,*(undefined4 *)(*(int *)(*DAT_021a1074 + 0x1c) + 0xc),
                  *(undefined4 *)(*(int *)(*DAT_021a1074 + 0x1c) + 8));
  return;
}

