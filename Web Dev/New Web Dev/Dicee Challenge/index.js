// generate number from 1 to 6
var x1 = Math.floor(Math.random() * 6) + 1;
var x2 = Math.floor(Math.random() * 6) + 1;

var src1 = "images/dice" + x1 + ".png";
var src2 = "images/dice" + x2 + ".png";

var img1 = document.querySelectorAll("img")[0];
var img2 = document.querySelectorAll("img")[1];
img1.setAttribute("src", src1);
img2.setAttribute("src", src2);

if (x1 > x2) {
  document.querySelector("h1").innerHTML = "🚩 Play 1 Wins!";
} else if (x2 > x1) {
  document.querySelector("h1").innerHTML = "Player 2 Wins! 🚩";
} else {
  document.querySelector("h1").innerHTML = "Draw!";
}
