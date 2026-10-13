/* Decompiled C draft; module arm9; ROM address 020dc308. No matching claim. */
#include "types.h"
#include "deps/020dc308_func_020dc308.h"

void func_020dc308(void)

{
  undefined4 uVar1;
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020dc340);
  func_020ea588(puRam020dc344,uVar1,0);
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020dc348);
  func_020ea55c(uRam020dc34c,uVar1,0x3f);
  Model_SetPolygonIdLightFlagsEmi(*puRam020dc344,0x3f,2,uRam020dc350);
  return;
}

