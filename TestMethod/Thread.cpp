#include "Thread.h"
unsigned __stdcall thread_entry(void* pvparam) {
	Thread* target = (Thread*)(pvparam);
	return target->run();
}

Thread::Thread(unsigned int flags)
{
	this->thread_handle = (HANDLE)_beginthreadex(NULL, 0, thread_entry, (void*)this, flags, NULL);
}

void Thread::Resume()
{
	while(ResumeThread(this->thread_handle)<=0);
	
}

void Thread::Suspend()
{
	while (SuspendThread(this->thread_handle) <= 0);
}


