/* Decompiled C draft; module arm9_ov003; ROM address 021b94c4. No matching claim. */
#include "types.h"
#include "deps/021b94c4_func_ov003_021b94c4.h"

void func_ov003_021b94c4(ushort *param_1)

{
  undefined4 *puVar1;
  
  func_ov003_021b7d84(uRam021b9508,0,8);
  *puRam021b950c = 1;
  func_ov003_021b7d84(puRam021b9510,0,0x1c);
  puVar1 = puRam021b9510;
  *puRam021b9510 = param_1 + 3;
  puVar1[1] = (uint)param_1[2];
  puVar1[2] = *param_1 & 0xf;
  *(char *)((int)puVar1 + 0x19) = (char)param_1[1];
  puVar1[3] = 0;
  puVar1[4] = uRam021b9514;
  *(undefined1 *)(puVar1 + 6) = 0;
  return;
}

