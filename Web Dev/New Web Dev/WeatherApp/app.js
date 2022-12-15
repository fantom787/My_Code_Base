const express = require("express");
const app = express();
const https = require("https");
const bodyParser = require("body-parser");
app.use(bodyParser.urlencoded({ extended: true }));

app.get("/", function (req, res) {
  res.sendFile(__dirname + "/index.html");
});

app.post("/", function (req, res) {
  const query = req.body.cityName;
  console.log(query);
  const apiKey = "8e459220fe36eca8110f94f444b96255";
  const units = "metric";
  const url =
    "https://api.openweathermap.org/data/2.5/weather?q=" +
    query +
    "&appid=" +
    apiKey +
    "&units=" +
    units;
  https.get(url, function (response) {
    console.log(response.statusCode);
    response.on("data", function (data) {
      const weatherData = JSON.parse(data);
      res.write(
        "<h1>the Temprature in " +
          weatherData.name +
          " is: " +
          weatherData.main.temp +
          "</h1>"
      );
      res.write(
        "the weather description: " + weatherData.weather[0].description
      );
      var linkIcon =
        "http://openweathermap.org/img/wn/" +
        weatherData.weather[0].icon +
        "@2x.png";
      res.write("<img src=" + linkIcon + ">");
      console.log(linkIcon);
      res.send();
    });
  });
});

app.listen(3000, function () {
  console.log("app listening at port 3000");
});
