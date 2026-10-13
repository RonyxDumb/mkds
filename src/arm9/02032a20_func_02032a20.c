/* Decompiled C draft; module arm9; ROM address 02032a20. No matching claim. */
#include "types.h"
#include "deps/02032a20_func_02032a20.h"

void func_02032a20(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(*piRam02032aa0 + 0x68) == 0) {
    iVar2 = GetGlobalCA_from_thumb();
    *(undefined4 *)(iVar2 + 200) = 2;
    iVar2 = *(int *)(*piRam02032aa0 + 0x44);
    iVar3 = GetGlobalCA_from_thumb();
    *(uint *)(iVar3 + 0xe4) = (uint)(iVar2 != 0);
  }
  else if (*(int *)(*piRam02032aa0 + 0x44) == 0) {
    iVar2 = GetGlobalCA_from_thumb();
    *(undefined4 *)(iVar2 + 200) = 3;
  }
  else {
    iVar2 = GetGlobalCA_from_thumb();
    *(undefined4 *)(iVar2 + 200) = 2;
    iVar2 = *(int *)(*piRam02032aa0 + 0x44);
    iVar3 = GetGlobalCA_from_thumb();
    *(uint *)(iVar3 + 0xe4) = (uint)(iVar2 != 1);
  }
  piVar1 = piRam02032aa0;
  *(undefined4 *)(*piRam02032aa0 + 100) = 1;
  *(undefined4 *)(*piVar1 + 0x54) = 5;
  NNSi_MaybeSndPlayerStartSeq(uRam02032aa4,0);
  return;
}

