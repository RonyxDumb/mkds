/* Decompiled C draft; module arm9; ROM address 02007014. No matching claim. */
#include "types.h"
#include "deps/02007014_FindGlobalGOBy_from_thumb.h"

int * FindGlobalGOBy_from_thumb(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)GetGlobalGO_from_thumb();
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
    if (*piVar1 == param_1) break;
    piVar1 = (int *)piVar1[10];
  }
  return piVar1;
}

