/* Decompiled C draft; module arm7; ROM address 060125a8. No matching claim. */
#include "types.h"
#include "deps/060125a8_FUN_060125a8.h"

void FUN_060125a8(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_2 + (uint)*(ushort *)(param_2 + 0xe) * 2;
  *(undefined2 *)(param_2 + 0xc) = *(undefined2 *)(iVar1 + 0x10);
  *(undefined2 *)(iVar1 + 0x12) = 2;
  *(undefined2 *)(iVar1 + 0x14) = 0;
  *(undefined2 *)(iVar1 + 0x16) = *(undefined2 *)(param_2 + 0x18);
                    /* WARNING: Could not recover jumptable at 0x060125d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_060125dc)();
  return;
}

