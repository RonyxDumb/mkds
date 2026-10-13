/* Decompiled C draft; module arm9; ROM address 02093708. No matching claim. */
#include "types.h"
#include "deps/02093708_func_02093708.h"

void func_02093708(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = CreateMapObjectFromModel_from_thumb(param_1,uRam02093748);
  uVar1 = uRam02093750;
  *puRam0209374c = uVar2;
  StructMapObject_AddAnimationNsbta_from_thumb(uVar2,uVar1);
  StructMapObject_MaybeSetPolygonId
            (*(uint *)((uint)puRam0209374c & 0xfffffffc) >> ((uint)puRam0209374c & 3) * 8 |
             *(uint *)((uint)puRam0209374c & 0xfffffffc) << ((uint)puRam0209374c & 3) * -8 + 0x20,
             0x3f);
  *(undefined4 *)(param_1 + 0x1c) = 1;
  return;
}

