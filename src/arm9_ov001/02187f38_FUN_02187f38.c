/* Decompiled C draft; module arm9_ov001; ROM address 02187f38. No matching claim. */
#include "types.h"
#include "deps/02187f38_FUN_02187f38.h"

int FUN_02187f38(int param_1)

{
  int iVar1;
  
  if ((int)*(uint *)(param_1 + DAT_02187f70) < (int)(uint)*(ushort *)(*DAT_02187f74 + 0xc)) {
    iVar1 = func_0x02042044(*(uint *)(param_1 + DAT_02187f70) & 0xffff,
                            *(uint *)(param_1 + DAT_02187f78) & 0xffff);
    return (int)*(short *)(iVar1 + 0x10);
  }
  return 0;
}

