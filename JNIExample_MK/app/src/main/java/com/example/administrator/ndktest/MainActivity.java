package com.example.administrator.ndktest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("jniMain");
        System.loadLibrary("dl");
    }

    public native String getJNIString();

    public native String checkPassword(String strPassword);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final TextView jniText = (TextView)findViewById(R.id.textView);
        jniText.setText(getJNIString());

        final EditText editText = (EditText)findViewById(R.id.edt_password);

        Button btnCheck = (Button)findViewById(R.id.btn_check);
        btnCheck.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String strPassword = editText.getText().toString();
                String strReturn = checkPassword(strPassword);
                jniText.setText(strReturn);
            }
        });
    }
}
