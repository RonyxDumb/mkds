/* Decompiled C draft; module arm9_ov003; ROM address 021cc83c. No matching claim. */
#include "types.h"
#include "deps/021cc83c_FUN_021cc83c.h"

void FUN_021cc83c(void)

{
  undefined1 auStack_6e [22];
  undefined1 auStack_58 [4];
  undefined1 auStack_54 [20];
  ushort local_40;
  
  *DAT_021cc8a8 = 0;
  FUN_021cc7b8();
  FUN_021bf86c(8);
  FUN_021bf5ec(2);
  func_0x0200fddc(auStack_58);
  func_0x0214cfe4(0,(int)(uintptr_t)(auStack_6e),0x16);
  func_0x0214cffc((int)(uintptr_t)(auStack_54),(int)(uintptr_t)(auStack_6e),(uint)local_40 << 1);
  FUN_021bf4f4((undefined4)(uintptr_t)(auStack_6e),0x6d);
  FUN_021beef8(0);
  FUN_021ce920(DAT_021cc8ac);
  FUN_021cdc10(0xb);
  FUN_021c212c(DAT_021cc8b0);
  return;
}

