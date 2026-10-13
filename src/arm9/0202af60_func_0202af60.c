/* Decompiled C draft; module arm9; ROM address 0202af60. No matching claim. */
#include "types.h"
#include "deps/0202af60_func_0202af60.h"

int func_0202af60(void)

{
  bool bVar1;
  int extraout_r1;
  int extraout_r1_00;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  
  iVar3 = *piRam0202afd8;
  lVar5 = Multiply64(*(undefined4 *)(iVar3 + 0x9c),*(undefined4 *)(iVar3 + 0xa0),
                     *(undefined4 *)(iVar3 + 0x94),*(undefined4 *)(iVar3 + 0x98));
  *(longlong *)(iVar3 + 0x94) = lVar5 + *(longlong *)(iVar3 + 0xa4);
  _s32_div_f(*(uint *)(iVar3 + 0x98) >> 0x14,0x14);
  iVar4 = *piRam0202afdc;
  iVar3 = extraout_r1;
  do {
    bVar1 = true;
    _s32_div_f(iVar3 + 1,0x14);
    iVar2 = 0;
    iVar3 = iVar4;
    do {
      if (*(int *)(iVar3 + 0x5c) == *(int *)(iRam0202afe0 + extraout_r1_00 * 4)) {
        bVar1 = false;
        break;
      }
      iVar3 = iVar3 + 4;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
    iVar3 = extraout_r1_00;
    if (bVar1) {
      return extraout_r1_00;
    }
  } while( true );
}

