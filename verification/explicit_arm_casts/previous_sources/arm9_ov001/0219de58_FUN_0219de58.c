/* Decompiled C draft; module arm9_ov001; ROM address 0219de58. No matching claim. */
#include "types.h"
#include "deps/0219de58_FUN_0219de58.h"

void FUN_0219de58(void)

{
  undefined4 uVar1;
  int local_10;
  int local_c;
  int local_8 [2];
  
  uVar1 = func_0x0204799c(DAT_0219df38);
  func_0x020b4934(&local_10,uVar1);
  uVar1 = func_0x0204799c(DAT_0219df3c);
  func_0x020b47d8(&local_c,uVar1);
  uVar1 = func_0x0204799c(DAT_0219df40);
  func_0x020b4a44(local_8,uVar1);
  uVar1 = func_0x0204799c(DAT_0219df44);
  *(undefined4 *)(*DAT_0219df48 + 0x44) = uVar1;
  uVar1 = func_0x0204799c(DAT_0219df4c);
  *(undefined4 *)(*DAT_0219df48 + 0x48) = uVar1;
  uVar1 = func_0x0204799c(DAT_0219df50);
  *(undefined4 *)(*DAT_0219df48 + 0x4c) = uVar1;
  uVar1 = func_0x0204799c(DAT_0219df54);
  func_0x020b49bc(*DAT_0219df48 + 0x3c,uVar1);
  uVar1 = func_0x0204799c(DAT_0219df58);
  func_0x020b48b4(*DAT_0219df48 + 0x38,uVar1);
  uVar1 = func_0x0204799c(DAT_0219df5c);
  func_0x020b4a44(*DAT_0219df48 + 0x40,uVar1);
  func_0x02016468(4,0,*(undefined4 *)(local_10 + 0x14),*(undefined4 *)(local_10 + 0x10));
  func_0x02016468(8,0,local_c + 0xc,*(undefined4 *)(local_c + 8));
  func_0x02016468(0xf,0,*(undefined4 *)(local_8[0] + 0xc),DAT_0219df60);
  func_0x02016468(0x23,0,*(undefined4 *)(*(int *)(*DAT_0219df48 + 0x3c) + 0x14),
                  *(undefined4 *)(*(int *)(*DAT_0219df48 + 0x3c) + 0x10));
  func_0x02016468(0x1e,0,*(undefined4 *)(*(int *)(*DAT_0219df48 + 0x40) + 0xc),
                  *(undefined4 *)(*(int *)(*DAT_0219df48 + 0x40) + 8));
  return;
}

