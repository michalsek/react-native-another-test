#include <jni.h>
#include "react-native-another-test.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_anothertest_AnotherTestModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return anothertest::multiply(a, b);
}
