/* Decompiled C draft; module arm9; ROM address 02077eb4. No matching claim. */
#include "types.h"
#include "deps/02077eb4_CreateCESex_from_thumb.h"

void CreateCESex_from_thumb(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = Mem_AllocateHeap(param_1,uRam02077efc);
  uVar2 = Mem_Exp_Create(uVar1,uRam02077efc,0);
  param_2[1] = uVar2;
  *param_2 = uVar1;
  param_2[4] = 0;
  param_2[3] = param_2[4];
  param_2[2] = param_2[3];
  param_2[7] = 0;
  param_2[6] = param_2[7];
  param_2[5] = param_2[6];
  param_2[10] = 0;
  param_2[9] = param_2[10];
  param_2[8] = param_2[9];
  param_2[0xb] = 0;
  *(undefined2 *)(param_2 + 0xc) = 0;
  return;
}

