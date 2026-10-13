/* Decompiled C draft; module arm9_ov003; ROM address 021b839c. No matching claim. */
#include "types.h"
#include "deps/021b839c_func_ov003_021b839c.h"

int func_ov003_021b839c(undefined1 *param_1)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_18;
  
  puVar1 = puRam021b8424;
  *param_1 = *(undefined1 *)((int)puRam021b8424 + 0x19);
  param_1[1] = 1;
  uVar3 = puVar1[1];
  iVar4 = (int)(short)uVar3;
  func_ov003_021b7d90(param_1 + 6,*puVar1,iVar4);
  uVar2 = func_ov003_021b7c94(uVar3 & 0xffff);
  *(undefined2 *)(param_1 + 2) = uVar2;
  iVar4 = func_0x02133068(((iVar4 + 6) * 0x10000 >> 0x10) + 1,2);
  uVar3 = (iVar4 << 0x11) >> 0x10;
  uVar2 = func_ov003_021b7c94(uVar3 & 0xffff);
  *(undefined2 *)(param_1 + 4) = uVar2;
  param_1[uVar3] = 0x60;
  param_1[uVar3 + 1] = 0;
  uVar2 = func_ov003_021b7c94();
  *(undefined2 *)(param_1 + uVar3 + 4) = uVar2;
  local_18 = func_ov003_021b7cac(0xe);
  func_ov003_021b7d90(param_1 + uVar3 + 6,&local_18,4);
  uVar2 = func_ov003_021b7c94(4);
  *(undefined2 *)(param_1 + uVar3 + 2) = uVar2;
  return ((short)((uint)(iVar4 << 0x11) >> 0x10) + 10) * 0x10000 >> 0x10;
}

