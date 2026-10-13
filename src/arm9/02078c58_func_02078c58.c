/* Decompiled C draft; module arm9; ROM address 02078c58. No matching claim. */
#include "types.h"
#include "deps/02078c58_func_02078c58.h"

void func_02078c58(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_18 [4];
  
  SetActiveExecutionContextHeapGroupId_from_thumb(1);
  func_02062860();
  func_02012b20(0);
  *(uint *)(*piRam02078d48 + 0x1c) = *(uint *)(*piRam02078d48 + 0x1c) & 0xfffffff7;
  func_02077bc0(param_1);
  InitializeModelResourceList();
  SetCurrentlyInKartModelMenu(1);
  InitializeGlobalCE_from_thumb(param_1);
  LoadKartAppearTablePointerCE_from_thumb(param_1,1);
  piVar1 = piRam02078d4c;
  iVar4 = 0;
  *(undefined4 *)*piRam02078d4c = 0;
  *(undefined4 *)(*piVar1 + 8) = 0;
  *(undefined4 *)(*piVar1 + 4) = 0;
  do {
    iVar3 = func_02077a70((int *)(void *)(auStack_18),iVar4);
    if (iVar3 != 0) {
      *(int *)(*piVar1 + 8) = *(int *)(*piVar1 + 8) + 1;
    }
    piVar2 = piRam02078d4c;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x24);
  *(undefined4 *)(*piRam02078d4c + 0x2c) = *puRam02078d50;
  uVar5 = 0;
  do {
    CreateCESex_from_thumb(param_1,(undefined4 *)(uintptr_t)(*piVar2 + iRam02078d54 + uVar5 * 0x34));
    piVar1 = piRam02078d4c;
    uVar5 = uVar5 + 1 & 0xffff;
  } while (uVar5 < 2);
  *(undefined4 *)(*piRam02078d4c + *(short *)(*piRam02078d4c + iRam02078d58) * 0x34 + iRam02078d5c)
       = 1;
  *(undefined4 *)(*piVar1 + 0x24) = 0;
  *(undefined4 *)(*piVar1 + 0x28) = 0;
  **(undefined4 **)(*piVar1 + 0x20) = 0;
  *(undefined4 *)(*(int *)(*piVar1 + 0x20) + 4) = 0;
  *(undefined4 *)(*(int *)(*piVar1 + 0x20) + 0x20) = *(undefined4 *)(*piVar1 + iRam02078d60);
  func_02077d68();
  func_02077c1c();
  StructCE0_SomeFn_from_thumb((undefined4 *)(uintptr_t)(*piRam02078d4c + 0x24),0);
  SetActiveExecutionContextHeapGroupId_from_thumb(9);
  return;
}

