/* Decompiled C draft; module arm9; ROM address 02084384. No matching claim. */
#include "types.h"
#include "deps/02084384_func_02084384.h"

void func_02084384(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = iRam020843d4 + 0x1cU & 3;
  uVar3 = *(uint *)(iRam020843d4 + 0x1cU & 0xfffffffc);
  uVar2 = iRam020843d4 + 0x18U & 3;
  uVar4 = *(uint *)(iRam020843d4 + 0x18U & 0xfffffffc);
  (*(code *)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20))
            ((uint)*(ushort *)
                    ((*(uint *)(uRam020843d0 & 0xfffffffc) >> (uRam020843d0 & 3) * 8 |
                     *(uint *)(uRam020843d0 & 0xfffffffc) << (uRam020843d0 & 3) * -8 + 0x20) +
                    (uint)*(ushort *)(param_1 + 0x74) * 2) * 0xc + iRam020843d4,
             uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,param_1);
  StructMQRacerEntry_SomeFn_18(param_1,0);
  return;
}

