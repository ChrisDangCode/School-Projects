// YOU CAN USE THIS FILE AS REFERENCE FOR SERVER DEVELOPMENT

// include the express module
var express = require("express");

// create an express application
var app = express();

// helps in extracting the body portion of an incoming request stream
var bodyparser = require('body-parser');

// fs module - provides an API for interacting with the file system
var fs = require("fs");

// helps in managing user sessions
var session = require('express-session');

// native js function for hashing messages with the SHA-1 algorithm
var sha1 = require('sha1');

// include the mysql module
var mysql = require("mysql");

var con = mysql.createConnection({
  host: "cse-curly.cse.umn.edu",
  user: "C4131S18U21", // replace with the database user provided to you
  password: "26", // replace with the database password provided to you
  database: "C4131S18U21", // replace with the database user provided to you
  port: 3306
});

con.connect(function(err) {
  if (err) {
    throw err;
  };
  console.log("Connected to MySQL server!");
});



// apply the body-parser middleware to all incoming requests
app.use(bodyparser());

// use express-session
// in mremory session is sufficient for this assignment
app.use(session({
  secret: "csci4131secretkey",
  saveUninitialized: true,
  resave: false}
));

// server listens on port 9007 for incoming connections
app.listen(9007, () => console.log('Listening on port 9007!'));

// GET method for defaulting to login.
app.get('/',function(req, res) {
	res.redirect('/login');
});

// GET method route for the favourites page.
// It serves favourites.html present in client folder
app.get('/favourites',function(req, res) {
  if(!req.session.user_ID){
      req.session.accessible = false;
    res.redirect('/login');
  }

    else{
	      res.sendFile(__dirname + '/client/favourites.html');
}
});

// GET method route for the addPlace page.
// It serves addPlace.html present in client folder
app.get('/addPlace',function(req, res) {
  if(!req.session.user_ID){
    req.session.accessible = false;
    res.redirect('/login');
  }

    else{
	     res.sendFile(__dirname + '/client/addPlace.html');
 }
});

// GET method route for the login page.
// It serves login.html present in client folder
app.get('/login',function(req, res) {
  res.sendFile(__dirname + '/client/login.html');
});

// GET method to return the list of favourite places
// The function queries the table tbl_places for the list of places and sends the response back to client
app.get('/getListOfFavPlaces', function(req, res) {
  var query = 'SELECT * FROM tbl_places;';
  con.query(query, function(err, result) {
    if(err) {
      throw err;
    }
    var entry = { placeEntry: [] };
    for (var item of result){
      entry.placeEntry.push({
        placeName: item.place_name,
        addr1: item.addr_line1,
        addr2: item.addr_line2,
        openTime: item.open_time,
        closeTime: item.close_time,
        info: item.add_info,
        infoURL: item.add_info_url
      })
    }
    res.send(JSON.stringify(entry));
    console.log("Getting favourite list.");
    //console.log('result is: ', result);
  });
});

// POST method to insert details of a new place to tbl_places table
app.post('/postPlace', function(req, res) {

  console.log(req.body);
  console.log(req.body.placename);

  var rowToBeInserted = {
    place_name: req.body.placename,
    addr_line1: req.body.addressline1,
    addr_line2: req.body.addressline2,
    open_time: req.body.opentime,
    close_time: req.body.closetime,
    add_info: req.body.additionalinfo,
    add_info_url: req.body.additionalinfourl
  };

  con.query('INSERT tbl_places SET ?', rowToBeInserted, function(err, result) {
    if(err) {
      throw err;
    }
    res.redirect('/favourites')
    console.log("Place inserted");
  });
});

// POST method to validate user login
// upon successful login, user session is created
app.post('/validateLoginDetails', function(req, res) {

    console.log("LOGIN ATTEMPTED");
  //console.log(req.body);

  var user_query = 'SELECT * FROM tbl_accounts WHERE acc_name = \"' + req.body.user_name +
  '\" AND acc_password = \"' + sha1(req.body.password) + '\";';

      //console.log(user_query);
  con.query(user_query, function(err, result) {
    if(err) {
      throw err;
    }
    //console.log("RESULT IS:");
    //console.log(result);
    if (result.length > 0){
    req.session.user_ID = 1;
    res.redirect('/favourites');
  }

  else{
      req.session.valid_login = false;
      res.redirect('/login');
  }


  });


});

app.post('/getLoginMessage', function(req, res) {

  //console.log(req.session.accessible);

  if(req.session.accessible != null){
    delete req.session.accessible;
    res.send("Permission not allowed.");
  }

  else if(req.session.valid_login != null){
    delete req.session.valid_login;
    res.send("Invalid user name or password. Please try again.");
  }

  //(!req.session.user_ID)
  else {
    res.send("");
  }



});

// log out of the application
// destroy user session
app.get('/logout', function(req, res) {

    req.session.destroy();
    console.log("Session destroyed");
    res.redirect('/login');
});

// middle ware to server static files
app.use('/client', express.static(__dirname + '/client'));


// function to return the 404 message and error to client
app.get('*', function(req, res) {
  res.sendFile(__dirname + '/client/404.html');
});
