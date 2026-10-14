/* Decompiled C draft; module arm9; ROM address 0203b018. No matching claim. */
#include "types.h"
#include "deps/0203b018_FindFormatGhostBinPath.h"

undefined4 FindFormatGhostBinPath(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = GetCourseIdFromInternalId();
  if (uVar1 != 0xffffffff) {
    Util_SNPrintF(param_2,param_3,uRam0203b06c,uVar1 & 0xff);
    return 1;
  }
  return 0;
}

