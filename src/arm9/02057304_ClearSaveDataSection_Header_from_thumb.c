/* Decompiled C draft; module arm9; ROM address 02057304. No matching claim. */
#include "types.h"
#include "deps/02057304_ClearSaveDataSection_Header_from_thumb.h"

void ClearSaveDataSection_Header_from_thumb(int param_1)

{
  ushort uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  Mem_CpuFill8((uint *)(uintptr_t)(*(undefined4 *)*puRam020573b4),0,uRam020573b8);
  puVar2 = puRam020573b4;
  if (param_1 != 0) {
    iVar3 = *piRam020573bc;
    uVar1 = *(ushort *)(iVar3 + 0x3e);
    *(byte *)(*(int *)*puRam020573b4 + 0x31) = *(byte *)(*(int *)*puRam020573b4 + 0x31) & 0xfe | 1;
    Mem_CpuFill8((uint *)(uintptr_t)(*(int *)*puVar2 + 0xc),0,0x14);
    Mem_CpuCopy8((ushort *)(uintptr_t)(iVar3 + 0x2a),(uint *)(uintptr_t)(*(int *)*puRam020573b4 + 0xc),((uint)uVar1 << 0x11) >> 0x10);
  }
  puVar2 = puRam020573b4;
  *(byte *)(*(int *)*puRam020573b4 + 0x31) = *(byte *)(*(int *)*puRam020573b4 + 0x31) & 0xf9;
  *(byte *)(*(int *)*puVar2 + 0x31) = *(byte *)(*(int *)*puVar2 + 0x31) & 0xf7;
  *(byte *)(*(int *)*puVar2 + 0x31) = *(byte *)(*(int *)*puVar2 + 0x31) & 0xef;
  *(short *)(*(int *)*puVar2 + 0x24) = (short)uRam020573c0;
  func_0209119c();
  func_02152690(*(int *)*puRam020573b4 + 0x4c,uRam020573c4);
  return;
}

