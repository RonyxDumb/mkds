/* Decompiled C draft; module arm9_ov001; ROM address 021978b4. No matching claim. */
#include "types.h"
#include "deps/021978b4_FUN_021978b4.h"

void FUN_021978b4(void)

{
  undefined4 uVar1;
  int iVar2;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10 [2];
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10[0] = 0;
  uVar1 = func_0x0204799c(*DAT_02197ae0);
  func_0x020b49bc((int *)(uintptr_t)(*DAT_02197ae4),uVar1);
  uVar1 = func_0x0204799c(*DAT_02197ae8);
  func_0x020b48b4((int *)(uintptr_t)(*DAT_02197ae4 + 4),uVar1);
  uVar1 = func_0x0204799c(*DAT_02197aec);
  func_0x020b4a44(&local_30,uVar1);
  uVar1 = func_0x0204799c(*DAT_02197af0);
  *(undefined4 *)(*DAT_02197ae4 + 8) = uVar1;
  uVar1 = func_0x0204799c(*DAT_02197af4);
  *(undefined4 *)(*DAT_02197ae4 + 0x10) = uVar1;
  uVar1 = func_0x0204799c(*DAT_02197af8);
  func_0x020b49bc((int *)(uintptr_t)(*DAT_02197ae4 + 0x14),uVar1);
  uVar1 = func_0x0204799c(*DAT_02197afc);
  func_0x020b48b4((int *)(uintptr_t)(*DAT_02197ae4 + 0x18),uVar1);
  uVar1 = func_0x0204799c(*DAT_02197b00);
  func_0x020b4a44(&local_1c,uVar1);
  uVar1 = func_0x0204799c(*DAT_02197b04);
  *(undefined4 *)(*DAT_02197ae4 + 0x1c) = uVar1;
  uVar1 = func_0x0204799c(*DAT_02197b08);
  *(undefined4 *)(*DAT_02197ae4 + 0x20) = uVar1;
  uVar1 = func_0x0204799c(*DAT_02197b0c);
  *(undefined4 *)(*DAT_02197ae4 + 0x24) = uVar1;
  uVar1 = func_0x020b4018(0);
  *(undefined4 *)(*DAT_02197ae4 + 0x28) = uVar1;
  uVar1 = func_0x020b400c(0);
  *(undefined4 *)(*DAT_02197ae4 + 0x2c) = uVar1;
  uVar1 = func_0x020b4030(0);
  *(undefined4 *)(*DAT_02197ae4 + 0x30) = uVar1;
  uVar1 = func_0x020b4000(0);
  *(undefined4 *)(*DAT_02197ae4 + 0x34) = uVar1;
  uVar1 = func_0x0204799c(*DAT_02197b10);
  func_0x020b4934(&local_2c,uVar1);
  uVar1 = func_0x0204799c(*DAT_02197b14);
  func_0x020b47d8(&local_24,uVar1);
  uVar1 = func_0x0204799c(*DAT_02197b18);
  func_0x020b47d8(&local_20,uVar1);
  uVar1 = func_0x0204799c(*DAT_02197b1c);
  func_0x020b4a44(&local_28,uVar1);
  uVar1 = func_0x0204799c(*DAT_02197b20);
  func_0x020b4934(&local_18,uVar1);
  uVar1 = func_0x0204799c(*DAT_02197b24);
  func_0x020b4a44(&local_14,uVar1);
  uVar1 = func_0x0204799c(*DAT_02197b28);
  func_0x020b47d8(local_10,uVar1);
  iVar2 = *(int *)(local_30 + 0xc);
  func_0x02016468(0x13,0,*(undefined4 *)(*(int *)*DAT_02197ae4 + 0x14),
                  *(undefined4 *)(*(int *)*DAT_02197ae4 + 0x10));
  func_0x02016468(0xe,0,*(undefined4 *)(local_30 + 0xc),DAT_02197b2c);
  func_0x02016468(0xe,DAT_02197b30,iVar2 + DAT_02197b30,0x40);
  func_0x02016468(0x23,0,*(undefined4 *)(*(int *)(*DAT_02197ae4 + 0x14) + 0x14),
                  *(undefined4 *)(*(int *)(*DAT_02197ae4 + 0x14) + 0x10));
  func_0x02016468(0x1e,0,*(undefined4 *)(local_1c + 0xc),*(undefined4 *)(local_1c + 8));
  func_0x02016468(4,0,*(undefined4 *)(local_2c + 0x14),*(undefined4 *)(local_2c + 0x10));
  func_0x02016468(8,0,local_24 + 0xc,*(undefined4 *)(local_24 + 8));
  func_0x02016468(9,0,local_20 + 0xc,*(undefined4 *)(local_20 + 8));
  func_0x02016468(0xf,0,*(undefined4 *)(local_28 + 0xc),0x40);
  func_0x02016468(0x17,0,*(undefined4 *)(local_18 + 0x14),*(undefined4 *)(local_18 + 0x10));
  func_0x02016468(0x1f,0,*(undefined4 *)(local_14 + 0xc),0x40);
  func_0x02016468(0x1b,0,local_10[0] + 0xc,*(undefined4 *)(local_10[0] + 8));
  return;
}

