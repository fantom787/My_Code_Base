const bodyParser = require("body-parser");
const express = require("express");
const ejs = require("ejs");
const mongoose = require("mongoose");

const app = express();
app.set("view engine", "ejs");

app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static("public"));

mongoose
  .connect("mongodb://127.0.0.1:27017/wikiDB", {
    useNewUrlParser: true,
  })
  .then(() => console.log("Connection Sucessfull..."))
  .catch((err) => console.log(err));

const articleSchema = {
  title: String,
  content: String,
};
const Article = mongoose.model("Article", articleSchema);

app.post("/articles", function (req, res) {
  const newar = new Article({
    title: req.body.title,
    content: req.body.content,
  });
  newar.save(function (err) {
    if (err) {
      console.log(err);
    }
    else{
      console.log("Sucessfully Saved!");
    }
  });
  res.send("hi this is post 1");
});

app.get("/article", function (req, res) {
  Article.find(function (err, foundArticles) {
    res.send(foundArticles);
  });
});

app.listen(3000, function () {
  console.log("Server is At port 3000");
});
