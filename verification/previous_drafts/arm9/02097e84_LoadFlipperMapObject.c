/* Decompiled C draft; module arm9; ROM address 02097e84. No matching claim. */
#include "types.h"
#include "deps/02097e84_LoadFlipperMapObject.h"

void LoadFlipperMapObject(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = CreateMapObjectFromModel_from_thumb(param_1,uRam02097ec0);
  uVar1 = uRam02097ec8;
  *puRam02097ec4 = uVar2;
  StructMapObject_AddAnimationNsbtp_from_thumb(uVar2,uVar1);
  StructMapObject_AddAnimationNsbta_from_thumb
            (*(uint *)((uint)puRam02097ec4 & 0xfffffffc) >> ((uint)puRam02097ec4 & 3) * 8 |
             *(uint *)((uint)puRam02097ec4 & 0xfffffffc) << ((uint)puRam02097ec4 & 3) * -8 + 0x20,
             uRam02097ecc);
  return;
}

