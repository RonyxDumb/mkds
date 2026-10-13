/* Decompiled C draft; module arm9_ov003; ROM address 021c3758. No matching claim. */
#include "types.h"
#include "deps/021c3758_FUN_021c3758.h"

void FUN_021c3758(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined1 local_6c;
  undefined1 local_6b;
  undefined1 local_6a;
  undefined1 local_69;
  undefined1 local_68;
  undefined1 local_67;
  int local_64;
  int local_60;
  undefined4 local_50 [4];
  undefined1 auStack_40 [44];
  
  uVar1 = FUN_021d2288(0,0);
  func_0x0200fe58(&local_6c);
  func_0x0213ca64(auStack_40,0x14,DAT_021c386c,local_6c,local_6b,local_6a,local_69,local_68,local_67
                 );
  FUN_021d2070(uVar1,*DAT_021c3870,DAT_021c3870[1],DAT_021c3870[2],DAT_021c3870[3],2,DAT_021c3874,
               auStack_40);
  func_0x02151910(&local_64);
  if (local_60 == 0 && local_64 == 0) {
    func_0x0213ca64(auStack_40,0x14,DAT_021c3884);
  }
  else {
    uVar5 = func_0x02132e4c(local_64,local_60,10,0);
    local_50[3] = func_0x02133048((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),DAT_021c3878,0);
    uVar5 = func_0x02132e40(local_64,local_60,10,0);
    iVar3 = 0;
    do {
      uVar4 = (undefined4)((ulonglong)uVar5 >> 0x20);
      uVar2 = func_0x02132e4c((int)uVar5,uVar4,DAT_021c387c,0);
      local_50[2 - iVar3] = uVar2;
      uVar5 = func_0x02132e40((int)uVar5,uVar4,DAT_021c387c,0);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
    func_0x0213ca64(auStack_40,0x14,DAT_021c3880,local_50[0],local_50[1],local_50[2],local_50[3]);
  }
  FUN_021d2070(uVar1,*DAT_021c3888,DAT_021c3888[1],DAT_021c3888[2],DAT_021c3888[3],2,DAT_021c3874,
               auStack_40);
  FUN_021d1fd0(uVar1);
  return;
}

