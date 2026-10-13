/* Decompiled C draft; module arm9_ov000; ROM address 02186634. No matching claim. */
#include "types.h"
#include "deps/02186634_FUN_02186634.h"

undefined4 FUN_02186634(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_r3;
  int in_stack_00000000;
  
  iVar1 = FUN_021866b8();
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = func_0x0213a434();
  if (in_stack_00000000 <= iVar2) {
    return 0;
  }
  func_0x0213a2d0(in_r3,iVar1);
  return 1;
}

