/* Decompiled C draft; module arm9_ov000; ROM address 0218dbf8. No matching claim. */
#include "types.h"
#include "deps/0218dbf8_FUN_0218dbf8.h"

int FUN_0218dbf8(int *param_1,int param_2)

{
  if ((param_2 < 0) || (*param_1 <= param_2)) {
    func_0x0213442c(DAT_0218dc3c,DAT_0218dc40,0,0x94);
  }
  if ((-1 < param_2) && (param_2 < *param_1)) {
    return param_1[5] + param_2 * param_1[2];
  }
  return 0;
}

