/* Decompiled C draft; module arm9; ROM address 020da684. No matching claim. */
#include "types.h"
#include "deps/020da684_func_020da684.h"

undefined1 func_020da684(int param_1,int param_2,char *param_3,undefined1 *param_4)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  
  if (*param_3 == '\0') {
    uVar1 = param_1 + 0xc4U & 3;
    uVar3 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 0x1000) &&
       (uVar1 = param_1 + 200U & 3, uVar3 = *(uint *)(param_1 + 200U & 0xfffffffc),
       uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0)) {
      *(undefined4 *)(param_1 + 200) = uRam020da734;
    }
  }
  else if ((*param_3 == '\x01') &&
          (((sVar2 = *(short *)(param_1 + 0x8e), sVar2 == 0 || (sVar2 == 5)) || (sVar2 == 1)))) {
    *(undefined2 *)(param_1 + 0x90) = 2;
    *(undefined2 *)(param_1 + 0x92) = 1;
    func_020f8ddc(param_2);
    if (param_2 != 0) {
      func_020da820(param_1,param_2 + 0x5c);
    }
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020da738;
  }
  return *param_4;
}

