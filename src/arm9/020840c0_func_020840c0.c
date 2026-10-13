/* Decompiled C draft; module arm9; ROM address 020840c0. No matching claim. */
#include "types.h"
#include "deps/020840c0_func_020840c0.h"

void func_020840c0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = iRam02084110 + 0x1cU & 3;
  uVar3 = *(uint *)(iRam02084110 + 0x1cU & 0xfffffffc);
  uVar2 = iRam02084110 + 0x18U & 3;
  uVar4 = *(uint *)(iRam02084110 + 0x18U & 0xfffffffc);
  (*(code *)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20))
            ((uint)*(ushort *)
                    ((*(uint *)(uRam0208410c & 0xfffffffc) >> (uRam0208410c & 3) * 8 |
                     *(uint *)(uRam0208410c & 0xfffffffc) << (uRam0208410c & 3) * -8 + 0x20) +
                    (uint)*(ushort *)(param_1 + 0x74) * 2) * 0xc + iRam02084110,
             uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,param_1);
  StructMQRacerEntry_SomeFn_18(param_1,0);
  return;
}

