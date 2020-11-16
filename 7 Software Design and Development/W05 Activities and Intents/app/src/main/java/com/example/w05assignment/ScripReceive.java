package com.example.w05assignment;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

public class ScripReceive extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_scrip_receive);
        Intent intent = getIntent();
        TextView tv = findViewById(R.id.fullScripture);
        String scripture = intent.getStringExtra("bookEntry") +
                ' ' + intent.getIntExtra("chapEntry", 1) +
                ':' + intent.getIntExtra("verseEntry", 1);
        Log.i("Received intent with ", scripture);
        tv.setText(scripture);
    }

    public void showToast(View view) {
        Toast.makeText(ScripReceive.this, "Scripture Saved", Toast.LENGTH_SHORT).show();
    }
}
