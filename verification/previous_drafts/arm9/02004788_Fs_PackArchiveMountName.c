/* Decompiled C draft; module arm9; ROM address 02004788. No matching claim. */
#include "types.h"
#include "deps/02004788_Fs_PackArchiveMountName.h"

uint Fs_PackArchiveMountName(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  if ((param_2 < 4) && (iVar3 = 0, 0 < param_2)) {
    uVar2 = 0;
    do {
      uVar1 = (uint)*(byte *)(param_1 + iVar3);
      if (uVar1 == 0) {
        return uVar4;
      }
      if (uVar1 - 0x41 < 0x1a) {
        uVar1 = uVar1 + 0x20;
      }
      iVar3 = iVar3 + 1;
      uVar4 = uVar4 | uVar1 << (uVar2 & 0xff);
      uVar2 = uVar2 + 8;
    } while (iVar3 < param_2);
  }
  return uVar4;
}

