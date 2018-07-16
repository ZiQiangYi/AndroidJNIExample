//
// Created by Administrator on 2017/8/5.
//

#include <stdio.h>
#include <string.h>
#include <com_example_administrator_ndktest_MainActivity.h>
#include <jni.h>
#include <dlfcn.h>

void test()
{
        void *handle;
        double (*cosine)(double);
        char *error;

        handle = dlopen ("/lib/libm.so.6", RTLD_LAZY);
        if (!handle) {
            printf("dlopen error : %s", dlerror());
            return;
        }

        cosine = (double (*)(double))dlsym(handle, "cos");
        if (((error = (char *)dlerror()) != NULL) && (cosine == NULL)) {
            printf("dlopen error1 : %s", dlerror());
            return;
        }

        printf ("%f\n", (*cosine)(2.0));
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

JNIEXPORT jstring JNICALL Java_com_example_administrator_ndktest_MainActivity_getJNIString(JNIEnv *env, jobject obj)
{
    return env->NewStringUTF("Message from JniMain");
}

JNIEXPORT jstring JNICALL Java_com_example_administrator_ndktest_MainActivity_checkPassword(JNIEnv *env, jobject obj, jstring password)
{
    const char* szPassword = env->GetStringUTFChars(password, 0);
    int nRet = checkPassword(szPassword);
    env->ReleaseStringUTFChars(password, szPassword);
    if (nRet == 1)
    {
        return env->NewStringUTF("password is correct.");
    }
    return env->NewStringUTF("password is incorrect");
}