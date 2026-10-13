/* Decompiled C draft; module arm9_ov000; ROM address 021a58dc. No matching claim. */
#include "types.h"
#include "deps/021a58dc_FUN_021a58dc.h"

uint FUN_021a58dc(int param_1)

{
  int extraout_r1;
  int extraout_r1_00;
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  uVar3 = *(uint *)(*DAT_021a5928 + DAT_021a592c);
  iVar1 = param_1;
  do {
    func_0x02133068(iVar1,0xd);
    if ((uVar3 & 1 << (extraout_r1 + 1U & 0xff)) != 0) break;
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xd);
  func_0x02133068(param_1 + iVar2,0xd);
  return extraout_r1_00 + 1U & 0xffff;
}

