/* Decompiled C draft; module arm9_ov003; ROM address 021c00ec. No matching claim. */
#include "types.h"
#include "deps/021c00ec_FUN_021c00ec.h"

void FUN_021c00ec(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  local_1c = 0;
  *(char *)(*DAT_021c0148 + DAT_021c014c) = (char)param_1;
  iVar1 = DAT_021c0150;
  iVar2 = 0;
  iVar3 = iVar2;
  do {
    FUN_021c0154(param_1,iVar3,*(undefined2 *)(iVar1 + iVar2 * 4 + 2));
    iVar2 = iVar2 + 0xc;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  if (param_1 == 2) {
    local_20 = 1;
  }
  else if (param_1 == 1) {
    local_1c = 1;
  }
  FUN_021c0050(0x2f,local_20);
  FUN_021c0050(0x30,local_1c);
  return;
}

