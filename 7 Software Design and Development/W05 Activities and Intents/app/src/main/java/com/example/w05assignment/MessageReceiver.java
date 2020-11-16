package com.example.w05assignment;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class MessageReceiver extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_message_receiver);
//        Intent intent = getIntent();
//        TextView tv = findViewById(R.id.received_Message);
//        tv.setText(intent.getStringExtra("message"));
    }
}
