/* Decompiled C draft; module arm9_ov001; ROM address 021885d4. No matching claim. */
#include "types.h"
#include "deps/021885d4_FUN_021885d4.h"

void FUN_021885d4(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  *(undefined4 *)(param_1 + DAT_02188618) = 0;
  if ((*(ushort *)(param_1 + 2) & DAT_0218861c) != 0) {
    param_2 = -param_2;
  }
  *(int *)(param_1 + DAT_02188620) = param_2;
  *(undefined4 *)(param_1 + DAT_02188624) = param_3;
  *(undefined4 *)(param_1 + DAT_02188628) = param_4;
  *(undefined4 *)(param_1 + DAT_0218862c) = param_5;
  *(undefined4 *)(param_1 + DAT_02188630) = param_6;
  *(undefined4 *)(param_1 + DAT_02188638) = DAT_02188634;
  *(undefined4 *)(param_1 + DAT_0218863c) = param_8;
  *(undefined4 *)(param_1 + DAT_02188640) = param_9;
  return;
}

