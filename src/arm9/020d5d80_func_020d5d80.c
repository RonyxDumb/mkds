/* Decompiled C draft; module arm9; ROM address 020d5d80. No matching claim. */
#include "types.h"
#include "deps/020d5d80_func_020d5d80.h"

void func_020d5d80(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(param_2);
  func_020ea588(puRam020d5dc4,uVar1,0);
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(param_3);
  func_020ea55c((undefined4 *)(uintptr_t)(uRam020d5dc8),uVar1,7);
  Model_SetPolygonIdLightFlagsEmi(*puRam020d5dc4,0x3f,2,uRam020d5dcc);
  Model_Render(*puRam020d5dc4,7);
  return;
}

