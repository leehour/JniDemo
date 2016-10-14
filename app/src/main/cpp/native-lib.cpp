#include <jni.h>
#include <string>
#include <android/log.h>
#include "com_leehour_jnidemo2_JNI.h"

#define LOG_TAG "JNI"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
/*extern "C"{

JNIEXPORT jstring JNICALL
        Java_com_leehour_jnidemo2_JNI_encode(JNIEnv *env, jclass type, jstring s_);
JNIEXPORT jstring JNICALL
        Java_com_leehour_jnidemo2_JNI_decode(JNIEnv *env, jclass type, jstring s_);
}*/


JNIEXPORT jstring JNICALL
Java_com_leehour_jnidemo2_JNI_encode(JNIEnv *env, jclass type, jstring s_) {
    LOGI("encode start");
    const char *s = env->GetStringUTFChars(s_, 0);
    jsize length = env->GetStringLength(s_);
    char *s1;
    s1 = (char *) malloc(sizeof(char) * length);
    for (int i = 0; i < length; ++i) {
        *(s1 + i) = *(s + i) + 2;
    }

    env->ReleaseStringUTFChars(s_, s);

    return env->NewStringUTF(s1);
}

JNIEXPORT jstring JNICALL
Java_com_leehour_jnidemo2_JNI_decode(JNIEnv *env, jclass type, jstring s_) {
    LOGI("decode start");
    const char *s = env->GetStringUTFChars(s_, 0);
    jsize length = env->GetStringLength(s_);
    char *s1;
    s1 = (char *) malloc(sizeof(char) * length);
    for (int i = 0; i < length; ++i) {
        *(s1 + i) = *(s + i) - 2;
    }

    env->ReleaseStringUTFChars(s_, s);

    return env->NewStringUTF(s1);
}