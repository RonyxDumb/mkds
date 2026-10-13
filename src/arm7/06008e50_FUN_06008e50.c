/* Decompiled C draft; module arm7; ROM address 06008e50. No matching claim. */
#include "types.h"
#include "deps/06008e50_FUN_06008e50.h"

undefined4 FUN_06008e50(uint *param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (*(ushort *)(param_2 + 10) == DAT_06008f30) {
    if (*(short *)(param_2 + 8) == *(short *)((int)param_1 + 10)) {
      thunk_FUN_037f8850(0x1000000);
      *(short *)(param_1 + 2) = (short)param_1[2] + -1;
      if ((short)param_1[2] == 0) {
        *param_1 = 0xffffffff;
        param_1[1] = 0xffffffff;
      }
      else if (param_2 ==
               (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20)) {
        uVar1 = param_2 + 4 & 3;
        uVar3 = *(uint *)(param_2 + 4 & 0xfffffffc);
        *param_1 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
        *(undefined4 *)
         (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
         *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) = 0xffffffff;
      }
      else {
        uVar1 = (uint)(param_1 + 1) & 3;
        uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
        if (param_2 == (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
          param_1[1] = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                       *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
          uVar1 = (uint)(param_1 + 1) & 3;
          uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
          *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 4) = 0xffffffff;
        }
        else {
          uVar1 = param_2 + 4 & 3;
          uVar3 = *(uint *)(param_2 + 4 & 0xfffffffc);
          *(uint *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) =
               *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
               *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
          uVar1 = param_2 + 4 & 3;
          uVar3 = *(uint *)(param_2 + 4 & 0xfffffffc);
          *(uint *)((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                    *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 4) =
               uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
        }
      }
      *(undefined2 *)(param_2 + 8) = 0;
      thunk_FUN_037f888c();
      uVar2 = 0;
    }
    else {
      uVar2 = 2;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

