/* Decompiled C draft; module arm9; ROM address 0208ddf4. No matching claim. */
#include "types.h"
#include "deps/0208ddf4_MaybeLoadSomeExplosion.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void MaybeLoadSomeExplosion
               (undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,
               int param_6)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  ushort *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 local_4c;
  
  puVar7 = (ushort *)(param_2 * 0x2c + iRam0208e084);
  uVar8 = *(uint *)(uRam0208e088 & 0xfffffffc) >> (uRam0208e088 & 3) * 8 |
          *(uint *)(uRam0208e088 & 0xfffffffc) << (uRam0208e088 & 3) * -8 + 0x20;
  uVar9 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
  local_4c = 1;
  if ((uVar9 == 0x12) || (uVar9 == 0x1d)) {
    local_4c = 0;
  }
  if (*puVar7 == 0) {
    return;
  }
  if (param_2 != 3) {
    LoadedModelTexture_SomeFn((int)(uintptr_t)(puVar7 + 0xe),param_3,param_3);
  }
  if (param_2 == 2) {
    *puRam0208e08c = 1;
  }
  iVar3 = Nsbmd_GetMDL0Block(param_3);
  uVar9 = 0;
  uVar8 = iVar3 + (uint)*(ushort *)(iVar3 + 0xe) + 0xc;
  uVar1 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  if (*puVar7 == 0) {
    return;
  }
  do {
    uVar4 = (*(uint *)(uRam0208e090 & 0xfffffffc) >> (uRam0208e090 & 3) * 8 |
            *(uint *)(uRam0208e090 & 0xfffffffc) << (uRam0208e090 & 3) * -8 + 0x20) + param_2 * 4 +
            0x48;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + uVar9 * 4;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar10 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    StructML_SomeFn(uVar10 + 8,iVar3 + (uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20));
    uVar4 = uVar10 + 0xc & 3;
    uVar5 = *(uint *)(uVar10 + 0xc & 0xfffffffc);
    Maybe_helper_013044(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20,local_4c);
    uVar4 = uVar10 + 0x90 & 3;
    uVar5 = *(uint *)(uVar10 + 0x90 & 0xfffffffc);
    uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    if (uVar4 != 0) {
      if (param_4 == 0) {
        *(undefined2 *)(uVar4 + 0x18) = 0;
      }
      else {
        Animation_CreateFrom(0,uVar4,uVar10 + 8,1);
        Animation_RegisterAll(uVar4,param_4,param_1);
      }
      if (param_2 == 2) {
        uVar4 = uVar10 + 0x90 & 3;
        uVar5 = *(uint *)(uVar10 + 0x90 & 0xfffffffc);
        iVar6 = Animation_GetCurrentLength(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
        puVar2 = puRam0208e094;
        if (iVar6 >> 0xc == 0x20) {
          *puRam0208e094 = 0x37;
          puVar2[1] = 0x38;
        }
        else {
          *puRam0208e094 = 0x39;
          puVar2[1] = 0xffffffff;
        }
      }
    }
    uVar4 = uVar10 + 0x94 & 3;
    uVar5 = *(uint *)(uVar10 + 0x94 & 0xfffffffc);
    uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    if (uVar4 != 0) {
      if (param_5 == 0) {
        *(undefined2 *)(uVar4 + 0x18) = 0;
      }
      else {
        Animation_CreateFrom(4,uVar4,uVar10 + 8,1);
        Animation_RegisterAll(uVar4,param_5,param_1);
      }
    }
    uVar4 = uVar10 + 0x98 & 3;
    uVar5 = *(uint *)(uVar10 + 0x98 & 0xfffffffc);
    uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    if (uVar4 != 0) {
      if (param_6 == 0) {
        *(undefined2 *)(uVar4 + 0x18) = 0;
      }
      else {
        Animation_CreateFrom(1,uVar4,uVar10 + 8,1);
        Animation_RegisterAll(uVar4,param_6,param_1);
      }
    }
    uVar9 = uVar9 + 1 & 0xffff;
  } while (uVar9 < *puVar7);
  return;
}

