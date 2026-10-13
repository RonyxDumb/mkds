/* Decompiled C draft; module arm9_ov000; ROM address 0218d644. No matching claim. */
#include "types.h"
#include "deps/0218d644_FUN_0218d644.h"

undefined4 FUN_0218d644(int param_1,int param_2,int param_3,uint *param_4)

{
  int iVar1;
  
  if (param_2 < 7) {
    return 1;
  }
  iVar1 = func_0x02134d30(param_3 + 4,DAT_0218d6cc,4);
  if (iVar1 != 0) {
    return 1;
  }
  if (*(short *)(param_3 + 2) != *(short *)(DAT_0218d6d0 + 6)) {
    return 1;
  }
  iVar1 = func_0x02134d30(param_1,DAT_0218d6d4,3);
  if (iVar1 != 0) {
    return 1;
  }
  *param_4 = (int)*(char *)(param_1 + 3) << 0x18 & DAT_0218d6d8 |
             (int)*(char *)(param_1 + 4) << 0x10 & DAT_0218d6dc |
             (int)*(char *)(param_1 + 5) << 8 & DAT_0218d6e0 | (uint)*(byte *)(param_1 + 6);
  return 0;
}

