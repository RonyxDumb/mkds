/* Decompiled C draft; module arm9_ov001; ROM address 0219c544. No matching claim. */
#include "types.h"
#include "deps/0219c544_FUN_0219c544.h"

void FUN_0219c544(void)

{
  undefined4 uVar1;
  int local_18;
  int local_14;
  int local_10;
  int local_c [3];
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c[0] = 0;
  uVar1 = func_0x0204799c(*DAT_0219c6b8);
  func_0x020b4934(&local_14,uVar1);
  uVar1 = func_0x0204799c(*DAT_0219c6bc);
  func_0x020b47d8(local_c,uVar1);
  uVar1 = func_0x0204799c(*DAT_0219c6c0);
  func_0x020b4a44(&local_10,uVar1);
  uVar1 = func_0x02036bec(*(undefined4 *)(*DAT_0219c6c4 + 0x44),DAT_0219c6c8);
  *(undefined4 *)(*DAT_0219c6c4 + 0x40) = uVar1;
  uVar1 = func_0x0204799c(*DAT_0219c6cc);
  *(undefined4 *)(*DAT_0219c6c4 + 4) = uVar1;
  uVar1 = func_0x0204799c(*DAT_0219c6d0);
  *(undefined4 *)(*DAT_0219c6c4 + 8) = uVar1;
  uVar1 = func_0x0204799c(*DAT_0219c6d4);
  func_0x020b48b4((int *)(uintptr_t)(*DAT_0219c6c4),uVar1);
  uVar1 = func_0x0204799c(*DAT_0219c6d8);
  *(undefined4 *)(*DAT_0219c6c4 + 0x10) = uVar1;
  uVar1 = func_0x0204799c(*DAT_0219c6dc);
  *(undefined4 *)(*DAT_0219c6c4 + 0x14) = uVar1;
  uVar1 = func_0x0204799c(*DAT_0219c6e0);
  *(undefined4 *)(*DAT_0219c6c4 + 0x18) = uVar1;
  uVar1 = func_0x0204799c(*DAT_0219c6e4);
  func_0x020b49bc(&local_18,uVar1);
  uVar1 = func_0x0204799c(*DAT_0219c6e8);
  func_0x020b48b4((int *)(uintptr_t)(*DAT_0219c6c4 + 0xc),uVar1);
  uVar1 = func_0x0204799c(*DAT_0219c6ec);
  func_0x020b4a44((int *)(uintptr_t)(*DAT_0219c6c4 + 0x1c),uVar1);
  uVar1 = func_0x020b4018(0);
  *(undefined4 *)(*DAT_0219c6c4 + 0x20) = uVar1;
  uVar1 = func_0x020b400c(0);
  *(undefined4 *)(*DAT_0219c6c4 + 0x24) = uVar1;
  uVar1 = func_0x020b4030(0);
  *(undefined4 *)(*DAT_0219c6c4 + 0x28) = uVar1;
  uVar1 = func_0x020b4000(0);
  *(undefined4 *)(*DAT_0219c6c4 + 0x2c) = uVar1;
  func_0x02016468(0x17,0,*(undefined4 *)(local_14 + 0x14),*(undefined4 *)(local_14 + 0x10));
  func_0x02016468(0x1f,0,*(undefined4 *)(local_10 + 0xc),0x20);
  func_0x02016468(0x1b,0,local_c[0] + 0xc,*(undefined4 *)(local_c[0] + 8));
  func_0x02016468(0x1b,DAT_0219c6c8,*(undefined4 *)(*DAT_0219c6c4 + 0x40),DAT_0219c6c8);
  func_0x02016468(0x23,0,*(undefined4 *)(local_18 + 0x14),*(undefined4 *)(local_18 + 0x10));
  func_0x02016468(0x1e,0,*(undefined4 *)(*(int *)(*DAT_0219c6c4 + 0x1c) + 0xc),
                  *(undefined4 *)(*(int *)(*DAT_0219c6c4 + 0x1c) + 8));
  return;
}

