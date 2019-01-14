(function() {
  // the API end point
  var url = "getLoginMessage";

// This function will change the login message.
  var xmlhttp = new XMLHttpRequest();
  xmlhttp.open("POST", url, true);
  xmlhttp.send();

  xmlhttp.onreadystatechange = function() {
    if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
      fillMsg(xmlhttp.responseText);
    }
  };

  function fillMsg(response) {
    document.getElementById("error_message").innerHTML += response;
  }
})();
