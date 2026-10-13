/* Decompiled C draft; module arm9_ov001; ROM address 02193a20. No matching claim. */
#include "types.h"
#include "deps/02193a20_FUN_02193a20.h"

void FUN_02193a20(void)

{
  undefined4 uVar1;
  int local_10;
  int local_c;
  int local_8 [2];
  
  uVar1 = func_0x0204799c(DAT_02193af4);
  func_0x020b4934(&local_10,uVar1);
  uVar1 = func_0x0204799c(DAT_02193af8);
  func_0x020b47d8(&local_c,uVar1);
  uVar1 = func_0x0204799c(DAT_02193afc);
  func_0x020b4a44(local_8,uVar1);
  uVar1 = func_0x0204799c(DAT_02193b00);
  *(undefined4 *)(*DAT_02193b04 + 0x30) = uVar1;
  uVar1 = func_0x0204799c(DAT_02193b08);
  *(undefined4 *)(*DAT_02193b04 + 0x34) = uVar1;
  uVar1 = func_0x0204799c(DAT_02193b0c);
  func_0x020b49bc((int *)(uintptr_t)(*DAT_02193b04 + 0x28),uVar1);
  uVar1 = func_0x0204799c(DAT_02193b10);
  func_0x020b48b4((int *)(uintptr_t)(*DAT_02193b04 + 0x24),uVar1);
  uVar1 = func_0x0204799c(DAT_02193b14);
  func_0x020b4a44((int *)(uintptr_t)(*DAT_02193b04 + 0x2c),uVar1);
  func_0x02016468(4,0,*(undefined4 *)(local_10 + 0x14),*(undefined4 *)(local_10 + 0x10));
  func_0x02016468(8,0,local_c + 0xc,*(undefined4 *)(local_c + 8));
  func_0x02016468(0xf,0,*(undefined4 *)(local_8[0] + 0xc),DAT_02193b18);
  func_0x02016468(0x23,0,*(undefined4 *)(*(int *)(*DAT_02193b04 + 0x28) + 0x14),
                  *(undefined4 *)(*(int *)(*DAT_02193b04 + 0x28) + 0x10));
  func_0x02016468(0x1e,0,*(undefined4 *)(*(int *)(*DAT_02193b04 + 0x2c) + 0xc),
                  *(undefined4 *)(*(int *)(*DAT_02193b04 + 0x2c) + 8));
  return;
}

