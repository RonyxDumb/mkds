/* Decompiled C draft; module arm9_ov000; ROM address 0218b30c. No matching claim. */
#include "types.h"
#include "deps/0218b30c_FUN_0218b30c.h"

undefined4 FUN_0218b30c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_18 [2];
  
  if (param_1 != 0) {
    local_18[0] = param_2;
    iVar1 = FUN_0218de28(*(undefined4 *)(param_1 + 0x18),local_18);
    if (iVar1 != 0) {
      param_3 = *(undefined4 *)(iVar1 + 4);
    }
    return param_3;
  }
  func_0x0213442c(DAT_0218b350,DAT_0218b354,0,0x97);
  return 0;
}

