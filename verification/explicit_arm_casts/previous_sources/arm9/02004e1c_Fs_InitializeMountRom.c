/* Decompiled C draft; module arm9; ROM address 02004e1c. No matching claim. */
#include "types.h"
#include "deps/02004e1c_Fs_InitializeMountRom.h"

void Fs_InitializeMountRom(undefined4 param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  
  *puRam02004f80 = param_1;
  uVar5 = Os_AllocateLockId();
  puVar3 = puRam02004f8c;
  puVar2 = puRam02004f88;
  *puRam02004f84 = uVar5;
  *puVar2 = 0;
  puVar2[1] = 0;
  *puVar3 = 0;
  puVar3[1] = 0;
  Card_Initialize();
  Fs_Archive_Initialize(uRam02004f90);
  Fs_RegisterArchive(uRam02004f90,uRam02004f94,3);
  uVar7 = uRam02004fb4;
  uVar6 = uRam02004fa8;
  uVar4 = uRam02004f9c;
  uVar5 = uRam02004f90;
  puVar3 = puRam02004f8c;
  puVar2 = puRam02004f88;
  if (*psRam02004f98 == 2) {
    *puRam02004f88 = 0xffffffff;
    puVar2[1] = 0;
    *puVar3 = 0xffffffff;
    puVar3[1] = 0;
    Fs_Archive_SetExtraFileOperationHandler(uVar5,uVar4);
    Fs_Archive_LoadFromFatFnt(uRam02004f90,0,0,0);
    return;
  }
  Fs_Archive_SetExtraFileOperationHandler(uRam02004f90,uRam02004fac,uRam02004fb0);
  uVar1 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  if (uVar6 == 0xffffffff) {
    return;
  }
  if (uVar6 == 0) {
    return;
  }
  uVar6 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
  if (uVar6 != 0xffffffff) {
    if (uVar6 != 0) {
      uVar1 = uVar7 + 4 & 3;
      uVar7 = *(uint *)(uVar7 + 4 & 0xfffffffc);
      Fs_Archive_LoadFromFatFnt
                (uRam02004f90,0,uVar6,uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
      return;
    }
    return;
  }
  return;
}

