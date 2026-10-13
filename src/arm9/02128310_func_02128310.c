/* Decompiled C draft; module arm9; ROM address 02128310. No matching claim. */
#include "types.h"
#include "deps/02128310_func_02128310.h"

void func_02128310(int param_1)

{
  int *piVar1;
  
  piVar1 = piRam0212835c;
  *(undefined4 *)(*piRam0212835c + iRam02128360) = 0;
  *(undefined4 *)(*piVar1 + iRam02128364) = 1;
  if (param_1 == 0) {
    *(undefined4 *)(*piVar1 + iRam02128368) = 0;
  }
  else {
    *(undefined4 *)(*piVar1 + iRam02128368) = 1;
  }
  if (*(uint *)(*piRam0212835c + iRam0212836c) != 0xffffffff) {
    NNSi_MaybeSndPlayerStartSeq(uRam02128370,0,*(uint *)(*piRam0212835c + iRam0212836c) & 0xffff);
  }
  return;
}

