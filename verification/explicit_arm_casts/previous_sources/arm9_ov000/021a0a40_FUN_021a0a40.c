/* Decompiled C draft; module arm9_ov000; ROM address 021a0a40. No matching claim. */
#include "types.h"
#include "deps/021a0a40_FUN_021a0a40.h"

void FUN_021a0a40(undefined1 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 local_ac;
  undefined1 local_ab;
  undefined1 local_aa;
  undefined1 local_a9;
  undefined4 local_a8;
  undefined1 local_a4;
  byte local_a3;
  undefined2 local_a2;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 auStack_98 [132];
  
  if ((param_4 == 0) || (param_5 == 0)) {
    param_5 = 0;
  }
  else {
    func_0x0214d02c(param_4,auStack_98,param_5 << 2);
  }
  local_ac = *DAT_021a0adc;
  local_ab = DAT_021a0adc[1];
  local_aa = DAT_021a0adc[2];
  local_a9 = DAT_021a0adc[3];
  local_a8 = 3;
  local_a3 = (byte)(param_5 << 2);
  iVar3 = *DAT_021a0ae0;
  local_a2 = *(undefined2 *)(iVar3 + 0x1a);
  local_a0 = *(undefined4 *)(iVar3 + 0x1c);
  local_9c = *(undefined4 *)(iVar3 + DAT_021a0ae4);
  iVar3 = 0;
  local_a4 = param_1;
  while( true ) {
    uVar1 = FUN_0219a760(param_2,0,0);
    iVar2 = FUN_0218b530(*(undefined4 *)(*DAT_021a0ae0 + 0xe4),uVar1,param_3,&local_ac,
                         local_a3 + 0x14);
    if (iVar2 == 0) {
      return;
    }
    if (iVar2 != 2) break;
    iVar3 = iVar3 + 1;
    if (4 < iVar3) {
      return;
    }
  }
  return;
}

