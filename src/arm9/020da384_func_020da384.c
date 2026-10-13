/* Decompiled C draft; module arm9; ROM address 020da384. No matching claim. */
#include "types.h"
#include "deps/020da384_func_020da384.h"

void func_020da384(int param_1,undefined4 param_2,code *param_3)

{
  undefined4 uVar1;
  
  *piRam020da400 = param_1;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffd;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfff7;
  *(undefined2 *)(param_1 + 0x66) = 0x1f;
  (*param_3)();
  uVar1 = FindFileBuffer_CRS_CST_from_thumb(uRam020da404);
  *(undefined4 *)
   ((*(uint *)(uRam020da408 & 0xfffffffc) >> (uRam020da408 & 3) * 8 |
    *(uint *)(uRam020da408 & 0xfffffffc) << (uRam020da408 & 3) * -8 + 0x20) + 0x174) = uVar1;
  uVar1 = FindFileBuffer_CRS_CST_from_thumb(uRam020da40c);
  *(undefined4 *)
   ((*(uint *)(uRam020da408 & 0xfffffffc) >> (uRam020da408 & 3) * 8 |
    *(uint *)(uRam020da408 & 0xfffffffc) << (uRam020da408 & 3) * -8 + 0x20) + 0x178) = uVar1;
  uVar1 = FindFileBuffer_CRS_CST_from_thumb(uRam020da410);
  *(undefined4 *)
   ((*(uint *)(uRam020da408 & 0xfffffffc) >> (uRam020da408 & 3) * 8 |
    *(uint *)(uRam020da408 & 0xfffffffc) << (uRam020da408 & 3) * -8 + 0x20) + 0x17c) = uVar1;
  return;
}

