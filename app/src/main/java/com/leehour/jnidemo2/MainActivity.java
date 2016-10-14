package com.leehour.jnidemo2;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private EditText et_name;
    private String s1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        et_name = (EditText) findViewById(R.id.et_name);
    }

    public void encode(View view) {
        String s = et_name.getText().toString().trim();
        if (s != null) {
            s = JNI.encode(s);
            Log.i("TAG", s);
             et_name.setText(s);
        }
    }

    public void decode(View view) {
      String  s = et_name.getText().toString().trim();
        if(s!=null) {
            s = JNI.decode(s);
            Log.i("TAG", s);
            et_name.setText(s);
        }
    }

}
