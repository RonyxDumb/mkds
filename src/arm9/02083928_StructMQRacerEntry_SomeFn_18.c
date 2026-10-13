/* Decompiled C draft; module arm9; ROM address 02083928. No matching claim. */
#include "types.h"
#include "deps/02083928_StructMQRacerEntry_SomeFn_18.h"

void StructMQRacerEntry_SomeFn_18(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = (uint)*(ushort *)(param_1 + 0x74) * 0x58 +
          (*(uint *)(uRam020839d4 & 0xfffffffc) >> (uRam020839d4 & 3) * 8 |
          *(uint *)(uRam020839d4 & 0xfffffffc) << (uRam020839d4 & 3) * -8 + 0x20);
  uVar6 = 0;
  do {
    iVar3 = iVar5 + uVar6 * 8;
    uVar2 = iVar3 + 0x10;
    uVar4 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    if ((uVar2 != 0) ||
       (uVar4 = iVar3 + 0x14, uVar1 = uVar4 & 3, uVar4 = *(uint *)(uVar4 & 0xfffffffc),
       uVar4 >> uVar1 * 8 != 0 || uVar4 << uVar1 * -8 + 0x20 != 0)) {
      if (param_2 == 0) {
        *(undefined1 *)(uVar2 + 0x99) = 1;
        uVar2 = iVar5 + uVar6 * 8 + 0x14;
        uVar4 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        *(undefined1 *)((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x99) = 1;
      }
      else {
        func_0208b710();
        uVar2 = iVar5 + uVar6 * 8 + 0x14;
        uVar4 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        func_0208b710(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20);
      }
      iVar3 = iVar5 + uVar6 * 8;
      *(undefined4 *)(iVar3 + 0x14) = 0;
      uVar2 = iVar3 + 0x14U & 3;
      uVar4 = *(uint *)(iVar3 + 0x14U & 0xfffffffc);
      *(uint *)(iVar3 + 0x10) = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
      *(undefined4 *)(iVar5 + uVar6 * 4 + 4) = 0xffffffff;
    }
    uVar6 = uVar6 + 1 & 0xffff;
  } while (uVar6 < 2);
  return;
}

