/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define data_0217b680 SDK_data_0217b70c
#define data_0215818c SDK_data_02158628
#define Maybe_CreateObj_15818c Maybe_CreateObj_158628
typedef unsigned int u32;
typedef struct Obj2c { u32 w[11]; } Obj2c;
extern void *GetActiveExecutionContext(void);
extern void *ExecutionContext_GetHeapHandle(void *ctx);
extern void *Mem_AllocateHeap(void *heap, u32 size);
extern void func_020d49d8(void *arg);
extern Obj2c *data_0217b680;
extern const Obj2c data_0215818c;
void *Maybe_CreateObj_15818c(void) {
    void *ctx = GetActiveExecutionContext();
    void *heap = ExecutionContext_GetHeapHandle(ctx);
    Obj2c *obj = (Obj2c *)Mem_AllocateHeap(heap, 0x2c);
    data_0217b680 = obj;
    *obj = data_0215818c;
    func_020d49d8(&data_0217b680);
    return data_0217b680;
}
