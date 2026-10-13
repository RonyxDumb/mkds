/* Decompiled C draft; module arm9; ROM address 02080fb8. No matching claim. */
#include "types.h"
#include "deps/02080fb8_StructMQRacerEntry_SomeFn_22.h"

void StructMQRacerEntry_SomeFn_22(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02080ffc & 0xfffffffc) >> (uRam02080ffc & 3) * 8 |
          *(uint *)(uRam02080ffc & 0xfffffffc) << (uRam02080ffc & 3) * -8 + 0x20) +
          (uint)*(ushort *)(param_1 + 0x74) * 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_0208b710();
    *(undefined4 *)
     ((*(uint *)(uRam02080ffc & 0xfffffffc) >> (uRam02080ffc & 3) * 8 |
      *(uint *)(uRam02080ffc & 0xfffffffc) << (uRam02080ffc & 3) * -8 + 0x20) +
     (uint)*(ushort *)(param_1 + 0x74) * 4) = 0;
    return;
  }
  return;
}

