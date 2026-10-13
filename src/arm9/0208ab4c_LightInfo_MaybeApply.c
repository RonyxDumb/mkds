/* Decompiled C draft; module arm9; ROM address 0208ab4c. No matching claim. */
#include "types.h"
#include "deps/0208ab4c_LightInfo_MaybeApply.h"

void LightInfo_MaybeApply(ushort *param_1)

{
  uint local_10;
  uint local_c;
  
  local_10 = (uint)*param_1;
  func_01ff9048(0x33,(undefined4)(uintptr_t)(&local_10),1);
  local_c = *param_1 | 0x40000000;
  func_01ff9048(0x33,(undefined4)(uintptr_t)(&local_c),1);
  return;
}

