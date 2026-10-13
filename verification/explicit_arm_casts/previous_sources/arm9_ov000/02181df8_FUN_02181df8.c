/* Decompiled C draft; module arm9_ov000; ROM address 02181df8. No matching claim. */
#include "types.h"
#include "deps/02181df8_FUN_02181df8.h"

void FUN_02181df8(void)

{
  undefined4 uVar1;
  
  uVar1 = func_0x0204799c(DAT_02181e74);
  *(undefined4 *)(*DAT_02181e78 + 0x2c) = uVar1;
  uVar1 = func_0x0204799c(DAT_02181e7c);
  *(undefined4 *)(*DAT_02181e78 + 0x30) = uVar1;
  uVar1 = func_0x0204799c(DAT_02181e80);
  func_0x020b49bc(*DAT_02181e78 + 0x24,uVar1);
  uVar1 = func_0x0204799c(DAT_02181e84);
  func_0x020b48b4(*DAT_02181e78 + 0x20,uVar1);
  uVar1 = func_0x0204799c(DAT_02181e88);
  func_0x020b4a44(*DAT_02181e78 + 0x28,uVar1);
  func_0x02016468(0x23,0,*(undefined4 *)(*(int *)(*DAT_02181e78 + 0x24) + 0x14),
                  *(undefined4 *)(*(int *)(*DAT_02181e78 + 0x24) + 0x10));
  func_0x02016468(0x1e,0,*(undefined4 *)(*(int *)(*DAT_02181e78 + 0x28) + 0xc),
                  *(undefined4 *)(*(int *)(*DAT_02181e78 + 0x28) + 8));
  return;
}

