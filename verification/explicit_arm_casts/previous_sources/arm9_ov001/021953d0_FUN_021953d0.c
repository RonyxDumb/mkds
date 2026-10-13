/* Decompiled C draft; module arm9_ov001; ROM address 021953d0. No matching claim. */
#include "types.h"
#include "deps/021953d0_FUN_021953d0.h"

void FUN_021953d0(void)

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
  uVar1 = func_0x0204799c(*DAT_02195674);
  func_0x020b49bc(*DAT_02195678,uVar1);
  uVar1 = func_0x0204799c(*DAT_0219567c);
  func_0x020b48b4(*DAT_02195678 + 4,uVar1);
  uVar1 = func_0x0204799c(*DAT_02195680);
  func_0x020b4a44(&local_28,uVar1);
  uVar1 = func_0x0204799c(*DAT_02195684);
  *(undefined4 *)(*DAT_02195678 + 8) = uVar1;
  uVar1 = func_0x0204799c(*DAT_02195688);
  *(undefined4 *)(*DAT_02195678 + 0x10) = uVar1;
  uVar1 = func_0x0204799c(*DAT_0219568c);
  func_0x020b49bc(*DAT_02195678 + 0x14,uVar1);
  uVar1 = func_0x0204799c(*DAT_02195690);
  func_0x020b48b4(*DAT_02195678 + 0x18,uVar1);
  uVar1 = func_0x0204799c(*DAT_02195694);
  func_0x020b4a44(&local_18,uVar1);
  uVar1 = func_0x0204799c(*DAT_02195698);
  *(undefined4 *)(*DAT_02195678 + 0x1c) = uVar1;
  uVar1 = func_0x0204799c(*DAT_0219569c);
  *(undefined4 *)(*DAT_02195678 + 0x20) = uVar1;
  uVar1 = func_0x0204799c(*DAT_021956a0);
  *(undefined4 *)(*DAT_02195678 + 0x24) = uVar1;
  uVar1 = func_0x0204799c(*DAT_021956a4);
  func_0x020b49bc(*DAT_02195678 + 0x28,uVar1);
  uVar1 = func_0x0204799c(*DAT_021956a8);
  func_0x020b48b4(*DAT_02195678 + 0x2c,uVar1);
  uVar1 = func_0x0204799c(*DAT_021956ac);
  func_0x020b4a44(*DAT_02195678 + 0x30,uVar1);
  uVar1 = func_0x0204799c(*DAT_021956b0);
  *(undefined4 *)(*DAT_02195678 + 0x34) = uVar1;
  uVar1 = func_0x020b4018(0);
  *(undefined4 *)(*DAT_02195678 + 0x38) = uVar1;
  uVar1 = func_0x020b400c(0);
  *(undefined4 *)(*DAT_02195678 + 0x3c) = uVar1;
  uVar1 = func_0x020b4030(0);
  *(undefined4 *)(*DAT_02195678 + 0x40) = uVar1;
  uVar1 = func_0x020b4000(0);
  *(undefined4 *)(*DAT_02195678 + 0x44) = uVar1;
  uVar1 = func_0x0204799c(*DAT_021956b4);
  func_0x020b4934(&local_24,uVar1);
  uVar1 = func_0x0204799c(*DAT_021956b8);
  func_0x020b4a44(&local_20,uVar1);
  uVar1 = func_0x0204799c(*DAT_021956bc);
  func_0x020b47d8(&local_1c,uVar1);
  uVar1 = func_0x0204799c(*DAT_021956c0);
  func_0x020b4934(&local_14,uVar1);
  uVar1 = func_0x0204799c(*DAT_021956c4);
  func_0x020b4a44(local_10,uVar1);
  uVar1 = func_0x0204799c(*DAT_021956c8);
  func_0x020b47d8(*DAT_02195678 + 0x48,uVar1);
  iVar2 = *(int *)(local_28 + 0xc);
  func_0x02016468(0x13,0,*(undefined4 *)(*(int *)*DAT_02195678 + 0x14),
                  *(undefined4 *)(*(int *)*DAT_02195678 + 0x10));
  func_0x02016468(0xe,0,*(undefined4 *)(local_28 + 0xc),DAT_021956cc);
  func_0x02016468(0xe,DAT_021956d0,iVar2 + DAT_021956d0,0x40);
  func_0x02016468(0x23,0,*(undefined4 *)(*(int *)(*DAT_02195678 + 0x14) + 0x14),
                  *(undefined4 *)(*(int *)(*DAT_02195678 + 0x14) + 0x10));
  func_0x02016468(0x1e,0,*(undefined4 *)(local_18 + 0xc),*(undefined4 *)(local_18 + 8));
  func_0x02016468(4,0,*(undefined4 *)(local_24 + 0x14),*(undefined4 *)(local_24 + 0x10));
  func_0x02016468(0xf,0,*(undefined4 *)(local_20 + 0xc),0x40);
  func_0x02016468(8,0,local_1c + 0xc,*(undefined4 *)(local_1c + 8));
  func_0x02016468(0x17,0,*(undefined4 *)(local_14 + 0x14),*(undefined4 *)(local_14 + 0x10));
  func_0x02016468(0x1f,0,*(undefined4 *)(local_10[0] + 0xc),0x40);
  func_0x02016468(0x1b,0,*(int *)(*DAT_02195678 + 0x48) + 0xc,
                  *(undefined4 *)(*(int *)(*DAT_02195678 + 0x48) + 8));
  iVar2 = *(int *)(*(int *)(*DAT_02195678 + 0x30) + 0xc);
  func_0x02016468(0x1e,(uint)*DAT_021956d4 << 5,iVar2 + (uint)*DAT_021956d8 * 0x20,0x20);
  func_0x02016468(0x1e,(uint)DAT_021956d4[1] << 5,iVar2 + (uint)DAT_021956d8[1] * 0x20,0x20);
  func_0x02016468(0x1e,(uint)DAT_021956d4[2] << 5,iVar2 + (uint)DAT_021956d8[2] * 0x20,0x20);
  return;
}

