/* Decompiled C draft; module arm9_ov001; ROM address 02185018. No matching claim. */
#include "types.h"
#include "deps/02185018_FUN_02185018.h"

void FUN_02185018(int param_1,uint param_2)

{
  if (param_2 == 0xffffffff) {
    *(undefined4 *)(param_1 + 0x40) = 2;
    *(undefined4 *)(param_1 + 0x34) = 1;
    return;
  }
  if (param_2 == 0xfffffffe) {
    func_0x02022040(param_1 + 0x2c);
    *(undefined4 *)(param_1 + 0x40) = 1;
    *(undefined4 *)(param_1 + 0x34) = 1;
    return;
  }
  if (param_2 == 0xfffffffd) {
    *(undefined4 *)(param_1 + 0x34) = 0;
    return;
  }
  if (param_2 == 0xfffffffc) {
    *(undefined4 *)(param_1 + 0xc) = 1;
    return;
  }
  if (param_2 == 0xfffffffb) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    return;
  }
  if (-1 < (int)param_2) {
    *(undefined4 *)(param_1 + 0xc) = 1;
    func_0x02022898(param_1 + 0x2c,param_2 & 0xffff);
  }
  return;
}

