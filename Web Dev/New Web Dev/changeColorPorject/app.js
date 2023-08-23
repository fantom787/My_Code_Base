function randomColor() {
  let random = Math.floor(Math.random() * 255);
  return random;
}
function changeColor() {
  console.log("clicked");
  const r = randomColor();
  const g = randomColor();
  const b = randomColor();
  const rgb = `rgb(${r},${g},${b})`;
  document.body.style.backgroundColor = rgb;
  document.querySelector("h1").innerText = rgb;
}
const button = document.querySelector("button");
button.addEventListener("click", changeColor);
