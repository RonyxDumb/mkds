/* Decompiled C draft; module arm7; ROM address 06015df4. No matching claim. */
#include "types.h"
#include "deps/06015df4_FUN_06015df4.h"

void FUN_06015df4(undefined4 param_1,int param_2)

{
  short sVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  
  sVar1 = *DAT_06015e64 + *DAT_06015e64 * 0x100;
  if (sVar1 == 0) {
    sVar1 = 1;
  }
  FUN_06009678(sVar1);
  FUN_0600ea7c(param_1,sVar1);
  uVar3 = FUN_060096c4((ushort *)(uintptr_t)(param_2 + 0x33));
  puVar4 = (undefined2 *)(param_2 + 0x34);
  for (uVar5 = 0; uVar5 < uVar3; uVar5 = uVar5 + 2) {
    uVar2 = FUN_06009648();
    *puVar4 = uVar2;
    puVar4 = puVar4 + 1;
  }
  return;
}

