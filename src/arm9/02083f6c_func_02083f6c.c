/* Decompiled C draft; module arm9; ROM address 02083f6c. No matching claim. */
#include "types.h"
#include "deps/02083f6c_func_02083f6c.h"

void func_02083f6c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  uVar2 = param_2 + 0x4cU & 3;
  uVar1 = *(uint *)(param_2 + 0x4cU & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x8000) == 0) {
    puVar3 = (undefined4 *)
             ((uint)*(ushort *)(param_2 + 0x74) * 0x58 +
             (*(uint *)(uRam02084030 & 0xfffffffc) >> (uRam02084030 & 3) * 8 |
             *(uint *)(uRam02084030 & 0xfffffffc) << (uRam02084030 & 3) * -8 + 0x20));
    uVar2 = (uint)(puVar3 + 3) & 3;
    uVar1 = *(uint *)((uint)(puVar3 + 3) & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 != 0) {
      *(undefined1 *)(uVar2 + 0x99) = 1;
      puVar3[3] = 0;
      *puVar3 = 0xffffffff;
    }
    StructMQRacerEntry_SomeFn_18(param_2,0);
    iVar4 = (uint)*(ushort *)(param_2 + 0x74) * 0x58 +
            (*(uint *)(uRam02084030 & 0xfffffffc) >> (uRam02084030 & 3) * 8 |
            *(uint *)(uRam02084030 & 0xfffffffc) << (uRam02084030 & 3) * -8 + 0x20);
    uVar2 = iVar4 + 0x20U & 3;
    uVar1 = *(uint *)(iVar4 + 0x20U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 != 0) {
      *(undefined1 *)(uVar2 + 0x99) = 1;
      *(undefined4 *)(iVar4 + 0x20) = 0;
    }
    uVar2 = iVar4 + 0x24U & 3;
    uVar1 = *(uint *)(iVar4 + 0x24U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 != 0) {
      *(undefined1 *)(uVar2 + 0x99) = 1;
      *(undefined4 *)(iVar4 + 0x24) = 0;
    }
    return;
  }
  uVar2 = iRam0208402c + param_1 * 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  (*(code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))(param_2);
  return;
}

