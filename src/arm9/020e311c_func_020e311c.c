/* Decompiled C draft; module arm9; ROM address 020e311c. No matching claim. */
#include "types.h"
#include "deps/020e311c_func_020e311c.h"

undefined1 func_020e311c(int param_1,int param_2,char *param_3,undefined1 *param_4)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int local_20 [2];
  int local_18;
  
  if (*param_3 == '\x01') {
    VecFx32_Subtract(param_1 + 4,param_2 + 0x80,local_20);
    uVar5 = param_2 + 0xa4U & 3;
    uVar6 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    uVar1 = param_2 + 0xacU & 3;
    uVar4 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    lVar2 = (longlong)local_18 * (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    lVar3 = (longlong)local_20[0] * (longlong)(int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20)
    ;
    if ((int)((int)((ulonglong)lVar2 >> 0x20) -
             ((int)((ulonglong)lVar3 >> 0x20) + (uint)((uint)lVar2 < (uint)lVar3))) < 0) {
      *(undefined4 *)(param_1 + 0xb4) = 1;
    }
    else {
      *(undefined4 *)(param_1 + 0xb4) = 0;
    }
    *(undefined4 *)(param_1 + 0x14) = 0x4000;
    *(undefined2 *)(param_1 + 0x90) = 6;
    *(undefined2 *)(param_1 + 0x92) = 1;
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020e3234;
    func_020d26f8(param_1,param_2);
  }
  else if (*param_3 == '\x02') {
    uVar5 = (uint)*(ushort *)(param_2 + 0x74) * 0x30 +
            (*(uint *)(uRam020e3230 & 0xfffffffc) >> (uRam020e3230 & 3) * 8 |
            *(uint *)(uRam020e3230 & 0xfffffffc) << (uRam020e3230 & 3) * -8 + 0x20) + 0x70;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if ((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) == 2) {
      return *param_4;
    }
    if (*(short *)(param_1 + 0x8e) == 7) {
      return *param_4;
    }
    *(undefined2 *)(param_1 + 0x90) = 7;
    *(undefined2 *)(param_1 + 0x92) = 1;
    func_020d26f8(param_1);
  }
  return *param_4;
}

