/* Decompiled C draft; module arm9_ov003; ROM address 021d1dd0. No matching claim. */
#include "types.h"
#include "deps/021d1dd0_FUN_021d1dd0.h"

undefined4 FUN_021d1dd0(undefined2 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)*DAT_021d1e0c;
  if (*(char *)((int)puVar2 + 9) != '\0') {
    return 0;
  }
  uVar1 = FUN_021d3544(1,DAT_021d1e10,puVar2,200);
  *puVar2 = uVar1;
  *(undefined2 *)(puVar2 + 1) = 0;
  *(undefined2 *)((int)puVar2 + 6) = param_1;
  *(undefined1 *)((int)puVar2 + 9) = 1;
  return 1;
}

