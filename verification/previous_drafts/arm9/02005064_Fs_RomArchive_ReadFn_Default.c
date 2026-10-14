/* Decompiled C draft; module arm9; ROM address 02005064. No matching claim. */
#include "types.h"
#include "deps/02005064_Fs_RomArchive_ReadFn_Default.h"

undefined4
Fs_RomArchive_ReadFn_Default
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  func_021461d8(*(uint *)(uRam020050ac & 0xfffffffc) >> (uRam020050ac & 3) * 8 |
                *(uint *)(uRam020050ac & 0xfffffffc) << (uRam020050ac & 3) * -8 + 0x20,param_3,
                param_2,param_4,uRam020050a8,param_1,1);
  return 6;
}

