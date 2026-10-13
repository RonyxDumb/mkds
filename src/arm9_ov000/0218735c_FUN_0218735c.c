/* Decompiled C draft; module arm9_ov000; ROM address 0218735c. No matching claim. */
#include "types.h"
#include "deps/0218735c_FUN_0218735c.h"

undefined4 FUN_0218735c(int param_1)

{
  int iVar1;
  undefined1 auStack_10 [8];
  
  iVar1 = FUN_02186bd4(param_1,DAT_021873bc,DAT_021873c0);
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = func_0x02139f70(*(undefined4 *)(param_1 + DAT_021873c4),DAT_021873c8);
  iVar1 = func_0x0213a434(iVar1 + 4);
  if (iVar1 != 0) {
    func_0x0200d9e0(auStack_10,7,DAT_021873cc);
    iVar1 = FUN_02186bd4(param_1,DAT_021873d0,(undefined4)(uintptr_t)(auStack_10));
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}

