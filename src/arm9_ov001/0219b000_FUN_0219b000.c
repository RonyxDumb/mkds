/* Decompiled C draft; module arm9_ov001; ROM address 0219b000. No matching claim. */
#include "types.h"
#include "deps/0219b000_FUN_0219b000.h"

void FUN_0219b000(void)

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
  uVar1 = func_0x0204799c(*DAT_0219b180);
  func_0x020b4934(&local_18,uVar1);
  uVar1 = func_0x0204799c(*DAT_0219b184);
  func_0x020b4a44(&local_14,uVar1);
  uVar1 = func_0x0204799c(*DAT_0219b188);
  func_0x020b47d8(local_10,uVar1);
  uVar1 = func_0x02036bec(*(undefined4 *)(*DAT_0219b18c + 0x2c),DAT_0219b190);
  *(undefined4 *)(*DAT_0219b18c + 0x28) = uVar1;
  uVar1 = func_0x0204799c(*DAT_0219b194);
  *(undefined4 *)(*DAT_0219b18c + 4) = uVar1;
  uVar1 = func_0x0204799c(*DAT_0219b198);
  *(undefined4 *)(*DAT_0219b18c + 8) = uVar1;
  uVar1 = func_0x0204799c(*DAT_0219b19c);
  func_0x020b49bc(&local_28,uVar1);
  uVar1 = func_0x0204799c(*DAT_0219b1a0);
  func_0x020b48b4((int *)(uintptr_t)(*DAT_0219b18c),uVar1);
  uVar1 = func_0x0204799c(*DAT_0219b1a4);
  func_0x020b4a44(&local_24,uVar1);
  uVar1 = func_0x0204799c(*DAT_0219b1a8);
  *(undefined4 *)(*DAT_0219b18c + 0x10) = uVar1;
  uVar1 = func_0x0204799c(*DAT_0219b1ac);
  *(undefined4 *)(*DAT_0219b18c + 0x14) = uVar1;
  uVar1 = func_0x0204799c(*DAT_0219b1b0);
  func_0x020b49bc(&local_20,uVar1);
  uVar1 = func_0x0204799c(*DAT_0219b1b4);
  func_0x020b48b4((int *)(uintptr_t)(*DAT_0219b18c + 0xc),uVar1);
  uVar1 = func_0x0204799c(*DAT_0219b1b8);
  func_0x020b4a44(&local_1c,uVar1);
  iVar2 = *(int *)(local_24 + 0xc);
  func_0x02016468(4,0,*(undefined4 *)(local_18 + 0x14),*(undefined4 *)(local_18 + 0x10));
  func_0x02016468(0xf,0,*(undefined4 *)(local_14 + 0xc),0x60);
  func_0x02016468(8,0,local_10[0] + 0xc,*(undefined4 *)(local_10[0] + 8));
  func_0x02016468(8,DAT_0219b190,*(undefined4 *)(*DAT_0219b18c + 0x28),DAT_0219b190);
  func_0x02016468(0x13,0,*(undefined4 *)(local_28 + 0x14),*(undefined4 *)(local_28 + 0x10));
  func_0x02016468(0xe,0,*(undefined4 *)(local_24 + 0xc),DAT_0219b1bc);
  func_0x02016468(0xe,DAT_0219b1c0,iVar2 + DAT_0219b1c0,0x40);
  func_0x02016468(0x23,0,*(undefined4 *)(local_20 + 0x14),*(undefined4 *)(local_20 + 0x10));
  func_0x02016468(0x1e,0,*(undefined4 *)(local_1c + 0xc),*(undefined4 *)(local_1c + 8));
  return;
}

