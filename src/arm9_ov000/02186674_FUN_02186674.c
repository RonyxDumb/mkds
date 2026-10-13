/* Decompiled C draft; module arm9_ov000; ROM address 02186674. No matching claim. */
#include "types.h"
#include "deps/02186674_FUN_02186674.h"

uint FUN_02186674(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_r3;
  uint in_stack_00000000;
  
  iVar1 = FUN_021866b8();
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = func_0x0213a434();
  uVar3 = FUN_021881d0(iVar1,uVar2,(byte *)(uintptr_t)(in_r3),in_stack_00000000);
  if ((uVar3 != 0xffffffff) && (uVar3 < in_stack_00000000)) {
    *(undefined1 *)(in_r3 + uVar3) = 0;
  }
  return uVar3;
}

