/* Decompiled C draft; module arm9; ROM address 02148e80. No matching claim. */
#include "types.h"
#include "deps/02148e80_GX_disableBankForX_.h"

ushort GX_disableBankForX_(ushort *param_1)

{
  ushort uVar1;
  
  uVar1 = *param_1;
  *param_1 = 0;
  if ((uVar1 & 1) != 0) {
    *puRam02148f3c = 0;
  }
  if ((uVar1 & 2) != 0) {
    *puRam02148f40 = 0;
  }
  if ((uVar1 & 4) != 0) {
    *puRam02148f44 = 0;
  }
  if ((uVar1 & 8) != 0) {
    *puRam02148f48 = 0;
  }
  if ((uVar1 & 0x10) != 0) {
    *puRam02148f4c = 0;
  }
  if ((uVar1 & 0x20) != 0) {
    *puRam02148f50 = 0;
  }
  if ((uVar1 & 0x40) != 0) {
    *puRam02148f54 = 0;
  }
  if ((uVar1 & 0x80) != 0) {
    *puRam02148f58 = 0;
  }
  if ((uVar1 & 0x100) != 0) {
    *puRam02148f5c = 0;
  }
  Os_UnlockVram(uVar1,*puRam02148f60);
  return uVar1;
}

