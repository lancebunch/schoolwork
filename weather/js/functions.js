/********************************
 * Weather Site JavaScript Functions
 *******************************/
console.log('My functions.js is being read.');

// variables for function use
let date = new Date();
let nextHour = date.getHours() + 1;
var storage = window.localStorage;


var idHeader = {
   headers: {
      "User-Agent": "Student Learning Project - bun15009@byui.edu"
   }
};

/*********************************************************
 * Function :: buildWC
 * Mathmatetically determines the wind speed
 *********************************************************/
function buildWC(speed, temp) {
   // Declare feelTemp and assign it to the 'feelsLike' location
   let feelsLike = document.getElementById('feelsLike');

   // Math to determine what the wc is
   let wc = 35.74 + 0.6215 * temp - 35.75 * Math.pow(speed, 0.16) + 0.4275 * temp * Math.pow(speed, 0.16);
   console.log(wc);

   // Round to the nearest integer
   wc = Math.floor(wc);

   // if chill is greater than temp, return temp otherwise return wc
   wc = (wc > temp) ? temp : wc;

   // display windchill to console
   console.log(wc);

   // displays the wc
   feelsLike.innerHTML = wc;
} // buildWC Function

/*********************************************************
 * Function :: windDial
 * Rotates the wind dial to visual display the widn direction
 *********************************************************/
function windDial(direction) {
   // linking the dial and wd variables with the HTML location
   let dial = document.getElementById("dial");
   let wd = document.getElementById("wd");

   // switch statement to determine where to point the dial
   // Also handles displaying the direction in text
   switch (direction) {
      case "N":
         dial.setAttribute("class", "n");
         console.log(direction);
         wd.innerHTML = direction;
         break;
      case "NE":
      case "NNE":
      case "ENE":
         dial.setAttribute("class", "ne");
         console.log(direction);
         wd.innerHTML = direction;
         break;
      case "NW":
      case "NNW":
      case "WNW":
         dial.setAttribute("class", "nw");
         console.log(direction);
         wd.innerHTML = direction;
         break;
      case "South":
      case "S":
         dial.setAttribute("class", "s");
         console.log(direction);
         wd.innerHTML = direction;
         break;
      case "SE":
      case "SSE":
      case "ESE":
         dial.setAttribute("class", "se");
         console.log(direction);
         wd.innerHTML = direction;
         break;
      case "SW":
      case "SSW":
      case "WSW":
         dial.setAttribute("class", "sw");
         console.log(direction);
         wd.innerHTML = direction;
         break;
      case "East":
      case "E":
         dial.setAttribute("Class", "e");
         console.log(direction);
         wd.innerHTML = direction;
         break;
      case "West":
      case "W":
         dial.setAttribute("class", "w");
         console.log(direction);
         wd.innerHTML = diretion;
         break;
   }
} // windDial Function

/*********************************************************
 * Function :: getCondition
 * Takes a variety of possible phrases to determine conditions
 *********************************************************/
function getCondition(condition) {
   // creates a new variable assignin gin the lowercase version of the parameter for testing
   let lowerCondition = condition.toLowerCase()

   // if/else if statement to determine what type of weather to return
   if (lowerCondition.includes("clear") || lowerCondition.includes("sunny") || lowerCondition.includes("warm")) {
      console.log("Clear");
      return "Clear";
   } else if (lowerCondition.includes("overcast") || lowerCondition.includes("clouds") || lowerCondition.includes("cloudy")) {
      console.log("Clouds");
      return "Clouds";
   } else if (lowerCondition.includes("fog") || lowerCondition.includes("low visibility")) {
      console.log("Fog");
      return "Fog";
   } else if (lowerCondition.includes("drizzle") || lowerCondition.includes("rain") || lowerCondition.includes("storms")) {
      console.log("Rain");
      return "Rain";
   } else if (lowerCondition.includes("flurries") || lowerCondition.includes("snow") || lowerCondition.includes("blizzards")) {
      console.log("Snow");
      return "Snow";
   }
} // getCondition Function

/*********************************************************
 * Function :: changeSummaryImage
 * uses a switch statement to change the visual conditions
 *********************************************************/
