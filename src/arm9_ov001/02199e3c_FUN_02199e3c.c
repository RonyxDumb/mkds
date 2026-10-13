/* Decompiled C draft; module arm9_ov001; ROM address 02199e3c. No matching claim. */
#include "types.h"
#include "deps/02199e3c_FUN_02199e3c.h"

void FUN_02199e3c(void)

{
  undefined4 uVar1;
  int local_10;
  int local_c;
  int local_8 [2];
  
  uVar1 = func_0x0204799c(DAT_02199f10);
  func_0x020b4934(&local_10,uVar1);
  uVar1 = func_0x0204799c(DAT_02199f14);
  func_0x020b47d8(&local_c,uVar1);
  uVar1 = func_0x0204799c(DAT_02199f18);
  func_0x020b4a44(local_8,uVar1);
  uVar1 = func_0x0204799c(DAT_02199f1c);
  *(undefined4 *)(*DAT_02199f20 + 0x2c) = uVar1;
  uVar1 = func_0x0204799c(DAT_02199f24);
  *(undefined4 *)(*DAT_02199f20 + 0x30) = uVar1;
  uVar1 = func_0x0204799c(DAT_02199f28);
  func_0x020b49bc((int *)(uintptr_t)(*DAT_02199f20 + 0x24),uVar1);
  uVar1 = func_0x0204799c(DAT_02199f2c);
  func_0x020b48b4((int *)(uintptr_t)(*DAT_02199f20 + 0x20),uVar1);
  uVar1 = func_0x0204799c(DAT_02199f30);
  func_0x020b4a44((int *)(uintptr_t)(*DAT_02199f20 + 0x28),uVar1);
  func_0x02016468(4,0,*(undefined4 *)(local_10 + 0x14),*(undefined4 *)(local_10 + 0x10));
  func_0x02016468(8,0,local_c + 0xc,*(undefined4 *)(local_c + 8));
  func_0x02016468(0xf,0,*(undefined4 *)(local_8[0] + 0xc),DAT_02199f34);
  func_0x02016468(0x23,0,*(undefined4 *)(*(int *)(*DAT_02199f20 + 0x24) + 0x14),
                  *(undefined4 *)(*(int *)(*DAT_02199f20 + 0x24) + 0x10));
  func_0x02016468(0x1e,0,*(undefined4 *)(*(int *)(*DAT_02199f20 + 0x28) + 0xc),
                  *(undefined4 *)(*(int *)(*DAT_02199f20 + 0x28) + 8));
  return;
}

