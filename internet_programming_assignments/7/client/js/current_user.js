"use strict";

// Function gets the current user and displays their name.
(function() {
  var url = "current_user";

  var xmlhttp = new XMLHttpRequest();
  xmlhttp.open("GET", url, true);
  xmlhttp.send();

  xmlhttp.onreadystatechange = function() {
    if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
      var myArr = xmlhttp.responseText;
      console.log(myArr);
      fillName(myArr);
    }
  };

  function fillName(response) {

    var output = "welcome "
    output += `<td>${response}</td>`;
    console.log(response);

    document.getElementById("currentUser").innerHTML = output;
  }
})();
