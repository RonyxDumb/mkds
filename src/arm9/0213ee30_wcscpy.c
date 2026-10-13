/* Decompiled C draft; module arm9; ROM address 0213ee30. No matching claim. */
#include "types.h"
#include "deps/0213ee30_wcscpy.h"

wchar_t * wcscpy(wchar_t *__dest,wchar_t *__src)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  
  pwVar2 = __dest;
  do {
    *(short *)pwVar2 = (short)*__src;
    wVar1 = *pwVar2;
    __src = (wchar_t *)((int)__src + 2);
    pwVar2 = (wchar_t *)((int)pwVar2 + 2);
  } while ((short)wVar1 != 0);
  return __dest;
}

