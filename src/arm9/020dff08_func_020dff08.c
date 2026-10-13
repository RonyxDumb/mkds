/* Decompiled C draft; module arm9; ROM address 020dff08. No matching claim. */
#include "types.h"
#include "deps/020dff08_func_020dff08.h"

void func_020dff08(void)

{
  undefined4 uVar1;
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020dff3c);
  func_020ea588(puRam020dff40,uVar1,0);
  Model_SetPolygonIdLightFlagsEmi(*puRam020dff40,0x3f,2,uRam020dff44);
  func_020e1dc0(*puRam020dff48,*puRam020dff40);
  return;
}

