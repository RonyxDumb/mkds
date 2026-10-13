/* Decompiled C draft; module arm9; ROM address 020e5f68. No matching claim. */
#include "types.h"
#include "deps/020e5f68_func_020e5f68.h"

void func_020e5f68(void)

{
  undefined4 uVar1;
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020e5fa0);
  func_020ea588(puRam020e5fa4,uVar1,0);
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020e5fa8);
  func_020ea55c((undefined4 *)(uintptr_t)(uRam020e5fac),uVar1,0x3f);
  Model_SetPolygonIdLightFlagsEmi(*puRam020e5fa4,0x3f,2,uRam020e5fb0);
  return;
}

