#pragma once

#include "types.h"
#include "00/Lib/DWC/server_auth.h"
#include "00/Lib/DWC/network_check_status.h"
#include "00/Lib/DWC/auth_http_params.h"

extern struct Http *gNetcheckHttp;
extern struct DWCNetcheck *gNetcheck;
extern DWCHttpParam gHttpParam;
extern AuthCreateParams gAuthParam;
