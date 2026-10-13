/* Decompiled C draft; module arm9; ROM address 02077750. No matching claim. */
#include "types.h"
#include "deps/02077750_func_02077750.h"

void func_02077750(int *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = *(int *)(*piRam020777a8 + 8);
  uVar1 = *(ushort *)(param_2 + 0x40);
  *(undefined2 *)(param_1 + 0x1f) = *(undefined2 *)(param_2 + 0x42);
  *(undefined2 *)((int)param_1 + 0x7e) = 2;
  *param_1 = param_2;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  if (3 < *(ushort *)(iVar2 + (uint)uVar1 * 4 + 2)) {
    StructVC_SomeFnLinkedRouteRelated(param_1 + 1);
    func_0207bd6c((int)(uintptr_t)(param_1 + 0x10),param_2);
  }
  return;
}

