var buttons = ["red", "blue", "green", "yellow"];
var pattern = [];
var userClicked = [];
var level = 0;
var toggle = false;

$(".btn").click(function () {
  var clicked = $(this).attr("id");
  userClicked.push(clicked);
  playSound(clicked);
  animatePress(clicked);
  checkAns(userClicked.length - 1);
});

$(document).keypress(function () {
  if (!toggle) {
    $("#level-title").text("level " + level);
    nextSeq();
    toggle = true;
  }
});

function nextSeq() {
  userClicked = [];
  level++;
  $("#level-title").text("level " + level);
  var x = Math.floor(Math.random() * 4);
  var randomColor = buttons[x];
  pattern.push(randomColor);
  $("#" + randomColor)
    .fadeIn(100)
    .fadeOut(100)
    .fadeIn(100);
  playSound(randomColor);
}

function playSound(randomColor) {
  var sound = new Audio("sounds/" + randomColor + ".mp3");
  sound.play();
}

function animatePress(color) {
  $("#" + color).addClass("pressed");
  setTimeout(function () {
    $("#" + color).removeClass("pressed");
  }, 100);
}

function checkAns(curLvl) {
  if (pattern[curLvl] === userClicked[curLvl]) {
    if (userClicked.length === pattern.length) {
      setTimeout(function () {
        nextSeq();
      }, 1000);
    }
  } else {
    playSound("wrong");
    $("body").addClass("game-over");
    setTimeout(function () {
      $("body").removeClass("game-over");
    }, 200);
    $("#level-title").text("Game Over, Press Any Key to Restart");
    toggle = false;
    level = 0;
    pattern = [];
  }
}
