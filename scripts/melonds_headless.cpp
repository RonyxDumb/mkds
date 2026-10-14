// SPDX-License-Identifier: GPL-3.0-or-later
// Local DS observation frontend for the pinned melonDS core.
// No GUI, network, microphone, camera, peripheral or save persistence.
#include "NDS.h"
#include "Args.h"
#include "Platform.h"
#include <cstdio>
#include <cstdarg>
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <fstream>
#include <vector>
#include <cstring>
#include <dlfcn.h>
#include <sstream>
#include <stdexcept>
#include <algorithm>

namespace melonDS::Platform {
struct FileHandle { FILE* file; };
std::string GetLocalFilePath(const std::string& p) { return p; }
FileHandle* OpenFile(const std::string& p,FileMode mode) {
 const char* m=(mode&Append)?((mode&Read)?"a+b":"ab"):(mode&Write)?((mode&Preserve)?"r+b":(mode&Read)?"w+b":"wb"):"rb";
 FILE* f=std::fopen(p.c_str(),m); return f?new FileHandle{f}:nullptr;
}
FileHandle* OpenLocalFile(const std::string& p,FileMode m) { return OpenFile(p,m); }
bool FileExists(const std::string& p) { FILE* f=fopen(p.c_str(),"rb");if(!f)return false;fclose(f);return true; }
bool LocalFileExists(const std::string& p) { return FileExists(p); }
bool CheckFileWritable(const std::string& p) { auto* f=OpenFile(p,Append);return f?CloseFile(f):false; }
bool CheckLocalFileWritable(const std::string& p) { return CheckFileWritable(p); }
bool CloseFile(FileHandle* f) { int r=fclose(f->file);delete f;return r==0; }
bool IsEndOfFile(FileHandle* f) { return feof(f->file); }
bool FileReadLine(char* s,int n,FileHandle* f) { return fgets(s,n,f->file)!=nullptr; }
u64 FilePosition(FileHandle* f) { return ftello(f->file); }
bool FileSeek(FileHandle* f,s64 o,FileSeekOrigin origin) { return fseeko(f->file,o,origin==FileSeekOrigin::Start?SEEK_SET:origin==FileSeekOrigin::End?SEEK_END:SEEK_CUR)==0; }
void FileRewind(FileHandle* f) { rewind(f->file); }
u64 FileRead(void* d,u64 s,u64 n,FileHandle* f) { return fread(d,s,n,f->file); }
bool FileFlush(FileHandle* f) { return fflush(f->file)==0; }
u64 FileWrite(const void* d,u64 s,u64 n,FileHandle* f) { return fwrite(d,s,n,f->file); }
u64 FileWriteFormatted(FileHandle* f,const char* fmt,...) { va_list a;va_start(a,fmt);int r=vfprintf(f->file,fmt,a);va_end(a);return r; }
u64 FileLength(FileHandle* f) { auto p=ftello(f->file);fseeko(f->file,0,SEEK_END);auto n=ftello(f->file);fseeko(f->file,p,SEEK_SET);return n; }
void SignalStop(StopReason r,void*) { fprintf(stderr,"STOP_REASON %d\n",int(r)); }
void Log(LogLevel,const char* fmt,...) { va_list a;va_start(a,fmt);vfprintf(stderr,fmt,a);va_end(a); }
struct Thread { std::thread thread; };
Thread* Thread_Create(std::function<void()> f) { return new Thread{std::thread(std::move(f))}; }
void Thread_Wait(Thread* t) { if(t->thread.joinable())t->thread.join(); }
void Thread_Free(Thread* t) { Thread_Wait(t);delete t; }
struct Semaphore { std::mutex mutex;std::condition_variable cv;int count=0; };
Semaphore* Semaphore_Create() { return new Semaphore; }
void Semaphore_Free(Semaphore* s) { delete s; }
void Semaphore_Reset(Semaphore* s) { std::lock_guard<std::mutex> lock(s->mutex);s->count=0; }
void Semaphore_Wait(Semaphore* s) { std::unique_lock<std::mutex> lock(s->mutex);s->cv.wait(lock,[&]{return s->count>0;});s->count--; }
bool Semaphore_TryWait(Semaphore* s,int ms) { std::unique_lock<std::mutex> lock(s->mutex);if(!s->cv.wait_for(lock,std::chrono::milliseconds(ms),[&]{return s->count>0;}))return false;s->count--;return true; }
void Semaphore_Post(Semaphore* s,int n) { std::lock_guard<std::mutex> lock(s->mutex);s->count+=n;s->cv.notify_all(); }
struct Mutex { std::mutex mutex; };
Mutex* Mutex_Create() { return new Mutex; }
void Mutex_Free(Mutex* m) { delete m; }
void Mutex_Lock(Mutex* m) { m->mutex.lock(); }
void Mutex_Unlock(Mutex* m) { m->mutex.unlock(); }
bool Mutex_TryLock(Mutex* m) { return m->mutex.try_lock(); }
void Sleep(u64 us) { std::this_thread::sleep_for(std::chrono::microseconds(us)); }
u64 GetUSCount() { return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count(); }
u64 GetMSCount() { return GetUSCount()/1000; }
void WriteNDSSave(const u8*,u32,u32,u32,void*) {}
void WriteGBASave(const u8*,u32,u32,u32,void*) {}
void WriteFirmware(const Firmware&,u32,u32,void*) {}
void WriteDateTime(int,int,int,int,int,int,void*) {}
void MP_Begin(void*) {} void MP_End(void*) {}
int MP_SendPacket(u8*,int,u64,void*) { return 0; }
int MP_RecvPacket(u8*,u64*,void*) { return 0; }
int MP_SendCmd(u8*,int,u64,void*) { return 0; }
int MP_SendReply(u8*,int,u64,u16,void*) { return 0; }
int MP_SendAck(u8*,int,u64,void*) { return 0; }
int MP_RecvHostPacket(u8*,u64*,void*) { return 0; }
u16 MP_RecvReplies(u8*,u64,u16,void*) { return 0; }
int Net_SendPacket(u8*,int,void*) { return 0; }
int Net_RecvPacket(u8*,void*) { return 0; }
void Camera_Start(int,void*) {} void Camera_Stop(int,void*) {}
void Camera_CaptureFrame(int,u32* f,int w,int h,bool,void*) { memset(f,0,w*h*sizeof(u32)); }
void Mic_Start(void*) {} void Mic_Stop(void*) {}
int Mic_ReadInput(s16* d,int n,void*) { memset(d,0,n*sizeof(s16));return n; }
AACDecoder* AAC_Init() { return nullptr; }
void AAC_DeInit(AACDecoder*) {}
bool AAC_Configure(AACDecoder*,int,int) { return false; }
bool AAC_DecodeFrame(AACDecoder*,const void*,int,void*,int) { return false; }
bool Addon_KeyDown(KeyType,void*) { return false; }
void Addon_RumbleStart(u32,void*) {} void Addon_RumbleStop(void*) {}
float Addon_MotionQuery(MotionQueryType,void*) { return 0; }
struct DynamicLibrary { void* handle; };
DynamicLibrary* DynamicLibrary_Load(const char* p) { auto* h=dlopen(p,RTLD_LAZY);return h?new DynamicLibrary{h}:nullptr; }
void DynamicLibrary_Unload(DynamicLibrary* d) { dlclose(d->handle);delete d; }
void* DynamicLibrary_LoadFunction(DynamicLibrary* d,const char* p) { return dlsym(d->handle,p); }
}

