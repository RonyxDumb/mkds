/* Decompiled C draft; module arm9; ROM address 020041e8. No matching claim. */
#include "types.h"
#include "deps/020041e8_Fs_FindArchiveByMountName.h"

uint Fs_FindArchiveByMountName(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = Fs_PackArchiveMountName();
  Os_DisableIrq();
  uVar3 = *(uint *)(uRam02004234 & 0xfffffffc) >> (uRam02004234 & 3) * 8 |
          *(uint *)(uRam02004234 & 0xfffffffc) << (uRam02004234 & 3) * -8 + 0x20;
  while ((uVar3 != 0 &&
         ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) != uVar2))) {
    uVar1 = uVar3 + 4 & 3;
    uVar3 = *(uint *)(uVar3 + 4 & 0xfffffffc);
    uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  }
  Os_RestoreIrq();
  return uVar3;
}

