/* Decompiled C draft; module arm9; ROM address 02004128. No matching claim. */
#include "types.h"
#include "deps/02004128_Fs_RegisterArchive.h"

undefined4 Fs_RegisterArchive(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  
  uVar8 = 0;
  uVar2 = Os_DisableIrq();
  iVar3 = Fs_FindArchiveByMountName(param_2,param_3);
  piVar1 = piRam020041e4;
  if (iVar3 == 0) {
    uVar7 = *(uint *)((uint)piRam020041e0 & 0xfffffffc) >> ((uint)piRam020041e0 & 3) * 8 |
            *(uint *)((uint)piRam020041e0 & 0xfffffffc) << ((uint)piRam020041e0 & 3) * -8 + 0x20;
    if (uVar7 == 0) {
      *piRam020041e0 = (int)param_1;
      *piVar1 = (int)param_1;
      piVar1[2] = 0;
      *(undefined2 *)((int)piVar1 + 6) = 0;
      *(undefined2 *)(piVar1 + 1) = 0;
    }
    else {
      uVar6 = uVar7 + 4 & 3;
      uVar4 = *(uint *)(uVar7 + 4 & 0xfffffffc);
      uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
      while (uVar6 != 0) {
        uVar4 = uVar6 + 4 & 3;
        uVar5 = *(uint *)(uVar6 + 4 & 0xfffffffc);
        uVar7 = uVar6;
        uVar6 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
      }
      *(undefined4 **)(uVar7 + 4) = param_1;
      param_1[2] = uVar7;
    }
    uVar8 = Fs_PackArchiveMountName(param_2,param_3);
    *param_1 = uVar8;
    uVar7 = (uint)(param_1 + 7) & 3;
    uVar6 = *(uint *)((uint)(param_1 + 7) & 0xfffffffc);
    uVar8 = 1;
    param_1[7] = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20 | 1;
  }
  Os_RestoreIrq(uVar2);
  return uVar8;
}

