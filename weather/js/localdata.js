"use strict"


let pageNav = document.getElementById('navigation');
let statusContainer = document.getElementById('status');
let contentContainer = document.getElementById('main-content');

pageNav.addEventListener("click", function (evt) {
   let cityName = evt.target.innerHTML;
   console.log(cityName);

   // only check for city names
   switch (cityName) {
      case "Franklin":
      case "Greenville":
      case "Springfield":
         evt.preventDefault();
         break;
   }


   let weatherURL = "./js/weather.json";

   fetch(weatherURL)
      .then(function (response) {
         if (response.ok) {
            return response.json();
         }
         throw new Error('Network response was not ok.');
      })
      .then(function (data) {
         // see what we retrieved from the data object
         console.log(data);
         // data is the full JavaScript object, but we just want the greenville part
         // shorten the variable and focus only on the data we want to reduce typing
         let g = data[cityName];

         /********************GRAB ALL OF THE DATA****************/

         // location data
         let locName = g.City;
         console.log("City: " + locName);
         let locState = g.State;
         console.log("State: " + locState);
         // combining them
         let fullName = locName + ', ' + locState;
         // make sure they were combined properly
         console.log('fullName is: ' + fullName);

         let locLong = g.Longitude;
         console.log("Longitude: " + locLong);

         let locLat = g.Latitude;
         console.log("Latitude: " + locLat);

         let locZip = g.Zip;
         console.log("Zip: " + locZip);

         let locElev = g.Elevation;
         console.log("Elevation: " + locElev);

         // temperature data
         let locHigh = g.High;
         console.log("High: " + locHigh);

         let locLow = g.Low;
         console.log("Low: " + locLow);

         let locTemp = g.Temp;
         console.log("Temp: " + locTemp);

         // wind data
         let locWind = g.Wind;
         console.log("WindSpeed: " + locWind);

         let windDirection = g.Direction;
         console.log("Direction: " + windDirection);

         let windGusts = g.Gusts;
         console.log("Gusts: " + windGusts);

         // current condition data
         let locPrecip = g.Precip;
         console.log("Precip: " + locPrecip);

         let locSummary = g.Summary;
         console.log("Summary: " + locSummary)

         // getting hourly data
         let hourly = g.Hourly;
         console.log(hourly);

         /********************DISPLAY EVERYTHING****************/

         let pageTitle = document.getElementById('page-title');

         if (pageTitle.childNodes.length > 1) {
            pageTitle.childNodes[0].remove();
         }

         let fullNameNode = document.createTextNode(fullName);


         pageTitle.insertBefore(fullNameNode, pageTitle.childNodes[0]);

         /******************** set location data ****************/
         // city location
         let contentHeading = document.getElementById('town');
         contentHeading.innerHTML = fullName;

         // zip code
         let contentZip = document.getElementById('zip');
         contentZip.innerHTML = locZip;

         // elevation
         convertMeters(locElev);

         // latitude and longitude
         let contentLocation = document.getElementById('location');
         let fullLocation = locLong + ', ' + locLat;
         contentLocation.innerHTML = fullLocation;

         // set Temperature data
         let contentCurrent = document.getElementById('currentTemp');
         contentCurrent.innerHTML = locTemp;

         // the high forecast display
         let contentHigh = document.getElementById('forecastHigh');
         contentHigh.innerHTML = locHigh;

         // The low foreacst display
         let contentLow = document.getElementById('forecastLow');
         contentLow.innerHTML = locLow;

         // set wind data

         // wind speed
         let contentWind = document.getElementById('windSpeed');
         contentWind.innerHTML = locWind + ' mph';
         buildWC(locWind, contentCurrent.innerHTML);

         // wind direction
         let contentDirection = document.getElementById('wd');
         contentDirection.innerHTML = windDirection;
         windDial(contentDirection.innerHTML)

         // wind gusts
         let contentGusts = document.getElementById('gusts');
         contentGusts.innerHTML = windGusts + ' mph';

         // Summary tile # 3
         // Current Condition
         let contentSummary = document.getElementById('currentCondition');
         contentSummary.innerHTML = locSummary;

         // displays the current condition through pictures
         let currentCondition = getCondition(contentSummary.innerHTML);
         changeSummaryImage(currentCondition);

         // precipitation
         let contentPrecip = document.getElementById('sumText');
         contentPrecip.innerHTML = "Precipitation: " + locPrecip + "%";

         // hourly Forecast
         let contentHourly = document.getElementById('averageHF');
         contentHourly.innerHTML = buildHourlyData(nextHour, hourly);

         // change the status of the containers
         contentContainer.setAttribute('class', ''); // removes the hide class
         statusContainer.setAttribute('class', 'hide'); // hides teh status container
      })
      .catch(function (error) {
         console.log('There was a fetch problem: ', error.message);
         statusContainer.innerHTML = 'Sorry, the data could not be processed.';
      })

})