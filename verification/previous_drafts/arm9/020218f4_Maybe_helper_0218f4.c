/* Decompiled C draft; module arm9; ROM address 020218f4. No matching claim. */
#include "types.h"
#include "deps/020218f4_Maybe_helper_0218f4.h"

uint Maybe_helper_0218f4(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = iRam0202195c;
  if ((iRam0202195c <= param_1) && (iVar1 = param_1, 0 < param_1)) {
    iVar1 = 0;
  }
  if (iVar1 < -0xf0) {
    iVar2 = 3;
  }
  else if (iVar1 < -0x78) {
    iVar2 = 2;
  }
  else if (iVar1 < -0x3c) {
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
  }
  return (uint)*(byte *)(iRam02021964 + iVar1 + iRam02021960) | iVar2 << 8;
}

