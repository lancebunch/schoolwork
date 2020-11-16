package com.example.weatherthread;

import com.google.gson.Gson;
import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.net.URLConnection;
import java.net.URLEncoder;
import java.util.Scanner;
import javax.net.ssl.HttpsURLConnection;
import java.io.BufferedReader;
import java.io.InputStreamReader;


public class APIConnect {
    public WeatherConditions temperature(String userCity) throws IOException {
        Gson g = new Gson();

        String baseurl = "https://api.openweathermap.org/data/2.5/weather";
        String charset = "UTF-8";
        String apiKey = "ebeda59035ed2c40737d4f5eca43ff37";
        String units = "imperial";

        String query = String.format("q=%s&units=%s&apiKey=%s",
                URLEncoder.encode(userCity, charset),
                URLEncoder.encode(units, charset),
                URLEncoder.encode(apiKey, charset));

        String url = baseurl + "?" + query;
        System.out.println(url);

        String data = loadJsonData(url);

        WeatherConditions weather = g.fromJson(data, WeatherConditions.class);

        System.out.println(weather);
        return weather;
    }

    public WeatherForecast forecast(String userCity) throws IOException {
            Gson g = new Gson();

            String baseurl = "https://api.openweathermap.org/data/2.5/forecast";
            String charset = "UTF-8";
            String apiKey = "ebeda59035ed2c40737d4f5eca43ff37";
            String units = "imperial";

            String query = String.format("q=%s&units=%s&apiKey=%s",
                    URLEncoder.encode(userCity, charset),
                    URLEncoder.encode(units, charset),
                    URLEncoder.encode(apiKey, charset));

            String url = baseurl + "?" + query;
            System.out.println(url);

            String data = loadJsonData(url);

            WeatherForecast forecast = g.fromJson(data, WeatherForecast.class);
            System.out.println(forecast);

            return forecast;
    }

    private String loadJsonData(String url) {
        StringBuilder data = new StringBuilder();
        try {
            URL urlObj = new URL(url);
            HttpsURLConnection connection = (HttpsURLConnection) urlObj.openConnection();
            BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));

            // Read all data from the website into a single string
            String line;
            do {
                line = reader.readLine();
                if (line != null) {
                  data.append(line);
                }
            }
            while (line != null);
        }
        catch (IOException ioe) {
               System.out.println(ioe.toString());
        }
         return data.toString();
    }
}
