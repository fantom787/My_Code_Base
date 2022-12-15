const express = require("express");
const app = express();
const bodyPraser = require("body-parser");
app.use(bodyPraser.urlencoded({ extended: true }));
app.get("/", function (req, res) {
  res.sendFile(__dirname + "/index.html");
});

app.post("/", function (req, res) {
  var x = Number(req.body.height);
  var y = Number(req.body.Weight);
  var ans = x + y;
  res.send("the bmi is" + (x + y));
});

app.listen(3000, function () {
  console.log("listining at port 30000");
});
