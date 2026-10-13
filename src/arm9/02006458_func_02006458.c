/* Decompiled C draft; module arm9; ROM address 02006458. No matching claim. */
#include "types.h"
#include "deps/02006458_func_02006458.h"

int func_02006458(uint param_1,int param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int local_1c;
  
  puVar2 = (uint *)GetGlobalGO_from_thumb();
  if (param_1 < uRam020064f8) {
    return param_2;
  }
  while( true ) {
    if (puVar2 == (uint *)0x0) {
      return -1;
    }
    if (*puVar2 == param_1) break;
    puVar2 = (uint *)puVar2[10];
  }
  if (param_1 == *puRam020064fc) {
    iVar5 = 0;
    local_1c = 0;
    do {
      if ((param_2 != *piRam02006500) && (param_2 != *piRam02006504)) break;
      param_2 = param_2 + 1;
      iVar3 = func_020070d8();
      uVar4 = func_020070d8();
      iVar3 = _s32_div_f(puVar2[1] + iVar3 + -1,uVar4);
      if (iVar3 + -1 < param_2) {
        param_2 = local_1c;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 3);
  }
  *puRam020064fc = param_1;
  piVar1 = piRam02006500;
  *piRam02006504 = *piRam02006500;
  *piVar1 = param_2;
  return param_2;
}

