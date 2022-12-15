const mongoose = require("mongoose");

mongoose
  .connect("mongodb://127.0.0.1:27017/fruitsDB", {
    useNewUrlParser: true,
  })
  .then(() => console.log("Connection Sucessfull..."))
  .catch((err) => console.log(err));

const schema = new mongoose.Schema({
  name: String,
  rating: Number,
  review: String,
});

const Fruit = mongoose.model("Fruit", schema);

const Apple = new Fruit({
  name: "Apple",
  rating: 10,
  review: "Very good",
});
const orange = new Fruit({
  name: "orange",
  rating: 10,
  review: "Very good orange",
});
const grapes = new Fruit({
  name: "grapes",
  rating: 10,
  review: "Very good grapes",
});
const kiwi = new Fruit({
  name: "kiwi",
  rating: 10,
  review: "Very good kiwi",
});

// Fruit.insertMany([orange,grapes,kiwi],function(err)
// {
//   if(err)
//   {
//     console.log(err);
//   }
//   else{
//     console.log("Sucessfully Inserted!");
//   }
// });
// Apple.save();

const personSchema = new mongoose.Schema({
  name: String,
  age: Number,
});

const Person = new mongoose.model("person", personSchema);

const person = new Person({
  name: "Ambuj",
  age: 21,
});

// person.save();

Fruit.find(function (err, result) {
  if (err) {
    console.log(err);
  } else {
    mongoose.connection.close();
    for (var i = 0; i < result.length; i++) {
      console.log(result[i].name);
    }
  }
});

// Fruit.deleteOne({ _id: "637f025665175b5587cddd5c" }, function (err) {
// if (err) {
// console.log(err);
// } else {
// console.log("Sucessfully deleted!");
// }
// });
//

Person.deleteMany({ name: "Ambuj" }, function (err) {
  if (err) {
    console.log(err);
  } else {
    console.log("Sucessfully Deleted Many!");
  }
});
