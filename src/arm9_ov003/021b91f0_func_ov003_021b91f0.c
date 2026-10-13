/* Decompiled C draft; module arm9_ov003; ROM address 021b91f0. No matching claim. */
#include "types.h"
#include "deps/021b91f0_func_ov003_021b91f0.h"

undefined4 func_ov003_021b91f0(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  uint local_20;
  undefined4 local_1c;
  
  iVar4 = 0;
  local_1c = 0;
  local_20 = *param_1;
  if (local_20 == 0) {
    return 5;
  }
  if (0x40 < local_20) {
    local_20 = 0x40;
  }
  iVar6 = 0;
  if (0 < (int)local_20) {
    puVar5 = param_1 + 2;
    do {
      if ((param_1[0x15] & 1) != 0) {
        uVar1 = func_ov003_021b7c30((char *)(uintptr_t)(uRam021b9274));
        if (param_1[1] == uVar1) {
          uVar2 = func_ov003_021b7c30((char *)(uintptr_t)(uRam021b9274));
          iVar3 = func_ov003_021b7da0((byte *)(void *)(puVar5),(byte *)(uintptr_t)(uRam021b9274),uVar2);
          if (iVar3 == 0) {
            iVar4 = iVar4 + 1;
          }
        }
      }
      param_1 = param_1 + 0x15;
      puVar5 = puVar5 + 0x15;
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)local_20);
  }
  if (1 < iVar4) {
    local_1c = 4;
  }
  if (iVar4 == 0) {
    local_1c = 5;
  }
  return local_1c;
}

