/* Decompiled C draft; module arm9; ROM address 02094db4. No matching claim. */
#include "types.h"
#include "deps/02094db4_func_02094db4.h"

void func_02094db4(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = CreateMapObjectFromModelAndAnimation_from_thumb(param_1,uRam02094de8,uRam02094dec);
  *puRam02094df0 = uVar1;
  StructMapObject_MaybeSetPolygonId(uVar1,0x3f);
  *(undefined4 *)(param_1 + 0x1c) = 1;
  return;
}

