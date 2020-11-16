package bunch;

import java.util.List;

public class WeatherForecast {
    private List<WeatherForecastItem> list;

    @Override
    public String toString() {
        return " Forecast:\n" + list;
    }
}
