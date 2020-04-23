package com.android.server.am;
import android.app.IHelloService;
public class HelloService extends IHelloService.Stub {
    public HelloService(){
      android.util.Log.d("dongjiao","Start AIDL HelloService...");
      nativeInit();
    }
    @Override 
    public int add(int a, int b){
      android.util.Log.d("dongjiao","AIDL HelloService add()...");
      int total = nativeAdd(a,b);
      return total;
    }
    private static native void nativeInit();
    private static native int nativeAdd(int a,int b);
}
