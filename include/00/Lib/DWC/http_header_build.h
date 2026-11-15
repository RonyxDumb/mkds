#pragma once

#include "types.h"

typedef struct Http Http;

BOOL DWC_Http_Add_Body(Http *http, const char *body);
BOOL DWC_Http_Add_PostBase64Item(Http *http, const char *name, const void *data, s32 dataSize);
BOOL DWC_Http_Add_HeaderItem(Http *http, const char *name, const char *value);
BOOL DWCi_Http_WriteBasicHeader(Http *http);
