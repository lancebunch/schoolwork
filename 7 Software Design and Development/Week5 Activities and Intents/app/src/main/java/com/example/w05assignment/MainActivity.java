package com.example.w05assignment;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    String book;
    int chapter, verse;

    EditText bookEntry;
    EditText chapEntry;
    EditText verseEntry;

    Button displayScripture;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        bookEntry = findViewById(R.id.bookEntry);
        chapEntry = findViewById(R.id.chapterEntry);
        verseEntry = findViewById(R.id.verseEntry);

        displayScripture = findViewById(R.id.displayScripture);

    }

    public void displayScripture(View view) {
        book = bookEntry.getText().toString();
        chapter = Integer.valueOf(chapEntry.getText().toString());
        verse = Integer.valueOf(verseEntry.getText().toString());
        Log.i("Creating intent with ", book + ' ' + chapter + ':' + verse);
        Intent intent = new Intent(this, ScripReceive.class);
        intent.putExtra("bookEntry", book);
        intent.putExtra("chapEntry", chapter);
        intent.putExtra("verseEntry", verse);
        startActivity(intent);
    }
}
