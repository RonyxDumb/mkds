/* Decompiled C draft; module arm9; ROM address 020aba9c. No matching claim. */
#include "types.h"
#include "deps/020aba9c_func_020aba9c.h"

void func_020aba9c(void)

{
  Arm_FlushRange(*(undefined4 *)(*piRam020abadc + 4),*(undefined4 *)(*piRam020abadc + 0xc));
  TEQSub_Fn26Impl_Fn28Impl
            (*(undefined4 *)(*piRam020abadc + 4),0,*(undefined4 *)(*piRam020abadc + 0xc));
  Arm_FlushRange(*(undefined4 *)*piRam020abadc,((undefined4 *)*piRam020abadc)[2]);
  CopyBgData_Bg2_Bottom(*(undefined4 *)*piRam020abadc,0,((undefined4 *)*piRam020abadc)[2]);
  return;
}

