/* Decompiled C draft; module arm9; ROM address 020fa3d0. No matching claim. */
#include "types.h"
#include "deps/020fa3d0_func_020fa3d0.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

int func_020fa3d0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int local_1c [2];
  
  local_1c[0] = 0;
  iVar2 = (*(uint *)(uRam020fa4ac & 0xfffffffc) >> (uRam020fa4ac & 3) * 8 |
          *(uint *)(uRam020fa4ac & 0xfffffffc) << (uRam020fa4ac & 3) * -8 + 0x20) + param_1 * 0x44;
  uVar3 = iVar2 + 0x20U & 3;
  uVar5 = *(uint *)(iVar2 + 0x20U & 0xfffffffc);
  uVar1 = iVar2 + 0x1cU & 3;
  uVar4 = *(uint *)(iVar2 + 0x1cU & 0xfffffffc);
  if (0 < (int)((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) -
               (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20))) {
    func_020f1048(iVar2,1,local_1c,param_2);
    uVar4 = uRam020fa4ac;
    iVar2 = (*(uint *)(uRam020fa4ac & 0xfffffffc) >> (uRam020fa4ac & 3) * 8 |
            *(uint *)(uRam020fa4ac & 0xfffffffc) << (uRam020fa4ac & 3) * -8 + 0x20) + param_1 * 0x44
    ;
    uVar3 = iVar2 + 0x1c;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(iVar2 + 0x1c) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 1;
    uVar1 = uVar4 & 3;
    uVar5 = *(uint *)(uVar4 & 0xfffffffc);
    uVar3 = local_1c[0] + 0x44U & 3;
    uVar4 = *(uint *)(local_1c[0] + 0x44U & 0xfffffffc);
    func_020f0ea0((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) * 0x44 +
                  (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20));
    func_020f98a0(local_1c[0],param_3,param_4);
    if (param_2 == 8) {
      *(ushort *)(local_1c[0] + 0x78) = *(ushort *)(local_1c[0] + 0x78) | *puRam020fa4b0;
    }
    return local_1c[0];
  }
  return 0;
}

