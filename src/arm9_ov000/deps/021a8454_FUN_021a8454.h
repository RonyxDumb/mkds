#pragma once
/* Function-specific inferred declarations. */
void FUN_021a7048(int param_1);
void FUN_021a8454(int param_1);


/* Address resolved to indexed definition; inferred ABI remains provisional. */
void Os_Thread_Join(int param_1);
#define func_0x0200e084 Os_Thread_Join
longlong Os_DisableIrq(void);
#define func_0x0200fca0 Os_DisableIrq
uint Os_DisableScheduler(void);
#define func_0x0200db9c Os_DisableScheduler
undefined4 Os_ReceiveMessage(int param_1,uint *param_2,uint param_3);
#define func_0x0200ea3c Os_ReceiveMessage
undefined4 Os_MessageQueue_Send(int param_1,undefined4 param_2,uint param_3);
#define func_0x0200eae8 Os_MessageQueue_Send
uint Os_EnableScheduler(void);
#define func_0x0200db64 Os_EnableScheduler
undefined4 Os_RestoreIrq(void);
#define func_0x0200fcb4 Os_RestoreIrq
void Os_RescheduleThread(void);
#define func_0x0200de50 Os_RescheduleThread
