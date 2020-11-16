package com.example.weatherthread;

import androidx.appcompat.app.AppCompatActivity;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Toast;

import java.io.IOException;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    /* Declaring variables for use */
    private String city;
    private EditText cityEntry;
    private ListView finalForecast;

    private ArrayAdapter<WeatherForecastItem> adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        finalForecast = findViewById(R.id.listView);
        cityEntry = findViewById(R.id.editText);
    }

    /* This onClick function is used to simply get the temperature of the city that
    * the user inputs in the EditText box
    * */
    public void getTemp(View view) {
        city = cityEntry.getText().toString();
        // Error handling if they try to submit nothing as their city
        if (city.length() <= 0) {
            Log.e("Submitting Entry: ", "No city specified");
            cityEntry.setError("No city specified");
        }
        else {
            // declaration of AsyncTask class created below
            AsyncTaskTemp thread = new AsyncTaskTemp(MainActivity.this);

            // execute the AsyncTask Thread passing in the infoType the user is requesting
            // and the city they wish to receive information on
            thread.execute(city);

            // This will later be implemented to display the temperature that is received from the thread
//            Toast.makeText(MainActivity.this, "Toast Test", Toast.LENGTH_SHORT).show();
        }
    }

    /* This onClick function is used to get the forecast of the city that
     * the user inputs in the EditText box
     * */
    public void getForecast(View view) {
        city = cityEntry.getText().toString();

        // More error checking
        if (city.length() <= 0) {
            Log.e("Submitting Entry: ", "No city specified");
            cityEntry.setError("No city specified");
        }
        else {
            // Declare the AsyncTask variable and begin the thread with the information the user wants
            AsyncTaskForecast thread = new AsyncTaskForecast(MainActivity.this);
            thread.execute(city);
        }
    }

    /* Declaration of my overriden AsyncTask thread to run tasks on a thread but still be able to
     * inform the UI what is going on.
     * */
    private static class AsyncTaskTemp extends AsyncTask<String, String, String> {
        private String resp;
        private MainActivity main;

        private AsyncTaskTemp(MainActivity main) {
            this.main = main;
        }

        @Override
        protected String doInBackground(String... params) {
            // Determines what function we are going to call from our APIConnect class
            APIConnect getInfo = new APIConnect();
            try {
                WeatherConditions weather = getInfo.temperature(params[0]);
                resp = "Feels like: " + weather.getMain().get("feels_like").toString();
            }
            catch (IOException ex) {
                System.out.println("Mission Failed, we'll get 'em next time");
                resp = "Failed to retrieve data";
            }
            return resp;
        }

        // Going to use this to set a member variable to the gson data that is retrieved and needed
        @Override
        protected void onPostExecute(String resp) {
            Toast.makeText(main, resp, Toast.LENGTH_SHORT).show();
        }
    }

    private class AsyncTaskForecast extends AsyncTask<String, String, List<WeatherForecastItem>> {
        private List<WeatherForecastItem> resp;
        private MainActivity main;

        private AsyncTaskForecast(MainActivity main) {
            this.main = main;
        }

        @Override
        protected List<WeatherForecastItem> doInBackground(String... params) {
            APIConnect getInfo = new APIConnect();
                try {
                    WeatherForecast forecast;
                    forecast = getInfo.forecast(params[0]);
                    resp = forecast.getList();
                }
                catch (IOException ex) {
                    WeatherForecastItem failMessage = new WeatherForecastItem();
                    failMessage.setDt_txt("Failed to retrieve data");
                    System.out.println("Mission Failed, we'll get 'em next time");
                    resp.set(0, failMessage);
                }
            return resp;
        }

        @Override
        protected void onPostExecute(List<WeatherForecastItem> resp) {
            adapter = new ArrayAdapter<>(main, android.R.layout.simple_list_item_1, resp);
            finalForecast.setAdapter(adapter);
        }
    }
}


