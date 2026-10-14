/* Decompiled C draft; module arm9; ROM address 0214ffb4. No matching claim. */
#include "types.h"
#include "deps/0214ffb4_Fifo8Handler.h"

void Fifo8Handler(undefined4 param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar6;
  undefined2 *puVar5;
  
  if (param_3 == 0) {
    uVar3 = param_2 & 0xff;
    uVar1 = ((param_2 & 0x7f00) << 8) >> 0x10;
    if ((uVar1 < 0x70) || (0x73 < uVar1)) {
      if (uVar1 == 0x60) {
        *puRam02150094 = 1;
      }
      else if (uVar1 == 0x62) {
        *puRam02150098 = 1;
      }
      else if (uVar1 == 0x67) {
        uVar1 = iRam0215009c + 0xcU & 3;
        uVar4 = *(uint *)(iRam0215009c + 0xcU & 0xfffffffc);
        puVar6 = (uint *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
        if (puVar6 != (uint *)0x0) {
          *puVar6 = uVar3;
        }
        uVar3 = 0;
      }
    }
    else {
      uVar4 = iRam0215008c + (uVar1 - 0x70) * 8;
      uVar2 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      puVar5 = (undefined2 *)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
      if (puVar5 != (undefined2 *)0x0) {
        *puVar5 = (short)uVar3;
      }
      *(undefined2 *)(iRam02150090 + (uVar1 - 0x70) * 8) = 1;
      uVar3 = 0;
    }
    func_02150164(uVar3);
    return;
  }
  func_02150164(2);
  return;
}

