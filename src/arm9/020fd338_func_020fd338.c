/* Decompiled C draft; module arm9; ROM address 020fd338. No matching claim. */
#include "types.h"
#include "deps/020fd338_func_020fd338.h"

int func_020fd338(int param_1,undefined4 param_2)

{
  uint uVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = func_020fa3d0(9,8,uRam020fd414,uRam020fd414);
  if (iVar5 == 0) {
    iVar5 = 0;
  }
  else {
    uVar1 = iVar5 + 0x74U & 3;
    uVar6 = *(uint *)(iVar5 + 0x74U & 0xfffffffc);
    if (((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 0x180000) == 0) {
      *(undefined4 *)(iVar5 + 0x120) = 0;
    }
    func_020f9c40(iVar5);
    *(undefined4 *)(iVar5 + 0x1a0) = 0;
    StateDualHandler_SetState(iVar5 + 0x184,3);
    *(undefined4 *)(iVar5 + 0x174) = 0;
  }
  if (iVar5 != 0) {
    func_020d233c(param_1);
    puVar3 = puRam020fd420;
    puVar2 = puRam020fd41c;
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020fd418;
    puVar4 = puRam020fd424;
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puVar2;
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puVar3;
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puVar4;
    *(int *)(iVar5 + 0x198) = param_1;
    *(undefined4 *)(iVar5 + 0x19c) = param_2;
    return iVar5;
  }
  return 0;
}

