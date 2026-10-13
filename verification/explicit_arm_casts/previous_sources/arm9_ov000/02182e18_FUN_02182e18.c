/* Decompiled C draft; module arm9_ov000; ROM address 02182e18. No matching claim. */
#include "types.h"
#include "deps/02182e18_FUN_02182e18.h"

void FUN_02182e18(void)

{
  undefined4 uVar1;
  int local_14;
  int local_10;
  int local_c [3];
  
  uVar1 = func_0x0204799c(DAT_02182f38);
  func_0x020b4934(&local_14,uVar1);
  uVar1 = func_0x0204799c(DAT_02182f3c);
  func_0x020b47d8(&local_10,uVar1);
  uVar1 = func_0x0204799c(DAT_02182f40);
  func_0x020b4a44(local_c,uVar1);
  uVar1 = func_0x0204799c(DAT_02182f44);
  *(undefined4 *)(*DAT_02182f48 + DAT_02182f4c) = uVar1;
  uVar1 = func_0x0204799c(DAT_02182f50);
  *(undefined4 *)(*DAT_02182f48 + DAT_02182f54) = uVar1;
  uVar1 = func_0x0204799c(DAT_02182f58);
  *(undefined4 *)(*DAT_02182f48 + DAT_02182f5c) = uVar1;
  uVar1 = func_0x0204799c(DAT_02182f60);
  func_0x020b49bc(*DAT_02182f48 + DAT_02182f64,uVar1);
  uVar1 = func_0x0204799c(DAT_02182f68);
  func_0x020b48b4(*DAT_02182f48 + DAT_02182f6c,uVar1);
  uVar1 = func_0x0204799c(DAT_02182f70);
  func_0x020b4a44(*DAT_02182f48 + DAT_02182f74,uVar1);
  *DAT_02182f78 = *DAT_02182f78 & 0x43 | (ushort)DAT_02182f7c;
  func_0x0214cfe4(0,*DAT_02182f48 + 0x38,DAT_02182f80);
  func_0x0214cffc(local_10 + 0xc,*DAT_02182f48 + 0x38,DAT_02182f84);
  func_0x02016468(0x17,0,*(undefined4 *)(local_14 + 0x14),*(undefined4 *)(local_14 + 0x10));
  func_0x02016468(0x1b,0,*DAT_02182f48 + 0x38,DAT_02182f80);
  func_0x02016468(0x1f,0,*(undefined4 *)(local_c[0] + 0xc),0x80);
  func_0x02016468(0x23,0,*(undefined4 *)(*(int *)(*DAT_02182f48 + DAT_02182f64) + 0x14),
                  *(undefined4 *)(*(int *)(*DAT_02182f48 + DAT_02182f64) + 0x10));
  func_0x02016468(0x1e,0,*(undefined4 *)(*(int *)(*DAT_02182f48 + DAT_02182f74) + 0xc),
                  *(undefined4 *)(*(int *)(*DAT_02182f48 + DAT_02182f74) + 8));
  return;
}

