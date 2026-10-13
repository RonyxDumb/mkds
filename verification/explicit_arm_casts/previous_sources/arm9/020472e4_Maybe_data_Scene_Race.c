/* Decompiled C draft; module arm9; ROM address 020472e4. No matching claim. */
#include "types.h"
#include "deps/020472e4_Maybe_data_Scene_Race.h"

void Maybe_data_Scene_Race(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined1 auStack_90 [132];
  
  func_0204f5e4();
  Mem_ResetFrameHeap(*(undefined4 *)(*piRam0204737c + iRam02047380),3);
  func_02047498(uRam02047384,2);
  Maybe_s_s(uRam02047388,3);
  if (param_2 == 3) {
    func_02047498(uRam0204738c,4);
    Maybe_s_s(uRam02047390,5);
  }
  else {
    func_02047498(uRam02047394,4);
    Maybe_s_s(uRam02047398,5);
  }
  piVar1 = piRam0204737c;
  *(int *)(*piRam0204737c + iRam0204739c) = param_2;
  Mem_ResetFrameHeap(*(undefined4 *)(*piVar1 + iRam020473a0),3);
  FormatCourseCarc_from_thumb(auStack_90,param_1,0);
  func_02047498(auStack_90,6);
  FormatCourseCarc_from_thumb(auStack_90,param_1,1);
  func_02047498(auStack_90,7);
  *(undefined4 *)(*piRam0204737c + iRam020473a4) = param_1;
  return;
}

