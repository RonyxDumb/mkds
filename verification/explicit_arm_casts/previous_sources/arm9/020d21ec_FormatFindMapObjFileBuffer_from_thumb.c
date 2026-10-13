/* Decompiled C draft; module arm9; ROM address 020d21ec. No matching claim. */
#include "types.h"
#include "deps/020d21ec_FormatFindMapObjFileBuffer_from_thumb.h"

void FormatFindMapObjFileBuffer_from_thumb(undefined4 param_1)

{
  char acStack_108 [264];
  
  _snprintf(acStack_108,sRam020d2208,pcRam020d220c,param_1);
  FindFileBuffer_CRS_CST_from_thumb(acStack_108);
  return;
}

