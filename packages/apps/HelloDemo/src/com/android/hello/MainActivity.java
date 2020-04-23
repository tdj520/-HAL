package com.android.hello;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.os.IBinder;
import android.app.IHelloService;
import android.os.ServiceManager;
import android.os.RemoteException;
import android.view.Window;
import android.widget.Toast;
public class MainActivity extends Activity implements View.OnClickListener {
    private Button button;

    private EditText editText1;
    private EditText editText2;
    private EditText editText3;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.activity_main);
        button = findViewById(R.id.button);
        editText1 = findViewById(R.id.edit_text1);
        editText2 = findViewById(R.id.edit_text2);
        editText3 = findViewById(R.id.edit_text3);
        button.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        IHelloService helloService = getHelloService();
        if(helloService == null){
           Log.d("dongjiao","onClick...faile to get helloService...");
           return;
        }
        Log.d("dongjiao","onClick...success to get helloService...");
        int a = Integer.parseInt(editText1.getText().toString());
        int b = Integer.parseInt(editText2.getText().toString());
        try{
           int total = helloService.add(a,b);
           editText3.setText(total+"");
           Toast.makeText(this,"total = :"+total,Toast.LENGTH_LONG).show();
        }catch(RemoteException e){
             Log.d("dongjiao","RemoteException = :"+e);
        }
   }
   private IHelloService getHelloService(){
         IBinder b = ServiceManager.getService("helloService");
         IHelloService helloService = IHelloService.Stub.asInterface(b);
         return helloService;
   }
}

