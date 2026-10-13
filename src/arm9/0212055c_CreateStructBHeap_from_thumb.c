/* Decompiled C draft; module arm9; ROM address 0212055c. No matching claim. */
#include "types.h"
#include "deps/0212055c_CreateStructBHeap_from_thumb.h"

void CreateStructBHeap_from_thumb(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = Mem_AllocateHeapAligned(param_1,uRam02120598,0x20);
  piVar1 = piRam0212059c;
  *(undefined4 *)(*piRam0212059c + 4) = uVar2;
  uVar2 = Mem_Exp_Create(*(undefined4 *)(*piVar1 + 4),uRam02120598,1);
  piVar1 = piRam0212059c;
  *(undefined4 *)*piRam0212059c = uVar2;
  *(undefined4 *)(*piVar1 + iRam021205a0) = 1;
  func_0x021a3744(uRam021205a4,uRam021205a8);
  return;
}

