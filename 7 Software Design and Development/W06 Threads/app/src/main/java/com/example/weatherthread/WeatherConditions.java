package com.example.weatherthread;

import com.google.gson.annotations.SerializedName;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class WeatherConditions {
    private int id;
    private String name;
    @SerializedName("main")
    private Map<String, Float> measurements;

    public WeatherConditions() {
        id = 0;
        name = null;
        measurements = new HashMap<>();
    }

    /**
     * Creates a new instance of the WeatherCondition class.
     * @param id The id of the information.
     * @param name The location of weather conditions.
     */
    public WeatherConditions(int id, String name) {
        this.id = id;
        this.name = name;
        this.measurements = new HashMap<>();
    }

    @Override
    public String toString() {
        return "WeatherConditions{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", main=" + measurements +
                '}';
    }

    public void addMain(String key, Float value) {
        measurements.put(key, value);
    }

    // These are my getters
    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public Map<String, Float> getMain() {
        return measurements;
    }

    // These are my setters
    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setMain(Map<String, Float> main) {
        this.measurements = main;
    }
}
