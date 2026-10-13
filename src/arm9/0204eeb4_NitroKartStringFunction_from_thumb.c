/* Decompiled C draft; module arm9; ROM address 0204eeb4. No matching claim. */
#include "types.h"
#include "deps/0204eeb4_NitroKartStringFunction_from_thumb.h"

void NitroKartStringFunction_from_thumb(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)*(ushort *)(*piRam0204ef04 + iRam0204ef08);
  iVar3 = uVar2 * 0x88;
  StructGO_SomeFn_from_thumb
            ((undefined4 *)(uintptr_t)(*piRam0204ef04 + iRam0204ef0c + iVar3),uVar2 + iRam0204ef10 & 0xffff,uRam0204ef14,
             param_1,param_2,0);
  piVar1 = piRam0204ef04;
  *(undefined4 *)(*piRam0204ef04 + iVar3 + iRam0204ef18) = param_1;
  *(short *)(*piVar1 + iRam0204ef08) = *(short *)(*piVar1 + iRam0204ef08) + 1;
  return;
}

