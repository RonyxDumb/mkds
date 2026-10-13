/* Decompiled C draft; module arm9; ROM address 0212586c. No matching claim. */
#include "types.h"
#include "deps/0212586c_G2d_Text_SomeFn_2_from_thumb.h"

void G2d_Text_SomeFn_2_from_thumb
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_480;
  undefined1 *local_47c;
  undefined4 local_478;
  int local_474;
  undefined1 *local_470 [5];
  int local_45c [4];
  undefined1 auStack_44c [80];
  undefined1 auStack_3fc [1000];
  
  local_480 = *(undefined4 *)((int)local_470 + iRam021258e8 + 0x10);
  local_47c = auStack_3fc;
  local_478 = *(undefined4 *)((int)local_45c + iRam021258e8);
  local_474 = (int)*(char *)((int)&local_480 + iRam021258ec);
  G2d_Text_SomeFn_3_from_thumb(param_1,local_45c + 2,auStack_44c,local_45c + 3);
  local_480 = param_2;
  local_47c = (undefined1 *)param_3;
  local_478 = param_4;
  local_474 = *(undefined4 *)((int)local_470 + iRam021258e8);
  local_470[0] = *(undefined1 **)((int)local_470 + iRam021258e8 + 4);
  local_470[1] = (undefined1 *)*(undefined4 *)((int)local_470 + iRam021258e8 + 8);
  local_470[2] = (undefined1 *)*(undefined4 *)((int)local_470 + iRam021258e8 + 0xc);
  local_470[3] = auStack_3fc;
  local_470[4] = (undefined1 *)*(undefined4 *)((int)local_45c + iRam021258e8);
  local_45c[0] = (int)*(char *)((int)&local_480 + iRam021258ec);
  local_45c[1] = *(undefined4 *)((int)local_45c + iRam021258e8 + 8);
  G2d_Text_SomeFn_4_from_thumb(param_1,local_45c[2],auStack_44c,local_45c[3]);
  return;
}

