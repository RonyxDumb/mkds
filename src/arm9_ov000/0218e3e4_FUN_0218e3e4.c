/* Decompiled C draft; module arm9_ov000; ROM address 0218e3e4. No matching claim. */
#include "types.h"
#include "deps/0218e3e4_FUN_0218e3e4.h"

void FUN_0218e3e4(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *in_stack_00000000;
  undefined1 in_stack_00000004;
  undefined1 local_1c [8];
  
  puVar4 = local_1c;
  iVar3 = 8;
  do {
    uVar1 = *in_stack_00000000;
    in_stack_00000000 = in_stack_00000000 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  local_1c[0] = in_stack_00000004;
  uVar2 = FUN_021a9018();
  FUN_0218e56c(uVar2,0xffffffff);
  return;
}

