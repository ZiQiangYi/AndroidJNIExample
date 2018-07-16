#include <jni.h>
#include <string>
#include <dlfcn.h>

extern "C" JNIEXPORT jstring

JNICALL
Java_com_example_user_myapplication_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

void test()
{
    void* handle;
    double (*cosine) (double);
    char *error;

    handle = dlopen("lib/libm.so.6", RTLD_LAZY);
    if(!handle) {
        printf("dlopen error: %s", dlerror());
        return;
    }

    cosine = (double (*)(double))dlsym(handle,"cos");

    if(((error = (char*) dlerror())!= NULL) && (cosine==NULL)){
        printf("dlopen error1: %s", dlerror());
    }

    printf("%f\n",(*cosine)(2.0));
    dlclose(handle);
}
int checkPassword(const char* password)
{
    test();

    if(strcmp(password, "newpassword"))
    {
        return 0;
    }

    return 1;
}

extern "C" JNIEXPORT jstring
JNICALL
Java_com_example_user_myapplication_MainActivity_checkPassword(
        JNIEnv* env,
        jobject,
        jstring password)
{
    const char* szPassword = env->GetStringUTFChars(password, 0);
    int nRet = checkPassword(szPassword);
    if(nRet == 1)
    {
        return env->NewStringUTF("password is correct.");
    }
    return env->NewStringUTF("password is incorrect");
}