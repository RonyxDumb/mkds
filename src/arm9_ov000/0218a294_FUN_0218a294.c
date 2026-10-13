/* Decompiled C draft; module arm9_ov000; ROM address 0218a294. No matching claim. */
#include "types.h"
#include "deps/0218a294_FUN_0218a294.h"

int FUN_0218a294(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_02188528();
  iVar2 = FUN_02188584(0x10);
  iVar3 = FUN_021a5bfc();
  if (iVar3 == 9) {
    switch(iVar1) {
    case 10:
      iVar1 = FUN_0218a24c(iVar2);
      break;
    case 0xb:
      iVar1 = FUN_0218a0f4();
      break;
    case 0xc:
      iVar1 = FUN_0218a1bc(iVar2);
      break;
    case 0xd:
      iVar1 = FUN_0218a194();
      break;
    case 0xe:
      iVar1 = FUN_0218a130(iVar2);
      break;
    case 0xf:
      iVar1 = FUN_0218a118(iVar2);
    }
  }
  else if (iVar1 == 0xb) {
    iVar1 = FUN_0218a0f4();
  }
  else {
    if (iVar1 == 0xe) {
      FUN_02187fb8();
      FUN_02188068();
    }
    else if (iVar1 == 0xf) {
      iVar1 = FUN_0218a118(iVar2);
      return iVar1;
    }
    *(undefined1 *)(iVar2 + (uint)*(byte *)(iVar2 + DAT_0218a348) * 4 + DAT_0218a34c) = 2;
    iVar1 = 0xb;
  }
  return iVar1;
}

