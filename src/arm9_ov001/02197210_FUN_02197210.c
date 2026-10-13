/* Decompiled C draft; module arm9_ov001; ROM address 02197210. No matching claim. */
#include "types.h"
#include "deps/02197210_FUN_02197210.h"

undefined4 FUN_02197210(void)

{
  int iVar1;
  undefined1 auStack_18 [24];
  
  iVar1 = func_0x02060228(*(undefined4 *)(DAT_02197268 + *(int *)(*DAT_02197264 + 0x6c) * 4),
                          *DAT_0219726c);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = func_0x0205fdb4(*(undefined4 *)(DAT_02197268 + *(int *)(*DAT_02197264 + 0x6c) * 4),
                          (undefined4)(uintptr_t)(auStack_18));
  if (iVar1 != 0) {
    return 1;
  }
  func_0x0212ecc0(DAT_02197270,0,0x16);
  return 0;
}

