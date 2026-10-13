/* Decompiled C draft; module arm9; ROM address 02080f44. No matching claim. */
#include "types.h"
#include "deps/02080f44_StructMQRacerEntry_SomeFn_62.h"

void StructMQRacerEntry_SomeFn_62(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar1 = (*(uint *)(uRam02080fac & 0xfffffffc) >> (uRam02080fac & 3) * 8 |
          *(uint *)(uRam02080fac & 0xfffffffc) << (uRam02080fac & 3) * -8 + 0x20) +
          (uint)*(ushort *)(param_1 + 0x74) * 4;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if (uVar1 >> uVar3 * 8 == 0 && uVar1 << uVar3 * -8 + 0x20 == 0) {
    uVar2 = func_0208b7bc(0x7f,uRam02080fb0);
    uVar3 = uRam02080fac;
    *(undefined4 *)
     ((*(uint *)(uRam02080fac & 0xfffffffc) >> (uRam02080fac & 3) * 8 |
      *(uint *)(uRam02080fac & 0xfffffffc) << (uRam02080fac & 3) * -8 + 0x20) +
     (uint)*(ushort *)(param_1 + 0x74) * 4) = uVar2;
    uVar2 = uRam02080fb4;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar1 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) +
            (uint)*(ushort *)(param_1 + 0x74) * 4;
    uVar3 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar1 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
    *(char *)(uVar1 + 0x9b) = (char)*(ushort *)(param_1 + 0x74);
    *(undefined4 *)(uVar1 + 0x94) = 1;
    *(undefined4 *)(uVar1 + 0x90) = uVar2;
    return;
  }
  return;
}

