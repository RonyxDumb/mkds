/* Decompiled C draft; module arm9; ROM address 020063f4. No matching claim. */
#include "types.h"
#include "deps/020063f4_func_020063f4.h"

uint * func_020063f4(uint param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = (uint *)GetGlobalGO_from_thumb();
  if (uRam02006454 <= param_1) {
    while( true ) {
      if (puVar1 == (uint *)0x0) {
        return (uint *)0x0;
      }
      if (*puVar1 == param_1) break;
      puVar1 = (uint *)puVar1[10];
    }
    uVar2 = puVar1[0xb];
    iVar3 = func_020070d8();
    return (uint *)(uVar2 + iVar3 * param_2);
  }
  uVar2 = 0;
  while( true ) {
    if (puVar1 == (uint *)0x0) {
      return (uint *)0x0;
    }
    if (uVar2 == param_1) break;
    uVar2 = uVar2 + 1;
    puVar1 = (uint *)puVar1[10];
  }
  iVar3 = func_020070d8();
  return (uint *)((int)puVar1 + iVar3 * param_2);
}

