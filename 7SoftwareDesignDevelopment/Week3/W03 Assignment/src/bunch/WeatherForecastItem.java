package bunch;

import com.google.gson.annotations.SerializedName;

import java.util.List;
import java.util.Map;

public class WeatherForecastItem {
    private String dt_txt;
    @SerializedName("main")
    private Map<String, Float> measurements;
    private WeatherWind wind;
    private List<WeatherDescription> weather;

    @Override
    public String toString() {
        return dt_txt + ' ' +
               measurements.get("temp") + "°F " +
                wind + ' ' + weather + '\n';
    }
}
