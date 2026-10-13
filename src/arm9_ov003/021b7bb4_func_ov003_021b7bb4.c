/* Decompiled C draft; module arm9_ov003; ROM address 021b7bb4. No matching claim. */
#include "types.h"
#include "deps/021b7bb4_func_ov003_021b7bb4.h"

uint func_ov003_021b7bb4(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int local_18;
  int local_14;
  int local_10;
  
  if (*piRam021b7c1c == 0) {
    uVar3 = 0;
    func_ov003_021b7d84(&local_18,0,0xc);
    iVar2 = func_0x0214df78((undefined4)(uintptr_t)(&local_18));
    puVar1 = puRam021b7c20;
    if (iVar2 == 0) {
      uVar3 = local_18 * 0x400 + local_14 * 8 + local_10;
    }
    *puRam021b7c20 = uVar3;
    puVar1[1] = uRam021b7c24;
    puVar1[2] = uRam021b7c28;
    *piRam021b7c1c = 1;
  }
  uVar3 = puRam021b7c20[2] + *puRam021b7c20 * puRam021b7c20[1];
  *puRam021b7c20 = uVar3;
  return iRam021b7c2c * (uVar3 >> 0x10) >> 0x10;
}

