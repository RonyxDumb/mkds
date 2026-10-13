/* Decompiled C draft; module arm9; ROM address 020eb72c. No matching claim. */
#include "types.h"
#include "deps/020eb72c_func_020eb72c.h"

void func_020eb72c(void)

{
  undefined4 uVar1;
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020eb754);
  func_020ea588(puRam020eb758,uVar1,0);
  Model_SetPolygonIdLightFlagsEmi(*puRam020eb758,0x3f,2,uRam020eb75c);
  return;
}

