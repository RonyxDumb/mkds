/* Decompiled C draft; module arm9_ov001; ROM address 021804e0. No matching claim. */
#include "types.h"
#include "deps/021804e0_func_ov001_021804e0.h"

undefined4 func_ov001_021804e0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_30 [9];
  
  puVar4 = local_30;
  iVar3 = 4;
  puVar5 = puRam02180508;
  do {
    uVar1 = *puVar5;
    uVar2 = puVar5[1];
    puVar5 = puVar5 + 2;
    *puVar4 = uVar1;
    puVar4[1] = uVar2;
    puVar4 = puVar4 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  func_0x020487fc(param_1,local_30);
  return 0;
}

