/* Decompiled C draft; module arm9; ROM address 020de6a8. No matching claim. */
#include "types.h"
#include "deps/020de6a8_func_020de6a8.h"

void func_020de6a8(short *param_1,undefined4 *param_2)

{
  longlong *plVar1;
  int iVar2;
  short extraout_r1;
  short extraout_r1_00;
  undefined4 uVar3;
  longlong lVar4;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + iRam020de830;
  *(short **)(param_1 + 0x7e) = param_1 + 2;
  plVar1 = (longlong *)func_020d22d0();
  lVar4 = Multiply64((int)plVar1[1],*(undefined4 *)((int)plVar1 + 0xc),(int)*plVar1,
                     *(undefined4 *)((int)plVar1 + 4));
  *plVar1 = lVar4 + plVar1[2];
  Multiply64(*(undefined4 *)((int)plVar1 + 4),0,uRam020de834,0);
  param_1[0x50] = extraout_r1;
  plVar1 = (longlong *)func_020d22d0();
  lVar4 = Multiply64((int)plVar1[1],*(undefined4 *)((int)plVar1 + 0xc),(int)*plVar1,
                     *(undefined4 *)((int)plVar1 + 4));
  *plVar1 = lVar4 + plVar1[2];
  Multiply64(*(undefined4 *)((int)plVar1 + 4),0,0x82,0);
  param_1[0x51] = extraout_r1_00;
  param_1[0x52] = 0x80;
  if (param_2 == (undefined4 *)0x0) {
    param_1[0x54] = 1;
    param_1[0x55] = 0;
    param_1[0x56] = 0;
    param_1[0x57] = 0;
    param_1[0x7c] = 1;
    param_1[0x7d] = 0;
    func_020d29cc((int)(uintptr_t)(param_1),uRam020de838);
  }
  else {
    if ((*param_1 == 0xc9) && (-1 < *(short *)((int)param_2 + 0x26))) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
    *(undefined4 *)(param_1 + 0x54) = uVar3;
    *(int *)(param_1 + 0x56) = (int)*(short *)(param_2 + 0xd);
    param_1[0x7c] = 0;
    param_1[0x7d] = 0;
  }
  if (*(int *)(param_1 + 0x7c) == 0) {
    param_1[0x79] = *(short *)((int)param_2 + 0x2a);
    param_1[0x7a] = *(short *)(param_2 + 0xb);
  }
  else {
    param_1[0x79] = 0;
    param_1[0x7a] = 0;
  }
  if (*(int *)(param_1 + 0x7c) == 0) {
    param_1[0x58] = *(short *)((int)param_2 + 0x2e);
    if (param_1[0x58] == 0) {
      local_20 = *param_2;
      local_1c = param_2[1];
      local_18 = param_2[2];
      if (*(int *)(param_1 + 0x54) != 0) {
        local_1c = local_1c + iRam020de83c;
      }
      iVar2 = func_020e516c((uint *)(void *)(param_1 + 0x5a),&local_20,uRam020de840,0xd);
      if (iVar2 == 0) {
        param_1[0x58] = 2;
      }
    }
  }
  else {
    param_1[0x58] = 1;
  }
  if ((param_2 != (undefined4 *)0x0) && (iVar2 = func_020e512c((undefined4)(uintptr_t)(param_2)), iVar2 != 0)) {
    param_1[1] = param_1[1] | *puRam020de844;
  }
  *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | *puRam020de848;
  return;
}

