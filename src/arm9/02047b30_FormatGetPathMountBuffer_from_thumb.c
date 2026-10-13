/* Decompiled C draft; module arm9; ROM address 02047b30. No matching claim. */
#include "types.h"
#include "deps/02047b30_FormatGetPathMountBuffer_from_thumb.h"

void FormatGetPathMountBuffer_from_thumb(undefined4 param_1,char *param_2)

{
  undefined1 auStack_84 [132];
  
  if (*param_2 == '/') {
    Util_SNPrintF(auStack_84,0x80,uRam02047b64,param_1,param_2);
  }
  else {
    Util_SNPrintF(auStack_84,0x80,uRam02047b68,param_1,param_2);
  }
  GetFileBuffer((undefined4)(uintptr_t)(auStack_84));
  return;
}

