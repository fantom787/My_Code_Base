function playSound(val) {
  switch (val) {
    case "w":
      var sound = new Audio("sounds/tom-1.mp3");
      sound.play();
      break;
    case "a":
      var sound = new Audio("sounds/tom-2.mp3");
      sound.play();
      break;
    case "s":
      var sound = new Audio("sounds/tom-3.mp3");
      sound.play();
      break;
    case "d":
      var sound = new Audio("sounds/tom-4.mp3");
      sound.play();
      break;
    case "j":
      var sound = new Audio("sounds/snare.mp3");
      sound.play();
      break;
    case "k":
      var sound = new Audio("sounds/crash.mp3");
      sound.play();
      break;
    case "l":
      var sound = new Audio("sounds/kick-bass.mp3");
      sound.play();
      break;
  }
}

// for click
var len = document.querySelectorAll(".drum").length;
console.log(len);
for (var i = 0; i < len; i++) {
  document.querySelectorAll(".drum")[i].addEventListener("click", function () {
    var val = this.innerHTML;
    playSound(val);
    animation(val);
  });
}

// for keypress
document.addEventListener("keypress", function (event) {
  playSound(event.key);
  animation(event.key);
});

// making animation

function animation(key) {
  var x = document.querySelector("." + key);
  x.classList.toggle("pressed");
  window.setTimeout(function () {
    x.classList.toggle("pressed");
  },100);
}
