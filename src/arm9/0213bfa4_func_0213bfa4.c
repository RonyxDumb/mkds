/* Decompiled C draft; module arm9; ROM address 0213bfa4. No matching claim. */
#include "types.h"
#include "deps/0213bfa4_func_0213bfa4.h"

uint func_0213bfa4(int param_1,int *param_2,undefined4 param_3)

{
  uint uVar1;
  bool bVar2;
  int iStack_24;
  uint local_20;
  int local_1c;
  int local_18 [3];
  
  local_18[1] = 0;
  local_18[0] = param_1;
  uVar1 = func_0213c560(param_3,0x7fffffff,uRam0213c06c,(undefined4)(uintptr_t)(local_18),&iStack_24,&local_20,&local_1c);
  if (param_2 != (int *)0x0) {
    *param_2 = param_1 + iStack_24;
  }
  if (((local_1c == 0) && ((local_20 != 0 || (uVar1 < 0x80000000)))) &&
     ((local_20 == 0 || (uVar1 < 0x80000001)))) {
    if (local_20 != 0) {
      uVar1 = -uVar1;
    }
    return uVar1;
  }
  bVar2 = local_20 != 0;
  if (bVar2) {
    local_20 = 0x80000000;
  }
  *puRam0213c070 = 0x22;
  if (!bVar2) {
    local_20 = 0x7fffffff;
  }
  return local_20;
}

