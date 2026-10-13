/* Decompiled C draft; module arm9_ov001; ROM address 02187f7c. No matching claim. */
#include "types.h"
#include "deps/02187f7c_FUN_02187f7c.h"

int FUN_02187f7c(int param_1)

{
  int iVar1;
  
  if ((int)*(uint *)(param_1 + DAT_02187fb4) < (int)(uint)*(ushort *)(*DAT_02187fb8 + 0xc)) {
    iVar1 = func_0x02042044(*(uint *)(param_1 + DAT_02187fb4) & 0xffff,
                            *(uint *)(param_1 + DAT_02187fbc) & 0xffff);
    return (int)*(short *)(iVar1 + 0xe);
  }
  return 0;
}

