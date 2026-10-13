/* Decompiled C draft; module arm9_ov003; ROM address 021d1ee0. No matching claim. */
#include "types.h"
#include "deps/021d1ee0_FUN_021d1ee0.h"

undefined4 FUN_021d1ee0(int param_1,int param_2,undefined4 param_3,undefined2 param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  char local_18 [8];
  
  local_18[0] = *DAT_021d1f5c;
  local_18[1] = DAT_021d1f5c[1];
  local_18[2] = DAT_021d1f5c[2];
  local_18[3] = DAT_021d1f5c[3];
  if (param_2 == 1) {
    puVar2 = (undefined4 *)*DAT_021d1f60;
  }
  else {
    puVar2 = (undefined4 *)(*DAT_021d1f60 + 0xc);
  }
  if (*(char *)((int)puVar2 + 9) != '\0') {
    return 0;
  }
  if (param_2 == 1) {
    func_0x0214a3e8(DAT_021d1f64,param_3,(int)local_18[param_1]);
  }
  else {
    func_0x0214a3e8(DAT_021d1f68,param_3,(int)local_18[param_1]);
  }
  uVar1 = FUN_021d3544(1,DAT_021d1f6c,puVar2,200);
  *puVar2 = uVar1;
  *(undefined2 *)(puVar2 + 1) = 0;
  *(char *)(puVar2 + 2) = (char)param_1;
  *(undefined2 *)((int)puVar2 + 6) = param_4;
  *(undefined1 *)((int)puVar2 + 9) = 1;
  return 1;
}

