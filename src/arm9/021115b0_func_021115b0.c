/* Decompiled C draft; module arm9; ROM address 021115b0. No matching claim. */
#include "types.h"
#include "deps/021115b0_func_021115b0.h"

void func_021115b0(undefined4 param_1,undefined2 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  puVar2 = (undefined4 *)Mem_AllocateHeap(param_1,0x34);
  piVar1 = piRam02111680;
  *piRam02111680 = (int)puVar2;
  *puVar2 = param_1;
  *(undefined2 *)(*piVar1 + 0x30) = 0;
  *(undefined2 *)(*piVar1 + 0x32) = 0;
  CreateLoadSomeDisplayConfig_from_thumb(param_1);
  uVar3 = func_02111318();
  CreateGlobalNN_from_thumb(param_1,uVar3);
  local_38 = 1;
  local_34 = GetLoadedFont_from_thumb();
  local_30 = 0;
  local_2c = 1;
  local_28 = 0;
  local_24 = 0;
  local_1c = 1;
  local_18 = 1;
  local_14 = 0;
  PrepareNavigationContextFiles_from_thumb();
  InitializeNavigationContext_from_thumb(param_1,&local_38);
  Maybe_emblem2(*(undefined4 *)*piRam02111680);
  func_021143f4();
  uVar3 = Mem_CreateChildExpHeap(*(undefined4 *)*piRam02111680);
  *(undefined4 *)(*piRam02111680 + 4) = uVar3;
  func_02111684();
  func_02111a98();
  piVar1 = piRam02111680;
  *(undefined2 *)(*piRam02111680 + 0x14) = param_2;
  *(undefined2 *)(*piVar1 + 0x16) = 0xffff;
  *(undefined4 *)(*piVar1 + 0xc) = 0xffffffff;
  *(undefined4 *)(*piVar1 + 0x2c) = 2;
  iVar4 = *piVar1;
  if (*(short *)(iVar4 + 0x14) == 0xc) {
    *(undefined4 *)(iVar4 + 0x10) = 6;
    *(undefined4 *)(*piVar1 + 8) = 3;
    func_02111ab4();
  }
  else {
    *(undefined4 *)(iVar4 + 0x10) = 5;
    *(undefined4 *)(*piVar1 + 8) = 0;
    func_0x0219a050();
  }
  (**(code **)(*piRam02111680 + 0x18))(*(undefined4 *)(*piRam02111680 + 4));
  return;
}