function changeSummaryImage(currentCondition) {

   // to change the diferences of the summary tile
   let conditionVisual = document.getElementById("conditionVisual");

   // to change the differences of the formated tiles
   let forecast = document.getElementById("tileFormat");

   // to change the statement in the summary tile
   let statement = document.getElementById("currentCondition");

   switch (currentCondition) {
      case "Clear":
         conditionVisual.setAttribute("src", "img/weather-site-images/clear-250-o.jpg");
         conditionVisual.setAttribute("alt", "It is clear outside");
         forecast.setAttribute("class", "Clear");
         statement.innerHTML = "Clear";
         break;
      case "Clouds":
         conditionVisual.setAttribute("src", "img/weather-site-images/clouds-300-o.jpg");
         conditionVisual.setAttribute("alt", "There are clouds outside");
         forecast.setAttribute("class", "Clouds");
         statement.innerHTML = "Clouds";
         break;
      case "Fog":
         conditionVisual.setAttribute("src", "img/weather-site-images/fog-260-o.jpg");
         conditionVisual.setAttribute("alt", "It is foggy outside");
         forecast.setAttribute("class", "Fog");
         statement.innerHTML = "Fog";
         break;
      case "Rain":
         conditionVisual.setAttribute("src", "img/weather-site-images/rain-275-o.jpg");
         conditionVisual.setAttribute("alt", "It is raining outside");
         forecast.setAttribute("class", "Rain");
         statement.innerHTML = "Rain";
         break;
      case "Snow":
         conditionVisual.setAttribute("src", "img/weather-site-images/snow-563h-o.jpg");
         conditionVisual.setAttribute("alt", "It is snowing outside");
         forecast.setAttribute("class", "Snow");
         statement.innerHTML = "Snow";
         break;
   }
} // changeSummaryImage Function

/*********************************************************
 * Function :: convertMeters
 * converts meters to feet
 *********************************************************/
function convertMeters(meters) {
   let elevation = document.getElementById("elevation");

   let ft = meters * 3.28084;

   console.log(ft);

   ft = Math.floor(ft);

   console.log(ft);

   elevation.innerHTML = ft + " ft";
} // convertMeters Function

/*********************************************************
 * Function :: format_time
 * used in tandum with buildHourlyData
 *********************************************************/
function format_time(hour) {
   if (hour > 23) {
      hour -= 24;
   }
   let amPM = (hour > 11) ? "pm" : "am";
   if (hour > 12) {
      hour -= 12;
   }
   if (hour == 0) {
      hour = "12";
   }
   return hour + amPM;
} // format_time Function

/*********************************************************
 * Function :: buildHourlyData
 * builds the HTML to late display the hourly forecast tile
 *********************************************************/
function buildHourlyData(nextHour, hourlyTemps) {
   let hourlyListItems = '<li>' + format_time(nextHour) + ': ' + hourlyTemps[0] + '&deg;F |</li>';

   for (let i = 1, x = hourlyTemps.length; i < x; i++) {
      hourlyListItems += '<li>' + format_time(nextHour + i) + ': ' + hourlyTemps[i] + '&deg;F |</li>';
   }

   return hourlyListItems;
} // buildHourlyData Function

/*********************************************************
 * Function :: getLocation
 * gets location (if allowed) o whoever is making request
 *********************************************************/
function getLocation(locale) {
   const URL = "https://api.weather.gov/points/" + locale;
   // NWS User-Agent header (built above) will be the second parameter 
   fetch(URL, idHeader)
      .then(function (response) {
         if (response.ok) {
            return response.json();
         }
         throw new ERROR('Response not OK.');
      })
      .then(function (data) {
         // Let's see what we got back
         console.log('Json object from getLocation function:');
         console.log(data);
         // Store data to localstorage 
         storage.setItem("locName", data.properties.relativeLocation.properties.city);
         storage.setItem("locState", data.properties.relativeLocation.properties.state);

         // Next, get the weather station ID before requesting current conditions 
         // URL for station list is in the data object 
         let stationsURL = data.properties.observationStations;
         // Call the function to get the list of weather stations
         getStationId(stationsURL);

         // Get the URL to the hourly forecast and pass into 
         // the getHourly function
         let hourlyForecast = data.properties.forecastHourly;
         getHourly(hourlyForecast);

         // Get the URL to the high and low temp forecast for day
         let highLow = data.properties.forecast;
         getHighLow(highLow);
      })
      .catch(error => console.log('There was a getLocation error: ', error))
} // end getLocation function

