/* Decompiled C draft; module arm9; ROM address 020ffbd4. No matching claim. */
#include "types.h"
#include "deps/020ffbd4_func_020ffbd4.h"

void func_020ffbd4(void)

{
  undefined4 uVar1;
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020ffbfc);
  func_020ea588(puRam020ffc00,uVar1,0);
  Model_SetPolygonIdLightFlagsEmi(*puRam020ffc00,0x3f,2,uRam020ffc04);
  return;
}

