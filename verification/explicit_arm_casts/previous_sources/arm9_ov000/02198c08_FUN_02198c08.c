/* Decompiled C draft; module arm9_ov000; ROM address 02198c08. No matching claim. */
#include "types.h"
#include "deps/02198c08_FUN_02198c08.h"

undefined4 FUN_02198c08(int param_1)

{
  int iVar1;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  
  local_10 = *DAT_02198c54;
  local_f = DAT_02198c54[1];
  local_e = 100;
  FUN_0219a01c(&local_10,3,*(undefined2 *)(param_1 + 0x66));
  iVar1 = FUN_02198714(param_1,&local_10,5);
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0x90) = 0;
  return 1;
}

