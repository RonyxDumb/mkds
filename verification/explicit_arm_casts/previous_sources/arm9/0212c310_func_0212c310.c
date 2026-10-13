/* Decompiled C draft; module arm9; ROM address 0212c310. No matching claim. */
#include "types.h"
#include "deps/0212c310_func_0212c310.h"

void func_0212c310(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  IntrusiveListWrapper_InitializeEmpty(uRam0212c3b8,0x14);
  IntrusiveListWrapper_InitializeEmpty(uRam0212c3bc,0x14);
  uVar1 = uRam0212c3bc;
  iVar3 = 0;
  iVar2 = iRam0212c3c0;
  do {
    *(undefined1 *)(iVar2 + 0x2c) = 0;
    *(char *)(iVar2 + 0x3c) = (char)iVar3;
    IntrusiveListWrapper_InsertLast(uVar1,iVar2);
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 0x44;
  } while (iVar3 < 0x10);
  iVar3 = 0;
  iVar2 = iRam0212c3c4;
  do {
    IntrusiveListWrapper_InitializeEmpty(iVar2,0xc);
    IntrusiveListWrapper_InitializeEmpty(iVar2 + 0xc,0);
    *(undefined1 *)(iVar2 + 0x20) = 0x7f;
    *(undefined4 *)(iVar2 + 0x18) = 1;
    iVar3 = iVar3 + 1;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    iVar2 = iVar2 + 0x24;
  } while (iVar3 < 0x20);
  return;
}

