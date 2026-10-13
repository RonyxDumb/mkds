/* Decompiled C draft; module arm9_ov001; ROM address 0219d03c. No matching claim. */
#include "types.h"
#include "deps/0219d03c_FUN_0219d03c.h"

void FUN_0219d03c(void)

{
  int *piVar1;
  undefined4 uVar2;
  int local_14;
  int local_10;
  int local_c;
  int local_8 [2];
  
  uVar2 = func_0x0204799c(DAT_0219d1e8);
  func_0x020b4934(&local_14,uVar2);
  uVar2 = func_0x0204799c(DAT_0219d1ec);
  func_0x020b47d8((int *)(uintptr_t)(*DAT_0219d1f0 + DAT_0219d1f4),uVar2);
  uVar2 = func_0x0204799c(DAT_0219d1f8);
  func_0x020b47d8((int *)(uintptr_t)(*DAT_0219d1f0 + DAT_0219d1fc),uVar2);
  uVar2 = func_0x0204799c(DAT_0219d200);
  func_0x020b47d8((int *)(uintptr_t)(*DAT_0219d1f0 + DAT_0219d204),uVar2);
  uVar2 = func_0x0204799c(DAT_0219d208);
  func_0x020b4a44(&local_10,uVar2);
  uVar2 = func_0x0204799c(DAT_0219d20c);
  piVar1 = DAT_0219d1f0;
  *(undefined4 *)(*DAT_0219d1f0 + DAT_0219d210) = uVar2;
  *(undefined4 *)(*piVar1 + DAT_0219d214) = 0;
  uVar2 = func_0x0204799c(DAT_0219d218);
  *(undefined4 *)(*DAT_0219d1f0 + DAT_0219d21c) = uVar2;
  uVar2 = func_0x0204799c(DAT_0219d220);
  *(undefined4 *)(*DAT_0219d1f0 + DAT_0219d224) = uVar2;
  uVar2 = func_0x0204799c(DAT_0219d228);
  piVar1 = DAT_0219d1f0;
  *(undefined4 *)(*DAT_0219d1f0 + DAT_0219d22c) = uVar2;
  *(undefined4 *)(*piVar1 + DAT_0219d230) = 0;
  uVar2 = func_0x0204799c(DAT_0219d234);
  func_0x020b49bc((int *)(uintptr_t)(*DAT_0219d1f0 + DAT_0219d238),uVar2);
  uVar2 = func_0x0204799c(DAT_0219d23c);
  func_0x020b48b4((int *)(uintptr_t)(*DAT_0219d1f0 + DAT_0219d240),uVar2);
  uVar2 = func_0x0204799c(DAT_0219d244);
  func_0x020b4a44(&local_c,uVar2);
  uVar2 = func_0x0204799c(DAT_0219d248);
  func_0x020b49bc((int *)(uintptr_t)(*DAT_0219d1f0 + DAT_0219d24c),uVar2);
  uVar2 = func_0x0204799c(DAT_0219d250);
  func_0x020b48b4((int *)(uintptr_t)(*DAT_0219d1f0 + DAT_0219d254),uVar2);
  uVar2 = func_0x0204799c(DAT_0219d258);
  func_0x020b4a44(local_8,uVar2);
  func_0x0214cfe4(0,*DAT_0219d1f0 + 0x30,DAT_0219d25c);
  func_0x02016468(6,0,*(undefined4 *)(local_14 + 0x14),*(undefined4 *)(local_14 + 0x10));
  func_0x02016468(10,0,*DAT_0219d1f0 + 0x30,DAT_0219d25c);
  func_0x02016468(0xf,0,*(undefined4 *)(local_10 + 0xc),DAT_0219d260);
  func_0x02016468(0x13,0,*(undefined4 *)(*(int *)(*DAT_0219d1f0 + DAT_0219d238) + 0x14),
                  *(undefined4 *)(*(int *)(*DAT_0219d1f0 + DAT_0219d238) + 0x10));
  func_0x02016468(0xe,0,*(undefined4 *)(local_c + 0xc),DAT_0219d264);
  func_0x02016468(0xe,DAT_0219d268,*(int *)(local_c + 0xc) + DAT_0219d268,0x40);
  func_0x02016468(0x23,0,*(undefined4 *)(*(int *)(*DAT_0219d1f0 + DAT_0219d24c) + 0x14),
                  *(undefined4 *)(*(int *)(*DAT_0219d1f0 + DAT_0219d24c) + 0x10));
  func_0x02016468(0x1e,0,*(undefined4 *)(local_8[0] + 0xc),*(undefined4 *)(local_8[0] + 8));
  return;
}

