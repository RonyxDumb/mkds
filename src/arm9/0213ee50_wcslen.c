/* Decompiled C draft; module arm9; ROM address 0213ee50. No matching claim. */
#include "types.h"
#include "deps/0213ee50_wcslen.h"

size_t wcslen(wchar_t *__s)

{
  wchar_t wVar1;
  size_t sVar2;
  
  sVar2 = 0xffffffff;
  do {
    wVar1 = *__s;
    sVar2 = sVar2 + 1;
    __s = (wchar_t *)((int)__s + 2);
  } while ((short)wVar1 != 0);
  return sVar2;
}

