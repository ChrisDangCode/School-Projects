"use strict";

function populate_user_list() {
  // the API end point
  var url = "getListOfUsers";

  var xmlhttp = new XMLHttpRequest();
  xmlhttp.open("GET", url, true);
  xmlhttp.send();

  xmlhttp.onreadystatechange = function() {
    if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
      var myArr = JSON.parse(xmlhttp.responseText);
      console.log(myArr);
      fillTable(myArr);
    }
  };

  function fillTable(response) {

    var arr = response.userEntry;
    console.log(arr);
    var output = "";
    for (var i = 0; i < arr.length; i++) {
      output +=
        `<tr id="ID-${arr[i].user_ID}"><td>${arr[i].user_ID}</td>
             <td>${arr[i].name}</td>
             <td>${arr[i].login}</td>
             <td></td>
             <td><span onclick="editEntry('${arr[i].user_ID}', '${arr[i].name}', '${arr[i].login}')" class="glyphicon glyphicon-pencil"></span>&nbsp;&nbsp;&nbsp;
             <span onclick="deleteEntry('${arr[i].user_ID}')" class="glyphicon glyphicon-trash"></span></td>`;
        //console.log(output);
    }
    document.getElementById("myUsrTable").innerHTML = output;
  }
};

populate_user_list();

var pressed = false;

function addUser() {

if (!pressed){
  var row = `<tr id="newRow"><td></td><td><input type="text" id="nameRow" name="userName"></td>
             <td><input type="text" id="loginRow" name="login"></td>
             <td><input type="text"  id="passwordRow" name="password"></td>
             <td><span onclick="saveEntry()" class="glyphicon glyphicon-floppy-save"></span>&nbsp;&nbsp;&nbsp;
                 <span onclick="clearEntry()" class="glyphicon glyphicon-remove"></span></td>
             </tr>`;


  document.getElementById("myUsrTable").innerHTML += row;

  pressed = true;
  }
};

function clearEntry(){

  $("#newRow").remove();
  pressed = false;

}


function saveEntry(){


    var name = $("#newRow")[0].children[1].children[0].value;
    var login = $("#newRow")[0].children[2].children[0].value;
    var password = $("#newRow")[0].children[3].children[0].value;
    //console.log(document.getElementById("myUsrTable"));


    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("POST", "/add_user");
    xmlhttp.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
    xmlhttp.send(JSON.stringify({ name: name, login:login, password:password }));

    xmlhttp.onreadystatechange = function() {
      if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
          document.getElementById("error_message_admin").innerHTML = xmlhttp.responseText;
          populate_user_list();
          pressed = false;
          $("#newRow").remove();
      }
    };

    //location.reload();
}


function deleteEntry(entry){

  //console.log(entry);
  console.log("ENTRY IS TO BE DELETED.");


  var xmlhttp = new XMLHttpRequest();
  xmlhttp.open("POST", "/delete_user");
  xmlhttp.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
  xmlhttp.send(JSON.stringify({ userID: entry }));

  xmlhttp.onreadystatechange = function() {
    if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
        document.getElementById("error_message_admin").innerHTML = xmlhttp.responseText;
        populate_user_list();
    }
  };
}

function editEntry(entryID, entryName, entryLogin){

  var rowID = "ID-" + entryID;

  var row = `<tr id="editRow"><td>${entryID}</td><td><input type="text" id="nameRow" name="userName" value="${entryName}"></td>
             <td><input type="text" id="loginRow" name="login" value="${entryLogin}"></td>
             <td><input type="text"  id="passwordRow" name="password"></td>
             <td><span onclick="updateEntry('${entryID}')" class="glyphicon glyphicon-floppy-save"></span>&nbsp;&nbsp;&nbsp;
                 <span onclick="cancelEdit('${entryID}', '${entryName}', '${entryLogin}')" class="glyphicon glyphicon-floppy-remove"></span></td>
             </tr>`;

  console.log(rowID);

  console.log(document.getElementById(rowID).innerHTML);

  document.getElementById(rowID).innerHTML = row;
  document.getElementById(rowID).setAttribute("id", "editRow");

}

function updateEntry(entryID){

    var name = $("#editRow")[0].children[1].children[0].value;
    var login = $("#editRow")[0].children[2].children[0].value;
    var password = $("#editRow")[0].children[3].children[0].value;


    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("POST", "/update_user");
    xmlhttp.setRequestHeader("Content-Type", "application/json;charset=UTF-8");
    xmlhttp.send(JSON.stringify({ entryID:entryID, name: name, login:login, password:password }));

    xmlhttp.onreadystatechange = function() {
      if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
          document.getElementById("error_message_admin").innerHTML = xmlhttp.responseText;
          populate_user_list();
          pressed = false;
          $("#newRow").remove(); // NEED TO UPDATE ROW
      }
    };

    //location.reload();
}

function cancelEdit(entryID, entryName, entryLogin){

  var row = `<tr id="ID-${entryID}"><td>${entryID}</td>
       <td>${entryName}</td>
       <td>${entryLogin}</td>
       <td></td>
       <td><span onclick="editEntry('${entryID}', '${entryName}', '${entryLogin}')" class="glyphicon glyphicon-pencil"></span>&nbsp;&nbsp;&nbsp;
       <span onclick="deleteEntry('${entryID}')" class="glyphicon glyphicon-trash"></span></td>`;

       document.getElementById("editRow").innerHTML = row;

}
