//进程控制块
typedef struct PCB
{
	int id;
	char name[20];
	enum STATUS status;
	HANDLE hThis;
	unsigned int threadID;
	int count;
	struct PCB *next;
}PCB,*pPCB;
//就绪队列和缓存区队列
typedef struct
{
	pPCB head;
	pPCB tail;
	int pcbNum;
}readyList,freeList,*pList;
//待创建进程，记录进程参数
typedef struct apply
{
	char name[20];
	int time;
	struct apply *next;
}applyProcess,*applyList;
//待创建进程队列
typedef struct
{
	applyList head;
	applyList tail;
	int applyNum;
}applyQueue;

enum STATUS{RUN,READY,WAIT};
//并发线程数
const int PCB_LIMIT=10;

void init();
void createProcess(char* name,int ax);
void addApplyProcess(char* name,int time);
void createIfAnyApply();
void scheduleProcess();
void remove(pPCB removeTarget);
void removeProcess(char* name);
void fprintReadyList();
void printCurrent();
void stopAllThreads();