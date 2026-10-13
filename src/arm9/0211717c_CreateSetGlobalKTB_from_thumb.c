/* Decompiled C draft; module arm9; ROM address 0211717c. No matching claim. */
#include "types.h"
#include "deps/0211717c_CreateSetGlobalKTB_from_thumb.h"

void CreateSetGlobalKTB_from_thumb(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = Mem_AllocateHeap(param_1,4);
  *puRam0211719c = uVar1;
  uVar1 = AllocateKartAppearTableData_from_thumb(param_1);
  *(undefined4 *)*puRam0211719c = uVar1;
  return;
}

