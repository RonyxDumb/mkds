/* Decompiled C draft; module arm9_ov003; ROM address 021c91fc. No matching claim. */
#include "types.h"
#include "deps/021c91fc_FUN_021c91fc.h"

undefined4 FUN_021c91fc(void)

{
  int iVar1;
  int iVar2;
  
  FUN_021cdb6c();
  iVar1 = FUN_021c8400();
  if (iVar1 == 0xe) {
    return 0;
  }
  iVar2 = FUN_021c8904();
  if (iVar2 == 0) {
    FUN_021cdc10(9);
    return 1;
  }
  FUN_021c8100(iVar1);
  switch(iVar1) {
  case 2:
  case 3:
  case 7:
  case 8:
    FUN_021c7e20();
  }
  FUN_021c90dc(iVar1);
  return 1;
}

