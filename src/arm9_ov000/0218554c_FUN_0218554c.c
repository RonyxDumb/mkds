/* Decompiled C draft; module arm9_ov000; ROM address 0218554c. No matching claim. */
#include "types.h"
#include "deps/0218554c_FUN_0218554c.h"

void FUN_0218554c(void)

{
  undefined4 uVar1;
  
  uVar1 = func_0x0204799c(DAT_021855d8);
  *(undefined4 *)(*DAT_021855dc + 0x40) = uVar1;
  uVar1 = func_0x0204799c(DAT_021855e0);
  *(undefined4 *)(*DAT_021855dc + 0x48) = uVar1;
  uVar1 = func_0x0204799c(DAT_021855e4);
  func_0x020b49bc((int *)(uintptr_t)(*DAT_021855dc + 0x38),uVar1);
  uVar1 = func_0x0204799c(DAT_021855e8);
  func_0x020b48b4((int *)(uintptr_t)(*DAT_021855dc + 0x34),uVar1);
  uVar1 = func_0x0204799c(DAT_021855ec);
  func_0x020b4a44((int *)(uintptr_t)(*DAT_021855dc + 0x3c),uVar1);
  func_0x0214bf04(*(undefined4 *)(*(int *)(*DAT_021855dc + 0x38) + 0x14),0,
                  *(undefined4 *)(*(int *)(*DAT_021855dc + 0x38) + 0x10));
  func_0x0214c090(*(undefined4 *)(*(int *)(*DAT_021855dc + 0x3c) + 0xc),0,DAT_021855f0);
  func_0x0214c090(*(int *)(*(int *)(*DAT_021855dc + 0x3c) + 0xc) + DAT_021855f4,DAT_021855f4,0x40);
  return;
}

