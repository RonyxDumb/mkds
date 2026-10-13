/* Decompiled C draft; module arm9_ov003; ROM address 021b9518. No matching claim. */
#include "types.h"
#include "deps/021b9518_func_ov003_021b9518.h"

void func_ov003_021b9518(void)

{
  if (*piRam021b9548 != 0) {
    func_ov003_021ba164();
    *piRam021b9548 = 0;
  }
  if (*piRam021b954c != 0) {
    func_ov003_021ba164();
    *piRam021b954c = 0;
  }
  return;
}

