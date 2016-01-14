// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SKY_ENGINE_BINDINGS_JNI_JNI_CLASS_H_
#define SKY_ENGINE_BINDINGS_JNI_JNI_CLASS_H_

#include <jni.h>

#include "base/android/jni_android.h"
#include "sky/engine/tonic/dart_wrappable.h"
#include "sky/engine/wtf/PassRefPtr.h"

namespace blink {

class JniObject;

// Wrapper that exposes a JNI jclass to Dart
class JniClass : public RefCounted<JniClass>, public DartWrappable {
  DEFINE_WRAPPERTYPEINFO();

 public:
  ~JniClass() override;

  static PassRefPtr<JniClass> FromName(const char* className);
  static PassRefPtr<JniClass> FromClassObject(const JniObject* classObject);

  intptr_t GetFieldId(const char* name, const char* sig);
  intptr_t GetStaticFieldId(const char* name, const char* sig);
  intptr_t GetMethodId(const char* name, const char* sig);
  intptr_t GetStaticMethodId(const char* name, const char* sig);

  PassRefPtr<JniObject> NewObject(jmethodID methodId,
                                  const Vector<Dart_Handle>& args);

  PassRefPtr<JniObject> GetStaticObjectField(jfieldID fieldId);
  bool GetStaticBooleanField(jfieldID fieldId);
  int64_t GetStaticByteField(jfieldID fieldId);
  int64_t GetStaticCharField(jfieldID fieldId);
  int64_t GetStaticShortField(jfieldID fieldId);
  int64_t GetStaticIntField(jfieldID fieldId);
  int64_t GetStaticLongField(jfieldID fieldId);
  double GetStaticFloatField(jfieldID fieldId);
  double GetStaticDoubleField(jfieldID fieldId);

  void SetStaticObjectField(jfieldID fieldId, const JniObject* value);
  void SetStaticBooleanField(jfieldID fieldId, bool value);
  void SetStaticByteField(jfieldID fieldId, int64_t value);
  void SetStaticCharField(jfieldID fieldId, int64_t value);
  void SetStaticShortField(jfieldID fieldId, int64_t value);
  void SetStaticIntField(jfieldID fieldId, int64_t value);
  void SetStaticLongField(jfieldID fieldId, int64_t value);
  void SetStaticFloatField(jfieldID fieldId, double value);
  void SetStaticDoubleField(jfieldID fieldId, double value);

  PassRefPtr<JniObject> CallStaticObjectMethod(jmethodID methodId,
                                               const Vector<Dart_Handle>& args);
  bool CallStaticBooleanMethod(jmethodID methodId,
                               const Vector<Dart_Handle>& args);
  int64_t CallStaticByteMethod(jmethodID methodId,
                               const Vector<Dart_Handle>& args);
  int64_t CallStaticCharMethod(jmethodID methodId,
                               const Vector<Dart_Handle>& args);
  int64_t CallStaticShortMethod(jmethodID methodId,
                                const Vector<Dart_Handle>& args);
  int64_t CallStaticIntMethod(jmethodID methodId,
                              const Vector<Dart_Handle>& args);
  int64_t CallStaticLongMethod(jmethodID methodId,
                               const Vector<Dart_Handle>& args);
  double CallStaticFloatMethod(jmethodID methodId,
                               const Vector<Dart_Handle>& args);
  double CallStaticDoubleMethod(jmethodID methodId,
                                const Vector<Dart_Handle>& args);
  void CallStaticVoidMethod(jmethodID methodId,
                            const Vector<Dart_Handle>& args);

 private:
  JniClass(JNIEnv* env, jclass clazz);

  base::android::ScopedJavaGlobalRef<jclass> clazz_;
};

} // namespace blink

#endif  // SKY_ENGINE_BINDINGS_JNI_JNI_CLASS_H_
