/* Decompiled C draft; module arm9; ROM address 020fd494. No matching claim. */
#include "types.h"
#include "deps/020fd494_func_020fd494.h"

void func_020fd494(undefined4 *param_1)

{
  uint uVar1;
  uint uVar3;
  uint uVar2;
  
  uVar3 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  StateDualHandler_SetState(uVar3 + 0x184,0);
  uVar2 = uVar3 + 0x198 & 3;
  uVar1 = *(uint *)(uVar3 + 0x198 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 == 0) {
    uVar2 = uVar3 + 0x44 & 3;
    uVar1 = *(uint *)(uVar3 + 0x44 & 0xfffffffc);
    func_020f0f70((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) * 0x44 +
                  (*(uint *)(uRam020fd524 & 0xfffffffc) >> (uRam020fd524 & 3) * 8 |
                  *(uint *)(uRam020fd524 & 0xfffffffc) << (uRam020fd524 & 3) * -8 + 0x20),uVar3);
  }
  else {
    *(ushort *)(uVar2 + 2) = *(ushort *)(uVar2 + 2) & 0xfffe;
    func_020d2398();
    *(undefined4 *)(uVar3 + 0x198) = 0;
    uVar2 = uVar3 + 0x44 & 3;
    uVar1 = *(uint *)(uVar3 + 0x44 & 0xfffffffc);
    func_020f0f70((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) * 0x44 +
                  (*(uint *)(uRam020fd524 & 0xfffffffc) >> (uRam020fd524 & 3) * 8 |
                  *(uint *)(uRam020fd524 & 0xfffffffc) << (uRam020fd524 & 3) * -8 + 0x20),uVar3);
  }
  *param_1 = 0;
  return;
}

