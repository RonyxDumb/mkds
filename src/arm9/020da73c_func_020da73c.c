/* Decompiled C draft; module arm9; ROM address 020da73c. No matching claim. */
#include "types.h"
#include "deps/020da73c_func_020da73c.h"

undefined1 func_020da73c(int param_1,int param_2,char *param_3,undefined1 *param_4)

{
  short sVar1;
  longlong lVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = uRam020da818;
  if (*param_3 == '\0') {
    uVar5 = param_1 + 0xc4U & 3;
    uVar4 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
    if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) == 0x1000) &&
       (uVar5 = param_1 + 200U & 3, uVar4 = *(uint *)(param_1 + 200U & 0xfffffffc),
       uVar4 >> uVar5 * 8 == 0 && uVar4 << uVar5 * -8 + 0x20 == 0)) {
      uVar5 = param_2 + 0x2a4U & 3;
      uVar4 = *(uint *)(param_2 + 0x2a4U & 0xfffffffc);
      uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
      lVar2 = (ulonglong)uVar5 * 0x52;
      *(uint *)(param_1 + 200) =
           (uint)lVar2 >> 0xc |
           (((int)uVar5 >> 0x1f) * 0x52 + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000;
    }
  }
  else if ((*param_3 == '\x01') &&
          (((sVar1 = *(short *)(param_1 + 0x8e), sVar1 == 0 || (sVar1 == 5)) || (sVar1 == 1)))) {
    *(undefined2 *)(param_1 + 0x90) = 2;
    *(undefined2 *)(param_1 + 0x92) = 1;
    func_020d26ec(param_2,uVar3);
    func_020d26f8(param_1,param_2);
    func_020da820(param_1,param_2 + 0xa4);
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020da81c;
  }
  return *param_4;
}

