/* Decompiled C draft; module arm9; ROM address 020a7fc4. No matching claim. */
#include "types.h"
#include "deps/020a7fc4_func_020a7fc4.h"

undefined1 func_020a7fc4(int param_1,undefined4 param_2,char *param_3,undefined1 *param_4)

{
  uint uVar1;
  undefined1 uVar2;
  ushort *puVar3;
  uint uVar4;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  uVar2 = *param_4;
  if (*param_3 == '\x01') {
    func_020a8098();
    puVar3 = puRam020a8078;
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020a8074;
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puVar3;
    func_020d26f8(param_1,param_2);
  }
  else {
    uVar1 = param_1 + 0xa4U & 3;
    uVar4 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
    if (uVar4 >> uVar1 * 8 == 0 && uVar4 << uVar1 * -8 + 0x20 == 0) {
      local_1c = param_1 + 4;
      local_20 = uRam020a807c;
      local_18 = 2;
      local_14 = func_020d4ef4();
      func_0210b7a8(&local_20);
      *(undefined4 *)(param_1 + 0xac) = 0x14;
    }
    *(undefined4 *)(param_1 + 0xa4) = 0x3c;
  }
  return uVar2;
}

