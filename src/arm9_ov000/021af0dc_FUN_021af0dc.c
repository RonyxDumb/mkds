/* Decompiled C draft; module arm9_ov000; ROM address 021af0dc. No matching claim. */
#include "types.h"
#include "deps/021af0dc_FUN_021af0dc.h"

undefined4 FUN_021af0dc(int param_1,ushort *param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 local_18;
  
  bVar3 = false;
  local_18 = 0;
  bVar2 = false;
  bVar1 = false;
  if ((*(char *)(param_3 + 8) != '\n') && (*(char *)(param_3 + 8) != '\v')) {
    bVar1 = true;
  }
  if ((bVar1) &&
     ((uint)*(ushort *)(param_3 + 10) == ((int)(uint)param_2[1] >> 8 | (param_2[1] & 0xff) << 8))) {
    bVar2 = true;
  }
  if ((bVar2) &&
     ((uint)*(ushort *)(param_3 + 0x18) == ((int)(uint)*param_2 >> 8 | (*param_2 & 0xff) << 8))) {
    bVar3 = true;
  }
  if ((bVar3) &&
     (*(uint *)(param_3 + 0x1c) ==
      (((int)(uint)*(ushort *)(param_1 + 0xc) >> 8 | (*(ushort *)(param_1 + 0xc) & 0xff) << 8) <<
       0x10 | (int)(uint)*(ushort *)(param_1 + 0xe) >> 8 | (*(ushort *)(param_1 + 0xe) & 0xff) << 8)
     )) {
    local_18 = 1;
  }
  return local_18;
}