struct InputEvent { int first,last; unsigned keys; int x,y; };
static std::vector<InputEvent> LoadInputs(const std::string& path,int frames) {
 std::ifstream stream(path);if(!stream)throw std::runtime_error("Cannot open input timeline");
 std::vector<InputEvent> events;std::string line;int previous=-1;
 while(std::getline(stream,line)) {
  if(line.empty() || line[0]=='#')continue;
  std::istringstream row(line);InputEvent e;std::string extra;
  if(!(row>>e.first>>e.last>>e.keys>>e.x>>e.y) || row>>extra || e.first<0 || e.last<=e.first || e.last>frames || e.first<previous || e.keys>4095 || !((e.x==-1 && e.y==-1)||(e.x>=0 && e.x<256 && e.y>=0 && e.y<192)))throw std::runtime_error("Invalid/overlapping input timeline");
  previous=e.last;events.push_back(e);
 }
 return events;
}
static void Capture(melonDS::NDS& nds,const std::string& prefix) {
 void *top=nullptr,*bottom=nullptr;
 if(nds.GPU.GetFramebuffers(&top,&bottom) && top && bottom) {
  for(auto item:{std::make_pair("-top.rgba",top),std::make_pair("-bottom.rgba",bottom)}) {
   std::ofstream out(prefix+item.first,std::ios::binary);out.write(static_cast<char*>(item.second),256*192*4);
   if(!out)throw std::runtime_error("Cannot write framebuffer");
  }
 }
}
int main(int argc,char** argv) {
 try {
 if(argc<3) { fprintf(stderr,"usage: melonds-headless ROM frames [output-prefix] [--gdb] [--inputs timeline.tsv] [--capture-every frames]\n");return 2; }
 int frames=std::stoi(argv[2]);if(frames<1 || frames>36000)return 2;
 bool gdb=false;int captureEvery=0;std::string prefix,inputPath;
 for(int i=3;i<argc;i++) {
  std::string option=argv[i];
  if(option=="--gdb")gdb=true;
  else if(option=="--inputs" && i+1<argc)inputPath=argv[++i];
  else if(option=="--capture-every" && i+1<argc) {captureEvery=std::stoi(argv[++i]);if(captureEvery<1)return 2;}
  else if(prefix.empty() && option.rfind("--",0)!=0)prefix=option;
  else return 2;
 }
 if(captureEvery && prefix.empty())return 2;
 auto events=inputPath.empty()?std::vector<InputEvent>{}:LoadInputs(inputPath,frames);size_t eventIndex=0;
 std::ifstream input(argv[1],std::ios::binary);if(!input)return 2;
 std::vector<melonDS::u8> rom((std::istreambuf_iterator<char>(input)),{});
 auto cart=melonDS::NDSCart::ParseROM(rom.data(),rom.size());if(!cart)return 3;
 melonDS::NDSArgs args;args.JIT=std::nullopt;
 if(gdb)args.GDB=melonDS::GDBArgs{3334,3333,true,true};
 auto nds=std::make_unique<melonDS::NDS>(std::move(args));
 nds->SetNDSCart(std::move(cart));nds->Reset();nds->SetupDirectBoot("AMCP.nds");nds->Start();
 nds->RTC.SetDateTime(2026,1,1,0,0,0);
 for(int frame=0;frame<frames && nds->IsRunning();frame++) {
  while(eventIndex<events.size() && events[eventIndex].last<=frame)eventIndex++;
  unsigned keys=0;int x=-1,y=-1;
  if(eventIndex<events.size() && events[eventIndex].first<=frame) {auto e=events[eventIndex];keys=e.keys;x=e.x;y=e.y;}
  nds->SetKeyMask(0xFFF ^ keys);
  if(x>=0)nds->TouchScreen(x,y);else nds->ReleaseScreen();
  nds->RunFrame();
  if(captureEvery && (frame+1)%captureEvery==0)Capture(*nds,prefix+"-"+std::to_string(frame+1));
  if(frame%60==0 || frame==frames-1) {
   printf("{\"frame\":%d,\"arm9_pc\":%u,\"arm7_pc\":%u,\"arm9_cpsr\":%u,\"arm7_cpsr\":%u}\n",frame+1,nds->ARM9.R[15],nds->ARM7.R[15],nds->ARM9.CPSR,nds->ARM7.CPSR);fflush(stdout);
   // Read only main RAM pointers; these are observations, not breakpoint hits.
   auto ram=[](unsigned a,unsigned n) {return a>=0x02000000 && a<=0x02400000-n;};
   unsigned state=nds->ARM9Read32(0x021759C0),places=nds->ARM9Read32(0x0217561C);
   if(ram(state,0x65)) {
    printf("{\"frame\":%d,\"state_ptr\":%u,\"mode_raw\":%u,\"lap_override_raw\":%u,\"places_ptr\":%u",frame+1,state,nds->ARM9Read32(state+8),nds->ARM9Read8(state+0x64),places);
    if(ram(places,8*0x8C)) {
     printf(",\"place_fields_raw\":[");for(int i=0;i<8;i++)printf("%s%u",i?",":"",nds->ARM9Read16(places+i*0x8C+0x50));printf("]");
    }
    unsigned owner=nds->ARM9Read32(0x02175620);
    if(ram(owner,0x1C)) {
     unsigned settings=nds->ARM9Read32(owner+0x18);
     if(ram(settings,4))printf(",\"lap_settings_raw\":%u",nds->ARM9Read16(settings+2));
    }
    printf("}\n");fflush(stdout);
   }
  }
 }
 if(!prefix.empty())Capture(*nds,prefix);
 return nds->IsRunning()?0:4;
 }catch(const std::exception& e) {fprintf(stderr,"%s\n",e.what());return 2;}
}
