/* Decompiled C draft; module arm9; ROM address 020d2210. No matching claim. */
#include "types.h"
#include "deps/020d2210_FormatFindMapObjFileBuffer_0_from_thumb.h"

void FormatFindMapObjFileBuffer_0_from_thumb(undefined4 param_1)

{
  char acStack_108 [264];
  
  _snprintf(acStack_108,sRam020d222c,pcRam020d2230,param_1);
  FindFileBuffer_MAR_EFT_from_thumb(acStack_108);
  return;
}

