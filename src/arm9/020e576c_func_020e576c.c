/* Decompiled C draft; module arm9; ROM address 020e576c. No matching claim. */
#include "types.h"
#include "deps/020e576c_func_020e576c.h"

void func_020e576c(void)

{
  undefined4 uVar1;
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020e5794);
  func_020ea588(puRam020e5798,uVar1,0);
  Model_SetPolygonIdLightFlagsEmi(*puRam020e5798,0x3f,2,uRam020e579c);
  return;
}

