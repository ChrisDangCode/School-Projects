"use strict";

(function() {
  // the API end point
  var url = "getListOfFavPlaces";

  // TO DO: YOU NEED TO USE AJAX TO CALL getListOfFavPlaces end-point from server
  // STEPS:
  // 1. Hit the getListOfFavPlaces end-point of server using AJAX get method
  // 2. Upon successful completion of API call, server will return the list of places
  // 2. Use the response returned to dynamically add rows to 'myFavTable' present in favourites.html page
  // 3. You can make use of jQuery or JavaScript to achieve this
  // Note: No changes will be needed in favourites.html page
  var xmlhttp = new XMLHttpRequest();
  xmlhttp.open("GET", url, true);
  xmlhttp.send();

  xmlhttp.onreadystatechange = function() {
    if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
      var myArr = JSON.parse(xmlhttp.responseText);
      //console.log(myArr);
      fillTable(myArr);
    }
  };

  function fillTable(response) {

    var arr = response.placeEntry;
    //console.log(arr);
    var output = "";
    for (var i = 0; i < arr.length; i++) {
      output +=
        `<tr><td>${arr[i].placeName}
        </td><td>${arr[i].addr1}<br>
        ${arr[i].addr2}</td><td>
        ${arr[i].openTime}<br>
        ${arr[i].closeTime}</td><td>
        ${arr[i].info}</td><td>
        ${arr[i].infoURL}</td>`;
      //... you fill in the rest of the information from
      // the array of JSON objects held by the variable response
    }
    document.getElementById("myFavTable").innerHTML += output;
  }
})();
