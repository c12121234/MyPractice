pthread_mutex_t mtx;
pthread_mutexattr_t mtxAttr;
int s, type;
s = ptrhead_mutexattr_init(&mtxAttr);
if(s != 0)
{
    errExitEN(s,"pthread_mutexattr_init");
}

s = ptrhead_mutexattr_settype(&mtxAttr,PTHREAD_MUTEX_ERRORCHECK);
if(s != 0)
{
    errExitEN(s,"ptrhead_mutexattr_settype");
}

s = ptrhead_mutex_init(&mtx,&mtxAttr);
if(s != 0)
{
    errExitEN(s,"ptrhead_mutex_init");
}

s = ptrhead_mutexattr_destroy(&mtxAttr);
if(s != 0)
{
    errExitEN(s,"ptrhead_mutexattr_destroy");
}