/* Decompiled C draft; module arm9; ROM address 020e3a7c. No matching claim. */
#include "types.h"
#include "deps/020e3a7c_func_020e3a7c.h"

void func_020e3a7c(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020e3ad8);
  func_020ea588(puRam020e3adc,uVar1,0);
  uVar2 = FormatFindMapObjFileBuffer_from_thumb(uRam020e3ae0);
  func_020ea4bc(0,*puRam020e3adc,puRam020e3ae4,uVar1,uVar2);
  uVar1 = Animation_GetCurrentLength(*puRam020e3ae4);
  *(undefined4 *)(*piRam020e3ae8 + 0x2c) = uVar1;
  Model_SetPolygonIdLightFlagsEmi(*puRam020e3adc,0x3f,2,uRam020e3aec);
  func_020e1dc0(*piRam020e3ae8,*puRam020e3adc);
  return;
}

