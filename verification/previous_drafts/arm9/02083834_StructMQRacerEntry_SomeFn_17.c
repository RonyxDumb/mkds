/* Decompiled C draft; module arm9; ROM address 02083834. No matching claim. */
#include "types.h"
#include "deps/02083834_StructMQRacerEntry_SomeFn_17.h"

void StructMQRacerEntry_SomeFn_17(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)
           ((uint)*(ushort *)(param_1 + 0x74) * 0x58 +
           (*(uint *)(uRam020838d8 & 0xfffffffc) >> (uRam020838d8 & 3) * 8 |
           *(uint *)(uRam020838d8 & 0xfffffffc) << (uRam020838d8 & 3) * -8 + 0x20));
  uVar1 = (uint)(puVar4 + 3) & 3;
  uVar2 = *(uint *)((uint)(puVar4 + 3) & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_0208b710();
    puVar4[3] = 0;
    *puVar4 = 0xffffffff;
  }
  StructMQRacerEntry_SomeFn_18(param_1,1);
  iVar3 = (uint)*(ushort *)(param_1 + 0x74) * 0x58 +
          (*(uint *)(uRam020838d8 & 0xfffffffc) >> (uRam020838d8 & 3) * 8 |
          *(uint *)(uRam020838d8 & 0xfffffffc) << (uRam020838d8 & 3) * -8 + 0x20);
  uVar1 = iVar3 + 0x20U & 3;
  uVar2 = *(uint *)(iVar3 + 0x20U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_0208b710();
    *(undefined4 *)(iVar3 + 0x20) = 0;
  }
  uVar1 = iVar3 + 0x24U & 3;
  uVar2 = *(uint *)(iVar3 + 0x24U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_0208b710();
    *(undefined4 *)(iVar3 + 0x24) = 0;
    return;
  }
  return;
}

