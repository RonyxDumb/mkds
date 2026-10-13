/* Decompiled C draft; module arm7; ROM address 06001e64. No matching claim. */
#include "types.h"
#include "deps/06001e64_FUN_06001e64.h"

void FUN_06001e64(void)

{
  ushort uVar1;
  int iVar2;
  int local_18;
  
  iVar2 = FUN_06000680();
  while( true ) {
    thunk_FUN_037f97b4(iVar2 + 0x28,&local_18,1);
    if (local_18 == 0) break;
    uVar1 = *(ushort *)(local_18 + 0xc);
    if ((((uVar1 & 0xff00) == 0) || ((uVar1 & 0xff00) == 0x100)) && ((uVar1 & 0x80) != 0)) {
      FUN_06001cdc(local_18);
    }
    else {
      thunk_FUN_037f9854(iVar2 + 0x58,local_18,1);
    }
  }
  thunk_FUN_037f92a4();
  return;
}

