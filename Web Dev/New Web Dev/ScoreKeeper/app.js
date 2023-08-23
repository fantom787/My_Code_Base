const p1btn = document.querySelector("#p1btn");
const p2btn = document.querySelector("#p2btn");
const reset = document.querySelector("#reset");
const p1s = document.querySelector("#p1S");
const p2s = document.querySelector("#p2S");
var p1score = 0,
  p2score = 0;

function update() {
  p1s.textContent = `${p1score}`;
  p2s.textContent = `${p2score}`;
}
reset.addEventListener("click", function () {
  (p1score = 0), (p2score = 0);
  update();
});
p1btn.addEventListener("click", function () {
  p1score++;
  update();
});
p2btn.addEventListener("click", function () {
  p2score++;
  update();
});
