/* Decompiled C draft; module arm9_ov000; ROM address 021851a0. No matching claim. */
#include "types.h"
#include "deps/021851a0_FUN_021851a0.h"

void FUN_021851a0(void)

{
  undefined4 uVar1;
  
  uVar1 = func_0x0204799c(DAT_02185218);
  *(undefined4 *)(*DAT_0218521c + 0x2c) = uVar1;
  uVar1 = func_0x0204799c(DAT_02185220);
  *(undefined4 *)(*DAT_0218521c + 0x30) = uVar1;
  uVar1 = func_0x0204799c(DAT_02185224);
  func_0x020b49bc(*DAT_0218521c + 0x24,uVar1);
  uVar1 = func_0x0204799c(DAT_02185228);
  func_0x020b48b4(*DAT_0218521c + 0x20,uVar1);
  uVar1 = func_0x0204799c(DAT_0218522c);
  func_0x020b4a44(*DAT_0218521c + 0x28,uVar1);
  func_0x0214bea4(*(undefined4 *)(*(int *)(*DAT_0218521c + 0x24) + 0x14),0,
                  *(undefined4 *)(*(int *)(*DAT_0218521c + 0x24) + 0x10));
  func_0x0214c028(*(undefined4 *)(*(int *)(*DAT_0218521c + 0x28) + 0xc),0,
                  *(undefined4 *)(*(int *)(*DAT_0218521c + 0x28) + 8));
  return;
}

