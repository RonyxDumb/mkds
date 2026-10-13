/* Decompiled C draft; module arm9; ROM address 02080ee4. No matching claim. */
#include "types.h"
#include "deps/02080ee4_StructMQRacerEntry_SomeFn_3.h"

void StructMQRacerEntry_SomeFn_3(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = uRam02080f3c;
  uVar4 = (*(uint *)(uRam02080f3c & 0xfffffffc) >> (uRam02080f3c & 3) * 8 |
          *(uint *)(uRam02080f3c & 0xfffffffc) << (uRam02080f3c & 3) * -8 + 0x20) +
          (uint)*(ushort *)(param_1 + 0x74) * 4;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  if (uVar4 != 0) {
    *(undefined1 *)(uVar4 + 0x9a) = 0;
    uVar2 = uRam02080f40;
    *(undefined1 *)(uVar4 + 0x99) = 5;
    *(undefined4 *)(uVar4 + 0x90) = uVar2;
    uVar4 = uVar1 & 3;
    uVar3 = *(uint *)(uVar1 & 0xfffffffc);
    *(undefined4 *)
     ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + (uint)*(ushort *)(param_1 + 0x74) * 4) = 0
    ;
    return;
  }
  return;
}

