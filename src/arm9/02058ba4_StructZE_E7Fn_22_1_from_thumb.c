/* Decompiled C draft; module arm9; ROM address 02058ba4. No matching claim. */
#include "types.h"
#include "deps/02058ba4_StructZE_E7Fn_22_1_from_thumb.h"

void StructZE_E7Fn_22_1_from_thumb(void)

{
  int iVar1;
  short extraout_r1;
  undefined8 uVar2;
  
  iVar1 = Os_GetTick();
  if (*psRam02058bf8 == 2) {
    uVar2 = Multiply64(iVar1 << 8,0,uRam02058bfc,uRam02058c00);
    Multiply64((int)((ulonglong)uVar2 >> 0x20) + (uint)CARRY4((uint)uVar2,uRam02058c04),0,0xb4);
    *(short *)(*piRam02058c08 + iRam02058c0c) = extraout_r1 + 0x78;
    return;
  }
  *(undefined2 *)(*piRam02058c08 + iRam02058c0c) = 0xb4;
  return;
}

