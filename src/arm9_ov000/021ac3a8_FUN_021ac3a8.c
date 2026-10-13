/* Decompiled C draft; module arm9_ov000; ROM address 021ac3a8. No matching claim. */
#include "types.h"
#include "deps/021ac3a8_FUN_021ac3a8.h"

undefined4 FUN_021ac3a8(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = param_1 * 4;
  uVar1 = *(uint *)(param_2 + iVar2) ^
          *(uint *)(param_2 + (param_1 + 2 & 0xf) * 4) ^
          *(uint *)(param_2 + (param_1 + 0xd & 0xf) * 4) ^ *(uint *)(param_2 + (param_1 ^ 8) * 4);
  *(uint *)(param_2 + iVar2) = uVar1 << 1 | uVar1 >> 0x1f;
  return *(undefined4 *)(param_2 + iVar2);
}

