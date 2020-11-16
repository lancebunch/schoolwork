package bunch;

import com.google.gson.Gson;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.net.URLConnection;
import java.net.URLEncoder;
import java.util.Scanner;

public class APIConnect {
    public void option() throws IOException {
        String choice;
        do {
            System.out.println("Forecast or Weather? (Please type response exactly as seen)");
            Scanner cin = new Scanner(System.in);
            choice = cin.nextLine();
            if (!choice.equals("Forecast") && !choice.equals("Weather")) {
                System.out.println("Invalid option. Please choose 'Forecast' or 'Weather'.");
            }
        }
        while (!choice.equals("Forecast") && !choice.equals("Weather"));

        if (choice.equals("Weather")) {
            Gson g = new Gson();
            Scanner userCity = new Scanner(System.in);
            System.out.println("What City are you from?");
            String q = userCity.nextLine();

            String url = "https://api.openweathermap.org/data/2.5/weather";
            String charset = "UTF-8";
            String apiKey = "ebeda59035ed2c40737d4f5eca43ff37";
            String units = "imperial";
            String responseBody;

            String query = String.format("q=%s&units=%s&apiKey=%s",
                    URLEncoder.encode(q, charset),
                    URLEncoder.encode(units, charset),
                    URLEncoder.encode(apiKey, charset));

            URLConnection connection = new URL(url + "?" + query).openConnection();
            connection.setRequestProperty("Accept-charset", charset);
            InputStream response = connection.getInputStream();

            try (Scanner scanner = new Scanner(response)) {
                responseBody = scanner.useDelimiter("\\A").next();
            }

            WeatherConditions weather = g.fromJson(responseBody, WeatherConditions.class);

            System.out.println(weather);
        }
        else if (choice.equals("Forecast")) {

            Gson g = new Gson();
            Scanner location = new Scanner(System.in);
            System.out.println("Please enter your zip code");
            String zip = location.nextLine();


            String url = "https://api.openweathermap.org/data/2.5/forecast";
            String charset = "UTF-8";
            String apiKey = "ebeda59035ed2c40737d4f5eca43ff37";
            String units = "imperial";
            String responseBody;

            String query = String.format("zip=%s&units=%s&apiKey=%s",
                    URLEncoder.encode(zip, charset),
                    URLEncoder.encode(units, charset),
                    URLEncoder.encode(apiKey, charset));

            URLConnection connection = new URL(url + "?" + query).openConnection();
            connection.setRequestProperty("Accept-charset", charset);
            InputStream response = connection.getInputStream();

            try (Scanner scanner = new Scanner(response)) {
                responseBody = scanner.useDelimiter("\\A").next();
            }

            WeatherForecast forecast = g.fromJson(responseBody, WeatherForecast.class);

            String display = forecast.toString();
            display = display.substring(1, display.length() - 1);

            System.out.println(display);
        }
        else {
            System.out.println("I don't know how you got here, but needless to say I'm impressed...");
        }
    }
}
