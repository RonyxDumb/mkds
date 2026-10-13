/* Decompiled C draft; module arm9_ov001; ROM address 02188dcc. No matching claim. */
#include "types.h"
#include "deps/02188dcc_FUN_02188dcc.h"

void FUN_02188dcc(int param_1,int param_2)

{
  if (param_2 == 0) {
    param_2 = DAT_02188dd8;
  }
  *(int *)(param_1 + DAT_02188ddc) = param_2;
  return;
}

