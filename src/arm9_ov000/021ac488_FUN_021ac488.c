/* Decompiled C draft; module arm9_ov000; ROM address 021ac488. No matching claim. */
#include "types.h"
#include "deps/021ac488_FUN_021ac488.h"

void FUN_021ac488(int param_1,undefined2 *param_2,int param_3)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  puVar2 = (undefined1 *)(param_1 + param_3 + -1);
  if (1 < param_3) {
    do {
      *puVar2 = (char)*param_2;
      puVar3 = puVar2 + -1;
      puVar2 = puVar2 + -2;
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *puVar3 = (char)((ushort)uVar1 >> 8);
      param_3 = param_3 + -2;
    } while (1 < param_3);
  }
  if (0 < param_3) {
    *puVar2 = (char)*param_2;
  }
  return;
}

