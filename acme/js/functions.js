"use strict"


console.log("My JavaScript is being read!");
// used later for event listener, handles hiding and displaying content
let linkContainer = document.getElementById('link-pages');
let mainContainer = document.getElementById('main-page');
let errorContainer = document.getElementById('error-message');
loadPage();


/************************************************************
 * Function :: loadPage
 * On page load, this fetches json data and builds nav bar
 ************************************************************/
function loadPage() {
   let acmeURL = "./js/acme.json";

   fetch(acmeURL)
      .then(function (response) {
         if (response.ok) {
            return response.json();
         }
         throw new Error('Network response was not ok.');
      })
      .then(function (data) {
         console.log(data);
         console.log(Object.keys(data));
         let keys = Object.keys(data);
         let navigation = document.getElementById("nav-style");
         navigation.innerHTML += buildNav(keys);
      })
} // loadPage function

/************************************************************
 * Function :: buildNav
 * Builds the navigation links on page load
 ************************************************************/
function buildNav(data) {
   let navListItems = "";
   for (let i = 0; i < 4; i++) {
      navListItems += '<li><a href="">' + data[i] + '</a></li>';
   }

   return navListItems;
} // buildNav function

/************************************************************
 * Function :: Event Listener
 * builds the other links based off of what user clicks
 ************************************************************/
let pageNav = document.getElementById('nav-style');
pageNav.addEventListener("click", function (evt) {
   let product = evt.target.innerHTML;
   console.log(product);

   // only check for products
   switch (product) {
      case "Anvils":
      case "Explosives":
      case "Decoys":
      case "Traps":
         evt.preventDefault();
         break;
   }

   let acmeURL = "./js/acme.json";

   fetch(acmeURL)
      .then(function (response) {
         if (response.ok) {
            return response.json();
         }
         throw new Error('Network response was not ok.');
      })
      .then(function (data) {
         // g becomes the name of the array holding data
         let g = data[product];

         console.log(g);
         /************ GRABBING ALL THE DATA ************/
         // name of product
         let locName = g.name;
         console.log("Product name: " + locName);

         // path of each image
         let imgPath = g.path;
         console.log("Image path: " + imgPath);

         // description of product
         let desc = g.description;
         console.log("Description: " + desc);

         // manufacturer of the product
         let manu = g.manufacturer;
         console.log("Manufacturer: " + manu);

         // overall review of product
         let reviews = g.reviews;
         console.log("Reviews: " + reviews);

         // price of product
         let price = g.price;
         console.log("Price: " + price);

         /************ SETTING ALL THE DATA ************/

         // setting the title of the page
         let tabTitle = document.getElementById('page-title');
         let contentTitle = document.getElementById('content-title');
         contentTitle.innerHTML = locName;
         tabTitle.innerHTML = locName;

         // setting the image path of the product
         let productImage = document.getElementById('product-img');
         productImage.setAttribute('src', imgPath);
         productImage.setAttribute('alt', 'A picture of an ' + locName);

         // setting the description of the product
         let description = document.getElementById('description');
         description.innerHTML = desc;

         // setting the manufacturer
         let manufacturer = document.getElementById('manufacturer');
         manufacturer.innerHTML = manu;

         // setting the reviews
         let revs = document.getElementById('revs');
         revs.innerHTML = reviews + '/5 stars';

         // setting the price
         let proPrice = document.getElementById('price');
         proPrice.innerHTML = 'Price: $' + price;

         // hiding the main page and displaying the content
         linkContainer.setAttribute('class', ''); // removes the hide class
         mainContainer.setAttribute('class', 'hide'); // hides the status container
         errorContainer.setAttribute('class', 'hide');
      })
      .catch(function (error) {
         console.log('There was a fetch problem: ', error.message);
         errorContainer.setAttribute('class', '');
      })
})