/* Decompiled C draft; module arm9; ROM address 0205fdb4. No matching claim. */
#include "types.h"
#include "deps/0205fdb4_GenerateTimeTrialCode.h"

undefined4 GenerateTimeTrialCode(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_30 [24];
  char local_18;
  
  iVar2 = TimeTrialRecord_CopyFrom_from_thumb(param_1,0,auStack_30);
  if ((iVar2 == 0) || (local_18 == '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    uVar3 = GenerateTimeTrialCodeImpl(param_2,auStack_30,param_1);
    return uVar3;
  }
  return 0;
}