/*********************************************************
 * Function :: getStationId
 * Gets local areas stationId to fetch appropriate weather data
 *********************************************************/
function getStationId(stationsURL) {
   // NWS User-Agent header (built above will be the second parameter
   fetch(stationsURL, idHeader)
      .then(function (response) {
         if (response.ok) {
            return response.json();
         }
         throw new ERROR('Response not OK.');
      })
      .then(function (data) {
         // Let's see what we got back
         console.log('From getStationId function:');
         console.log(data);

         // Store station ID and elevation(in meters - will need to be converted to feet)
         let stationId = data.features[0].properties.stationIdentifier;
         let stationElevation = data.features[0].properties.elevation.value;
         console.log('Station and Elevation are: ' + stationId, stationElevation);

         // Store data to localstorage
         storage.setItem("stationId", stationId);
         storage.setItem("stationElevation", stationElevation);

         // Request the CurrentWeather for this station
         getWeather(stationId);
      })
      .catch(error => console.log('There was a getStationId error: ', error))
} // getStationId Function

/************************************************************
 * Function :: getWeather
 * gets all of the information and stores it locally
 ************************************************************/
function getWeather(stationId) {
   // This is the URL for current observation data
   const URL = 'https://api.weather.gov/stations/' + stationId + '/observations/latest';
   // NWS User-Agent header (build above) will be the second parameter
   fetch(URL, idHeader)
      .then(function (response) {
         if (response.ok) {
            return response.json();
         }
         throw new ERROR('Response not OK.');
      })
      .then(function (data) {
         // Let's see what we got back
         console.log('From getWeather function:');
         console.log(data);

         // Store weather information to localStorage
         storage.setItem("locTemp", data.properties.temperature.value);
         storage.setItem("locWind", data.properties.windSpeed.value);

         // Build the page for viewing

      })
      .catch(error => console.log('There was a getWeather error: ', error))
   buildPage();
} // end getWeather function

/************************************************************
 * Function :: getHourly
 * gets next 13 hour temp forecast and stores it locally
 *    Also gets the wind direction for ease of other functions
 ************************************************************/
function getHourly(URL) {
   // fetch the URL and make sure it returns the right response
   fetch(URL, idHeader)
      .then(function (response) {
         if (response.ok) {
            return response.json();
         }
         throw new ERROR('Response not OK.');
      })
      .then(function (data) {
         // make sure is got the right URL
         console.log('Json object from getHourly function:');
         console.log(data);

         // Creating an array to hold 13 hours worth of temp
         // forecasts in degrees F
         let hourly = [];
         for (let i = 0; i < 13; i++) {
            hourly[i] = data.properties.periods[i].temperature;
         }
         console.log(hourly);
         // use buildHourlyData to get ready to build the page
         let hourlyTemps = buildHourlyData(nextHour, hourly);
         // Store it locally
         storage.setItem("hourly", hourlyTemps);
         storage.setItem("windDirection", data.properties.periods[0].windDirection);
         // Writes the Hourly temps to HTML
         let contentHourly = document.getElementById('averageHF');
         contentHourly.innerHTML = buildHourlyData(nextHour, hourly);

      })
      .catch(error => console.log('There was a getHourly error: ', error))
} // getHourly Function

/************************************************************
 * Function :: getHighLow
 * Locates the high and low of today's forecast
 ************************************************************/
function getHighLow(URL) {
   fetch(URL, idHeader)
      .then(function (response) {
         if (response.ok) {
            return response.json();
         }
         throw new ERROR('Response not OK.');
      })
      .then(function (data) {
         // Let's see what we got back
         console.log('Json object from getHighLow function:');
         console.log(data);

         // store the local high, local low, current summary,
         // and detailed forecast locally
         storage.setItem("locHigh", data.properties.periods[0].temperature);
         storage.setItem("locLow", data.properties.periods[1].temperature);
         storage.setItem("currentCondition", data.properties.periods[0].shortForecast);
         storage.setItem("detailedForecast", data.properties.periods[0].detailedForecast);
         storage.setItem("WindGusts", data.properties.periods[0].windSpeed);
      })
      .catch(error => console.log('There was a getHighLow error: ', error))
} //getHighLow function

