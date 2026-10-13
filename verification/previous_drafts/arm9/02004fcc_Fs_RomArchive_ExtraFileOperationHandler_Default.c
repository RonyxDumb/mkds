/* Decompiled C draft; module arm9; ROM address 02004fcc. No matching claim. */
#include "types.h"
#include "deps/02004fcc_Fs_RomArchive_ExtraFileOperationHandler_Default.h"

undefined4 Fs_RomArchive_ExtraFileOperationHandler_Default(undefined4 param_1,int param_2)

{
  if (param_2 == 1) {
    return 4;
  }
  if (param_2 != 9) {
    if (param_2 != 10) {
      return 8;
    }
    Card_UnlockRomResource
              ((*(uint *)(uRam02005058 & 0xfffffffc) >> (uRam02005058 & 3) * 8 |
               *(uint *)(uRam02005058 & 0xfffffffc) << (uRam02005058 & 3) * -8 + 0x20) & 0xffff);
    return 0;
  }
  Card_LockRomResource
            ((*(uint *)(uRam02005058 & 0xfffffffc) >> (uRam02005058 & 3) * 8 |
             *(uint *)(uRam02005058 & 0xfffffffc) << (uRam02005058 & 3) * -8 + 0x20) & 0xffff);
  return 0;
}

