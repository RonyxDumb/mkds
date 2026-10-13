/* Decompiled C draft; module arm9; ROM address 0203bedc. No matching claim. */
#include "types.h"
#include "deps/0203bedc_AllocateKartAppearTableData_from_thumb.h"

int AllocateKartAppearTableData_from_thumb(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Mem_AllocateHeap(param_1,0x48);
  uVar2 = LoadKartAppearTablePointer_from_thumb(param_1);
  *(undefined4 *)(iVar1 + 0x44) = uVar2;
  StructKTB_SomeFn_from_thumb((undefined1 *)(uintptr_t)(iVar1));
  return iVar1;
}

