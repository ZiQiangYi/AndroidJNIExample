# AndroidJNIExample
An example program of Android JNI

Android studio Setting
1. Open [File]/[Settings...].

2. Tools/External Tools Click + button.
   1)javah
     Name:javah 
     Description:javah
     Program:C:\Program Files\Java\jdk1.8.0_171\bin\javah.exe
     Arguments:-v -jni -d $ModuleFileDir$/src/main/jni $FileClass$
     Working directory:$SourcepathEntry$
   2)ndk-build
     Name:ndk-build
     Description: ndk build
     Program:D:\ndk\android-ndk-r17b\ndk-build.cmd
     WorkingDirectory:D:\Ndktest\app\src\main\libs

3.[File]/[Project Structure...]
  Android NDK location:  D:\ndk\android-ndk-r17b
