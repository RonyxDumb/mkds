/* Decompiled C draft; module arm9; ROM address 020db3e4. No matching claim. */
#include "types.h"
#include "deps/020db3e4_func_020db3e4.h"

void func_020db3e4(void)

{
  undefined4 uVar1;
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020db41c);
  func_020ea588(puRam020db420,uVar1,0);
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020db424);
  func_020ea55c((undefined4 *)(uintptr_t)(uRam020db428),uVar1,0x3f);
  Model_SetPolygonIdLightFlagsEmi(*puRam020db420,0x3f,2,uRam020db42c);
  return;
}