/************************************************************
 * Function :: coverToFahrenheit
 * Does simple math to convert from C to F and deletes decimal
 ************************************************************/
function converToFahrenheit(celcius) {
   let fahr = (celcius * 1.8) + 32;
   let fixedFahr = Number(fahr).toFixed();
   return fixedFahr;
}

/************************************************************
 * Function :: buildPage
 * Puts the local current weather into the WeatherPage template
 ************************************************************/
function buildPage() {

   // get City & state, combine them, and write to HTML
   let locName = storage.getItem("locName");
   let locState = storage.getItem("locState");
   let fullName = locName + ', ' + locState;
   console.log("Fullname: " + fullName);
   let contentHeading = document.getElementById('town');
   contentHeading.innerHTML = fullName;

   // Setting the page title to the local location
   let pageTitle = document.getElementById('page-title');
   pageTitle.innerHTML = fullName + " | Local Weather";

   // gets elevation, converts it to meters, and writes to HTML
   let elev = storage.getItem("stationElevation");
   console.log("Elevation after conversion: ");
   convertMeters(elev);

   // Get long & lat, reduce decimals, combine, and write to HTML
   let locLong = storage.getItem("locLong");
   let locLat = storage.getItem("locLat");
   let fixedLong = Number(locLong).toFixed(2);
   let fixedLat = Number(locLat).toFixed(2);
   let fullLocation = fixedLong + ', ' + fixedLat;
   console.log("long, lat: " + fullLocation);
   let contentLocation = document.getElementById('location');
   contentLocation.innerHTML = fullLocation;

   // Gets current temp, deletes decimals, converts to F, and writes to HTML
   let locTemp = storage.getItem("locTemp");
   let fixedTemp = converToFahrenheit(locTemp);
   console.log("Temp: " + fixedTemp + " F");
   let contentCurrent = document.getElementById('currentTemp');
   contentCurrent.innerHTML = fixedTemp;

   // Gets forecasted high, and writes to HTML
   let locHigh = storage.getItem("locHigh");
   console.log("High: " + locHigh);
   let contentHigh = document.getElementById('forecastHigh');
   contentHigh.innerHTML = locHigh;

   // Gets forecasted low, and writes to HTML
   let locLow = storage.getItem("locLow");
   console.log("Low: " + locLow);
   let contentLow = document.getElementById('forecastLow');
   contentLow.innerHTML = locLow;

   // Gets current wind, and writes with units to HTML
   let locWind = storage.getItem("locWind");
   console.log("WindSpeed: " + locWind);
   let contentWind = document.getElementById('windSpeed');
   contentWind.innerHTML = locWind + ' mph';

   // Uses the current wind and temperature to build wind chill
   console.log("Wind Chill: ");
   buildWC(locWind, fixedTemp);

   // handles the wind dial direction
   let wd = storage.getItem("windDirection");
   console.log("Wind Direction before winDial Function: " + wd);
   windDial(wd);

   // Gets gust info and writes it with units to HTML
   let gusts = storage.getItem("WindGusts");
   console.log("Gusts: " + gusts);
   let contentGusts = document.getElementById('gusts');
   contentGusts.innerHTML = gusts;

   // Sets the current condition 
   let summary = storage.getItem("currentCondition");
   console.log("Summary: " + summary);
   let fixedSummary = getCondition(summary);
   changeSummaryImage(fixedSummary);

   let detailed = storage.getItem("detailedForecast");
   console.log("Detailed Forecast: " + detailed);
   let contentDetailed = document.getElementById('sumText');
   contentDetailed.innerHTML = detailed;


   let statusUpdate = document.getElementById('status');
   let displayEverything = document.getElementById('main-content');
   displayEverything.setAttribute('class', ''); // removes the hide class
   statusUpdate.setAttribute('class', 'hide'); // hides the status container
}