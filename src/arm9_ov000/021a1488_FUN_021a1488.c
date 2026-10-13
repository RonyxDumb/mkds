/* Decompiled C draft; module arm9_ov000; ROM address 021a1488. No matching claim. */
#include "types.h"
#include "deps/021a1488_FUN_021a1488.h"

undefined4 FUN_021a1488(void)

{
  undefined4 uVar1;
  undefined1 auStack_30 [12];
  undefined1 auStack_24 [36];
  
  if (*(char *)(*DAT_021a1500 + 0x15) != '\x02') {
    return 0;
  }
  func_0x0200d9e0((undefined4)(uintptr_t)(auStack_30),0xc,DAT_021a1504,*(byte *)(*DAT_021a1500 + 0x16) + 1);
  FUN_021a363c(DAT_021a1508,(undefined4)(uintptr_t)(auStack_30),(undefined4)(uintptr_t)(auStack_24),0x2f);
  func_0x0200d9e0((undefined4)(uintptr_t)(auStack_30),0xc,DAT_021a1504,*(byte *)(*DAT_021a1500 + 0xd) + 1);
  FUN_021a360c(DAT_021a150c,(undefined4)(uintptr_t)(auStack_30),(undefined4)(uintptr_t)(auStack_24),0x2f);
  func_0x0200d9e0((undefined4)(uintptr_t)(auStack_30),0xc,DAT_021a1504,3);
  FUN_021a360c(DAT_021a1510,(undefined4)(uintptr_t)(auStack_30),(undefined4)(uintptr_t)(auStack_24),0x2f);
  uVar1 = FUN_0219d558(6,(int)(uintptr_t)(auStack_24),0);
  return uVar1;
}

