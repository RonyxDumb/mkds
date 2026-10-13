/* Decompiled C draft; module arm9; ROM address 021087d4. No matching claim. */
#include "types.h"
#include "deps/021087d4_ComputeRAudioBufferAllocSize.h"

int ComputeRAudioBufferAllocSize(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 2) {
    iVar2 = 0xaf000;
  }
  else {
    iVar2 = 0xc400;
  }
  if (param_1 == 0) {
    iVar1 = 0xc8000;
  }
  else {
    iVar1 = 0xaf000;
  }
  return iVar1 - iVar2;
}

