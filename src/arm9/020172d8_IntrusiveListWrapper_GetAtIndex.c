/* Decompiled C draft; module arm9; ROM address 020172d8. No matching claim. */
#include "types.h"
#include "deps/020172d8_IntrusiveListWrapper_GetAtIndex.h"

int IntrusiveListWrapper_GetAtIndex(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = IntrusiveListWrapper_NextItem(param_1,0);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (iVar2 == param_2) break;
    iVar2 = iVar2 + 1;
    iVar1 = IntrusiveListWrapper_NextItem(param_1);
  }
  return iVar1;
}

